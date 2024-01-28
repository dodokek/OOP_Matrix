cmake_minimum_required(VERSION 3.15)

project(matrix)
aux_source_directory(./src SRC_FILES)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

