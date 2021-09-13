#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// partition the vector or a part of it in place into three parts
// 1.values less or equal to the pivot value
// 2.the pivot value
// 3.values greater than the pivot value
// the pivot value is chosen as the last element
// takes O(n) time
// takes in a reference to the vector, start and end(inclusive) index of the range in the vector
// returns the index of the pivot
int partition(std::vector<int>& vec, int start, int end) {
	int pivotValue = vec[end];

	// the greatest index in the range of values equal 
	// or less than the pivot in the current range
	int leftSide = start - 1;

	for (auto i = start; i < end; i++) {
		if (vec[i] <= pivotValue) {
			++leftSide;
			std::swap(vec[leftSide], vec[i]);
		}
	}

	++leftSide;
	// put pivot in the right place
	std::swap(vec[leftSide], vec[end]);

	return leftSide;
}

// takes a reference to the vector, the zero based index of the value to return,
// the start index and end(inclusive) index of the range in the vector
// return the nth lowest value in the vector without sorting the entire vector
// takes O(n) time
int quickSelect(std::vector<int>& vec, int nthLowestVal, int start, int end) {
	// if range has one element, we have found the element
	if (end - start <= 0) {
		return vec[start];
	}

	int pivot = partition(vec, start, end);

	if (pivot > nthLowestVal) {
		return quickSelect(vec, nthLowestVal, start, pivot - 1);
	}
	else if (pivot < nthLowestVal) {
		return quickSelect(vec, nthLowestVal, pivot + 1, end);
	}
	else {
		return vec[pivot];
	}
}

int main()
{
	std::vector<int> vec{ 3,1,78,4,2,45,3,4,9,45 };

	std::cout << "The values\n";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, " "});

	// select 2nd lowest value
	int secondLowest = quickSelect(vec, 1, 0, vec.size() - 1);
	std::cout << "\n\nSecond lowest value in the vector: " << secondLowest << '\n';

	// select largest value
	int largest = quickSelect(vec, vec.size() - 1, 0, vec.size() - 1);
	std::cout << "\nLargest value in the vector: " << largest << '\n';
}