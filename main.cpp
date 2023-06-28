#include <iostream>

using Comparison = bool (*)(int, int);

bool Asscending(int x, int y)
{
	return x > y;
}

bool descending(int x, int y)
{
	return x < y;
}

void Sort(int numbers[], int count, Comparison f)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = i + i; j < count; j++)
		{
			if (f(numbers[i], numbers[j]))
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

int main()
{
	const int ARRAY_COUNT{ 10 };
	int scores[ARRAY_COUNT]{ 20,10,40,15,30,70,90,80,50 };

	Sort(scores, ARRAY_COUNT, Asscending);
}