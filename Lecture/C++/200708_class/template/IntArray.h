#pragma once
class IntArray
{
private:
	int* arr;
	int arrSize;
public:
	IntArray(int arrSize = 100);
	~IntArray();
	bool setInt(int idx, int value);
	bool getInt(int idx, int& value);
};

