#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,to_l = 0,to_b = 0,a,b;

	cin >> n;

	int A[n];

	for (int i = 0; i < n; i++) cin >> A[i];
	
	for (int i = 1; i < n; i++)
	{
		if(A[i-1] < A[i]) to_l = 1;

		if(A[i-1] > A[i]) to_b = 1; 
	}

	if(to_l == 0 || to_b == 0) cout << "Yes";
	else cout << "No";

	return 0;
}