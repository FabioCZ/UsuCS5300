# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fabio/Desktop/UsuCS5300/HW3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fabio/Desktop/UsuCS5300/HW3

# Include any dependencies generated for this target.
include CMakeFiles/f_cpsl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/f_cpsl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/f_cpsl.dir/flags.make

CMakeFiles/f_cpsl.dir/driver.cpp.o: CMakeFiles/f_cpsl.dir/flags.make
CMakeFiles/f_cpsl.dir/driver.cpp.o: driver.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fabio/Desktop/UsuCS5300/HW3/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/f_cpsl.dir/driver.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/f_cpsl.dir/driver.cpp.o -c /home/fabio/Desktop/UsuCS5300/HW3/driver.cpp

CMakeFiles/f_cpsl.dir/driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/f_cpsl.dir/driver.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/fabio/Desktop/UsuCS5300/HW3/driver.cpp > CMakeFiles/f_cpsl.dir/driver.cpp.i

CMakeFiles/f_cpsl.dir/driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/f_cpsl.dir/driver.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/fabio/Desktop/UsuCS5300/HW3/driver.cpp -o CMakeFiles/f_cpsl.dir/driver.cpp.s

CMakeFiles/f_cpsl.dir/driver.cpp.o.requires:
.PHONY : CMakeFiles/f_cpsl.dir/driver.cpp.o.requires

CMakeFiles/f_cpsl.dir/driver.cpp.o.provides: CMakeFiles/f_cpsl.dir/driver.cpp.o.requires
	$(MAKE) -f CMakeFiles/f_cpsl.dir/build.make CMakeFiles/f_cpsl.dir/driver.cpp.o.provides.build
.PHONY : CMakeFiles/f_cpsl.dir/driver.cpp.o.provides

CMakeFiles/f_cpsl.dir/driver.cpp.o.provides.build: CMakeFiles/f_cpsl.dir/driver.cpp.o

# Object files for target f_cpsl
f_cpsl_OBJECTS = \
"CMakeFiles/f_cpsl.dir/driver.cpp.o"

# External object files for target f_cpsl
f_cpsl_EXTERNAL_OBJECTS =

f_cpsl: CMakeFiles/f_cpsl.dir/driver.cpp.o
f_cpsl: CMakeFiles/f_cpsl.dir/build.make
f_cpsl: libcpsl_common.a
f_cpsl: /usr/lib/x86_64-linux-gnu/libfl.so
f_cpsl: /usr/lib/x86_64-linux-gnu/libboost_program_options.a
f_cpsl: /usr/lib/x86_64-linux-gnu/libboost_system.a
f_cpsl: /usr/lib/x86_64-linux-gnu/libboost_filesystem.a
f_cpsl: CMakeFiles/f_cpsl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable f_cpsl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/f_cpsl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/f_cpsl.dir/build: f_cpsl
.PHONY : CMakeFiles/f_cpsl.dir/build

CMakeFiles/f_cpsl.dir/requires: CMakeFiles/f_cpsl.dir/driver.cpp.o.requires
.PHONY : CMakeFiles/f_cpsl.dir/requires

CMakeFiles/f_cpsl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/f_cpsl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/f_cpsl.dir/clean

CMakeFiles/f_cpsl.dir/depend:
	cd /home/fabio/Desktop/UsuCS5300/HW3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fabio/Desktop/UsuCS5300/HW3 /home/fabio/Desktop/UsuCS5300/HW3 /home/fabio/Desktop/UsuCS5300/HW3 /home/fabio/Desktop/UsuCS5300/HW3 /home/fabio/Desktop/UsuCS5300/HW3/CMakeFiles/f_cpsl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/f_cpsl.dir/depend

