#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// sort a vector of integers in place using the bubble sort algorithm
// sorts in ascending order using less than predicate
// takes O(n^2) time
void bubbleSort(std::vector<int>& nums) {
	size_t unsortedUntilIndex = nums.size() - 1;
	bool sorted = false;

	while (!sorted) {
		sorted = true;

		for (size_t i = 0; i < unsortedUntilIndex; i++) {
			if (nums[i] > nums[i + 1]) {
				std::swap(nums[i], nums[i + 1]);
				sorted = false;
			}
		}

		unsortedUntilIndex -= 1;
	}
}

int main()
{
	std::vector<int> vecNums{ 290,130,101,-1,-100,96,85,63,78,44,51,37,33,25,12,2,7,2 };

    std::cout << "vector before sort\n";

	std::copy(vecNums.begin(), vecNums.end(), std::ostream_iterator<int>{std::cout, ", "});

	bubbleSort(vecNums);

	std::cout << "\n\nvector after bubble sort\n";

	std::copy(vecNums.begin(), vecNums.end(), std::ostream_iterator<int>{std::cout, ", "});
}