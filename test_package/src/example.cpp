#include "oal.h"
#include <vector>
#include <string>

int main() {
    oal();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    oal_print_vector(vec);
}
