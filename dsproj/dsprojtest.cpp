#include <iostream>
#include <vector>
#include <string>
using namespace std;

void AdminMenu();
void DisplayByNatID();
void DeleteByNatID();
void MainMenu();
bool is_digits(const std::string &str);
void DisplayWaitingLine(string x);
void UpdateData();

class person
{
public:
	string fullname;
	int id;
	unsigned long long int national_id;
	string pass;
	char gender;
	int age;
	string country;
	string gover;
	bool vacc;
	bool doses[2];
	static int x;

public:
	person()
	{
	}

	person(string f, string p, unsigned long long int nat, char g, int a, string c, string go, bool v, bool d1, bool d2)
	{
		fullname = f;
		id = x;
		national_id = nat;
		pass = p;
		gender = g;
		age = a;
		country = c;
		gover = go;
		vacc = v;
		doses[0] = d1;
		doses[1] = d2;
		x++;
	}

	void display()
	{
		system("CLS");
		cout << "full name : " << fullname << endl;
		cout << "id : " << id << endl;
		cout << "national id: " << national_id << endl;
		cout << "password : " << pass << endl;
		cout << "gender : " << gender << endl;
		cout << "age : " << age << endl;
		cout << "country : " << country << endl;
		cout << "governate : " << gover << endl;
		// cout << "vaccinated : " << vacc << endl;
		if (vacc == 1)
		{
			if (doses[0] == 1 && doses[1] == 0)
			{
				cout << "one dose is taken\n";
				DisplayWaitingLine(pass);
			}
			else if (doses[0] == 1 && doses[1] == 1)
			{
				cout << "both doses are taken\n";
			}
		}
		else
		{
			cout << "not vaccinated\n";
			DisplayWaitingLine(pass);
		}

		int y;
		cout << "1 to return to menu : ";
		cin >> y;
		if (y == 1)
			menu();
	}

	void edit()
	{
		system("CLS");
		int c;
		cout << "1 name" << endl;
		cout << "2 password" << endl;
		cout << "3 age" << endl;
		cout << "4 country" << endl;
		cout << "5 governate" << endl;
		cout << "choose what to edit" << endl;
		cin >> c;

		if (c == 1)
		{
			string n;
			cout << "enter new name : ";
			cin >> n;
			fullname = n;
		}
		if (c == 2)
		{
			int p;
			cout << "enter new password : ";
			cin >> p;
			pass = p;
		}
		if (c == 3)
		{
			int a;
			cout << "enter new age : ";
			cin >> a;
			age = a;
		}
		if (c == 4)
		{
			string c;
			cout << "enter new country : ";
			cin >> c;
			country = c;
			string g;
			cout << "enter new governate : ";
			cin >> g;
			gover = g;
		}
		if (c == 5)
		{
			string g;
			cout << "enter new governate : ";
			cin >> g;
			gover = g;
		}

		int y;
		cout << "1 to return to menu : ";
		cin >> y;
		if (y == 1)
			menu();
	}

	void deleteme()
	{
		pass = "";
	}

	void menu()
	{
		UpdateData();
		system("CLS");
		cout << "1. display my information" << endl;
		cout << "2. edit my information" << endl;
		cout << "3. delete my information" << endl;
		cout << "4. sign out" << endl;
		cout << "choose an option : ";
		int c;
		cin >> c;

		if (c == 1)
			display();
		if (c == 2)
			edit();
		if (c == 3)
			deleteme();
		if (c == 4)
			MainMenu();
	}

