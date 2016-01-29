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

void readInputFile(string);
void basics(string);
void woodDataPrinter(string);

	struct wood {
		string name;
		int amount;
	};

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
double deliveryTime() {
	double deliveryETA = 0.0;
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
	
	for(int k = 0; k != amounts.size(); ++k)
	{
		cout << "Name: " << amounts[k].name << ", Amount: " <<
			amounts[k].amount << " BF, Cost: $";
			
		if(amounts[k].name == "Cherry") {
			cout << 5.95;
			totalCost += 5.95;
		}
		else if(amounts[k].name == "Curly Maple") {
			cout << 6.00;
			totalCost += 6.00;
		}
		else if(amounts[k].name == "Genuine Mahogany") {
			cout << 9.60;
			totalCost += 9.60;
		}
		else if(amounts[k].name == "Wenge") {
			cout << 22.35;
			totalCost += 22.35;
		}
		else if(amounts[k].name == "White Oak") {
			cout << 6.70;
			totalCost += 6.70;
		}
		else if(amounts[k].name == "Sawdust") {
			cout << 1.5;
			totalCost +=1.5;
		}
		
		cout << endl;
	}
	cout << "\nTotal cost: " << totalCost << endl;
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