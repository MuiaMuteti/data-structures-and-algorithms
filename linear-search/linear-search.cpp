#include <iostream>
#include <vector>
#include <cassert>

// linear search on a vector of integers
// uses equality as the predicate
// return index of the location where the value is found
// otherwise return -1
int linearSearch(const std::vector<int>& nums, int val) {

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == val) {
			return i;
		}
	}

	return -1;
}

int main()
{
	std::vector<int> vecNums{ 1,2,3,4,5,6,7,8,9,10 };

	assert(linearSearch(vecNums, 1) == 0);
	assert(linearSearch(vecNums, 7) == 6);
	assert(linearSearch(vecNums, 10) == 9);
	assert(linearSearch(vecNums, 20) == -1);
	assert(linearSearch(vecNums, -5) == -1);
}
