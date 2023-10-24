/* Intro
Emily is tired of rabbits eating her lettuce plants in her backyard. She is thinking of designing a ballistic Nerf dart rabbit
deterrent system, to be placed in the centre of her back lawn, which can be considered as (0,0). As part of the design
phase, over a 24-hour period starting at midnight, she recorded the time a rabbit was spotted and the (x,y) coordinates in
meters of the rabbit, saving them to a file called wascally_wabbits.txt. She wants to know the distance and heading
(an angle from -180 to 180 degrees, where 0 degrees is along the positive x-axis) of each rabbit, and the shortest time in
minutes between rabbit sightings.
*/

/* File Format
wascally_wabbits.txt contains an unknown number of lines. Each line contains three values: a time, an x
coordinate, and a y coordinate.
? The time is an integer in an HHMM format on a 24 hour clock. For example, 1450 represents the time 2:50 pm.
? The x and y coordinates are relative to a point at the centre of the lawn (0,0).
? File data can be assumed to be valid coordinates, which will not include the point (0,0)
*/

/* The program:
Write a function that:
? Receives a time as an integer in HHMM format (eg. 0350)
? Returns the time in minutes from midnight (eg. 230)
Write a function that:
? Receives a location x and y in m
? Returns the distance to that location in m
Write a function that:
? Receives a location x and y in m
? Returns the heading in degrees, between -180 and 180
Write a program that:
? Opens the file wascally_wabbits.txt and checks if it has opened
? Opens an output file to store the results
? Reads the data on each rabbit, and outputs to the file the distance and heading to each rabbit
? Outputs to the file the shortest time, in minutes, between rabbits
? Closes the files
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int mins_2_mid(int time) // function to get time in minutes
{
	int hours = time/100;
	int minutes = time % 100; // to get minutes from midnight
	int minutes_midnight = (hours*6) + minutes;	
	return minutes_midnight;
}

float getDistance (float x, float y)
{
	float distance = sqrt(pow(x,2) + pow(y,2)); // use pyathagoras theorem to find the distance from 0,0
	return distance;
}

float getBearingAngle (float x, float y) // get angle bearing using arctan and convert to degrees
{
	float angleRad = atan(y/x);
	if (angleRad > M_PI ) // ensure that the value is between -pi < x < pi, if it isnt then it adds or subtracts pi accordingly
	{
		angleRad = angleRad - M_PI;
	}
	if (angleRad < -M_PI)
	{
		angleRad = angleRad + M_PI;
	}
	else
	{
		angleRad = angleRad;
	}
	float angleDeg = (angleRad *180)/ M_PI;
	return angleDeg;	
}
/*float shortestTime(int time, int time1) (still a work in progress)
{
	if (time > time1)
	{
		int temp; 
		temp = time;
		time = time1;
		time1 = temp;
	}
}*/
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
	file 
	while (fileIn >> time >> x_cord >> y_cord) // loop to make sure the code runs to the end of the file
	{
		fileOut << mins_2_mid(time) << "  " <<getDistance(x_cord, y_cord) << "  "<< getBearingAngle(x_cord, y_cord) << "\n"; //file output
		cout << mins_2_mid(time) << "  " <<getDistance(x_cord, y_cord) << "  "<< getBearingAngle(x_cord, y_cord) << "\n"; //output on code to see whether it works
		
	}
	
	fileIn.close();
	fileOut.close(); // closing both output and input files
	return EXIT_SUCCESS;
}
