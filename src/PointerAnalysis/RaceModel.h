#pragma once

#include "PointerAnalysis/Context/KOrigin.h"
#include "PointerAnalysis/Models/LanguageModel/DefaultLangModel/DefaultLangModel.h"
#include "PointerAnalysis/Models/MemoryModel/CppMemModel/CppMemModel.h"
#include "PointerAnalysis/Solver/PartialUpdateSolver.h"

namespace pta {
using ctx = KOrigin<3>;
using MemModel = cpp::CppMemModel<ctx>;
using LangModel = DefaultLangModel<ctx, MemModel>;
using PTA = PartialUpdateSolver<LangModel>;
using ObjTy = PTA::ObjTy;
using CallGraphNodeTy = CallGraphNode<ctx>;
using CT = CtxTrait<ctx>;
using GT = llvm::GraphTraits<const CallGraph<ctx>>;
using PtsTy = BitVectorPTS;

}  // namespace pta