#include "cholesky.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

PYBIND11_MODULE(cholesky_cpp, m) {
    m.doc() = R"doc(
        Python bindings for Cholesky decomposition.
    )doc";
    m.def("cholesky", &cholesky_numpy, "Compute Cholesky decomposition of a symmetric positive-definite matrix");
}