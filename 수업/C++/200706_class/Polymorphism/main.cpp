#include<iostream>
#include "Human.h"
#include "Developer.h"
using namespace std;
void main()
{
	Developer dev;
	Human* hu = &dev;
	hu->play();

}