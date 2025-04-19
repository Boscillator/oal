#include "oal/units.hpp"

#include <pybind11/numpy.h>

#include "python/python.hpp"

namespace oal {
namespace python {

void register_units(py::module_& oal) {
  auto units = oal.def_submodule("units", "Unit conversion library");

  py::enum_<oal::units::AngleUnit>(units, "AngleUnit")
      .value("RADIANS", oal::units::RADIANS)
      .value("DEGREES", oal::units::DEGREES)
      .export_values();

  double (*to_degrees)(const double, const oal::units::AngleUnit) =
      &oal::units::to_degrees;  // Specify overload resolution
  units.def("to_degrees", py::vectorize(to_degrees),
            "Convert an angle to radians", py::arg("angle"),
            py::arg("units") = units::RADIANS);

  double (*to_radians)(const double, const oal::units::AngleUnit) =
      &oal::units::to_radians;  // Specify overload resolution
  units.def("to_radians", py::vectorize(to_radians),
            "Convert an angle to degrees", py::arg("angle"),
            py::arg("units") = units::DEGREES);
}

}  // namespace python
}  // namespace oal