	static person signup(vector<person> persons)
	{
		system("CLS");
		person p = person();
		cout << "enter your data" << endl;

		string n;
		cout << "enter your full name : ";
		cin >> n;
		p.fullname = n;

		string pass;
		cout << "enter your password : ";
		int s = 1;
		while (s == 1)
		{
			cin >> pass;
			int r = 0;
			for (int j = 0; j < persons.size(); j++)
			{
				if (persons[j].pass == pass)
				{
					cout << "used password , try again" << endl;
					r = 1;
					break;
				}
			}
			if (r == 0)
				s = 0;
		}
		p.pass = pass;

		// unsigned long long int nat_id;
		string nat_id;
		s = 1;
		while (s == 1)
		{
			int r2 = 1;
			do
			{
				cout << "enter your national id: ";
				cin >> nat_id;
				if (is_digits(nat_id))
				{
					if (nat_id.size() == 13)
					{
						r2 = 0;
					}
				}
				// unsigned long long int temp = nat_id;
				// int counter = 0;
				// while (temp != 0) {
				//	temp /= 10;
				//	counter++;
				// }
				// if (counter == 13) {
				//	r2 = 0;
				//	//break;
				// }
				// else if (counter > 13 || counter < 13) {
				//	r2 = 1;
				// }
			} while (r2 == 1);

			int r = 0;
			for (int i = 0; i < persons.size(); i++)
			{
				if (persons[i].national_id == stoll(nat_id))
				{
					cout << "this national id is already registered , try again" << endl;
					r = 1;
					break;
				}
			}
			if (r == 0)
			{
				s = 0;
			}
		}
		p.national_id = stoll(nat_id);

		char g;
		cout << "choose your gender (m/f) : ";
		while (true)
		{
			cin >> g;
			if (g != 'm' && g != 'f')
				cout << "invalid input" << endl;
			else
				break;
		}
		p.gender = g;

		int a;
		cout << "enter your age : ";
		cin >> a;
		p.age = a;

		string c;
		cout << "enter your country : ";
		cin >> c;
		p.country = c;

		string go;
		cout << "enter your governate : ";
		cin >> go;
		p.gover = go;

		char choice;
		int choice_int;
		cout << "were you vaccinated?\n";
		cout << "[y/n]\n";
		cin >> choice;
		if (choice == 'y')
		{
			p.vacc = 1;
			cout << "enter number of doses recieved: ";
			cin >> choice_int;
			if (choice_int == 1)
			{
				p.doses[0] = 1;
				p.doses[1] = 0;
				// waiting_list2.push_back(p);
			}

			else if (choice_int == 2)
			{
				p.doses[0] = 1;
				p.doses[1] = 1;
			}
		}
		else if (choice == 'n')
		{
			p.doses[0] = 0;
			p.doses[1] = 0;
			p.vacc = 0;
			// waiting_list.push_back(p);
		}

		// p.vacc = false;
		p.id = x;
		x++;
		return p;
	}

	~person()
	{
	}
};

int person::x = 0;
vector<person> persons;
vector<person> waiting_list;
vector<person> waiting_list2;

int main()
{
	person p1 = person("ali yasser", "123", 3656529371239, 'm', 21, "egypt", "cairo", 1, 1, 0);
	person p2 = person("ahmed maher", "124", 2751237412971, 'm', 20, "egypt", "cairo", 0, 0, 0);
	person p3 = person("ammar yasser", "125", 2653617281940, 'm', 23, "egypt", "cairo", 0, 0, 0);
	person p4 = person("omar moustafa", "126", 7651928361429, 'm', 22, "egypt", "cairo", 0, 0, 0);
	person admin = person("Omar Mohamed", "admin999", 1232000715915, 'm', 21, "Egypt", "Cairo", 1, 1, 1);
	persons.push_back(p1);
	persons.push_back(p2);
	persons.push_back(p3);
	persons.push_back(p4);
	persons.push_back(admin);
	UpdateData();
	MainMenu();

	return 0;
}

void UpdateData()
{
	for (int i = 0; i < persons.size(); i++)
	{
		if (persons[i].vacc == 0)
		{
			waiting_list.push_back(persons[i]);
		}
		else if (persons[i].doses[1] == 0)
		{
			waiting_list2.push_back(persons[i]);
		}
	}
}

