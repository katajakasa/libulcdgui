# A simple Makefile for libulcdgui

# Installation stuff
LIBNAME=libulcdgui.so
INSTALL_LIBDIR=/usr/lib
INSTALL_INCDIR=/usr/include

# Internal paths
OBJDIR=obj
LIBDIR=lib
INCDIR=include

# Tools
CC=g++
RM=rm -f
MKDIR=mkdir -p
RMDIR=rmdir
MV=mv
CP=cp

# Stuff for compilation
FILES := \
    src/lcddevice.cpp \
    src/guiobject.cpp \
    src/frame.cpp \
    src/components/button.cpp \
    src/components/component.cpp \
    src/rendering/color.cpp \
    src/rendering/surface.cpp \
    src/sizers/sizer.cpp \
    src/sizers/vsizer.cpp \
    src/sizers/hsizer.cpp 
    
SIGCONFIG=/usr/lib/sigc++-2.0/include/
SIGHEADER=/usr/include/sigc++-2.0/
    
CFLAGS=-I include/ -I$(SIGHEADER) -I$(SIGCONFIG) -fPIC -O2 -std=c++0x -Wall -W -DLINUX
LDFLAGS=-shared

all: 
	$(MKDIR) $(LIBDIR)
	$(MKDIR) $(OBJDIR)
	$(CC) $(CFLAGS) -c $(FILES)
	$(MV) *.o $(OBJDIR)/
	$(CC) $(LDFLAGS) -Wl,-soname,$(LIBNAME) -o $(LIBDIR)/$(LIBNAME) $(OBJDIR)/*.o
	@echo "Make done. To install, run make install."

clean:
	$(RM) $(OBJDIR)/*.o
	$(RM) $(LIBDIR)/*

install:
	$(CP) $(LIBDIR)/$(LIBNAME) $(INSTALL_LIBDIR)
	$(MKDIR) $(INSTALL_INCDIR)/ulcdgui
	$(CP) -r $(INCDIR)/ulcdgui/* $(INSTALL_INCDIR)/ulcdgui/
	@echo "Install done."

uninstall:
	$(RM) $(INSTALL_INCDIR)/ulcdgui/events/event.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/frame.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/lcddevice.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/guiobject.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/drawable.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/guiexception.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/rendering/color.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/rendering/surface.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/components/button.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/components/component.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/sizers/hsizer.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/sizers/sizer.h
	$(RM) $(INSTALL_INCDIR)/ulcdgui/sizers/vsizer.h
	$(RMDIR) $(INSTALL_INCDIR)/ulcdgui/components
	$(RMDIR) $(INSTALL_INCDIR)/ulcdgui/sizers
	$(RMDIR) $(INSTALL_INCDIR)/ulcdgui/rendering
	$(RMDIR) $(INSTALL_INCDIR)/ulcdgui/events
	$(RMDIR) $(INSTALL_INCDIR)/ulcdgui
	$(RM) $(INSTALL_LIBDIR)/$(LIBNAME)
	@echo "Uninstall done."