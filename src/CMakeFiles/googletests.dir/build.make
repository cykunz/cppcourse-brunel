# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/localguest/Documents/Neuron/NeuronProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/localguest/Documents/Neuron/NeuronProject/src

# Include any dependencies generated for this target.
include CMakeFiles/googletests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/googletests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/googletests.dir/flags.make

CMakeFiles/googletests.dir/Neuron.cpp.o: CMakeFiles/googletests.dir/flags.make
CMakeFiles/googletests.dir/Neuron.cpp.o: Neuron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/googletests.dir/Neuron.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/googletests.dir/Neuron.cpp.o -c /home/localguest/Documents/Neuron/NeuronProject/src/Neuron.cpp

CMakeFiles/googletests.dir/Neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/googletests.dir/Neuron.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/localguest/Documents/Neuron/NeuronProject/src/Neuron.cpp > CMakeFiles/googletests.dir/Neuron.cpp.i

CMakeFiles/googletests.dir/Neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/googletests.dir/Neuron.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/localguest/Documents/Neuron/NeuronProject/src/Neuron.cpp -o CMakeFiles/googletests.dir/Neuron.cpp.s

CMakeFiles/googletests.dir/Neuron.cpp.o.requires:
.PHONY : CMakeFiles/googletests.dir/Neuron.cpp.o.requires

CMakeFiles/googletests.dir/Neuron.cpp.o.provides: CMakeFiles/googletests.dir/Neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/googletests.dir/build.make CMakeFiles/googletests.dir/Neuron.cpp.o.provides.build
.PHONY : CMakeFiles/googletests.dir/Neuron.cpp.o.provides

CMakeFiles/googletests.dir/Neuron.cpp.o.provides.build: CMakeFiles/googletests.dir/Neuron.cpp.o

CMakeFiles/googletests.dir/Network.cpp.o: CMakeFiles/googletests.dir/flags.make
CMakeFiles/googletests.dir/Network.cpp.o: Network.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/googletests.dir/Network.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/googletests.dir/Network.cpp.o -c /home/localguest/Documents/Neuron/NeuronProject/src/Network.cpp

CMakeFiles/googletests.dir/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/googletests.dir/Network.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/localguest/Documents/Neuron/NeuronProject/src/Network.cpp > CMakeFiles/googletests.dir/Network.cpp.i

CMakeFiles/googletests.dir/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/googletests.dir/Network.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/localguest/Documents/Neuron/NeuronProject/src/Network.cpp -o CMakeFiles/googletests.dir/Network.cpp.s

CMakeFiles/googletests.dir/Network.cpp.o.requires:
.PHONY : CMakeFiles/googletests.dir/Network.cpp.o.requires

CMakeFiles/googletests.dir/Network.cpp.o.provides: CMakeFiles/googletests.dir/Network.cpp.o.requires
	$(MAKE) -f CMakeFiles/googletests.dir/build.make CMakeFiles/googletests.dir/Network.cpp.o.provides.build
.PHONY : CMakeFiles/googletests.dir/Network.cpp.o.provides

CMakeFiles/googletests.dir/Network.cpp.o.provides.build: CMakeFiles/googletests.dir/Network.cpp.o

CMakeFiles/googletests.dir/googletests.cpp.o: CMakeFiles/googletests.dir/flags.make
CMakeFiles/googletests.dir/googletests.cpp.o: googletests.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/googletests.dir/googletests.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/googletests.dir/googletests.cpp.o -c /home/localguest/Documents/Neuron/NeuronProject/src/googletests.cpp

CMakeFiles/googletests.dir/googletests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/googletests.dir/googletests.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/localguest/Documents/Neuron/NeuronProject/src/googletests.cpp > CMakeFiles/googletests.dir/googletests.cpp.i

CMakeFiles/googletests.dir/googletests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/googletests.dir/googletests.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/localguest/Documents/Neuron/NeuronProject/src/googletests.cpp -o CMakeFiles/googletests.dir/googletests.cpp.s

CMakeFiles/googletests.dir/googletests.cpp.o.requires:
.PHONY : CMakeFiles/googletests.dir/googletests.cpp.o.requires

CMakeFiles/googletests.dir/googletests.cpp.o.provides: CMakeFiles/googletests.dir/googletests.cpp.o.requires
	$(MAKE) -f CMakeFiles/googletests.dir/build.make CMakeFiles/googletests.dir/googletests.cpp.o.provides.build
.PHONY : CMakeFiles/googletests.dir/googletests.cpp.o.provides

CMakeFiles/googletests.dir/googletests.cpp.o.provides.build: CMakeFiles/googletests.dir/googletests.cpp.o

# Object files for target googletests
googletests_OBJECTS = \
"CMakeFiles/googletests.dir/Neuron.cpp.o" \
"CMakeFiles/googletests.dir/Network.cpp.o" \
"CMakeFiles/googletests.dir/googletests.cpp.o"

# External object files for target googletests
googletests_EXTERNAL_OBJECTS =

googletests: CMakeFiles/googletests.dir/Neuron.cpp.o
googletests: CMakeFiles/googletests.dir/Network.cpp.o
googletests: CMakeFiles/googletests.dir/googletests.cpp.o
googletests: CMakeFiles/googletests.dir/build.make
googletests: gtest/googlemock/gtest/libgtest.a
googletests: gtest/googlemock/gtest/libgtest_main.a
googletests: gtest/googlemock/gtest/libgtest.a
googletests: CMakeFiles/googletests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable googletests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/googletests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/googletests.dir/build: googletests
.PHONY : CMakeFiles/googletests.dir/build

CMakeFiles/googletests.dir/requires: CMakeFiles/googletests.dir/Neuron.cpp.o.requires
CMakeFiles/googletests.dir/requires: CMakeFiles/googletests.dir/Network.cpp.o.requires
CMakeFiles/googletests.dir/requires: CMakeFiles/googletests.dir/googletests.cpp.o.requires
.PHONY : CMakeFiles/googletests.dir/requires

CMakeFiles/googletests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/googletests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/googletests.dir/clean

CMakeFiles/googletests.dir/depend:
	cd /home/localguest/Documents/Neuron/NeuronProject/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/localguest/Documents/Neuron/NeuronProject /home/localguest/Documents/Neuron/NeuronProject /home/localguest/Documents/Neuron/NeuronProject/src /home/localguest/Documents/Neuron/NeuronProject/src /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles/googletests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/googletests.dir/depend
