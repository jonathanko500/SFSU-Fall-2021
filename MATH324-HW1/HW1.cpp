#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>		/* math functions */
using namespace std;

//q1 const int
const int rnSize = 20;//40000 rng 
const int meanSize = 5;//2000 sample
const int len = 10;//range of variables for pareto distribution 


//functions/methods
void makeNumbs(int x[], int size);
void makeMeans(int x[], double y[], int xSize, int ySize);

double prob(double x[],int xSize, double min, double max);
double avgMean(double x[], int xSize);
double SD(double x[], int xSize);
//could not figure out how to make a histogram of means

void makePDnum(float x[], int xSize);
void makePDmean(float x[], float y[], int xSize, int ySize);


int main()
{
	//set up randomizer to be random every time
	// Get the system time.
	unsigned seed = time(0);
	// Seed the random number generator.
	srand(seed);
	//*****************************************
	/*
	//q1
	int rnList[rnSize];//array of random numbers between -6 and 10
	double means[meanSize];//means of nums
	
	makeMeans(rnList, means, rnSize, meanSize);	

	double chance = prob(means, meanSize, 2.0, 2.4);
	cout << "the probablity of mean between 2.0 and 2.4 inclusive is: " << chance << endl;

	double avg = avgMean(means, meanSize);
	cout << "the mean of the means is : " << avg << endl;
	
	double sd = SD(means, meanSize);
	cout << "the standard deviation is : " << sd << endl;

	//**************************************************
	*/
	//q2
	float pdNum[rnSize];//means of nums
	float pdMeans[meanSize];//means of nums

	//make pd array back to double
	makePDmean(pdNum, pdMeans, rnSize, meanSize);

	
}



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


//values from Pareto distribution
void makePDnum(float x[], int xSize)
{
	float val[len];
	int count = 1;
	
	for (int j = 0; j < len; j++)
	{//array of numbs between 0 - 1	for y val	
		val[j] = (float) count / (float) len;
		count++;
	}
	int yPT;
	float bottom;
	float raise;
	for (int j = 0; j < xSize; j++)
	{//fill rnList
		yPT = (rand() % len);
		bottom = 1 - val[yPT];
		raise = pow(bottom, 0.125);
		x[j] = 1/raise;
	}
}

void makePDmean(float x[], float y[], int xSize, int ySize)
{
	float sum = 0;
	float avg;
	for (int i = 0; i < ySize; i++)
	{
		makePDnum(x, xSize);
		for (int j = 0; j < xSize; j++)
		{
			sum += x[j];
		}
		avg = (float)sum / xSize;
		y[i] = avg;
		sum == 0;
		cout << y[i] << endl;

	}
}