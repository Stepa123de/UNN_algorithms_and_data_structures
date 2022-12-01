#include <iostream>
#include <algorithm>

using namespace std;

bool mysort(int a, int b)
{
	if (a > b) return true;
	else return false;
}

int main(int argc, char const *argv[])
{
	int n,sum = 0, count = 0,mysum = 0;

	cin >> n;

	int A[n];

	for (int i = 0; i < n; ++i) 
	{
		cin >> A[i];
		sum += A[i];	
	}	

	sort(A, A+n, mysort);	

	int i = 0;

	while(mysum <= sum)
	{
		mysum += A[i];
		sum -= A[i];
		count++;
		i++;
	}

	cout << count;

	return 0;	
}
