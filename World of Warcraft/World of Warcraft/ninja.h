/*********************************************************************************

  * FileName:       ninja.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Ninja
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


#include "warrior.h"


class Ninja: public Warrior
{
private:
	// The strength of ninja
	static int ninja_strength_;
	// The attack of ninja
	static int ninja_attack_;

public:
	Ninja(int n);

	/*
	* Gets the strength of ninja
	* @ Return:
	*                  The strength of ninja
	*/
	static int GetNinjaStrength();

	/*
	* Sets the ninja strength
	* @ Parameter:
	*       ninja_strength:     The ninja strength
	*/
	static void SetNinjaStrength(int ninja_strength);

	/*
	* Sets the ninja attack
	* @ Parameter:
	*       ninja_attack:       The ninja attack
	*/
	static void SetNinjaAttack(int ninja_attack);
};


