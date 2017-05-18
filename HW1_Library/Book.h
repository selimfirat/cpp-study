#ifndef BOOK_H
#define BOOK_H

#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Book
{
    public:
        Book();
        Book(const Book &book);
        Book(string bookTitle, string publishingHouse, int publishingYear);
        ~Book();
        void initBook(const Book &book);
        void displayDetailedBook();
        void displayBook();
        void removeCoauthor ( string coauthorName);
        void addCoauthor( string coauthorName );
        bool coauthorExists( string coauthorName);
        string bookTitle;
        string publishingHouse;
        int publishingYear;

    private:
        int numCoauthors;
        string *coauthors;
        bool iequals(string stringA , string stringB);

};

#endif // BOOK_H
