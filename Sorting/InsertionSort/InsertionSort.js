function insertionSort(array){
	for(let index = 1; index < array.length; index++){
		let tempValue = array[index];
		let position = index - 1;

		while(position >= 0 && array[position] > tempValue){
			array[position + 1] = array[position];
			position--;
		}
		array[position + 1] = tempValue;
	}
	return array;
}


let array = [5, 3, 1, 7, 6, 9, 10, 2, 4, 8];
console.log("Unsorted array: ");
console.log(array);

console.log("Sorted array");
console.log(insertionSort(array));
