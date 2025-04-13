#include <pybind11/pybind11.h>

#include "oal/core.hpp"

namespace py = pybind11;

PYBIND11_MODULE(oal, m) {
  m.doc() = "Open Aerospace Library. Unopinionated, open source, and correct utilities for aerospace applications.";
  m.def("hello", &oal::hello, "Test function");
}
