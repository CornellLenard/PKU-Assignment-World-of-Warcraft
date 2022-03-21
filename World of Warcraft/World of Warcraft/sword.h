/*********************************************************************************

  * FileName:       sword.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Sword
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


class Sword
{
private:
	// The sword attack
	int attack_;

public:
	Sword(int a);
	Sword(const Sword& s);

	/*
	* Gets the sword attack
	* @ Return:
	*                  The sword attack
	*/
	int GetAttack() const;
	
	/*
	* Uses sword
	* @ Return:
	*                  Sword attack
	*/
	int UseSword();
};


