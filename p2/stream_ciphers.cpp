//
//  main.cpp
//  p2
//
//  Created by Cai Huichuan on 2019-11-08.
//  Copyright © 2019 Cai Huichuan. All rights reserved.
//
#include <iostream>
#include <cctype>
#include <cmath>
#include <cassert>
bool is_valid_cipertext(char *str);
bool is_valid_plaintext(char *str);
void armour(unsigned char *str, char *changed_str, int index);
void dearmour(char *str, char *changed_str, int index);
int key_to_array(int key, int k);
char *encode(char *plaintext, unsigned long key);
char *decode(char *ciphertext, unsigned long key);
std::size_t string_length(char *str);
#ifndef MARMOSET_TESTING
int main();
#endif

#ifndef MARMOSET_TESTING
int main() {
 char str0[]{ "Hello world!" };
 char str1[]{ "A Elbereth Gilthoniel\nsilivren penna miriel\n"
 "o menel aglar elenath!\nNa-chaered palan-diriel\n"
 "o galadhremmin ennorath,\nFanuilos, le linnathon\n"
 "nef aear, si nef aearon!" }; // [1]
 std::cout << "\"" << str0 << "\"" << std::endl;
 char *ciphertext{ encode( str0, 51323 ) };
 std::cout << "\"" << ciphertext << "\"" << std::endl;
 char *plaintext{ decode( ciphertext, 51323 ) };
 std::cout << "\"" << plaintext << "\"" << std::endl;
 delete[] plaintext;
 plaintext = nullptr;
 delete[] ciphertext;
 ciphertext = nullptr;
 std::cout << "\"" << str1 << "\"" << std::endl;
 ciphertext = encode( str1, 51323 );
 std::cout << "\"" << ciphertext << "\"" << std::endl;
 plaintext = decode( ciphertext, 51323 );
 std::cout << "\"" << plaintext << "\"" << std::endl;
 delete[] plaintext;
 plaintext = nullptr;
 delete[] ciphertext;
 ciphertext = nullptr;
 return 0;
}
#endif


// a helper function to convert key to the binary array[] and it return
// kth bit of the key.
int key_to_array(unsigned long key, int k)
{
    int key_array[64]{0};
    for (int i = 0; i < 64; i++) {
        if (key) {
            key_array[i] = key % 2;
            key /= 2;
        }
        else{
            key_array[i] = 0;
        }
    }
    return key_array[k];
}

// A helper function to find R.


// ACSII armour problem:
// index is a pass by reference value to increment to get the changed_str index
void armour(unsigned char *str, char *changed_str, int index)
{
            int modulo{};
        // Then for every four bytes, we changed it into 5 char and then use a pointer to use it in encode function.
            int base{24};
            unsigned int result{};
            for (int i = 0; i < 4; i++) {
                result += static_cast<unsigned char>(str[i]) << base;
                base -= 8;
            }
    for (int j = 0; j < 5; j++) {
                modulo = result % 85;
                changed_str[index] = modulo + '!';
                index --;
                result /= 85;
            }
}

// A helper function to find the length of char array
std::size_t string_length(char *str)
{
    for (int k{0}; true; k++) {
        if (str[k] == '\0') {
            return k;
        }
    }
}
// A helper function to ensure cipertext
bool is_valid_cipertext(char *str)
{
//    int modulo{static_cast<int>(string_length(str) % 5)};
    if (str[string_length(str)] != '\0') {
        return false;
    }
    for (int i = 0; i < string_length(str)-1; i++) {
        if (str[i] < '!' || str[i] > 'u') {
            return false;
        }
    }
    return true;
}

// A helper function to ensure plaintext
bool is_valid_plaintext(char *str)
{
    int capacity{static_cast<int>(string_length(str))};
    for (int i = 0; i < capacity; i++ ) {
        if (!(std::isprint(str[i])) && !(std::isspace(str[i]))) {
            return false;
            break;
        }
    }
    return true;
}


