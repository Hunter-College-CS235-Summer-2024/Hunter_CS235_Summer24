/**
 * @file recursion.cpp
 * @author Sadab Hafiz (sh3646@hunter.cuny.edu)
 * @brief Example recursive functions
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

std::string reverseString(std::string str){
    if (str.length() == 0) {
        return "";
    }
    return reverseString(str.substr(1)) + str[0];
}

template <class T>
size_t binarySearch(const std::vector<T>& container, const T& item, size_t left, size_t right) {
    if (left > right) {
        throw std::out_of_range("The `item` doesn't exist in the `container`.");
    }
    size_t mid = left + ((right-left) / 2);
    
    if (container[mid] == item) {
        return mid;
    }
    
    if (item < container[mid]) {
        return binarySearch(container,item,left,mid-1);
    }
    
    return binarySearch(container,item,mid+1,right);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& container) {
    for (auto i: container) {
        os << i << " ";
    }
    return os;
}

const size_t BOARD_SIZE = 8;

// "N" represents invalid position where a placed queen can go
// "E" represents an empty valid position
// "Q" represents a position with a queen
void printBoard(std::vector<std::vector<std::string>> board) {
    for(int i=0; i<BOARD_SIZE; i++) {
        std::cout << board[i] << std::endl;
    }
}

std::vector<std::vector<std::string>> placeQueen(std::vector<std::vector<std::string>> board, size_t row, size_t column) {
    // place a queen at specified position
    board[row][column] = "Q";
    for (int r = 0; r < BOARD_SIZE; r++) {
        // set vertical rows to "N"
        if (board[r][column] != "Q") {
            board[r][column] = "N";
        }
        for (int c = 0; c < BOARD_SIZE; c++) {
            // set horizontal rows to "N"
            if (board[row][c] != "Q") {
                board[row][c] = "N";
            }
            // set diagonal rows to "N"
            if (abs(r - row) == abs(c - column)) {
                if (board[r][c] != "Q") {
                    board[r][c] = "N";
                }
            }
        }
    }
    return board;
}

bool placeQueens(std::vector<std::vector<std::string>> board, size_t column, bool verbose = true) {
    // base case: if column goes upto BOARD_SIZE, we have placed a queen upto that column
    if(column >= BOARD_SIZE) {
        // print the final state of the board if verbose is true
        if (verbose == true) {
            std::cout << "FINAL BOARD:" << std::endl;
            printBoard(board);
        }
        return true;
    }
    else {
        // iterate through each row of the current column
        for (int r = 0; r < BOARD_SIZE; r++) {
            // try placing a queen if current row is empty
            if (board[r][column] == "E") {
                std::vector<std::vector<std::string>> new_board = placeQueen(board,r,column);
                // return true if the rest of the board can also be solved
                if (placeQueens(new_board,column+1,verbose)) {
                    return true;
                }
            }
        }
        return false;
    }
}

int main() {
    std::string query = "badaS";
    std::cout << reverseString(query) << std::endl;
    std::vector<int> sorted = {10,20,30,40,50,60,70,80,90};
    std::cout << sorted << std::endl;
    try {
        std::cout << binarySearch(sorted,100,0,sorted.size()-1) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Index of `60`: " << binarySearch(sorted,60,0,sorted.size()-1) << std::endl;
    std::vector<std::vector<std::string>> board(BOARD_SIZE,std::vector<std::string>(BOARD_SIZE,"E"));
    std::cout << "INITIAL BOARD: " << std::endl;
    printBoard(board);
    placeQueens(board,0);
}
