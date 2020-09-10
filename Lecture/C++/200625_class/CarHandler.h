#pragma once
#include<iostream>
#include "Car.h"
using namespace std;

class CarHandler {
private:
	Car* m_pCar;
public:
	CarHandler(Car* pCar);
	~CarHandler();
public:
	void CarTest();
	void SpeedUp();
	void SpeedDown();
	void CarStop();
};