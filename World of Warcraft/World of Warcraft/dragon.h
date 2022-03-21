/*********************************************************************************

  * FileName:       dragon.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Dragon
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


#include "warrior.h"


class Dragon: public Warrior
{
private:
	// The strength of dragon
	static int dragon_strength_;
	// The attack of dragon
	static int dragon_attack_;
	// The morale of dragon
	double morale_;

public:
	Dragon(int n, double m);

	/*
	* Gets the strength of dragon
	* @ Return:
	*                  The strength of dragon
	*/
	static int GetDragonStrength();

	/*
	* Sets the dragon strength
	* @ Parameter:
	*       dragon_strength:    The dragon strength
	*/
	static void SetDragonStrength(int dragon_strength);
	
	/*
	* Sets the dragon attack
	* @ Parameter:
	*       dragon_attack:      The dragon attack
	*/
	static void SetDragonAttack(int dragon_attack);
	
	/*
	* Gets the dragon morale
	* @ Return:
	*                  The dragon morale
	*/
	double GetMorale() const;
	
	/*
	* Changes the morale of the dragon
	* @ Parameter:
	*       win:       Either "win" or "not win"
	*/
	void ChangeMorale(const std::string& win);
	
	/*
	* Yells
	* @ Return:
	*                  The yell
	*/
	std::string Yell() const;
};


