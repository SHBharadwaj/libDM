#include "include/data/Dataset.h"

#ifndef SAMPLING_H
#define SAMPLING_H

namespace DM {
class Sampler {
  Dataset *dataset;
  unsigned sampleSize;

public:
  Sampler(Dataset *dataset, unsigned sampleSize)
      : dataset(dataset), sampleSize(sampleSize) {}

  virtual Dataset getDataSample();

  inline Dataset *getCurrDataset() { return dataset; }

  inline unsigned getSampleSize() { return sampleSize; }
};

class RandomSampler : public Sampler {
  bool replaceItems = false;
  Data sampledData;

public:
  RandomSampler(Dataset *dataset, unsigned sampleSize,
                bool replaceItems = false)
      : Sampler(dataset, sampleSize), replaceItems(replaceItems) {}

  Dataset getDataSample();

  Dataset sampleWithReplacement();

  Dataset sampleWithoutReplacement();
};

// TODO: Class for stratified sampler has to be added here.
} // namespace DM

#endif SAMPLING_H
