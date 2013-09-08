/*
ID: lynermo1
PROG: crypt1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(int*, int, int);

int main()
{
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");

	int n;
	int num[9];

	fin >> n;
	for(int i = 0; i < n; i++)
	{
		fin >> num[i];
	}
	
	int count = 0;
	
	// iterate through possible numbers
	for(int l1 = 0; l1 < n; l1++)
	{
		for(int l2 = 0; l2 < n; l2++)
		{
			for(int l3 = 0; l3 < n; l3++)
			{
				for(int l4 = 0; l4 < n; l4++)
				{
					for(int l5 = 0; l5 < n; l5++)
					{
						// generate large number
						int large = num[l1] * 100 + num[l2] * 10 + num[l3];
						int small = num[l4] * 10 + num[l5];
						int prod1 = large * num[l4];
						int prod2 = large * num[l5];
						int prod = large * small;

						if(prod1 > 999 || prod2 > 999 || prod > 9999)
							continue;

						if(check(num, n, prod1) && check(num, n, prod2) &&
							 check(num, n, prod))
						{
//							cout << large << " " << small << " " << prod1 << " " << prod2 << " " << prod << endl;
							count++;
						}
					}
				}
			}
		}
	}

	fout << count << endl;

	fin.close();
	fout.close();
	return(0);
}

bool check(int* num, int n, int cnum)
{
	bool subset = true;
	while(subset && cnum > 0)
	{
		int cur = cnum % 10;
		bool sub = false;
		for(int i = 0; i < n; i++)
		{
			if(cur == num[i])
				sub = true;
		}
		cnum /= 10;
		subset &= sub;
	}

	return subset;
}
