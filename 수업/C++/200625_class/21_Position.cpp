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
// Position pos�� ���� ������� �Ű������� �޾ƿ��� pos�� �Ѱ� ���� �� Ŭ������ ��°�� �����ϹǷ� �뷮�� ���� �Դ´�
// const Postion& pos ó�� ���� ������� ������ ��Ȯ�� ���� �ּҸ� �Ѱܹ����� ���縦 ���� �ʴ´�.
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