add_executable (codeforcesCPP main.cpp)

add_custom_target(run_cpp DEPENDS codeforcesCPP
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/codeforcesCPP
)
