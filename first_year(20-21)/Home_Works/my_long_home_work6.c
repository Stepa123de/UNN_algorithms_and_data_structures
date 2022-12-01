#include <stdlib.h>
#include <stdio.h>

int ChangeArray(int N, int A[], int B[])

{

            int k = 0;

            for(int i=0; i<N; i++)

            {

                       if(A[i] > 0)

{

B[k] = A[i];

k++;

}

}

return k;

}

void OutIntArray(int Array[], int n)
{
	for(int i = 0; i < n; i++) printf("%d ",Array[i]);

	printf("\n");
}


int main()
{
		int A[] = {-2,-1,1,2};
		int B[4];
		int k = ChangeArray(4,A,B);

		OutIntArray(B,k);

	return 0;
}