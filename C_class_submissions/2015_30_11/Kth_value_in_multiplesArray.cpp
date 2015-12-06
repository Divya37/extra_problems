/*
5.Given three numbers n1,n2,and r. Merge the table of n1 and n2 and find the r th number. In merging it should eliminate duplicate values (tables consists the multiples of those numbers ,ie 3 contains 3,6,9,12..)
Ex , n1=3 ,n2=5 and r=5, The merged table is 3,5,6,9,10,12,15(One more 15 is removed as its duplicate ) 18,20,21,24,25........so on .
The rth num ie 5th number is 12 ,so OP is 12
Extension ,what if n3,n4 .. are also given ?
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int Kth_value(int n1, int n2,int n3, int k)
{
	int c_n1 = 1, c_n2 = 1, c_n3 = 1, size = 0,*arr,a=n1,b=n2,c=n3;
	arr = (int *)malloc(sizeof(int)*k + 1);
	while (size < k)
	{
		if (a < b && a < c)
		{
			arr[size++] = a;
			c_n1++;
			a = n1*c_n1;
			//printf("\narr[%d]=%d", size - 1, arr[size - 1]);
		}
		else if (b < a && b < c)
		{
			arr[size++] = b;
			c_n2++;
			b = n2*c_n2;
			//printf("\narr[%d]=%d", size - 1, arr[size - 1]);
		}
		else if (c < a && c < b)
		{
			arr[size++] = c;
			c_n3++;
			c = n3*c_n3;
			//printf("\narr[%d]=%d", size - 1, arr[size - 1]);
		}
		else
		{
			if (a == b && a == c)
			{
				arr[size++] = a;
				c_n1++;
				c_n2++;
				c_n3++;
				a = n1*c_n1;
				b = n2*c_n2;
				c = n3*c_n3;
				//printf("\narr[%d]=%d", size - 1, arr[size - 1]);
			}
			if (a == b && a != c)
			{
				if (a < c)
				{
					arr[size++] = a;
					c_n1++;
					c_n2++;
					a = n1*c_n1;
					b = n2*c_n2;
				//	printf("\narr[%d]=%d", size - 1, arr[size - 1]);
				}
				else
				{
					arr[size++] = c;
					c_n3++;
					c = n3*c_n3;
					//printf("\narr[%d]=%d", size - 1, arr[size - 1]);
				}

			}
			else if (a == c && a != b)
			{
				if (a < b)
				{
					arr[size++] = a;
					c_n1++;
					c_n3++;
					a = n1*c_n1;
					c = n3*c_n3;
					//printf("\narr[%d]=%d", size - 1, arr[size - 1]);
				}
				else
				{
					arr[size++] = c;
					c_n2++;
					b = n2*c_n2;
					//printf("\narr[%d]=%d", size - 1, arr[size - 1]);
				}
			}
			else if (b==c && b!=a)
			{
				if (c < a)
				{
					arr[size++] = c;
					c_n3++;
					c_n2++;
					c = n3*c_n3;
					b = n2*c_n2;
					//printf("\narr[%d]=%d", size - 1, arr[size - 1]);
				}
				else
				{
					arr[size++] = a;
					c_n1++;
					c = n1*c_n1;
					//printf("\narr[%d]=%d", size - 1, arr[size - 1]);
				}
			}
		}
	}
	return(arr[size-1]);
}
void main()
{
	printf("output:%d", Kth_value(2, 5,7, 150));
	_getch();
}
