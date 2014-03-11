/******************************************************************/
/* Program Assignment:2 */
/* Name: Rey Padilla */
/* Date: February 9 2014 */
/* Description: Counts the total line of codes and then number of
/*              functions, this works only on simple c++ with functions */
/******************************************************************/

#include "locCounter.hpp"
using namespace std;

int main ( int, char* argv[] )
{

  LocCounter counter;
  counter.setFile (argv[1]);
  counter.parse();

  return 0;
}
