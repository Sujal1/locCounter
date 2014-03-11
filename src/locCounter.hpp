/******************************************************************/
/* Program Assignment:2 */
/* Name: Rey Padilla */
/* Date: February 9 2014 */
/* Description: Counts the total line of codes and then number of
/*              functions, this works only on simple c++ with functions */
/******************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

/******************************************************************/
/* Reuse instructions */
/* LocCounter counter */
/* Purpose: to count the LOC  */
/* Limitations: semicolons should be in 1 line  */
/* Return in table format */
/******************************************************************/
class LocCounter{
    string filename;
    ifstream infile;
  public:
    void parse();
    void setFile (string);
    int getLoc ();
    vector<string> getParts();
    //vector<int> getPartsSize();

    bool isLineCountable(string);
  private:
     vector<string> v_parts_name;
     vector<int> v_parts_count;
     vector<int> v_parts_calls;
     vector<int> v_parts_type;
     string current_line;
     string test_line;
     string string_curly_brace_open = "{";
     string string_curly_brace_close = "}";
     string previous_line;
     string extension;

     //counts the number of open brace
     int curly_brace_open_count = 0;
     int loc = 0;

     //count the LOC for the parts we are in
     int parts_counter = 0;

     //true when a comment start is found
     bool comment_start;

     void isCommentStart(string);
     void isCommentEnd(string);
     void checkCurlyBraceOpen(string);
     void checkCurlyBraceClose(string);
     void getPartsName(string);

};
