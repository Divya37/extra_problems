//program to find a sub array with maximum sum.
#include<stdio.h>
#include<conio.h>

void sub_arr(int *arr,int size)
{
	int i,sum=0,start=0,prev_sum=0,negative=0,end=0;
	
	for (i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			negative++;
		}
		sum = sum + arr[i];
		if (sum > 0)
		{
			if (sum < prev_sum && (arr[i+1]+arr[i])<0)
			{
				sum = sum - arr[i];
				break;
			}
			end = i;
		}
		else
		{
			sum = 0;
			start = i+1;
		}
		prev_sum = sum;
	}
	if (negative == size - 1)
	{
		start = 0;
		end = 0;
	}
	printf("\n");
	for (i = start; i <=end; i++)
		printf(" %d ", arr[i]);
	printf("sum=%d", sum);
}
void main()
{
	int arr[] = { 14,-2, 2, 16, -14, 27, -13, 82, -10,100 };
	sub_arr(arr, 10);
	_getch();
}