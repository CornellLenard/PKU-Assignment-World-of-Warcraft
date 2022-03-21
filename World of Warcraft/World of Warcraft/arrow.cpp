/*********************************************************************************

  * FileName:       arrow.cpp
  * Author:         Lenard Zhang
  * Version:        V1.00
  * Description:    The implementation of the class Arrow
  * Project:        The project of the PKU C++ Programming

**********************************************************************************/


#include "arrow.h"


int Arrow::arrow_attack_ = 0;


Arrow::Arrow()
{
	capacity_ = 3;
}


Arrow::Arrow(const Arrow& a)
{
	capacity_ = a.capacity_;
}


int Arrow::GetArrowAttack()
{
	return arrow_attack_;
}


void Arrow::SetArrowAttack(int arrow_attack)
{
	arrow_attack_ = arrow_attack;
}


int Arrow::GetCapacity() const
{
	return capacity_;
}


int Arrow::UseArrow()
{
	capacity_ = (capacity_ - 1 < 0) ? 0 : capacity_ - 1;
	return arrow_attack_;
}


