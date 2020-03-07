#include <iostream>
#include <string>
#include <vector>

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
  Dataset(string datasetLoc) : datasetLoc(datasetLoc) { readDataset(); }

  Dataset(Data dataset) : dataset(dataset) {}

  // Returns data
  inline Data &getData() { return dataset; }

  // Returns total number of rows in the dataset
  inline unsigned getRowCount() { return dataset.size(); }

  void printDataShape();

  void printDataset();

};
} // namespace DM

#endif DATASET_H
