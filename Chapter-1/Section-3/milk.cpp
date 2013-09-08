/*
ID: lynermo1
PROG: milk
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

struct offers
{
	int price;
	int gallons;
};

bool compare (const offers& i, const offers& j)
{
	return i.price<j.price;
}

int main()
{
	ofstream fout("milk.out");
	ifstream fin("milk.in");
	vector<offers> deals;
	int required,dealnum;

	fin >> required >> dealnum;
	for(int i = 0; i < dealnum; ++i)
	{
		offers temp;
		fin >> temp.price >> temp.gallons;
		deals.push_back(temp);
	}

	sort(deals.begin(),deals.end(),compare);
	vector<offers>::iterator it = deals.begin();

	int minprice = 0;

	while(required != 0)
	{
		if(required > it->gallons)
		{
			minprice += it->gallons*it->price;
			required -= it->gallons;
			it++;
		}
		else
		{
			minprice += required*it->price;
			required = 0;
		}
	}

	fout << minprice << endl;
	
	fin.close();
	fout.close();
	return(0);
}
