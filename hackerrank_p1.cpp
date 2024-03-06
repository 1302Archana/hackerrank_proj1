// hackerrank_p1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <vector>
using namespace std;

int findNoofPaths(vector<vector<int>> vec);

	int main()
	{
		int rows, colmns;
		int paths;
		cout << "no of rows" << endl;
		cin >> rows;
		cout << " no. of columns" << endl;
		cin >> colmns;
		//vector<vector<int>> A;
		vector<vector<int>> A(rows, vector<int>(colmns));
			cout << "enter the elements"<<endl;
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < colmns; j++)
			{
				cin >> A[i][j];
			}
			cout << endl;
			
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < colmns; j++){
				cout << A[i][j] << " ";
			}
			cout << endl;
			
		}

	 paths =  findNoofPaths(A);
	 cout << "no. of possible paths: " << paths;
	 return 0;


	}
	int findNoofPaths(vector<vector<int>> A) 
	{  // obstacles are 0 s and paths represented as 1;	 

		if (A[0][0] == 0) return 0;

		else {
			for (int i = 1; i < A[0].size(); i++) // n0.of columns;
			{
				if (A[0][i] == 1)
				{
					A[0][i] = A[0][i - 1];
				}
			}
			for (int i = 1; i < A.size(); i++)
			{
				if (A[i][0] == 1)
				{
					A[i][0] = A[i - 1][0];

				}
			}
			for (int i = 1; i < A.size(); i++) {
				for (int j = 1; j < A[0].size(); j++) {

					if (A[i][j] == 1) {
						A[i][j] = A[i - 1][j] + A[i][j - 1];
					}

				}
			}
			cout << "modified matrix is:";

			for (int i = 0; i < A.size(); i++) {
				for (int j = 0; j < A[0].size(); j++) {
					cout << A[i][j] << " ";
				}
				cout << endl;

			}
			return (A[(A.size())-1][(A[0].size()) -1]);

		}
		

	}



