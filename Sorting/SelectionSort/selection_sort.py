def selection_sort(array: list):
    for i in range(len(array)):
        min_index_sofar = i;
        for j in range(i + 1, len(array)):
            if array[j] < array[min_index_sofar]:
                min_index_sofar = j
        if i != min_index_sofar:
            array[min_index_sofar], array[i] = array[i], array[min_index_sofar]
    return array

array = [5, 3, 1, 7, 6, 9, 10, 2, 4, 8]
print("Unsorted array: ")
print(array)

print("Sorted array: ")
print(selection_sort(array))
