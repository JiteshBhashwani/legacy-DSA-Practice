#include "linkedList.hpp"
void menu()
{
	std::cout << "press 0: exit\n";
	std::cout << "press 1: push()\n";
	std::cout << "press 2: pop()\n";
	std::cout << "press 3: isEmpty()\n";
	std::cout << "press 4: isFull()\n";
	std::cout << "press 5: display()\n";
	std::cout << "press 6: clear screen[shell cmd]\n\n:";
	
}
int main() 
{
	linkedList q;
    
	int choice;
	menu();
	do
	{
		std::cin >> choice;
		switch (choice)
		{
		case 0: break;
		case 1:
			{int x; std::cin >> x;
			// if(!q.isFUll()) std::cout << x << " added" << std::endl;
			// q.push(x);
			// node new_node(x);
			// q.push(new_node);}
			q.push(x);}
			break;
		case 2:
			std::cout << q.pop() << " dequed from queue" << std::endl;  
			break;
		case 3:
			std::cout << (q.isEmpty() ? "empty" : "not empty") << std::endl;
			break;
		case 4:
			std::cout << (q.isFUll() ? "full" : "not full") << std::endl;
			break;
		case 5:
			q.display();
			break;
		case 6:
			std::system("clear");
			menu();
		default:
			break;
		}
	} while (choice != 0);
	
	return 0;
}