#include "eigenpredictor.h"
#include <Eigen/Dense>
#include <Eigen/IterativeLinearSolvers>
#include <iostream>
#include <vector>
#include <random>
#include <numeric>

void run_predictor() {
    size_t n = 108;
    float holdB = 4.0f;
    float holdX = 0.3f;

    // Generate simple training data
    std::vector<float> x_data(n), y_data(n);
    std::iota(x_data.begin(), x_data.end(), 0);
    std::iota(y_data.begin(), y_data.end(), 0);

    std::random_device rd;
    std::mt19937 re(rd());
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
    for(auto &x: x_data) x += dist(re);
    for(auto &y: y_data) y += dist(re);

    Eigen::Map<Eigen::MatrixXf> x_mat(x_data.data(), n, 1);
    Eigen::Map<Eigen::MatrixXf> y_mat(y_data.data(), n, 1);

    Eigen::MatrixXf x(n,6);
    Eigen::MatrixXf x01 = Eigen::MatrixXf::Ones(n,1);
    Eigen::MatrixXf x02 = Eigen::MatrixXf::Ones(n,1);
    Eigen::MatrixXf x03 = Eigen::MatrixXf::Ones(n,1);
    Eigen::MatrixXf x04 = Eigen::MatrixXf::Ones(n,1);
    Eigen::MatrixXf x05 = Eigen::MatrixXf::Ones(n,1);
    Eigen::MatrixXf x06 = Eigen::MatrixXf::Ones(n,1);
    x << x01, x02, x03, x04, x05, x06;

    Eigen::MatrixXf y = y_mat;
    y.array() *= holdX;
    y.array() += holdB;

    // Train least-squares
    Eigen::LeastSquaresConjugateGradient<Eigen::MatrixXf> gd;
    gd.setMaxIterations(1000);
    gd.setTolerance(0.001f);
    gd.compute(x);
    Eigen::VectorXf b = gd.solve(y);

    std::cout << "Estimated parameters vector: " << b.transpose() << std::endl;
}
