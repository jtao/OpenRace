#include "RaceDetect/RaceDetect.h"

using namespace race;

Report race::detectRaces(llvm::Module *module) {
  race::Reporter reporter;

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