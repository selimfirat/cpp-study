#include "Book.h"

// constructor with args
Book::Book(string bookTitle, string publishingHouse, int publishingYear)
{
    this->bookTitle = bookTitle;
    this->publishingHouse = publishingHouse;
    this->publishingYear = publishingYear;
    numCoauthors = 0;
    coauthors = new string[0];
}

// default constructor
Book::Book()
{
    this->bookTitle = "";
    this->publishingHouse = "";
    this->publishingYear = 0;
    numCoauthors = 0;
    coauthors = new string[0];
}

// copy constructor
Book::Book (const Book &book)
{
    this->bookTitle = book.bookTitle;
    this->publishingHouse = book.publishingHouse;
    this->publishingYear = book.publishingYear;
    this->numCoauthors = book.numCoauthors;
    this->coauthors = new string[this->numCoauthors];

    for (int i = 0; i < this->numCoauthors; i++)
        coauthors[i] = book.coauthors[i];

}

// destructor
Book::~Book()
{
    this->bookTitle = "";
    this->publishingHouse = "";
    this->publishingYear = 0;
    this->numCoauthors = 0;
    delete[] coauthors;
    coauthors = NULL;
}

// helper method to copy a book
void Book::initBook(const Book &book)
{
    this->bookTitle = book.bookTitle;
    this->publishingHouse = book.publishingHouse;
    this->publishingYear = book.publishingYear;
    this->numCoauthors = book.numCoauthors;

    delete[] coauthors;
    this->coauthors = new string[this->numCoauthors];

    for (int i = 0; i < this->numCoauthors; i++)
        this->coauthors[i] = book.coauthors[i];

}

// adds coauthor
void Book::addCoauthor( string coauthorName ) {

    if (this->coauthorExists(coauthorName)) {

        cout << "There exist the coauthor " << coauthorName << " for the book " << bookTitle << ". Please enter another name." << endl;
        return;
    }


    string *sub = coauthors;
    coauthors = new string[numCoauthors + 1];

    for (int i = 0; i < numCoauthors; i++)
        coauthors[i] = sub[i];

    coauthors[numCoauthors] = coauthorName;
    numCoauthors++;

    delete[] sub;
}

// removes a coauthor
void Book::removeCoauthor ( string coauthorName) {

    // If not found
    if (coauthorExists(coauthorName)) {
        numCoauthors++;
        cout << "The coauthor " << coauthorName << " does not exists. Please enter a valid coauthor name." << endl;
    }

    string *sub = coauthors;
    coauthors = new string[numCoauthors-1];

    int ex = 0;
    for (int i = 0; i < numCoauthors; i++) {
        if (!iequals(sub[i], coauthorName)) {
            coauthors[i - ex] = sub[i];
        } else {
            ex = 1;
        }
    }

    numCoauthors--;
    delete[] sub;
}

// displays book
void Book::displayBook() {
    cout << this->bookTitle << ", " << this->publishingYear << endl;
}

// display details of the book
void Book::displayDetailedBook() {
    cout << this->bookTitle << ", " << this->publishingHouse << ", " << this->publishingYear << endl;
    for (int i = 0; i < numCoauthors; i++) {
        cout << coauthors[i] << endl;
    }
}

// returns whether a coauthor with given coauthorName exists.
bool Book::coauthorExists(string coauthorName) {
    for (int i = 0; i < numCoauthors; i++)
        if (iequals(coauthors[i], coauthorName))
            return true;

    return false;
}

// compares two strings case insensitively

bool Book::iequals(string stringA , string stringB)
{
    transform(stringA.begin(), stringA.end(), stringA.begin(), ::toupper);
    transform(stringB.begin(), stringB.end(), stringB.begin(), ::toupper);

    return (stringA == stringB);
}
