/**
 * Daniel Tate
 * COS 241: C++ Data Structures
 * Final Project Address Book-Card Program Using Linked List
 */

#ifndef FINALPROJECT_CARDTYPE_H
#define FINALPROJECT_CARDTYPE_H

#include <string>
#include <ctime>

enum RelationType {LESS, GREATER, EQUAL};
/**
 * Item type that makes up each card in the address book
 */
class CardType
{
public:
    CardType(); // constructor

    /**
     * @brief sets the fName and lName values by splitting input string on space
     * @param string with first name and last name sperated by space
     * @post  fName = first part of string, lName = last part of string
     */
    void SetName( std::string );

    /**
     * @brief sets the street, city, state, and zip of the cardtype
     * @param street address like so: 1600 pennsylvania ave
     * @param city, state, zip each separated by space.
     */
    void SetAddress( std::string, std::string );

    /**
     * @brief sets the phone parameter
     * @param string of the phone number
     */
    void SetPhone( std::string );

    /**
     * @brief sets the anniversary parameter
     * @param takes string in the format "%d-%m-%Y"
     */
    void SetAnniversary( std::string );

    /**
     * @brief sets the birthday parameter
     * @param takes string in the format "%d-%m-%Y"
     */
    void SetBirthday( std::string );

    /**
     * @brief  compares both fName and lName. Prioritizes lName over fName
     * @return if equal = EQUAL, if less = LESS, if greater = GREATER
     */
    RelationType ComparedTo( CardType ) const;

    /**
     * @brief prints the address card to the screen.
     */
    void Print( std::ostream& ) const;

    /**
     * @brief prints the birthday card to ostream&
     */
    void PrintBirthday( std::ostream& ) const;

    /**
     * @brief prints the anniversary card to the ostream&
     */
    void PrintAnniversary( std::ostream& ) const;

private:
    std::string fName;
    std::string lName;
    std::string streetName;
    std::string city;
    std::string state;
    std::string zip;
    std::string phone;
    std::tm anniversary;
    std::tm birthday;
};


#endif //FINALPROJECT_CARDTYPE_H
