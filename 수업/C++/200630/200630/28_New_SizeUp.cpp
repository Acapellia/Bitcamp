/*처음에 5개의 int배열 공간
꽉차면 5개씩 추가 할당
*/
#include<iostream>
using namespace std;
#define ALLOC_SIZE 5
void main()
{
	int *arr = new int[ALLOC_SIZE]();
	int allocSize = ALLOC_SIZE;
	int cnt=0;
	while (1) {
		cout << "정수를 입력하세요 : ";
		int num;
		cin >> num;
		if (num == -1) { cout << "입력을 종료합니다." << endl;  break; }
		arr[cnt++] = num;
		if (allocSize == cnt) {
			int* temp = new int[ALLOC_SIZE + allocSize]();
			/*for (int i = 0; i < allocSize; i++) {
				temp[i] = arr[i];
			}*/
			// 배열 복사
			memcpy(temp, arr, sizeof(int)*allocSize);
			allocSize += ALLOC_SIZE;
			delete[] arr;
			arr = temp;
		}
	}
	cout << "입력된 정수의 개수 : " << cnt << endl;
	cout << "입력된 정수 : " <<  endl;
	for (int i = 0; i < cnt; i++) {
		cout << arr[i]<<" ";
	}
	cout << endl;
	delete[] arr;
}