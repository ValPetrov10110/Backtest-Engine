cmake_minimum_required(VERSION 3.16)

project(BacktestEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# Taking care of the libraries
FetchContent_Declare(
	cpp_httplib
	GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
	GIT_TAG master
)

FetchContent_Declare(
	json
	GIT_REPOSITORY https://github.com/nlohmann/json.git
	GIT_TAG master
)

FetchContent_MakeAvailable(cpp_httplib json)
find_package(OpenSSL REQUIRED)

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

target_link_libraries(backtest_core PUBLIC
	httplib::httplib
	OpenSSL::SSL
	OpenSSL::Crypto
	nlohmann_json::nlohmann_json
)

# Removes the need to have #define CPPHTTPLIB_OPENSSL_SUPPORT in the source file
target_compile_definitions(backtest_core PUBLIC
	CPPHTTPLIB_OPENSSL_SUPPORT
)

# In charge of the creation of the executable
add_executable(BacktestEngine
	app/main.cpp
)

target_link_libraries(BacktestEngine PRIVATE
	backtest_core
)
