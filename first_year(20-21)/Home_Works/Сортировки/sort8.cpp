#include <iostream>
#include <algorithm>
using namespace std;

struct Mas
{
	int a,b;
};

bool mysort(pair<int,int> a, pair<int,int> b)
{
	if( a.second > b.second) return true;
	else return false;
}

int main()
{
	int n,m,sum = 0;

	cin >> n >> m;

	pair<int,int> A[m];

	for (int i = 0; i < m; i++)
	{
		cin >> A[i].first >> A[i].second;
	}

	sort(A,A + m, mysort);

	int i = 0;
	
	while (n != 0 && m != 0)
	{
		while(A[i].first!=0 && n !=0) {
		    sum += A[i].second;
		    n--;
		    A[i].first--;
		}
		i++;
		m--;
	}
    
	cout << sum;

	return 0;
}
