/* 
 * @file    ListException.h
 *          Addapted from:
 *          Carrano, F. M. (2007). Data Abstraction: The Walls. In M. Hirsch
 *              (Ed.) "Data Abstraction & Problem Solving with C++: Walls and
 *              Mirrors" (5th ed.) pp. 162-163. Boston, MA: Pearson Education,
 *              Inc.
 * @author  Brendan Sweeney, SID 1161837
 * @date    October 25, 2011
 */

#ifndef _LISTEXCEPTION_H
#define	_LISTEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;


class ListException : public logic_error
{
public:
    ListException(const string & message = "")
            : logic_error(message.c_str())
    {
    }
}; // end ListException


#endif	/* _LISTEXCEPTION_H */
