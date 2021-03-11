//
// Created by peiming on 3/14/20.
//

#ifndef PTA_INSERTGLOBALCTORCALLPASS_H
#define PTA_INSERTGLOBALCTORCALLPASS_H

#include <llvm/Pass.h>

class InsertGlobalCtorCallPass : public llvm::ModulePass {
 public:
  static char ID;
  explicit InsertGlobalCtorCallPass() : llvm::ModulePass(ID) {}

  bool runOnModule(llvm::Module &M) override;
};

#endif
