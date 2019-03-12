//Name: Thomas Cooper
//Class: CSC160-101
//Due Date: 11/07/2016
//Files: curiosity.cpp
//Description: Pull temperature recordings from file and calculate avg, low,
//and high temps for each day at each reading.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;



int main()
{
	int i, j, d, l2, l3, c, day2 = 0, day3 = 0;
	double temps2[3][40] = {0}, temps3[3][40] = {0};
	double avg2 = 0, low21 = 100, high21 = -1000, avg21 = 0, low25 = 100, 
		high25 = -1000, avg25 = 0, low225 = 100, high225 = -1000, avg225 = 0, 
		avg3 = 0, tempdoub;
	double low31 = 0, high31 = -100, avg31 = 0, low35 = 0, high35 = -100, 
		avg35 = 0, low325 = 0, high325 = -100, avg325 = 0, total21 = 0, 
		total25 = 0, total225 = 0, total31 = 0, total35 = 0, total325 = 0;
	string dummy, temp;
	
	ifstream fromFile;
	ofstream toFile;
	fromFile.open("curiosity234X.dat");
	
	//first four lines ignored
	for (i = 0; i < 4; i++)
	getline (fromFile, dummy);
	
	l2 = 0, l3 = 0;
	
	
	//main part to pull data from the file until end of file.
	while (!fromFile.eof())
	{
		//pulling each line and turning them into a string stream
		getline (fromFile, temp);
		stringstream cur(temp);
		
		//String stream pulls the day
		cur >> d;
		
		//This is for everything day 2. The string stream throws the next two
		//sections from the stream and writes to a dummy string, essentially
		//throwing them away. It then pulls the numbers one by one, converts
		//it to fahrenheit, stores it in the array, adds to a total, and then
		//checks if the value is a high or a low for that day. This happens
		// for each reading and then a counter increases to keep track of the
		//number of days for later.
		if (d == 2)
		{
			cur >> dummy >> dummy;
			
			cur >> tempdoub;
			temps2[0][l2] = (tempdoub * 9.0) / 5.0 + 32;
			total21 += temps2[0][l2];
			
			if (temps2[0][l2] < low21)
				low21 = temps2[0][l2];
			if (temps2[0][l2] > high21)
				high21 = temps2[0][l2];
			
			
			cur >> tempdoub;
			temps2[1][l2] = (tempdoub * 9.0) / 5.0 + 32;
			total25 += temps2[1][l2];
			
			if (temps2[1][l2] < low25)
				low25 = temps2[1][l2];
			if (temps2[1][l2] > high25)
				high25 = temps2[1][l2];
			
			cur >> tempdoub;
			temps2[2][l2] = (tempdoub * 9.0) / 5.0 + 32;
			total225 += temps2[2][l2];
			
			if (temps2[2][l2] < low225)
				low225 = temps2[2][l2];
			if (temps2[2][l2] > high225)
				high225 = temps2[2][l2];
			
			l2++;
			day2++;
			
			
			
		}
		
		//This is the same thing for day 3
		if (d == 3)
		{
			cur >> dummy >> dummy;
			
			cur >> tempdoub;
			temps3[0][l3] = (tempdoub * 9.0) / 5.0 + 32;
			total31 += temps3[0][l3];
			
			if (temps3[0][l3] < low31)
				low31 = temps3[0][l3];
			if (temps3[0][l3] > high31)
				high31 = temps3[0][l3];
			
			cur >> tempdoub;
			temps3[1][l3] = (tempdoub * 9.0) / 5.0 + 32;
			total35 += temps3[1][l3];
			
			if (temps3[1][l3] < low35)
				low35 = temps3[1][l3];
			if (temps3[1][l3] > high35)
				high35 = temps3[1][l3];
			
			cur >> tempdoub;
			temps3[2][l3] = (tempdoub * 9.0) / 5.0 + 32;
			total325 += temps3[2][l3];
			
			if (temps3[2][l3] < low325)
				low325 = temps3[2][l3];
			if (temps3[2][l3] > high325)
				high325 = temps3[2][l3];
			
			
			l3++;
			day3++;
		}
	
	}
	
	//The averages are calculated
	avg21 = total21 / day2;
	avg25 = total25 / day2;
	avg225 = total225 / day2;
	avg31 = total31 / day3;
	avg35 = total35 / day3;
	avg325 = total325 / day3;
	
	//This is the formatting for the console output. The titles are seperated
	// with spaces as they are constant and will not move. The calculated 
	//values are spaced automatically as they change in value from single
	//digit to multiple digit, negative positive, etc.
	cout << "Solar     Average     Low        High     Average     Low        "
		"High    Average     Low       High" << endl;
	cout << " Day       Temp       Temp       Temp      Temp       Temp"
		"       Temp     Temp       Temp      Temp" << endl;
	cout <<	"                    1 meter                        .5 meters     "
		"	            .25 meters" << endl;
	cout << "  2" << setprecision(1) << fixed << setw(11) << right << avg21 <<
	setw(11) << right << low21 << setw(11) << right << high21 << setw(11) << 
	right << avg25 << setw(10) << right << low25 << setw(11) << right << high25
	<< setw(11) << right << avg225 << setw(11) << right << low225 << setw(9) <<
	right << high225 << endl;
	cout << "  3" << setprecision(1) << fixed << setw(11) << right << avg31 <<
	setw(11) << right << low31 << setw(11) << right << high31 << setw(11) <<
	right << avg35 << setw(10) << right << low35 << setw(11) << right << high35
	<< setw(11) << right << avg325 << setw(11) << right << low325 << setw(9) <<
	right << high325 << endl;
	
	//This is the formatting for the file output. Same thing above with slight
	//adjustments for notepad.
	toFile.open("output.dat");
	toFile << "Solar     Average     Low        High     Average     Low      "
	"  High    Average     Low       High" << endl;
	toFile << " Day       Temp       Temp       Temp      Temp       Temp     "
	"  Temp     Temp       Temp      Temp" << endl;
	toFile << "                     1 meter                        .5 meters  "
	"                     .25 meters" << endl;
	toFile << "  2" << setprecision(1) << fixed << setw(11) << right << avg21
	<< setw(11) << right << low21 << setw(11) << right << high21 << setw(11) <<
	right << avg25 << setw(10) << right << low25 << setw(11) << right << high25
	<< setw(11) << right << avg225 << setw(11) << right << low225 << setw(9) <<
	right << high225 << endl;
	toFile << "  3" << setprecision(1) << fixed << setw(11) << right << avg31
	<< setw(11) << right << low31 << setw(11) << right << high31 << setw(11) <<
	right << avg35 << setw(10) << right << low35 << setw(11) << right << high35
	<< setw(11) << right << avg325 << setw(11) << right << low325 << setw(9) <<
	right << high325 << endl;
	toFile.close();
	
	//Console out to inform completion.
	cout << endl;
	cout << "         " <<  "The output.dat file has been written and "
							"transmitted.";
	
	return 0;
}
