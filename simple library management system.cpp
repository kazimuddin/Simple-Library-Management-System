#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued; 
    string issuedTo;  
};

// Function to add a new book
void addBook(vector<Book>& library) {
    Book book;
    cout << "Enter Book ID: ";
    cin >> book.id;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, book.title);
    cout << "Enter Book Author: ";
    getline(cin, book.author);
    book.isIssued = false;
    book.issuedTo = "";
    library.push_back(book);
    cout << "Book added successfully!\n";
}

// Function to search for a book
void searchBook(const vector<Book>& library) {
    int choice;
    cout << "Search by: 1. ID  2. Title\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;
        for (const auto& book : library) {
            if (book.id == id) {
                cout << "Book Found: " << book.title << " by " << book.author << "\n";
                return;
            }
        }
    } else if (choice == 2) {
        string title;
        cout << "Enter Book Title: ";
        getline(cin, title);
        for (const auto& book : library) {
            if (book.title == title) {
                cout << "Book Found: ID " << book.id << ", Author: " << book.author << "\n";
                return;
            }
        }
    }
    cout << "Book not found.\n";
}

// Function to issue a book
void issueBook(vector<Book>& library) {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    for (auto& book : library) {
        if (book.id == id) {
            if (book.isIssued) {
                cout << "Book is already issued to " << book.issuedTo << ".\n";
                return;
            }
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, book.issuedTo);
            book.isIssued = true;
            cout << "Book issued successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Function to return a book
void returnBook(vector<Book>& library) {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    for (auto& book : library) {
        if (book.id == id) {
            if (!book.isIssued) {
                cout << "This book is not currently issued.\n";
                return;
            }
            book.isIssued = false;
            book.issuedTo = "";
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

// Function to list all books
void listBooks(const vector<Book>& library) {
    if (library.empty()) {
        cout << "No books in the library.\n";
        return;
    }

    cout << "List of books:\n";
    cout << "ID\tTitle\t\tAuthor\t\tStatus\n";
    for (const auto& book : library) {
        cout << book.id << "\t" << book.title << "\t\t" << book.author
             << "\t\t" << (book.isIssued ? "Issued" : "Available") << "\n";
    }
}

// Function to delete a book
void deleteBook(vector<Book>& library) {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;
    for (auto it = library.begin(); it != library.end(); ++it) {
        if (it->id == id) {
            library.erase(it);
            cout << "Book deleted successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

int main() {
    vector<Book> library;
    int choice;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Search Book\n3. Issue Book\n4. Return Book\n5. List All Books\n6. Delete Book\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                searchBook(library);
                break;
            case 3:
                issueBook(library);
                break;
            case 4:
                returnBook(library);
                break;
            case 5:
                listBooks(library);
                break;
            case 6:
                deleteBook(library);
                break;
            case 7:
                cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

