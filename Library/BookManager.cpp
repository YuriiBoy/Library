#include "Header.h"
#include "BookManager.h"

void BookManager::loadData()
{
	std::ifstream fin;
	fin.open("BooksStorage.txt");
	books.clear();

	while (!fin.eof()) 	{
		int id;
		std::string name;
		std::string author;
		int year;

		fin >> id;
		fin.ignore();
		std::getline(fin, name);
		std::getline(fin, author);
		fin >> year;

		Book book(id, name, author, year);
		books.push_back(book);
		std::cout << "\n List of books has been loaded\n";

	}
	books.pop_back();
	fin.close();

}

void BookManager::saveData()
{
	std::ofstream fout;
	fout.open("BooksStorage.txt");

	for (int i = 0; i < books.size(); i++) {
		Book temp = books[i];
		fout << temp.getId() << std::endl;
		fout << temp.getName() << std::endl;
		fout << temp.getAuthor() << std::endl;
		fout << temp.getYear() << std::endl;
	}

	fout.close();
	std::cout << "\n List of books is saved\n";
}

void BookManager::displayAllBooks() const
{
	if (books.empty()) {
		std::cout << "\n Books list is empty\n";
	}
	else {
		const int N = books.size();
		std::cout << "\n There are " << N << " books in the list\n";
		for (int i = 0; i < N; i++) {
			books[i].display();
		}
	}
}

void BookManager::addNewBook()
{
	int id;
	std::string name;
	std::string author;
	int year;

	id = books.back().getId() + 1;
	std::cin.ignore();

	std::cout << "\n Input Name of the book: ";
	std::getline(std::cin, name);
	std::cout << "\n Input name of author of the book: ";
	std::getline(std::cin, author);
	std::cout << "\n Input Name year of the book first edition: ";
	std::cin >> year;

	Book newBook(id, name, author, year);
	books.push_back(newBook);
	saveData();

}

void BookManager::delBook()
{
	int id;
	std::cout << "\n Please input books ID you want to delete: ";
	std::cin >> id;
	auto iter = std::find_if(books.begin(), books.end(), 
		[id](Book& b) {return (b.getId() == id); });
	if (iter == books.end()) {
		std::cout << "\n There is no such book\n";
	}
	else {
		books.erase(iter);
		std::cout << "\n The book has been deleted\n";
		saveData();
	}
}
