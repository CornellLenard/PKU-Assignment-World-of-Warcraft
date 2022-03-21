/*********************************************************************************

  * FileName:       city.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class City
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "city.h"


City::City()
{
	red_warrior_num_ = 0;
	red_warrior_type_ = "none";
	blue_warrior_num_ = 0;
	blue_warrior_type_ = "none";
	strength_ = 0;
	flag_ = "none";
	last_win_ = "none";
	should_award_red_warrior_ = false;
	should_award_blue_warrior_ = false;
}


int City::GetWarriorNumber(const std::string& side) const
{
	return (side == "red") ? red_warrior_num_ : blue_warrior_num_;
}


void City::SetWarriorNumber(int num, const std::string& side)
{
	(side == "red" ? red_warrior_num_ : blue_warrior_num_) = num;
}


std::string City::GetWarriorType(const std::string& side) const
{
	return (side == "red") ? red_warrior_type_ : blue_warrior_type_;
}


void City::SetWarriorType(const std::string& type, const std::string& side)
{
	(side == "red" ? red_warrior_type_ : blue_warrior_type_) = type;
}


int City::GetStrength() const
{
	return strength_;
}


std::string City::GetFlag() const
{
	return flag_;
}


std::string City::SetFlag(const std::string& flag)
{
	flag_ = flag;
	return flag + " flag raised ";
}


std::string City::GetLastWin() const
{
	return last_win_;
}


void City::SetLastWin(const std::string& last_win)
{
	last_win_ = last_win;
}


bool City::ShouldAwardWarrior(const std::string& side) const
{
	return (side == "red") ? should_award_red_warrior_ : should_award_blue_warrior_;
}


void City::SetShouldAwardWarrior(const std::string& should, const std::string& side)
{
	if (side == "red")
		should_award_red_warrior_ = (should == "true") ? true : false;
	else
		should_award_blue_warrior_ = (should == "true") ? true : false;
}


void City::ProduceStrength()
{
	strength_ += 10;
}


int City::BeTakenStrength()
{
	int res = strength_;
	strength_ = 0;
	return res;
}


void City::AddWarrior(int num, const std::string& side, const std::string& type)
{
	(side == "red" ? red_warrior_num_ : blue_warrior_num_) = num;
	(side == "red" ? red_warrior_type_ : blue_warrior_type_) = type;
}


void City::RemoveWarrior(int num, const std::string& side)
{
	(side == "red" ? red_warrior_num_ : blue_warrior_num_) = 0;
	(side == "red" ? red_warrior_type_ : blue_warrior_type_) = "none";
}


