#include "oal/core.hpp"

#include "python/python.hpp"

PYBIND11_MODULE(oal, m) {
  m.doc() =
      "Open Aerospace Library. Unopinionated, open source, and correct "
      "utilities for aerospace applications.";
  m.def("hello", &oal::hello, "Test function");

  oal::python::register_units(m);
}