void MainMenu()
{

	vector<person>::iterator it;

	int y = 1;

	while (y == 1)
	{
		system("CLS");
		cout << "welcome to vaccine tracking system" << endl;
		cout << "1 login" << endl;
		cout << "2 signup" << endl;
		int d;
		cin >> d;

		if (d == 1)
		{
			int s = 1;
			int i = -1;
			unsigned long long int id_choice;
			int r1 = 1;

			cout << "enter national id: ";
			while (r1 == 1)
			{
				cin >> id_choice;
				for (int j = 0; j < persons.size(); j++)
				{
					if (persons[j].national_id == id_choice)
					{
						// r1 = 0;
						i = j;
						r1 = 0;
						break;
					}
				}
				if (i == -1)
				{
					cout << "wrong national id, try again: ";
					// j = 0;
				}
			}

			cout << "enter password : ";
			while (s == 1)
			{
				string p;
				cin >> p;

				for (int j = 0; j < persons.size(); j++)
				{
					if (p == "admin999")
					{
						AdminMenu();
					}
					else if (persons[j].pass == p)
					{
						i = j;
						s = 0;
						break;
					}
				}

				if (i == -1)
					cout << "password doesn't exist , try again : ";
			}

			it = persons.begin();
			persons[i].menu();
			if (persons[i].pass == "")
				persons.erase(it + i);

			cout << "press 1 for main menu : ";
			cin >> y;
		}
		if (d == 2)
		{
			persons.push_back(person::signup(persons));
			cout << "press 1 for main menu : ";
			cin >> y;
		}
	}
}

void AdminMenu()
{
	system("CLS");
	cout << "1. display users' information" << endl;
	cout << "2. delete users' information" << endl;
	cout << "3. sign out" << endl;
	cout << "choose an option : ";
	int c;
	cin >> c;

	if (c == 1)
		DisplayByNatID();
	if (c == 2)
		DeleteByNatID();
	if (c == 3)
		MainMenu();
}

void DisplayByNatID()
{
	cout << "Enter user's national ID: ";
	unsigned long long int NatID;
	cin >> NatID;
	for (int i = 0; i < persons.size(); i++)
	{
		if (persons[i].national_id == NatID)
		{
			system("CLS");
			cout << "full name : " << persons[i].fullname << endl;
			cout << "id : " << persons[i].id << endl;
			cout << "national id: " << persons[i].national_id << endl;
			cout << "password : " << persons[i].pass << endl;
			cout << "gender : " << persons[i].gender << endl;
			cout << "age : " << persons[i].age << endl;
			cout << "country : " << persons[i].country << endl;
			cout << "governate : " << persons[i].gover << endl;
			cout << "vaccinated : " << persons[i].vacc << endl;
			int t;
			cout << "press 1 to return to menu\n";
			cin >> t;
			if (t == 1)
				AdminMenu();
		}
	}
}

void DeleteByNatID()
{
	cout << "Enter user's national ID: ";
	unsigned long long int NatID;
	cin >> NatID;
	for (int i = 0; i < persons.size(); i++)
	{
		if (persons[i].national_id == NatID)
		{
			persons[i].deleteme();
			vector<person>::iterator it;
			it = persons.begin();
			if (persons[i].pass == "")
				persons.erase(it + i);

			AdminMenu();
		}
	}
}

bool is_digits(const std::string &str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

void DisplayWaitingLine(string x)
{
	// cout << "test";
	for (int j = 0; j < waiting_list.size(); j++)
	{
		if (waiting_list[j].pass == x)
		{
			cout << "your position in line for vaccination is " << j + 1 << endl;
		}
	}
	for (int j = 0; j < waiting_list2.size(); j++)
	{
		if (waiting_list2[j].pass == x)
		{
			cout << "your position in line for second dose is " << j + 1 << endl;
		}
	}
	// for (int i = 0; i < persons.size(); i++) {
	//	if (persons[i].pass == x) {
	//		//cout << "test";
	//		if (persons[i].vacc == 0) {
	//			//cout << "test";

	//		}
	//		else if (persons[i].vacc == 1 && persons[i].doses[0] == 1) {
	//			//cout << "test";

	//		}

	//	}
	//}
}