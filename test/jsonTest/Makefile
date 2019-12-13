SRCDIR = ./JsonLib

# LIB_OBJS = $(SRCDIR)/INIParser.o \
	
LIB_NAME = jsoncpp
LIB_DIR = ../../../Lib/FileLib/JsonLib/
INTERFACE_DIR = ../../../Interface/FileLib/JsonLib/

# CC = gcc
# CPP = g++
# LD = g++
# AR = ar
# AR2 = ranlib

# CFLAGS = -g -O3 -Wall -D__linux__ -D_LINUX -fPIC
# DEFINES = -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_ISOC9X_SOURCE
# INC = -I./ 



# all: lib install

# lib: lib$(LIB_NAME).a

# lib$(LIB_NAME).a: $(LIB_OBJS)
	# $(RM) lib$(LIB_NAME).a
	# $(AR) cru lib$(LIB_NAME).a $(LIB_OBJS)
	# $(AR2) lib$(LIB_NAME).a

# %.o: %.S
	# $(CC) $(CFLAGS) $(INC) $(DEFINES) -c -o $@ $<
	
# %.o:%.c
	# $(CC) $(CFLAGS) $(INC) $(DEFINES) -c $< -o $@

# %.o:%.cpp
	# $(CPP) $(CFLAGS) $(INC) $(DEFINES) -c $< -o $@

install:
	@if [ ! -e $(LIB_DIR) ]; then mkdir -p $(LIB_DIR) ; fi
	@if [ ! -e $(INTERFACE_DIR) ]; then mkdir -p $(INTERFACE_DIR) ; fi
	cp -rf $(SRCDIR)/json $(INTERFACE_DIR)
	cp -f lib$(LIB_NAME).a $(LIB_DIR)
	

# clean:


# rebuild: clean all

