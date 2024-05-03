cmake_minimum_required(VERSION 3.12)
project(matmulprof)
set(CMAKE_CXX_STANDARD 17)

# Add your source files here
set(SOURCES 
    src/main.cpp
)

# Add your include directories here
set(INCLUDE_DIRS 
    include
)


# Set the output directory for the build artifacts
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})


