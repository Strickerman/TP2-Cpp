#ifndef TP2_TIMESERIESGENERATOR_H
#define TP2_TIMESERIESGENERATOR_H

#include <vector>

class TimeSeriesGenerator {
protected:
    int seed{};
public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);
    virtual ~TimeSeriesGenerator() = default;
    virtual std::vector<double> generateTimeSeries(int) = 0;
    static void printTimeSeries(const std::vector<double>& series);
};

#endif //TP2_TIMESERIESGENERATOR_H