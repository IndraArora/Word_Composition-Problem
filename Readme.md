# Compounded Words Finder

## Overview

This C++ program is designed to find and print the longest and second longest compounded words from a list of words stored in a file. A compounded word is defined as a word that can be constructed by combining at least two shorter words that exist in the given list. The program utilizes a sorting-based approach along with dynamic programming concepts, including the implementation of a Trie data structure, to efficiently find compounded words.

## Approach

### Input Reading

- The program reads the input from a file named Input_01.txt/"Input_02.txt". Each line of the file is considered as a word, and these words are stored in a vector.

### Sorting

- The words are sorted based on their lengths. This sorting ensures that when checking for compounded words, shorter words are considered first.

### Trie Implementation

- Alongside the sorting-based approach, the program implements the logic and concept of a Trie data structure. A Trie (prefix tree) is used to efficiently store and search for words in the list. This allows for faster lookup and validation of whether a word can be compounded from shorter words present in the list.

### Finding Compounded Words

- For each word in the sorted list, the program iterates through its characters to check if it can be split into two or more shorter words. It utilizes the Trie data structure to validate the existence of shorter words in the list. If a split point is found such that both substrings are valid words, it marks the current word as a compounded word and adds it to the list of compounded words.

### Output Printing

- The longest and second longest compounded words are printed along with the time taken by the code to execute.

## Design Decisions

### Comparator Function

- A comparator function is used to sort the words based on their lengths. This ensures that shorter words are considered first during the search for compounded words, potentially improving efficiency.

### Data Structures

- Maps, sets, and Trie data structure are utilized to efficiently store and retrieve information about encountered words, split points, and validate the existence of shorter words.

### Input/Output Optimization

- The program uses `ios_base::sync_with_stdio(false)` and `cin.tie(NULL)` to improve input/output performance by disabling synchronization between C and C++ standard streams.

# Steps to Execution

### 1. Compile the Code

```bash
 g++ -o Word_Composition_Problem.cpp
```

### 2. Prepare Input File:

Ensure that the input file "Input_01.txt"/"Input_02.txt" containing the list of words is available in the same directory as the compiled program.

### 3. Run the Program:

```bash
    ./Word_Composition_Problem.cpp
```

### 4. View Output:

The program will output the longest and second longest compounded words along with the execution time.

# Code Flow Diagram

```mermaid

Read Input from File
│
▼
Sort Words by Length
│
▼
Initialize Trie Data Structure
│
▼
For each word in sorted list:
│
├─── Check if word is compounded:
│   │
│   ▼
│   Iterate over word characters
│   │
│   ├─── Check if current prefix is in Trie:
│   │   │
│   │   ├─── If yes, check if remaining part is in Trie:
│   │   │   │
│   │   │   ├─── If yes, mark as compounded
│   │   │   │
│   │   │   └─── If no, continue
│   │   │
│   │   └─── If no, continue
│   │
│   └─── Update Trie with current word
│
└─── Update Trie with current word

Sort Compounded Words by Length
│
▼
Print Longest and Second Longest Compounded Words
│
▼
Print Time Taken by Code

End


```
