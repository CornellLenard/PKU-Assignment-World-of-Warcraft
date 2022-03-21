/*********************************************************************************

  * FileName:       warrior.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Warrior
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


#include <string>
#include "sword.h"
#include "bomb.h"
#include "arrow.h"


class Warrior
{
protected:
	// The number of warrior
	int number_;
	// The strength of warrior
	int strength_;
	// The attack of warrior
	int attack_;
	// The sword that the warrior (might) has
	Sword* sword_;
	// The bomb that the warrior (might) has
	Bomb* bomb_;
	// The arrow that the warrior (might) has
	Arrow* arrow_;

public:
	Warrior(int n);
	virtual ~Warrior();

	/*
	* Gets the number of warrior
	* @ Return:
	*                  The number of warrior
	*/
	int GetNumber() const;
	
	/*
	* Gets the strength of warrior
	* @ Return:
	*                  The strength of warrior
	*/
	int GetStrength() const;
	
	/*
	* Gets the attack of warrior
	* @ Return:
	*                  The attack of warrior
	*/
	int GetAttack() const;
	
	/*
	* Verifies whether the warrior has sword
	* @ Return:
	*                  Whether the warrior has sword
	*/
	bool HasSword() const;
	
	/*
	* Verifies whether the warrior has bomb
	* @ Return:
	*                  Whether the warrior has bomb
	*/
	bool HasBomb() const;
	
	/*
	* Verifies whether the warrior has arrow
	* @ Return:
	*                  Whether the warrior has arrow
	*/
	bool HasArrow() const;
	
	/*
	* Gets the sword of the warrior
	* @ Return:
	*                  The sword of the warrior
	*/
	Sword* GetSword() const;
	
	/*
	* Gets the bomb of the warrior
	* @ Return:
	*                  The bomb of the warrior
	*/
	Bomb* GetBomb() const;
	
	/*
	* Gets the arrow of the warrior
	* @ Return:
	*                  The arrow of the warrior
	*/
	Arrow* GetArrow() const;

	/*
	* The warrior is attacked
	* @ Parameter:
	*       damage:    The damage to the warrior
	*/
	void BeAttacked(int damage);
	
	/*
	* The warrior receives strength
	* @ Parameter:
	*       strength:  The strength that the warrior receives
	*/
	void ReceiveStrength(int strength);
	
	/*
	* The warrior uses sword
	* @ Return:
	*                  The attack
	*/
	int UseSword();
	
	/*
	* The warrior uses bomb
	*/
	void UseBomb();
	
	/*
	* The warrior uses arrow
	* @ Return:
	*                  The attack
	*/
	int UseArrow();
	
	/*
	* The warrior reports his weapons
	*/
	void ReportWeapons() const;
};


