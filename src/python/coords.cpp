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

  py::enum_<coords::RotationSequence>(coords, "RotationSequence")
      .value("INTRINSIC_ZYX", coords::RotationSequence::INTRINSIC_ZYX)
      .value("INTRINSIC_XZY", coords::RotationSequence::INTRINSIC_XZY)
      .value("INTRINSIC_YXZ", coords::RotationSequence::INTRINSIC_YXZ)
      .value("INTRINSIC_YZX", coords::RotationSequence::INTRINSIC_YZX)
      .value("INTRINSIC_XYZ", coords::RotationSequence::INTRINSIC_XYZ)
      .value("INTRINSIC_ZXY", coords::RotationSequence::INTRINSIC_ZXY)
      .value("PROPER_XZX", coords::RotationSequence::PROPER_XZX)
      .value("PROPER_XYX", coords::RotationSequence::PROPER_XYX)
      .value("PROPER_YXY", coords::RotationSequence::PROPER_YXY)
      .value("PROPER_YZY", coords::RotationSequence::PROPER_YZY)
      .value("PROPER_ZYZ", coords::RotationSequence::PROPER_ZYZ)
      .value("PROPER_ZXZ", coords::RotationSequence::PROPER_ZXZ)
      .value("EXTRINSIC_ZYX", coords::RotationSequence::EXTRINSIC_ZYX)
      .value("EXTRINSIC_XZY", coords::RotationSequence::EXTRINSIC_XZY)
      .value("EXTRINSIC_YXZ", coords::RotationSequence::EXTRINSIC_YXZ)
      .value("EXTRINSIC_YZX", coords::RotationSequence::EXTRINSIC_YZX)
      .value("EXTRINSIC_XYZ", coords::RotationSequence::EXTRINSIC_XYZ)
      .value("EXTRINSIC_ZXY", coords::RotationSequence::EXTRINSIC_ZXY);

  Mat3 (*dcm_from_eulers)(const Vec3Ref, const units::AngleUnit, const coords::RotationSequence) = &coords::dcm_from_eulers;
  coords.def("dcm_from_eulers", dcm_from_eulers, "Compute a DCM from euler angles", py::arg("eulers"), py::arg("units") = units::RADIANS, py::arg("sequence") = coords::RotationSequence::INTRINSIC_ZYX);

  Mat3 (*dcm_from_eulers_2)(const double, const double, const double, const units::AngleUnit) = &coords::dcm_from_eulers;
  coords.def("dcm_from_eulers", dcm_from_eulers_2, "Compute a DCM from euler angles", py::arg("yaw"), py::arg("pitch"), py::arg("roll"), py::arg("units") = units::RADIANS);
}
}  // namespace python
}  // namespace oal
