#include <iostream>
#include <chrono>


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
		for (int j = 0; j < count; j++)
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
// Time Complexity : Worst case�� ���(���� �������ٸ� ��������ΰ�) n^2 * 4
// Space Complexity : �Ű����� ���� - 3

/* Big O Notation (�� �� ǥ���) : ��ǻ���� �����̳� ȯ�濡 ������ ���� �ʰ�, �Է��� ������ ���� ����ȭ ����
  1. ���ϱ�: ������ ������ ����� ����
  2. ���ϱ�: ���� ������ ��� ( x: 1��, x^2 : 2��)
  3. �Ϲ� ���ڴ� 1
  4. Worst case�� ���

  =���ٹ�(asymtotic notation)

  ex) O(n+3) = O(n^1 + 3 * n^0) = O(n)
      O(2) = O(1) 
	  O(Time Complexity) : O(4 * n ^ 2) = o(n^2)
	  Space Complexity : O(3) = O(1)
  */

int main()
{
	const int ARRAY_COUNT{ 10 };
	int scores[ARRAY_COUNT]{ 20,10,40,15,30,70,90,80,50 };

	auto startTime = std::chrono::system_clock::now();
	Sort(scores, ARRAY_COUNT, Asscending);
	auto endTime = std::chrono::system_clock::now();

	auto duration = endTime - startTime;

	std::cout << "Sort() runs : " << duration.count() << "ms" << std::endl;
}

