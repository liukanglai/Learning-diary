# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/demo_cuda.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo_cuda.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo_cuda.dir/flags.make

CMakeFiles/demo_cuda.dir/main.cu.o: CMakeFiles/demo_cuda.dir/flags.make
CMakeFiles/demo_cuda.dir/main.cu.o: ../main.cu
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CUDA object CMakeFiles/demo_cuda.dir/main.cu.o"
	/opt/cuda/bin/nvcc -forward-unknown-to-host-compiler $(CUDA_DEFINES) $(CUDA_INCLUDES) $(CUDA_FLAGS) -x cu -dc /home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda/main.cu -o CMakeFiles/demo_cuda.dir/main.cu.o

CMakeFiles/demo_cuda.dir/main.cu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CUDA source to CMakeFiles/demo_cuda.dir/main.cu.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_PREPROCESSED_SOURCE

CMakeFiles/demo_cuda.dir/main.cu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CUDA source to assembly CMakeFiles/demo_cuda.dir/main.cu.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CUDA_CREATE_ASSEMBLY_SOURCE

# Object files for target demo_cuda
demo_cuda_OBJECTS = \
"CMakeFiles/demo_cuda.dir/main.cu.o"

# External object files for target demo_cuda
demo_cuda_EXTERNAL_OBJECTS =

CMakeFiles/demo_cuda.dir/cmake_device_link.o: CMakeFiles/demo_cuda.dir/main.cu.o
CMakeFiles/demo_cuda.dir/cmake_device_link.o: CMakeFiles/demo_cuda.dir/build.make
CMakeFiles/demo_cuda.dir/cmake_device_link.o: CMakeFiles/demo_cuda.dir/dlink.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CUDA device code CMakeFiles/demo_cuda.dir/cmake_device_link.o"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo_cuda.dir/dlink.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo_cuda.dir/build: CMakeFiles/demo_cuda.dir/cmake_device_link.o

.PHONY : CMakeFiles/demo_cuda.dir/build

# Object files for target demo_cuda
demo_cuda_OBJECTS = \
"CMakeFiles/demo_cuda.dir/main.cu.o"

# External object files for target demo_cuda
demo_cuda_EXTERNAL_OBJECTS =

demo_cuda: CMakeFiles/demo_cuda.dir/main.cu.o
demo_cuda: CMakeFiles/demo_cuda.dir/build.make
demo_cuda: CMakeFiles/demo_cuda.dir/cmake_device_link.o
demo_cuda: CMakeFiles/demo_cuda.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CUDA executable demo_cuda"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo_cuda.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo_cuda.dir/build: demo_cuda

.PHONY : CMakeFiles/demo_cuda.dir/build

CMakeFiles/demo_cuda.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo_cuda.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo_cuda.dir/clean

CMakeFiles/demo_cuda.dir/depend:
	cd /home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda /home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda /home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda/cmake-build-debug /home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda/cmake-build-debug /home/liukanglai/Downloads/Learning-diary/Code/CLionProjects/demo_cuda/cmake-build-debug/CMakeFiles/demo_cuda.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo_cuda.dir/depend

