/**
 * @file    eenyMeeny.cpp
 * Purpose  To determine who would survive if an arbitrary number of people
 *          stood in a circle and, starting from the first, a chosen number
 *          were skipped before one was killed, continuing around the circle
 *          until only one person remained.
 * @author  Brendan Sweeney, SID 1161837
 * @date    October 25, 2011
 */

#include <cstdlib>
#include <iostream>
#include "WhittleList.h"

using namespace std;

/** Determine the winner in a game of eeny, meeny, miny, moe. Input is taken
 *  from cin. count is the number of people to represent in a circle and skip
 *  is the number to skip before someone is eliminated. Output is a single
 *  integer stating the initial position of the winner.
 */
int main(int argc, char** argv)
    throw(ListException)
{
    WhittleList eenyMeeny;  // our circle

    // count is the number of items in the list; skip is the number to skip
    // before removing an item form the lsit; 0 0 exits program
    int count, skip;        // must be >= 0, count should be > 0.

    cin >> count >> skip;
    while(count || skip)    // terminate when both count and skip are 0
    {
        if (count > 0)
        {
            try
            {
                eenyMeeny.populate(count);
            }
            catch(ListException e)
            {
                throw ListException(
                        "ListException: eenyMeeny cannot allocate memory.");
            } // try
            cout << eenyMeeny.whittle(skip) << endl;
        }
        else
        {
            cout << 0 << endl;      // no players, no winner
        } // end if (count > 0)

        cin >> count >> skip;
    } // end while(count || skip)

    return (EXIT_SUCCESS);
} // end main
