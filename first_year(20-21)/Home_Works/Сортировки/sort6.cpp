#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool vs(pair<string,int> a, pair<string,int> b)
{
	if(a.second > b.second) return true;
	
	if(a.second < b.second) return false;

	if(a.second == b.second)
	{
		string aa = a.first, bb = b.first;

		int N;

		if(aa.length()>= bb.length()) N = bb.length();
		else N = aa.length();

		for(int i = 0; i < N; i++){
			if(aa[i]<bb[i]) return true;

			if(aa[i]>bb[i]) return false;
		}

		if (aa.length() > bb.length()) return false;
		else return true;
	}
	

	/*if(a.first.legth() > b.first.legth())
	{
		for(int i = 0; i < b.first.legth()) if(a.first[i] <b.first[i]) return true;
		return false;
	} 
	if(a.first.legth() < b.first.legth()) for(int i = 0; i < a.first.legth())
	{
		if(b.first[i] <a.first[i]) return false;
		return true;	
	} */
}

int main()
{
	int n;

	cin >> n;

	pair<string,int> A[n];

	for(int  i = 0; i < n; i++) cin >> A[i].first >> A[i].second;

	sort(A, A+n, vs);

	for(int i = 0; i < n; i++) cout << A[i].first << " ";

	return 0;
}