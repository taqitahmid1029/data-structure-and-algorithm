# Data Structures and Algorithms

This repository contains comprehensive implementations of fundamental linked list data structures in the C programming language. Each implementation includes detailed operations for node management, memory allocation, and list traversal. Below is a formal explanation of each linked list variant and the operations they support.

---

## Overview

A linked list is a linear data structure composed of nodes, where each node contains data and a reference (or pointer) to the next node. This collection presents three primary variants of linked lists:

1. **Singly Linked Lists** - Each node maintains a reference to the next node only
2. **Doubly Linked Lists** - Each node maintains references to both the previous and next nodes
3. **Circular Linked Lists** - The last node references the first node, creating a circular structure

For each variant, two implementation approaches are provided:

- **Pointer-to-Pointer Approach** (Versions 1) - Uses double pointers to modify the head pointer directly
- **Return Value Approach** (Versions 2) - Functions return the updated head pointer

---

## Data Structures

### Node Representation

#### Singly Linked List Node
```c
struct Node {
    int data;
    struct Node *next;
};
```
Each node stores an integer value and a pointer to the next node in the sequence.

#### Doubly Linked List Node
```c
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};
```
Each node maintains bidirectional links, enabling traversal in both forward and backward directions.

#### Circular Linked List Node
```c
struct Node {
    int data;
    struct Node *next;
};
```
Structurally identical to singly linked nodes, but the last node's next pointer references the head node, creating a circular topology.

---

## Singly Linked List Operations

### File: singlyLinkedList.c and singlyLinkedList2.c

#### 1. **printList**
Displays all elements in the linked list in sequential order. The function traverses the list from the head node and prints each element followed by an arrow (`->`). When the end of the list is reached, it prints `NULL`.

**Complexity:** O(n) - where n is the number of nodes

#### 2. **numberOfNodes**
Calculates and returns the total count of nodes present in the linked list. This is essential for validating insertion and deletion positions. If the list is empty, it returns zero.

**Complexity:** O(n)

#### 3. **insertBegin**
Inserts a new node at the beginning of the list. The new node becomes the head, and its next pointer references the previous head node. For an empty list, the new node becomes both the head and terminal node.

**Complexity:** O(1) - constant time operation

#### 4. **insertEnd**
Appends a new node at the end of the list. The function traverses to the last node and updates its next pointer to reference the new node. For an empty list, the new node becomes the head.

**Complexity:** O(n)

#### 5. **insertMiddle**
Inserts a new node at a specified position within the list. The function validates the position against the list size and delegates to `insertBegin` or `insertEnd` for boundary positions. For middle positions, it locates the insertion point and adjusts pointers accordingly.

**Complexity:** O(n)

#### 6. **deleteBegin**
Removes the head node from the list. The second node becomes the new head. If the list contains only one node, it becomes empty.

**Complexity:** O(1)

#### 7. **deleteEnd**
Removes the last node from the list. The function traverses to the second-to-last node and updates its next pointer to NULL. Special handling is provided for single-node lists.

**Complexity:** O(n)

#### 8. **deleteMiddle**
Removes a node at a specified position. The function validates the position and either delegates to `deleteBegin` or `deleteEnd` for boundary positions, or locates the target node and updates surrounding pointers.

**Complexity:** O(n)

#### 9. **deleteList**
Deallocates all nodes in the list by iterating through each node, freeing its memory, and moving to the next node. The head pointer is set to NULL upon completion.

**Complexity:** O(n)

---

## Doubly Linked List Operations

### File: doublyLinkedList.c and doublyLinkedList2.c

The doubly linked list maintains all operations from the singly linked list while adding backward traversal capability. Each operation additionally manages the `prev` pointer.

#### 1. **printList**
Identical to singly linked list printing, displaying elements in forward order from head to tail.

**Complexity:** O(n)

#### 2. **numberOfNodes**
Counts total nodes in the list by traversing forward.

**Complexity:** O(n)

#### 3. **insertBegin**
Inserts a new node at the beginning. If the list is non-empty, both the new node's next pointer and the current head's prev pointer are updated accordingly.

**Complexity:** O(1)

#### 4. **insertEnd**
Appends a new node at the end, updating both forward and backward pointers to maintain bidirectional linkage.

**Complexity:** O(n)

#### 5. **insertMiddle**
Inserts at a specified position, updating both the new node's prev and next pointers, as well as the surrounding nodes' pointers.

**Complexity:** O(n)

#### 6. **deleteBegin**
Removes the head node. The new head's prev pointer is set to NULL to maintain list integrity.

**Complexity:** O(1)

