//
// Created by peiming on 1/2/20.
//

#ifndef PTA_FSCANONICALIZER_H
#define PTA_FSCANONICALIZER_H

#include <llvm/IR/Instructions.h>
#include <llvm/IR/Intrinsics.h>
#include <llvm/IR/Value.h>

namespace pta {

// Canonicalizer should not collapse alloca, load, store, phi .. instructions
class FSCanonicalizer {
 public:
  static const llvm::Value *canonicalize(const llvm::Value *V);
};

}  // namespace pta

#endif
