def bubble_sort(array: list) -> list:
    for i in range(len(array)):
        for j in range(len(array) - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
    return array

array = [5, 3, 1, 7, 6, 9, 10, 2, 4, 8]

print("Unsorted array: ")
print(array)

print("Sorted array: ")
print(bubble_sort(array))

