/*
ID: lynermo1
PROG: milk2
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

struct interval
{
	int start;
	int end;
};

bool intcompare (const interval& i, const interval& j)
{
	return i.start<j.start;
}

int main()
{
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	vector<interval> milkings;
	int N;

	fin >> N;
	for(int i = 0; i < N; ++i)
	{
		interval temp;
		fin >> temp.start >> temp.end;
		milkings.push_back(temp);
	}

	sort(milkings.begin(),milkings.end(),intcompare);
	vector<interval>::iterator i,j;

	int milkinterval = 0;
	int freeinterval = 0;

	int milkstart = milkings.begin()->start;
	int milkend = milkings.begin()->end;

	for(i=milkings.begin(); i != milkings.end(); ++i)
	{
		if(i->start <= milkend)
		{
			milkend = milkend > i->end ? milkend : i->end;
		}
		else
		{
			int curfree = i->start - milkend;
			if(curfree > freeinterval)
				freeinterval = curfree;
			int curmilk = milkend - milkstart;
			if(curmilk > milkinterval)
				milkinterval = curmilk;
			milkstart = i->start;
			milkend = i->end;
		}
	}
	int curmilk = milkend - milkstart;
	if(curmilk > milkinterval)
		milkinterval = curmilk;
	
	fout << milkinterval << " " << freeinterval << endl;

	fin.close();
	fout.close();
	return(0);
}
