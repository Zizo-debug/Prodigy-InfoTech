#include <iostream>
using namespace std;

//validity of the number
bool checkPossiblity(int grid[9][9], int value, int xCord, int yCord)
{
	for (int i = 0; i < 9; i++)
	{
		if (grid[yCord][i] == value)
			return false;
	}

	for (int i = 0; i < 9; i++)
	{
		if (grid[i][xCord] == value)
			return false;
	}
	int x = (xCord/3)*3;
	int y = (yCord / 3) * 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[y+i][x+j] == value)
				return false;
		}
	}
	return true;

}

//solve

bool solve(int grid[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (grid[i][j] == 0)
			{
				for (int k = 1; k < 10; k++)
				{
					if (checkPossiblity(grid, k, j, i))
					{
						grid[i][j] = k;
						if (solve(grid)) {
							return true;
						}
						else {
							grid[i][j] = 0;
						}
					}
				}
				return false;
			}
		}
	}
	return true;
}

/*
int main()
{
	int grid[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
{5, 2, 0, 0, 0, 0, 0, 0, 0},
{0, 8, 7, 0, 0, 0, 0, 3, 1},
{0, 0, 3, 0, 1, 0, 0, 8, 0},
{9, 0, 0, 8, 6, 3, 0, 0, 5},
{0, 5, 0, 0, 9, 0, 6, 0, 0},
{1, 3, 0, 0, 0, 0, 2, 5, 0},
{0, 0, 0, 0, 0, 0, 0, 7, 4},
{0, 0, 5, 2, 0, 6, 3, 0, 0} };
	cout << "--------------Initial Grid--------" << endl << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << grid[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	cout << "--------------Solved Grid--------" << endl << endl;
	if (solve(grid)) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << grid[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else {
		cout << "No solution exists" << endl;
	}

	return 0;


}
*/