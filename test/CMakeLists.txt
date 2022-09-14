# Executable
add_executable(raylib_assert_test raylib_assert_test.c)

# Options
if (MSVC)
    target_compile_options(raylib_assert_test PRIVATE /Wall /W4)
else()
    target_compile_options(raylib_assert_test PRIVATE -Wall -Wextra -Wconversion -Wsign-conversion)
endif()

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
        FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.2.0
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# Link to raylib_assert
target_link_libraries(raylib_assert_test raylib raylib_assert)

# Build the test
add_test(NAME raylib_assert_test COMMAND raylib_assert_test)
