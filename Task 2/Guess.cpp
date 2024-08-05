#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(0));
	int attempts = 0;
	int guess;
	int num = rand() % 1000+1;
	//cout << num<<endl;
	cout << "Guess the number range 1-1000: ";
	cin >> guess;
	attempts++;
	while (guess != num)
	{
		if (num-guess<=500 && num-guess>250)
		{
			cout << "Too low, guess a higher number " << endl;
			cin >> guess;
			attempts++;
		}
		else if (guess-num <= 500 && guess-num>250)
		{
			cout << "Too high, guess a lower number " << endl;
			cin >> guess;
			attempts++;
		}
		else if (num-guess <= 250 && num - guess > 100)
		{
			cout << "low, guess a higher number " << endl;
			cin >> guess;
			attempts++;
		}
		else if (guess-num <= 250 && guess - num > 100)
		{
			cout << "high, guess a lower number " << endl;
			cin >> guess;
			attempts++;
		}
		else if (num-guess<= 100 && num-guess > 10)
		{
			cout << "close, guess a higher number ";
			cin >> guess;
			attempts++;
		}
		else if (guess-num <= 100 && guess-num > 10 )
		{
			cout << "close, guess a lower number ";
			cin >> guess;
			attempts++;
		}
		else if (num-guess<=10 && num-guess>0)
		{
			cout << "Extremely Close, guess a higher number ";
			cin >> guess;
			attempts++;
		}
		else if (guess-num<=10 && guess-num>0)
		{
			cout << "Extremely Close, guess a lower number ";
			cin >> guess;
			attempts++;

		}
	}
	if (guess == num)
	{
		cout << "Congratulations you guessed the number " << num << " in " << attempts << " Attempts! ";
	}
	return 0;


}