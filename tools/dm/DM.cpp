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

  return 0;
}
