#include <iostream>
#include <string>

using namespace std;

int main()
{
	float temp, ConvertOne,  ConvertTwo;
	string unit;
	cout << "Enter the temparature unit by typing Kelvin, Fahrenheit, Celcius: " << endl;
	getline(cin, unit);
	cout << "Enter the temparature value: " << endl;
	cin >> temp;
	if (unit == "Kelvin")
	{
		while (temp < 0)
		{
			cout << "Enter the correct temparature value: " << endl;
			cin >> temp;
		}
 
		ConvertOne = temp + 273.15;
		ConvertTwo = (ConvertOne * 9/5)+32;
		cout << "The temperature in Celcius : " << ConvertOne << endl;
		cout << "The temperature in Fahrenheit: " << ConvertTwo << endl;
	}
	else if(unit == "Celcius")
	{
		ConvertOne = temp + 273.15;
		ConvertTwo = (temp * 9/5)  + 32;
		cout << "The temperature in Kelvin : " << ConvertOne << endl;
		cout << "The temperature in Fahrenheit: " << ConvertTwo << endl;
	}
	else if (unit == "Fahrenheit")
	{
		ConvertOne = (((temp - 32) * 5) / 9)+273.15;
		ConvertTwo = ((temp-32)*5)/9;
		cout << "The temperature in Kelvin : " << ConvertOne << endl;
		cout << "The temperature in Celcius: " << ConvertTwo << endl;
	}
	else {
		cout << "Error! " << endl;
		return 0;
	}


}