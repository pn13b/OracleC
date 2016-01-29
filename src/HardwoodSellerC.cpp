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
#include <vector>
#include <cstdlib>
using namespace std;

struct wood {
	string name;
	double amount;
	double hours;
};

void readInputFile(string);
void basics(string);
void woodDataPrinter(string);
double deliveryTime(vector<wood>);

int main() {
	cout << "Welcome to the program" << endl;
	
	string name;
	
	cout << "Enter filename: ";
	cin >> name;
	cout << endl;
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
		getline(myfile, line);
		line += '\n';
		basics(line);
		getline(myfile, line);
		line += '\n';
		woodDataPrinter(line);

		myfile.close();
	}
	else
		cout << "unable to open file" << endl;
}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime(vector<wood> amounts) {
	double deliveryETA = 0.0;
	
	for(int i = 0; i != amounts.size(); ++i)
	{		
		if(amounts[i].name == "Cherry") {
			amounts[i].hours = 2.5;
		}
		else if(amounts[i].name == "Curly Maple") {
			amounts[i].hours = 1.5;
		}
		else if(amounts[i].name == "Genuine Mahogany") {
			amounts[i].hours = 3;
		}
		else if(amounts[i].name == "Wenge") {
			amounts[i].hours = 5;
		}
		else if(amounts[i].name == "White Oak") {
			amounts[i].hours = 2.3;
		}
		else if(amounts[i].name == "Sawdust") {
			amounts[i].hours = 1;
		}
	}
	
	for(int k = 0; k != amounts.size(); ++k)
	{
		if((amounts[k].amount >= 1) && (amounts[k].amount <= 100))
			amounts[k].hours *= 1;
		else if((amounts[k].amount >= 101) && (amounts[k].amount <= 200))
			amounts[k].hours *= 2;
		else if((amounts[k].amount >= 201) && (amounts[k].amount <= 300))
			amounts[k].hours *= 3;
		else if((amounts[k].amount >= 301) && (amounts[k].amount <= 400))
			amounts[k].hours *= 4;
		else if((amounts[k].amount >= 401) && (amounts[k].amount <= 500))
			amounts[k].hours *= 5;
		else if((amounts[k].amount >= 501) && (amounts[k].amount <= 1000))
			amounts[k].hours *= 5.5;
	}
	
	for(int j = 0; j != amounts.size(); j++)
	{
		deliveryETA += amounts[j].hours;
	}
	
	return deliveryETA;
}


void woodDataPrinter(string liner)
{
	string temp;
	string holder;
	short tigger = 0;
	vector<wood> amounts;
	wood t;
	
	int trailing = 0;
	
	for(int i = 0; i != liner.length(); ++i)
	{
		if(liner[i] == ':' || liner[i] == ';' || liner[i] == '\n')
		{
			temp = liner.substr(trailing, i-trailing);
			trailing = i+1;
			//cout << temp << endl;
			
			if(liner[i] == ':')
				t.name = temp;
			else if(liner[i] == ';' || liner[i] == '\n')
			{
				t.amount = atoi(temp.c_str());
				amounts.push_back(t);
			}
			temp.clear();
		}
	}
	
	cout << endl;
	double totalCost = 0;
	double estimate;
	
	estimate = deliveryTime(amounts);
	
	for(int k = 0; k != amounts.size(); ++k)
	{
		cout << "Name: " << amounts[k].name << ", Amount: " <<
			amounts[k].amount << " BF, Cost: $";
			
		if(amounts[k].name == "Cherry") {
			totalCost = totalCost + (5.95 * amounts[k].amount);
			cout << (5.95 * amounts[k].amount);
		}
		else if(amounts[k].name == "Curly Maple") {
			totalCost = totalCost + (6.00 * amounts[k].amount);
			cout << (6.00 * amounts[k].amount);
		}
		else if(amounts[k].name == "Genuine Mahogany") {
			totalCost = totalCost + (9.60 * amounts[k].amount);
			cout << (9.60 * amounts[k].amount);
		}
		else if(amounts[k].name == "Wenge") {
			totalCost = totalCost + (22.35 * amounts[k].amount);
			cout << (22.35 * amounts[k].amount);
		}
		else if(amounts[k].name == "White Oak") {
			totalCost = totalCost + (6.70 * amounts[k].amount);
			cout << (6.70 * amounts[k].amount);
		}
		else if(amounts[k].name == "Sawdust") {
			totalCost = totalCost + (1.5 * amounts[k].amount);
			cout << (1.5 * amounts[k].amount);
		}
		
		cout << endl;
	}
	cout << "\nTotal cost: $" << totalCost << endl;
	cout << "Total time: " << estimate << " hours" << endl;
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