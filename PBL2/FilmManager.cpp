#include "FilmManager.h"

char asciitolower(char in) {
	if (in <= 'Z' && in >= 'A')
		return in - ('Z' - 'z');
	return in;
}

void FilmManager::findByName(string& name) {
	Node* node = this->head;
	transform(name.begin(), name.end(), name.begin(), asciitolower);
	int check = 0;
	int i = 0;
	while(i < this->length) {
		string nametmp = node->data.getName();
		transform(nametmp.begin(), nametmp.end(), nametmp.begin(), asciitolower);
		size_t found = nametmp.find(name);
		if (found != string::npos && check == 0)
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t<<PHIM CHUA TEN TREN LA>>\n\n";
			cout << "\t";
			for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
			cout << "\t";
			cout << "|" << left << setw(13) << "    Ma phim" << "|" << left << setw(31) << "\t   Ten phim" << "|" << left << setw(20) << "   Dao dien" << "|" << left << setw(20) << "\tDien vien chinh" << "|" << left << setw(17) << "\tQuoc gia" << "|" << left << setw(20) << "\tThe loai" << "|" << left << setw(15) << "  Thoi gian" << "|" << endl;
			cout << "\t";
			for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
			cout << "\t";
			node->data.writeData();
			cout << "\t";
			for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
			check = 1;
		}
		else if (found != string::npos) {
			cout << "\t";
			node->data.writeData();
			cout << "\t";
			for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
		}
		node = node->next;
		i++;
	}
	if(check == 0) {
		cout << "\n\t\t\t\t\t\t\tKhong tim thay phim!" << endl;
		return;
	}
}		

Film FilmManager::setFilmInfor() {
	Type allType;
	string id;
	string name;
	string director;
	string actor;
	string country;
	int type;
	int length;
	int check = 0;
	Film filmtmp;
	do {
		cout << "\n\t\t\t\t\t\t\tNhap id: ";
		getline(cin, id);
		if(this->findById(id) != nullptr) {
			do {
				cout << "\t\t\t\t\t\t\t\tMa bi trung!. Lua chon";
				cout << "\n\t\t\t\t\t\t\t1. Nhap lai";
				cout << "\t\t\t2. Thoat";
				cout << "\n\t\t\t\t\t\t\t";
				check = getInt();
				if (check != 1 && check != 2) {
					cout << "\t\t\t\t\t\t\tLua chon khong hop le! Moi chon lai.\n";
					system("pause");
				}
			} while (check != 1 && check != 2);
		}
		else check = 3;
	} while(check == 1 || check == 0);
	if (check == 2) {
		Film film;
		film.setId("null");
		return film;
	}
	check = 0;
	cout << "\t\t\t\t\t\t\tNhap ten phim: ";
	getline(cin, name);
	cout << "\t\t\t\t\t\t\tNhap dao dien: ";
	getline(cin, director);
	cout << "\t\t\t\t\t\t\tNhap dien vien chinh: ";
	getline(cin, actor);
	cout << "\t\t\t\t\t\t\tNhap noi san xuat: ";
	getline(cin, country);
	cout << "\t\t\t\t\t\t\t\t\t\tCac the loai bao gom:";
	int cnt = 0;
	while (cnt < 20) {
		cout << "\n\t\t\t\t\t\t\t" << left << setw(4) << cnt << ": " << left << setw(30) << *(allType.getType() + cnt) << "|";
		cout << "\t\t\t\t" << left << setw(4) << cnt + 1 << ": " << *(allType.getType() + cnt + 1);
		cnt += 2;
	}
	cout << "\n";
	do {
		cout << "\t\t\t\t\t\t\tNhap ma the loai: ";
		type = getInt();
		if(type >= 0 && type < 20) check = 1;
		if (check == 0) {
			cout << "\t\t\t\t\t\t\t\tThe loai khong hop le moi nhap lai.\n";
		}
	} while (check == 0);
	cout << "\t\t\t\t\t\t\tNhap do dai phim: ";
	length = getInt();
	Film film(id, name, director, actor, country, type, length);
	return film;
}

