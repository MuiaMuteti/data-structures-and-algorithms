#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


void countingSort(std::vector<int>& input, int placeValue) {
	
	// stores frequency of each value in the place value position
	std::vector<int> temp(10);

	//output vector
	std::vector<int> output(input.size());

	// calculate the frequencies
	for (int i = 0; i < input.size(); i++) {
		temp[(input[i] / placeValue) % 10]++;
	}

	// update the frequencies vector such that each position i,
	// contains number of values equal or less than i
	for (int i = 1; i < temp.size(); i++) {
		temp[i] += temp[i - 1];
	}

	// place each item of the input to the correct position in the output
	for (int i = input.size() - 1; i >= 0; i--) {

		// temp[ (input[i] / placeValue) % 10 ] - 1, gets the zero based index
		output[temp[(input[i] / placeValue) % 10] - 1] = input[i];

		// decrement so that the next duplicate is placed in the correct position
		temp[(input[i] / placeValue) % 10]--;
	}

	// assign sorted vector to input
	input = output;
}

// in place radix sort
void radixSort(std::vector<int>& vec) {
	int max = *std::max_element(vec.begin(), vec.end());

	for (int placeValue = 1; max / placeValue > 0; placeValue *= 10) {
		countingSort(vec, placeValue);
	}
}

int main()
{
	std::vector<int> inputVec{ 909,12,342,654,1023,1,45,488 };

	std::cout << "Input vector not sorted:\n";
	std::copy(inputVec.begin(), inputVec.end(), std::ostream_iterator<int>{std::cout, " "});

	radixSort(inputVec);

	std::cout << "\n\nOutput vector sorted:\n";
	std::copy(inputVec.begin(), inputVec.end(), std::ostream_iterator<int>{std::cout, " "});
}
