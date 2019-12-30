//
//  delimiters.cpp
//  project1
//
//  Created by Cai Huichuan on 2019-10-01.
//  Copyright © 2019 Cai Huichuan. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string>
#include "project_1.hpp"

// Function declarations
int main();
void print_program();
bool does_delimiter_match(char del);
bool do_delimiters_nest();

//function definition
int main() {
    print_program();
    std::cout << does_delimiter_match('(') << std::endl;
    std::cout << does_delimiter_match('[') << std::endl;
    std::cout << does_delimiter_match('{') << std::endl;
    std::cout << do_delimiters_nest() << std::endl;
    return 0;
}



void print_program()
{
    ece150::start_reading_file();
    do {
        std::cout << ece150::get_next_character();
    } while (!ece150::at_eof());
    std::cout << std::endl;
}


bool does_delimiter_match(char delimiter){
//    a counter to count the number
    int num{0};
    int count{0};
    char origin_del{delimiter};
    char changed_del{};
    char new_delimeter{};
    bool check{true};
//    different assigned value for changed_del according to delimter
    if (origin_del ==  '(') {
        changed_del = ')';
    }
    else if (origin_del == '{'){
        changed_del = '}';
    }
    else if (origin_del == '['){
        changed_del = ']';
    }
    else{
        return false;
    }
    
//   increment and decrement counter:
    ece150::start_reading_file();
    do {
        new_delimeter = ece150::get_next_character();
        if (new_delimeter == origin_del) {
            num += 1;
        }
        else if (new_delimeter == changed_del){
            num -= 1;
            if (num < 0) {
                check = false;
                std::cout << "Unmatched " << changed_del << std::endl;
                num = 0;
            }
        }
        else continue;
    } while (!ece150::at_eof());
    
    
    if (num > 0) {
        check = false;
        std::cout << "Missing ";
//        cout using a loop with several cout missing in a same line
        while (count < num) {
            std::cout << changed_del;
            count +=1;
        }
        std::cout  << std::endl;
    }
//   return the boolean value for check:
//   return true if not in the loop ever
    return check;
}



bool do_delimiters_nest()
{
    ece150::start_reading_file();
    ece150::initialize_table();
    char delimiter{};

    while (!ece150::at_eof()) {
        delimiter = ece150::get_next_character();
//        If it is any opening variables, place it into the table
        if (delimiter == '(' || delimiter == '{' || delimiter == '[') {
            ece150::place_character(delimiter);
        }
//        If it is one of the closing brackets without nested opening: cout << unmatched
        else if(delimiter == ')' ){
            if (ece150::get_right_most_character() != '(') {
                std::cout << "unmatched " << delimiter << std::endl;
            }
            else
            {
                ece150::erase_right_most_character();
            }
        }
        else if(delimiter == '}' ){
            if (ece150::get_right_most_character() != '{') {
                std::cout << "unmatched " << delimiter << std::endl;
            }
            else
            {
                ece150::erase_right_most_character();
            }
        }
        else if(delimiter == ']' ){
            if (ece150::get_right_most_character() != '[') {
                std::cout << "unmatched " << delimiter << std::endl;
            }
            else
            {
                ece150::erase_right_most_character();
            }
        }
    }
 
// check the missing at the end of the file
    if (ece150::at_eof()) {
        if (!ece150::is_table_empty()) {
            std::cout << "missing ";
            do {
//                 erase the rightmost character and loop to cout << missing in a same line.
                if (ece150::get_right_most_character() == '(') {
                    std::cout << ')';
                    ece150::erase_right_most_character();
                }
                if (ece150::get_right_most_character() == '{') {
                    std::cout << '}';
                    ece150::erase_right_most_character();
                }
                if (ece150::get_right_most_character() == '[') {
                    std::cout << ']';
                    ece150::erase_right_most_character();
                }
            } while (!ece150::is_table_empty());
            std::cout << std::endl;
        }
    }
// only if at the end of file and table is empty both is true, return true
    else if (ece150::at_eof() && ece150::is_table_empty())
    {
        return true;
    }
    return 0;
}
