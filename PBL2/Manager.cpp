#include "Manager.h"

template <class type>
Manager<type>::Manager() {
    this->head = this->tail = nullptr;
    this->length = 0;
}

template <class type>
Manager<type>::~Manager() {
	for (int i = 0; i < this->length - 2; i++)
        {
            head = head->next;
            delete head->back;
        }
        delete head;
}

template <class type>
void Manager<type>::add(const type ty) {
	Node *node = this->constructorNode(ty);
    if (head == NULL)
    {
        this->head = this->tail = node;
        this->length++;
        return;
    }
    this->tail->next = node;
    node->back = this->tail;
    this->tail = node;
	this->length++;
}

template <class type>
typename Manager<type>::Node* Manager<type>::constructorNode(const type data) {
	Node *node = new Node(data);
    return node;
}

template <class type>
type& Manager<type>::operator[](int index) {
	Node *node = this->head;
    for (int i = 0; i < index; i++)
    {
        node = node->next;
    }
    return node->data;
}

template <class type>
type* Manager<type>::findById(const string& id) {
	Node* node = this->head;
	for (int i = 0; i < this->length; i++) {
		if (strcmp(node->data.getId().c_str(), id.c_str()) == 0) {
            type& a = node->data;
            type* b = &a;
			return b;
		}
		node = node->next;
	}
    return nullptr;
}

template <class type>
void Manager<type>::del(const string& id) {
	Node* node = this->head;
	for (int i = 0; i < this->length; i++) {
		if (strcmp(node->data.getId().c_str(), id.c_str()) == 0) {
			delByIndex(i);
			return;
		}
		node = node->next;
	}
}

template <class type>
void Manager<type>::delByIndex(int index) {
	// Trường hợp vị trí node không tồn tại
    if (index < 0 || index >= this->length)
        return;
    // Trường hợp kích thước danh sách bằng 0
    else if (this->length == 0)
   	{
        return;
    }
    // Trường hợp kích thước danh sách bằng 1
    else if (this->length == 1)
    {
        delete head;
        head = tail = NULL;
    }
    // Trường hợp node ở vị trí đầu
    else if (index == 0)
    {
        Node *node = head->next;
        head->next->back = NULL;
        delete head;
        head = node;
    }
    // Trường hợp node ở vị trí cuối
    else if (index == this->length - 1)
    {
        Node *node = tail->back;
        tail->back->next = NULL;
        delete tail;
        tail = node;
    }
    // Trường hợp node ở giữa
    else
    {
        Node *node = this->head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        node->back->next = node->next;
        node->next->back = node->back;
        delete node;
    }
    this->length--;
}

template <class type>
int Manager<type>::getLength() {
	return this->length;
}

template <class type>
void Manager<type>::setLength(int length) {
	this->length = length;
}

int getInt() {
	while (true) {
		int x;
		cin >> x;
		if (!std::cin) {
			cin.clear(); 
			cin.ignore(100, 10);
			cout << "\t\t\t\t\t\t\tChi nhap so. Moi Nhap lai: ";
		}
		else {
			cin.ignore(100, 10);
			return x;
		}
	}
}

string getphone() {
	string x;
	getline(cin, x);
	if (x.length() > 11 || x.length() < 10) throw long(0);
	for (int i = 0; i < x.length(); i++) {
		if (x[i] > '9' || x[i] < '0') {
			throw int(0);
		}
	}
	return x;
}
int checktime(int date, int month, int year) {
	if (date > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) throw int();
	else if (date > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) throw int();
	else if (date > 29 && month == 2) throw int();
	else if (month > 12 || month < 1) throw long();
	else if (date < 1) throw float();
	else if (year > 9999 || year < 1000) throw string();
	return 0;
}
template class Manager<Ticket>;
template class Manager<Schedule>;
template class Manager<Film>;
template class Manager<CinemaRoom>;
template class Manager<Staff>;
template class Manager<Director>;
