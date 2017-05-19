/**
 * Daniel Tate
 * COS 241: C++ Data Structures
 * Final Project Address Book-Card Program Using Linked List
 *
 * Implementation file for the AddressBook Class
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "AddressBook.h"

using namespace std;

void AddressBook::NewCard()
{
    CardType newCard;
    string name;
    string address;
    string cityStZip;
    string phone;
    string anniversary;
    string birthday;

    cout << "Please enter the new contact's name like so: firstName lastName"
         << endl;
    cout << "Enter name: ";
    getline( cin, name );

    cout << "Please enter the street address like so: 1600 Pennsylvania Ave \n"
         << "City, State and Zip will be entered next." << endl;
    cout << "Address: ";
    getline( cin, address );

    cout << "Please input the city, state, and zip separated by only spaces:"
         << endl;
    getline( cin, cityStZip );

    cout << "Please enter the phone number: ";
    getline( cin, phone );

    cout << "Please input anniversary date in day-month-year string like:"
         << " 20-05-2017." << endl;
    cout << "Date: ";
    getline( cin, anniversary );

    cout << "Please input birthday date in day-month-year string like:"
         << " 20-05-2017." << endl;
    cout << "Date: ";
    getline( cin, birthday );

    cout << "Adding new card..." << endl;
    newCard.SetName( name );
    newCard.SetAddress( address, cityStZip );
    newCard.SetPhone( phone );
    newCard.SetAnniversary( anniversary );
    newCard.SetBirthday( birthday );
    addressBook.PutItem( newCard );
    cout << "New card added!" << endl;

}

void AddressBook::DeleteCard()
{
    CardType removeCard;
    string name;

    cout << "Who would you like to remove? (firstName lastName):" << endl;
    getline( cin, name );

    removeCard.SetName( name );
    addressBook.DeleteItem( removeCard );
    cout << "Card removed." << endl;
}

void AddressBook::UpdateCard()
{
    CardType updatedCard;
    CardType oldCard; // old card used to remove old card
    string name;
    int choice;
    bool found;

    cout << "Which contact would you like to update? (firstName lastName):"
         <<endl;
    getline( cin, name );

    updatedCard.SetName( name ); // sets name to find card
    oldCard = addressBook.GetItem( updatedCard, found );
    updatedCard = oldCard;

    if( found )
    {
        do
        {
            cout << "What would you like to update? (select number)" << endl;
            cout << "1: Name\n"
                 << "2: Address\n"
                 << "3: Phone number\n"
                 << "4: Anniversary date\n"
                 << "5: Birthday\n"
                 << "6: Cancel/Done" << endl;
            cin >> choice;
            cin.clear();
            cin.get();

            string newName;
            string address;
            string cityStZip;
            string phone;
            string annDate;
            string birthDate;


            switch( choice )
            {
                case 1: // update name
                    cout << "Please enter the new name: ";
                    getline( cin, newName );
                    updatedCard.SetName( newName );
                    break;
                case 2: // update the address
                    cout << "Please enter the street address:";
                    getline( cin, address );
                    cout << "Please enter the city, state, and zip separated by"
                         << "only spaces: " << endl;
                    getline( cin, cityStZip );
                    updatedCard.SetAddress( address, cityStZip );
                    break;
                case 3: // update phone number
                    cout << "Please enter the new phone number:";
                    getline( cin, phone );
                    updatedCard.SetPhone( phone );
                    break;
                case 4: // update anniversary annDate
                    cout << "Please enter new annDate in DD-MM-YYYY format:";
                    getline( cin, annDate );
                    updatedCard.SetAnniversary( annDate );
                    break;
                case 5: // update birthday annDate
                    cout << "Please enter new annDate in DD-MM-YYYY format:";
                    getline( cin, birthDate );
                    updatedCard.SetBirthday( birthDate );
                    break;
            }

        } while( choice != 6 );
        // remove old card
        addressBook.DeleteItem( oldCard );
        // insert updated card
        addressBook.PutItem( updatedCard );
    }
    else
    {
        cout << "That name wasn't found in the address book." << endl;
    }
}

void AddressBook::PrintCard()
{
    CardType toPrint;
    string name;
    bool found;

    cout << "Which contact would you like to print? (firstName lastName):"
         << endl;
    getline( cin, name );
    toPrint.SetName( name );

    // get the contact
    toPrint = addressBook.GetItem( toPrint, found );
    if( found )
    {
        // print header
        cout << "Begin Card:" << endl;
        cout << setfill( '#' ) << setw( 80 ) << "#" << setfill( ' ' ) << endl;

        // print card
        toPrint.Print( cout );

        // print footer
        cout << setfill( '#' ) << setw( 80 ) << "#" << setfill( ' ' ) << endl;
    }
    else
    {
        cout << "That name wasn't found in the address book." << endl;
    }
}

void AddressBook::ListCards()
{
    CardType tempCard;
    int length;

    length = addressBook.GetLength();
    addressBook.ResetList();

    // loop through linked list print the names of each card
    cout << "The address book contains the following names:" << endl;
    for( int i = 1; i <= length; i++ )
    {
        tempCard = addressBook.GetNextItem();
        cout << tempCard.GetName() << endl;
    }
}

void AddressBook::GenBirthCards()
{
    CardType tempCard;
    int choice;
    int range = 0;
    int length = addressBook.GetLength();
    time_t rawTime; // Current system date variable
    tm* todayPtr; // pointer to hold converted system date
    //tm today;

    time( &rawTime ); // get current time
    todayPtr = localtime( &rawTime ); // convert to tm type time/date

    do
    {
        cout << "How would you like to generate the birthday cards?" << endl;
        cout << "1: Make a card for a specific person\n";
        cout << "2: Make all cards for today\n";
        cout << "3: Make all cards for the next X number of days\n";
        cout << "4: Cancel/Done" << endl;
        cin >> choice;
        cin.clear();
        cin.get();

        string name;

        switch( choice )
        {
            case 1: // specific person
                bool found;

                cout << "Which contact do you want to make a card for? "
                     << "(fistName lastName): " << endl;
                getline( cin, name );

                tempCard.SetName( name );
                tempCard = addressBook.GetItem( tempCard, found );
                if( found )
                {
                    tempCard.PrintBirthday( cout );
                }
                else
                {
                    cout << "Could not locate a card for that name" << endl;
                }
                break;
            case 2:
                addressBook.ResetList();
                // loop through all cards in list checking their dates
                for( int i = 1; i <= length; i++ )
                {
                    bool print = false;
                    tempCard = addressBook.GetNextItem();
                    print = tempCard.CompareBirthday( *todayPtr, 0 );
                    if( print )
                    {
                        tempCard.PrintBirthday( cout );
                    }
                }
                break;
            case 3:
                cout << "Please enter the number of days from now for which you"
                     << "would like to print cards up to:" << endl;
                cin >> range;

                addressBook.ResetList();
                // loop through all cards in list checking their dates
                for( int i = 1; i <= length; i++ )
                {
                    bool print = false;
                    tempCard = addressBook.GetNextItem();
                    print = tempCard.CompareBirthday( *todayPtr, range );
                    if( print )
                    {
                        tempCard.PrintBirthday( cout );
                    }
                }
                break;
        }
    } while( choice != 4 );
}

void AddressBook::GenAnnCards()
{
    CardType tempCard;
    int choice;
    int range = 0;
    int length = addressBook.GetLength();
    time_t rawTime; // Current system date variable
    tm* todayPtr; // pointer to hold converted system date
    //tm today;

    time( &rawTime ); // get current time
    todayPtr = localtime( &rawTime ); // convert to tm type time/date

    do
    {
        cout << "How would you like to generate the Anniversary cards?" << endl;
        cout << "1: Make a card for a specific person\n";
        cout << "2: Make all cards for today\n";
        cout << "3: Make all cards for the next X number of days\n";
        cout << "4: Cancel/Done" << endl;
        cin >> choice;
        cin.clear();
        cin.get();

        string name;
        bool found;

        switch( choice )
        {
            case 1: // specific person
                cout << "Which contact do you want to make a card for? "
                     << "(fistName lastName): " << endl;
                getline( cin, name );

                tempCard.SetName( name );
                tempCard = addressBook.GetItem( tempCard, found );
                if( found )
                {
                    tempCard.PrintAnniversary( cout );
                }
                else
                {
                    cout << "Could not locate a card for that name" << endl;
                }
                break;
            case 2:
                addressBook.ResetList();
                // loop through all cards in list checking their dates
                for( int i = 1; i <= length; i++ )
                {
                    bool print = false;
                    tempCard = addressBook.GetNextItem();
                    print = tempCard.CompareAnniversary( *todayPtr, 0 );
                    if( print )
                    {
                        tempCard.PrintAnniversary( cout );
                    }
                }
                break;
            case 3:
                cout << "Please enter the number of days from now for which you"
                     << "would like to print cards up to:" << endl;
                cin >> range;

                addressBook.ResetList();
                // loop through all cards in list checking their dates
                for( int i = 1; i <= length; i++ )
                {
                    bool print = false;
                    tempCard = addressBook.GetNextItem();
                    print = tempCard.CompareAnniversary( *todayPtr, range );
                    if( print )
                    {
                        tempCard.PrintAnniversary( cout );
                    }
                }
                break;
        }
    } while( choice != 4 );
}

void AddressBook::SaveBook()
{
    string fileName;
    ofstream saveFile;
    int length;
    CardType tempCard;

    cout << "Name of file to save to: "; // get file name to write to
    cin >> fileName;
    saveFile.open( fileName ); // open file for saving

    addressBook.ResetList();
    length = addressBook.GetLength();
    for( int i = 1; i <= length; i++ )
    {
        tempCard = addressBook.GetNextItem();
        tempCard.Print( saveFile );
    }
    saveFile.close();
    cout << "File saved" << endl;
}

void AddressBook::LoadBook()
{
    string fileName;
    ifstream openFile;
    CardType tempCard;
    string inputString;
    string tempString;

    cout << "Name of file to load: ";
    getline( cin, fileName );
    openFile.open( fileName );

    // loop through file line by line
    while( getline( openFile, inputString ))
    {
        istringstream tempStream( inputString );
        string lineKey;
        string lineVal;

        tempStream >> lineKey >> lineVal;

        if( lineKey == "Name:") // detect and set name
        {
            tempCard.SetName( lineVal );
        }
        else if( lineKey == "Address:" )
        {
            tempString = lineVal; // set first part of address
        }
        else if( lineKey == ":" )
        {
            tempCard.SetAddress( tempString, lineVal ); // set address
        }
        else if( lineKey == "Phone:" )
        {
            tempCard.SetPhone( lineVal ); // set phone number
        }
        else if( lineKey == "Anniversary:" )
        {
            tempCard.SetAnniversary( lineVal );
        }
        else if( lineKey == "Birthday:" )
        {
            tempCard.SetBirthday( lineVal );
        }
        else
        {
            /** since we know a blank line is inserted after output of each
             *  card, we can use it to submit the tempCard to the list.
             *  This allows us to loop again and create the next card.
             */
            addressBook.PutItem( tempCard );
        }

    }

}
