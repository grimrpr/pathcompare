# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin

# Include any dependencies generated for this target.
include CMakeFiles/mainplugin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mainplugin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainplugin.dir/flags.make

CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o: CMakeFiles/mainplugin.dir/flags.make
CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o: src/pathcomparemainfactoryplugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o -c /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/src/pathcomparemainfactoryplugin.cpp

CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/src/pathcomparemainfactoryplugin.cpp > CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.i

CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/src/pathcomparemainfactoryplugin.cpp -o CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.s

CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o.requires:
.PHONY : CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o.requires

CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o.provides: CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o.requires
	$(MAKE) -f CMakeFiles/mainplugin.dir/build.make CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o.provides.build
.PHONY : CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o.provides

CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o.provides.build: CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o

CMakeFiles/mainplugin.dir/src/comperatorplugin.o: CMakeFiles/mainplugin.dir/flags.make
CMakeFiles/mainplugin.dir/src/comperatorplugin.o: src/comperatorplugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mainplugin.dir/src/comperatorplugin.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mainplugin.dir/src/comperatorplugin.o -c /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/src/comperatorplugin.cpp

CMakeFiles/mainplugin.dir/src/comperatorplugin.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainplugin.dir/src/comperatorplugin.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/src/comperatorplugin.cpp > CMakeFiles/mainplugin.dir/src/comperatorplugin.i

CMakeFiles/mainplugin.dir/src/comperatorplugin.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainplugin.dir/src/comperatorplugin.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/src/comperatorplugin.cpp -o CMakeFiles/mainplugin.dir/src/comperatorplugin.s

CMakeFiles/mainplugin.dir/src/comperatorplugin.o.requires:
.PHONY : CMakeFiles/mainplugin.dir/src/comperatorplugin.o.requires

CMakeFiles/mainplugin.dir/src/comperatorplugin.o.provides: CMakeFiles/mainplugin.dir/src/comperatorplugin.o.requires
	$(MAKE) -f CMakeFiles/mainplugin.dir/build.make CMakeFiles/mainplugin.dir/src/comperatorplugin.o.provides.build
.PHONY : CMakeFiles/mainplugin.dir/src/comperatorplugin.o.provides

CMakeFiles/mainplugin.dir/src/comperatorplugin.o.provides.build: CMakeFiles/mainplugin.dir/src/comperatorplugin.o

CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o: CMakeFiles/mainplugin.dir/flags.make
CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o: src/moc_pathcomparemainfactoryplugin.cxx
	$(CMAKE_COMMAND) -E cmake_progress_report /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o -c /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/src/moc_pathcomparemainfactoryplugin.cxx

CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/src/moc_pathcomparemainfactoryplugin.cxx > CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.i

CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/src/moc_pathcomparemainfactoryplugin.cxx -o CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.s

CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o.requires:
.PHONY : CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o.requires

CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o.provides: CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o.requires
	$(MAKE) -f CMakeFiles/mainplugin.dir/build.make CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o.provides.build
.PHONY : CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o.provides

CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o.provides.build: CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o

src/moc_pathcomparemainfactoryplugin.cxx: src/pathcomparemainfactoryplugin.h
	$(CMAKE_COMMAND) -E cmake_progress_report /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating src/moc_pathcomparemainfactoryplugin.cxx"
	/usr/bin/moc-qt4 -I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore -I/opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin -I/pathcompare/src/interfaces -DQT_NO_KEYWORDS -DQT_PLUGIN -DQT_NO_DEBUG -DQT_SHARED -DQT_GUI_LIB -DQT_CORE_LIB -o /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/src/moc_pathcomparemainfactoryplugin.cxx /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/src/pathcomparemainfactoryplugin.h

# Object files for target mainplugin
mainplugin_OBJECTS = \
"CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o" \
"CMakeFiles/mainplugin.dir/src/comperatorplugin.o" \
"CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o"

# External object files for target mainplugin
mainplugin_EXTERNAL_OBJECTS =

lib/libmainplugin.so: CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o
lib/libmainplugin.so: CMakeFiles/mainplugin.dir/src/comperatorplugin.o
lib/libmainplugin.so: CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o
lib/libmainplugin.so: /usr/lib/x86_64-linux-gnu/libQtGui.so
lib/libmainplugin.so: /usr/lib/x86_64-linux-gnu/libQtCore.so
lib/libmainplugin.so: CMakeFiles/mainplugin.dir/build.make
lib/libmainplugin.so: CMakeFiles/mainplugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library lib/libmainplugin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainplugin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainplugin.dir/build: lib/libmainplugin.so
.PHONY : CMakeFiles/mainplugin.dir/build

CMakeFiles/mainplugin.dir/requires: CMakeFiles/mainplugin.dir/src/pathcomparemainfactoryplugin.o.requires
CMakeFiles/mainplugin.dir/requires: CMakeFiles/mainplugin.dir/src/comperatorplugin.o.requires
CMakeFiles/mainplugin.dir/requires: CMakeFiles/mainplugin.dir/src/moc_pathcomparemainfactoryplugin.o.requires
.PHONY : CMakeFiles/mainplugin.dir/requires

CMakeFiles/mainplugin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainplugin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainplugin.dir/clean

CMakeFiles/mainplugin.dir/depend: src/moc_pathcomparemainfactoryplugin.cxx
	cd /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin /opt/ros/diamondback/stacks/pathcompare/src/plugins/mainplugin/CMakeFiles/mainplugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mainplugin.dir/depend

