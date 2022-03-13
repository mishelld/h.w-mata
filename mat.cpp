#include "mat.hpp"
#include <iostream>
using namespace std;
namespace ariel {
    
	string mat(int a,int b,char c,char d){
        //https://rollbar.com/blog/error-exceptions-in-c/
          if (a%2==0 || b%2==0)
      {
         throw invalid_argument("Mat size is always odd \n");
    
         
      }
      if (a<=0 || b<=0 )
      {
         throw invalid_argument("The row and column number is always positive \n");
         
         
      }
      if (c==d)
      {
         throw invalid_argument("Symbols should be different \n");
        
         
      }
      if 
       (!(c >= 33 && c <= 126) || !(d >= 33 && d <= 126))
      {
        throw invalid_argument("the symbols needs to be char \n");
      }
    
     
    int n =a;
	int m = b;
    int numbers[m][n];
    //init the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
             numbers[i][j]  = 0;
        }
    }


    //turn into steps of numbers in matrix:like so
    //00000
    //01111
    //01222
    //01233
    //01234
	for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if(numbers[i-1][j]==numbers[i][j-1]){
				numbers[i][j]= numbers[i-1][j]+1;
			}
			else if(max(numbers[i-1][j],numbers[i][j-1])==0){
				numbers[i][j] = 1;
            }
            else {
				numbers[i][j]=max(numbers[i-1][j],numbers[i][j-1]);
			}
        }
    }
//copy the matrix a;
 int copy[m][n];
    //init the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
             copy[i][j]  = numbers[i][j];
        }
    }

          
    // rotate the matrix by 180 degrees

    //https://kalkicode.com/rotate-matrix-180-degree
        int temp = 0;
		int row = b - 1;
        int col = a - 1;
		int row_size = (b / 2);
		int col_size =a;
		if (b % 2 == 1) {
			//When in case number of rows are Odd size
			row_size = (b / 2) + 1;
		}
		for (int i = 0; i < row_size; ++i) {
			if (b / 2 == i) {
				//When in case number of rows are Odd size
				//In This case reverse middle row element
				col_size = a / 2;
			} else {
				col_size = a;
			}
			for (int j = 0; j < col_size; ++j) {
				//Swap element
				temp = numbers[i][j];
				numbers[i][j] = numbers[row - i][col - j];
				numbers[row - i][col - j] = temp;
			}
		}
	

    string final;
	for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
           int m = min(numbers[i][j],copy[i][j]);
           if(m%2==0){
               final += c;
           }else{
                final += d;
           }
        }
	
        final += '\n';

    }
        return final;
      

        
    }
}
 
    