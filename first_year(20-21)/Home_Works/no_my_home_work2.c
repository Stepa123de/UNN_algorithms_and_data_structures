#include <stdio.h>

int Kashin_Stepan(int A[],int n)
{	
	int N = 0;
	for(int i = 0; i < n;i++)
	{
		int flag = 1;
		for(int j = 0; j < i;j++) 
		{
			if(A[i] == A[j])
			{
				flag = 0;
				break;
			}
		}
		if(flag) N++;
	}
	return N;
}

int main()
{
	int n,N;
	scanf("%d",&n);
	int A[n];
	for(int i = 0; i < n;i++) scanf("%d",&A[i]); 

	N = Kashin_Stepan(A,n);

	printf("%d",N);
	
	return 0;
}