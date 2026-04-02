cmake_minimum_required(VERSION 3.16)

project(BacktestEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# This is what will determine the compiler flags for Windows vs Unix
if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(backtest_core
	src/data/DataFetcher.cpp
)

target_include_directories(backtest_core PUBLIC
	${CMAKE_SOURCE_DIR}/include
)

# In charge of the creation of the executable
add_executable(BacktestEngine
	app/main.cpp
)

target_link_libraries(BacktestEngine PRIVATE
	backtest_core
)
