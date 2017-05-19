/**
 * Daniel Tate
 * COS 241: C++ Data Structures
 * Final Project Address Book-Card Program Using Linked List
 *
 * Header file for AddressBook Class
 */

#ifndef FINALPROJECT_ADDRESSBOOK_H
#define FINALPROJECT_ADDRESSBOOK_H

#include <iostream>
#include "LinkedList.h"


class AddressBook
{
public:
    /**
     * @brief Prompts user for card details and then inserts puts it in
     *        the address book.
     */
    void NewCard();

    /**
     * @brief Prompts user for name of card to delete, then removes that card
     *        from the address book.
     */
    void DeleteCard();

    /**
     * @brief Prompts user for name of card to update. Then prompts user for
     *        what changes to implement, then replaces existing card with
     *        new card in address book.
     */
    void UpdateCard();

    /**
     * @brief Prompts user for name of card to print.
     *        Then prints the card to the screen.
     */
    void PrintCard();

    /**
     * @brief List the names of all the address cards stored
     *        in the address book.
     */
    void ListCards();

    /**
     * @brief Prints birthday cards based on three options:
     *        1: Specific Name
     *        2: Birthday Today
     *        3: Birthday in the next "X" number of days
     */
    void GenBirthCards();

    /**
     * @brief Prints Anniversary cards based on three options:
     *        1: Specific Name
     *        2: Anniversary Today
     *        3: Anniversary in the next "X" number of days
     */
    void GenAnnCards();

    /**
     * @brief Writes out address book to text file specified.
     */
    void SaveBook();

    /**
     * @brief Loads address book from specified text file.
     */
    void LoadBook();

private:
    // main address book object
    LinkedList addressBook;

};


#endif //FINALPROJECT_ADDRESSBOOK_H
