#include <stdio.h>

void Kashin_Stepan(int A[],int n)
{
	int x;
	for(int i = 0;i <= n/2;i++)
	{
		x = A[i];
		A[i] = A[n - i - 1];
		A[n - i - 1] = x;
	}

	for (int i = 0; i < n; i++) printf("%3d",A[i]);
}

int main()
{
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i = 0;i < n;i++) scanf("%d",&A[i]);

	Kashin_Stepan(A, n);


}