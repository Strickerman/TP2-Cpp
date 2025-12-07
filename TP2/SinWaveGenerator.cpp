#include "SinWaveGenerator.h"
#include <cmath>

using namespace std;

SinWaveGenerator::SinWaveGenerator(double A, double w, double phi, int s)
    : TimeSeriesGenerator(s),
      amplitude(A),
      frequency(w),
      phase(phi)
{}

SinWaveGenerator::SinWaveGenerator()
    : TimeSeriesGenerator(0),
      amplitude(1.0),
      frequency(1.0),
      phase(0.0)
{}

std::vector<double> SinWaveGenerator::generateTimeSeries(int count) {
    if (count <= 0) {
        return {};
    }
    std::vector<double> timeSeries;
    timeSeries.reserve(count);
    for (int i = 0; i < count; ++i) {
        double x = static_cast<double>(i);
        double value = amplitude * std::sin(frequency * x + phase);
        timeSeries.push_back(value);
    }
    return timeSeries;
}