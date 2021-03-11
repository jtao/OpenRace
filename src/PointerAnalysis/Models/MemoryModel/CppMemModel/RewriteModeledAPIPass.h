//
// Created by peiming on 7/23/20.
//

#ifndef PTA_REWRITEMODELEDAPIPASS_H
#define PTA_REWRITEMODELEDAPIPASS_H

#include <llvm/Pass.h>
namespace pta {
namespace cpp {

class RewriteModeledAPIPass : public llvm::FunctionPass {
 public:
  static char ID;
  explicit RewriteModeledAPIPass() : llvm::FunctionPass(ID) {}

  bool runOnFunction(llvm::Function &F) override;
};

}  // namespace cpp
}  // namespace pta

#endif
