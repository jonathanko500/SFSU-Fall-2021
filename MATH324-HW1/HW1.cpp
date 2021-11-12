#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>		/* math functions */



using namespace std;

const int rnSize = 40000;//make 40000
const int meanSize = 2000;//make 2000


//q1 functions/methods
void makeNumbs(int x[], int size);
void makeMeans(int x[], double y[], int xSize, int ySize);

double prob(double x[],int xSize, double min, double max);
double avgMean(double x[], int xSize);
double SD(double x[], int xSize);
//could not figure out how to make a histogram of means

int main()
{
	// Get the system time.
	unsigned seed = time(0);

	// Seed the random number generator.
	srand(seed);
	
	//q1
	int rnList[rnSize];//array of random numbers between -6 and 10
	double means[meanSize];//means of nums
	
	makeMeans(rnList, means, rnSize, meanSize);

	

	double chance = prob(means, meanSize, 2.0, 2.4);
	cout << "the probablity of mean is between 2.0 and 2.4 inclusive is: " << chance << endl;

	double avg = avgMean(means, meanSize);
	cout << "the mean of the means is : " << avg << endl;
	
	double sd = SD(means, meanSize);
	cout << "the standard deviation is : " << sd << endl;

	printHistogram(means, meanSize);
	
	return 0;
}


//q1 functions/methods

//make array full of random numbers between -6 and 10
void makeNumbs(int x[], int size)
{
	
	for (int j = 0; j < size; j++)
	{//fill rnList
		x[j] = (rand() % 17) - 6;
	}
}

//make array full means
void makeMeans(int x[], double y[], int xSize, int ySize)
{
	
	int sum = 0;
	double avg;
	for (int i = 0; i < ySize; i++)
	{
		makeNumbs(x, xSize);
		for (int j = 0; j < xSize; j++)
		{
			sum += x[j];
		}
		avg = (double)sum / xSize;
		y[i] = avg;
		sum == 0;		
	}
}

//find probability that mean is between x and y
double prob(double x[], int xSize, double min, double max)
{
	double prob;
	int count = 0;
	for (int i = 0; i < xSize; i++)
	{
		if (x[i] <= min || x[i] >= max)
		{
			count++;
		}
	}
	prob = 1 - ((double)count / xSize);
	return prob;
}

//find mean of means
double avgMean(double x[], int xSize)
{
	double avg;
	double sum = 0.0;
	for (int i = 0; i < xSize; i++)
	{
		sum += x[i];
	}
	avg = sum / xSize;
	return avg;
}

//find standard deviation
double SD(double x[], int xSize)
{
	double recpSize = (double) 1 / (double) xSize;// 1/N

	double avg = avgMean(x, meanSize);//mu

	double sigma = 0;
	double meanDiff;//mean from array - mu
	double sqMeanDiff;//(mean from array - mu)^2
	

	for (int i = 0; i < xSize; i++)
	{
		meanDiff = x[i] - avg;
		sqMeanDiff = pow(meanDiff, 2);
		sigma += sqMeanDiff;//total of all (mean - mu)^2
	}
	
	double sd = sqrt(recpSize*sigma);//standard deviation

	return sd;

}


