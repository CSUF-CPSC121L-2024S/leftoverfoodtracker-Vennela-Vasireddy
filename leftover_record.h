#ifndef LEFTOVER_RECORD_H_
#define LEFTOVER_RECORD_H_

// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>
#include <iostream> 
#include <vector>
class LeftoverRecord {
    // ======================= YOUR CODE HERE =======================
    // Write the LeftoverRecord class here. Refer to your class design for the
    // member variables, constructors, and member functions needed.
    //
    // Note: mark functions that do not modify the member variables
    // as const, by writing `const` after the parameter list.
    // Pass objects by const reference when appropriate.
    // Remember that std::string is an object!
    // ===============================================================

  public:

  void SetDate(const std::string &date);
  void SetMeal(const std::string &meal) ;
  void SetFoodName(const std::string &food_name);
  void SetQuantityInOz(double qty_in_oz);
  void SetLeftoverReason(const std::string &leftover_reason);
  void SetDisposalMechanism(const std::string &disposal_mechanism) ;
  void SetCost(double cost);

  std::string GetDate() const;
  std::string GetMeal() const ;
  std::string GetFoodName() const;
  double GetQuantityInOz() const ;
  std::string GetLeftoverReason() const;
  std::string GetDisposalMechanism() const;
  double GetCost() const;


  private:

  std::string date_;
  std::string meal_;
  std::string food_name_;
  double qty_in_oz_;
  std::string leftover_reason_;
  std::string disposal_mechanism_;
  double cost_;



};

#endif
