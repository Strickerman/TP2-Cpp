#include "StepGenerator.h"
#include <random>

using namespace std;

StepGenerator::StepGenerator(int s)
    : TimeSeriesGenerator(s)
{
}

std::vector<double> StepGenerator::generateTimeSeries(int count) {
    if (count <= 0) {
        return {};
    }

    std::vector<double> timeSeries;
    timeSeries.reserve(count);
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> choiceDistribution(0, 1);
    std::uniform_int_distribution<int> valueDistribution(0, 100);
    double currentValue = 0.0;
    timeSeries.push_back(currentValue);
    for (int i = 1; i < count; ++i) {
        if (choiceDistribution(generator) == 1) {
            currentValue = static_cast<double>(valueDistribution(generator));
        }
        else {
        }

        timeSeries.push_back(currentValue);
    }

    return timeSeries;
}