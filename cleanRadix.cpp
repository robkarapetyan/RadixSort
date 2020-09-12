#include <iostream>

u_int get_max_of_array(const u_int arr[], const u_int& cap){
	u_int max = 0;
	for(u_int i = 0; i < cap; ++i){
		if(arr[i] > max) max = arr[i];
	}
	return max;
}

void count_sort(u_int arr[],const u_int& cap, const u_int& d){
	u_int counter[10] = {0};
	u_int result[cap] = {0};

	for(u_int i = 0; i < cap; ++i){
		counter[ (arr[i]/d)%10 ] ++;
	}

	for(u_int i = 1; i < 10; ++i){
		counter[i] += counter[ i - 1];
	}
	for(u_int i = cap - 1; i > 0; i--){
		result[ --counter[ (arr[i]/d)%10 ]] = arr [i]; 
	}

	for(u_int i = 0; i < cap; ++i){
		arr[i] = result[i];
	}
}

void radix(u_int arr[],const u_int& cap){
	u_int max = get_max_of_array(arr, cap);
	for(int d = 1; max/d > 0; d *= 10){
		std::cout << "  d : " << d ; 
		count_sort(arr, cap, d);
	}
}

int main(){
	
	u_int arr[] = {100, 340, 122, 564, 139 };
	u_int capacity = sizeof(arr)/sizeof(arr[0]);

	radix(arr, capacity);
	for ( u_int i = 0; i < capacity; ++i){
		std::cout << arr[i] << std::endl;
	}
return 0;
}
