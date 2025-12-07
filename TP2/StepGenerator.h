#ifndef TP2_STEPGENERATOR_H
#define TP2_STEPGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator(int seed = 0);
    std::vector<double> generateTimeSeries(int count) override;
};

#endif //TP2_STEPGENERATOR_H