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
include CMakeFiles/AllNeurons.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AllNeurons.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AllNeurons.dir/flags.make

CMakeFiles/AllNeurons.dir/Neuron.cpp.o: CMakeFiles/AllNeurons.dir/flags.make
CMakeFiles/AllNeurons.dir/Neuron.cpp.o: Neuron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/AllNeurons.dir/Neuron.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AllNeurons.dir/Neuron.cpp.o -c /home/localguest/Documents/Neuron/NeuronProject/src/Neuron.cpp

CMakeFiles/AllNeurons.dir/Neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AllNeurons.dir/Neuron.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/localguest/Documents/Neuron/NeuronProject/src/Neuron.cpp > CMakeFiles/AllNeurons.dir/Neuron.cpp.i

CMakeFiles/AllNeurons.dir/Neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AllNeurons.dir/Neuron.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/localguest/Documents/Neuron/NeuronProject/src/Neuron.cpp -o CMakeFiles/AllNeurons.dir/Neuron.cpp.s

CMakeFiles/AllNeurons.dir/Neuron.cpp.o.requires:
.PHONY : CMakeFiles/AllNeurons.dir/Neuron.cpp.o.requires

CMakeFiles/AllNeurons.dir/Neuron.cpp.o.provides: CMakeFiles/AllNeurons.dir/Neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/AllNeurons.dir/build.make CMakeFiles/AllNeurons.dir/Neuron.cpp.o.provides.build
.PHONY : CMakeFiles/AllNeurons.dir/Neuron.cpp.o.provides

CMakeFiles/AllNeurons.dir/Neuron.cpp.o.provides.build: CMakeFiles/AllNeurons.dir/Neuron.cpp.o

CMakeFiles/AllNeurons.dir/Network.cpp.o: CMakeFiles/AllNeurons.dir/flags.make
CMakeFiles/AllNeurons.dir/Network.cpp.o: Network.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/AllNeurons.dir/Network.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AllNeurons.dir/Network.cpp.o -c /home/localguest/Documents/Neuron/NeuronProject/src/Network.cpp

CMakeFiles/AllNeurons.dir/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AllNeurons.dir/Network.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/localguest/Documents/Neuron/NeuronProject/src/Network.cpp > CMakeFiles/AllNeurons.dir/Network.cpp.i

CMakeFiles/AllNeurons.dir/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AllNeurons.dir/Network.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/localguest/Documents/Neuron/NeuronProject/src/Network.cpp -o CMakeFiles/AllNeurons.dir/Network.cpp.s

CMakeFiles/AllNeurons.dir/Network.cpp.o.requires:
.PHONY : CMakeFiles/AllNeurons.dir/Network.cpp.o.requires

CMakeFiles/AllNeurons.dir/Network.cpp.o.provides: CMakeFiles/AllNeurons.dir/Network.cpp.o.requires
	$(MAKE) -f CMakeFiles/AllNeurons.dir/build.make CMakeFiles/AllNeurons.dir/Network.cpp.o.provides.build
.PHONY : CMakeFiles/AllNeurons.dir/Network.cpp.o.provides

CMakeFiles/AllNeurons.dir/Network.cpp.o.provides.build: CMakeFiles/AllNeurons.dir/Network.cpp.o

CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o: CMakeFiles/AllNeurons.dir/flags.make
CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o: test_allneurons.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o -c /home/localguest/Documents/Neuron/NeuronProject/src/test_allneurons.cpp

CMakeFiles/AllNeurons.dir/test_allneurons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AllNeurons.dir/test_allneurons.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/localguest/Documents/Neuron/NeuronProject/src/test_allneurons.cpp > CMakeFiles/AllNeurons.dir/test_allneurons.cpp.i

CMakeFiles/AllNeurons.dir/test_allneurons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AllNeurons.dir/test_allneurons.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/localguest/Documents/Neuron/NeuronProject/src/test_allneurons.cpp -o CMakeFiles/AllNeurons.dir/test_allneurons.cpp.s

CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o.requires:
.PHONY : CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o.requires

CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o.provides: CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o.requires
	$(MAKE) -f CMakeFiles/AllNeurons.dir/build.make CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o.provides.build
.PHONY : CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o.provides

CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o.provides.build: CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o

# Object files for target AllNeurons
AllNeurons_OBJECTS = \
"CMakeFiles/AllNeurons.dir/Neuron.cpp.o" \
"CMakeFiles/AllNeurons.dir/Network.cpp.o" \
"CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o"

# External object files for target AllNeurons
AllNeurons_EXTERNAL_OBJECTS =

AllNeurons: CMakeFiles/AllNeurons.dir/Neuron.cpp.o
AllNeurons: CMakeFiles/AllNeurons.dir/Network.cpp.o
AllNeurons: CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o
AllNeurons: CMakeFiles/AllNeurons.dir/build.make
AllNeurons: CMakeFiles/AllNeurons.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable AllNeurons"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AllNeurons.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AllNeurons.dir/build: AllNeurons
.PHONY : CMakeFiles/AllNeurons.dir/build

CMakeFiles/AllNeurons.dir/requires: CMakeFiles/AllNeurons.dir/Neuron.cpp.o.requires
CMakeFiles/AllNeurons.dir/requires: CMakeFiles/AllNeurons.dir/Network.cpp.o.requires
CMakeFiles/AllNeurons.dir/requires: CMakeFiles/AllNeurons.dir/test_allneurons.cpp.o.requires
.PHONY : CMakeFiles/AllNeurons.dir/requires

CMakeFiles/AllNeurons.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AllNeurons.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AllNeurons.dir/clean

CMakeFiles/AllNeurons.dir/depend:
	cd /home/localguest/Documents/Neuron/NeuronProject/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/localguest/Documents/Neuron/NeuronProject /home/localguest/Documents/Neuron/NeuronProject /home/localguest/Documents/Neuron/NeuronProject/src /home/localguest/Documents/Neuron/NeuronProject/src /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles/AllNeurons.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AllNeurons.dir/depend

