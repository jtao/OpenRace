#pragma once

#include "Analysis/HappensBeforeGraph.h"
#include "Analysis/LockSet.h"
#include "Analysis/SharedMemory.h"
#include "LanguageModel/RaceModel.h"
#include "Reporter/Reporter.h"
#include "Trace/ProgramTrace.h"

namespace race {

Report detectRaces(llvm::Module *module);

}  // namespace race