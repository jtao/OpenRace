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

//
// Created by peiming on 11/5/19.

#include <llvm/IR/GlobalAlias.h>
#include <llvm/IR/Operator.h>

#include <set>

#include "Logging/Log.h"
#include "PointerAnalysis/Program/CallSite.h"

using namespace pta;
using namespace llvm;

// extern cl::opt<size_t> MaxIndirectTarget("max-indirect-target", cl::init(2),
//                                  cl::desc("max number of indirect call target
//                                  that can be resolved by indirect call"));

const Function* pta::CallSite::resolveTargetFunction(const Value* calledValue) {
  // TODO: In this case, a constant expression/global aliases, which can be
  // resolved directly
  if (auto bitcast = dyn_cast<BitCastOperator>(calledValue)) {
    if (auto function = dyn_cast<Function>(bitcast->getOperand(0))) {
      return function;
    }
  }

  if (auto globalAlias = dyn_cast<GlobalAlias>(calledValue)) {
    auto globalSymbol = globalAlias->getIndirectSymbol()->stripPointerCasts();
    if (auto function = dyn_cast<Function>(globalSymbol)) {
      return function;
    }
    LOG_ERROR("Unhandled Global Alias. alias={}", *globalAlias);
    llvm_unreachable(
        "resolveTargetFunction matched globalAlias but symbol was not "
        "Function");
  }

  if (isa<UndefValue>(calledValue)) {
    return nullptr;
  }
  LOG_ERROR("Unable to resolveTargetFunction from calledValue. called={}", *calledValue);
  // return nullptr;
  llvm_unreachable("Unable to resolveTargetFunction from calledValue");
}
