###############################################################
# Program:
#     Assignment 10, Map
#     Brother JonesL, CS 235
# Author:
#     Adam Goff, Aaron Rook, Martin Melerio, Tanner Stratford, Allan Marina
# Summary:
#     Our own custom map data structure.
# Time:
#     <how long did it take to complete this program?>
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment10.o wordCount.o
	g++ -o a.out assignment10.o wordCount.o -g
	tar -cf assignment10.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment10.o : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
assignment10.o: pair.h map.h bst.h assignment10.cpp
	g++ -c assignment10.cpp -g

wordCount.o: map.h bst.h wordCount.h wordCount.cpp 
	g++ -c wordCount.cpp -g
