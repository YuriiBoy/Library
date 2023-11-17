#include "Header.h"
#include "Book.h"

Book::Book() : id(0), name("-"), author("-"), year(0)
{
}

Book::Book(int id, std::string name, std::string author, int year)
	: id(id), name(name), author(author), year(year)
{}

void Book::display() const
{
	std::cout << std::setw(5) << id;
	std::cout << std::setw(40) << name;
	std::cout << std::setw(25) << author;
	std::cout << std::setw(20) << year;
	std::cout << std::endl;
}

int Book::getId() const
{
	return id;
}

std::string Book::getName() const
{
	return name;
}

std::string Book::getAuthor() const
{
	return author;
}

int Book::getYear() const
{
	return year;
}
