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
include CMakeFiles/Buffer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Buffer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Buffer.dir/flags.make

CMakeFiles/Buffer.dir/Neuron.cpp.o: CMakeFiles/Buffer.dir/flags.make
CMakeFiles/Buffer.dir/Neuron.cpp.o: Neuron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Buffer.dir/Neuron.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Buffer.dir/Neuron.cpp.o -c /home/localguest/Documents/Neuron/NeuronProject/src/Neuron.cpp

CMakeFiles/Buffer.dir/Neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Buffer.dir/Neuron.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/localguest/Documents/Neuron/NeuronProject/src/Neuron.cpp > CMakeFiles/Buffer.dir/Neuron.cpp.i

CMakeFiles/Buffer.dir/Neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Buffer.dir/Neuron.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/localguest/Documents/Neuron/NeuronProject/src/Neuron.cpp -o CMakeFiles/Buffer.dir/Neuron.cpp.s

CMakeFiles/Buffer.dir/Neuron.cpp.o.requires:
.PHONY : CMakeFiles/Buffer.dir/Neuron.cpp.o.requires

CMakeFiles/Buffer.dir/Neuron.cpp.o.provides: CMakeFiles/Buffer.dir/Neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/Buffer.dir/build.make CMakeFiles/Buffer.dir/Neuron.cpp.o.provides.build
.PHONY : CMakeFiles/Buffer.dir/Neuron.cpp.o.provides

CMakeFiles/Buffer.dir/Neuron.cpp.o.provides.build: CMakeFiles/Buffer.dir/Neuron.cpp.o

CMakeFiles/Buffer.dir/Network.cpp.o: CMakeFiles/Buffer.dir/flags.make
CMakeFiles/Buffer.dir/Network.cpp.o: Network.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Buffer.dir/Network.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Buffer.dir/Network.cpp.o -c /home/localguest/Documents/Neuron/NeuronProject/src/Network.cpp

CMakeFiles/Buffer.dir/Network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Buffer.dir/Network.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/localguest/Documents/Neuron/NeuronProject/src/Network.cpp > CMakeFiles/Buffer.dir/Network.cpp.i

CMakeFiles/Buffer.dir/Network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Buffer.dir/Network.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/localguest/Documents/Neuron/NeuronProject/src/Network.cpp -o CMakeFiles/Buffer.dir/Network.cpp.s

CMakeFiles/Buffer.dir/Network.cpp.o.requires:
.PHONY : CMakeFiles/Buffer.dir/Network.cpp.o.requires

CMakeFiles/Buffer.dir/Network.cpp.o.provides: CMakeFiles/Buffer.dir/Network.cpp.o.requires
	$(MAKE) -f CMakeFiles/Buffer.dir/build.make CMakeFiles/Buffer.dir/Network.cpp.o.provides.build
.PHONY : CMakeFiles/Buffer.dir/Network.cpp.o.provides

CMakeFiles/Buffer.dir/Network.cpp.o.provides.build: CMakeFiles/Buffer.dir/Network.cpp.o

CMakeFiles/Buffer.dir/buffertest.cpp.o: CMakeFiles/Buffer.dir/flags.make
CMakeFiles/Buffer.dir/buffertest.cpp.o: buffertest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Buffer.dir/buffertest.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Buffer.dir/buffertest.cpp.o -c /home/localguest/Documents/Neuron/NeuronProject/src/buffertest.cpp

CMakeFiles/Buffer.dir/buffertest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Buffer.dir/buffertest.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/localguest/Documents/Neuron/NeuronProject/src/buffertest.cpp > CMakeFiles/Buffer.dir/buffertest.cpp.i

CMakeFiles/Buffer.dir/buffertest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Buffer.dir/buffertest.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/localguest/Documents/Neuron/NeuronProject/src/buffertest.cpp -o CMakeFiles/Buffer.dir/buffertest.cpp.s

CMakeFiles/Buffer.dir/buffertest.cpp.o.requires:
.PHONY : CMakeFiles/Buffer.dir/buffertest.cpp.o.requires

CMakeFiles/Buffer.dir/buffertest.cpp.o.provides: CMakeFiles/Buffer.dir/buffertest.cpp.o.requires
	$(MAKE) -f CMakeFiles/Buffer.dir/build.make CMakeFiles/Buffer.dir/buffertest.cpp.o.provides.build
.PHONY : CMakeFiles/Buffer.dir/buffertest.cpp.o.provides

CMakeFiles/Buffer.dir/buffertest.cpp.o.provides.build: CMakeFiles/Buffer.dir/buffertest.cpp.o

# Object files for target Buffer
Buffer_OBJECTS = \
"CMakeFiles/Buffer.dir/Neuron.cpp.o" \
"CMakeFiles/Buffer.dir/Network.cpp.o" \
"CMakeFiles/Buffer.dir/buffertest.cpp.o"

# External object files for target Buffer
Buffer_EXTERNAL_OBJECTS =

Buffer: CMakeFiles/Buffer.dir/Neuron.cpp.o
Buffer: CMakeFiles/Buffer.dir/Network.cpp.o
Buffer: CMakeFiles/Buffer.dir/buffertest.cpp.o
Buffer: CMakeFiles/Buffer.dir/build.make
Buffer: CMakeFiles/Buffer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Buffer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Buffer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Buffer.dir/build: Buffer
.PHONY : CMakeFiles/Buffer.dir/build

CMakeFiles/Buffer.dir/requires: CMakeFiles/Buffer.dir/Neuron.cpp.o.requires
CMakeFiles/Buffer.dir/requires: CMakeFiles/Buffer.dir/Network.cpp.o.requires
CMakeFiles/Buffer.dir/requires: CMakeFiles/Buffer.dir/buffertest.cpp.o.requires
.PHONY : CMakeFiles/Buffer.dir/requires

CMakeFiles/Buffer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Buffer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Buffer.dir/clean

CMakeFiles/Buffer.dir/depend:
	cd /home/localguest/Documents/Neuron/NeuronProject/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/localguest/Documents/Neuron/NeuronProject /home/localguest/Documents/Neuron/NeuronProject /home/localguest/Documents/Neuron/NeuronProject/src /home/localguest/Documents/Neuron/NeuronProject/src /home/localguest/Documents/Neuron/NeuronProject/src/CMakeFiles/Buffer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Buffer.dir/depend

