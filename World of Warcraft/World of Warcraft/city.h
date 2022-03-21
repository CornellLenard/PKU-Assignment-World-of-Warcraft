/*********************************************************************************

  * FileName:       city.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class City
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


#include <iostream>


class City
{
private:
	// The number of the red warrior in the city
	int red_warrior_num_;
	// The type of the red warrior in the city
	std::string red_warrior_type_;
	// The number of the blue warrior in the city
	int blue_warrior_num_;
	// The type of the blue warrior in the city
	std::string blue_warrior_type_;
	// The strength of the city
	int strength_;
	// The flag of the city
	std::string flag_;
	// Stores which side won in last fight
	std::string last_win_;
	// Whether headquarter should award the red warrior in the city
	bool should_award_red_warrior_;
	// Whether headquarter should award the blue warrior in the city
	bool should_award_blue_warrior_;

public:
	City();

	/*
	* Gets the number of warrior in the city
	* @ Parameter:
	*       side:      From which side is the warrior
	* @ Return:
	*                  The number of warrior in the city
	*/
	int GetWarriorNumber(const std::string& side) const;

	/*
	* Sets the number of warrior in the city
	* @ Parameter:
	*       num:       The number
	*       side:      From which side is the warrior
	*/
	void SetWarriorNumber(int num, const std::string& side);

	/*
	* Gets the type of warrior in the city
	* @ Parameter:
	*       side:      From which side is the warrior
	* @ Return:
	*                  The type of warrior in the city
	*/
	std::string GetWarriorType(const std::string& side) const;

	/*
	* Sets the type of warrior in the city
	* @ Parameter:
	*       type:      The type
	*       side:      From which side is the warrior
	*/
	void SetWarriorType(const std::string& type, const std::string& side);

	/*
	* Gets the strength of the city
	* @ Return:
	*                  The strength of the city
	*/
	int GetStrength() const;

	/*
	* Gets the flag of the city
	* @ Return:
	*                  The flag of the city
	*/
	std::string GetFlag() const;

	/*
	* Sets the flag of the city
	* @ Parameter:
	*       flag:      The flag
	* @ Return:
	*                  The message that the flag is raised
	*/
	std::string SetFlag(const std::string& flag);

	/*
	* Gets the winner side of last fight
	* @ Return:
	*                  The winner side of last fight
	*/
	std::string GetLastWin() const;

	/*
	* Sets the winner side of last fight
	* @ Parameter:
	*       last_win:  The winner side of last fight
	*/
	void SetLastWin(const std::string& last_win);

	/*
	* Whether headquarter should award warrior
	* @ Parameter:
	*       side:      From which side is the warrior
	* @ Return:
	*                  Whether headquarter should award warrior
	*/
	bool ShouldAwardWarrior(const std::string& side) const;

	/*
	* Sets whether headquarter should award warrior
	* @ Parameter:
	*       should:    Whether headquarter should award warrior
	*       side:      From which side is the warrior
	*/
	void SetShouldAwardWarrior(const std::string& should, const std::string& side);

	/*
	* City produces strength
	*/
	void ProduceStrength();

	/*
	* The strength of the city is taken
	* @ Return:
	*                  The strength taken
	*/
	int BeTakenStrength();

	/*
	* Adds warrior to the city
	* @ Parameter:
	*       num:       The warrior number
	*       side:      From which side is the warrior
	*       type:      The warrior type
	*/
	void AddWarrior(int num, const std::string& side, const std::string& type);

	/*
	* Removes warrior from the city
	* @ Parameter:
	*       num:       The warrior number
	*       side:      From which side is the warrior
	*/
	void RemoveWarrior(int num, const std::string& side);
};


