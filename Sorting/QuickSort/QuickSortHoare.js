/*
 * Quick sort implementation using Hoare partition scheme.
 *
 * */

function partitionHoare(lo, hi, array){
	let pivotIndex = hi;
	let pivot = array[pivotIndex];
	hi--;

	while(true){
		while(array[lo] < pivot) lo++;
		while(array[hi] > pivot) hi--;
		if(lo >= hi){
			break;
		} else{
			let temp = array[lo];
			array[lo] = array[hi];
			array[hi] = temp;
			lo++;
		}
	}

	let temp = array[lo];
	array[lo] = array[pivotIndex];
	array[pivotIndex] = temp;
	
	return lo;
}

function quickSort(lo, hi, array){
	if(hi - lo <= 0) return;
	let partitionIndex = partitionHoare(lo, hi, array);
	quickSort(lo, partitionIndex - 1, array);
	quickSort(partitionIndex + 1, hi, array);
	return array;
}

let array = [5, 3, 1, 7, 6, 9, 10, 2, 4, 8];

console.log("Unsorted array: ");
console.log(array)

console.log("Sorted array: ");
console.log(quickSort(0, array.length - 1, array))
