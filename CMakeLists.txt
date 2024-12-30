cmake_minimum_required(VERSION 3.16)

project(TowerDefense)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

set(SDL_INCLUDE_DIR "/usr/local/include/SDL3")
set(SDL_LIB_DIR "/user/local/lib/")

include_directories(src)

set(SRC
    src/main.cpp

    src/core/app.cpp

    src/core/grid.cpp
    src/core/tile.cpp
)

add_executable(${PROJECT_NAME} ${SRC})

# Link SDL3
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL_INCLUDE_DIR})

target_link_directories(${PROJECT_NAME} PRIVATE ${SDL_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3 SDL3_image)

# copy asset folder into build
set(ASSET_DIR ${CMAKE_SOURCE_DIR}/assets)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ASSET_DIR} ${CMAKE_BINARY_DIR}/assets
)