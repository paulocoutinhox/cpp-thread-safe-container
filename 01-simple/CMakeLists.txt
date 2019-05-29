set(PROJECT_NAME 01-simple)

project(${PROJECT_NAME} CXX)

include_directories(include)
file(GLOB CPP_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${CPP_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED true
    CXX_EXTENSIONS false
    CXX_VISIBILITY_PRESET default
)