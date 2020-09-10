#pragma once
#include<iostream>
#include "Car.h"
using namespace std;

class HyundaiCar :public Car {
public:
	virtual void Driver();
	virtual void Accel();
	virtual void Break();
};