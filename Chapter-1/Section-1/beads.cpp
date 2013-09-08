/*
ID: lynermo1
PROG: beads
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ofstream fout("beads.out");
	ifstream fin("beads.in");

	int num_beads;
	string beads;
	int max_length = 0;
	
	fin >> num_beads;
	fin >> beads;

	for(int i = 0; i < num_beads; i++)
	{
		int cur_len = 0;
		int cur_pos = i;
		char color = beads[cur_pos];
		while((beads[cur_pos] == color || beads[cur_pos] == 'w' || color == 'w') && cur_len < num_beads)
		{
			if(color == 'w')
				color = beads[cur_pos];
			cur_len++;
//			cout << beads[cur_pos];
			cur_pos = (cur_pos + 1)%num_beads;
		}
//		cout << endl;

		cur_pos = (i-1+num_beads) % num_beads;
		color = beads[cur_pos];
		while((beads[cur_pos] == color || beads[cur_pos] == 'w' || color == 'w') && cur_len < num_beads)
		{
			if(color == 'w')
				color = beads[cur_pos];
			cur_len++;
//			cout << beads[cur_pos];
			cur_pos = (cur_pos - 1 + num_beads)%num_beads;
		}
//		cout << endl << cur_len << endl;

		if(cur_len > max_length)
			max_length = cur_len;
	}

	fout << max_length << endl;

	fin.close();
	fout.close();
	return(0);
}
