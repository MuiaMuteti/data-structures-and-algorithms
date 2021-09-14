#include <iostream>
#include <vector>
#include <iterator>

/* merge two sorted vector ranges 
   represented by the range vec[start to mid] and vec[mid+1 to end] end is inclusive
   the range from start to end ends up being sorted
   takes O(n) time
*/
void merge(std::vector<int>& vec, int start, int mid, int end) {
	int length = end - start + 1;

	/* store the sorted result in a temporary
	   if we overwrote the original vector, further comparisons would be made with incorrect values
	*/
	std::vector<int> temp(length);

	int leftStart = start;
	int rightStart = mid + 1;
	int i = 0;

	/*compare values at the start of the vectors and always insert the smallest first*/
	while (leftStart <= mid && rightStart <= end) {
		if (vec[leftStart] <= vec[rightStart]) {
			temp[i++] = vec[leftStart++];
		}
		else {
			temp[i++] = vec[rightStart++];
		}
	}

	while (leftStart <= mid) {
		temp[i++] = vec[leftStart++];
	}
	while (rightStart <= end) {
		temp[i++] = vec[rightStart++];
	}

	std::copy(temp.begin(), temp.end(), vec.begin() + start);
}

/* takes O(nlogn) time */
void mergeSort(std::vector<int>& vec, int start, int end) {
	if (start < end) {
		int mid = (end + start) / 2;
		mergeSort(vec, start, mid);
		mergeSort(vec, mid + 1, end);
		merge(vec, start, mid, end);
	}
}

int main()
{
	std::vector<int> vec{ 7,2,6,3,8,4,5 };

    std::cout << "Vector before sort:\n";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, " "});

	mergeSort(vec, 0, vec.size() - 1);

	std::cout << "\n\nVector after sort:\n";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{std::cout, " "});
}
