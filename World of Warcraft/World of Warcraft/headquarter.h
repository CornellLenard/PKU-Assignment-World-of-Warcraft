/*********************************************************************************

  * FileName:       headquarter.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Headquarter
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


#include <map>
#include <iomanip>
#include "dragon.h"
#include "ninja.h"
#include "iceman.h"
#include "lion.h"
#include "wolf.h"


class Headquarter
{
protected:
	// The clock indicating when to create warriors
	int creation_clock_;
	// Stores the type of warriors according to the order of creating them
	std::string warrior_creation_guide_type_[5];
	// Stores the strength of warriors according to the order of creating them
	int warrior_creation_guide_strength_[5];
	// The strength of headquarter
	int strength_;
	// The created dragons
	std::map<int, Dragon*> dragons_;
	// The created ninjas
	std::map<int, Ninja*> ninjas_;
	// The created icemans
	std::map<int, Iceman*> icemans_;
	// The created lions
	std::map<int, Lion*> lions_;
	// The created wolfs
	std::map<int, Wolf*> wolfs_;
	// Stores the largest number of the warrior created
	int number_record_;

public:
	Headquarter(int s);
	virtual ~Headquarter();

	/*
	* Gets the strength of the headquarter
	* @ Return:
	*                  The strength of the headquarter
	*/
	int GetStrength() const;

	/*
	* The headquarter takes strength
	* @ Parameter:
	*       strength:  The strength
	*/
	void TakeStrength(int strength);

	/*
	* Reports the strength of headquarter
	* @ Return:
	*                  The strength of the headquarter
	*/
	int ReportStrength() const;

	/*
	* The headquarter awards strength to a warrior
	* @ Return:
	*                  The awarded strength
	*/
	int AwardStrength();

	/*
	* Gets the warrior
	* @ Parameter:
	*       num:       The warrior number
	*       type:      The warrior type
	* @ Return:
	*                  The warrior
	*/
	Warrior* GetWarrior(int num, const std::string& type);

	/*
	* Removes warrior
		* @ Parameter:
	*       num:       The warrior number
	*       type:      The warrior type
	*/
	void RemoveWarrior(int num, std::string type);
};


