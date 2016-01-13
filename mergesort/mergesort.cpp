#include <iostream>
#include <array>

struct elem_slice {
	int size;
	int arr[9];
};

elem_slice merge(int l[], int lsize, int r[], int rsize) {
	//std::cout << "In merge method lsize"<< lsize << ", rsize: " << rsize << std::endl;
	int totalSize = lsize + rsize;
	int counter = 0;
	int lind = 0;
	int rind = 0;
	struct elem_slice sl;
	sl.size = totalSize;
	
	while(counter < totalSize){
		if(lind == lsize){
			sl.arr[counter] = r[rind];
			rind++; 
		} else if(rind == rsize){
			sl.arr[counter] = l[lind];
			lind ++;
		} else if(l[lind] < r[rind]){
			sl.arr[counter] = l[lind];
			lind ++;
		} else {
			sl.arr[counter] = r[rind];
			rind ++;
		}
		counter ++;
	}
	
	return sl;
}

elem_slice mergeSort(int arr[], int len){
	//std::cout << "In mergeSort method: "<< len << std::endl;
	if(len > 1){
		// Create new arr
		int leftSize = (int) len / 2;
		int left[leftSize];
		//std::cout << "Left Array length: " << leftSize << std::endl;
		int li = 0;
		int rightSize = (int) len - leftSize;
		//std::cout << "Right Array length: " << rightSize << std::endl;
		int right[rightSize];
		int ri = 0;
		for(int i = 0; i < len; i++){
			if(i < len/2) {
				//std::cout << "Setting left array value: " << arr[i] << std::endl;
				// This is the left array
				left[li] = arr[i];
				li ++;
			} else {
				//std::cout << "Setting right array value: " << arr[i] << std::endl;
				// This is the right array
				right[ri] = arr[i];
				ri ++;
			}
		}
		struct elem_slice ls = mergeSort(left, leftSize);
		struct elem_slice rs = mergeSort(right, rightSize);
		return merge(ls.arr, ls.size,rs.arr, rs.size);
	} else {
		struct elem_slice sl;
		sl.size = len;
		sl.arr[0] = arr[0];
		return sl;
	}
}

void print_sorted_array(struct elem_slice sl) {
	std::cout << "Printing Sorted Array: " << std::endl;
	for(int i = 0; i < sl.size; i++){
		std::cout << sl.arr[i] << std::endl;
	}
}

int main(){
	std::cout << "In Mergesort Main" << std::endl;
	int arr[] = {6,5,3,1,8,7,2,4,9};
	struct elem_slice sorted_slice = mergeSort(arr, 9);
	print_sorted_array(sorted_slice);
	std::cout << "Printing another slice" << std::endl;
	int arr2[] = {0,5,2,1,2,7,2,4,9};
	struct elem_slice sorted_slice2 = mergeSort(arr2, 9);
	print_sorted_array(sorted_slice2);
	
	return 0;
}