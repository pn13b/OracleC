//============================================================================
// Name        : HardwoodSellerC.cpp
// Author      : Esteban Parra
// Version     : 1
// Copyright   : It's free
// Description : Main class for the Hardwood Seller
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void readInputFile(string);

int main() {
	cout << "Welcome to the program" << endl;
	
	string name;
	
	cout << "Enter filename" << endl;
	cin >> name;
	cout << name << endl;
	
	readInputFile(name);

	
	
	return 0;
}

/*
 * Method to read the input file
 */
void readInputFile(string inputFilePath) {
	string line;
	ifstream myfile (inputFilePath.c_str());
	
	if(myfile.is_open())
	{
		while(getline(myfile, line))
			cout << line << '\n';
		myfile.close();
	}
	else
		cout << "unable to open file" << endl;
}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime() {
	double deliveryETA = 0.0;
	return deliveryETA;
}
