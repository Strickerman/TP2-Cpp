#include "KNN.h"
#include <algorithm> // Pour sort, max_element, count
#include <stdexcept> // Pour les exceptions
#include <cmath>
#include <iostream>

using namespace std;

KNN::KNN(int neighborsn, string sim_measure)
    : k(neighborsn), similarity_measure(sim_measure) 
{}

double KNN::evaluate(const TimeSeriesDataset& trainSet,
                     const TimeSeriesDataset& testSet, 
                     const vector<int>& groundTruth) {
    
    int correct = 0;
    
    // Récupération des données brutes via les getters
    const auto& trainData = trainSet.getData();
    const auto& trainLabels = trainSet.getLabels();
    const auto& testData = testSet.getData();

    // Boucle sur chaque échantillon de test (i)
    for (size_t i = 0; i < testData.size(); i++) {
        
        // Stocke les paires {distance, label_du_train}
        vector<pair<double, int>> distances;
        
        // On compare l'échantillon de test (i) avec TOUS les échantillons d'entraînement (j)
        for (size_t j = 0; j < trainData.size(); j++) {
            double dist = 0.0;

            // Choix de la mesure
            if (similarity_measure == "euclidean_distance") {
                dist = trainSet.euclidean_distance(testData[i], trainData[j]);
            } else if (similarity_measure == "dtw") {
                dist = trainSet.DTW(testData[i], trainData[j]);
            } else {
                throw invalid_argument("Mesure de similarité inconnue (utiliser 'euclidean_distance' ou 'dtw')");
            }

            distances.push_back({ dist, trainLabels[j] });
        }

        // 1. Trier les distances de la plus petite à la plus grande
        sort(distances.begin(), distances.end());

        // 2. Récupérer les labels des K plus proches voisins
        vector<int> k_nearest_labels;
        for (int n = 0; n < k && n < distances.size(); n++) {
            k_nearest_labels.push_back(distances[n].second);
        }

        // 3. Vote majoritaire (Trouver le label le plus fréquent)
        int predictedLabel = *max_element(k_nearest_labels.begin(), k_nearest_labels.end(),
            [&k_nearest_labels](int a, int b) {
                // On compare le nombre d'occurrences de 'a' et 'b'
                return count(k_nearest_labels.begin(), k_nearest_labels.end(), a) <
                       count(k_nearest_labels.begin(), k_nearest_labels.end(), b);
            });

        // 4. Vérification
        if (predictedLabel == groundTruth[i]) {
            correct++;
        }
    }

    // Retourne la précision (Accuracy) : nb_correct / nb_total
    return static_cast<double>(correct) / testData.size();
}