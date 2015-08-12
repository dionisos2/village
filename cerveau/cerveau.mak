# Microsoft Developer Studio Generated NMAKE File, Based on cerveau.dsp
!IF "$(CFG)" == ""
CFG=cerveau - Win32 Debug
!MESSAGE No configuration specified. Defaulting to cerveau - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "cerveau - Win32 Release" && "$(CFG)" != "cerveau - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cerveau.mak" CFG="cerveau - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cerveau - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "cerveau - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cerveau - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\cerveau.exe"


CLEAN :
	-@erase "$(INTDIR)\ame.obj"
	-@erase "$(INTDIR)\cerveau.obj"
	-@erase "$(INTDIR)\fonctions.obj"
	-@erase "$(INTDIR)\positron.obj"
	-@erase "$(INTDIR)\timer.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\village.obj"
	-@erase "$(OUTDIR)\cerveau.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\cerveau.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\cerveau.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\cerveau.pdb" /machine:I386 /out:"$(OUTDIR)\cerveau.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ame.obj" \
	"$(INTDIR)\cerveau.obj" \
	"$(INTDIR)\fonctions.obj" \
	"$(INTDIR)\positron.obj" \
	"$(INTDIR)\village.obj" \
	"$(INTDIR)\timer.obj"

"$(OUTDIR)\cerveau.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "cerveau - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\cerveau.exe"


CLEAN :
	-@erase "$(INTDIR)\ame.obj"
	-@erase "$(INTDIR)\cerveau.obj"
	-@erase "$(INTDIR)\fonctions.obj"
	-@erase "$(INTDIR)\positron.obj"
	-@erase "$(INTDIR)\timer.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\village.obj"
	-@erase "$(OUTDIR)\cerveau.exe"
	-@erase "$(OUTDIR)\cerveau.ilk"
	-@erase "$(OUTDIR)\cerveau.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\cerveau.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\cerveau.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib glut32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\cerveau.pdb" /debug /machine:I386 /out:"$(OUTDIR)\cerveau.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ame.obj" \
	"$(INTDIR)\cerveau.obj" \
	"$(INTDIR)\fonctions.obj" \
	"$(INTDIR)\positron.obj" \
	"$(INTDIR)\village.obj" \
	"$(INTDIR)\timer.obj"

"$(OUTDIR)\cerveau.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("cerveau.dep")
!INCLUDE "cerveau.dep"
!ELSE 
!MESSAGE Warning: cannot find "cerveau.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "cerveau - Win32 Release" || "$(CFG)" == "cerveau - Win32 Debug"
SOURCE=.\Ame\ame.cpp

"$(INTDIR)\ame.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\cerveau.cpp

"$(INTDIR)\cerveau.obj" : $(SOURCE) "$(INTDIR)"


SOURCE="I:\Program Files\Microsoft Visual Studio\VC98\Lib\fonctions.cpp"

"$(INTDIR)\fonctions.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\positron\positron.cpp

"$(INTDIR)\positron.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE="I:\Program Files\Microsoft Visual Studio\VC98\Lib\timer.cpp"

"$(INTDIR)\timer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\village.cpp

"$(INTDIR)\village.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

