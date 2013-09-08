/*
ID: lynermo1
PROG: palsquare
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string stringify(int num, int base)
{
	char eq[20] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
	string conv;
	
	while(num != 0)
	{
		conv = eq[num%base] + conv;
		num /= base;
	}
	
	return conv;
}

string rev(string orig)
{
	string reverse;
	
	for(int i = 0; i < orig.length(); i++)
	{
		reverse = orig[i] + reverse;
	}

	return reverse;
}

int main()
{
	ofstream fout("palsquare.out");
	ifstream fin("palsquare.in");

	int base;
	fin >> base;

	for(int i = 1; i <= 300; i++)
	{
		string sq = stringify(i*i, base);
		if(sq == rev(sq))
			fout << stringify(i,base) << " " << stringify(i*i,base) << endl;
	}
	
	fin.close();
	fout.close();
	return(0);
}