char *encode(char *plaintext, unsigned long key)
{
    int capacity{static_cast<int>(string_length(plaintext))};
//    The capacity is correct.
    int new_input_capacity{};
    int new_output_capacity{};
    int times{0};
    if (capacity % 4 != 0) {
        new_input_capacity = capacity + (4 - capacity % 4);
    }
    else{
        new_input_capacity = capacity;
    }
    
    times = new_input_capacity / 4;
    new_output_capacity = times * 5;
//   The new_output_capacity is also correct
    char *result_array = new char[new_output_capacity]{};
    char *middle_array = new char[new_input_capacity];
    char *new_plaintext = new char[new_input_capacity];
    for (int i = 0; i < new_input_capacity; i++) {
        new_plaintext[i] = plaintext[i];
        if (i > capacity) {
            new_plaintext[i] = '\0';
        }
    }
    
//  the function get the R
    
    int i {0};
    unsigned char array[256];
    int temp{0};
    for (int x = 0; x < 256; x++) {
        array[x] = x;
    }
    //    scramble the numbers
    int j{0};
    for (int i = 0; i < 256; i++) {
        int k {i%64};
        j = (j + array[i] + key_to_array(key, k)) % 256;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
//    iterate all to get the R
    for (int m = 0 ; m < new_input_capacity; m++) {
        temp = 0;
        i ++;
        i %= 256;
        j = (j +array[i]) % 256;
        temp = array[j];
        array[j] = array[i];
        array[i] = temp;
        int r{(array[i]+ array[j]) % 256};
        int R{array[r]};
        middle_array[m] = new_plaintext[m] ^ R;
    }

    int m = 4;
    for (int i = 0; i < new_input_capacity; i +=4) {
        unsigned char temp[4]{static_cast<unsigned char>(middle_array[i]), static_cast<unsigned char>(middle_array[i+1]),static_cast<unsigned char>(middle_array[i+2]), static_cast<unsigned char>((middle_array[i+3]))};
        armour(temp, result_array, m);
        m +=5;
    }
    result_array[new_output_capacity] ='\0';
    assert(is_valid_cipertext(result_array));
    return result_array;
}














// Decode problem:
char *decode(char *ciphertext, unsigned long key)
{
    
    int capacity{static_cast<int>(string_length(ciphertext))};
    int times = capacity / 5;
    int new_capacity = times * 4;
    char *result_text = new char[new_capacity];
    int m{0};
    unsigned int mid_value{};
//    Here I decide to just code the decipher into the main function
    for (int i = 0; i < capacity; i+=5) {
        char temp[5]{static_cast<char>(ciphertext[i]-'!'), static_cast<char>(ciphertext[i+1]-'!'),static_cast<char>(ciphertext[i+2]-'!'),static_cast<char>(ciphertext[i+3]-'!'),static_cast<char>(ciphertext[i+4]-'!')};
        mid_value = temp[0] * 85 * 85 * 85 * 85 + temp[1] * 85 * 85 * 85 + temp[2] * 85 * 85  + temp[3] * 85  + temp[4];
//        std::cout << mid_value << std::endl;
        result_text[m] = mid_value >> 24 & 0b11111111;
//        std::cout <<  (mid_value >> 24) << std::endl;
//        std::cout <<  (mid_value >> 16)<< std::endl;
//        std::cout <<  (mid_value >> 8) << std::endl;
        result_text[m+1] = mid_value >> 16 & 0b11111111;
        result_text[m+2] = mid_value >> 8 & 0b11111111;
        result_text[m+3] = mid_value & 0b11111111;
//      so the problem is on the increment of m
        m+=4;
    }
//    Now we need to do the R
    int i {0};
    int array[256];
    int temp{0};
    for (int i = 0; i < 256; i++) {
        array[i] = i;
    }
    //    scramble the numbers
    int j{0};
    for (int i = 0; i < 256; i++) {
        int k {i%64};
        j = (j + array[i] + key_to_array(key, k)) % 256;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    for (int k = 0 ; k < new_capacity; k++) {
        temp = 0;
        i ++;
        i %= 256;
        j = (j +array[i]) % 256;
        temp= array[j];
        array[j] = array[i];
        array[i] = temp;
        int r{(array[i]+ array[j]) % 256};
        int R{array[r]};
        
        result_text[k] = result_text[k] ^ R;
    }
    
    assert(is_valid_plaintext(result_text));
    return result_text;
}
