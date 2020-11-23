#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

vector<int> list, list2;

void Swap(int index1, int index2)
{
	int mid = list[index1];
	list[index1] = list[index2];
	list[index2] = mid;

	mid = list2[index1];
	list2[index1] = list2[index2];
	list2[index2] = mid;
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
				Swap(j, j + 1);
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