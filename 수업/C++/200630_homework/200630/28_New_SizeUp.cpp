/*ó���� 5���� int�迭 ����
������ 5���� �߰� �Ҵ�
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
		cout << "������ �Է��ϼ��� : ";
		int num;
		cin >> num;
		if (num == -1) { cout << "�Է��� �����մϴ�." << endl;  break; }
		arr[cnt++] = num;
		if (allocSize == cnt) {
			int* temp = new int[ALLOC_SIZE + allocSize]();
			/*for (int i = 0; i < allocSize; i++) {
				temp[i] = arr[i];
			}*/
			// �迭 ����
			memcpy(temp, arr, sizeof(int)*allocSize);
			allocSize += ALLOC_SIZE;
			delete[] arr;
			arr = temp;
		}
	}
	cout << "�Էµ� ������ ���� : " << cnt << endl;
	cout << "�Էµ� ���� : " <<  endl;
	for (int i = 0; i < cnt; i++) {
		cout << arr[i]<<" ";
	}
	cout << endl;
	delete[] arr;
}