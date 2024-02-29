# Configuration
# ------------- 
LIBNAME    := solution
BOOSTROOT  := /opt/homebrew/include/

TARDIR     := target
INCDIR     := inc

SRCDIR     := src
SRCOBJDIR  := $(TARDIR)/src
LIBTARDIR  := $(TARDIR)/lib
SRC        := $(wildcard $(SRCDIR)/*.cpp)  
SRCOBJ     := $(addprefix $(SRCOBJDIR)/,$(notdir $(patsubst %.cpp,%.o,$(SRC))))

TESTDIR    := $(SRCDIR)/tests
TESTTARDIR := $(TARDIR)/tests
TEST	     := $(wildcard $(TESTDIR)/*.cpp)
TESTBIN    := $(addprefix $(TESTTARDIR)/,$(notdir $(patsubst %.cpp,%.o,$(TEST))))

CC         := g++
INC        := -I$(BOOSTROOT) -I$(INCDIR)
LDFLAGS    := 
LIBS       :=
CXXFLAGS   := $(INC) -std=c++17
OPT        := -g -O0 -std=c++17 -Werror -pedantic-errors

.PHONY: all, test, clean


# Build and Test Commands
# -----------------------
debug: CXXFLAGS += -g -O0 -Werror -pedantic-errors
debug: output 

release: CXXFLAGS += -O2
release: output 

output: $(LIBTARDIR)/lib$(LIBNAME).a $(LIBTARDIR)/local/lib$(LIBNAME).so

test: $(basename $(TESTBIN)) 
	for unit_test in $(basename $(TESTBIN)); do ./$$unit_test --log_level=all; done

test_%: $(TESTTARDIR)/test_% $(LIBTARDIR)/lib$(LIBNAME).a
	$<

clean: 
	rm -rf $(TARDIR) compile_commands.json


# Compile Commands 
# ----------------
$(LIBTARDIR)/lib$(LIBNAME).a: $(SRCOBJ) | $(LIBTARDIR) 
	ar crsv $(LIBTARDIR)/lib$(LIBNAME).a $(SRCOBJ)

$(LIBTARDIR)/local/lib$(LIBNAME).so: $(SRCOBJ) | $(LIBTARDIR) $(LIBTARDIR)/local
	$(CC) $^ -shared -o $@ -fPIC $(CXXFLAGS)

$(TESTTARDIR)/test_%: $(TESTDIR)/test_%.cpp $(SRCOBJDIR)/%.o $(SRCOBJDIR)/solution.o | $(TESTTARDIR)
	$(CC) $^ -o $@ $(CXXFLAGS) -g $(LDFLAGS) $(LIBS)   

$(SRCOBJDIR)/%.o: $(SRCDIR)/%.cpp | $(SRCOBJDIR)
	$(CC) $^ -o $@ -c $(CXXFLAGS) $(LDFLAGS) $(LIBS)  


# Mkdir Commands 
# --------------
$(SRCOBJDIR):
	mkdir -p $(SRCOBJDIR)

$(LIBTARDIR):
	mkdir -p $(LIBTARDIR)

$(LIBTARDIR)/local:
	mkdir -p $(LIBTARDIR)/local

$(TESTTARDIR): 
	mkdir -p $(TESTTARDIR)
