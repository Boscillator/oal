#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace oal {
namespace python {

void register_units(py::module_& oal);
void register_coords(py::module_& oal);

}
}  // namespace oal
