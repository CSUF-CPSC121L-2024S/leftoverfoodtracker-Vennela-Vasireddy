// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>

#include "leftover_tracker.h"
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
    for (int i = 0; i < leftover_records_.size(); i++) {
      if (leftover_records_.at(i).GetDate() == record.GetDate() &&
          leftover_records_.at(i).GetMeal() == record.GetMeal() &&
          leftover_records_.at(i).GetFoodName() == record.GetFoodName() &&
          leftover_records_.at(i).GetQuantityInOz() ==
              record.GetQuantityInOz() &&
          leftover_records_.at(i).GetLeftoverReason() ==
              record.GetLeftoverReason() &&
          leftover_records_.at(i).GetDisposalMechanism() ==
              record.GetDisposalMechanism() &&
          leftover_records_.at(i).GetCost() == record.GetCost()) {
        return false;
      }
    }
    leftover_records_.push_back(record);
    return true;
  }