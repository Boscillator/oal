#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define OAL_EXPORT __declspec(dllexport)
#else
  #define OAL_EXPORT
#endif

OAL_EXPORT void oal();
OAL_EXPORT void oal_print_vector(const std::vector<std::string> &strings);
