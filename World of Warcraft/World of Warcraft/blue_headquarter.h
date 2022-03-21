/*********************************************************************************

  * FileName:       blue_headquarter.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class BlueHeadquarter
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


#include "headquarter.h"


class BlueHeadquarter: public Headquarter
{
public:
	BlueHeadquarter(int s, int data[]);
	~BlueHeadquarter();

	/*
	* Creates warrior
	* @ Parameter:
	*       clock:     The reference clock
	* @ Return:
	*                  Indicates whether the creation is successful
	*/
	std::pair<int, std::string> CreateWarrior(const std::string& clock);
};


