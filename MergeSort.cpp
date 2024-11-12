// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


std::vector<int> merge(std::vector<int>& leftVec, std::vector<int>& rightVec){
	std::vector<int> sortedVec;
	int leftSize = leftVec.size();
	int rightSize = rightVec.size();

	int left = 0;
	int right = 0;

	while (left != leftSize || right != rightSize) {
		
		if (left == leftSize) {
			sortedVec.push_back(rightVec[right]);
			++right;
		}
		else if (right == rightSize) {
			sortedVec.push_back(leftVec[left]);
			++left;
		}
		else if (leftVec[left] <= rightVec[right]) {
			sortedVec.push_back(leftVec[left]);
			++left;
		}
		else if (rightVec[right] <= leftVec[left]) {
			sortedVec.push_back(rightVec[right]);
			++right;
		}
	}
	
	return sortedVec;
}
std::vector<int> splitVector(std::vector<int>& vec, int& left, int& right) {
	std::vector<int> newVector;

	for (int i = left; i < right; ++i) {
		newVector.push_back(vec[i]);
	}
	return newVector;
}


std::vector<int> mergeSort(std::vector<int>& vec) {

	int vecSize = vec.size();
	if (vecSize == 1) {
		return vec;
	}
	
	int start = 0;
	int mid = (vecSize) / 2;

	std::vector<int> leftVector = splitVector(vec, start, mid);

	/*for (int i = 0; i < mid; ++i) {
		leftVector.push_back(vec[i]);
	}*/

	std::vector<int> rightVector = splitVector(vec, mid, vecSize);;

	/*for (int i = mid; i < vecSize; ++i) {
		rightVector.push_back(vec[i]);
	}*/

	

	leftVector = mergeSort(leftVector);
	rightVector = mergeSort(rightVector);


	return merge(leftVector, rightVector);

}


int main()
{

	std::vector<int> vec = { 12, 45, 64, 32, 212, 6, 5, 6, 43, 12, 32, 43, 6, 7, 9, 99, 87, 65, 8, 4};

	vec = mergeSort(vec);

	for (auto e : vec) {
		std::cout << e << ", ";
	}
}

