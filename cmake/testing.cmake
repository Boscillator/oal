find_package(Catch2 3 REQUIRED)
include(CTest)
include(Catch)

enable_testing()

function(oal_add_test)
  set(one_value_args NAME)
  set(multi_value_args SOURCE_FILES)
  cmake_parse_arguments(test_args "" "${one_value_args}" "${multi_value_args}" ${ARGN})

  add_executable("test_${test_args_NAME}" "${test_args_SOURCE_FILES}")
  target_link_libraries("test_${test_args_NAME}" PRIVATE oal Catch2::Catch2WithMain)
  catch_discover_tests("test_${test_args_NAME}")
endfunction()
