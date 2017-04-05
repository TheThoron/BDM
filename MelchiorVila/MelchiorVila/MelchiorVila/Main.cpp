#include "fonctions.h"

void main(){
	string buffer;
	ifstream text("test.txt", ios::in);  // we open the file in reading mode
	if (text)  // if we could open it
	{
		cout << "chargement du fichier" << endl;
		while (!text.eof()) //we put all the text in the string buffer
		{
			string temp;
			getline(text, temp);
			buffer += temp;
		}
		text.close();  // we clode the file

		Node<string>* root = new Node<string>(); // the root of the tree
		Node<string>* parent = root; // the current parent
		Node<string>* current = nullptr; // the current "word"
		size_t lastFound = 0;
		size_t found = buffer.find_first_of("#\\;>."); // we try to find on specific sign
		while (found != string::npos) // while we find one of the sign
		{
			switch (buffer[found]) // which sign did we find ?
			{
			case '#': // each '#' we create an other node, children of the current parent
			{
				lastFound = found + 1;
				found = buffer.find_first_of("#\\;>.", found + 1); 
				current = new Node<string>();
				current->data().assign(buffer, lastFound, found - lastFound); // we copy the word into the new node
				current->setParent(parent); // we put the node in the tree
				break;
			}
			case '>': // each '>' the child become the current parent
			{
				if (current != nullptr)
					parent = current;
				found = buffer.find_first_of("#\\;>.", found + 1);
				break;
			}
			case '\\': // each '\' the parent of the parent become the current parent
				parent = parent->getParent();
				found = buffer.find_first_of("#\\;>.", found + 1);
				break;
			case ';': // each ';' we move forward on the text
				found = buffer.find_first_of("#\\;>.", found + 1);
				break;
			case '.': // when we meet '.' we  go out of the while
				found = string::npos;
				break;
			}//switch off
		} // while off
		sortNode(root); // we sort the tree
		string txt;
		writeNode(root, txt, 0); // we use a function to write the tree on a string
		ofstream textAnswer;  // we open the file in writing mode
		textAnswer.open("resulta.txt");
		textAnswer << txt; // we copy the string in the file
		textAnswer.close(); // we close the file
	} // if(text) off
	else  cerr << "Impossible d'ouvrir le fichier !" << endl;
}