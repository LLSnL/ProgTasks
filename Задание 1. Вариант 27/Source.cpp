#include <iostream>
#include <random>

using namespace std;

int32_t* RandomArray(int32_t* array, size_t num, int32_t min, int32_t max)
{
	random_device rd;
	mt19937 gen(rd());

	const uniform_int_distribution<int32_t> MinMax(min, max);

	for (size_t i = 0; i < num;++i) 
	{
		array[i] = MinMax(gen);
	}
	return array;
}

void PrintArray(int32_t* array, size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int32_t* SortArray(int32_t* array, size_t num)
{
	int32_t* newarray = new int[num];

	for (size_t i = 0; i < num; ++i) 
	{
		newarray[i] = array[i];
	}

	for (size_t i = 1; i < num; ++i)
	{
		int32_t pos = i;

		for (int32_t k = i - 1;k >= 0;--k)
		{
			if (array[i] < array[k])
			{
				newarray[k + 1] = newarray[k];
				newarray[k] = array[i];
				pos -= 1;
			}
			else
				break;
		}

		newarray[pos] = array[i];

		for (size_t i = 0; i < num; ++i)
		{
			array[i] = newarray[i];
		}

	}

	delete[] newarray;

	return array;
}

void SearchElem(int32_t* array, size_t num)
{
	cout << "Please, enter the key" << endl;
	int32_t key;
	cin >> key;

	bool error = false;

	int32_t low, medium, high;
	low = 0;
	high = num;
	medium = (high + low) / 2;
	while (array[medium] != key && low < high)
	{
		if (array[medium] < key)
		{
			low = medium;
		}
		else
		{
			high = medium;
		}
		medium = (high + low) / 2;
		if (low == high && array[medium] != key)
		{
			error = true;
			break;
		}
	}
	if (error == false) 
	{
		++medium;
		cout << "Element position is " << medium << endl;
	}
	else
	{
		cout << "This number is not presented in the array." << endl;
	}
}

void Positive(int32_t* array, size_t num)
{
	int32_t q = 0;
	int32_t S = 0;
	for (size_t i = 0; i < num; ++i)
	{
		if (array[i] > 0) 
		{
			q += 1;
			S += array[i];
		}
	}
	cout << "Quantity: " << q << endl;
	cout << "Sum: " << S << endl;
}

int main()
{
	bool exe1 = true;
	do {
		cout << "Please, input which number of the elements you want\n";
		size_t num;
		cin >> num;

		int32_t* array = new int[num];

		cout << "Please, input minimum value of the elements\n";
		int32_t min;
		cin >> min;

		cout << "Please, input maximum value of the elements\n";
		int32_t max;
		cin >> max;

		RandomArray(array, num, min, max);

		bool exe2 = true;
		do
		{
			cout << "Chooce, which action do you want, input:\n1 - to sort array;\n2 - for search element;\n3 - for sum and quantity of positive elements;\n4 - to print array;\n5 - to enter different array;\n0 - to end programm." << endl;
			int32_t choice;
			cin >> choice;

			switch (choice)
			{
				case 1:
				{
					SortArray(array, num);	
					break;
				}
				case 2:
				{
					SearchElem(array, num);
					break;
				}
				case 3:
				{
					Positive(array, num);
					break;
				}
				case 4:
				{
					PrintArray(array, num);
					break;
				}
				case 5:
				{
					exe2 = false;
					break;
				}
				case 0:
				{
					exe1 = false;
					exe2 = false;
					break;
				}
			}

		} while (exe2 == true);
		delete[] array;
	} while (exe1 == true);

	return 0;
}