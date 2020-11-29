#include <iostream>
using namespace std;

int average_salary(const int* arr, int size) {
	int average = 0;
	for (int i = 0; i < size; i++) {
		average += arr[i];
	}
	average = average / size;
	
	return average;
}

int main()
{
	//Works with integers
	int amount;
	cout << "Amount of people: ";
	cin >> amount;
	int *arr = new int[amount];
	int salary;
	for (int z = 0; z < amount; z++) {
		cout << "Salary of person: " << endl;
		cin >> salary;
		arr[z] = salary;
	}
	cout << "Average salary is: " << average_salary(arr, amount);
	return 0;
}

