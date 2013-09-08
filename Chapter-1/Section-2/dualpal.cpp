/*
ID: lynermo1
PROG: dualpal
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
	ofstream fout("dualpal.out");
	ifstream fin("dualpal.in");

	int N,S;
	fin >> N >> S;

	int count = 0;

	while(count != N)
	{
		S++;
		int palcount = 0;
		for(int base = 2; base <= 10; base++)
		{
			string num = stringify(S, base);
			if(num == rev(num))
				palcount++;
		}
		if(palcount >= 2)
		{
			count++;
			fout << S << endl;
		}
	}
	
	fin.close();
	fout.close();
	return(0);
}
