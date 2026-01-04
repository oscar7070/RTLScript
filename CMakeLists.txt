file(GLOB_RECURSE RTL_SCRIPT_FILES
    *.cpp
    *.hpp
    *.cxx
    *.mm // Objective C++
    *.m  // Objective C
)

# Add source to this project's executable.
add_library(RTLScript STATIC ${RTL_SCRIPT_FILES})
target_compile_definitions(RTLScript PRIVATE RTL_SCRIPT_EXPORTS)

# Make headers visible to consumers
target_include_directories(RTLScript PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# TODO: Add tests and install targets if needed.