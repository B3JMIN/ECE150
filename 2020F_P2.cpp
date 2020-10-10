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
unsigned int exchange_int_array(unsigned int n, unsigned int size);
unsigned int algo(unsigned int n);
// 8 digits algo
unsigned int algo(unsigned int n){
    for
}


//unsigned int add_checksum( unsigned int n ){
//    unsigned int number[]{ 0 };
//    unsigned int m = n;
//    unsigned int i = 0;
//    unsigned int aftersum = 0;
//    unsigned int aftermultply = 0;
//    unsigned int aftermod = 0;
//    unsigned int result = 0;
//    if (m > 99999999) {
//        return 99999999;
//    }
//    else if (m <= 99999999 && n >= 0) {
//        while (m>0) {
//            number[i] = m % 10;
//            m = m / 10;
//            i++;
//        }
//        for (x = 0, x <= i - 1, x + 2) {
//            if (number[x] * 2 > 9) {
//                number[x] = 1 + (number[x] * 2) % 10;
//            }
//            else { number[x] = number[x] * 2; }
//        }
//        for (x = 0, x < i - 1, x++) {
//            aftersum = aftersum + number[x];
//        }
//        aftermultply = aftersum * 9;
//        aftermod = aftersum % 10;
//        result = n * 10 + aftermod;
//        return result;
//    }
//}


unsigned int add_checksum( unsigned int n ){
    if (n > 0 && n < 9999999){
        unsigned int result[9] = exchange_int_array(n,9);
        unsigned int sum = 0;
        unsigned int res = 0;
        for(int i=0;i<9;i++){
            if (i % 2==0){
                result[i] = result[i] * 2;
                if (result[i] > 9){
                    result[i] = result[i] - 9;
                }
            }
        }
        // step 2
        for(int i=0;i<9;i++){
            sum += result[i];
        }
        // step 3&4
        res = sum * 9 % 10
        return res;
        // todo: return the actual checksum
    }
    else{
        std::cout<< "enter right 9 digits" << std::endl;
        return 0;g
    }
	return 0;
}

// convert int to array
unsigned int exchange_int_array(unsigned int n, unsigned int size){
    unsigned int result[size];
    for(int i =0; i< size;i++){
        result[i] = n / 10;
        n = n % 10;
    }
    return result;
}

bool verify_checksum(unsigned int n){
    if (n > 99999999 ){
        return true;
    }else{
        return false;
    }
}

void add_checksum(unsigned int array[], std::size_t capacity ){
    for (int i=0;i<capacity;i++){
        if (){
            array[i] += 1 // todo: actually modify every digits
        }
        else{
            // todo: set to the maximum integer value
        }
    }
	std::cout << array[capacity -1 ] << std::endl;
}


unsigned int remove_checksum(unsigned int n)
{
    if(){
        // todo:return maximum unsigned integer
    }
    else{
        // todo: without checksum
    }
}

void remove_checksum(unsigned int array[], std::size_t capacity)
{
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



