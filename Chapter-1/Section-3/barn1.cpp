/*
ID: lynermo1
PROG: barn1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int main()
{
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
	vector<int> occupied;
	int M,S,C;

	fin >> M >> S >> C;
	
	istream_iterator<int> iit(fin);
	
	for(int i = 0; i < C; i++, iit++)
		occupied.push_back(*iit);

	sort(occupied.begin(),occupied.end());

	int max_len = 1 + occupied[C-1] - occupied[0];

	vector<int> spacings;
	for(int i = 1; i < C; i++)
	{
		int space = occupied[i] - occupied[i-1] -1;
		if(space != 0)
			spacings.push_back(space);
	}

	sort(spacings.begin(),spacings.end());
	reverse(spacings.begin(),spacings.end());

	vector<int>::iterator it = spacings.begin();

	for(int board = 0; board < M-1 && it != spacings.end(); board++, it++)
	{
		max_len -= *it;
	}

	fout << max_len << endl;

	fin.close();
	fout.close();
	return(0);
}
