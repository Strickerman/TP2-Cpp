#include "TimeSeriesGenerator.h"
#include <iostream>
#include <random>

using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator() : seed(std::random_device{}()) {
}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed) : seed(_seed) {
}

void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& series) {
    cout << "Time Series (Count: " << series.size() << "):" << endl;
    for (size_t i = 0; i < series.size(); ++i) {
        cout << series[i] << (i < series.size() - 1 ? ", " : "");
    }
    cout << endl;
}