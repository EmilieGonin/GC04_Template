cmake_minimum_required(VERSION 3.28)
project(GC04_Template LANGUAGES CXX)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DENABLE_DEBUG_MACRO")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0-rc.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME})
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "src/*.h")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES} "src/Component/Behaviour/PaddleBehaviour.cpp")

set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/resources)
if (NOT EXISTS ${RESOURCE_DIR})
    file(MAKE_DIRECTORY ${RESOURCE_DIR})
endif()

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${RESOURCE_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)

# Multi-processor compilation
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /MP)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
