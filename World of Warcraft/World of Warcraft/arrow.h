/*********************************************************************************

  * FileName:       arrow.h
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The header file for the class Arrow
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#pragma once


class Arrow
{
private:
	// The attack of arrow
	static int arrow_attack_;
	// The capacity of arrow
	int capacity_;

public:
	Arrow();
	Arrow(const Arrow& a);

	/*
	* Gets the arrow attack
	* @ Return:
	*                  The arrow attack
	*/
	static int GetArrowAttack();
	
	/*
	* Sets the arrow attack
	* @ Parameter:
	*       arrow_attack:   The arrow attack
	*/
	static void SetArrowAttack(int arrow_attack);
	
	/*
	* Gets the arrow capacity
	* @ Return:
	*                  The arrow capacity
	*/
	int GetCapacity() const;
	
	/*
	* Uses the arrow
	* @ Return:
	*                  Arrow attack
	*/
	int UseArrow();
};


