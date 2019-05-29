set(PROJECT_NAME 03-std)

project(${PROJECT_NAME} CXX)

include_directories(include)
file(GLOB CPP_FILES src/*.cpp)

add_executable(${PROJECT_NAME} ${CPP_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED true
    CXX_EXTENSIONS false
)