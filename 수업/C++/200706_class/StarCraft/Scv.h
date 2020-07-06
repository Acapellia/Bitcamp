#pragma once
#include "StarUnit.h"
#include<iostream>
using namespace std;
class Scv : public StarUnit
{
public:
	virtual void move();
	virtual void attack();
	virtual void die();
};

