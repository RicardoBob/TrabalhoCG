# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\generator.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\generator.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\generator.dir\flags.make

CMakeFiles\generator.dir\main.cpp.obj: CMakeFiles\generator.dir\flags.make
CMakeFiles\generator.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/generator.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\generator.dir\main.cpp.obj /FdCMakeFiles\generator.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\main.cpp"
<<

CMakeFiles\generator.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\generator.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\main.cpp"
<<

CMakeFiles\generator.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\generator.dir\main.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\main.cpp"
<<

CMakeFiles\generator.dir\modelos\bezier.cpp.obj: CMakeFiles\generator.dir\flags.make
CMakeFiles\generator.dir\modelos\bezier.cpp.obj: ..\modelos\bezier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/generator.dir/modelos/bezier.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\generator.dir\modelos\bezier.cpp.obj /FdCMakeFiles\generator.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\bezier.cpp"
<<

CMakeFiles\generator.dir\modelos\bezier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/modelos/bezier.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\generator.dir\modelos\bezier.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\bezier.cpp"
<<

CMakeFiles\generator.dir\modelos\bezier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/modelos/bezier.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\generator.dir\modelos\bezier.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\bezier.cpp"
<<

CMakeFiles\generator.dir\modelos\box.cpp.obj: CMakeFiles\generator.dir\flags.make
CMakeFiles\generator.dir\modelos\box.cpp.obj: ..\modelos\box.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/generator.dir/modelos/box.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\generator.dir\modelos\box.cpp.obj /FdCMakeFiles\generator.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\box.cpp"
<<

CMakeFiles\generator.dir\modelos\box.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/modelos/box.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\generator.dir\modelos\box.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\box.cpp"
<<

CMakeFiles\generator.dir\modelos\box.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/modelos/box.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\generator.dir\modelos\box.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\box.cpp"
<<

CMakeFiles\generator.dir\modelos\plane.cpp.obj: CMakeFiles\generator.dir\flags.make
CMakeFiles\generator.dir\modelos\plane.cpp.obj: ..\modelos\plane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/generator.dir/modelos/plane.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\generator.dir\modelos\plane.cpp.obj /FdCMakeFiles\generator.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\plane.cpp"
<<

CMakeFiles\generator.dir\modelos\plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/modelos/plane.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\generator.dir\modelos\plane.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\plane.cpp"
<<

CMakeFiles\generator.dir\modelos\plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/modelos/plane.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\generator.dir\modelos\plane.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\plane.cpp"
<<

CMakeFiles\generator.dir\modelos\cone.cpp.obj: CMakeFiles\generator.dir\flags.make
CMakeFiles\generator.dir\modelos\cone.cpp.obj: ..\modelos\cone.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/generator.dir/modelos/cone.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\generator.dir\modelos\cone.cpp.obj /FdCMakeFiles\generator.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\cone.cpp"
<<

CMakeFiles\generator.dir\modelos\cone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/modelos/cone.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\generator.dir\modelos\cone.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\cone.cpp"
<<

CMakeFiles\generator.dir\modelos\cone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/modelos/cone.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\generator.dir\modelos\cone.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\cone.cpp"
<<

CMakeFiles\generator.dir\modelos\sphere.cpp.obj: CMakeFiles\generator.dir\flags.make
CMakeFiles\generator.dir\modelos\sphere.cpp.obj: ..\modelos\sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/generator.dir/modelos/sphere.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\generator.dir\modelos\sphere.cpp.obj /FdCMakeFiles\generator.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\sphere.cpp"
<<

CMakeFiles\generator.dir\modelos\sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/modelos/sphere.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\generator.dir\modelos\sphere.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\sphere.cpp"
<<

CMakeFiles\generator.dir\modelos\sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/modelos/sphere.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\generator.dir\modelos\sphere.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\sphere.cpp"
<<

CMakeFiles\generator.dir\modelos\boxInverted.cpp.obj: CMakeFiles\generator.dir\flags.make
CMakeFiles\generator.dir\modelos\boxInverted.cpp.obj: ..\modelos\boxInverted.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/generator.dir/modelos/boxInverted.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\generator.dir\modelos\boxInverted.cpp.obj /FdCMakeFiles\generator.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\boxInverted.cpp"
<<

CMakeFiles\generator.dir\modelos\boxInverted.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generator.dir/modelos/boxInverted.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\generator.dir\modelos\boxInverted.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\boxInverted.cpp"
<<

CMakeFiles\generator.dir\modelos\boxInverted.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generator.dir/modelos/boxInverted.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\generator.dir\modelos\boxInverted.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\modelos\boxInverted.cpp"
<<

# Object files for target generator
generator_OBJECTS = \
"CMakeFiles\generator.dir\main.cpp.obj" \
"CMakeFiles\generator.dir\modelos\bezier.cpp.obj" \
"CMakeFiles\generator.dir\modelos\box.cpp.obj" \
"CMakeFiles\generator.dir\modelos\plane.cpp.obj" \
"CMakeFiles\generator.dir\modelos\cone.cpp.obj" \
"CMakeFiles\generator.dir\modelos\sphere.cpp.obj" \
"CMakeFiles\generator.dir\modelos\boxInverted.cpp.obj"

# External object files for target generator
generator_EXTERNAL_OBJECTS =

generator.exe: CMakeFiles\generator.dir\main.cpp.obj
generator.exe: CMakeFiles\generator.dir\modelos\bezier.cpp.obj
generator.exe: CMakeFiles\generator.dir\modelos\box.cpp.obj
generator.exe: CMakeFiles\generator.dir\modelos\plane.cpp.obj
generator.exe: CMakeFiles\generator.dir\modelos\cone.cpp.obj
generator.exe: CMakeFiles\generator.dir\modelos\sphere.cpp.obj
generator.exe: CMakeFiles\generator.dir\modelos\boxInverted.cpp.obj
generator.exe: CMakeFiles\generator.dir\build.make
generator.exe: CMakeFiles\generator.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable generator.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\generator.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\generator.dir\objects1.rsp @<<
 /out:generator.exe /implib:generator.lib /pdb:"C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug\generator.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\generator.dir\build: generator.exe

.PHONY : CMakeFiles\generator.dir\build

CMakeFiles\generator.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\generator.dir\cmake_clean.cmake
.PHONY : CMakeFiles\generator.dir\clean

CMakeFiles\generator.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator" "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator" "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug" "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug" "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 4\generator\cmake-build-debug\CMakeFiles\generator.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\generator.dir\depend

