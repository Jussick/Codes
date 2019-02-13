#include<iostream>
#include<ctime>
#include "include/list.h"

using namespace std;

template <typename NumType>
void printArr(NumType *arr, int len)
{
    int i;
    if (len <= 0) return;
    for (i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
        if (i == len-1) cout << endl;
    }
}

template <class T>
void swap(T *a, T *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int RandomInRange(int min, int max)
{
    srand((unsigned int)(time(NULL)));
    int randomNum = rand();
    randomNum %= max;
    int difference = max - min;
    srand((unsigned int)(time(NULL)));
    int offset = rand() % difference;
    return abs(randomNum - offset) + 1;

}


int Partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >= length)
    {
        cout << "Invalid Input" << endl;
        return -1;
    }
    int index = RandomInRange(start, end);
    swap(&data[index], &data[end]);

    int small = start - 1;
    for (index = start; index < end; ++ index)
    {
        if (data[index] < data[end])
        {
            ++small;
            if (small != index)
                swap(&data[index], &data[small]);
        }
    }
    ++ small;
    swap(&data[small], &data[end]);
    return small;
}

void quickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;
	int index = Partition(data, length, start, end);
	if (index > start)
		quickSort(data, length, start, index - 1);
	if (index < end)
		quickSort(data, length, index + 1, end);
}

int main()
{
#if 0
	int arr[10] = {1,5,7,65,34,9,4,2,6,0};	
	quickSort(arr, 10, 0, 9);
	printArr(arr, 10);
#endif
	int a = RandomInRange(1,10);
	cout << a << endl;
	return 0;
}
