#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

const int rnSize = 40000;
const int avgSize = 2000;

int[] makeNumbs(int x[]);
int main()
{
	// Get the system time.
	unsigned seed = time(0);

	// Seed the random number generator.
	srand(seed);

	int rnList[5];//array of random numbers between -6 and 10
	double means[avgSize];//means of nums

	rnList = makeNumbs(rnList);

	return 0;
}



//make array full of random numbers between -6 and 10
int[] makeNumbs(int x[])
{
	int len = sizeof(x) / sizeof(x[0]);
	for (int j = 0; j < len; j++)
	{//fill rnList
		x[j] = (rand() % 16) - 6;
	}

	return x[];
}







