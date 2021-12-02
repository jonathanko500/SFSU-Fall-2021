#include <iostream>
#include <cstdlib> 
#include <ctime> 

using namespace std;

const int sim = 10000;//make 10000

//functions/methods
int reroll(int x, int y);
void fill(int x[]);
float probW(int x[]);



int main()
{
	//set up randomizer to be random every time
	srand((unsigned)time(0));

	//array of simulations
	int list[sim];

	//fill array of simulation
	fill(list);

	//determine prob of winning 
	float win = probW(list);

	cout << "Your chances of winning is " << win * 100 << "%" << endl;



	return 0;
}

//makes 2 new randomized numbers for the dice
int reroll(int x, int y)
{
	x = rand() % 6 + 1;
	y = rand() % 6 + 1;
	return x + y;
}

//fill array of sums
void fill(int x[])
{
	//2 6-sided dice
	int d1=0, d2=0;
	for (int i = 0; i < sim; i++)
	{//start to fill array
		//make sum
		int sum = reroll(d1, d2);
		//reroll for next sum
		x[i] = sum;
		reroll(d1, d2);
	}

}

//find prob of winning
float probW(int x[])
{
	//list of W/L
	int result[sim];

	//reroll until point is achieved
	int d1=0,d2=0,sum;

	//counter
	int count = 0;

	for (int i = 0; i < sim; i++)
	{//looks through list of sums
		if (x[i] == 7 || x[i] == 11)
		{//check for 7 or 11
			//W = 1
			result[i] = 1;
		}
		else if (x[i] == 2 || x[i] == 3 || x[i] == 12)
		{//check for 2, 3, or 12
			//L = 0
			result[i] = 0;
		}
		else
		{//reroll if list is not number listed above
			do
			{		
				sum = reroll(d1, d2);
				if (x[i] == sum)
				{//win if point is acheived again
					result[i] = 1;
				}
			} while (sum != 7);

			//lose if reroll 7
			result[i] = 0;
		}
	}

	for (int i = 0; i < sim; i++)
	{
		if (result[i] == 1)
		{
			count++;
		}
	}

	float prob = (float) count / (float) sim;
	return prob;
}

