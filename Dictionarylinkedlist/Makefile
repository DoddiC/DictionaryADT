#-------------------------------------------------------------------------------
# Chidvi Doddi
# cdoddi
# 12B
# July 27th, 2019
# Description: This file is responsible for creating an executable jar file, DictionaryTest, that would be helpful for running the Dictionary.c file, along with the other provided .c files.
#------------------------------------------------------------------------------

# Makefile (macros)


ASSIGNMENT            = pa3
CLIENT                = DictionaryTest
ADT                   = Dictionary
CLIENT_SOURCE         = $(CLIENT).c
CLIENT_OBJECT         = $(CLIENT).o
ADT_SOURCE            = $(ADT).c
ADT_OBJECT            = $(ADT).o
ADT_HEADER_           = $(ADT).h
FLAGS                 = -std=c99 -Wall
FILES                 = $(CLIENT_SOURCE) $(ADT_SOURCE) Makefile README Dictionary.h
SUBMIT                = submit cmps012b-pt.u19 $(ASSIGNMENT)

$(CLIENT) : $(CLIENT_OBJECT) $(ADT_OBJECT)
	gcc -o $(CLIENT) $(CLIENT_OBJECT) $(ADT_OBJECT)

$(CLIENT_OBJECT) : $(CLIENT_SOURCE) $(ADT_HEADER)
	gcc -c $(FLAGS) $(CLIENT_SOURCE)

$(ADT_OBJECT) : $(ADT_SOURCE) $(ADT_HEADER)
	gcc -c $(FLAGS) $(ADT_SOURCE)

clean:
	rm -f $(CLIENT) $(CLIENT_OBJECT) $(ADT_OBJECT)

submit: $(FILES)
	$(SUBMIT) $(FILES)

check:
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.u19/pa3/cdoddi

memcheck:
	valgrind --leak-check=full $(CLIENT)

