//
// Created by peiming on 3/30/20.
//

#ifndef PTA_STATISTICS_H
#define PTA_STATISTICS_H

#include <llvm/ADT/Statistic.h>

#define LOCAL_STATISTIC(VARNAME, DESC) \
  llvm::Statistic VARNAME { DEBUG_TYPE, #VARNAME, DESC }

#endif
