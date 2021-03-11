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

const Function* pta::CallSite::resolveTargetFunction(
    const Value* calledValue) {
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
  LOG_ERROR("Unable to resolveTargetFunction from calledValue. called={}",
            *calledValue);
  // return nullptr;
  llvm_unreachable("Unable to resolveTargetFunction from calledValue");
}