#include <iostream>
#include "CarHandler.h"
#include "HyundaiCar.h"
#include "KiaCar.h"
using namespace std;

int main()
{
	HyundaiCar hCar;
	KiaCar kCar;
	CarHandler carH(&kCar);
	carH.CarTest();
	carH.SpeedUp();
	carH.SpeedDown();
	carH.CarStop();
	return 0;
}