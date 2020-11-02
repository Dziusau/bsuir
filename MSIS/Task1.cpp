#include <iostream>
using namespace std;

void viewArray(int* arr, int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		cout << arr[i] << "\t";//����� ��������� �������
	}
	cout << endl;
}
void bubbleSort(int* arr, int arrayLength) {//������� ����������� ����������
	for (int i = 0; i < arrayLength - 1; i++) {
		for (int j = i + 1; j < arrayLength; j++) {
			if (arr[j] < arr[i]) {
				int buf = arr[i];
				arr[i] = arr[j];
				arr[j] = buf;
			}
		}
	}
}
int main() {
	cout << "Enter values of the first nine elements of the array: " << endl;
	int arr[10];
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];//���� ��������� �������
	}
	cout << "The tenth element will be 0 by default!!!" << endl;
	arr[9] = 0;//�������� 10-��� �������� ������� �� ���������
	cout << "Raw array:\t";
	viewArray(arr, 10);//����� ��������� �������
	bubbleSort(arr, 9);//���������� ������ 9 ��������� �������
	cout << "Sorted array:\t";
	viewArray(arr, 10);//����� ���������������� �������
	cout << "Enter value of the tenth element: ";
	cin >> arr[9];//���� �������� 10-��� �������� �������
	int i = 0;//�������� ��� �������� ������� �����	������� 10-��� ��������
	for (; arr[i] <= arr[9]; i++);//����� ����� ������� 10-��� ��������
	bubbleSort(arr, 10);//���������� �������
	cout << "Result:\t\t";
	viewArray(arr, 10);//����� �������� �������
	cout << "New position of the tenth element: " << i + 1 << endl;//����� ����� ������� 10-��� ��������
}