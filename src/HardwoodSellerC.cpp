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
void basics(string);

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
		cout << "made it" << endl;
		getline(myfile, line);
		line.append("\n");
		basics(line);
		
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


void basics(string liner){
	int i = 0;
	short trigger = 0;
	
	cout << "Name: ";
	
	while(liner[i] != '\n')
	{
		if(liner[i] != ';')
			cout << liner[i];
		else
		{
			cout << endl;
			if(trigger == 1)
				cout << "Date: ";
			else
			{
				cout << "Address: ";
				++trigger;
			}
		}
		++i;
	}
	
	cout << endl;
	
}