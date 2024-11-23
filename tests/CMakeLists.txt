include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0 # Use the latest version available
)
FetchContent_MakeAvailable(Catch2)

set(test_list test_meta.cpp)
add_executable(unit_test ${test_list})
target_link_libraries(unit_test PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
enable_testing()
catch_discover_tests(unit_test)
