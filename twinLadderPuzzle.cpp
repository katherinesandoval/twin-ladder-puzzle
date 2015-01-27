/* 
	Author: Katherine Sandoval
	Date: 09/24/2013
	Contact: kate_sandoval27@hotmail.com
    Description: In an alleyway between two buildings, two ladders cross each other. This program 
	finds the width of the alley given that the ladders are 20 feet and 30 feet long, and the point 
	at which they cross is 10 feet above the ground.
*/

#include <iostream>
#include <cmath>
using namespace std;

const double DX = 0.125; // "x" will be increased by this value everytime it loops to create a new guess. It's also the choosen value for "almost zero."

int main()
{
	double A;		// This is the height of building A (20ft ladder)
	double B;		// This is the height of building B (30ft ladder)
	double H;		// This is the height of the point at which the ladders crossed (10ft)
	double X;		// This is the width of the alley (the value that is being searched) 
	double closeness;	// This variable checks how close is H to 10
	
	// Create a new guess of "X" by adding a DX (0.125) value to "guess"
	for (double guess = 5; guess < 20; guess += DX)
	{
		// Find the value of A and B given "guess"
		A = sqrt(400 - pow(guess,2));
		B = sqrt(900 - pow(guess,2));

		// Compute H
		H = guess / ( (guess / A) + (guess / B) );

		// Check how close it's H to 10 
		closeness = H - 10;
		
		// If closeness is almost 0, X has been found
		if (abs(closeness) <= DX)
		{
			X = guess;
			cout << "The Alley Width is: " << X << endl;
			break;
		}
	} // End of for Loop

	system("pause");
	return 0;
} // End of main
