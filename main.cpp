/**
 * Daniel Tate
 * COS 241: C++ Data Structures
 * Final Project Address Book-Card Program Using Linked List
 *
 * Main driver program
 */

#include <iostream>
#include <iomanip>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook myAddressBook;
    int choice;

    cout << "Welcome to the Address Book Generator Program" << endl;

    do
    {
        cout << endl;
        cout << setw( 80 ) << setfill( '#' ) << "#" << setfill( ' ' ) << endl;
        cout << "Please make a selection from the menu (select number):\n"
             << "1: Enter a new name into the address book\n"
             << "2: Delete a name from the address book\n"
             << "3: Update a contact card\n"
             << "4: List all contact cards\n"
             << "5: View a contact card\n"
             << "6: Generate birthday cards\n"
             << "7: Generate anniversary cards\n"
             << "8: Save address book to file\n"
             << "9: Load address book from file\n"
             << "10: exit program" << endl;
        cin >> choice;
        cin.clear();
        cin.get();

        switch( choice )
        {
            case 1:
                myAddressBook.NewCard();
                break;
            case 2:
                myAddressBook.DeleteCard();
                break;
            case 3:
                myAddressBook.UpdateCard();
                break;
            case 4:
                myAddressBook.ListCards();
                break;
            case 5:
                myAddressBook.PrintCard();
                break;
            case 6:
                myAddressBook.GenBirthCards();
                break;
            case 7:
                myAddressBook.GenAnnCards();
                break;
            case 8:
                myAddressBook.SaveBook();
                break;
            case 9:
                myAddressBook.LoadBook();
                break;
        }
    } while( choice != 10 );


    return 0;
}