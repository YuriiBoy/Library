#pragma once
class Book

{
	int id;
	std::string name;
	std::string author;
	int year;
public:
	Book();
	Book(int id, std::string name, std::string author, int year);
	void display() const;
	int getId() const;
	std::string getName() const;
	std::string getAuthor() const;
	int getYear() const;
};

