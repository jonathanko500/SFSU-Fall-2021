#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>		/* math functions */
using namespace std;

//q1 const int
const int rnSize = 40000;//40000 rng 
const int meanSize = 2000;//2000 sample
const int len = 1000;//range of variables for pareto distribution 


//functions/methods
void makeNumbs(int x[], int size);
void makeMeans(int x[], double y[], int xSize, int ySize);

double prob(double x[], int xSize, double min, double max);//q1
double prob2(double x[], int xSize, double min, double max);//q2

template <class T> T avgMean(T x[], int xSize);

template <class T> T SD(T x[], int xSize);

//could not figure out how to make a histogram of means

void makePDnum(double x[], int xSize);
void makePDmean(double x[], double y[], int xSize, int ySize);


int main()
{
	//set up randomizer to be random every time
	// Get the system time.
	unsigned seed = time(0);
	// Seed the random number generator.
	srand(seed);
	//*****************************************
	
	//q1
	cout << "The following statements are for question 1. " << endl;
	int rnList[rnSize];//array of random numbers between -6 and 10
	double means[meanSize];//means of nums
	
	makeMeans(rnList, means, rnSize, meanSize);	

	double chance = prob(means, meanSize, 2.0, 2.4);
	cout << "the probablity of mean between 2.0 and 2.4 inclusive is: " << chance*100 << "%" << endl;

	double avg = avgMean(means, meanSize);
	cout << "the mean of the means is : " << avg << endl;
	
	double sd = SD(means, meanSize);
	cout << "the standard deviation is : " << sd << endl;
	
	//**************************************************
	cout << "**************************************************" << endl;
	//q2
	cout << "The following statements are for question 2. " << endl;
	double pdNum[rnSize];//means of nums
	double pdMeans[meanSize];//means of nums

	makePDmean(pdNum, pdMeans, rnSize, meanSize);

	double chance2 = prob(pdMeans, meanSize, 1.140, 1.142);
	cout << "the probablity of mean between 1.140 and 1.142 exclusive is: " << chance2 * 100 << "%" << endl;

	double avg2 = avgMean(pdMeans, meanSize);
	cout << "the mean of the means is : " << avg2 << endl;

	double sd2 = SD(pdMeans, meanSize);
	cout << "the standard deviation is : " << sd2 << endl;
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
		sum = 0;		
	}
}

//find probability that mean is between x and y q1
double prob(double x[], int xSize, double min, double max)//q1
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

//find probability that mean is between x and y q2
double prob2(double x[], int xSize, double min, double max)//q2
{
	double prob;
	int count = 0;
	for (int i = 0; i < xSize; i++)
	{
		if (x[i] < min || x[i] > max)
		{
			count++;
		}
	}
	prob = 1 - ((double)count / xSize);
	return prob;
}

//find mean of means
template <class T> T avgMean(T x[], int xSize)
{
	T avg;
	T sum = 0.0;
	for (int i = 0; i < xSize; i++)
	{
		sum += x[i];
	}
	avg = sum / xSize;
	return avg;
}

//find standard deviation
template <class T> T SD(T x[], int xSize)
{
	T recpSize = (double) 1 / (double) xSize;// 1/N

	T avg = avgMean(x, meanSize);//mu

	T sigma = 0;
	T meanDiff;//mean from array - mu
	T sqMeanDiff;//(mean from array - mu)^2
	

	for (int i = 0; i < xSize; i++)
	{
		meanDiff = x[i] - avg;
		sqMeanDiff = pow(meanDiff, 2);
		sigma += sqMeanDiff;//total of all (mean - mu)^2
	}
	
	T sd = sqrt(recpSize*sigma);//standard deviation
	return sd;

}


//values from Pareto distribution
void makePDnum(double x[], int xSize)
{
	double val[len];
	int count = 1;
	
	for (int j = 0; j < len; j++)
	{//array of numbs between 0 - 1	for y val	
		val[j] = (double) count / (double) len;
		count++;
	}
	// x = 1 / (1-y)^0.125
	int yPT;
	double bottom;
	double raise;
	for (int j = 0; j < xSize; j++)
	{//fill array of pareto dist val		
		yPT = (rand() % len);//random y pt
		bottom = 1 - val[yPT];//1 - y
		raise = pow(bottom, 0.125);// (1 - y)^0.125
		x[j] = 1/raise;//1 / [(1 - y)^0.125]
	}
}

void makePDmean(double x[], double y[], int xSize, int ySize)
{
	double sum = 0;
	double avg;
	for (int i = 0; i < ySize; i++)
	{
		makePDnum(x, xSize);
		for (int j = 0; j < xSize; j++)
		{
			sum += x[j];
		}
		//make mean of pd vals
		avg = (double)sum / xSize;
		y[i] = avg;
		sum = 0;
	}
}