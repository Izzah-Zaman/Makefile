#include <stdio.h>
#include <iostream>
#include "vectorList.h"

vectorList::vectorList(int x):len(x) {
		std::cout << "Length: " << len<< std::endl; 
		//std::vector<int> col(len, 0);
		vector = new int[ len ];
		for(int i=0; i<len; i++){
		vector[i]=1;
		}
		std::cout << "Vector value " <<  len << std::endl;
	}




