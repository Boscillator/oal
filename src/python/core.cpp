#include "oal/core.hpp"

#include "python/python.hpp"

PYBIND11_MODULE(oal, module) {
  module.doc() =
      "Open Aerospace Library. Unopinionated, open source, and correct "
      "utilities for aerospace applications.";

  oal::python::register_units(module);
  oal::python::register_coords(module);
}
