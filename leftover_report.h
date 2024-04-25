#ifndef LEFTOVER_REPORT_H_
#define LEFTOVER_REPORT_H_

// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "leftover_record.h"

class LeftoverReport {
 public:
  LeftoverReport(const std::vector<LeftoverRecord> &leftover_records)
      : leftover_records_(leftover_records){};

  std::vector<std::string> MostCommonLeftover() const {
    std::map<std::string, int> leftovers;
    std::vector<std::string> most_common_leftover;
    int leftover_frequency = 0;
    for (LeftoverRecord record : leftover_records_) {
      std::string food_name = record.GetFoodName();
      if (leftovers.find(food_name) == leftovers.end()) {
        leftovers[food_name] = 1;
      } else {
        leftovers[food_name] += 1;
      }
      if (leftovers[food_name] > leftover_frequency) {
        leftover_frequency = leftovers[food_name];
      }
    }
    for (std::pair<std::string, int> pair : leftovers) {
      if (pair.second == leftover_frequency) {
        most_common_leftover.push_back(pair.first);
      }
    }
    return most_common_leftover;
  }
  std::vector<std::string> MostCostlyLeftoverProducingMeals() const {
    std::map<std::string, double> costly_meals;
    std::vector<std::string> most_costly_leftover;
    double mostly_costly = 0.0;
    for (LeftoverRecord record : leftover_records_) {
      std::string meal = record.GetMeal();
      if (costly_meals.find(meal) == costly_meals.end()) {
        costly_meals[meal] = record.GetCost();
      } else {
        if (record.GetCost() > costly_meals[meal]) {
          costly_meals[meal] = record.GetCost();
        }
      }
      if (costly_meals[meal] > mostly_costly) {
        mostly_costly = costly_meals[meal];
      }
    }
    for (std::pair<std::string, double> pair : costly_meals) {
      if (pair.second == mostly_costly) {
        most_costly_leftover.push_back(pair.first);
      }
    }
    return most_costly_leftover;
  }
  double TotalCostOfLeftover() const {
    double totalCost = 0.0;
    for (const auto &record : leftover_records_) {
      totalCost += record.GetCost();
    }
    return totalCost;
  }
  std::vector<std::string> MostCommonLeftoverReasons() {
    std::map<std::string, int> common_leftover;
    std::vector<std::string> most_common_leftover_reasons;
    int most_common = 0;

    for (LeftoverRecord record : leftover_records_) {
      std::string reasons = record.GetLeftoverReason();
      if (common_leftover.find(reasons) == common_leftover.end()) {
        common_leftover[reasons] = 1;
      } else {
        common_leftover[reasons] += 1;
      }
      if (common_leftover[reasons] > most_common) {
        most_common = common_leftover[reasons];
      }
    }

    for (std::pair<std::string, int> pair : common_leftover) {
      if (pair.second == most_common) {
        most_common_leftover_reasons.push_back(pair.first);
      }
    }
    most_common_leftover_reasons_ = most_common_leftover_reasons;
    return most_common_leftover_reasons;
  }
  std::vector<std::string> MostCommonDisposalMechanisms() const {
    std::map<std::string, int> most_common_disposal;
    std::vector<std::string> most_common_disposal_mechanisms;
    int most_disposal = 0;

    for (LeftoverRecord record : leftover_records_) {
      std::string mechanisms = record.GetDisposalMechanism();
      if (most_common_disposal.find(mechanisms) == most_common_disposal.end()) {
        most_common_disposal[mechanisms] = 1;
      } else {
        most_common_disposal[mechanisms] += 1;
      }
      if (most_common_disposal[mechanisms] > most_disposal) {
        most_disposal = most_common_disposal[mechanisms];
      }
    }

    for (std::pair<std::string, int> pair : most_common_disposal) {
      if (pair.second == most_disposal) {
        most_common_disposal_mechanisms.push_back(pair.first);
      }
    }
    return most_common_disposal_mechanisms;
  }
  std::vector<std::string> SuggestLeftoverReductionStrategies() const {
    std::vector<std::string> strategies;
    std::vector<std::string> common_reasons = most_common_leftover_reasons_;

    if (common_reasons.empty()) {
      return strategies;
    }

    for (const std::string &reason : common_reasons) {
      if (reason == "Expired") {
        if (std::find(strategies.begin(), strategies.end(),
                      "Donate before expiration") == strategies.end()) {
          strategies.push_back("Donate before expiration");
        }
      }
      if (reason == "Tastes bad") {
        if (std::find(strategies.begin(), strategies.end(),
                      "Try buying less food") == strategies.end()) {
          strategies.push_back("Buy less food");
        }
      }
      if (reason == "Too much left overs") {
        if (std::find(strategies.begin(), strategies.end(), "Buy less food") ==
            strategies.end()) {
          strategies.push_back("Buy less food");
        }
        if (std::find(strategies.begin(), strategies.end(),
                      "Cook small servings") == strategies.end()) {
          strategies.push_back("Cook small servings");
        }
      }
    }
    if (std::find(strategies.begin(), strategies.end(),
                  "Donate before expiration") == strategies.end()) {
      strategies.push_back("Recycle left overs");
    }
    return strategies;
  }

 private:
  const std::vector<LeftoverRecord> &leftover_records_;
  std::vector<std::string> most_common_leftover_;
  std::vector<std::string> most_costly_leftover_producing_meals_;
  double total_cost_of_leftovers_;
  std::vector<std::string> most_common_leftover_reasons_;
  std::vector<std::string> most_common_disposal_mechanisms_;
  std::vector<std::string> suggested_strategies_to_reduce_leftovers_;
};

#endif
