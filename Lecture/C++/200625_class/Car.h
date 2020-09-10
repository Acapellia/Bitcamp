#pragma once
class Car {
public:
	virtual void Driver() = 0;
	virtual void Accel() = 0;
	virtual void Break() = 0;
};