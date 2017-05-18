/**
 * Daniel Tate
 * COS 241: C++ Data Structures
 * Final Project Address Book-Card Program Using Linked List
 *
 * implementation file for the CardType
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include "CardType.h"
using namespace std;

CardType::CardType()
{

}

void CardType::SetName( string fullName )
{
    istringstream nameStream( fullName );
    nameStream >> fName >> lName;
}

void CardType::SetAddress( string strAddress, string cityStZip )
{
    streetName = strAddress;
    istringstream localStream( cityStZip );
    localStream >> city >> state >> zip;
}

void CardType::SetPhone( string newPhone )
{
    phone = newPhone;
}

void CardType::SetAnniversary( string newDate )
{
    istringstream date_s( newDate );
    date_s >> get_time( &anniversary, "%d-%m-%Y" );
}

void CardType::SetBirthday( string newDate )
{
    istringstream date_s( newDate );
    date_s >> get_time( &birthday, "%d-%m-%Y" );
}

RelationType CardType::ComparedTo( CardType compVal ) const
{

   if( lName > compVal.lName )
    {
        return GREATER;
    }
    else if( lName < compVal.lName )
    {
        return LESS;
    }
    else if( fName > compVal.fName )
    {
        return GREATER;
    }
    else if( fName < compVal.fName )
    {
        return LESS;
    }
    else
    {
        return EQUAL;
    }
}

void CardType::Print( ostream &stream ) const
{
    stream << setw(13) << "Name: " << fName << " " << lName << endl;
    stream << setw(13) << "Address: " << streetName << endl;
    stream << setw(13) << " " << city << " " << state << " " << zip << endl;
    stream << setw(13) << "Phone: " << phone << endl;
    stream << setw(13) << "Anniversary: " << anniversary.tm_mday
                                          << "/"
                                          << anniversary.tm_mon
                                          << "/"
                                          << anniversary.tm_year
                                          << endl;
    stream << setw(13) << "Birthday: " << birthday.tm_mday
                                       << "/"
                                       << birthday.tm_mon
                                       << "/"
                                       << birthday.tm_year
                                       << endl;
}

void CardType::PrintBirthday( ostream &stream ) const
{
    stream << endl;
    stream << "###################" << endl;
    stream << "# HAPPY BIRTHDAY! #" << endl;
    stream << "###################" << endl;
    stream << "Dear " << fName << " " << lName << ", " << endl;
    stream << "I hope this new year brings a lot of fun and experience!" << endl;
    stream << "Sincerely, " << endl;
    stream << "Daniel T." << endl;
    stream << endl;
}

void CardType::PrintAnniversary( ostream &stream) const
{
    stream << endl;
    stream << "######################" << endl;
    stream << "# HAPPY ANNIVERSARY! #" << endl;
    stream << "######################" << endl;
    stream << "Dear " << fName << " " << lName << ", " << endl;
    stream << "Congratulations on your anniversary today!" << endl;
    stream << "Sincerely, " << endl;
    stream << "Daniel T." << endl;
    stream << endl;
}