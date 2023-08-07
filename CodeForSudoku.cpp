// C++ Program to solve sudoku using Recursion-Backtracking

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

//can i put this num at cell(r,c)
bool isSafe(int r,int c,int num,vector<vector<int>> &dp)
{
	for(int i=0 ;i<dp[0].size(); i++)
	{
		if(dp[r][i] == num)
		{
			return false;
		}	
	}	

	for(int j=0; j<dp[0].size(); j++)
	{
		if(dp[j][c] == num)
		{
			return false;
		}	
	}	
    
  int sqr = (int)sqrt(9);
	int startr = r - (r%sqr);
	int startc = c - (c%sqr);
    
    for(int i = startr; i< startr+sqr; i++)
    {
    	for(int j = startc; j < startc+sqr; j++)
    	{
    		if(dp[i][j] == num)
    	   {
    	   	 return false;
    	   }		
    	}	
    }	

    return true;
}

//
bool sudoku(int r,int c, vector<vector<int>> &dp)
{

	if(r == dp[0].size()-1 && c == dp[0].size())   //Base case (when we have reached the end of the last row of sudoku)
	{
		return true;
	}	

	if(c==dp[0].size())       //When we reach end of 1st row, which means 1st row is filled with numbers, so go to next row.
	{
		return sudoku(r+1,0,dp);
	}	

	if(dp[r][c] == 0)            //if the current cell is empty, try to fill correct numbers in it.
 {
		for(int i=1; i<=9; i++)
   {		
	  	if(isSafe(r,c,i,dp))     //Check whether it is safe to put the current number in the current cell or not.
		 {
		  	dp[r][c] = i;        //put the number in the cell
			 if(sudoku(r,c+1,dp))       
	       return true;         //if, if() condition becomes true, means sudoku has been solved correctly.Hence return true.
     }                       // if, if() condition becomes false, means one of the cells can not be filled correctly with any of the numbers from 1 to 9,                           
  }                             so fill the current cell with other numbers,if it is safe .
}

	  dp[r][c] = 0;          // otherwise make current cell empty and return false.
	  if(dp[r][c] == 0)      //Backtrack
	  	return false;
	}	
    
    return sudoku(r,c+1,dp); // if current cell is already filled ,go to next cell.
}

//Driver Code
int main()
{
	#ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif

    vector<vector<int>> dp{             // GIven Sudoku to be solved in the input.
    	{3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    
   /* for(vector<char> vec:dp)
    {
    	for(char x:vec)
    	{
    		cout<< x <<" "; 
    	}
    	cout<<endl;	
    }*/

    for(int i=0; i<dp.size(); i++)             //Display the sudoku given in input.
   {
   	 for(int j=0; j<dp[0].size();j++)
   	 {
   	 	if(j==3 || j==6)
   	    {
   	      cout<<"|";		
   	 	}

   	 	 cout<< dp[i][j] <<" "; 	  
   	 }	

   	 if(i==2 || i==5)
   	 {
   	 	cout<<endl;
   	 	cout<<"-------------------";
   	 }	
   	 cout<<endl;
   } 	

    cout<<endl;  
    cout<<endl;

    bool fg1 = sudoku(0,0,dp);          //sudoku() function will solve the given input sudoku 
  
    if(fg1 == true)                    //Display the sudoku if it has been solved.
    {   
    	for(int i=0; i<dp.size(); i++)
      {
   	    for(int j=0; j<dp[0].size();j++)
   	   {
   	 	  if(j==3 || j==6)
   	     {
   	       cout<<"|";		
   	 	 }

   	 	  cout<< dp[i][j] <<" "; 	  
   	   }	

   	    if(i==2 || i==5)
   	   {
   	 	  cout<<endl;
   	 	  cout<<"-------------------";
   	   }	
   	    cout<<endl;
     }

	}
	else
	{
		cout<<"sudoku can not be solved"<<endl;
	}	

    return 0;
}
