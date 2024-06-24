#
# Mark's Magic Makefile
#
# Instructions:
#
# 1. Add .cc files (not .h files) to the line beginning with SRCS = main.cc.
#    Files should be separated with spaces, not commas.  If all of the
#    .cc files in the directory should be included in the build, then you
#    can avoid maintaining a specific list of source files by commenting
#    out the first SRCS line and uncommenting the second (as done below).
# 2. Type 'make depend' to build or update the dependency list.  Do this
#    whenever you add this Makefile or add a .cc or .h file to a project.
# 3. Type 'make' to build the project.
# 4. Type 'make clean' to start over or prepare for submission.  This does
#    not remove the dependency information.
#
# N.B. If you're using files with .cpp extensions, then you need to search
# and replace cc with cpp.
#

CC = g++
CFLAGS = -pg -Wall -std=c++11
#SRCS = main.cpp
SRCS = ${wildcard *.cpp}
OBJS = ${SRCS:.cpp=.o}
INCLS = ${SRCS:.cpp=.h}

p2: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o p2

$(OBJS):
	$(CC) $(CFLAGS) -c $*.cpp

depend: Makefile.dep
	$(CC) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) Makefile Makefile.dep

clean:
	rm -f *.o a.out core

include Makefile.dep


