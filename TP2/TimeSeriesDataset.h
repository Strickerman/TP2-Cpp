#ifndef TP2_TIMESERIESDATASET_H
#define TP2_TIMESERIESDATASET_H

#include <vector>
#include <cmath>
#include <limits>

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;
    int maxLength;
    int numberOfSamples;
    std::vector<std::vector<double>> data;
    std::vector<int> labels;
    std::vector<double> zNormalizeSeries(const std::vector<double>& series) const;

public:
    TimeSeriesDataset(bool zNormalize, bool isTraining);

    // Méthode nécessaire pour ajouter des données et déclencher la normalisation
    void addTimeSeries(const std::vector<double>& series, int label = -1);

    // Méthodes de calcul de distance
    double euclidean_distance(const std::vector<double>& series1, const std::vector<double>& series2) const;
    double DTW(const std::vector<double>& series1, const std::vector<double>& series2) const;

    // Getters pour tester
    int getNumberOfSamples() const { return numberOfSamples; }
    const std::vector<std::vector<double>>& getData() const { return data; }
    const std::vector<int>& getLabels() const { return labels; }
};

#endif //TP2_TIMESERIESDATASET_H