def insertion_sort(array: list):
    for index in range(1, len(array)):
        temp_value = array[index]
        position = index - 1

        while position >= 0 and array[position] > temp_value:
            array[position + 1] = array[position]
            position -= 1

        array[position + 1] = temp_value
    return array

array = [5, 3, 1, 7, 6, 9, 10, 2, 4, 8]
print("Unsorted array: ")
print(array)
print("Sorted array: ")
print(insertion_sort(array))

