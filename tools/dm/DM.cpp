#include "include/data/Dataset.h"
#include "include/preprocess/Sampling.h"
#include <getopt.h>
#include <iostream>
#include <string>

using namespace DM;

unsigned sampleSize = -1;
string filePath = "";

bool printData = false;
bool sampleData = false;
bool printShape = false;
bool datasetPathSet = false;

void PrintHelp() {
  cout << "--printData               : print the dataset\n"
          "--randomSample <n>       : Input the sample size\n"
          "--printShape              : prints the shape of the dataset\n"
          "--inputDataset <dataset> : set the full path for dataset\n"
          "--help                    : Show help\n";
  exit(1);
}

void parseCmdLineOptions(int argc, char **argv) {
  const char *const short_opts = "p:r:s:f:h";
  const option long_opts[] = {{"printData", no_argument, nullptr, 'p'},
                              {"randomSample", required_argument, nullptr, 'r'},
                              {"printShape", no_argument, nullptr, 's'},
                              {"inputDataset", required_argument, nullptr, 'f'},
                              {"help", no_argument, nullptr, 'h'},
                              {nullptr, no_argument, nullptr, 0}};

  while (true) {
    const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

    if (opt == -1) {
      break;
    }

    switch (opt) {
    case 'p':
      printData = true;
      break;

    case 'r':
      sampleData = true;
      sampleSize = std::stoi(optarg);
      break;

    case 's':
      printShape = true;
      break;

    case 'f':
      datasetPathSet = true;
      filePath = std::string(optarg);
      break;

    case 'h':
    default:
      PrintHelp();
      break;
    }
  }
}

int main(int argc, char **argv) {
  parseCmdLineOptions(argc, argv);
  if (!datasetPathSet) {
    PrintHelp();
  }

  Dataset currDataset = Dataset(filePath);

  if (printData) {
    currDataset.printDataset();
  }

  if (sampleData) {
    RandomSampler sampler(&currDataset, sampleSize);
    auto dataSample = sampler.getDataSample();
    dataSample.printDataset();
  }

  if (printShape) {
    currDataset.printDataShape();
  }

  // TODO: Add a commandline support to these operations !
  // for eg: --apply-sampling n = 10
  //         --print-shape

  /*unsigned OptionSelected = 1;
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
      dataSample.printDataShape();
      break;
    }
    case 2:
      currDataset.printDataShape();
      break;
    case 3:
      OptionSelected = 0;
      break;
    default:
      cout << "Choose a valid option " << endl;
      break;
    };
  }*/

  cout << "Thank you for using the program" << endl;
  return 0;
}
