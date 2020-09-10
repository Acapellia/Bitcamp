// class 내부의 변수에 static 키워드를 붙이면 
// 그 class를 통해 생성한 객체들은 모두 같은 변수를 공유 할 수 있다.
#include<iostream>
using namespace std;
#define NAME_LEN 30
class Theater {
private:
	char* m_strName;
	static int m_nViewrCount;
public:
	Theater(char* _Name){
		this->m_strName = new char[NAME_LEN];
		memset(m_strName, 0, NAME_LEN);
		strcpy(m_strName, _Name);
	}
	Theater(const Theater& theater) {
		m_strName = new char[NAME_LEN];
		memset(m_strName, 0, NAME_LEN);
		memcpy(m_strName, theater.m_strName, NAME_LEN);
	}
	~Theater() {
		delete[] m_strName;
	}
	static void AddViewCount() {
		m_nViewrCount++;
	}
	static int GetViewerCount() {
		return m_nViewrCount;
	}
};
int Theater::m_nViewrCount = 0;
int main()
{
	cout << "관객수" << Theater::GetViewerCount() << "명" << endl;
	Theater theater1("단성사");
	Theater theater2("서울극장");
	Theater theater3("명동CGV");

	for (int i = 0; i < 1000000; i++)
		theater1.AddViewCount();
	for (int i = 0; i < 1500000; i++)
		theater2.AddViewCount();
	for (int i = 0; i < 2000000; i++)
		theater3.AddViewCount();
	cout << "관객수 : " << Theater::GetViewerCount() << "명" << endl;
	return 0;
}