#include <iostream>
#include <vector>
#include <iterator>

// insertion sort on a vector of integers in place
// sorts in ascending order using less than predicate
// takes O(n*n) time
void insertionSort(std::vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++) {
		auto temp = nums[i];
		auto position = i - 1;

		while (position >= 0) {
			if (nums[position] > temp) {
				nums[position + 1] = nums[position];
				--position;
			}
			else {
				break;
			}
		}

		nums[position + 1] = temp;
	}
}

int main()
{
	std::vector<int> vecNums{ 290,130,101,-1,-100,96,85,63,78,44,51,37,33,25,12,2,7,2 };

	std::cout << "vector before sort\n";

	std::copy(vecNums.begin(), vecNums.end(), std::ostream_iterator<int>{std::cout, ", "});

	insertionSort(vecNums);

	std::cout << "\n\nvector after sort\n";

	std::copy(vecNums.begin(), vecNums.end(), std::ostream_iterator<int>{std::cout, ", "});

}