void FilmManager::update() {
	Type allType;
	string id;
	cout << "\t\t\t\t\t\t\tNhap id: ";
	getline(cin, id);
	if (findById(id) == nullptr) {
		cout << "\t\t\t\t\t\t\tKhong tim thay id phu hop!\n";
		system("pause");
	}
	else {
		int opttmp = 0;
		Film* film = findById(id);
		do {
			system("cls");
			cout << "\n";
			cout << "\t";
			for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
			cout << "\t";
			cout << "|" << left << setw(13) << "    Ma phim" << "|" << left << setw(31) << "\t   Ten phim" << "|" << left << setw(20) << "   Dao dien" << "|" << left << setw(20) << "\tDien vien chinh" << "|" << left << setw(17) << "\tQuoc gia" << "|" << left << setw(20) << "\tThe loai" << "|" << left << setw(15) << "  Thoi gian" << "|" << endl;
			cout << "\t";
			for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
			cout << "\t";
			film->writeData();
			cout << "\t";
			for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
			cout << "\n\t\t\t\t\t\t\t1. Sua ten phim" << endl;
			cout << "\t\t\t\t\t\t\t2. Sua dao dien" << endl;
			cout << "\t\t\t\t\t\t\t3. Sua dien vien" << endl;
			cout << "\t\t\t\t\t\t\t4. Sua noi san xuat" << endl;
			cout << "\t\t\t\t\t\t\t5. Sua the loai" << endl;
			cout << "\t\t\t\t\t\t\t6. Sua do dai phim" << endl;
			cout << "\t\t\t\t\t\t\t0. Xac nhan va thoat" << endl;
			cout << "\t\t\t\t\t\t\t\t>> Nhap lua chon: ";
			opttmp = getInt();
			string up;
			int upn;
			switch (opttmp) {
			case(1): {
				cout << "\t\t\t\t\t\t\tNhap ten phim: ";
				getline(cin, up);
				film->setName(up);
				break;
			}
			case(2): {
				cout << "\t\t\t\t\t\t\tNhap dao dien: ";
				getline(cin, up);
				film->setDirector(up);
				break;
			}
			case(3): {
				cout << "\t\t\t\t\t\t\tNhap dien vien: ";
				getline(cin, up);
				film->setActor(up);
				break;
			}
			case(4): {
				cout << "\t\t\t\t\t\t\tNhap noi san xuat: ";
				getline(cin, up);
				film->setCountry(up);
				break;
			}
			case(5): {
				cout << "\t\t\t\t\t\t\t\t\t\tCac the loai bao gom:";
				int check = 0;
				int cnt = 0;
				while (cnt < 20) {
					cout << "\n\t\t\t\t\t\t\t" << left << setw(4) << cnt << ": " << left << setw(30) << *(allType.getType() + cnt) << "|";
					cout << "\t\t\t\t" << left << setw(4) << cnt + 1 << ": "  << *(allType.getType() + cnt + 1);
					cnt += 2;
				}
				cout << "\n";
				do {
					cout << "\t\t\t\t\t\t\tNhap ma the loai: ";
					upn = getInt();
					if(upn >= 0 && upn < 20) check = 1;
					if (check == 0) {
						cout << "\t\t\t\t\t\t\t\tThe loai khong hop le moi nhap lai.\n";
						system("pause");
					}
				} while (check == 0);
				film->setType(upn);
				break;
			}
			case(6): {
				cout << "\t\t\t\t\t\t\tNhap thoi gian: ";
				upn = getInt();
				film->setLength(upn);
				break;
			}
			case(0): {
				break;
			}
			default:
				cout << "\t\t\t\t\t\t\tLua chon khong hop le! Moi chon lai.\n";
				system("pause");
			}
		} while (opttmp != 0);
	}
}
void FilmManager::readFile(fstream& filein) {
	int len;
	filein >> len;
	 for (int i = 0; i < len; i++) {
	 	Film film;
	 	film.readDataFile(filein);
	 	this->add(film);
	}
}
void FilmManager::writeFile(fstream& fileout) {
	Node* node = this->head;
	fileout << length << "\n";
	for (int i = 0; i < length; i++) {
		node->data.writeDataFile(fileout);
		node = node->next;
	}
}
void FilmManager::write() {
	Node* node = this->head;
	cout << "\t";
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
	cout << "\t";
	cout << "|" << left << setw(13) << "    Ma phim" << "|" << left << setw(31) << "\t   Ten phim" << "|" << left << setw(20) << "   Dao dien" << "|" << left << setw(20) << "\tDien vien chinh" << "|" << left << setw(17) << "\tQuoc gia" << "|" << left << setw(20) << "\tThe loai" << "|" << left << setw(15) << "  Thoi gian" << "|" << endl;
	cout << "\t";
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
	for (int i = 0; i < length; i++) {
		cout << "\t";
		node->data.writeData();
		node = node->next;
	}
	cout << "\t";
	for (int x = 0; x < 156; x++) cout << "-"; cout << endl;
}