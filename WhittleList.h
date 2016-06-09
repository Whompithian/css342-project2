/**
 * @file    WhittleList.h
 *          Addapted from:
 *          Carrano, F. M. (2007). Linked Lists. In M. Hirsch (Ed.) "Data
 *              Abstraction & Problem Solving with C++: Walls and  Mirrors"
 *              (5th ed.) pp. 195-197. Boston, MA: Pearson Education, Inc.
 * @author  Brendan Sweeney, SID 1161837
 * @date    October 25, 2011
 */

#ifndef _LINKLIST_H
#define	_LINKLIST_H

#include "ListException.h"
#include "ListIndexOutOfRangeException.h"

typedef int ListItemType;


class WhittleList
{
public:
// Constructors and destructor:

    /** Default constructor.
     */
    WhittleList();

    /** Copy constructor.
     * @param orig  The list to copy.
     */
    WhittleList(const WhittleList& orig);

    /** Destructor.
     */
    virtual ~WhittleList();

// List operations:

    /** Determine if a list is empty.
     * @pre None.
     * @post The list remains unchanged.
     * @return true if there are no nodes in the list, false if the list
     *         contains one or more nodes.
     */
    bool isEmpty() const;
    
    /** Determine the length of a list.
     * @pre None.
     * @post The list remains unchanged.
     * @return The number of nodes in the list, 0 if empty.
     */
    int getLength() const;
    
    /** Insert a new node at a specified index. The node currently at that
     *  index will be placed after the new node.
     * @param index  Location to insert the new node.
     * @param newItem  The data to store in the new node.
     * @pre index is within range of the listed items; there are enough
     *      resources to allocate memory for a new node.
     * @post The list contains a new node at the specified index. The node
     *       formerly at the specified index now follows the new node and
     *       length is updated to count the new node.
     * @throw ListIndexOutOfRangeException  If index lies outside the range of
     *        items in the list.
     * @throw ListException  If there are insufficient resources to allocate
     *        memory for a new node.
     */
    void insert(int index, const ListItemType& newItem)
        throw(ListIndexOutOfRangeException, ListException);
    
    /** Delete a node from a specified index. The node currently after the
     *  index will occupy the index location afterwards.
     * @param index  Location of the node to be removed.
     * @pre index is within range of the listed items.
     * @post The node at the specified location is deleted and its memory
     *       returned to the system. The node that followed the deleted node is
     *       now at index and length is updated to discount the old node.
     * @throw ListIndexOutOfRangeException  If index lies outside the range of
     *        items in the list.
     */
    void remove(int index)
        throw(ListIndexOutOfRangeException);
    
    /** Gets the data item from a node at a specified index.
     * @param index  Location of the node to find.
     * @param dataItem  Reference for the located data.
     * @pre index is within range of the listed items; the node at the desired
     *          index contains data.
     * @post The node at the desired index is found and its data is referenced
     *       by dataItem. The list remains unchanged.
     * @throw ListIndexOutOfRangeException  If index lies outside the range of
     *        items in the list.
     */
    void retrieve(int index, ListItemType& dataItem) const
        throw(ListIndexOutOfRangeException);

    /** Set the list to have a specified number of nodes, each holding its
     *  position as its data.
     * @param count  The number of nodes to appear in the list.
     * @pre There are enough system resources to create count number of nodes.
     * @post The list contains exactly the number of nodes specified. dataItem
     *       for each node is the index of that node in the list.
     * @throw ListException  If there are insufficient resources to allocate
     *        count number of nodes.
     */
    void populate(int count)
        throw(ListException);

    /** Whittle down the list by skipping a set number of nodes, then removing
     *  one. The list is treated as a circle and whittling continues until a
     *  single node remains
     * @param skip  The number of nodes to skip before one is removed.
     * @pre The list already contains at least one node.
     * @post The list contains only one node. That node represents the survivor
     *       in a given variation of the Josephus Problem.
     * @return The dataItem of the remaining node; i.e. the winning position.
     */
    ListItemType whittle(int skip);

private:

    struct ListNode
    {
        ListItemType item;
        ListNode *next;
    }; // end ListNode

    int size;
    ListNode *head;

    /** Get a pointer to a node at a specified index.
     * @param index  Location of the node to find.
     * @pre index is within range of the listed items.
     * @post The ListNode at the desired index is found and the list is
     *       unchanged.
     * @return Pointer to the ListNode at the desired index.
     */
    ListNode *find(int index) const;
}; // end WhittleList

#endif	/* _WHITTLELIST_H */
