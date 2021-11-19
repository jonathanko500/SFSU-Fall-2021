#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

const int sim = 10000;//make 10000

//functions/methods
int direction();
void result(int direct[],int time[]);
int left();
double mean(int x[]);
double SD(int x[]);

int main()
{
	//set up randomizer to be random every time
	srand((unsigned)time(0));
	//*****************************************

	
	int totalSim[sim];//array of directions
	for(int i =0;i<sim;i++)
	{
		totalSim[i] = direction();
	}
	int timeSpent[sim];//array of time rat spent in maze

	//fill timeSpent array
	result(totalSim, timeSpent);

	double sMean, sampleSD;

	sMean = mean(timeSpent);
	sampleSD = SD(timeSpent);

	cout << "a) the expected (average) number of minutes that he will be trapped in the maze is:  " << sMean << " min." << endl;
	cout << "b) the standard deviation of the amount of time the rat spends in the maze is:  " << sampleSD << " min." << endl;
	
	
	return 0;
}

//rng direction of either left (0) or right (1)
int direction()
{
	int direct = rand() % 2;
	return direct;
}

//fill array of times spend in maze
void result(int direct[], int time[])
{
	for (int i = 0; i < sim; i++)
	{//fills time array based off direction from direction array
		if (direct[i] == 0)
		{//result of direction being left
			time[i] = left();
		}
		else
		{//result of direction being right
			time[i] = 4;
		}
	}
}

//fill time array with either 3 min (2/5) or 6 min (3/5)
int left()
{
	int direct = rand() % 5 + 1;// 1 - 5
	int result = direct % 2;
	//0 = 3 min (2/5)
	//1 = 6 min (3/5)
	if (result == 0)
	{
		return 3;
	}
	else
	{
		return 6;
	}
	return result;
}

/*
	sample sd = sqrt{ (sigma[x - x-bar]^2) / n - 1 }
	sample mean (x-bar) = sigma(x) / n
*/

//calc sample mean
double mean(int x[])
{
	int sum = 0;
	double avg;
	for (int i = 0; i < sim; i++)
	{
		sum += x[i];
	}
	avg = (double)sum / (double)sim;
	return avg;
}

//calc sample sd
double SD(int x[])
{
	double avg = mean(x);
	double diff;
	double sigma = 0;
	double root;
	double sd;
	int count = (sim - 1);
	for (int i = 0; i < sim; i++)
	{
		diff = x[i] - avg;
		sigma += pow(diff, 2);
	}
	root = sigma / (double) count;

	sd = sqrt(root);
	return sd;
}