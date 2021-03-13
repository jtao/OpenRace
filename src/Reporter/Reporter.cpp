#include "Reporter.h"

#include "llvm/IR/DebugInfoMetadata.h"

using namespace race;

namespace {

SourceLoc getSourceLoc(const Event *e) {
  auto const &loc = e->getInst()->getDebugLoc();
  if (auto diloc = loc.get()) {
    return SourceLoc(diloc);
  }

  return SourceLoc();
}

}  // namespace

llvm::raw_ostream &race::operator<<(llvm::raw_ostream &os, const SourceLoc &loc) {
  os << loc.filename << ":" << loc.line << ":" << loc.col;
  return os;
}

void Reporter::collect(const WriteEvent *e1, const MemAccessEvent *e2) { races.emplace_back(std::make_pair(e1, e2)); }

Report Reporter::getReport() const {
  Report report;
  for (auto const &racepair : races) {
    report.emplace_back(getSourceLoc(racepair.first), getSourceLoc(racepair.second));
  }
  return report;
}

bool race::reportContains(const Report &report, Race race) {
  return std::find(report.begin(), report.end(), race) != report.end();
}

bool race::reportContains(const Report &report, std::vector<Race> races) {
  for (auto const &race : report) {
    auto it = std::find(races.begin(), races.end(), race);
    if (it != races.end()) {
      races.erase(it);
    }
  }

  return races.empty();
}
