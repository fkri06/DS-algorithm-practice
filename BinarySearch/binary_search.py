def binary_search(haystack: list, needle: int):
    low = 0
    upp = len(haystack) - 1

    while low <= upp:
        midpoint = low + (upp - low) // 2
        midvalue = haystack[midpoint]

        if needle == midvalue:
            return {"search_status": "Found", "value": midvalue, "at_index": midpoint}
        elif needle < midvalue:
            upp = midpoint - 1
        else:
            low = midpoint + 1

    return {"search_status": "Not Found"}

array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(binary_search(array, -1))
print(binary_search(array, 1))
print(binary_search(array, 2))
print(binary_search(array, 3))
print(binary_search(array, 4))
print(binary_search(array, 5))
print(binary_search(array, 6))
print(binary_search(array, 7))
print(binary_search(array, 8))
print(binary_search(array, 9))
print(binary_search(array, 10))
print(binary_search(array, 11))
