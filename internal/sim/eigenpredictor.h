// #ifndef EIGENPREDICTOR_H
// #define EIGENPREDICTOR_H

// #ifdef __cplusplus
// extern "C" {
// #endif

// // Runs the C++ predictor
// void run_predictor();

// #ifdef __cplusplus
// }
// #endif

// #endif
//=======================================================
#ifndef EIGENPREDICTOR_H
#define EIGENPREDICTOR_H

#ifdef __cplusplus
#include <Eigen/Dense>
#include <string>

// ------------------------------------------------------------
// Define struct for predictor input
// ------------------------------------------------------------
struct PredictorInput {
    Eigen::MatrixXf matrix;
    float myDate;
    std::string dateLabel;
};

// Returns a hardcoded test input (can be extended later)
PredictorInput getPredictorInput();

extern "C" {
#endif

// Main predictor entry point callable from Go
void run_predictor();

#ifdef __cplusplus
}
#endif

#endif // EIGENPREDICTOR_H
