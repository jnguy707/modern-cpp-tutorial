#include <vector>
#include "io_tools.h"
#include "image.h"

namespace igg {
// Getter Functions of Value
// Assuming row and col are zero index based for referencing
	const int Image::at(row,col) const {
	return data_[row * cols_ + col];
	}
// Setter Function
	int Image:: at(int row, int col){
	return data_[row *cols_ + col];
	}
// Reading from Disk
	bool FillFromPgm(const std::string& file_name){
	// Read the Pgm file from io_tools library
	io_tools::ImageData image = io_tools::ReadFromPgm(file_name)
	// Checking if file was read and imported
	if (image.data.empty()){
		std::cout << "Data was not read." << std::endl;
		return false;
	}

	// Transfering Data to image object
	rows_ = image.rows;
	cols_ = image.cols;
	max_vals_ = image_max_val;
	data_.assign(image.data.begin(),image.data.end());

	return true;
	}
// Writing from Disk
	void WriteToPgm(const std::string& file_name){
	// Using struct defined in io_tools.h, make a struct and initialize the variables with the private members of image.h
	// Create an image objective
	io_tools::ImageData image{
	rows_;
	cols_;
	max_val_;
	data_;
	};
	// Checking if Data was written
	if(bool io_tools::WriteToPgm(image,file_name)){
		std::cout << "Data write: Sucessful" << std::endl;
	else
		std::cout << "Data write: Failed" << std::endl;
	}

	}

}
