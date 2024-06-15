#include<stdio.h>

int binary_search(int* haystack, int needle, int len){
	int low = 0;
	int upp = len - 1;
	
	while(low <= upp){
		int midpoint = low + (upp - low) / 2;
		int midvalue = haystack[midpoint];
		if(needle == midvalue){
			return 1;
		} else if(needle < midvalue){
			upp = midpoint - 1;
		} else{
			low = midpoint + 1;
		}
	}
	return 0;
}

int main(){
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int len = sizeof(array) / sizeof(array[0]);

	if(binary_search(array, 100, len)){
		printf("Found\n");
	} else{
		printf("Not Found\n");
	}
}
