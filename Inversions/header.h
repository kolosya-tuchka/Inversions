#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

vector<int> list, list2;

void Swap(int& first, int& second)
{
	int mid = first;
	first = second;
	second = mid;
}

void Sort()
{
	int size = list.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (list[j] > list[j + 1])
			{
				Swap(list[j], list[j + 1]);
				Swap(list2[j], list2[j + 1]);
			}
		}
	}
}

void Input()
{
	ifstream inFile("input.txt");
	while (inFile.good())
	{
		int num;
		inFile >> num;
		list.push_back(num);
	}
}

void Output()
{
	ofstream outFile("output.txt");
	for (auto num : list)
	{
		outFile << setw(4) << num;
	}
}

void ToInversions()
{
	int size = list.size();

	for (int i = 0; i < size; ++i)
	{
		int num = 0;
		for (int j = i - 1; j >= 0; --j)
		{
			if (list[i] < list[j])
			{
				++num;
			}
		}
		list2.push_back(num);
	}
	Sort();
	list = list2;
	Output();
}

void FromInversions()
{
	int size = list.size();

	for (int i = 0; i < size; ++i)
	{
		list2.push_back(0);
	}

	for (int i = 0; i < size; ++i)
	{
		int num = list[i], pos = 0;
		while (num != 0)
		{
			if (list2[pos] == 0)
			{
				num--;
			}
			pos++;
		}
		while (list2[pos] != 0)
			pos++;
		list2[pos] = i + 1;
	}
	list = list2;
	Output();
}

void NextPermutation()
{
	int max = list[list.size() - 1], index = -1;

	for (int i = list.size() - 2; i >= 0; --i)
	{
		if (list[i + 1] > max && list[i] < list[i + 1] && index == -1)
		{
			max = list[i + 1];
			index = i;
		}
	}

	if (index < 0)
	{
		cout << "Good)";
		return;
	}

	int min = INT16_MAX, indexMin = list.size() - 1;

	for (int j = list.size() - 1; j > index; --j)
	{
		if (list[j] > list[index] && list[j] < min)
		{
			indexMin = j;
			min = list[j];
		}
	}

	Swap(list[indexMin], list[index]);

	vector <int> nums;
	for (int j = index + 1; j <= index + (list.size() - index) / 2; ++j)
	{
		Swap(list[j], list[list.size() - j + index]);
	}
	Output();
}