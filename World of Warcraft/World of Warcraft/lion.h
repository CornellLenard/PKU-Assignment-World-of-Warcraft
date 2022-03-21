/*********************************************************************************

  * FileName:       lion.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Lion
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


#include "warrior.h"


class Lion: public Warrior
{
private:
	// The strength of lion
	static int lion_strength_;
	// The attack of lion
	static int lion_attack_;
	// The loyalty decrease of lion
	static int loyalty_decrease_;
	// The loyalty of lion
	int loyalty_;

public:
	Lion(int n, int l);

	/*
	* Gets the strength of lion
	* @ Return:
	*                  The strength of lion
	*/
	static int GetLionStrength();

	/*
	* Sets the lion strength
	* @ Parameter:
	*       lion_strength:      The lion strength
	*/
	static void SetLionStrength(int lion_strength);

	/*
	* Sets the lion attack
	* @ Parameter:
	*       lion_attack:        The lion attack
	*/
	static void SetLionAttack(int lion_attack);
	
	/*
	* Sets the lion loyalty decrease
	* @ Parameter:
	*       loyalty_decrease:   The loyalty decrease
	*/
	static void SetLionLoyaltyDecrease(int loyalty_decrease);

	/*
	* Gets the loyalty of lion
	* @ Return:
	*                  The loyalty of lion
	*/
	int GetLoyalty() const;

	/*
	* Changes the loyalty of lion
	* @ Parameter:
	*       win:       Either "win" or "not win"
	*/
	void ChangeLoyalty(const std::string& win);
};


