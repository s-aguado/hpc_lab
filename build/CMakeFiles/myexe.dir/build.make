# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /mnt/netapp1/Optcesga_FT2_RHEL7/easybuild-cesga/software/Compiler/gcccore/6.4.0/cmake/3.12.4/bin/cmake

# The command to remove a file.
RM = /mnt/netapp1/Optcesga_FT2_RHEL7/easybuild-cesga/software/Compiler/gcccore/6.4.0/cmake/3.12.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ulc/cursos/curso391/Tools/hpc_lab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ulc/cursos/curso391/Tools/hpc_lab/build

# Include any dependencies generated for this target.
include CMakeFiles/myexe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myexe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myexe.dir/flags.make

CMakeFiles/myexe.dir/matmul_kernels_avx.c.o: CMakeFiles/myexe.dir/flags.make
CMakeFiles/myexe.dir/matmul_kernels_avx.c.o: ../matmul_kernels_avx.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulc/cursos/curso391/Tools/hpc_lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/myexe.dir/matmul_kernels_avx.c.o"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myexe.dir/matmul_kernels_avx.c.o   -c /home/ulc/cursos/curso391/Tools/hpc_lab/matmul_kernels_avx.c

CMakeFiles/myexe.dir/matmul_kernels_avx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myexe.dir/matmul_kernels_avx.c.i"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulc/cursos/curso391/Tools/hpc_lab/matmul_kernels_avx.c > CMakeFiles/myexe.dir/matmul_kernels_avx.c.i

CMakeFiles/myexe.dir/matmul_kernels_avx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myexe.dir/matmul_kernels_avx.c.s"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulc/cursos/curso391/Tools/hpc_lab/matmul_kernels_avx.c -o CMakeFiles/myexe.dir/matmul_kernels_avx.c.s

CMakeFiles/myexe.dir/matmul_kernels.c.o: CMakeFiles/myexe.dir/flags.make
CMakeFiles/myexe.dir/matmul_kernels.c.o: ../matmul_kernels.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulc/cursos/curso391/Tools/hpc_lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/myexe.dir/matmul_kernels.c.o"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myexe.dir/matmul_kernels.c.o   -c /home/ulc/cursos/curso391/Tools/hpc_lab/matmul_kernels.c

CMakeFiles/myexe.dir/matmul_kernels.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myexe.dir/matmul_kernels.c.i"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulc/cursos/curso391/Tools/hpc_lab/matmul_kernels.c > CMakeFiles/myexe.dir/matmul_kernels.c.i

CMakeFiles/myexe.dir/matmul_kernels.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myexe.dir/matmul_kernels.c.s"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulc/cursos/curso391/Tools/hpc_lab/matmul_kernels.c -o CMakeFiles/myexe.dir/matmul_kernels.c.s

CMakeFiles/myexe.dir/matmul.c.o: CMakeFiles/myexe.dir/flags.make
CMakeFiles/myexe.dir/matmul.c.o: ../matmul.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulc/cursos/curso391/Tools/hpc_lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/myexe.dir/matmul.c.o"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myexe.dir/matmul.c.o   -c /home/ulc/cursos/curso391/Tools/hpc_lab/matmul.c

CMakeFiles/myexe.dir/matmul.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myexe.dir/matmul.c.i"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulc/cursos/curso391/Tools/hpc_lab/matmul.c > CMakeFiles/myexe.dir/matmul.c.i

CMakeFiles/myexe.dir/matmul.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myexe.dir/matmul.c.s"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulc/cursos/curso391/Tools/hpc_lab/matmul.c -o CMakeFiles/myexe.dir/matmul.c.s

CMakeFiles/myexe.dir/stuff.c.o: CMakeFiles/myexe.dir/flags.make
CMakeFiles/myexe.dir/stuff.c.o: ../stuff.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ulc/cursos/curso391/Tools/hpc_lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/myexe.dir/stuff.c.o"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/myexe.dir/stuff.c.o   -c /home/ulc/cursos/curso391/Tools/hpc_lab/stuff.c

CMakeFiles/myexe.dir/stuff.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myexe.dir/stuff.c.i"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ulc/cursos/curso391/Tools/hpc_lab/stuff.c > CMakeFiles/myexe.dir/stuff.c.i

CMakeFiles/myexe.dir/stuff.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myexe.dir/stuff.c.s"
	/opt/cesga/easybuild-cesga/software/Core/gcccore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ulc/cursos/curso391/Tools/hpc_lab/stuff.c -o CMakeFiles/myexe.dir/stuff.c.s

# Object files for target myexe
myexe_OBJECTS = \
"CMakeFiles/myexe.dir/matmul_kernels_avx.c.o" \
"CMakeFiles/myexe.dir/matmul_kernels.c.o" \
"CMakeFiles/myexe.dir/matmul.c.o" \
"CMakeFiles/myexe.dir/stuff.c.o"

# External object files for target myexe
myexe_EXTERNAL_OBJECTS =

myexe: CMakeFiles/myexe.dir/matmul_kernels_avx.c.o
myexe: CMakeFiles/myexe.dir/matmul_kernels.c.o
myexe: CMakeFiles/myexe.dir/matmul.c.o
myexe: CMakeFiles/myexe.dir/stuff.c.o
myexe: CMakeFiles/myexe.dir/build.make
myexe: CMakeFiles/myexe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ulc/cursos/curso391/Tools/hpc_lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable myexe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myexe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myexe.dir/build: myexe

.PHONY : CMakeFiles/myexe.dir/build

CMakeFiles/myexe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myexe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myexe.dir/clean

CMakeFiles/myexe.dir/depend:
	cd /home/ulc/cursos/curso391/Tools/hpc_lab/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ulc/cursos/curso391/Tools/hpc_lab /home/ulc/cursos/curso391/Tools/hpc_lab /home/ulc/cursos/curso391/Tools/hpc_lab/build /home/ulc/cursos/curso391/Tools/hpc_lab/build /home/ulc/cursos/curso391/Tools/hpc_lab/build/CMakeFiles/myexe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myexe.dir/depend
