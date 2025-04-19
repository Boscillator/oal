#include <pybind11/numpy.h>
#include <pybind11/eigen.h>

#include "python/python.hpp"
#include "oal/core.hpp"
#include "oal/coords.hpp"

namespace oal {
namespace python {

void register_coords(py::module_& oal) {

  auto coords = oal.def_submodule("coords", "Coordinate transformation library");

  Mat3 (*rotate_x)(double, units::AngleUnit) = &coords::rotate_x;
  coords.def("rotate_x", rotate_x, "Compute a DCM rotation about the x-axis", py::arg("angle"), py::arg("units") = units::RADIANS);

  Mat3 (*rotate_y)(double, units::AngleUnit) = &coords::rotate_y;
  coords.def("rotate_y", rotate_y, "Compute a DCM rotation about the y-axis", py::arg("angle"), py::arg("units") = units::RADIANS);

  Mat3 (*rotate_z)(double, units::AngleUnit) = &coords::rotate_z;
  coords.def("rotate_z", rotate_z, "Compute a DCM rotation about the z-axis", py::arg("angle"), py::arg("units") = units::RADIANS);
}
}  // namespace python
}  // namespace oal
