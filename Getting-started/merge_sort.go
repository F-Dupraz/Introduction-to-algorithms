package main

import "fmt"

const SIZE int = 100

/*
	This algorithm has some diferences with the original from CLRS book:
	I used slice operations instead of in-place modifications,
	simplified the merge process and
	returns a new sorted slice instead of modifying in-place.

	I LIKE IT WAY MORE IN C BY THE WAY!
*/

func merge(left, right []int) []int {
	var result []int
	result = make([]int, 0, len(left)+len(right))
	
	var i int = 0
	var j int = 0
	for i < len(left) && j < len(right) {
		if left[i] <= right[j] {
			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			j++
		}
	}
	
	result = append(result, left[i:]...)
	
	result = append(result, right[j:]...)
	
	return result
}

func merge_sort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}
	
	var mid int = len(arr) / 2
	var left []int = merge_sort(arr[:mid])
	var right []int = merge_sort(arr[mid:])
	
	return merge(left, right)
}

func main() {
	var unsorted_array [SIZE]int = [SIZE]int{7, 6, 45, 84, 87, 94, 95, 96, 97, 32, 14, 56, 89, 21, 8, 39, 1, 74, 35, 63, 18, 49, 27, 64, 92, 83, 41, 2, 88, 59, 50, 91, 68, 44, 66, 12, 72, 23, 57, 25, 99, 28, 47, 70, 78, 51, 16, 71, 85, 11, 60, 4, 22, 34, 5, 24, 73, 15, 36, 65, 40, 20, 26, 29, 53, 55, 30, 58, 31, 77, 80, 17, 3, 48, 76, 69, 79, 61, 33, 75, 52, 10, 37, 46, 93, 67, 62, 43, 86, 82, 38, 54, 42, 36, 90, 81, 98, 9, 13, 65}

	var sorted_array []int = merge_sort(unsorted_array[:])

	for _, v := range sorted_array {
		fmt.Printf(" %d", v)
	}
}

