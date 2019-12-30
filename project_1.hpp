////////////////////////////////////
// Authors: Douglas Harder 
//          Hiren Patel
////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

namespace ece150 {
	std::ifstream file{};
	std::string content{};
	std::size_t next_ch;  // uninitialized

	////////////////////
	// File functions //
	////////////////////

	// Open the file for reading
	void start_reading_file() {
		// If the file is already open, close it
		//  - this is just in case the file changed since the last opening
		if ( file.is_open() ) {
			file.close();
		}

		// Open the file and set the character position to zero
		file.open( "test_code.cpp" );
		next_ch = 0;

		// If the file did not open, indicate an error occurred.
		if (!file.is_open()) {
			std::cerr << "[ERROR]: test_code.cpp not found" << std::endl;
		}

		// Assign to the string the 'content' the contents of the file
		content = std::string( std::istreambuf_iterator<char>( file ),
		                       std::istreambuf_iterator<char>() );
	}

	// See if we are at the end of the string
	bool at_eof() {
		return ( next_ch == content.size() );
	}

	// Get the next character in the string, and increment the index
	char get_next_character() {
		char next{ content.at( next_ch ) };
		++next_ch;
		return next;
	}

	/////////////////////
	// Table functions //
	/////////////////////

	std::vector<char> table(256);

	// Clear the table
	void initialize_table() {
		table.clear();
	}

	// Push the character onto the table
	void place_character( char delimiter ) {
		table.push_back( delimiter );
	}

	// Check if the table is empty
	bool is_table_empty() {
		return table.empty();
	}

	// Return the last character placed onto the table
	//  - the table 
	char get_right_most_character() {
		if ( table.empty() ) {
			return '\0';
		} else {
			return table.back();
		}

	}

	// Remove the last character from the table
	void erase_right_most_character() {
		if ( !table.empty() ) {
			table.pop_back();
		}
	}

	void print_table() {
		std::clog << "[DEBUG]:  table print" << std::endl;

		if ( !table.empty() ) {
			std::clog << table[0];

			for ( std::size_t k{1}; k < table.size(); ++k ) {
				std::clog << ", " << table[k];
			}
		}

		std::clog << std::endl;
	}
};
