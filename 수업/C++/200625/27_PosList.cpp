#include<iostream>
#include "PosList.h"	
using namespace std;
template<typename T>
PosList<T>::PosList(int arrlen) {
	m_nArrLen = arrlen;
	m_pArray = new T[arrlen];
}
template<typename T>
PosList<T>::~PosList() {
	delete[] m_pArray;
}
template<typename T>
bool PosList<T>::SetPos(int index, T pos) {
	if (index< 0 || index>m_nArrLen) return false;
	m_pArray[index] = pos;
	return true;
}
template<typename T>
bool PosList<T>::GetPos(int index, T& pos) {
	if (index< 0 || index>m_nArrLen) return false;
	pos = m_pArray[index];
	return true;
}