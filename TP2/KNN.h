#ifndef TP2_KNN_H
#define TP2_KNN_H

#include <vector>
#include <string>
#include "TimeSeriesDataset.h"

class KNN {
private:
    int k;
    std::string similarity_measure;
public:
    KNN(int k, std::string similarity_measure);
    double evaluate(const TimeSeriesDataset& trainSet,
                    const TimeSeriesDataset& testSet,
                    const std::vector<int>& groundTruth);
};

#endif //TP2_KNN_H