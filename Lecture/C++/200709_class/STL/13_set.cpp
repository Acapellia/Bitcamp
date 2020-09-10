#include<iostream>
#include<set>
using namespace std;
void main()
{
	string fruitArr[] = {
		"kiwi", "apple", "pineapple", "orange", "lemon","banana"
	};

	set<string> fruitSet;
	int arrLen = sizeof(fruitArr) / sizeof(fruitArr[0]);
	for (int i = 0; i < arrLen; i++) {
		fruitSet.insert(fruitArr[i]);
	}

	set<string>::iterator it = fruitSet.begin();
	while (it != fruitSet.end()) {
		cout << *it++ << " ";
	}cout << endl;

	string testArr[] = { "strawberry", "banana", "watermelon", "apple", "melon", "kiwi" };
	int testLen = sizeof(testArr) / sizeof(testArr[0]);

	for (int i = 0; i < testLen; i++) {
		set<string>::iterator found = fruitSet.find(testArr[i]);
		if (found != fruitSet.end())
			cout << *found << "는 fruitSet에 존재한다." << endl;
	}
}