set(PROJECT_NAME 02-fluentcpp)

project(${PROJECT_NAME} CXX)

include_directories(include)
file(GLOB CPP_FILES src/*.cpp include/safe/*.h)

add_executable(${PROJECT_NAME} ${CPP_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED true
    CXX_EXTENSIONS false
)