# This file taken from the SeQuant project. See https://github.com/ValeevGroup/SeQuant

if (NOT TARGET tiledarray)
    find_package(TiledArray CONFIG COMPONENTS tiledarray)
    if (TiledArray_INSTALL_DIR)
        set(TiledArray_DIR ${TiledArray_INSTALL_DIR}/lib/cmake/tiledarray)
    endif ()
    find_package(TiledArray CONFIG QUIET COMPONENTS tiledarray)
endif (NOT TARGET tiledarray)

set(TA_PYTHON OFF) # disable python bindings, don't need them

if (TARGET tiledarray)
    message(STATUS "Found TiledArray CONFIG at ${TiledArray_CONFIG}")
else (TARGET tiledarray)

    set(ENABLE_DQ_PREBUF OFF CACHE BOOL "Whether to enable prebuffering in madness::DQueue")

    include(FetchContent)
    FetchContent_Declare(
            TILEDARRAY
            GIT_REPOSITORY https://github.com/ValeevGroup/tiledarray.git
            GIT_TAG v1.1.0
    )
    FetchContent_MakeAvailable(TILEDARRAY)
    FetchContent_GetProperties(TILEDARRAY
            SOURCE_DIR TILEDARRAY_SOURCE_DIR
            BINARY_DIR TILEDARRAY_BINARY_DIR
    )
    # TA includes dependencies that are built manually, not using FetchContent, hence make sure build them before the project
    add_dependencies(tiledarray External-tiledarray)

    # this is where tiledarray-config.cmake will end up
    # must be in sync with the "install(FILES ...tiledarray-config.cmake" statement in https://github.com/ValeevGroup/tiledarray/blob/${MPQC_TRACKED_TILEDARRAY_TAG}/CMakeLists.txt
    set(TiledArray_CONFIG "${CMAKE_INSTALL_PREFIX}/${TILEDARRAY_INSTALL_CMAKEDIR}" CACHE INTERNAL "The location of installed tiledarray-config.cmake file")
endif (TARGET tiledarray)
