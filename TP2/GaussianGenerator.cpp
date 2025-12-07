#include "GaussianGenerator.h"
#include <cmath> // Pas de point virgule ici !
#include <cstdlib> // Pour rand() et RAND_MAX

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

GaussianGenerator::GaussianGenerator(double _mean, double _stdDev, int _seed):
    TimeSeriesGenerator(_seed), mean(_mean), stdDev(_stdDev) {
    if (_seed != 0) std::srand(_seed);
}

GaussianGenerator::GaussianGenerator():
    TimeSeriesGenerator(), mean(0), stdDev(1) {}

double GaussianGenerator::boxMuller() {
    double u1 = ((double)std::rand() + 1.0) / ((double)RAND_MAX + 2.0);
    double u2 = ((double)std::rand() + 1.0) / ((double)RAND_MAX + 2.0);
    double z = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
    return mean + z * stdDev;
}

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> out;
    out.reserve(size);
    for (int i = 0; i < size; i++) {
        out.push_back(boxMuller());
    }
    return out;
}