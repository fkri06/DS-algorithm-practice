/*
 * Quick sort implementation using Lomuto partition scheme.
 *
 * */

function partitionLomuto(lo, hi, array){
	let pivot = array[hi];
	let index = lo;

	for(let j = lo; j < hi; j++){
		if(array[j] <= pivot){
			let temp = array[j];
			array[j] = array[index];
			array[index] = temp;
			index++;
		}
	}
	let temp = array[index];
	array[index] = array[hi];
	array[hi] = temp;

	return index;
}

function quickSort(lo, hi, array){
	if(hi - lo <= 0) return;
	let partitionIndex = partitionLomuto(lo, hi, array);
	quickSort(lo, partitionIndex - 1, array);
	quickSort(partitionIndex + 1, hi, array);
	return array;
}

let array = [5, 3, 1, 7, 6, 9, 10, 2, 4, 8];

console.log("Unsorted array: ");
console.log(array)

console.log("Sorted array: ");
console.log(quickSort(0, array.length - 1, array))
