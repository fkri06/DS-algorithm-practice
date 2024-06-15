# Implementation of Quick sort using Hoare's partition

def partition_hoare(lo, hi, array: list) -> int:
    pivot_index = hi
    pivot = array[pivot_index]
    hi -= 1

    while(True):
        while array[lo] < pivot:
            lo += 1
        while array[hi] > pivot:
            hi -= 1

        if lo >= hi:
            break
        else:
            array[lo], array[hi] = array[hi], array[lo]
            lo += 1
    array[pivot_index], array[lo] = array[lo], array[pivot_index]
    print(f"Final array = {array} and lo value = {lo}")
    return lo 

def quick_sort(lo, hi, array: list) -> list:
    if hi - lo <= 0:
        return
    partition_index = partition_hoare(lo, hi, array)
    #quick_sort(lo, partition_index - 1, array)
    #quick_sort(partition_index + 1, hi, array)
    return array

array = [5, 3, 1, 7, 6, 9, 10, 2, 4, 8]
print("Unsorted array: ")
print(array)

print("Sorted array: ") 
print(quick_sort(0, len(array) - 1, array))
