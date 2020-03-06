#include "include/data/Dataset.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iterator>

using namespace DM;

// TODO: Add support to multiple delimiters
void Dataset::readDataset() {
  ifstream file(datasetLoc);
  string line, word;
  while (getline(file, line)) {
    vector<string> row;
    boost::algorithm::split(row, line, boost::is_any_of(","));
    dataset.push_back(row);
  }
}

void Dataset::printDataShape() {
  cout << dataset.size() << "*" << dataset[0].size() << endl;
}

void Dataset::printDataset() {
  for (auto row : dataset) {
    for (auto column : row) {
      cout << column << " ";
    }
    cout << endl;
  }
}
