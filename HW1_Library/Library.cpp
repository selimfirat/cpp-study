#include "Library.h"


// default constructor
Library::Library()
{
    numBooks = 0;
    books = new Book[0];
}

// destructor
Library::~Library()
{
    numBooks = 0;
    delete[] books;
    books = NULL;
}

// adds book to the library
void Library::addBook( string bookTitle, string publishingHouse, int publishingYear ) {

    // Check for book with duplicate title
    if (bookExists(bookTitle)) {
        cout << "There is already a book named " << bookTitle << ". Please enter another name." << endl;
        return;
    }

    Book *sub = books;
    books = new Book[numBooks + 1];

    for (int i = 0; i < numBooks; i++)
        books[i].initBook(sub[i]);


    books[numBooks].bookTitle = bookTitle;
    books[numBooks].publishingHouse = publishingHouse;
    books[numBooks].publishingYear = publishingYear;

    numBooks++;

    delete[] sub;
    sub = NULL;
}

// removes book from the library
void Library::removeBook( string bookTitle ){

    // If not found
    if (!bookExists(bookTitle)) {
        cout << "The book " << bookTitle << " does not exists. Please enter a valid book title." << endl;
        return;
    }

    Book *sub = books;
    books = new Book[numBooks - 1];

    int ex = 0;
    for (int i = 0; i < numBooks; i++) {
        if (!iequals(sub[i].bookTitle, bookTitle)) {
            books[i - ex].initBook(sub[i]);
        } else {
            ex = 1;
        }
    }


    numBooks--;
    delete[] sub;
    sub = NULL;
}

// adds coauthor to a book with given bookTitle
void Library::addCoauthor( string bookTitle, string coauthorName ){
    for (int i = 0; i < numBooks; i++) {
        if (iequals(books[i].bookTitle, bookTitle)) {
            books[i].addCoauthor(coauthorName);
            return;
        }
    }

    cout << "The book " << bookTitle << " does not exists. Please enter a valid book title." << endl;
}

// removes coauthor from the book with given bookTitle
void Library::removeCoauthor ( string bookTitle, string coauthorName ){
    for (int i = 0; i < numBooks; i++) {
        if (iequals(books[i].bookTitle, bookTitle)) {
            books[i].removeCoauthor(coauthorName);
            return;
        }
    }

    cout << "The book " << bookTitle << " does not exists. Please enter a valid book title." << endl;
}

// displayAllBooks function lists all books already found in the library system.
void Library::displayAllBooks(){
    if (numBooks == 0) {
        cout << "--EMPTY--" << endl;
    } else {
        cout << "Book, publishing year" << endl;
        for (int i = 0; i < numBooks; i++) {
            books[i].displayBook();
        }
    }
}

// displayBook function displays all of the information about a particular book.
void Library::displayBook( string bookTitle ){

    for (int i = 0; i < numBooks; i++) {
        if (iequals(books[i].bookTitle, bookTitle)) {
            books[i].displayDetailedBook();
            return;
        }
    }

    cout << "--EMPTY--" << endl;
}

// displayAuthor function displays all of the information about a particular author.
void Library::displayAuthor( string authorName ){
    bool first = false;

    for (int i = 0; i < numBooks; i++) {
        if (books[i].coauthorExists(authorName)) {
            if (!first){
                cout << authorName << endl;
                first = true;
            }

            books[i].displayBook();
        }
    }

    if (!first)
        cout << "--EMPTY--" << endl;

}

// compares two strings case insensitively
bool Library::iequals(string stringA , string stringB)
{
    transform(stringA.begin(), stringA.end(), stringA.begin(), ::toupper);
    transform(stringB.begin(), stringB.end(), stringB.begin(), ::toupper);

    return (stringA == stringB);
}

// returns whether a book exists
bool Library::bookExists(string bookTitle) {
    for (int i = 0; i < numBooks; i++)
        if (iequals(books[i].bookTitle, bookTitle))
            return true;

    return false;
}
