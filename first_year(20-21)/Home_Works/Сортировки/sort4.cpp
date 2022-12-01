#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,N;

	cin >> n;

	N=n;

	int A[n];

	for(int i  = 0; i < n; i++)
	{
		cin >> A[i];
		for(int j = 0;j < i; j++)
		{
			if(A[i] == A[j])
			{
				N--;
				break;
			}
		}
	}

	cout << N;

	return 0;
}
