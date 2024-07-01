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
        return binarySearch(container,item,0,mid-1);
    }
    
    return binarySearch(container,item,mid+1,right);
}

const size_t BOARD_SIZE = 8;

template <class T>
std::ostream& operator<<(std::ostream& os, std::vector<T> container) {
    for (auto i: container) {
        os << i << " ";
    }
    return os;
}

void printBoard(std::vector<std::vector<std::string>> board) {
    for(int i=0; i<BOARD_SIZE; i++) {
        std::cout << board[i] << std::endl;
    }
}

std::vector<std::vector<std::string>> placeQueen(std::vector<std::vector<std::string>> board, size_t row, size_t column) {
    board[row][column] = "Q";
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][column] != "Q") {
            board[r][column] = "N";
        }
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[row][c] != "Q") {
                board[row][c] = "N";
            }
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
    if(column >= BOARD_SIZE) {
        if (verbose == true) {
            std::cout << "FINAL BOARD:" << std::endl;
            printBoard(board);
        }
        return true;
    }
    else {
        for (int r = 0; r < BOARD_SIZE; r++) {
            if (board[r][column] == "E") {
                std::vector<std::vector<std::string>> new_board = placeQueen(board,r,column);
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
    catch(const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Index of `60`: " << binarySearch(sorted,60,0,sorted.size()-1) << std::endl;
    std::vector<std::vector<std::string>> board(BOARD_SIZE,std::vector<std::string>(BOARD_SIZE,"E"));
    std::cout << "INITIAL BOARD: " << std::endl;
    printBoard(board);
    placeQueens(board,0);
}
