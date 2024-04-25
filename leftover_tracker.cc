// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>

#include "leftover_tracker.h"

#include <algorithm>
#include <iostream>
#include <vector>

// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (leftover_tracker.h), only
// if you didn't implement them inline within leftover_tracker.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the LeftoverTracker
// class.
// ===================================================================

bool LeftoverTracker::AddRecord(const LeftoverRecord &record) {
  for (auto & leftover_record : leftover_records_) {
    if (leftover_record.GetDate() == record.GetDate() &&
        leftover_record.GetMeal() == record.GetMeal() &&
        leftover_record.GetFoodName() == record.GetFoodName() &&
        leftover_record.GetQuantityInOz() == record.GetQuantityInOz() &&
        leftover_record.GetLeftoverReason() ==
            record.GetLeftoverReason() &&
        leftover_record.GetDisposalMechanism() ==
            record.GetDisposalMechanism() &&
        leftover_record.GetCost() == record.GetCost()) {
      return false;
    }
  }
  leftover_records_.push_back(record);
  return true;
}

LeftoverReport LeftoverTracker::GetLeftoverReport() const {
  LeftoverReport report{leftover_records_};
  return report;
}
