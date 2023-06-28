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
// Time Complexity : Worst case로 계산(가장 느려진다면 어느정도인가) n^2 * 4
// Space Complexity : 매개변수 제외 - 3

/* Big O Notation (빅 오 표기법) : 컴퓨터의 성능이나 환경에 영향을 받지 않고, 입력의 갯수에 따라 정량화 측정
  1. 곱하기: 변수를 제외한 상수는 무시
  2. 더하기: 높은 차수만 고려 ( x: 1차, x^2 : 2차)
  3. 일반 숫자는 1
  4. Worst case로 계산

  =점근법(asymtotic notation)

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

