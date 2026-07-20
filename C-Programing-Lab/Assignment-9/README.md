# 📊 Assignment-09: Dynamic Array Operations

## 📌 Objective

The objective of this assignment is to implement various operations on a dynamically allocated array using C language. The program demonstrates memory allocation using `malloc()` and `realloc()` while performing insertion, deletion, updating, searching, and displaying array elements. It also compares the performance of Linear Search and Binary Search after sorting the array.

---

## 📝 Problem Statement

Develop a menu-driven Dynamic Array Operations program that performs the following operations:

- Create a dynamic array
- Insert an element
- Delete an element
- Update an element
- Search an element using Linear Search
- Sort the array
- Search an element using Binary Search
- Display all elements

The program should use **Dynamic Memory Allocation**, **Arrays**, **Searching Algorithms**, and **Algorithm Analysis**.

---

## 🛠️ Concepts Used

- Dynamic Memory Allocation (`malloc()`, `realloc()`, `free()`)
- Arrays
- Functions
- Searching Algorithms
- Sorting Algorithms
- Menu-Driven Programming
- Algorithm Analysis

---

## 📋 Algorithm

1. Start the program.
2. Allocate memory for the dynamic array.
3. Display the main menu.
4. Read the user's choice.
5. Perform the selected operation:
   - Insert Element
   - Delete Element
   - Update Element
   - Display Array
   - Linear Search
   - Sort Array
   - Binary Search
6. Repeat until the user selects Exit.
7. Release allocated memory using `free()`.
8. Stop the program.

---

## ⏱️ Time Complexity

| Operation | Time Complexity |
|------------|-----------------|
| Insert (End) | O(1) |
| Insert (Middle) | O(n) |
| Delete | O(n) |
| Update | O(1) |
| Display | O(n) |
| Linear Search | O(n) |
| Bubble Sort | O(n²) |
| Binary Search | O(log n) |

---

## 💾 Space Complexity

**O(n)**

where **n** is the number of elements stored in the dynamic array.

---

## 📂 Project Structure

```
Assignment-09/
│── main.c
│── README.md
└── output.png
```

---

## 🎯 Learning Outcomes

After completing this assignment, you will learn:

- How to use dynamic memory allocation in C.
- Working with `malloc()`, `realloc()`, and `free()`.
- Performing insertion, deletion, and update operations.
- Implementing Linear Search and Binary Search.
- Sorting arrays before Binary Search.
- Understanding the time complexity of common array operations.
- Developing efficient menu-driven applications.

---

## 🚀 How to Run

### Linux / macOS

```bash
gcc main.c -o dynamic_array
./dynamic_array
```

### Windows (MinGW)

```bash
gcc main.c -o dynamic_array.exe
dynamic_array.exe
```

---

## 📸 Output

> Add a screenshot of the program execution as **output.png** inside this folder.

---

## 👨‍💻 Author

**Raj Sharma**

**B.Tech – C Programming & Data Structures Lab**