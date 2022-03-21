/*********************************************************************************

  * FileName:       wolf.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Wolf
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


#include "warrior.h"


class Wolf: public Warrior
{
private:
	// The strength of wolf
	static int wolf_strength_;
	// The attack of wolf
	static int wolf_attack_;

public:
	Wolf(int n);

	/*
	* Gets the strength of wolf
	* @ Return:
	*                  The strength of wolf
	*/
	static int GetWolfStrength();

	/*
	* Sets the wolf strength
	* @ Parameter:
	*       wolf_strength:      The wolf strength
	*/
	static void SetWolfStrength(int wolf_strength);

	/*
	* Sets the wolf attack
	* @ Parameter:
	*       wolf_attack:        The wolf attack
	*/
	static void SetWolfAttack(int wolf_attack);

	/*
	* Takes weapons
	* @ Parameter:
	*       sword:     The sword
	*       bomb:      The bomb
	*       arrow:     The arrow
	*/
	void TakeWeapon(Sword* sword, Bomb* bomb, Arrow* arrow);
};


