# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/hamza/Documents/clion-2018.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/hamza/Documents/clion-2018.3.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/circular_cue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/circular_cue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/circular_cue.dir/flags.make

CMakeFiles/circular_cue.dir/main.cpp.o: CMakeFiles/circular_cue.dir/flags.make
CMakeFiles/circular_cue.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/circular_cue.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/circular_cue.dir/main.cpp.o -c /home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue/main.cpp

CMakeFiles/circular_cue.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/circular_cue.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue/main.cpp > CMakeFiles/circular_cue.dir/main.cpp.i

CMakeFiles/circular_cue.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/circular_cue.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue/main.cpp -o CMakeFiles/circular_cue.dir/main.cpp.s

# Object files for target circular_cue
circular_cue_OBJECTS = \
"CMakeFiles/circular_cue.dir/main.cpp.o"

# External object files for target circular_cue
circular_cue_EXTERNAL_OBJECTS =

circular_cue: CMakeFiles/circular_cue.dir/main.cpp.o
circular_cue: CMakeFiles/circular_cue.dir/build.make
circular_cue: CMakeFiles/circular_cue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable circular_cue"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/circular_cue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/circular_cue.dir/build: circular_cue

.PHONY : CMakeFiles/circular_cue.dir/build

CMakeFiles/circular_cue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/circular_cue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/circular_cue.dir/clean

CMakeFiles/circular_cue.dir/depend:
	cd /home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue /home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue /home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue/cmake-build-debug /home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue/cmake-build-debug /home/hamza/Documents/Semester-3/University/Sir_Fazl-e-basit/Apply/circular_cue/cmake-build-debug/CMakeFiles/circular_cue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/circular_cue.dir/depend

