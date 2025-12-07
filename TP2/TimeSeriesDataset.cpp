#include "TimeSeriesDataset.h"
#include <numeric>
#include <cmath>
#include <algorithm>
#include <iostream>

TimeSeriesDataset::TimeSeriesDataset(bool _zNormalize, bool _isTraining)
    : znormalize(_zNormalize),
      isTrain(_isTraining),
      maxLength(0),
      numberOfSamples(0)
{}

std::vector<double> TimeSeriesDataset::zNormalizeSeries(const std::vector<double>& series) const {
    if (series.empty()) return series;

    // 1. Calcul de la moyenne (mu)
    double sum = std::accumulate(series.begin(), series.end(), 0.0);
    double mean = sum / series.size();

    // 2. Calcul de l'écart-type (sigma)
    double sq_sum = 0.0;
    for (double val : series) {
        sq_sum += (val - mean) * (val - mean);
    }
    double stdDev = std::sqrt(sq_sum / series.size());
    if (stdDev == 0) return std::vector<double>(series.size(), 0.0);

    // 3. Application de la normalisation
    std::vector<double> normalizedSeries;
    normalizedSeries.reserve(series.size());
    for (double val : series) {
        normalizedSeries.push_back((val - mean) / stdDev);
    }
    return normalizedSeries;
}

// Méthode pour ajouter une série et gérer la logique de normalisation
void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    std::vector<double> seriesToAdd = series;
    if (znormalize) {
        seriesToAdd = zNormalizeSeries(series);
    }

    // Mise à jour des données
    if (seriesToAdd.size() > maxLength) {
        maxLength = seriesToAdd.size();
    }

    data.push_back(seriesToAdd);
    labels.push_back(label);
    numberOfSamples++;
}

double TimeSeriesDataset::euclidean_distance(const std::vector<double> &series1, const std::vector<double> &series2) const {
    size_t len = std::min(series1.size(), series2.size());
    double sumSq = 0.0;
    for (size_t i = 0; i < len; ++i) {
        double diff = series1[i] - series2[i];
        sumSq += diff * diff;
    }
    return std::sqrt(sumSq);
}

double TimeSeriesDataset::DTW(const std::vector<double> &series1, const std::vector<double> &series2) const {
    size_t n = series1.size();
    size_t m = series2.size();
    // Initialisation de la matrice avec l'infini
    std::vector<std::vector<double>> dtw(n + 1, std::vector<double>(m + 1, std::numeric_limits<double>::infinity()));

    dtw[0][0] = 0.0;

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            // Coût local : carré de la différence
            double diff = series1[i-1] - series2[j-1];
            double cost = diff * diff;

            // Formule de récurrence : coût + min(insertion, suppression, déplacement)
            dtw[i][j] = cost + std::min({dtw[i-1][j],    // Insertion
                                         dtw[i][j-1],    // Suppression
                                         dtw[i-1][j-1]}); // Déplacement
        }
    }
    return std::sqrt(dtw[n][m]);
}