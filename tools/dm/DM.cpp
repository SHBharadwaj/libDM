#include "include/data/Dataset.h"
#include "include/preprocess/Sampling.h"
#include <iostream>
#include <string>

#define ARGS_REQUIRED 2

using namespace DM;

int main(int argc, char *argv[]) {
  if (argc != ARGS_REQUIRED) {
    cout << " Syntax : < executable > < path-to-dataset > ";
    exit(0);
  }

  std::string filePath = argv[1];

  Dataset currDataset = Dataset(filePath);

  unsigned OptionSelected = 1;
  while (OptionSelected) {
    cout << "\nChoose operation on your dataset \n";
    cout << " 1. Apply random sampling \n";
    cout << " 2. Print dimensions of my dataset \n";
    cout << " 3. Select 0 to exit \n\n";

    cin >> OptionSelected;

    switch (OptionSelected) {
    case 1: {
      unsigned sampleSize;
      cout << "\n Input sample size \n";
      cin >> sampleSize;
      RandomSampler sampler(&currDataset, sampleSize);
      auto dataSample = sampler.getDataSample();
      dataSample.printDataset();
      break;
    }
    case 2:
      currDataset.printDataShape();
      break;
    default:
      cout << "Choose a valid option " << endl;
      break;
    };
  }

  cout << "Thank you for using the program" << endl;
  return 0;
}
