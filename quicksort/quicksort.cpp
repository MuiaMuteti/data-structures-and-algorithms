#include <iostream>
#include <vector>
#include <iterator>

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

// sorts the vector in place
// takes O(nlogn) in average and best case, O(n*n) in worst case
void quickSort(std::vector<int>& vec, int start, int end) {
	// return immediately for empty or single element vectors
	if (start < end) {
		int pivot = partition(vec, start, end);
		quickSort(vec, start, pivot - 1);
		quickSort(vec, pivot + 1, end);
	}
}

int main()
{
	std::vector<int> vec{ 2,8,2,7,1,3,5,6,4,2 };

    std::cout << "Before sort\n";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, " "});

	quickSort(vec, 0, vec.size() - 1);
	
	std::cout << "\nAfter sort\n";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, " "});
	
}
