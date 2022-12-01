#include <iostream>
#include <algorithm>
using namespace std;
 
int main(int argc, char const *argv[])
{
	int n;
 
	cin >> n;
 
	long long int A[n];
 
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		A[i]= A[i] * 1000000 +i+1;
	} 
 
	sort(A,A + n);
 
	for(int i = 0; i < n; i++) cout << A[i]%1000000 << " ";
 
	return 0;
}