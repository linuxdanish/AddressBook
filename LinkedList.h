/**
 * Daniel Tate
 * COS 241: C++ Data Structures
 * Final Project Address Book-Card Program Using Linked List
 */

#ifndef FINALPROJECT_LINKEDLIST_H
#define FINALPROJECT_LINKEDLIST_H

#include "CardType.h"
struct NodeType;

/**
 * Linked list implementation
 */
class LinkedList
{
public:
    LinkedList(); // constructor
    ~LinkedList(); // destructor

    /**
     * @brief: Returns the list to the empty state.
     * @post: List is empty
     */
    void MakeEmpty();

    /**
     * @brief: Test to see if the list is full.
     * @pre List has been initialized.
     * @return = (list is full)
     */
    bool IsFull() const;

    /**
     * @brief: Gets the number of elements in the list.
     * @return number of elements in list.
     */
    int GetLength() const;

    /**
     * @brief: Gets the item whose key matches items key if present.
     * @pre    List has been initialized.
     *         Key in item has been initialized
     *         nodeType has comparison operator overloaded.
     * @param  item the item to search for.
     * @param  found = true if found, else = false.
     * @return Item that is found.
     */
    CardType GetItem(CardType &item, bool &found);

    /**
     * @brief  Adds item to the list.
     * @pre    list is not full.
     *         item is not in list.
     * @param  item to add to the list.
     * @post   item has been added to the list.
     */
    void PutItem( CardType item );

    /**
     * @brief Deletes the element whose key matches item's key
     * @param item to delete from the list
     * @post  no element in the list has items key
     */
    void DeleteItem(CardType item);

    /**
     * @brief Initializes current position for an iteration through the list.
     * @post  Current position is prior to list.
     */
    void ResetList();

    /**
     * @brief  Gets the next item in list
     * @return copy of current element.
     * @post   current position is updated to next position.
     */
    CardType GetNextItem();

private:
    NodeType* listStart; // pointer to list
    int length; // length of list
    NodeType* currentPos; // pointer to current position.
};


#endif //FINALPROJECT_LINKEDLIST_H
