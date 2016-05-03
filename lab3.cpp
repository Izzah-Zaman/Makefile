#include <iostream>
#include <vector>
#include <random>
#include <stdio.h>
#include "vectorList.h"
#include "matrixList.h"
using namespace std;

#define NUM_THREADS 5



int row =10;
int column =10;
matrixList  matrix1(row, column);
matrixList  matrix2(row, column);
int length=10;
vectorList  v(length);
matrixList  m(row,column);

int* mult = new int[matrix1.row*matrix2.column];
void *multiplyMat (void *id1){
	int i=0;
	int j=0;
	int k=0;
        int id = *((int*)id1);
	
 	std::cout << "ID: "<<id1;
	if (matrix1.column == matrix2.row){

	//std::cout << "multiplication possible\n"; 
	int each = matrix1.row/NUM_THREADS;
	
	int start = each*id;
	int end = start + each;
	if((matrix1.row%NUM_THREADS!=0) && (id==NUM_THREADS - 1) ){
	end = matrix1.row;
	}
	 

	for(i=start; i<end; i++){
      	//std::cout <<"start: "<<start <<"  end:" << end <<"  each" << each << "   i:" <<i;
    	for(j=0; j<matrix2.column; j++)
    	{
        for(k=0; k<matrix2.row; k++){
        
	mult[(i*matrix2.column)+j] = mult[(i*matrix2.column)+j] + (matrix1.mat[(i*matrix1.column)+k])* (matrix2.mat[(k*matrix2.column)+j]);
		
   	 }
	//std::cout <<mult[(i*matrix2.column)+j] << "   ";

	}
	//std::cout << "\n";
	
	} 
	}
	else {
	std::cout << "multiplication NOT possible\n"; 
	
	}
	
	return 0;
}


void *multiplyVecMat ( void *id1){
	int i=0;
	int j=0;
	int id = *((int *)id1);
	if (m.column == v.len){
	//std::cout << "multiplication possible\n"; 
	 int* mult = new int[m.row];
	 
	int each = m.row/NUM_THREADS;
	
	int start = each*id;
	int end = start + each;
	if((m.row%NUM_THREADS!=0) && (id==NUM_THREADS - 1) ){
	end = m.row;
	}
	for(i=0; i<m.row; ++i){
	 	mult[i] =0;
		//std::cout <<mult[i] << "\n";
	 }

	for(i=start; i<end; ++i){
    	for(j=0; j<m.column; ++j)
    		{
        
        //m.mat[row*column]=1;
      //  std::cout << "mat[" << i+1 << "]["<< j+1 << "]: " << matrix1.mat[row*column];
		// std::cout << m.mat[row*column] << "   ";
		mult[i] = mult[i] + m.mat[i + j]* v.vector[j];
		if(j==(m.column-1)){
		std::cout <<mult[i] << "\n";
		}
    	}
	std::cout << "\n" ;
	}
	
	
	
	} 
	else {
	std::cout << "multiplication NOT possible\n"; 
	
	}
	
	return 0;
}



int main()
{    
	int rc;
	int rc2;
	pthread_t threads[NUM_THREADS];
	pthread_t threads2[NUM_THREADS];
	int k=0;
	int i=0;
	int j=0;

	for(i=0; i<row; ++i){
   	 for(j=0; j<column; ++j)
    	{
        
        matrix1.mat[(i*row)+j]=1;
	matrix2.mat[(i*row)+j]=1;
    	}
	}
	for(i=0; i<(matrix1.row*matrix2.column); ++i){
	 	mult[i] =0;
	 }

	 void *status;

	for( int i1=0; i1 < NUM_THREADS; i1++ ){
      		std::cout << "main() : creating thread, " << i1 << std::endl;
      		//rc = pthread_create(&threads[i1], NULL,  multiplyMat, (void*)i1);
		rc2 = pthread_create(&threads2[i1], NULL,  multiplyVecMat, (void*)&i1);
		//pthread_join(threads[i1], &status);
		pthread_join(threads2[i1], &status);

      if (rc2){
        std::cout << "Error:unable to create thread," << rc << std::endl;
      }
   }
	
   pthread_exit(NULL);

}

