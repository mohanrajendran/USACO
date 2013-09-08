/*
ID: lynermo1
PROG: ride
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string comet,group;
	int cprod = 1, gprod = 1;
	
	fin >> comet >> group;
	for(int i = 0; i < comet.length(); i++)
	{
		cprod *= ((int)comet[i] - (int)'@');
	}
	for(int i = 0; i < group.length(); i++)
	{
		gprod *= ((int)group[i] - (int)'@');
	}
	if(cprod%47 == gprod%47)
		fout << "GO" << endl;
	else
		fout << "STAY" << endl;		

	fin.close();
	fout.close();
	return(0);
}
