//
// Created by peiming on 11/3/19.
//
#ifndef PTA_FICANONICALIZER_H
#define PTA_FICANONICALIZER_H

#include <llvm/IR/Instructions.h>
#include <llvm/IR/Intrinsics.h>
#include <llvm/IR/Value.h>

namespace pta {

// Canonicalizer should not collapse alloca, load, store, phi .. instructions
class FICanonicalizer {
  static const llvm::Value *stripPointerCastsAndOffsets(const llvm::Value *V);

 public:
  static const llvm::Value *canonicalize(const llvm::Value *V);
};

}  // namespace pta

#endif