#pragma once

#include <vector>

namespace igg {

class Image {
 public:
  ///////////////////// Create the public interface here ///////////////////////
// Constructor(s)
	Image();
	Image(int rows, int cols): rows_{rows}, cols_{cols} {
	data_.reserve(rows * cols +1);	
	}
// Getter
	int rows() const {return rows_;}
	int cols() const {return cols_;}
// Declare of .at function
	// Reference the value
	const int at(int row,int col) const
	// Set the value
	int at(int row,int col);
// Declare Reading and Writing to Disk
	bool FillFromPgm(const std::string& file_name);
	void WriteToPgm(const std::string& file_name);
// Declare Compute Histogram
	std::vector<float> ComputeHistogram(int bins);
 private:
	int rows_ = 0;
	int cols_ = 0;
	int max_val_ = 255;
	std::vector<int> data_;
};

}  // namespace igg
