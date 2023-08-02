       // ***MOVIE TICKET BOOKING SYSTEM***
/* Develop a program that simulates a movie ticket booking system.
Allow users to view movie listings, select seats, make bookings,
and calculate the total cost. Consider implementing seat
availability and seat selection validation. */

#include <iostream>
#include <iomanip>

const int MAX_ROWS = 5;
const int MAX_COLS = 5;
const int TICKET_PRICE = 10;

char seats[MAX_ROWS][MAX_COLS] = {};

void initializeSeats() {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            seats[i][j] = 'O'; // 'O' represents an available seat, 'X' represents a booked seat
        }
    }
}

void displaySeats() {
    std::cout << "  ";
    for (int j = 0; j < MAX_COLS; ++j) {
        std::cout << std::setw(3) << j + 1;
    }
    std::cout << "\n";
    for (int i = 0; i < MAX_ROWS; ++i) {
        std::cout << char('A' + i) << " ";
        for (int j = 0; j < MAX_COLS; ++j) {
            std::cout << std::setw(3) << seats[i][j];
        }
        std::cout << "\n";
    }
}

bool isValidSeat(int row, int col) {
    return (row >= 0 && row < MAX_ROWS) && (col >= 0 && col < MAX_COLS);
}

bool isSeatAvailable(int row, int col) {
    return seats[row][col] == 'O';
}

void bookSeat(int row, int col) {
    seats[row][col] = 'X';
}

int main() {
    initializeSeats();

    while (true) {
        std::cout << "Welcome to the Movie Ticket Booking System\n";
        displaySeats();

        char row;
        int col;

        std::cout << "Enter the row (A-E) and column (1-5) of the seat you want to book (e.g., B3): ";
        std::cin >> row >> col;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        row = std::toupper(row) - 'A';
        col--;

        if (!isValidSeat(row, col)) {
            std::cout << "Invalid seat selection. Please try again.\n";
            continue;
        }

        if (!isSeatAvailable(row, col)) {
            std::cout << "Sorry, the seat is already booked. Please select another seat.\n";
            continue;
        }

        bookSeat(row, col);

        int totalCost = TICKET_PRICE;
        std::cout << "Seat booked successfully! Your total cost is $" << totalCost << "\n";

        char choice;
        std::cout << "Do you want to book another seat? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        if (choice != 'Y' && choice != 'y') {
            break;
        }
    }

    std::cout << "Thank you for using the Movie Ticket Booking System!\n";

    return 0;
}
