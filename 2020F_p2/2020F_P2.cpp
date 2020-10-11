//
//  main.cpp
//  checksum
//
//  Created by Cai Huichuan on 2020-10-10.
//

#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
#endif

unsigned int add_checksum( unsigned int n );
void add_checksum(unsigned int array[], std::size_t capacity );
bool verify_checksum(unsigned int n);
unsigned int remove_checksum( unsigned int n );
void remove_checksum( unsigned int array[], std::size_t capacity );

// calculate for 8 digits checksum
unsigned int add_checksum( unsigned int n ){
    if (n > 0 && n < UINT_MAX){
        unsigned int result[8];
        unsigned int sum = 0;
        unsigned int res = 0;
        // initialize the array
        for(int i =7; i>0;i--){
            result[i] = n / 10 ;
            n = n * 10;
        }
        // step 1
        for(int i=0;i<7;i++){
            if (i % 2==0){
                // step 1.a
                result[i] = result[i] * 2;
                // step 1.b
                if (result[i] > 9){
                    result[i] = result[i] - 9;
                }
            }
        }
        // step 2
        for(int i=0;i<7;i++){
            sum += result[i];
        }
        // step 3&4
        res = n * 10 + sum * 9 % 10;
        return res;
    }
    else{
        return UINT_MAX;
    }
}


bool verify_checksum(unsigned int n){
    if (n <UINT_MAX && add_checksum(n / 10) == n){
        return true;
    }else{
        return false;
    }
}

// add checksum for each entry
void add_checksum(unsigned int array[], std::size_t capacity ){
    for (int i=0;i<capacity-1;i++){
        add_checksum(array[i]);
    }

    std::cout << array[capacity -1] << std::endl;
}

unsigned int remove_checksum(unsigned int n)
{
    if(n>UINT_MAX || !verify_checksum(n)){
        return UINT_MAX;
    }
    else{
//        return the first 8 digits
        return n / 10;
    }
}

void remove_checksum(unsigned int array[], std::size_t capacity)
{
    for(int i =0; i<capacity;i++)
    {
        remove_checksum(array[i]);
    }
    // todo: modify each entry of the array
}

#ifndef MARMOSET_TESTING
int main() {
    unsigned int value_to_protect{21352411};
    unsigned int protected_value = add_checksum(value_to_protect);

    std::cout << "The value " << value_to_protect  << " with the checksum added is "
            << protected_value << "." << std::endl;

    if (verify_checksum(protected_value)) {
        std::cout << "The checksum is valid." << std::endl;
    }

    else   {
        std::cout << "The checksum is invalid." << std::endl;
    }

    std::size_t qty_values {3};
    unsigned int value_series[qty_values] {20201122, 20209913, 20224012};

    add_checksum(value_series, qty_values);
    std::cout << "Series with checksums added: ";

    for (std::size_t series_index {0}; series_index < qty_values; series_index++){
        std::cout << value_series[series_index] << " ";
    }
    std::cout << std::endl;

    return 0;
}
#endif



