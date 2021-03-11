//
// Created by peiming on 11/13/19.
//
#ifndef PTA_DEFAULTEXTFUNCTIONS_H
#define PTA_DEFAULTEXTFUNCTIONS_H

#include <llvm/IR/Function.h>

#include <set>

namespace pta {

// TODO: think about this!

class DefaultExtFunctions {
 private:
  const static std::set<llvm::StringRef> THREAD_CREATIONS;

 public:
  inline static bool isThreadCreation(const llvm::Function *fun) {
    return THREAD_CREATIONS.find(fun->getName()) != THREAD_CREATIONS.end();
  }
};

}  // namespace pta

#endif