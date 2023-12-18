##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=serverUnitTestPP
ConfigurationName      :=Debug
WorkspacePath          :=/home/a/Desktop/CodeLiteWorkSpace
ProjectPath            :=/home/a/Desktop/CodeLiteWorkSpace/serverUnitTestPP
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=1
Date                   :=18/12/23
CodeLitePath           :=/home/a/.codelite
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="serverUnitTestPP.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/include/UnitTest++ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)UnitTest++ $(LibrarySwitch)crypto++ 
ArLibs                 :=  "libUnitTest++.so" "crypto++" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/lib/x86_64-linux-gnu/ 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/mdfile.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/mdfile.cpp$(ObjectSuffix): mdfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mdfile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mdfile.cpp$(DependSuffix) -MM mdfile.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/a/Desktop/CodeLiteWorkSpace/serverUnitTestPP/mdfile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mdfile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mdfile.cpp$(PreprocessSuffix): mdfile.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mdfile.cpp$(PreprocessSuffix) mdfile.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/a/Desktop/CodeLiteWorkSpace/serverUnitTestPP/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


