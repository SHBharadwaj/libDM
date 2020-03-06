#include "include/preprocess/Sampling.h"

using namespace DM;

Dataset Sampler::getDataSample() { return *dataset; }

Dataset RandomSampler::getDataSample() {
  if (replaceItems) {
    sampleWithoutReplacement();
    return Dataset(sampledData);
  } else {
    sampleWithReplacement();
    return Dataset(sampledData);
  }
}

void RandomSampler::sampleWithoutReplacement() {
  unsigned count = 0;
  auto data = getCurrDataset()->getData();
  while (count < getSampleSize()) {
    auto randomNumber = rand() % (getCurrDataset()->getRowCount()) + 1;
    sampledData.push_back(data[randomNumber]);
    count++;
  }
}

void RandomSampler::sampleWithReplacement() {
  unsigned count = 0;
  auto totalRows = getCurrDataset()->getRowCount();
  bool IsChoosen[totalRows] = {0};

  auto data = getCurrDataset()->getData();
  while (count < getSampleSize()) {
    auto randomNumber = rand() % totalRows + 1;
    if (!IsChoosen[randomNumber]) {
      sampledData.push_back(data[randomNumber]);
      count++;
    }
  }
}
