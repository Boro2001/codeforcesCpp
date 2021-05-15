add_executable (codeforcesCPP a.cpp)

add_custom_target(run_template DEPENDS codeforcesCPP
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/codeforcesCPP
)
