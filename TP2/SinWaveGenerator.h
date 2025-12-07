#ifndef TP2_SINWAVEGENERATOR_H
#define TP2_SINWAVEGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;
    double frequency;
    double phase;

public:
    SinWaveGenerator(double amplitude, double frequency, double phase, int seed = 0);
    SinWaveGenerator();
    std::vector<double> generateTimeSeries(int count) override;
};


#endif //TP2_SINWAVEGENERATOR_H