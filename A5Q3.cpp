/*
Alessandra Grant and Koustav Bhasin
Version 1.0
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
//Minutes till midnight
int mins_2_mid(int time) // function to get time in minutes
{
	int hours = time/100;
	int minutes = time % 100; // to get minutes from midnight
	int minutes_midnight = (hours*6) + minutes;
	return minutes_midnight;
}
//Distance
float getDistance (float x, float y)
{
	float distance = sqrt(pow(x,2) + pow(y,2)); // use pyathagoras theorem to find the distance from 0,0
	return distance;
}
//Angle
float getBearingAngle (float x, float y) // get angle bearing using arctan and convert to degrees
{
	//atan2 because its between pi and -pi
	//pos x axis is 0 degrees
	float angleRad = atan2(y,x);
	//convert to degrees
	float angleDeg = (angleRad *180)/ M_PI;
	return angleDeg;
}

int main()
{
	ifstream fileIn ("wascally_wabbits.txt"); // check file open/close
	ofstream fileOut ("output.txt");

	if (!fileIn || !fileOut)
		{
			cout << "Unable to open files\n";
			return EXIT_FAILURE;
		}
	float time = 0.0;
	float x_cord = 0.0;
	float y_cord = 0.0;
	float time_rabbit_1=0;
	float time_rabbit_2=0;
	float shortest_time=100000;//assuming this is greater than the first time between rabbits
	float new_time=0;
	fileOut<<setw(15)<<"MinTillMidnight"<<setw(11)<<"Distance"<<setw(10)<<"Angle\n";
	while (fileIn >> time >> x_cord >> y_cord) // loop to make sure the code runs to the end of the file
		{
			//Get shortest time between rabbits
			time_rabbit_2=time;
			new_time=max(time_rabbit_2,time_rabbit_1)-min(time_rabbit_2,time_rabbit_1);
			if(shortest_time>new_time)
				{
					shortest_time=new_time;
				}
			time_rabbit_1=time_rabbit_2;
			fileOut << setw(15)<<setprecision(4)<<mins_2_mid(time)<<setw(11)<<getDistance(x_cord, y_cord);
			fileOut << setw(9)<<getBearingAngle(x_cord, y_cord) << "\n"; //file output
		}
	fileOut<<"The shortest time between rabbits is "<<shortest_time<<" minutes.";
	fileIn.close();
	fileOut.close(); // closing both output and input files
	return EXIT_SUCCESS;
}
//In the closed console:
/*

--------------------------------
Process exited after 0.09827 seconds with return value 0
Press any key to continue . . .
*/