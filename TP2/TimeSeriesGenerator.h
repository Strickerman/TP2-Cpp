#ifndef TP2_TIMESERIESGENERATOR_H
#define TP2_TIMESERIESGENERATOR_H

#include <vector>


class TimeSeriesGenerator {
protected:
    int seed{};
public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int seed);
    ~TimeSeriesGenerator()=default;
    virtual std::vector<double> generateTimeSeries(int)=0;
    void printTimeSeries(std::vector<double>) const;
};


#endif //TP2_TIMESERIESGENERATOR_H