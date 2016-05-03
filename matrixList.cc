#include <stdio.h>
#include <iostream>
#include "matrixList.h"
  
	
	
	matrixList::matrixList(int x, int y): row(x),column(y) {
		std::cout << "Row: " << row << " Column: " << column << std::endl;
		 mat = new int[row * column];
		 matrix1 = new int[row * column];
		 matrix2 = new int[row * column];
		for(int i=0; i<row*column; i++){
			mat[i]=1;
			}
	}



