/**
 * Daniel Tate
 * COS 241: C++ Data Structures
 * Final Project Address Book-Card Program Using Linked List
 *
 * Implementation file for LinkedList.h
 */

#include <iostream>
#include "LinkedList.h"

struct NodeType
{
    CardType info;
    NodeType* next;
};

LinkedList::LinkedList()
{
    length = 0;
    listStart = NULL;
}

void LinkedList::MakeEmpty()
{
    NodeType* tempPtr;
    while( listStart != NULL )
    {
        tempPtr = listStart;
        listStart = listStart->next;
        delete tempPtr;
    }

    length = 0;
}

bool LinkedList::IsFull() const
{
    NodeType *location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

int LinkedList::GetLength() const
{
    return length;
}

CardType LinkedList::GetItem(CardType &item, bool &found)
{
    bool moreToSearch;
    NodeType* location;

    location = listStart;
    found = false;
    moreToSearch = (location != NULL);

    while( moreToSearch && !found )
    {
        switch( item.ComparedTo( location->info ) )
        {
            case GREATER:
                location = location->next;
                moreToSearch = ( location != NULL );
                break;
            case EQUAL:
                found = true;
                item = location->info;
                break;
            case LESS:
                moreToSearch = false;
                break;
        }
    }
    return  item;
}

void LinkedList::PutItem( CardType item )
{
    // Inserts alphabetically
    NodeType* newNode;
    NodeType* predLoc;
    NodeType* location;
    bool moreToSearch;
    location = listStart;
    predLoc = NULL;
    moreToSearch = ( location != NULL );

    while( moreToSearch ) // find where to insert the new node
    {
        switch( item.ComparedTo(location->info))
        {
            case GREATER:
                predLoc = location;
                location = location->next;
                moreToSearch = ( location != NULL );
                break;
            case LESS:
                moreToSearch = false;
                break;
        }
    }

    newNode = new NodeType;
    newNode->info = item;

    //insert new node
    if( predLoc == NULL ) // insert at beginning of list
    {
        newNode->next = listStart;
        listStart = newNode;
    }
    else // insert elsewhere in list.
    {
        newNode->next = location;
        predLoc->next = newNode;
    }

    length++;
}

void LinkedList::DeleteItem(CardType item)
{
    NodeType* predloc;
    NodeType* location;
    bool moreToSearch;
    location = listStart;
    predloc = NULL;
    moreToSearch = ( location != NULL);

    while( moreToSearch )
    {
        switch( item.ComparedTo(location->info) )
        {
            case GREATER:
                predloc = location;
                location = location->next;
                moreToSearch = ( location != NULL );
                break;
            case LESS:
                moreToSearch = false;
                break;
            case EQUAL:
                if( predloc == NULL )
                {
                    listStart = listStart->next;
                }
                else
                {
                    predloc->next = location->next;
                }
                delete location;
                moreToSearch = false;
                length--;
                break;
        }
    }
}

void LinkedList::ResetList()
{
    currentPos = NULL;
}

CardType LinkedList::GetNextItem()
{
    CardType item;
    if( currentPos == NULL )
    {
        currentPos = listStart;
    }
    else
    {
        currentPos = currentPos->next;
    }
    item = currentPos->info;
    return  item;
}

LinkedList::~LinkedList()
{
    NodeType* tempPtr;

    while( listStart != NULL )
    {
        tempPtr = listStart;
        listStart = listStart->next;
        delete tempPtr;
    }
}
