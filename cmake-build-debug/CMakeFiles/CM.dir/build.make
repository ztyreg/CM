# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zty/Documents/Courses/Compiler/CM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CM.dir/flags.make

CMakeFiles/CM.dir/lex.yy.c.o: CMakeFiles/CM.dir/flags.make
CMakeFiles/CM.dir/lex.yy.c.o: ../lex.yy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CM.dir/lex.yy.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CM.dir/lex.yy.c.o   -c /Users/zty/Documents/Courses/Compiler/CM/lex.yy.c

CMakeFiles/CM.dir/lex.yy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CM.dir/lex.yy.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zty/Documents/Courses/Compiler/CM/lex.yy.c > CMakeFiles/CM.dir/lex.yy.c.i

CMakeFiles/CM.dir/lex.yy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CM.dir/lex.yy.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zty/Documents/Courses/Compiler/CM/lex.yy.c -o CMakeFiles/CM.dir/lex.yy.c.s

CMakeFiles/CM.dir/tiny.tab.c.o: CMakeFiles/CM.dir/flags.make
CMakeFiles/CM.dir/tiny.tab.c.o: ../tiny.tab.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/CM.dir/tiny.tab.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CM.dir/tiny.tab.c.o   -c /Users/zty/Documents/Courses/Compiler/CM/tiny.tab.c

CMakeFiles/CM.dir/tiny.tab.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CM.dir/tiny.tab.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zty/Documents/Courses/Compiler/CM/tiny.tab.c > CMakeFiles/CM.dir/tiny.tab.c.i

CMakeFiles/CM.dir/tiny.tab.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CM.dir/tiny.tab.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zty/Documents/Courses/Compiler/CM/tiny.tab.c -o CMakeFiles/CM.dir/tiny.tab.c.s

CMakeFiles/CM.dir/util.c.o: CMakeFiles/CM.dir/flags.make
CMakeFiles/CM.dir/util.c.o: ../util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/CM.dir/util.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CM.dir/util.c.o   -c /Users/zty/Documents/Courses/Compiler/CM/util.c

CMakeFiles/CM.dir/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CM.dir/util.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zty/Documents/Courses/Compiler/CM/util.c > CMakeFiles/CM.dir/util.c.i

CMakeFiles/CM.dir/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CM.dir/util.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zty/Documents/Courses/Compiler/CM/util.c -o CMakeFiles/CM.dir/util.c.s

CMakeFiles/CM.dir/main.c.o: CMakeFiles/CM.dir/flags.make
CMakeFiles/CM.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/CM.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CM.dir/main.c.o   -c /Users/zty/Documents/Courses/Compiler/CM/main.c

CMakeFiles/CM.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CM.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zty/Documents/Courses/Compiler/CM/main.c > CMakeFiles/CM.dir/main.c.i

CMakeFiles/CM.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CM.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zty/Documents/Courses/Compiler/CM/main.c -o CMakeFiles/CM.dir/main.c.s

CMakeFiles/CM.dir/analyze.c.o: CMakeFiles/CM.dir/flags.make
CMakeFiles/CM.dir/analyze.c.o: ../analyze.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/CM.dir/analyze.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CM.dir/analyze.c.o   -c /Users/zty/Documents/Courses/Compiler/CM/analyze.c

CMakeFiles/CM.dir/analyze.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CM.dir/analyze.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zty/Documents/Courses/Compiler/CM/analyze.c > CMakeFiles/CM.dir/analyze.c.i

CMakeFiles/CM.dir/analyze.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CM.dir/analyze.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zty/Documents/Courses/Compiler/CM/analyze.c -o CMakeFiles/CM.dir/analyze.c.s

CMakeFiles/CM.dir/symtab.c.o: CMakeFiles/CM.dir/flags.make
CMakeFiles/CM.dir/symtab.c.o: ../symtab.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/CM.dir/symtab.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CM.dir/symtab.c.o   -c /Users/zty/Documents/Courses/Compiler/CM/symtab.c

CMakeFiles/CM.dir/symtab.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CM.dir/symtab.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zty/Documents/Courses/Compiler/CM/symtab.c > CMakeFiles/CM.dir/symtab.c.i

CMakeFiles/CM.dir/symtab.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CM.dir/symtab.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zty/Documents/Courses/Compiler/CM/symtab.c -o CMakeFiles/CM.dir/symtab.c.s

# Object files for target CM
CM_OBJECTS = \
"CMakeFiles/CM.dir/lex.yy.c.o" \
"CMakeFiles/CM.dir/tiny.tab.c.o" \
"CMakeFiles/CM.dir/util.c.o" \
"CMakeFiles/CM.dir/main.c.o" \
"CMakeFiles/CM.dir/analyze.c.o" \
"CMakeFiles/CM.dir/symtab.c.o"

# External object files for target CM
CM_EXTERNAL_OBJECTS =

CM: CMakeFiles/CM.dir/lex.yy.c.o
CM: CMakeFiles/CM.dir/tiny.tab.c.o
CM: CMakeFiles/CM.dir/util.c.o
CM: CMakeFiles/CM.dir/main.c.o
CM: CMakeFiles/CM.dir/analyze.c.o
CM: CMakeFiles/CM.dir/symtab.c.o
CM: CMakeFiles/CM.dir/build.make
CM: CMakeFiles/CM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable CM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CM.dir/build: CM

.PHONY : CMakeFiles/CM.dir/build

CMakeFiles/CM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CM.dir/clean

CMakeFiles/CM.dir/depend:
	cd /Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zty/Documents/Courses/Compiler/CM /Users/zty/Documents/Courses/Compiler/CM /Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug /Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug /Users/zty/Documents/Courses/Compiler/CM/cmake-build-debug/CMakeFiles/CM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CM.dir/depend

