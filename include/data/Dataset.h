#include<iostream>
#include<vector>
#include<string>

#ifndef DATASET_H
#define DATASET_H

using namespace std;

typedef vector<vector<string>> Data;

namespace DM {
  class Dataset {
        string datasetLoc;	
   	Data dataset;
        
	// Reads dataset from datasetLoc
	void readDataset(); 

  public:
  	Dataset(string datasetLoc) : datasetLoc(datasetLoc) {
	  readDataset();
	}

	// Returns data
        inline Data &getData() { return dataset; }

        void printDataShape();    
  };	
}

#endif DATASET_H
