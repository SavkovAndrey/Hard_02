#include <iomanip>
#include <iostream>
#include <time.h>
#include <chrono> 
#include <algorithm>
#include <numeric>
#include <ctime>
using namespace std;
//---------------------������� � ���������---------------------------------------

/*
��������� ������ ����������� ������� ����� ���������.
���������� �������� ��������� �������������, � ������� ���������� ��������� ����� rand.
������ �������� ���������� �������� ��� ��������� �������,
������� ���������� �������� ��������������� ������������ ���������(��������, 
���������� ��������� ����� ��� �����, ������� ���� ��������� �� ����������).
��������� ��������� ���������� �� ������� �������������.

1) ���������� �������.������� ����������� �����  ������������ �������� � �������,
����� ���� ����������� �� ��������� ����������.����� ���� ������� ��������� � �������,
� ��� ����������� �� ��� �������� ������������� �� ���� ������� �����.
����� ����� ����������� ������� ���������  �  ��������� �������,
������� ������������ ����� ������ ��������� �����.

2) ������ - ����������.�������� � ������ � �������� ������������ ������������ � ������� ������ �����.

*/


float Sort1(int *&arr, int size);

float Sort2(int *&arr, int size);


//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------���� �����-------------------------------------

	float t1 = 0, t2 = 0;  // ����� ���������� ������ ����������

	int size;
	cout << "Enter the size of the arry: ";
	cin >> size;
	int* arr = new int[size];    

	for (int i = 0; i < size; i++)
	{
		arr[i] = 1 + rand() % 30;
		cout << setw(4) << arr[i];
	}
	cout << endl;

	int* copy_arr = new int[size];   // ������� ����� ������� , ��� ��������� �� ������ �������
	
	for (int i = 0; i < size; i++)
	{
		copy_arr[i] = arr[i];
	}

	t1 = Sort1(arr, size);

	t2 = Sort2(copy_arr, size);

	if (t1 > t2)
	{
		cout << endl << "Method 2 is more effective" << endl;
	}
	else if (t1 < t2)
	{
		cout << endl << "Method 1 is more effective" << endl;
	}
	else if (t1 = t2)
	{
		cout << endl << "the methods are equivalent" << endl;
	}

	delete[] arr;
	delete[] copy_arr;

	cout << endl << "runtime = " << clock() / 1000.0 << endl;

	system("pause");
	return 0;
}


float Sort1(int *&arr, int size)
{
	
	float start_time_1 = clock(); // ��������� �����

	int number_min = 0;


	for (int temp_size = size; temp_size > 0 ; temp_size--)
	{
	int min = 31;     // ���� "������ ��������"

		// ����� ������������ � ���������� ��� �� ��������� ����������
		for (int i = 0; i < temp_size; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
				number_min = i;
			}
		}


		// cout << " �������: " << number_min << " : " << min << endl;   // �������

		// �������� ������� � ������ ������������ � ����� �������

		for (int i = number_min; i < temp_size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[temp_size - 1] = min;


		// for (int i = 0; i < size; i++)     //�������
		// {                                  //
		//	cout << setw(4) << arr[i];        //
		// }                                  //
		//  cout << endl;                     //�������

	}

	cout << endl << "array sorted by method 1: " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << arr[i];
	}
	cout << endl << endl;

	float end_time_1 = clock(); // �������� �����
	float search_time_1 = end_time_1 - start_time_1; // ������� �����
	cout << endl << "Sort 1 time: " << search_time_1 << endl;

	return search_time_1;

}


float Sort2(int*& arr, int size)
{

	float start_time_2 = clock(); // ��������� �����

	//----������

	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
		{
			if (arr[i - 1] < arr[i])
			{
				int buff;
				buff = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = buff;
			}
		}
			leftMark++;


			for (int i = leftMark; i <= rightMark; i++)
			{
				if (arr[i - 1] < arr[i])
				{
					int buff2;
					buff2 = arr[i];
					arr[i] = arr[i - 1];
					arr[i - 1] = buff2;
				}
			}
			rightMark--;
	}

	//----������
	cout << endl << "array sorted by method 2: " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << arr[i];
	}
	cout << endl << endl;

	float end_time_2 = clock(); // �������� �����
	float search_time_2 = end_time_2 - start_time_2; // ������� �����
	cout << endl << "Sort 2 time: " << search_time_2 << endl;

	return search_time_2;

}