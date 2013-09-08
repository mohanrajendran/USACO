/*
ID: lynermo1
PROG: gift1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int NtoI(string* names, string name, int NP)
{
	for(int i = 0; i < NP; i++)
	{
		if(names[i] == name)
			return i;
	}
	return NP;
}

int main()
{
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");

	int NP;
	string names[10];
	int amount[10]={0};

	fin >> NP;
	for(int i = 0; i < NP; i++)
	{
		fin >> names[i];
	}

	for(int i = 0; i < NP; i++)
	{
		string donor;
		int give;
		int num_rec;
		
		fin >> donor;
		fin >> give >> num_rec;
		
		if(num_rec != 0)
			give -= give%num_rec;

		amount[NtoI(names,donor,NP)] -= give;

		for(int j = 0; j < num_rec; j++)
		{
			string rec;
			fin >> rec;
			if(num_rec != 0)
				amount[NtoI(names,rec,NP)] += (give/num_rec);
		}
	}

	for(int i = 0; i < NP; i++)
	{
		fout << names[i] << " " << amount[i] << endl;
	}		

	fin.close();
	fout.close();
	return(0);
}
