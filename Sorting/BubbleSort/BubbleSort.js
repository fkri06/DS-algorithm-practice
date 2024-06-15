function bubbleSort(array){
	for(let i = 0; i < array.length; i++){
		// if(i == 1) return;
		for(let j = array.length - 1; j >= 0 + i; j--){
			console.log(`for i = ${i} and j = ${j} = ${array}`);
			if(array[j] > array[j + 1]){
				let xor = array[j] ^ array[j + 1];
				array[j] = xor ^ array[j];
				array[j + 1] = xor ^ array[j + 1]
			}
		}
	}
	return array;
}

let array = [5, 3, 1, 7, 6, 9, 10, 2, 4, 8];
console.log(`Array length = ${array.length}`);
console.log("Unsorted array: ");
console.log(array);

console.log("Sorted array: ");
console.log(bubbleSort(array));

