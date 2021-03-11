//
// Created by peiming on 8/14/19.
//
#ifndef PTA_CTXTRAIT_H
#define PTA_CTXTRAIT_H

namespace pta {

template <typename ctx>
class CtxTrait {
  using unknownTypeError = typename ctx::unknownTypeErrorType;
};

}  // namespace pta

#endif
