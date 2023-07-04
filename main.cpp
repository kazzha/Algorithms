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
// Time Complexity: O(n^2)
// Space Complexity: O(n)
void InsertionSort(int input[], int size)
{
	for (int i = 1; i < size; i++) 
	{
		int j = i;
		int target = input[i];

		while (--j >= 0 && target < input[j])
		{
			input[j + 1] = input[j];
			input[j] = target;
		}
    }
}
// Merge Sort
// Time Complexity: O(n * log n)
// Space Complexity: O(n)
void Merge(int input[], int start, int half, int end, int temp[])
{
	int i{ start };
	int j{ half + 1 };
	int tempIndex{};

	while (i <= half && j <= end)
	{
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];
		}
		else
		{
			temp[tempIndex++] = input[j++];
		}
	}

	// 남아 있는 것 병합
	while (i <= half)
	{
		temp[tempIndex++] = input[i++];
	}
	while (j <= end)
	{
		temp[tempIndex++] = input[j++];
	}

	// 임시 배열 -> 원래배열로 복사
	tempIndex = 0;
	for (int i = start; i <= end; i++)
	{
		input[i] = temp[tempIndex++];
	}
}

void MergeSort(int input[], int start, int end, int temp[])
{
	//base casee
	if (start >= end)
	{
		return;
	}
	// recursive case 반/반

	int half = (start + end) / 2;

	MergeSort(input, start, half, temp);
	MergeSort(input, half+1 , end, temp);

	// Merge
	Merge(input, start, half, end, temp);
}

// QuickSort - 요즘 프로그래밍에서 가장 많이 사용
void QuickSort(int input[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = input[(left + right) / 2];

	do
	{
		while (input[i] < pivot)
		{
			i++;
		}
		while (input[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}
	} while (i<=j);

	if (left < j)
	{
		QuickSort(input, left, j);
	}
	if (i < right)
	{
		QuickSort(input, i, right);
	}
}

int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8,7,2,3,1 };

	//SequentialSort(array, ARRAY_SIZE);
	//SelectionSort(array, ARRAY_SIZE);
	//InsertionSort(array, ARRAY_SIZE);

	/*int tempArray[ARRAY_SIZE]{};
	MergeSort(array, 0, ARRAY_SIZE - 1,tempArray);
	*/

	QuickSort(array, 0, ARRAY_SIZE - 1);
	
	Print(array, ARRAY_SIZE);
	
}

