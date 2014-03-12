
/*vector<int> locCounter::getPartsSize()
{
    return v_parts_count;
}*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include "locCounter.hpp"

#include <math.h>
#include <lib.h>
#include <test.h>

using namespace std;

void LocCounter::getPartsName(string line)
{

    if ( line == "{"   ) line = previous_line;

    unsigned pos1 = line.find(" ");
    unsigned pos2 = line.find("(");

    //if not a function but a class
    if (line.find("class") == 0 )
    {
        pos2 = line.find("{");
        v_parts_type.push_back('class');
        parts_counter = 0;
    }
    else
    {
        v_parts_type.push_back('function');
        parts_counter = 1;
    }

    v_parts_name.push_back(line.substr (pos1+1, pos2 - pos1 -1 ));
    v_parts_calls.push_back(0); /*stores how many times this function will be called*/


}

void LocCounter::checkCurlyBraceOpen(string line)
{

    if ( line == "{" || line[line.length()-1] == '{' ){
        //before incrementing curly_brace_open_count, we'll try to get the Parts name
        if (curly_brace_open_count == 0) getPartsName(current_line);
        curly_brace_open_count++;
    }
}

void LocCounter::checkCurlyBraceClose(string line)
{
    if ( line == "}" || line.find("};") != std::string::npos )
    {

        curly_brace_open_count--;

        //store the final value of the Parts counter
        if (curly_brace_open_count == 0 )
        {
             v_parts_calls.push_back(0);
             v_parts_count.push_back(parts_counter);
        }
    }
}

void LocCounter::setFile (string input_data)
{
    filename = input_data;

    unsigned pos1 = input_data.find(".");
    extension = input_data.substr(pos1,input_data.length());


    //if (extension != ".cpp") return false;
   // if (extension != ".cpp")throw std::runtime_error("Requires .cpp extension" );



}

void LocCounter::isCommentStart (string line)
{
    if ( line[0] == '/' && line[1] == '*' ) comment_start = true;
}

void LocCounter::isCommentEnd (string line)
{
    if (comment_start  && line.find("*/") != std::string::npos )  comment_start = false;

}

/******************************************************************/
/* Reuse instructions */
/* bool isLineCountable(string line) */
/* Purpose: Check if the line is countable for LOC */
/* Limitations: does not check the end semi colon */
/* Return true if is countable*/
/******************************************************************/

bool LocCounter::isLineCountable (string line)
{
   if(  line != ""  &&
        comment_start  == false &&
        line  != "private:" &&
        line  != "public:"  &&
        line  != string_curly_brace_open &&
        line  != string_curly_brace_close &&
        line  != string_curly_brace_close +";"  &&
        !(line[0] == '/' && line[1] == '/') &&
        !line.find("#") == 0
                             ) return true;
   else return false;
}

vector<string> LocCounter::getParts()
{
    return v_parts_name;
}

int LocCounter::getLoc()
{
    return loc;
}
void LocCounter::parse()
{


    infile.open(filename.c_str(),ios::binary);

    if (!infile)
    {
        //throw std::runtime_error("File not found" );
    }

    while (!infile.eof())
    {
         getline(infile, current_line);

         //we will use test_line as temporary container where we remove spaces
         test_line = current_line;

         //remove trailing spaces and tabs
         test_line.erase(std::remove(test_line.begin(), test_line.end(), ' '), test_line.end());
         test_line.erase(std::remove(test_line.begin(), test_line.end(), '\t'), test_line.end());

         isCommentStart(test_line);

         //check if the we have an open brace
         checkCurlyBraceOpen(test_line);

         if (isLineCountable(test_line) ){
            loc++;
            if (curly_brace_open_count > 0 )  parts_counter++;
         }
         //checks if it has found a curly brace
         checkCurlyBraceClose(test_line);

         isCommentEnd(test_line); //end of comment
         previous_line  = current_line;
    }

    //loop again to get how many times the part is called
    infile.clear();
    infile.seekg(0, ios::beg);

    while (!infile.eof())
    {
        getline(infile, current_line);
        for (int i =0; i < v_parts_name.size(); i++)
        {
            if (current_line.find(v_parts_name[i] +"(") != string::npos)
            {
                v_parts_calls[i] = v_parts_calls[i] + 1;
            }
        }
    }


    cout << "========================================" << endl;
    cout << "filename: " << filename << endl;
    cout  << "LOC: " << loc << endl;
    cout << "Part  / Number of Items / Part Size" << endl;

    int tmp_counter = 0;
    for (int i =0; i< v_parts_name.size(); i++)
    {
        cout << v_parts_name[i] << "  / " ;
        if (v_parts_type[i] == 'function') cout << v_parts_calls[i] -1 << " / ";
        else cout << v_parts_calls[i]  << " / ";
        cout << v_parts_count[i] << endl;
        tmp_counter = tmp_counter + v_parts_count[i];
    }
    cout << "Global / 0 / " << loc - tmp_counter << endl;

}
