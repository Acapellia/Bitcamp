#include <iostream>
#include "CarHandler.h"
using namespace std;

CarHandler::CarHandler(Car* pCar) {
	m_pCar = pCar;
}
CarHandler::~CarHandler(){}
void CarHandler::CarTest() {
	for (int i = 0; i < 10; i++) {
		m_pCar->Driver();
		for (int i = 0; i < 5; i++) m_pCar->Accel();
		for (int i = 0; i < 5; i++) m_pCar->Break();
	}
}
void CarHandler::SpeedUp() {
	for (int i = 0; i < 2; i++)
		m_pCar->Accel();
}
void CarHandler::SpeedDown() {
	for (int i = 0; i < 2; i++)
		m_pCar->Break();
}
void CarHandler::CarStop() {
	for (int i = 0; i < 10; i++)
		m_pCar->Break();
}