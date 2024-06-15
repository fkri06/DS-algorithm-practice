# Implementation of Quick sort using Lomuto's partition

def partition_lomuto(lo, hi, array: list) -> int:
    pivot = array[hi]
    index = lo

    for j in range(lo, hi):
        print(f"For j = {j} and index = {index} the array is = {array}, and hi = {hi}")
        if array[j] <= pivot:
            array[j], array[index] = array[index], array[j]
            index += 1
    array[hi], array[index] = array[index], array[hi] 
    print(f"Finish partitioning array = {array}, and index = {index}")
    return index 

def quick_sort(lo, hi, array: list) -> list:
    if hi - lo <= 0:
        return
    partition_index = partition_lomuto(lo, hi, array)
    #quick_sort(lo, partition_index - 1, array)
    #quick_sort(partition_index + 1, hi, array)
    return array

array = [5, 3, 1, 7, 6, 9, 10, 2, 4, 8]
print("Unsorted array: ")
print(array)

print("Sorted array: ") 
print(quick_sort(0, len(array) - 1, array))
