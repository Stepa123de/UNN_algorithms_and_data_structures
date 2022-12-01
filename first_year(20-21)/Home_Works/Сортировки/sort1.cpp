#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;

	cin >> n;

	int A[n];

	for(int i = 0; i < n; i++) cin >> A[i];

	for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++)
		{
			if (A[i] > A[j]) swap(A[i],A[j]);
		}

	for (int i = 0; i < n; ++i) cout << A[i] << " ";

	return 0;
}