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
CMAKE_SOURCE_DIR = "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\engine.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\engine.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\engine.dir\flags.make

CMakeFiles\engine.dir\main.cpp.obj: CMakeFiles\engine.dir\flags.make
CMakeFiles\engine.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/engine.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\engine.dir\main.cpp.obj /FdCMakeFiles\engine.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\main.cpp"
<<

CMakeFiles\engine.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\engine.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\main.cpp"
<<

CMakeFiles\engine.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\engine.dir\main.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\main.cpp"
<<

CMakeFiles\engine.dir\tinyxml2-master\tinyxml2.cpp.obj: CMakeFiles\engine.dir\flags.make
CMakeFiles\engine.dir\tinyxml2-master\tinyxml2.cpp.obj: ..\tinyxml2-master\tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/engine.dir/tinyxml2-master/tinyxml2.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\engine.dir\tinyxml2-master\tinyxml2.cpp.obj /FdCMakeFiles\engine.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\tinyxml2-master\tinyxml2.cpp"
<<

CMakeFiles\engine.dir\tinyxml2-master\tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/tinyxml2-master/tinyxml2.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\engine.dir\tinyxml2-master\tinyxml2.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\tinyxml2-master\tinyxml2.cpp"
<<

CMakeFiles\engine.dir\tinyxml2-master\tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/tinyxml2-master/tinyxml2.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\engine.dir\tinyxml2-master\tinyxml2.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\tinyxml2-master\tinyxml2.cpp"
<<

CMakeFiles\engine.dir\classes\catmull.cpp.obj: CMakeFiles\engine.dir\flags.make
CMakeFiles\engine.dir\classes\catmull.cpp.obj: ..\classes\catmull.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/engine.dir/classes/catmull.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\engine.dir\classes\catmull.cpp.obj /FdCMakeFiles\engine.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\catmull.cpp"
<<

CMakeFiles\engine.dir\classes\catmull.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/classes/catmull.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\engine.dir\classes\catmull.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\catmull.cpp"
<<

CMakeFiles\engine.dir\classes\catmull.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/classes/catmull.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\engine.dir\classes\catmull.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\catmull.cpp"
<<

CMakeFiles\engine.dir\classes\Group.cpp.obj: CMakeFiles\engine.dir\flags.make
CMakeFiles\engine.dir\classes\Group.cpp.obj: ..\classes\Group.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/engine.dir/classes/Group.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\engine.dir\classes\Group.cpp.obj /FdCMakeFiles\engine.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\Group.cpp"
<<

CMakeFiles\engine.dir\classes\Group.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/classes/Group.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\engine.dir\classes\Group.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\Group.cpp"
<<

CMakeFiles\engine.dir\classes\Group.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/classes/Group.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\engine.dir\classes\Group.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\Group.cpp"
<<

CMakeFiles\engine.dir\classes\Transformation.cpp.obj: CMakeFiles\engine.dir\flags.make
CMakeFiles\engine.dir\classes\Transformation.cpp.obj: ..\classes\Transformation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/engine.dir/classes/Transformation.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\engine.dir\classes\Transformation.cpp.obj /FdCMakeFiles\engine.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\Transformation.cpp"
<<

CMakeFiles\engine.dir\classes\Transformation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/classes/Transformation.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\engine.dir\classes\Transformation.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\Transformation.cpp"
<<

CMakeFiles\engine.dir\classes\Transformation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/classes/Transformation.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\engine.dir\classes\Transformation.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\Transformation.cpp"
<<

CMakeFiles\engine.dir\classes\Point.cpp.obj: CMakeFiles\engine.dir\flags.make
CMakeFiles\engine.dir\classes\Point.cpp.obj: ..\classes\Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/engine.dir/classes/Point.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\engine.dir\classes\Point.cpp.obj /FdCMakeFiles\engine.dir\ /FS -c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\Point.cpp"
<<

CMakeFiles\engine.dir\classes\Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/classes/Point.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\engine.dir\classes\Point.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\Point.cpp"
<<

CMakeFiles\engine.dir\classes\Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/classes/Point.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\engine.dir\classes\Point.cpp.s /c "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\classes\Point.cpp"
<<

# Object files for target engine
engine_OBJECTS = \
"CMakeFiles\engine.dir\main.cpp.obj" \
"CMakeFiles\engine.dir\tinyxml2-master\tinyxml2.cpp.obj" \
"CMakeFiles\engine.dir\classes\catmull.cpp.obj" \
"CMakeFiles\engine.dir\classes\Group.cpp.obj" \
"CMakeFiles\engine.dir\classes\Transformation.cpp.obj" \
"CMakeFiles\engine.dir\classes\Point.cpp.obj"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

engine.exe: CMakeFiles\engine.dir\main.cpp.obj
engine.exe: CMakeFiles\engine.dir\tinyxml2-master\tinyxml2.cpp.obj
engine.exe: CMakeFiles\engine.dir\classes\catmull.cpp.obj
engine.exe: CMakeFiles\engine.dir\classes\Group.cpp.obj
engine.exe: CMakeFiles\engine.dir\classes\Transformation.cpp.obj
engine.exe: CMakeFiles\engine.dir\classes\Point.cpp.obj
engine.exe: CMakeFiles\engine.dir\build.make
engine.exe: C:\Users\igor1\Desktop\CG\TrabalhoCG\toolkit\toolkits\glut\glut32.lib
engine.exe: C:\Users\igor1\Desktop\CG\TrabalhoCG\toolkit\toolkits\glew\glew32.lib
engine.exe: CMakeFiles\engine.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable engine.exe"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\engine.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\engine.dir\objects1.rsp @<<
 /out:engine.exe /implib:engine.lib /pdb:"C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug\engine.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  opengl32.lib glu32.lib C:\Users\igor1\Desktop\CG\TrabalhoCG\toolkit\toolkits\glut\glut32.lib C:\Users\igor1\Desktop\CG\TrabalhoCG\toolkit\toolkits\glew\glew32.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\engine.dir\build: engine.exe

.PHONY : CMakeFiles\engine.dir\build

CMakeFiles\engine.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\engine.dir\cmake_clean.cmake
.PHONY : CMakeFiles\engine.dir\clean

CMakeFiles\engine.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine" "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine" "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug" "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug" "C:\Users\igor1\Desktop\CG\TrabalhoCG\entrega 3\engine\cmake-build-debug\CMakeFiles\engine.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\engine.dir\depend

