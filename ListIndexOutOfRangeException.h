/* 
 * @file    ListIndexOutOfRangeException.h
 *          Addapted from:
 *          Carrano, F. M. (2007). Data Abstraction: The Walls. In M. Hirsch
 *              (Ed.) "Data Abstraction & Problem Solving with C++: Walls and 
 *              Mirrors" (5th ed.) p. 162. Boston, MA: Pearson Education, Inc.
 * @author  Brendan Sweeney, SID 1161837
 * @date    October 25, 2011
 */

#ifndef _LISTINDEXOUTOFRANGEEXCEPTION_H
#define	_LISTINDEXOUTOFRANGEEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;


class ListIndexOutOfRangeException : public out_of_range
{
public:
    ListIndexOutOfRangeException(const string & message = "")
            : out_of_range(message.c_str())
    {
    }
}; //end ListIndexOutOfRangeException


#endif	/* _LISTINDEXOUTOFRANGEEXCEPTION_H */
