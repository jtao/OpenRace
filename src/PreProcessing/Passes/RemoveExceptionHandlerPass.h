//
// Created by peiming on 1/10/20.
//

#ifndef PTA_REMOVEEXCEPTIONHANDLERPASS_H
#define PTA_REMOVEEXCEPTIONHANDLERPASS_H

#include <llvm/Pass.h>

class RemoveExceptionHandlerPass : public llvm::FunctionPass {
 public:
  static char ID;
  RemoveExceptionHandlerPass() : llvm::FunctionPass(ID) {}

  bool runOnFunction(llvm::Function &F) override;
  bool doInitialization(llvm::Module &M) override;
};

#endif
