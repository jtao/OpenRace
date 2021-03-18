/* Copyright 2021 Coderrect Inc. All Rights Reserved.
Licensed under the GNU Affero General Public License, version 3 or later (“AGPL”), as published by the Free Software
Foundation. You may not use this file except in compliance with the License. You may obtain a copy of the License at
https://www.gnu.org/licenses/agpl-3.0.en.html
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an “AS IS” BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "RaceDetect/RaceDetect.h"

#include "PreProcessing/PreProcessing.h"

using namespace race;

Report race::detectRaces(llvm::Module *module) {
  race::Reporter reporter;

  // Run preprocessing on module
  preprocess(*module);

  // Actual PTA
  auto pta = std::make_unique<pta::PTA>();
  pta->analyze(module, "main");

  race::ProgramTrace program(*pta);
  race::SharedMemory sharedmem(program);
  race::HappensBeforeGraph happensbefore(program);
  race::LockSet lockset(program);

  auto checkRace = [&](const race::WriteEvent *write, const race::MemAccessEvent *other) {
    if (happensbefore.areParallel(write, other) && !lockset.sharesLock(write, other)) {
      llvm::outs() << "Race between:\n\t" << *write->getIRInst()->getInst() << "\n\t" << *other->getIRInst()->getInst()
                   << "\n";
      reporter.collect(write, other);
    }
  };

  for (auto const sharedObj : sharedmem.getSharedObjects()) {
    auto threadedWrites = sharedmem.getThreadedWrites(sharedObj);
    auto threadedReads = sharedmem.getThreadedReads(sharedObj);

    for (auto it = threadedWrites.begin(), end = threadedWrites.end(); it != end; ++it) {
      auto const wtid = it->first;
      auto const writes = it->second;
      // check Read/Write race
      for (auto const &[rtid, reads] : threadedReads) {
        if (wtid == rtid) continue;
        for (auto write : writes) {
          for (auto read : reads) {
            checkRace(write, read);
          }
        }
      }

      // Check write/write
      for (auto wit = std::next(it, 1); wit != end; ++wit) {
        auto otherWrites = wit->second;
        for (auto write : writes) {
          for (auto otherWrite : otherWrites) {
            checkRace(write, otherWrite);
          }
        }
      }
    }
  }

  return reporter.getReport();
}