cmake_minimum_required(VERSION 4.0)
project(TP2)

set(CMAKE_CXX_STANDARD 20)

add_executable(TP2 main.cpp
        TimeSeriesGenerator.cpp
        TimeSeriesGenerator.h
        GaussianGenerator.cpp
        GaussianGenerator.h
        StepGenerator.cpp
        StepGenerator.h
        SinWaveGenerator.cpp
        SinWaveGenerator.h
        TimeSeriesDataset.cpp
        TimeSeriesDataset.h
        KNN.cpp
        KNN.h)