#### 7. **deleteEnd**
Removes the last node, properly maintaining the prev pointer of the new last node.

**Complexity:** O(n)

#### 8. **deleteMiddle**
Removes a node at a specified position, ensuring both prev and next pointers of surrounding nodes are correctly updated.

**Complexity:** O(n)

#### 9. **deleteList**
Deallocates all nodes sequentially, freeing memory and maintaining list integrity.

**Complexity:** O(n)

---

## Circular Linked List Operations

### File: circularLinkedList.c and circularLinkedList2.c

Circular linked lists employ a unique topology where the last node references the head node, creating a continuous loop. This eliminates the need for a NULL terminator and enables efficient operations on both ends.

#### 1. **printList**
Displays all elements in the circular structure. The function iterates from the head until it encounters the head pointer again, indicating the list's completion. The output format shows the circular nature by displaying `[back to head: X]`.

**Complexity:** O(n)

#### 2. **numberOfNodes**
Counts nodes by traversing until returning to the head pointer. Single-node lists are handled as a special case since the node's next pointer references itself.

**Complexity:** O(n)

#### 3. **insertBegin**
Inserts a new node at the beginning. For an empty list, the new node's next pointer references itself. For existing lists, the new node is inserted before the current head, and the last node's next pointer is updated to reference the new head.

**Complexity:** O(n) - due to traversal to find the last node

#### 4. **insertEnd**
Appends a new node at the end while maintaining the circular property. The new node's next pointer references the head, and the previous last node's next pointer references the new node.

**Complexity:** O(n)

#### 5. **insertMiddle**
Inserts at a specified position while preserving the circular structure. The function locates the insertion point and adjusts pointers accordingly.

**Complexity:** O(n)

#### 6. **deleteBegin**
Removes the head node. The function updates the last node's next pointer to reference the new head node, maintaining the circular structure.

**Complexity:** O(n) - requires traversal to find the last node

#### 7. **deleteEnd**
Removes the last node. The second-to-last node's next pointer is updated to reference the head, maintaining circularity.

**Complexity:** O(n)

#### 8. **deleteMiddle**
Removes a node at a specified position while preserving the circular topology.

**Complexity:** O(n)

#### 9. **deleteList**
Deallocates all nodes in the circular structure. The function iterates until all nodes are freed.

**Complexity:** O(n)

---

## Implementation Comparison

### Approach 1: Pointer-to-Pointer (Double Pointer)
Files: `singlyLinkedList.c`, `doublyLinkedList.c`, `circularLinkedList.c`

**Advantages:**
- Functions can modify the head pointer directly
- Eliminates the need for return values for list modification
- Cleaner semantics for head manipulation

**Disadvantages:**
- Requires dereferencing double pointers
- Slightly more complex syntax
- May be confusing for programmers unfamiliar with pointer-to-pointer concepts

### Approach 2: Return Value
Files: `singlyLinkedList2.c`, `doublyLinkedList2.c`, `circularLinkedList2.c`

**Advantages:**
- Simpler pointer semantics
- Functional programming style
- Easier to understand for beginners

**Disadvantages:**
- Requires explicit head reassignment after each operation
- Slightly more verbose usage code

---

## Memory Management

All implementations employ dynamic memory allocation using `malloc()` for node creation. Proper deallocation is performed using `free()` to prevent memory leaks. The `deleteList()` function provides complete cleanup of all allocated nodes.

---

## Usage Example

```c
// Create an empty list
struct Node *head = NULL;

// Insert elements
insertBegin(&head, 10);    // head -> 10 -> NULL
insertEnd(&head, 20);      // head -> 10 -> 20 -> NULL
insertEnd(&head, 30);      // head -> 10 -> 20 -> 30 -> NULL

// Print the list
printList(&head);          // Output: 10 -> 20 -> 30 -> NULL

// Delete operations
deleteEnd(&head);          // head -> 10 -> 20 -> NULL

// Cleanup
deleteList(&head);         // Free all nodes, head = NULL
```

---

## Compilation and Execution

Each C file can be compiled independently using GCC:

```bash
gcc singlyLinkedList.c -o singlyLinkedList
./singlyLinkedList

gcc doublyLinkedList.c -o doublyLinkedList
./doublyLinkedList

gcc circularLinkedList.c -o circularLinkedList
./circularLinkedList
```

---

## Conclusion

This repository provides a comprehensive foundation for understanding linked list data structures in C. Each implementation demonstrates core concepts including pointer manipulation, memory management, and algorithmic efficiency. These structures serve as building blocks for more complex data structures such as stacks, queues, and graphs.