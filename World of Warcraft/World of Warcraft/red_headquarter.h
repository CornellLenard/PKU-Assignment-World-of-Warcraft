/*********************************************************************************

  * FileName:       red_headquarter.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class RedHeadquarter
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


#include "headquarter.h"


class RedHeadquarter: public Headquarter
{
public:
	RedHeadquarter(int s, int data[]);
	~RedHeadquarter();

	/*
	* Creates warrior
	* @ Parameter:
	*       clock:     The reference clock
	* @ Return:
	*                  Indicates whether the creation is successful
	*/
	std::pair<int, std::string> CreateWarrior(const std::string& clock);
};


