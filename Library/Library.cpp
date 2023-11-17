#include "Header.h"
#include "Menu.h"
#include "BookManager.h"

int main()
{
    std::string taskName = " Favorite books";
    std::vector <std::string> menuList = {
        "Display all library",
        "Add new book",
        "Delete book",
        "Exit"
    };

    std::unique_ptr<Menu> m(new Menu(taskName, menuList));
    std::unique_ptr<BookManager> manager(new BookManager);
    manager->loadData();
    
    bool stop = false;
    do {
        system("cls");
        m->displayTaskName();
        m->displayMenuList();
        int choice = m->getChoice();
        switch (choice)
        {
        case 1:
            manager->displayAllBooks();
            break;
        case 2:
            manager->addNewBook();
            break;
        case 3:
            manager->delBook();
            break;
        case 4: stop = true;
            break;
        default:
            break;
        }
        if (stop) {
            break;
        }

    } while (m->allawContinue());
    
    std::cout << "\n Finish";
}
