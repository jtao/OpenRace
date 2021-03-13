#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>

#include <catch2/catch.hpp>

#include "RaceDetect/RaceDetect.h"
#include "Reporter/Reporter.h"

TEST_CASE("dataracebench", "[integration][dataracebench][omp]") {
  llvm::LLVMContext context;
  llvm::SMDiagnostic err;

  auto module = llvm::parseIRFile("integration/dataracebench/DRB001-antidep1-orig-yes.ll", err, context);
  if (!module) {
    err.print("DRB001", llvm::errs());
  }
  REQUIRE(module.get() != nullptr);

  auto report = race::detectRaces(module.get());

  llvm::errs() << "races\n";
  for (auto const &race : report) {
    llvm::errs() << race.first << " " << race.second << "\n";
  }

  race::Race race = {{"DRB001-antidep1-orig-yes.c", 64, 9}, {"DRB001-antidep1-orig-yes.c", 66, 26}};
  // This check fails when omp fork is not joined correctly
  CHECK(!reportContains(report, race));
}