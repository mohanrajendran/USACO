/*
ID: lynermo1
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>

using namespace std;

int main()
{
	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	ifstream dictin("dict.txt");

	map<char, char> keys;
	keys['A'] = '2';
	keys['B'] = '2';
	keys['C'] = '2';
	keys['D'] = '3';
	keys['E'] = '3';
	keys['F'] = '3';
	keys['G'] = '4';
	keys['H'] = '4';
	keys['I'] = '4';
	keys['J'] = '5';
	keys['K'] = '5';
	keys['L'] = '5';
	keys['M'] = '6';
	keys['N'] = '6';
	keys['O'] = '6';
	keys['P'] = '7';
	keys['R'] = '7';
	keys['S'] = '7';
	keys['T'] = '8';
	keys['U'] = '8';
	keys['V'] = '8';
	keys['W'] = '9';
	keys['X'] = '9';
	keys['Y'] = '9';

	bool found = false;
	string key;
	fin >> key;

	while( !dictin.eof() )
	{
		string name;
		string hash;
		dictin >> name;
		for(int i = 0; i < name.length(); i++)
		{
			hash = hash + keys[name[i]];
		}
		if(hash == key)
		{
			fout << name << endl;
			found = true;
		}
	}

	if(!found)
		fout << "NONE" << endl;

	dictin.close();	
	fin.close();
	fout.close();
	return(0);
}
