# Set the C and C++ compilers to GCC and G++ from MSYS2
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe")

# CMake Minimum Version Requirement
cmake_minimum_required(VERSION 3.10)

# Project Name
project(bdOS)

# Enable all warnings for better code quality
set(CMAKE_C_FLAGS "-Wall -Wextra -g")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")

# Define the build type (default to Debug for development)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Add subdirectories for all modules
add_subdirectory(core)
add_subdirectory(aispecs)
add_subdirectory(aiiot)
add_subdirectory(clntsrvrcomm)
add_subdirectory(clouddsi)
add_subdirectory(contnrz)
add_subdirectory(iotspecs)
add_subdirectory(netcon)
add_subdirectory(secpriv)
add_subdirectory(serverspecs)
add_subdirectory(clientspecs)
add_subdirectory(tests)

# Add the main executable for the OS
add_executable(bdOS main.c)

# Link all the modules and libraries to the main executable
target_link_libraries(bdOS 
    core 
    aispecs 
    aiiot 
    clntsrvrcomm 
    clouddsi 
    contnrz 
    iotspecs 
    netcon 
    secpriv 
    serverspecs 
    clientspecs
)

# Optionally, include any external libraries
# target_link_libraries(bdOS <your_external_libraries>)

# Add include directories if needed (if modules use headers from other directories)
target_include_directories(bdOS PRIVATE 
    ${CMAKE_SOURCE_DIR}/core
    ${CMAKE_SOURCE_DIR}/aispecs
    ${CMAKE_SOURCE_DIR}/aiiot
    ${CMAKE_SOURCE_DIR}/clntsrvrcomm
    ${CMAKE_SOURCE_DIR}/clouddsi
    ${CMAKE_SOURCE_DIR}/contnrz
    ${CMAKE_SOURCE_DIR}/iotspecs
    ${CMAKE_SOURCE_DIR}/netcon
    ${CMAKE_SOURCE_DIR}/secpriv
    ${CMAKE_SOURCE_DIR}/serverspecs
    ${CMAKE_SOURCE_DIR}/clientspecs
)

# Enable testing if you have test modules
enable_testing()

# Optional: If using CMocka or another testing library
# find_package(CMocka REQUIRED)

# Add tests (example, adjust based on your test files)
# add_executable(test_kernel test_kernel.c)
# target_link_libraries(test_kernel core aispecs)
# add_test(NAME KernelTest COMMAND test_kernel)

# Optionally, add more tests here for other components
# add_executable(test_aiiot test_aiiot.c)
# target_link_libraries(test_aiiot aiiot)
# add_test(NAME IOTTest COMMAND test_aiiot)

# Add more complex build commands if necessary for tools or scripts
# add_custom_target(scripts COMMAND python3 ${CMAKE_SOURCE_DIR}/scripts/myscript.py)

# Optionally, set specific compiler flags or optimization options if needed
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
