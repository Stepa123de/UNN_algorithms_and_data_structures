#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,sum = 0;

	cin >> n >> m;

	int A[n];

	for (int i = 0; i < n; ++i) cin >> A[i];

	sort(A,A + n);
	
	int i =0;

	while (m !=0 && A[i] < 0)
	{
		sum-=A[i]; 
		i++;
		n--;
		m--;
	}	
	cout << sum;
	return 0;
}