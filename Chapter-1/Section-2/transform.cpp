/*
ID: lynermo1
PROG: transform	
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ofstream fout("transform.out");
	ifstream fin("transform.in");
	char start[10][10];
	char end[10][10];
	int size;
	string temp;
	int change = 7;

	fin >> size;

	for(int i = 0; i < size; i++)
	{
		fin >> temp;
		for(int j = 0; j < size; j++)
		{
			start[i][j] = temp[j];
		}
	}
	
	for(int i = 0; i < size; i++)
	{
		fin >> temp;
		for(int j = 0; j < size; j++)
		{
			end[i][j] = temp[j];
		}
	}

	//no change
	bool match = true;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(start[i][j] != end[i][j])
			{
				match = false;
				break;
			}
		}
		if(!match)
			break;
	}
	if(match)
		change = 6;
	
	//combination 90
	match = true;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(start[i][j] != end[size-j-1][size-i-1])
			{
				match = false;
				break;
			}
		}
		if(!match)
			break;
	}
	if(match)
		change = 5;
	
	//combination 180
	match = true;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(start[i][j] != end[size-i-1][j])
			{
				match = false;
				break;
			}
		}
		if(!match)
			break;
	}
	if(match)
		change = 5;

	//combination 270
	match = true;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(start[i][j] != end[j][i])
			{
				match = false;
				break;
			}
		}
		if(!match)
			break;
	}
	if(match)
		change = 5;

	//reflection
	match = true;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(start[i][j] != end[i][size-j-1])
			{
				match = false;
				break;
			}
		}
		if(!match)
			break;
	}
	if(match)
		change = 4;

	//rotation 270
	match = true;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(start[i][j] != end[size-j-1][i])
			{
				match = false;
				break;
			}
		}
		if(!match)
			break;
	}
	if(match)
		change = 3;

	//rotation 180
	match = true;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(start[i][j] != end[size-i-1][size-j-1])
			{
				match = false;
				break;
			}
		}
		if(!match)
			break;
	}
	if(match)
		change = 2;
	
	//rotation 90
	match = true;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(start[i][j] != end[j][size-i-1])
			{
				match = false;
				break;
			}
		}
		if(!match)
			break;
	}
	if(match)
		change = 1;

	fout << change << endl;	

	fin.close();
	fout.close();
	return(0);
}
