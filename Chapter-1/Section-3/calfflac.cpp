/*
ID: lynermo1
PROG: calfflac
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
	ofstream fout("calfflac.out");
	ifstream fin("calfflac.in");

	string input = "";

	bool nline = false;

	while(!fin.eof())
	{
		if(nline)
			input += '\n';
		string temp;
		getline(fin,temp);
		input += temp;
		nline = true;
	}

	int ilen = input.length();

	//cout << input;

	int start, stop, best = 0;

	// Odd sized palindromes
	for(int i = 0; i < ilen; i++)
	{
		int tstart = i;
		int tstop = i;
		int pstart, pstop, len = -1;
		
		while(tstart >= 0 && tstop < ilen && 
		      tolower(input[tstart]) == tolower(input[tstop]))
		{
	//		cout << tstart << " " << tstop << " " << len <<  endl;
			// Store previous values
			pstart = tstart;
			pstop = tstop;
			len += 2;
			
			// Decrement starting pointer
			do
			{
				tstart--;
			}while(tstart >= 0 && !isalpha(input[tstart]));

			// Increment ending pointer
			do
			{
				tstop++;
			}while(tstop < ilen && !isalpha(input[tstop]));
		}

		if(len > best)
		{
			start = pstart;
			stop = pstop;
			best = len;
		}
	}

	// even  sized palindromes
	for(int i = 0; i < ilen-1; i++)
	{
		int tstart = i;
		int tstop = i+1;
		int pstart, pstop, len = 0;
		
		while(tstart >= 0 && tstop < ilen && 
		      tolower(input[tstart]) == tolower(input[tstop]))
		{
	//		cout << tstart << " " << tstop << " " << len <<  endl;
			// Store previous values
			pstart = tstart;
			pstop = tstop;
			len += 2;
			
			// Decrement starting pointer
			do
			{
				tstart--;
			}while(tstart >= 0 && !isalpha(input[tstart]));

			// Increment ending pointer
			do
			{
				tstop++;
			}while(tstop < ilen && !isalpha(input[tstop]));
		}
			
		if(len > best)
		{
			start = pstart;
			stop = pstop;
			best = len;
		}
	}
	
//	fout << best << endl;
	int count = 0;
	for(int i = start; i <= stop; i++)
	{
		if(isalpha(input[i]))
			count++;
	}
	fout << count << endl;
	for(int i = start; i <= stop; i++)
	{
		fout << input[i];
	}
	fout << endl;

	fin.close();
	fout.close();
	return(0);
}
