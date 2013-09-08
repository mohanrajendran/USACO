/*
ID: lynermo1
PROG: friday
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool isleap(int year)
{
	if(year%4 != 0)
		return false;
	else if(year%100 == 0 && year%400 != 0)
		return false;
	else
		return true;
}

int main()
{
	ofstream fout("friday.out");
	ifstream fin("friday.in");

	int yearcount;
	int curday = 1;
	int numoccur[7] = {0};
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	fin >> yearcount;
	
	for(int i = 0; i < yearcount; i++)
	{
		int curyear = 1900 + i;
		
		for(int j = 0; j < 12; j++)
		{
			int day13 = (curday+13)%7;
			numoccur[day13]++;
			int daynext = days[j];
			if(j == 1 && isleap(curyear))
				daynext = 29;
			curday = (curday+daynext)%7;
		}
	}

	for(int i = 0; i < 7; i++)
	{
		fout << numoccur[i];
		if(i != 6)
			fout << " ";
	}
	fout << endl;

	fin.close();
	fout.close();
	return(0);
}
