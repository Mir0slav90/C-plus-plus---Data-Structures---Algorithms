#include"BinTree.h"
using namespace std;

int main()
{
	int n, key, data;
	BinTree<int, int> tree;
	int ch;
	do
	{
		cout << "Pres 0 for exit!\n";
		cout << "Pres 1 to add element in tree.\n";
		cout << "Pres 2 to insert element in tree.\n";
		cout << "Pres 3 for search element by key.\n";
		cout << "Pres 4 to get info for element.\n";
		cout << "Pres 5 for search element by key and update information.\n";
		cout << "Pres 6 for print elements in line (Root -> Left -> Right)!\n";
		cout << "Pres 7 for print elements in line (Left -> Root -> Right)!\n";
		cout << "Pres 8 for the number of all elements.\n";
		cout << "Pres 9 for print elements in line (Right -> Root -> Left)!\n";
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case 0: break;
		case 1: cout << "Enter number of elements: "; cin >> n;
			cout << "Enter the elements: ";
			for (int i = 0; i < n; i++)
			{
				int current_n;
				cin >> current_n;
				tree.Insert(current_n, current_n);
			}break;
		case 2:
			cout << "Enter the key and info: ";
			cin >> key >> data; 
			if (tree.Insert(key, data) == true)
			{
				tree.Insert(key, data);
				cout << "Done.\n";
			}
			else cout << "Wrong key!\n"; break;
		case 3:
			cout << "Enter key for search: ";
			cin >> key;
			if (tree.Search(key) == true) cout << "There is an element with this key.\n"; else cout << "Wrong key!\n"; break;
		case 4:
			cout << "Enter key for search: ";
			cin >> key;

			if (tree.GetInfo(key, data) == true) cout << "info for " << key << " is " << data << endl; break;
		case 5:
			cout << "Enter key for search: ";
			cin >> key;

			if (tree.Search(key) == true)
			{
				cout << "Enter new info: ";
				cin >> data;
				tree.UpdateInfo(key, data);
				cout << "New information saved.\n";
			}
			else cout << "You entered a non-existent key.\n";break;
		case 6: tree.Print_R_L_R(); cout << endl; break;
		case 7: tree.Print_L_R_R(); cout << endl; break;
		case 8: cout << "The number of elements in the tree is " << tree.PrintCount() << ".\n"; break;
		case 9: tree.Print_R_R_L(); cout << endl; break;
		default:
			break;
		}
		cout << endl;
	} while (ch);

	return 0;
}