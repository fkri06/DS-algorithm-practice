function binarySearch(haystack, needle){
	let low = 0;
	let upp = haystack.length - 1;
	
	while(low <= upp){
		let midpoint = Math.floor(low + (upp - low) / 2);
		let midvalue = haystack[midpoint];

		if(needle === midvalue){
			return {"searchStatus": "Found", "value": midvalue, "atIndex": midpoint};
		} else if(needle < midvalue){
			upp = midpoint - 1;
		} else{
			low = midpoint + 1;
		}
	}
	return {"searchStatus": "Not Found"};
}

let array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
console.log(binarySearch(array, -1));
console.log(binarySearch(array, 1));
console.log(binarySearch(array, 2));
console.log(binarySearch(array, 3));
console.log(binarySearch(array, 4));
console.log(binarySearch(array, 5));
console.log(binarySearch(array, 6));
console.log(binarySearch(array, 7));
console.log(binarySearch(array, 8));
console.log(binarySearch(array, 9));
console.log(binarySearch(array, 10));
console.log(binarySearch(array, 11));
