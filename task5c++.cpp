#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <ctime>

using namespace std;

// Structure to hold book information
struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;
};

// Structure to hold borrower information
struct Borrower {
    string name;
    string borrowedBookISBN;
    time_t borrowDate;
};

// Function to add a book to the library
void addBook(vector<Book>& books) {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter book author: ";
    getline(cin, newBook.author);
    cout << "Enter book ISBN: ";
    getline(cin, newBook.isbn);
    newBook.isAvailable = true;
    books.push_back(newBook);
    cout << "Book added successfully!\n";
}

// Function to search for a book
void searchBook(const vector<Book>& books) {
    string searchTerm;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    for (const auto& book : books) {
        if (book.title == searchTerm || book.author == searchTerm || book.isbn == searchTerm) {
            cout << "Found: " << book.title << " by " << book.author << " (ISBN: " << book.isbn << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No book found with that title, author, or ISBN.\n";
    }
}

// Function to check out a book
void checkoutBook(vector<Book>& books, vector<Borrower>& borrowers) {
    string isbn;
    cout << "Enter ISBN of the book to check out: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto& book : books) {
        if (book.isbn == isbn && book.isAvailable) {
            Borrower newBorrower;
            cout << "Enter borrower's name: ";
            getline(cin, newBorrower.name);
            newBorrower.borrowedBookISBN = isbn;
            newBorrower.borrowDate = time(0);
            borrowers.push_back(newBorrower);
            book.isAvailable = false;
            cout << "Book checked out successfully!\n";
            return;
        }
    }
    cout << "Book not available for checkout.\n";
}

// Function to return a book
void returnBook(vector<Book>& books, vector<Borrower>& borrowers) {
    string isbn;
    cout << "Enter ISBN of the book to return: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto& book : books) {
        if (book.isbn == isbn) {
            book.isAvailable = true;

            // Find the borrower
            for (auto it = borrowers.begin(); it != borrowers.end(); ++it) {
                if (it->borrowedBookISBN == isbn) {
                    // Calculate fine if overdue
                    time_t currentTime = time(0);
                    double seconds = difftime(currentTime, it->borrowDate);
                    double daysOverdue = seconds / (60 * 60 * 24) - 14; // Assuming a 2-week borrowing period
                    if (daysOverdue > 0) {
                        double fine = daysOverdue * 0.50; // $0.50 per day
                        cout << "Book returned. Fine: $" << fine << endl;
                    } else {
                        cout << "Book returned successfully. No fine.\n";
                    }
                    borrowers.erase(it);
                    return;
                }
            }
        }
    }
    cout << "No record of this book being checked out.\n";
}

// Function to display all books
void displayBooks(const vector<Book>& books) {
    cout << "\n--- Library Books ---\n";
    for (const auto& book : books) {
        cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn;
        cout << (book.isAvailable ? " [Available]" : " [Checked Out]") << endl;
    }
}

int main() {
    vector<Book> books;
    vector<Borrower> borrowers;
    int choice;

    while (true) {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Exit\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                searchBook(books);
                break;
            case 3:
                checkoutBook(books, borrowers);
                break;
            case 4:
                returnBook(books, borrowers);
                break;
            case 5:
                displayBooks(books);
                break;
            case 6:
                cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
