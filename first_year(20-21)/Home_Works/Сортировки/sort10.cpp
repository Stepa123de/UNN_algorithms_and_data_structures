#include <iostream>
#include <algorithm>

using namespace std;


int fun(int l,string s)
{
	int count = 0;
	string ne = s;

	sort(ne.begin(), ne.end());

	for (int i = 0; i < l; i++)
	{
		if(s[i] != ne[i])
		{
			count++;
		}
	}

	return count;
}

int main()
{
	int n;

	cin >> n;

	pair<int,string> A[n];

	for (int i = 0; i < n; i++) cin >> A[i].first >> A[i].second;

	for (int i = 0; i < n; i++) cout << fun(A[i].first,A[i].second) << "\n";

	return 0;
}