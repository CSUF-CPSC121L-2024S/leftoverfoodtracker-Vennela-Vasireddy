#ifndef LEFTOVER_REPORT_H_
#define LEFTOVER_REPORT_H_

// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>
#include <iostream> 
#include <vector>
#include "leftover_record.h"

class LeftoverReport {
 public:
  LeftoverReport(){};
  LeftoverReport(const std::vector<LeftoverRecord>& leftover_records)
      : leftover_records_(leftover_records){};


  std::vector<std::string> MostCommonlLeftover() const {
    return most_common_leftover_;
  }
  std::vector<std::string> MostCostlyLeftoverProducingMeals() const {
    return most_costly_leftover_producing_meals_;
  }
  double TotalCostOfLeftover() const { return total_cost_of_leftover_; }
  std::vector<std::string> MostCommonLeftoverReasons() const {
    return most_common_leftover_reasons_;
  }
  std::vector<std::string> MostCommonDisposalMechanisms() const {
    return most_common_disposal_mechanism_;
  }
  std::vector<std::string> SuggestLeftoverReductionStrategies() const {
    return suggest_leftover_reduction_strategies_;
  }


 private:
  std::vector<LeftoverRecord> leftover_records_;
  std::vector<std::string> most_common_leftover_;
  std::vector<std::string> most_costly_leftover_producing_meals_;
  double total_cost_of_leftover_;
  std::vector<std::string> most_common_leftover_reasons_;
  std::vector<std::string> most_common_disposal_mechanism_;
  std::vector<std::string> suggest_leftover_reduction_strategies_;
};


#endif
