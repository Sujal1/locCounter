/******************************************************************/
/* Program Assignment: 2 */
/* Name: Rey Padilla */
/* Date: March 4 2014 */
/* Description: Test the Global LOC
/******************************************************************/


#include <boost/test/minimal.hpp>
#include "locCounter.hpp"

using namespace std;


int test_main( int, char *[] )
{
    //Sample given to us
    LocCounter counter;
    counter.setFile ("cpp_sample2.cpp");
    counter.parse();

    BOOST_CHECK(counter.getLoc()== 8);
    return counter.getLoc() == 8 ? 0: 1;

}
