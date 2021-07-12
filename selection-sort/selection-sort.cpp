#include <iostream>
#include <vector>
#include <iterator>
#include <cassert>
#include <algorithm>

// selection sort on a vector of integers in place
// sorts in ascending order using less than predicate
// takes O(n^2) time
void selectionSort(std::vector<int>& nums) {
	for (size_t i = 0; i < nums.size() - 1; i++) {
		auto lowestIndex = i;

		for (size_t j = i + 1; j < nums.size(); j++) {
			if (nums[j] < nums[lowestIndex]) {
				lowestIndex = j;
			}
		}

		if (i != lowestIndex) {
			std::swap(nums[i], nums[lowestIndex]);
		}
	}
}

int main()
{
	std::vector<int> vecNums{ 290,130,101,-1,-100,96,85,63,78,44,51,37,33,25,12,2,7,2 };

	std::cout << "vector before sort\n";

	auto vecSize = vecNums.size();

	std::copy(vecNums.begin(), vecNums.end(), std::ostream_iterator<int>{std::cout, ", "});

	selectionSort(vecNums);

	assert(vecSize == vecNums.size());
	assert(std::is_sorted(vecNums.begin(), vecNums.end()));

	std::cout << "\n\nvector after sort\n";

	std::copy(vecNums.begin(), vecNums.end(), std::ostream_iterator<int>{std::cout, ", "});
}
