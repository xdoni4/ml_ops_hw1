#include "cholesky.h"

#include <iostream>
#include <vector>
#include <cmath>

namespace py = pybind11;

std::vector<std::vector<double>> choleskyDecomposition(const std::vector<std::vector<double>>& A) {
    size_t n = A.size();
    std::vector<std::vector<double>> L(n, std::vector<double>(n, 0.0));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j <= i; ++j) {
            double sum = 0.0;
            for (size_t k = 0; k < j; ++k) {
                sum += L[i][k] * L[j][k];
            }

            if (i == j) {
                L[i][j] = std::sqrt(A[i][i] - sum);
            } else {
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }

    return L;
}

py::array_t<double> cholesky_numpy(py::array_t<double> input) {
    auto buf = input.request();
    size_t n = buf.shape[0];

    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    double* ptr = static_cast<double*>(buf.ptr);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            A[i][j] = ptr[i * n + j];
        }
    }

    auto L = choleskyDecomposition(A);

    py::array_t<double> result({n, n});
    auto res_buf = result.request();
    double* res_ptr = static_cast<double*>(res_buf.ptr);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            res_ptr[i * n + j] = L[i][j];
        }
    }
    return result;
}