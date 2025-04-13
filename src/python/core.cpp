#include "python/python.hpp"
#include "oal/core.hpp"

PYBIND11_MODULE(oal, m) {
  m.doc() = "Open Aerospace Library. Unopinionated, open source, and correct utilities for aerospace applications.";
  m.def("hello", &oal::hello, "Test function");

  python::register_units(m);
}
