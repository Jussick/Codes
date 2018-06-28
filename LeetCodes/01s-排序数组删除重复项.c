#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int i;
    for (i = 0; i < numsSize; ++i)
    {
		if (i == 0) continue;
        int j;
		// 整体前移
		if (*(nums+i) == *(nums+i-1))
		{
			for (j = i-1; j < numsSize-1; j++)
			{
				*(nums+j) = *(nums+j+1);
			}
			numsSize--;
			i--;
		}
            
    }

	return numsSize;	
}

int main()
{
	int array[11] = {0,0,1,1,1,2,2,3,3,4};
	int size = 10;
	int finalSize = removeDuplicates(array, size);

	int i;
	for (i = 0; i < finalSize; i++)
		printf("array[%d] = %d\n", i, array[i]);
	return 0;
}
