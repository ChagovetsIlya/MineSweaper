# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cagovecila/test/MyTests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cagovecila/test/MyTests/build

# Include any dependencies generated for this target.
include CMakeFiles/MyTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyTests.dir/flags.make

CMakeFiles/MyTests.dir/test.cpp.o: CMakeFiles/MyTests.dir/flags.make
CMakeFiles/MyTests.dir/test.cpp.o: /Users/cagovecila/test/MyTests/test.cpp
CMakeFiles/MyTests.dir/test.cpp.o: CMakeFiles/MyTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cagovecila/test/MyTests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyTests.dir/test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyTests.dir/test.cpp.o -MF CMakeFiles/MyTests.dir/test.cpp.o.d -o CMakeFiles/MyTests.dir/test.cpp.o -c /Users/cagovecila/test/MyTests/test.cpp

CMakeFiles/MyTests.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyTests.dir/test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cagovecila/test/MyTests/test.cpp > CMakeFiles/MyTests.dir/test.cpp.i

CMakeFiles/MyTests.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyTests.dir/test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cagovecila/test/MyTests/test.cpp -o CMakeFiles/MyTests.dir/test.cpp.s

CMakeFiles/MyTests.dir/fieldgenerator.cpp.o: CMakeFiles/MyTests.dir/flags.make
CMakeFiles/MyTests.dir/fieldgenerator.cpp.o: /Users/cagovecila/test/MyTests/fieldgenerator.cpp
CMakeFiles/MyTests.dir/fieldgenerator.cpp.o: CMakeFiles/MyTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cagovecila/test/MyTests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MyTests.dir/fieldgenerator.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyTests.dir/fieldgenerator.cpp.o -MF CMakeFiles/MyTests.dir/fieldgenerator.cpp.o.d -o CMakeFiles/MyTests.dir/fieldgenerator.cpp.o -c /Users/cagovecila/test/MyTests/fieldgenerator.cpp

CMakeFiles/MyTests.dir/fieldgenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyTests.dir/fieldgenerator.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cagovecila/test/MyTests/fieldgenerator.cpp > CMakeFiles/MyTests.dir/fieldgenerator.cpp.i

CMakeFiles/MyTests.dir/fieldgenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyTests.dir/fieldgenerator.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cagovecila/test/MyTests/fieldgenerator.cpp -o CMakeFiles/MyTests.dir/fieldgenerator.cpp.s

# Object files for target MyTests
MyTests_OBJECTS = \
"CMakeFiles/MyTests.dir/test.cpp.o" \
"CMakeFiles/MyTests.dir/fieldgenerator.cpp.o"

# External object files for target MyTests
MyTests_EXTERNAL_OBJECTS =

MyTests: CMakeFiles/MyTests.dir/test.cpp.o
MyTests: CMakeFiles/MyTests.dir/fieldgenerator.cpp.o
MyTests: CMakeFiles/MyTests.dir/build.make
MyTests: CMakeFiles/MyTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cagovecila/test/MyTests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MyTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyTests.dir/build: MyTests
.PHONY : CMakeFiles/MyTests.dir/build

CMakeFiles/MyTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyTests.dir/clean

CMakeFiles/MyTests.dir/depend:
	cd /Users/cagovecila/test/MyTests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cagovecila/test/MyTests /Users/cagovecila/test/MyTests /Users/cagovecila/test/MyTests/build /Users/cagovecila/test/MyTests/build /Users/cagovecila/test/MyTests/build/CMakeFiles/MyTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyTests.dir/depend

