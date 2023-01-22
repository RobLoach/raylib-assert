cmake_minimum_required(VERSION 3.11)
project(raylib_assert
    DESCRIPTION "raylib-assert: Assertion library for raylib."
    HOMEPAGE_URL "https://github.com/robloach/raylib-assert"
    VERSION 1.1.1
    LANGUAGES C
)

# Options
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(RAYLIB_ASSERT_IS_MAIN TRUE)
else()
    set(RAYLIB_ASSERT_IS_MAIN FALSE)
endif()
option(BUILD_RAYLIB_ASSERT_TEST "Test" ${RAYLIB_ASSERT_IS_MAIN})

# raylib_assert
add_library(raylib_assert INTERFACE)
#target_precompile_headers(raylib_assert INTERFACE raylib-assert.h) # Requires CMake 3.16
target_include_directories(raylib_assert INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/)
install(FILES raylib-assert.h DESTINATION include)

# Testing
if (BUILD_RAYLIB_ASSERT_TEST)
    include(CTest)
    enable_testing()
    if (BUILD_TESTING)
        # Always print verbose output when tests fail if run using `make test`.
        list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")

        add_subdirectory(test)
    endif()
endif()
