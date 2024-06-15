function selectionSort(array){
	for(let i = 0; i < array.length; i++){
		let minIndexSofar = i;
		for(let j = i + 1; j < array.length; j++){
			if(array[j] < array[minIndexSofar]){
				minIndexSofar = j;
			}
		}
		if(i !== minIndexSofar){
			let xor = array[i] ^ array[minIndexSofar];
			array[i] = xor ^ array[i];
			array[minIndexSofar] =  xor ^ array[minIndexSofar];
		}
	}
	return array;
}

let array = [5, 3, 1, 7, 6, 9, 10, 2, 4, 8];
console.log("Unsorted array: ");
console.log(array);

console.log("Sorted array: ");
console.log(selectionSort(array));
