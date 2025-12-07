#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <vector>

namespace py = pybind11;

std::vector<std::vector<double>> choleskyDecomposition(
    const std::vector<std::vector<double>>& A
);

py::array_t<double> cholesky_numpy(
    py::array_t<double> input
);