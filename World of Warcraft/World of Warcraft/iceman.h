/*********************************************************************************

  * FileName:       iceman.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Iceman
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


#include "warrior.h"


class Iceman: public Warrior
{
private:
	// The strength of iceman
	static int iceman_strength_;
	// The attack of iceman
	static int iceman_attack_;
	// Records steps
	int march_record_;

public:
	Iceman(int n);

	/*
	* Gets the strength of iceman
	* @ Return:
	*                  The strength of iceman
	*/
	static int GetIcemanStrength();

	/*
	* Sets the iceman strength
	* @ Parameter:
	*       iceman_strength:    The iceman strength
	*/
	static void SetIcemanStrength(int iceman_strength);

	/*
	* Sets the iceman attack
	* @ Parameter:
	*       iceman_attack:      The iceman attack
	*/
	static void SetIcemanAttack(int iceman_attack);

	/*
	* The special gift of iceman
	*/
	void IcemanSpecialGift();
};


