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

string CardType::GetName()
{
    string name;
    name = fName + " " + lName;
    return name;
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

/**
 * @brief  helper function to check to see if date is in a specific range.
 * @param  objectDate the date to check
 * @param  requestedDate earliest part of the valid range
 * @param  range the latest part of the valid range
 * @return bool, in range or not.
 */
bool CompareDate( tm objectDate, tm requestedDate, int range)
{
    bool inRange;
    int daysInMonth;
    tm maxDate;

    if( range == 0 )
    {
        maxDate = requestedDate;
    }
    else
    {
        maxDate = requestedDate;
        // calculate max date with overflow from month to month
        switch( requestedDate.tm_mon )
        {
            case 1: // February
                if( ((requestedDate.tm_year % 4) != 0) )
                {
                    // not a leap year
                    daysInMonth = 28;
                }
                else if( ((requestedDate.tm_year % 100) == 0)
                         && ((requestedDate.tm_year % 400) != 0))
                {
                    // not a leap year
                    daysInMonth = 28;
                }
                else // is a leap year
                {
                    daysInMonth = 29;
                }
                break;
            case 3: // April
                daysInMonth = 30;
                break;
            case 5: // June
                daysInMonth = 30;
                break;
            case 8: // September
                daysInMonth = 30;
                break;
            case 10: // November
                daysInMonth = 30;
                break;
            default:
                daysInMonth = 31;
                break;
        }

        if( (requestedDate.tm_mday + range) > daysInMonth )
        {
            maxDate.tm_mday = (requestedDate.tm_mday + range) - daysInMonth;
            maxDate.tm_mon++;
        }
        else
        {
            maxDate.tm_mday += range;
        }
    }

    // check to see if date is in range
    if( (objectDate.tm_mon >= requestedDate.tm_mon)
        && (objectDate.tm_mon <= maxDate.tm_mon)
        && (objectDate.tm_mday >= requestedDate.tm_mday)
        && (objectDate.tm_mday >= requestedDate.tm_mday))
    {
        inRange = true;
    }
    else
    {
        inRange = false;
    }
    return inRange;
}

bool CardType::CompareAnniversary( tm date, int range ) const
{
    bool inRange;
    inRange = CompareDate( anniversary, date, range );
    return inRange;
}

bool CardType::CompareBirthday( tm date, int range ) const
{
    bool inRange;
    inRange = CompareDate( birthday, date, range );
    return inRange;
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