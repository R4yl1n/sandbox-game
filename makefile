COMPILER = clang++
SOURCE_LIBS = -Ilib/
OSX_OPT = -std=c++17 -Llib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a
OSX_OUT = -o "bin/build_osx"
BUILD_IMAGE_OSX_OUT = -o "bin/build_img_osx"
CFILES = src/*.cpp
CFILESEXPORTASCODE = exportimagesAsCode/*.cpp
build_osx:
	$(COMPILER) $(CFILES) $(SOURCE_LIBS) $(OSX_OUT) $(OSX_OPT) 

build_img:
	$(COMPILER) $(CFILESEXPORTASCODE) $(SOURCE_LIBS) $(BUILD_IMAGE_OSX_OUT) $(OSX_OPT)
	
