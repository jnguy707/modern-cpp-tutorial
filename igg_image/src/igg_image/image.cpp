#include <vector>
#include "image.h"
#include "io_tools.h"

namespace igg {
// Getter Function
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
	max_vals_ = image.max_val;
	data_.assign(image.data.begin(),image.data.end());

	return true;
}//end of FillFromPgm
// Writing from Disk
void WriteToPgm(const std::string& file_name){
	// Create an image object from io_tools.h
 	// Populate struct ImageData (io_tools.h) with class Image
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
}// end of WriteToPgm
// Compute Histogram
std::vector<float> ComputeHistogram(int bins){
	int n = bins;
	// Need to write a sorting algorithm
	// Maybe a for loop, double?
	// Outter for loop keeps track of bin
	// Inner for loop adds to bin number
	// How should I go about using methods of the vector class?
	// First Step: Construct/Allocate memory for vector
	std::vector<float> histogram;
	histogram.reserve(bins);
	// I can easily write some sorting algorithm, but I have the std lib
/*pseudo code
for i = 1:bin
	for ii = 1:sizeofVector
		if ((i-1)*max_val_ =<data_[ii] && data_[ii] =<(i)*max)
		histogram[i] += data_[ii];
		end
	end
*/
// There is a count_if algorithm in std <algorithms>
	for(int i = 0;  i < bin-1; i++){
	}
// I will use std::emplace_back and std::count_if
// Can use a lambda function for a dynamic count_if condition or for/if loop
// Lambda function is a choice for simplicifcation for the count_if condition
}

}
