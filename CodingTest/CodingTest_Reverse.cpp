#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool re(int a, int b)
{
	return a > b;
}
int main()
{
	vector<int> List;
	int iNumber;

	cin >> iNumber;

	for (int i = 1; i < iNumber+1; i++)
	{
		List.push_back(i);
	}
	cout << "\n";
	sort(List.begin(),List.end(),re);

	for (int i = 0; i < List.size(); i++)
	{
		cout << List[i];
	}



}