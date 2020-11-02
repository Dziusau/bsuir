#include <iostream>
using namespace std;

void viewArray(int* arr, int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		cout << arr[i] << "\t";//Вывод элементов массива
	}
	cout << endl;
}
void bubbleSort(int* arr, int arrayLength) {//Обычная пузырьковая сортировка
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
		cin >> arr[i];//Ввод элементов массива
	}
	cout << "The tenth element will be 0 by default!!!" << endl;
	arr[9] = 0;//Значение 10-ого элемента массива по умолчанию
	cout << "Raw array:\t";
	viewArray(arr, 10);//Вывод исходного массива
	bubbleSort(arr, 9);//Сортировка первых 9 элементов массива
	cout << "Sorted array:\t";
	viewArray(arr, 10);//Вывод отсортированного массива
	cout << "Enter value of the tenth element: ";
	cin >> arr[9];//Ввод значения 10-ого элемента массива
	int i = 0;//Итератор для хранения индекса новой	позиции 10-ого элемента
	for (; arr[i] <= arr[9]; i++);//Поиск новой позиции 10-ого элемента
	bubbleSort(arr, 10);//Сортировка массива
	cout << "Result:\t\t";
	viewArray(arr, 10);//Вывод готового массива
	cout << "New position of the tenth element: " << i + 1 << endl;//Вывод новой позиции 10-ого элемента
}