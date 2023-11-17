#pragma once
#include "Book.h"

class BookManager
	 
{
	std::vector < Book > books;
public:
	void loadData();
	void saveData();
	void displayAllBooks() const;
	void addNewBook();
	void delBook();
};

