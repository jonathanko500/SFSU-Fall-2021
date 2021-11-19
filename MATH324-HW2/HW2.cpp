#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

const int sim = 10;//make 10000


/*
	sample sd = sqrt( (sigma[x - x-bar]^2) / n - 1
	sample mean (x-bar) = sigma(x) / n
*/

int direction();

int main()
{
	//set up randomizer to be random every time
	srand((unsigned)time(0));
	//*****************************************


	int prob = direction();

	for (int i = 0; i < sim; i++)
	{
		cout << prob << endl;
	}


	return 0;
}

//rng direction of either right (0) or left (1)
int dirention()
{
	int direct = rand() % 2;
	return direct;
}

