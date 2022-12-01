#include <iostream>

int LocalMin(int* A, int n);

void SortIndexEven(int* A, int n);

void SortOnlyEven(int* A, int n);

int PlaysUp(int* A, int n);

int MinOfLocalMax(int* A, int n);

void CreateOneArray(int* All, int A1[], int n1, int A2[], int n2);

int LocalMin(int * A,int n)
{
	int ans,i;

	ans = 0;

	for (i = 0; i < n; i ++)
	{
		if (i == 0)
		{
			if (A[i] < A[i + 1])
			{
				ans++;

			}
		}
		else if (i == n-1)
		{
			if (A[i-1]> A[i])
			{
				ans++;
			}
		}
		else
		{
			if (A[i-1] > A[i] && A[i] < A[i+1])
			{
				ans++;
			}
		}
	} 
	return ans;
}

void SortIndexEven(int * A, int n)
{
	int elem, i, j; // elem for swap

	for (i = 0; i < n; i += 2)
	{
		for (j  = i+2; j < n; j += 2)
		{
			if (A[i] > A[j])
			{
				elem = A[i];
				A[i] = A[j];
				A[j] = elem;
			}
		}
	}
}
//10000 1 0 -1 10 -1 5
int MinOfLocalMax(int * A,int n)
{
	int min,i;

	min = A[0];

	for (i = 1; i < n; i++)
	{
		if (A[i] > min) min=A[i];
	}

	for (i = 0; i < n; i ++)
	{
		if (i == 0)
		{
			if(A[i] > A[i + 1] && A[i] < min)
			{
				min = A[i];
			}
		}
		else if (i == n-1)
		{
			if(A[i-1] < A[i] && A[i] < min)
			{
				min = A[i];
			}
		}
		else
		{
			if(A[i-1] < A[i] && A[i] > A[i+1] && A[i] < min)
			{
				min = A[i];
			}
		}
	} 
	return min;
}

void SortOnlyEven(int * A,int n)
{
	int elem, i, j; // elem for swap;

	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n;j++)
		{
			if (A[i] > A[j] && A[i] % 2 == 0 && A[j] % 2 == 0)
			{
				elem = A[i];
				A[i] = A[j];
				A[j] = elem;
			}
		}
	}
}

int PlaysUp(int * A,int n)
{
	int flag, ans, i;

	flag = 0;
	
	ans = 0;

	for (i = 0; i < n -1; i++)
	{
		if (A[i] < A[i+1])
		{
			flag = 1;
		}
		else
		{
			if ( flag == 1)
			{
				ans++;
				flag = 0;
			}
		}
	}

	if (flag == 1) ans++;

	return ans;
}

void CreateOneArray(int *All,int A1[],int n1,int A2[], int n2)
{
	int i;

	i = 0;

	while(i < n1+n2)
	{
		if(i < n1) All[i] = A1[i];

		else All[i] = A2[i - n1]; 

		i++;
	}
}