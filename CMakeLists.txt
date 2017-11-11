cmake_minimum_required (VERSION 2.6)
project (Network)

set(CMAKE_CXX_FLAGS " -W -Wall -pedantic -std=c++11 -O2")

add_executable(OneNeuron ../src/Neuron.cpp ../src/Network.cpp ../src/oneneurontest.cpp)
add_executable(Buffer ../src/Neuron.cpp ../src/Network.cpp ../src/buffertest.cpp)
add_executable (AllNeurons ../src/Neuron.cpp ../src/Network.cpp ../src/test_allneurons.cpp)
add_executable(googletests ../src/Neuron.cpp ../src/Network.cpp ../src/googletests.cpp)



enable_testing()
add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(googletests gtest gtest_main)
add_test(googletests googletests)


# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files

	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/src/doxygen/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

