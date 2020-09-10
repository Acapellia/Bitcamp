#include<iostream>
#include "Position.h"

using namespace std;

Position::Position() {
	m_nX = 0;
	m_nY = 0;
}
Position::Position(int x, int y) {
	m_nX = x;
	m_nY = y;
}
Position::~Position() {}
void Position::ShowPosition() {
	cout << "[" << m_nX << "," << m_nY << "]" << endl;
}
Position& Position::operator++() {
	++m_nX;
	++m_nY;
	return *this;
}
Position Position::operator++(int) {
	Position temp = *this;
	++m_nX; ++m_nY;
	return temp;
}
// Position pos와 같은 방법으로 매개변수를 받아오면 pos가 넘겨 받을 때 클래스를 통째로 복사하므로 용량을 많이 먹는다
// const Postion& pos 처럼 값이 변경되지 않음을 명확히 한후 주소를 넘겨받으면 복사를 하지 않는다.
Position Position::operator+(const Position& pos) {
	Position temp;
	temp.m_nX = m_nX + pos.m_nX;
	temp.m_nY += m_nY + pos.m_nY;
	return temp;
}
Position Position::operator*(int num) {
	Position temp;
	temp.m_nX = m_nX * num;
	temp.m_nY += m_nY * num;
	return temp;
}
Position operator*(int num, Position pos) {
	Position temp;
	temp.m_nX = num * pos.m_nX;
	temp.m_nY = num * pos.m_nY;
	return temp;
}