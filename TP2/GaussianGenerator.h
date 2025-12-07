#ifndef TP2_GAUSSIANGENERATOR_H
#define TP2_GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double stdDev;

public:
    GaussianGenerator(double mean, double stdDev, int seed = 0);
    GaussianGenerator();
    double boxMuller();
    std::vector<double> generateTimeSeries(int size) override;
};

#endif //TP2_GAUSSIANGENERATOR_H