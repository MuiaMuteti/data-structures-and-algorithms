#include <vector>
#include <cassert>

// binary search on vector of integers
// uses equality as the predicate
// returns index of the location where the value is found
// otherwise returns -1
// the vector must be sorted for it to work
// runs in O(log n) time
int binarySearch(const std::vector<int>& nums, int val) {
	int start = 0;
	int end = nums.size() - 1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (val == nums[mid]) {
			return mid;
		}
		else if (val < nums[mid]) {
			end = mid - 1;
		}
		else if (val > nums[mid]) {
			start = mid + 1;
		}
	}

	return -1;
}

int main()
{
	std::vector<int> vecNums{ 1,2,3,4,5,6,7,8,9,10 };

	assert(binarySearch(vecNums, 1) == 0);
	assert(binarySearch(vecNums, 7) == 6);
	assert(binarySearch(vecNums, 10) == 9);
	assert(binarySearch(vecNums, 20) == -1);
	assert(binarySearch(vecNums, -5) == -1);
}
