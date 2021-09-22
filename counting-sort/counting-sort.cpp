#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// takes an input vector and returns a sorted one
// useful when the integers to be sorted are within a small range [0..k]
// runs in O(n) time
std::vector<int> countingSort(const std::vector<int>& input) {
	// find the largest value in the vector
	int max = *(std::max_element(input.begin(), input.end()));

	// stores frequency of each value in the input vector
	std::vector<int> temp(max + 1);

	//output vector
	std::vector<int> output(input.size());

	// calculate the frequencies
	for (int i = 0; i < input.size(); i++) {
		temp[input[i]]++;
	}

	// update the frequencies vector such that each position i,
	// contains number of values equal or less than i
	for (int i = 1; i < temp.size(); i++) {
		temp[i] += temp[i - 1];
	}

	// place each item of the input to the correct position in the output
	for (int i = input.size() - 1; i >= 0; i--) {

		// temp[ input[i] ] - 1, gets the zero based index
		output[temp[input[i]] - 1] = input[i];

		// decrement so that the next duplicate is placed in the correct position
		temp[input[i]]--;
	}

	return output;
}

int main()
{
	std::vector<int> inputVec{ 1,7,4,9,0,1,2,2,6,3,2,10,5 };

	std::cout << "Input vector not sorted:\n";
	std::copy(inputVec.begin(), inputVec.end(), std::ostream_iterator<int>{std::cout, " "});

	auto outputVec = countingSort(inputVec);

	std::cout << "\n\nOutput vector sorted:\n";
	std::copy(outputVec.begin(), outputVec.end(), std::ostream_iterator<int>{std::cout, " "});
}