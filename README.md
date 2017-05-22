# Address Book - Card Generator

This program was written as part of my final project for
my C++ Data Structures course. This was a learning project, so if you have 
any constructive feedback or suggestions I would love to hear it!

The program stores address cards consisting of:
1. names
2. addresses
3. phone number
4. birthday dates
5. anniversary dates

The address cards are stored in a linked list and are sorted alphabetically 
by the last name and then the first name. Searches and comparisons also use 
this method as the key when searching and retrieving the cards. 

The program can enter new cards, delete cards, update cards, gernerate
birthday and anniversary cards (displayed to the screen), save the list
to a text file, and load the list from said text file. 

It consist of the following files:

* CardType.h: Header file for CardType class which is the main data type.
* CardType.cpp implementation file for the CardType.
* LinkedList.h General ADT for a sorted LinkedList.
* LinkedList.cpp: LinkedList implementation file. 
* AddressBook.h main AddressBook Class.
* AddressBook.cpp: Implementation file for AddressBook Class. 
* main.cpp: Main driver program.
* addressbook.md: some sample data to test the list with.
* README.md: the readme file...
