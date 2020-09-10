#include <iostream>
using namespace std;
class Position {
private:
	int x, y;
public:
	Position() {}
	Position(int _x, int _y) { x = _x; y = _y; }
	void showPosition() {
		cout << "(" << x << "," << y << ")" << endl;
	}
	Position& operator++() {
		Position temp;
		temp.x = this->x++;
		temp.y = this->y++;
		return temp;
	}
	Position operator++(int) {
		Position temp;
		temp.x = this->x++;
		temp.y = this->y++;
		return *this;
	}
	Position operator+(Position pos) {
		Position temp;
		temp.x = this->x + pos.x;
		temp.y = this->y + pos.y;
		return temp;
	}
	Position operator+(int num) {
		Position temp;
		temp.x = this->x + num;
		temp.y = this->y + num;
		return temp;
	}
};
void main()
{
	Position p1(10,10);
	p1 = p1 + 5;
	p1.showPosition();
}