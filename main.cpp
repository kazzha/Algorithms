#include <iostream>

/* Big O Notation (빅 오 표기법) : 컴퓨터의 성능이나 환경에 영향을 받지 않고, 입력의 갯수에 따라 정량화 측정
  1. 곱하기: 변수를 제외한 상수는 무시
  2. 더하기: 높은 차수만 고려 ( x: 1차, x^2 : 2차)
  3. 일반 숫자는 1
  4. Worst case로 계산(가장 느려진다면 어느정도인가)

  =점근법(asymtotic notation)

  ex) O(n+3) = O(n^1 + 3 * n^0) = O(n)
      O(2) = O(1) 
	  O(Time Complexity) : O(4 * n ^ 2) = o(n^2)
	  Space Complexity : O(3) = O(1)
  */


/*

void f(int n)
{
	if (n <= 0)
    {
		return;
	}
		
	f(n - 1);
	f(n - 1);
}

// 시간복잡도: 2^n 공간복잡도: n (호출되었다가 사라짐, 0은 바로 return됨)

*/

void Print(int input[], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << input[i] << " ";
	}

	std::cout << std::endl;
}

void Swap(int& value1, int& value2)
{
	int temp = value1;

	value1 = value2;
	value2 = temp;
}

// Sequential Sort
// Time Complexity: O(n^2)
// Space Complexity: O(n)
void SequentialSort(int input[], int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (input[i] > input[j])
			{
				Swap(input[i], input[j]);
			}
		}
	}
}

//Selection Sort
// Time Complexity: O(n^2)
// Space Complexity: O(n)
void SelectionSort(int input[], int size)
{
	for (int i = 0; i < size; i++) 
	{
		int minindex = i;
		for (int j = i; j < size; j++)
		{
			if (input[minindex] > input[j])
			{
				minindex = j;
			}
		}
		Swap(input[i], input[minindex]);
	}
}

// Bubble Sort
// Time Complexity: O(n^2)
// Space Complexity: O(n)
void BubbleSort(int input[], int size)
{
	
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (input[j] > input[j + 1])
				{
					Swap(input[j], input[j + 1]);
				}
			}
		}
    
}

//Insertion Sort
void InsertionSort(int input[], int size)
{
	for (int i = 0; i < size; i++) {
		for(int j=0; j)
   }
}

int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8,7,2,3,1 };

	//SequentialSort(array, ARRAY_SIZE);
	SelectionSort(array, ARRAY_SIZE);
	Print(array, ARRAY_SIZE);
	
}

