#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool test(string s1, string s2){
	if(s1.size() > s2.size()) return true;

	if(s1.size() < s2.size()) return false;

	int n = s1.size();

	for (int i = 0; i < n; ++i)
	{
		if(s1[i] - '0' > s2[i] - '0') return true;

		if(s1[i] - '0' < s2[i] - '0') return false;
	}

	return false;
}

int main()
{
	
	int n;

	cin >> n;

	string A[n];

	for(int i = 0; i < n; i++) cin >> A[i];

	sort(A,A+n,test);

	/*for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j)
			{
				if(A[i] > A[j]) swap(A[i],A[j]);

				//if(A[j] =="0") swap(A[i],A[j]);
			}*/

	for (int i = n-1; i >= 0; i--) cout << A[i] << " ";

	return 0;
}