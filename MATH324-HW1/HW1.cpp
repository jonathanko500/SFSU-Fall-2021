#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

const int rnSize = 40000;
const int avgSize = 2000;

void fillMeans(double x[] , double y[]);

int main()
{
	// Get the system time.
	unsigned seed = time(0);

	// Seed the random number generator.
	srand(seed);

	double rnList[rnSize];//array of random numbers between -6 and 10
	double means[avgSize];//means of nums


	fillMeans(rnList, means);

	return 0;
}


//get 2000 mean samples
void fillMeans(double x[], double y[])
{//start
	int sum = 0;
	double avg;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{//fill rnList
			x[j] = (rand() % 16) - 6;
			sum += x[j];
			cout << x[j] << endl;
		}
		cout << sum << endl;
		cout << "***********" << endl;
		avg = sum / 5;
		y[i] = avg;
		cout.precision(3);
		cout << y[i] << endl;
	}
	

}//end









