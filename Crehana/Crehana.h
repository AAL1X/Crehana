#ifndef __CREHANA_H__
#define __CREHANA_H__
#include "Resources.h"
#include "DoubleCircularLinkedList.h"
#include "HashTable.h"
#include "BinarySearchTree.h"
#include "Name.h"
#include "LastName.h"
#include "Student.h"
#include "Tutor.h"
class Crehana
{
private:
	BinarySearchTree<LastName>* LastNames;
	BinarySearchTree<Name>* Names;
	DoubleCircularLinkedList<Student*>* Students;
	BinarySearchTree<Student*>* Students2;
	HashTable<Student*>* Students3;
	DoubleCircularLinkedList<Tutor>* Teachers;
	DoubleCircularLinkedList<Course>* Courses;

	fstream FileIO;
	ofstream FileWriter;
	ifstream FileReader;

	string ObjectQuantity;
	string CoverterTotxt;
	string Message;

	short Selection;
	short Option;
	string OptionSelective;
	bool Looping;
	bool RestartSystem;
	short PauseTime;
	short Random;

	Student* User;
public:
	Crehana();
	~Crehana();

	void CrehanaVbeta();

	void LoaderCrehanaData();
	void LoaderTxtDataBase();
	void LoaderTxtCourseData();
	void LoaderTxtTeacherData();
	void LoaderTxtStudentData();

	void SelectionHandler();

	void LogoGenius();
	void DisplayCrehanaMenu();

	void SignIn();
	void SignUp();
	void LogOut();
	void TerminateExecution();

	void DisplayUserProfile();
	void DisplayUserCourse();
	void DisplayUserCalendar();
	void DisplayUserDiploma();
	void DisplayUserNotification();
	void DisplayCrehanaCourses();

	void RecursiveReaderTxtCrehanaDataBase(size_t Iter, int Limitation, char ClassType);
	void RecursiveReaderTxtCourseFile(size_t Iter, int Limitation, char ClassType);
	void RecursiveReaderTxtPersonFile(size_t Iter, int Limitation, char ClassType);
	void RecursiveReaderTxtDiplomaFile(size_t Iter, int Limitation);
	void RecursiveReaderTxtNotificationFile(size_t Iter, int Limitation);

	void RecursiveWriterTxtStudentFile(size_t Iter, size_t Limitation);
	void RecursiveWriterTxtCourseFile(size_t Iter, size_t Limitation);
	void RecursiveWriterTxtDiplomaFile(size_t Iter, size_t Limitation);
	void RecursiveWriterTxtNotificationFile(size_t Iter, int Limitation);

	void RecursiveDisplayStudentsAccount(size_t Iter, size_t Limitation);
	void RecursiveDisplayUserCalendar(size_t Iter, size_t Limitation);
	void RecursiveDisplayCourse(size_t Iter, size_t Limitation, char ClassType);
	void RecursiveCourseEnrollment(size_t Iter, size_t Limitation);

	void FisherYatesShuffle();
	void ExchangeSort();
	void BubbleSort();
};

Crehana::Crehana() {
	Names = new BinarySearchTree<Name>();
	LastNames = new BinarySearchTree<LastName>();
	Students = new DoubleCircularLinkedList<Student*>();
	Students2 = new BinarySearchTree<Student*>();
	Students3 = new HashTable<Student*>(10000);
	Teachers = new DoubleCircularLinkedList<Tutor>();
	Courses = new DoubleCircularLinkedList<Course>();

	Looping = true;
	Selection = 0;
	Option = 0;
	OptionSelective = "";

	RestartSystem = true;

	PauseTime = 100;
	Random = 1 + rand() % +3;

	User = nullptr;
}
Crehana::~Crehana()
{
	delete Students;
	delete Teachers;
	delete Courses;

	Students = nullptr;
	Teachers = nullptr;
	Courses = nullptr;

	User = nullptr;
}

void Crehana::CrehanaVbeta() {

	/// [   REPEATER CREHANA SYSTEM   ]
	while (Looping) {
		/// [   CLEANER SCREEN   ]
		system("cls");
		/// [   CLEANER SCREEN   ]


		/// [   CREHANA MENU   ]
		DisplayCrehanaMenu();
		/// [   CREHANA MENU   ]


		/// [   SELECTION HANDLER   ]
		SelectionHandler();
		/// [   SELECTION HANDLER   ]


		/// [   FUNCTION DELAY TIME   ]
		_sleep(PauseTime * 5);
		/// [   FUNCTION DELAY TIME   ]
	}
	/// [   REPEATER CREHANA SYSTEM   ]
}

void Crehana::LoaderCrehanaData() {
	cout << " [   OK   ]   Started Remount Root File "; Message = "System.\n\n";
	for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
		cout << i.operator*();
	}
	_sleep(PauseTime);

	cout << "              Starting Read File System..." << endl;
	/// [   CREHANA DATA LOADER FUNCTIONS   ]
	LoaderTxtDataBase();
	LoaderTxtCourseData();
	LoaderTxtTeacherData();
	LoaderTxtStudentData();
	/// [   CREHANA DATA LOADER FUNCTIONS   ]
}
void Crehana::LoaderTxtDataBase() {
	FileReader.open("CrehanaDataBase.txt", ios::in);
	if (FileReader.is_open()) {

		getline(FileReader, ObjectQuantity);
		if (stoi(ObjectQuantity) > 0)
			RecursiveReaderTxtCrehanaDataBase(0, stoi(ObjectQuantity) - 1, 'N');

		getline(FileReader, ObjectQuantity);
		if (stoi(ObjectQuantity) > 0)
			RecursiveReaderTxtCrehanaDataBase(0, stoi(ObjectQuantity) - 1, 'L');


		string FirstNameU = "";
		string SecondNameU = "";
		string LastNameU = "";
		string MothersLastNameU = "";
		int Age = 0;
		string StudentID = "";
		string Password = "";

		int Random = 0;
		char Data = ' ';

		for (int i = 0; i < 10000; i++) {

			FirstNameU = Names->ObtainRandom().getData();

			do {
				SecondNameU = Names->ObtainRandom().getData();
			} while (SecondNameU == FirstNameU);


			LastNameU = LastNames->ObtainRandom().getData();
			do
			{
				MothersLastNameU = LastNames->ObtainRandom().getData();
			} while (LastNameU == MothersLastNameU);

			Age = 10 + rand() % 108;

			StudentID += "U";

			Random = 10000 + rand() % 90000;

			StudentID += to_string(Random);

			Random = 1 + rand() % 2;

			if (Random == 1) {
				Data = 97 + rand() % 26;
				StudentID += Data;
			}
			else
				if (Random == 2) {
					Random = 1 + rand() % 9;
					StudentID += to_string(Random);
				}

			Random = 100 + rand() % 900;

			StudentID += to_string(Random);

			Random = 4 + rand() % 6;

			for (int i = 0; i < Random; i++) {
				Password += char(33 + rand() % +58);
			}

			Students->AddToEnd(new Student(FirstNameU, SecondNameU, LastNameU, MothersLastNameU, Age, StudentID, Password));

			FirstNameU = "";
			SecondNameU = "";
			LastNameU = "";
			MothersLastNameU = "";
			Age = 0;
			StudentID = "";
			Password = "";

			Random = 0;
			Data = ' ';
		}
		FileReader.close();
	}
}
void Crehana::LoaderTxtCourseData() {
	/// [   CREHANA-COURSES FILE OPENDED   ]
	FileReader.open("Courses.txt", ios::in);
	/// [   CREHANA-COURSES FILE OPENDED   ]


	/// [   CREHANA-COURSES FILE VIEWER   ]
	if (FileReader.is_open()) {
		/// [   OBJECT QUANTITY READING   ]
		getline(FileReader, ObjectQuantity);
		/// [   OBJECT QUANTITY READING   ]


		/// [   RECURSIVE COURSES READER FUNCTION   ]
		RecursiveReaderTxtCourseFile(0, stoi(ObjectQuantity) - 1, 'C');
		/// [   RECURSIVE COURSES READER FUNCTION   ]


		/// [   CREHANA-COURSES FILE CLOSED   ]
		FileReader.close();
		/// [   CREHANA-COURSES FILE CLOSED   ]
	}
	/// [   CREHANA-COURSES FILE VIEWER   ]
}
void Crehana::LoaderTxtTeacherData() {
	/// [   CREHANA-TEACHERS FILE OPENDED   ]
	FileIO.open("Teachers.txt", ios::in);
	/// [   CREHANA-TEACHERS FILE OPENDED   ]


	/// [   CREHANA-TEACHERS FILE VIEWER   ]
	if (FileIO.is_open()) {
		/// [   OBJECT QUANTITY READING   ]
		getline(FileIO, ObjectQuantity);
		/// [   OBJECT QUANTITY READING   ]


		/// [   RECURSIVE TEACHERS READER FUNCTION   ]
		RecursiveReaderTxtPersonFile(0, stoi(ObjectQuantity) - 1, 'T');
		/// [   RECURSIVE TEACHERS READER FUNCTION   ]


		/// [   CREHANA-TEACHERS FILE CLOSED   ]
		FileIO.close();
		/// [   CREHANA-TEACHERS FILE CLOSED   ]
	}
	/// [   CREHANA-TEACHERS FILE VIEWER   ]
}
void Crehana::LoaderTxtStudentData() {
	/// [   CREHANA-STUDENTS FILE OPENDED   ]
	FileIO.open("Students.txt", ios::in);
	/// [   CREHANA-STUDENTS FILE OPENDED   ]


	_sleep(PauseTime);
	/// [   CREHANA-STUDENTS FILE VIEWER   ]
	if (FileIO.is_open()) {
		/// [   OBJECT QUANTITY READING   ]
		getline(FileIO, ObjectQuantity);
		/// [   OBJECT QUANTITY READING   ]


		/// [   RECURSIVE STUDENTS READER FUNCTION   ]
		if (stoi(ObjectQuantity) > 0)
			RecursiveReaderTxtPersonFile(0, stoi(ObjectQuantity) - 1, 'S');
		/// [   RECURSIVE STUDENTS READER FUNCTION   ]


		/// [   CREHANA-STUDENTS FILE CLOSED   ]
		FileIO.close();
		/// [   CREHANA-STUDENTS FILE CLOSED   ]
	}
	/// [   CREHANA-STUDENTS FILE VIEWER   ]
}

void Crehana::SelectionHandler() {
	/// [   OPTION INPUT   ]
	cout << endl << " get source "; Message = "option ";
	for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
		cout << (*i);
	}
	cin >> Option;
	/// [   OPTION INPUT   ]

	system("cls");

	/// [   CREHANA MENU   ]
	LogoGenius();
	/// [   CREHANA MENU   ]

	if (User == nullptr) {
		switch (Option)
		{
		case 1:
			SignIn();
			break;
		case 2:
			SignUp();
			break;
		case 3:
			TerminateExecution();
			break;
		default:
			break;
		}
	}
	else {
		switch (Option)
		{
		case 1:
			DisplayUserProfile();
			break;
		case 2:
			DisplayUserCourse();
			break;
		case 3:
			DisplayUserCalendar();
			break;
		case 4:
			DisplayUserDiploma();
			break;
		case 5:
			DisplayUserNotification();
			break;
		case 6:
			DisplayCrehanaCourses();
			break;
		case 7:
			LogOut();
			break;
		case 8:
			TerminateExecution();
			break;
		default:
			break;
		}
		cin.get();
	}
	Option = 0;
}

void Crehana::LogoGenius() {
	if (RestartSystem) {
		cout << endl << " Execute Shell Program "; Message = "CREHANA VSTUDIO\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}
		_sleep(PauseTime);

		cout << " Swift[ CREHANA ]: ~/   tools   -sudo/"; Message = "CREHANA\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}
		_sleep(PauseTime);

		cout << " Loading. Please "; Message = "wait...";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}
		_sleep(PauseTime * 5); system("cls");
	}

	if (!RestartSystem)
		system("color F");
	else
		system("color F");

	if (User == nullptr) {
		cout << "                                                        NULL                                                         "; _sleep(PauseTime);
	}
	else {
		cout << "                                                " << User->getStudentID() << char(64) << "upc.edu.pe" << endl; _sleep(PauseTime);
	}

	cout << " =================================================================================================================== " << endl; _sleep(PauseTime);
	cout << " CREHANA:  PowerShell  post - exploitation  agent  " << char(179) << "  [Version]  3.905" << endl; _sleep(PauseTime);
	cout << " =================================================================================================================== " << endl << endl; _sleep(PauseTime);
	cout << " =================================================================================================================== " << endl << endl;

	if (RestartSystem) {
		Random = 3;
	}
	else {
		Random = 1 + rand() % +2;
	}

	if (Option == 0) {
		if (Random == 1) {
			int sombra = 176;
			cout << endl << "   " << char(219) << char(219) << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << "  " << char(sombra) << char(219) << char(219) << char(219) << char(219) << char(219) << "   " << char(219) << "      " << char(219) << "   " << char(sombra) << char(219) << char(219) << char(219) << char(219) << char(219) << endl; _sleep(PauseTime / 10);
			cout << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "       " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << "  " << char(219) << char(219) << "    " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << endl; _sleep(PauseTime / 10);
			cout << " " << char(219) << char(219) << char(sombra) << "       " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "       " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(219) << char(219) << "  " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << endl; _sleep(PauseTime / 10);
			cout << " " << char(219) << char(219) << char(sombra) << "       " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << char(sombra) << "  " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << char(219) << char(219) << " " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << char(sombra) << "  " << char(219) << char(219) << char(sombra) << endl; _sleep(PauseTime / 10);
			cout << " " << char(219) << char(219) << char(sombra) << "       " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << "       " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(sombra) << endl; _sleep(PauseTime / 10);
			cout << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "  " << char(219) << char(219) << char(sombra) << "  " << char(219) << char(219) << char(sombra) << "       " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << endl; _sleep(PauseTime / 10);
			cout << "   " << char(219) << char(219) << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(219) << char(sombra) << "  " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << " " << char(219) << char(219) << char(sombra) << "   " << char(219) << char(219) << char(sombra) << endl << endl << endl; _sleep(PauseTime / 10);
		}
		else
			if (Random == 2) {
				int sombra1 = 178;
				int sombra2 = 177;
				int sombra3 = 176;

				cout << endl << "  " << char(220) << char(219) << char(219) << char(219) << char(219) << char(220) << "   " << char(219) << char(219) << char(223) << char(219) << char(219) << char(219) << "  " << char(sombra1) << char(219) << char(219) << char(219) << char(219) << char(219) << "  " << char(219) << char(219) << char(sombra3) << " " << char(219) << char(219) << "  " << char(220) << char(220) << char(220) << "       " << char(219) << char(219) << char(219) << char(220) << "   " << char(219) << "  " << char(220) << char(220) << char(220) << endl; _sleep(PauseTime / 10);
				cout << " " << char(sombra2) << char(219) << char(219) << char(223) << " " << char(223) << char(219) << "  " << char(sombra1) << char(219) << char(219) << " " << char(sombra2) << " " << char(219) << char(219) << char(sombra2) << char(sombra1) << char(219) << "   " << char(223) << " " << char(sombra1) << char(219) << char(219) << char(sombra3) << " " << char(219) << char(219) << char(sombra2) << char(sombra2) << char(219) << char(219) << char(219) << char(219) << char(220) << "     " << char(219) << char(219) << " " << char(223) << char(219) << "  " << char(219) << " " << char(sombra2) << char(219) << char(219) << char(219) << char(219) << char(220) << endl; _sleep(PauseTime / 10);
				cout << " " << char(sombra2) << char(sombra1) << char(219) << "    " << char(220) << " " << char(sombra1) << char(219) << char(219) << " " << char(sombra3) << char(220) << char(219) << " " << char(sombra2) << char(sombra2) << char(219) << char(219) << char(219) << "   " << char(sombra2) << char(219) << char(219) << char(223) << char(223) << char(219) << char(219) << char(sombra3) << char(sombra2) << char(219) << char(219) << "  " << char(223) << char(219) << char(220) << "  " << char(sombra1) << char(219) << char(219) << "  " << char(223) << char(219) << " " << char(219) << char(sombra2) << char(sombra2) << char(219) << char(219) << "  " << char(223) << char(219) << char(220) << endl; _sleep(PauseTime / 10);
				cout << " " << char(sombra2) << char(sombra1) << char(sombra1) << char(220) << " " << char(220) << char(219) << char(219) << char(sombra2) << char(sombra2) << char(219) << char(219) << char(223) << char(223) << char(219) << char(220) << "  " << char(sombra2) << char(sombra1) << char(219) << "  " << char(220) << " " << char(sombra3) << char(sombra1) << char(219) << " " << char(sombra3) << char(219) << char(219) << " " << char(sombra3) << char(219) << char(219) << char(220) << char(220) << char(220) << char(220) << char(219) << char(219) << " " << char(sombra1) << char(219) << char(219) << char(sombra2) << "  " << char(219) << char(219) << char(219) << char(sombra2) << char(sombra3) << char(219) << char(219) << char(220) << char(220) << char(220) << char(220) << char(219) << char(219) << endl; _sleep(PauseTime / 10);
				cout << " " << char(sombra2) << " " << char(sombra1) << char(219) << char(219) << char(219) << char(223) << " " << char(sombra3) << char(sombra3) << char(219) << char(219) << char(sombra1) << " " << char(sombra2) << char(219) << char(219) << char(sombra2) << char(sombra3) << char(sombra2) << char(219) << char(219) << char(219) << char(219) << char(sombra2) << char(sombra3) << char(sombra1) << char(219) << char(sombra2) << char(sombra3) << char(219) << char(219) << char(sombra1) << " " << char(sombra1) << char(219) << "   " << char(sombra1) << char(219) << char(219) << char(sombra2) << char(sombra2) << char(219) << char(219) << char(sombra3) << "  " << char(sombra1) << char(219) << char(219) << char(sombra3) << " " << char(sombra1) << char(219) << "   " << char(sombra1) << char(219) << char(219) << char(sombra2) << endl; _sleep(PauseTime / 10);
				cout << " " << char(sombra3) << " " << char(sombra3) << char(sombra2) << " " << char(sombra3) << "  " << char(sombra3) << char(sombra3) << " " << char(sombra2) << char(sombra1) << " " << char(sombra3) << char(sombra2) << char(sombra1) << char(sombra3) << char(sombra3) << char(sombra3) << " " << char(sombra2) << char(sombra3) << " " << char(sombra3) << " " << char(sombra2) << " " << char(sombra3) << char(sombra3) << char(sombra2) << char(sombra3) << char(sombra2) << " " << char(sombra2) << char(sombra2) << "   " << char(sombra1) << char(sombra2) << char(219) << char(sombra3) << char(sombra3) << " " << char(sombra2) << char(sombra3) << "  " << char(sombra2) << " " << char(sombra2) << "  " << char(sombra2) << char(sombra2) << "   " << char(sombra1) << char(sombra2) << char(219) << char(sombra3) << endl; _sleep(PauseTime / 10);
				cout << " " << char(sombra3) << "  " << char(sombra2) << "     " << char(sombra3) << char(sombra2) << " " << char(sombra3) << " " << char(sombra2) << char(sombra3) << " " << char(sombra3) << " " << char(sombra3) << "  " << char(sombra3) << " " << char(sombra2) << " " << char(sombra3) << char(sombra2) << char(sombra3) << " " << char(sombra3) << "  " << char(sombra2) << "   " << char(sombra2) << char(sombra2) << " " << char(sombra3) << char(sombra3) << " " << char(sombra3) << char(sombra3) << "   " << char(sombra3) << char(sombra2) << char(sombra3) << "  " << char(sombra2) << "   " << char(sombra2) << char(sombra2) << " " << char(sombra3) << endl; _sleep(PauseTime / 10);
				cout << " " << char(sombra3) << "          " << char(sombra3) << char(sombra3) << "   " << char(sombra3) << "    " << char(sombra3) << "    " << char(sombra3) << "  " << char(sombra3) << char(sombra3) << " " << char(sombra3) << "  " << char(sombra3) << "   " << char(sombra2) << "     " << char(sombra3) << "   " << char(sombra3) << " " << char(sombra3) << "   " << char(sombra3) << "   " << char(sombra2) << endl; _sleep(PauseTime / 10);
				cout << " " << char(sombra3) << char(sombra3) << "         " << char(sombra3) << "        " << char(sombra3) << "  " << char(sombra3) << " " << char(sombra3) << "  " << char(sombra3) << "  " << char(sombra3) << "      " << char(sombra3) << "  " << char(sombra3) << "        " << char(sombra3) << "       " << char(sombra3) << "  " << char(sombra3) << endl; _sleep(PauseTime / 10);
				cout << " " << char(sombra3) << endl << endl << endl; _sleep(PauseTime / 10);
			}
			else
				if (Random == 3) {
					cout << "   ____ ____  _____ _   _    _    _   _    _" << endl; _sleep(PauseTime / 10);
					cout << "  / ___|  _ " << char(92) << "| ____| | | |  / " << char(92) << "  | " << char(92) << " | |  / " << char(92) << endl; _sleep(PauseTime / 10);
					cout << " | |   | |_) |  _| | |_| | / _ " << char(92) << " |  " << char(92) << "| | / _ " << char(92) << endl; _sleep(PauseTime / 10);
					cout << " | |___|  _ <| |___|  _  |/ ___ " << char(92) << "| |" << char(92) << "  |/ ___ " << char(92) << endl; _sleep(PauseTime / 10);
					cout << "  " << char(92) << "____|_| " << char(92) << "_" << char(92) << "_____|_| |_/_/   " << char(92) << "_" << char(92) << "_| " << char(92) << "_/_/   " << char(92) << "_" << char(92) << endl << endl << endl; _sleep(PauseTime / 10);
				}
	}

	if (RestartSystem) {
		_sleep(PauseTime * 5);
		cout << endl << " [            192.24.93.0 SD. 0:0:0:0:  "; Message = "[sda]\n\n";
		for (string::iterator i = Message.begin(); i < Message.end(); i++) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}
		_sleep(PauseTime);


		/// [   RESTART LOCAL VARIABLES   ]
		Looping = true;
		Selection = 0;
		Option = 0;
		OptionSelective = "";
		User = nullptr;
		ObjectQuantity = "";
		CoverterTotxt = "";
		/// [   RESTART LOCAL VARIABLES   ]
		cout << " [   OK   ]   Started SSC : Set preliminary "; Message = "keymap.\n\n";
		for (string::iterator i = Message.begin(); i < Message.end(); i++) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}
		_sleep(PauseTime);

		cout << "              Starting Remount Root File "; Message = "System...\n\n";
		for (string::iterator i = Message.begin(); i < Message.end(); i++) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}


		/// [   CREHANA DATA LOADER   ]
		LoaderCrehanaData();
		/// [   CREHANA DATA LOADER   ]


		RestartSystem = false; _sleep(PauseTime * 5);
		cout << " [   OK   ]   Reached target Local File System "; Message = "(Pre).\n";
		for (string::iterator i = Message.begin(); i < Message.end(); i++) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}
		_sleep(PauseTime * 5);

		system("cls"); LogoGenius(); _sleep(PauseTime * 5);
	}
}
void Crehana::DisplayCrehanaMenu() {
	LogoGenius();

	if (User == nullptr) {
		cout << " [   1   ]   Sign "; Message = "In\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}

		cout << endl << " [   2   ]   Sign "; Message = "Up\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}

		cout << endl << " [   3   ]   "; Message = "Exit\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}
	}
	else {
		cout << " [   1   ]   View "; Message = "Profile\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}

		cout << endl << " [   2   ]   My "; Message = "Courses\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}

		cout << endl << " [   3   ]   My "; Message = "Calendar\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}

		cout << endl << " [   4   ]   My "; Message = "Diplomas\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}

		cout << endl << " [   5   ]   "; Message = "Notifications\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}

		cout << endl << " [   6   ]   "; Message = "Search\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}

		cout << endl << " [   7   ]   Log "; Message = "Out\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}

		cout << endl << " [   8   ]   "; Message = "Exit\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
			cout << i.operator*(); _sleep(PauseTime / 10);
		}
	}
}

void Crehana::SignIn() {
	if (Students->getSize() != 0) {
		string Password;

		RecursiveDisplayStudentsAccount(0, Students->getSize() - 1);

		do {
			Message = " get source account ";
			for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
				cout << i.operator*(); _sleep(PauseTime / 10);
			}
			cin >> Selection;
		} while (Selection < 1 || Selection > Students->getSize());

		do {
			Message = "\n Password: ";
			for (string::iterator i = Message.begin(); i != Message.end(); ++i) {
				cout << i.operator*(); _sleep(PauseTime / 10);
			}
			cin >> Password;
		} while (Password != Students->ObtainIndex(Selection - 1)->getPassword());

		User = Students->ObtainIndex(Selection - 1);


		system("cls");
		LogoGenius();
		cout << "     // PERSON header structure" << endl;
		cout << "     //" << endl << endl << endl;


		cout << "     typedef struct {" << endl;
		cout << "        u32string FirstName                            [     connected     ];" << endl; _sleep(PauseTime);
		cout << "        u32string SecondName                           [     connected     ];" << endl; _sleep(PauseTime);
		cout << "        u32string LastName                             [     connected     ];" << endl; _sleep(PauseTime);
		cout << "        u32string MothersLastName                      [     connected     ];" << endl; _sleep(PauseTime);
		cout << "        u_int32_t Age                                  [     connected     ];" << endl; _sleep(PauseTime);
		cout << endl << "     } cr_person_t; " << endl << endl << endl; _sleep(PauseTime);

		cout << "     //" << endl;
		cout << "     // STUDENT BLOCK definitions" << endl;
		cout << "     //" << endl << endl << endl;

		cout << "     typedef struct {" << endl;
		cout << "        var_list CourseList                            [     connected     ];" << endl; _sleep(PauseTime);
		cout << "        var_list DiplomaList                           [     connected     ];" << endl; _sleep(PauseTime);
		cout << "        var_list NotificationHeap                      [     connected     ];" << endl; _sleep(PauseTime);
		cout << "        u32string Password                             [     connected     ];" << endl; _sleep(PauseTime);
		cout << "        u32string StudentID                            [     connected     ];" << endl; _sleep(PauseTime);
		cout << endl << "     } cr_student_t, cr_user_t;" << endl;
		cout << "     //" << endl << endl;
	}
	else {
		cout << "--No hay cuentas que usar--";
	}
}
void Crehana::SignUp() {
	cout << " _ooooo__oooo____oooo___ooo____oo____oo______oo_ooooooo__" << endl; _sleep(PauseTime / 10);
	cout << " oo___oo__oo___oo____oo_oooo___oo____oo______oo_oo____oo_" << endl; _sleep(PauseTime / 10);
	cout << " _oo______oo__oo________oo_oo__oo____oo______oo_oo____oo_" << endl; _sleep(PauseTime / 10);
	cout << " ___oo____oo__oo____ooo_oo__oo_oo____oo______oo_oooooo___" << endl; _sleep(PauseTime / 10);
	cout << " oo___oo__oo___oo____oo_oo___oooo_____oo____oo__oo_______" << endl; _sleep(PauseTime / 10);
	cout << " _ooooo__oooo____oooo___oo____ooo_______oooo____oo_______" << endl; _sleep(PauseTime / 10);
	cout << " ________________________________________________________" << endl << endl << endl; _sleep(PauseTime / 10);
	string FirstName;
	string SecondName;
	string LastName;
	string MothersLastName;
	short Age;
	string StudentID;
	string Password;

	cout << " Sign Up - Trophy CREHANA v7.00PC " << endl; _sleep(PauseTime);
	cout << " Copyright (C) by Crehana Company" << endl; _sleep(PauseTime);
	cout << " Rev.4.25" << endl; _sleep(PauseTime);
	cout << " Main Processor : XXXXXXXXXXXXXXXXXXXX" << endl; _sleep(PauseTime);
	cout << " Memory Testing : " << &Students << " OK" << endl << endl << endl << endl; _sleep(PauseTime);
	cout << " Students Cache Size : 79KB" << endl; _sleep(PauseTime);
	cout << " First Name Student : "; cin >> FirstName;
	cout << " Second Name Student : "; cin >> SecondName;
	cout << " Last Name Student : "; cin >> LastName;
	cout << " Mother's Last Name Student : "; cin >> MothersLastName;
	cout << " Old-Age Student : "; cin >> Age;
	do {
		cout << " ID Student : "; cin >> StudentID;
		StudentID[0] = toupper(StudentID[0]);
	} while (StudentID[0] != ('U') || StudentID.size() != 10);
	cout << " Not-So-Secret Password : "; cin >> Password; cout << endl;

	Students->AddToEnd(new Student(FirstName, SecondName, LastName, MothersLastName, Age, StudentID, Password));
	User = Students->ObtainEnd();

	FileWriter.open("Students.txt", ios::out);
	if (FileWriter.is_open()) {
		FileWriter << Students->getSize() << endl;
		RecursiveWriterTxtStudentFile(0, Students->getSize() - 1);
		FileWriter.close();
	}

	CoverterTotxt = StudentID + ".txt";

	FileWriter.open(CoverterTotxt, ios::out);
	if (FileWriter.is_open()) {
		FileWriter << User->getCourseList()->getSize() << endl;
		FileWriter << User->getDiplomaList()->getSize() << endl;
		FileWriter << User->getNotificationHeap()->getSize();
		FileWriter.close();
	}

	cout << " Floppy file(s) fail (80)" << endl << endl << endl; _sleep(PauseTime);
	cout << " Press any button to Continue"; _sleep(PauseTime);
}
void Crehana::LogOut() {
	cout << "     // PERSON header structure" << endl;
	cout << "     //" << endl << endl << endl;


	cout << "     typedef struct {" << endl;
	cout << "        u32string FirstName                            [   disconnected   ];" << endl; _sleep(PauseTime);
	cout << "        u32string SecondName                           [   disconnected   ];" << endl; _sleep(PauseTime);
	cout << "        u32string LastName                             [   disconnected   ];" << endl; _sleep(PauseTime);
	cout << "        u32string MothersLastName                      [   disconnected   ];" << endl; _sleep(PauseTime);
	cout << "        u_int32_t Age                                  [   disconnected   ];" << endl; _sleep(PauseTime);

	cout << endl << "     } cr_person_t; " << endl << endl << endl;


	cout << "     //" << endl;
	cout << "     // STUDENT BLOCK definitions" << endl;
	cout << "     //" << endl << endl << endl;


	cout << "     typedef struct {" << endl;
	cout << "        var_list CourseList                            [   disconnected   ];" << endl; _sleep(PauseTime);
	cout << "        var_list DiplomaList                           [   disconnected   ];" << endl; _sleep(PauseTime);
	cout << "        var_list NotificationHeap                      [   disconnected   ];" << endl; _sleep(PauseTime);
	cout << "        u32string Password                             [   disconnected   ];" << endl; _sleep(PauseTime);
	cout << "        u32string StudentID                            [   disconnected   ];" << endl; _sleep(PauseTime);
	cout << endl << "     } cr_student_t, cr_user_t;" << endl;
	cout << "     //" << endl << endl;
	User = nullptr;
}
void Crehana::TerminateExecution() {
	Looping = false;
	cout << "--Hasta pronto--";
}

void Crehana::DisplayUserProfile() {
	cout << "  ________  ________  ________  ________ ___  ___       _______" << endl;
	cout << " |" << char(92) << "   __  " << char(92) << "|" << char(92) << "   __  " << char(92) << "|" << char(92) << "   __  " << char(92) << "|" << char(92) << "  _____" << char(92) << char(92) << "  " << char(92) << "|" << char(92) << "  " << char(92) << "     |" << char(92) << "  ___ " << char(92) << endl;
	cout << " " << char(92) << " " << char(92) << "  " << char(92) << "|" << char(92) << "  " << char(92) << " " << char(92) << "  " << char(92) << "|" << char(92) << "  " << char(92) << " " << char(92) << "  " << char(92) << "|" << char(92) << "  " << char(92) << " " << char(92) << "  " << char(92) << "__/" << char(92) << " " << char(92) << "  " << char(92) << " " << char(92) << "  " << char(92) << "    " << char(92) << " " << char(92) << "   __/|" << endl;
	cout << "  " << char(92) << " " << char(92) << "   ____" << char(92) << " " << char(92) << "   _  _" << char(92) << " " << char(92) << "  " << char(92) << char(92) << char(92) << "  " << char(92) << " " << char(92) << "   __" << char(92) << char(92) << " " << char(92) << "  " << char(92) << " " << char(92) << "  " << char(92) << "    " << char(92) << " " << char(92) << "  " << char(92) << "_|/__" << endl;
	cout << "   " << char(92) << " " << char(92) << "  " << char(92) << "___|" << char(92) << " " << char(92) << "  " << char(92) << char(92) << "  " << char(92) << char(92) << " " << char(92) << "  " << char(92) << char(92) << char(92) << "  " << char(92) << " " << char(92) << "  " << char(92) << "_| " << char(92) << " " << char(92) << "  " << char(92) << " " << char(92) << "  " << char(92) << "____" << char(92) << " " << char(92) << "  " << char(92) << "_|" << char(92) << " " << char(92) << endl;
	cout << "    " << char(92) << " " << char(92) << "__" << char(92) << "    " << char(92) << " " << char(92) << "__" << char(92) << char(92) << "__" << char(92) << char(92) << " " << char(92) << "_______" << char(92) << " " << char(92) << "__" << char(92) << "   " << char(92) << " " << char(92) << "__" << char(92) << " " << char(92) << "_______" << char(92) << " " << char(92) << "_______" << char(92) << endl;
	cout << "     " << char(92) << "|__|     " << char(92) << "|__|" << char(92) << "|__|" << char(92) << "|_______|" << char(92) << "|__|    " << char(92) << "|__|" << char(92) << "|_______|" << char(92) << "|_______|" << endl << endl;

	cout << "      ";
	if (User->getCourseList()->getSize() > 9)
		cout << User->getCourseList()->getSize();
	else
		cout << "0" << User->getCourseList()->getSize() << " courses currently enrolled" << endl; _sleep(PauseTime);

	cout << "      ";
	if (User->getDiplomaList()->getSize() > 9)
		cout << User->getDiplomaList()->getSize();
	else
		cout << "0" << User->getDiplomaList()->getSize() << " diplomas currently obtained" << endl; _sleep(PauseTime);


	cout << "      ";
	if (User->getNotificationHeap()->getSize() > 9)
		cout << User->getNotificationHeap()->getSize();
	else
		cout << "0" << User->getNotificationHeap()->getSize() << " unread notifications" << endl << endl; _sleep(PauseTime);

	cout << " <Employed stored variables /user> " << char(175); Message = " options\n\n";
	for (string::iterator i = Message.begin(); i != Message.end(); ++i)
		cout << i.operator*(); _sleep(PauseTime / 10);

	cout << " Description:" << endl; _sleep(PauseTime);
	cout << "     Dedicated and curious, " << User->getAge() << "-year-old " << User->getFirstName() << " " << User->getLastName() << " is a passionate student ready to improve \n     his problem-solving skills and creativity, has a positive attitude and unwavering commitment\n     to his studies. With student ID " << User->getStudentID() << ", he enthusiastically embraces his educational journey." << endl << endl; _sleep(PauseTime);

	cout << " Options:" << endl; _sleep(PauseTime);

	cout << "     Atribute";
	for (size_t i = 0; i < 10; i++) {
		cout << " ";
	}
	cout << "Value";
	for (size_t i = 0; i < 7; i++) {
		cout << " ";
	}
	cout << "Description" << endl; _sleep(PauseTime);

	cout << "     --------";
	for (size_t i = 0; i < 10; i++) {
		cout << " ";
	}
	cout << "-----";
	for (size_t i = 0; i < 10; i++) {
		cout << " ";
	}
	cout << "-----------" << endl; _sleep(PauseTime);

	cout << "     FirstName";
	for (size_t i = 0; i < 9; i++) {
		cout << " ";
	}
	cout << User->getFirstName();
	for (size_t i = User->getFirstName().size(); i < 15; i++) {
		cout << " ";
	}
	cout << "Permission granted to generate variables and display files on the screen." << endl; _sleep(PauseTime);

	cout << "     SecondName";
	for (size_t i = 0; i < 8; i++) {
		cout << " ";
	}
	cout << User->getSecondName();
	for (size_t i = User->getSecondName().size(); i < 15; i++) {
		cout << " ";
	}
	cout << "No intermediary server to utilize for the inquiry (default, none, other)." << endl << endl; _sleep(PauseTime);

	cout << "     LastName";
	for (size_t i = 0; i < 10; i++) {
		cout << " ";
	}
	cout << User->getLastName();
	for (size_t i = User->getLastName().size(); i < 15; i++) {
		cout << " ";
	}
	cout << "User-agent string to use for the display request (default, none, other)." << endl << endl << endl; _sleep(PauseTime);

	cout << "     MothersLastName";
	for (size_t i = 0; i < 3; i++) {
		cout << " ";
	}
	cout << User->getMothersLastName();
	for (size_t i = User->getMothersLastName().size(); i < 15; i++) {
		cout << " ";
	}
	cout << "Authorization to generate variables for output of files, necessary,                                                  showcase on the screen." << endl << endl; _sleep(PauseTime);

	cout << "     Old-Age";
	for (size_t i = 0; i < 11; i++) {
		cout << " ";
	}
	cout << User->getAge();
	for (size_t i = 2; i < 15; i++) {
		cout << " ";
	}
	cout << "User-agent identifier to employ for the storing request (default, none, other)." << endl << endl << endl << endl; _sleep(PauseTime);

	cout << " <Copied stagelabels> " << char(175) << " get studentslist/obtainindex/profile ";
	Message = "crehana0.00\n";
	for (size_t i = 0; i < Message.size(); i++) {
		cout << Message[i]; _sleep(PauseTime / 10);
	}
	_sleep(PauseTime);

	cout << " <Copied stagelabels> " << char(175);
	Message = " generate\n\n";
	for (size_t i = 0; i < Message.size(); i++) {
		cout << Message[i]; _sleep(PauseTime / 10);
	}
	_sleep(PauseTime);

	cout << " [*] user output value run /implaided" << endl << endl;
	_sleep(PauseTime);

	cout << " <Copied stagelabels> " << char(175);
	Message = " Modificate list detail students [Y/n] ";
	for (size_t i = 0; i < Message.size(); i++) {
		cout << Message[i]; _sleep(PauseTime / 10);
	}

	cin >> OptionSelective;

	if (toupper(OptionSelective[0]) != 'Y') {
		return;
	}
	system("cls");
	LogoGenius();
	int t;
	for (int i = 0; i < Students->getSize(); i++) {
		if (User->getStudentID() == Students->ObtainIndex(i)->getStudentID()) {
			t = i;
		}
	}

	cout << " #_ Loading, please wait..." << endl << endl; _sleep(PauseTime * 5);
	cout << " [ 2.201060524] sd 0:0:0:0:0ddbu22 [Cre] Assuming drive cache: write through" << endl; _sleep(PauseTime);
	cout << " Valid path for Overwrite User." << endl << endl; _sleep(PauseTime);

	cout << " Started:  Attempting to overwrite Crehaware fuse file" << endl; _sleep(PauseTime);
	cout << " See 'systemctm status: 'runCrehaware//fuse.mount'' for details" << endl << endl; _sleep(PauseTime);

	cout << " [ 0.000000] init_memory_mapping: [mem " << &Students << "-" << Students->ObtainEnd() << "]" << endl; _sleep(PauseTime);
	cout << " [ 1.169734] [mem " << &Students << "-" << &User << "]" << endl << endl; _sleep(PauseTime);

	cout << " area 1 status: OK  CRE" << t << "-vr (FirstName): " << User->getFirstName() << endl; _sleep(PauseTime);
	cout << " area 2 status: OK  CRE" << t << "-vr (SecondName): " << User->getSecondName() << endl; _sleep(PauseTime);
	cout << " area 3 status: OK  CRE" << t << "-vr (LastName): " << User->getLastName() << endl; _sleep(PauseTime);
	cout << " area 4 status: OK  CRE" << t << "-vr (MLastName): " << User->getMothersLastName() << endl; _sleep(PauseTime);
	cout << " area 5 status: OK  CRE" << t << "-vr (Old-Age): " << User->getAge() << endl; _sleep(PauseTime);
	cout << " area 6 status: OK  CRE" << t << "-vr(Password) : " << User->getPassword() << endl; _sleep(PauseTime);
	cout << " status: OK  found CREHANA HT-table mapped at [mem " << &Students << "-" << &User << "]" << endl << endl; _sleep(PauseTime);

	do {
		cout << " Edit Mounted area "; cin >> Selection;
	} while (Selection < 1 && Selection > 6);

	if (Selection == 1) {
		string FirstName;
		cout << " [ " << &FirstName << "] NewVariable: FirstName = "; cin >> FirstName;
		User->setFirstName(FirstName);
		cout << " Overwriting initrd memory" << endl << endl;
	}
	else
		if (Selection == 2) {
			string SecondName;
			cout << " [ " << &SecondName << "] NewVariable: SecondName = "; cin >> SecondName;
			User->setSecondName(SecondName);
			cout << " Overwriting initrd memory" << endl << endl;
		}
		else
			if (Selection == 3) {
				string LastName;
				cout << " [ " << &LastName << "] NewVariable: LastName = "; cin >> LastName;
				User->setLastName(LastName);
				cout << " Overwriting initrd memory" << endl << endl;
			}
			else
				if (Selection == 4) {
					string MothersLastName;
					cout << " [ " << &MothersLastName << "] NewVariable: MLastName = "; cin >> MothersLastName;
					User->setMothersLastName(MothersLastName);
					cout << " Overwriting initrd memory" << endl << endl;
				}
				else
					if (Selection == 5) {
						int Age;
						cout << " [ " << &Age << "] NewVariable: Old-Age = "; cin >> Age;
						User->setAge(Age);
						cout << " Overwriting initrd memory" << endl << endl;
					}
					else
						if (Selection == 6) {
							string Password;
							cout << " [ " << &Password << "] NewVariable: Password = "; cin >> Password;
							User->setPassword(Password);
							cout << " Overwriting initrd memory" << endl << endl;
						}

	cout << " Overwriting area " << Selection << " for overwrite variable corruption" << endl; _sleep(PauseTime);
	cout << " Monitoring of Crehana file... ng dmeventd or progress overwriting." << endl; _sleep(PauseTime);
	cout << " init_memory_mapping: [mem " << &Students << "-" << Students->ObtainEnd() << "]" << endl << endl; _sleep(PauseTime);

	cout << " Mounted variable Chehaware: user edited:" << endl << endl << endl; _sleep(PauseTime);

	for (size_t i = 0; i < 45; i++)
	{
		cout << " -"; _sleep(PauseTime);
	}

	FileWriter.open("Students.txt", ios::out);
	if (FileWriter.is_open()) {

		FileWriter << Students->getSize() << endl;

		RecursiveWriterTxtStudentFile(0, Students->getSize() - 1);

		FileWriter.close();
	}
}
void Crehana::DisplayUserCourse() {
	if (User->getCourseList()->getSize() == 0) {
		cout << "Usted no tiene cursos programados...";
	}
	else {

		cout << " ___  ____   __  _____ _____ _   _______  _____ _____ _____ " << endl;
		cout << " |  " << char(92) << "/  " << char(92) << " " << char(92) << " / / /  __ " << char(92) << "  _  | | | | ___ " << char(92) << "/  ___|  ___/  ___|" << endl;
		cout << " | .  . |" << char(92) << " V /  | /  " << char(92) << "/ | | | | | | |_/ /" << char(92) << " `--.| |__ " << char(92) << " `--. " << endl;
		cout << " | |" << char(92) << "/| | " << char(92) << " /   | |   | | | | | | |    /  `--. " << char(92) << "  __| `--. " << char(92) << endl;
		cout << " | |  | | | |   | " << char(92) << "__/" << char(92) << " " << char(92) << "_/ / |_| | |" << char(92) << " " << char(92) << " /" << char(92) << "__/ / |___/" << char(92) << "__/ /" << endl;
		cout << " " << char(92) << "_|  |_/ " << char(92) << "_/    " << char(92) << "____/" << char(92) << "___/ " << char(92) << "___/" << char(92) << "_| " << char(92) << "_|" << char(92) << "____/" << char(92) << "____/" << char(92) << "____/ " << endl << endl;

		RecursiveDisplayCourse(0, User->getCourseList()->getSize() - 1, 'S');
		cout << " get source course";
		do {
			cout << " ";
			cin >> Selection;
		} while (Selection < 1 || Selection > User->getCourseList()->getSize());
		Selection--;

		system("cls");
		LogoGenius();
		cout << " ================================================" << endl; _sleep(PauseTime);
		if (User->getCourseList()->ObtainIndex(Selection)->getSessionQueue()->Peek().getSessionNumber() == 3) {
			cout << "   _____ ________________ ________  _   __   _____" << endl; _sleep(PauseTime / 10);
			cout << "  / ___// ____/ ___/ ___//  _/ __ " << char(92) << "/ | / /  |__  /" << endl; _sleep(PauseTime / 10);
			cout << "  " << char(92) << "__ " << char(92) << "/ __/  " << char(92) << "__ " << char(92) << char(92) << "__ " << char(92) << " / // / / /  |/ /    /_ < " << endl; _sleep(PauseTime / 10);
			cout << " ___/ / /___ ___/ /__/ // // /_/ / /|  /   ___/ / " << endl; _sleep(PauseTime / 10);
			cout << "/____/_____//____/____/___/" << char(92) << "____/_/ |_/   /____/  " << endl << endl; _sleep(PauseTime);
		}
		else
			if (User->getCourseList()->ObtainIndex(Selection)->getSessionQueue()->Peek().getSessionNumber() == 2) {
				cout << "   _____ ________________ ________  _   __   ___ " << endl; _sleep(PauseTime / 10);
				cout << "  / ___// ____/ ___/ ___//  _/ __ " << char(92) << "/ | / /  |__ " << char(92) << endl; _sleep(PauseTime / 10);
				cout << "  " << char(92) << "__ " << char(92) << "/ __/  " << char(92) << "__ " << char(92) << char(92) << "__ " << char(92) << " / // / / /  |/ /   __/ /" << endl; _sleep(PauseTime / 10);
				cout << " ___/ / /___ ___/ /__/ // // /_/ / /|  /   / __/ " << endl; _sleep(PauseTime / 10);
				cout << "/____/_____//____/____/___/" << char(92) << "____/_/ |_/   /____/ " << endl << endl; _sleep(PauseTime / 10);
			}
			else
				if (User->getCourseList()->ObtainIndex(Selection)->getSessionQueue()->Peek().getSessionNumber() == 1) {
					cout << "    _____ ________________ ________  _   __   ___" << endl; _sleep(PauseTime / 10);
					cout << "   / ___// ____/ ___/ ___//  _/ __ " << char(92) << "/ | / /  <  /" << endl; _sleep(PauseTime / 10);
					cout << "   " << char(92) << "__ " << char(92) << "/ __/  " << char(92) << "__ " << char(92) << char(92) << "__ " << char(92) << " / // / / /  |/ /   / / " << endl; _sleep(PauseTime / 10);
					cout << "  ___/ / /___ ___/ /__/ // // /_/ / /|  /   / /  " << endl; _sleep(PauseTime / 10);
					cout << " /____/_____//____/____/___/" << char(92) << "____/_/ |_/   /_/   " << endl << endl; _sleep(PauseTime / 10);
				}
		cout << " ================================================" << endl << endl; _sleep(PauseTime);

		cout << " *****" << char(64) << "crehana:~$ app -cache search MicrosoftVS [ CREHANA ]" << endl; _sleep(PauseTime);
		cout << " MicrosoftVS:Browser:~$ sudo -E app-get session Crehana - launcher" << endl; _sleep(PauseTime);
		cout << " Reading package list..."; _sleep(PauseTime); _sleep(PauseTime); _sleep(PauseTime); cout << " Done" << endl << endl; _sleep(PauseTime);

		cout << " Start Session : [ Y / N ]" << endl;
		cout << " ";
		cin >> OptionSelective;

		if (toupper(OptionSelective.at(0)) == 'Y') {
			cout << endl;
			cout << " Remote Access Session" << endl; _sleep(PauseTime / 10);
			cout << " ["; _sleep(PauseTime);
			for (int i = 0; i < 60; i++) {
				cout << "o";
				_sleep(PauseTime / 10);
			}
			cout << "]" << endl << endl << endl; _sleep(PauseTime);

			cout << " [  DONE  ]" << endl << endl; _sleep(PauseTime);

			if (User->getCourseList()->ObtainIndex(Selection)->getSessionQueue()->Peek().getSessionNumber() == 3) {
				cout << " *** FAREWELL MY DEAR COURSE ***"; _sleep(PauseTime);
				User->getNotificationHeap()->Push(Notification("Diploma", User->getCourseList()->ObtainIndex(Selection)->getCourseName()));
			}

			User->getCourseList()->ObtainIndex(Selection)->getSessionQueue()->Dequeue();

			if (User->getCourseList()->ObtainIndex(Selection)->getSessionQueue()->IsEmpty()) {
				if (User->getDiplomaList()->getSize() > 0) {
					for (SimpleCircularLinkedList<Diploma>::Iterator it = User->getDiplomaList()->begin(); it != User->getDiplomaList()->end(); ++it) {
						if ((*it).getAchievementHonor() == "Bacholer's") {
							User->getDiplomaList()->RemoveIndex(it.Index);
							User->getDiplomaList()->AddToEnd(Diploma(User->getCourseList()->ObtainIndex(Selection)->getCourseName(), User->getFirstName(), "Master's"));
						}
						else
							if ((*it).getAchievementHonor() == "Master's") {
								User->getDiplomaList()->RemoveIndex(it.Index);
								User->getDiplomaList()->AddToEnd(Diploma(User->getCourseList()->ObtainIndex(Selection)->getCourseName(), User->getFirstName(), "Doctorate"));
							}

						if (it.Index == User->getDiplomaList()->getSize() - 1) {
							User->getDiplomaList()->AddToEnd(Diploma(User->getCourseList()->ObtainIndex(Selection)->getCourseName(), User->getFirstName(), "Bacholer's"));
							break;
						}
					}
				}
				else {
					User->getDiplomaList()->AddToEnd(Diploma(User->getCourseList()->ObtainIndex(Selection)->getCourseName(), User->getFirstName(), "Bacholer's"));
				}
				User->getCourseList()->RemoveIndex(Selection);
			}

			CoverterTotxt = User->getStudentID() + ".txt";

			FileWriter.open(CoverterTotxt, ios::out);
			if (FileWriter.is_open()) {
				FileWriter << User->getCourseList()->getSize();
				if (User->getCourseList()->getSize() > 0) {
					FileWriter << endl;
					RecursiveWriterTxtCourseFile(0, User->getCourseList()->getSize() - 1);
				}

				FileWriter << endl << User->getDiplomaList()->getSize();
				if (User->getDiplomaList()->getSize() > 0) {
					FileWriter << endl;
					RecursiveWriterTxtDiplomaFile(0, User->getDiplomaList()->getSize() - 1);
				}

				FileWriter << endl << User->getNotificationHeap()->getSize();
				if (User->getNotificationHeap()->getSize() > 0) {
					FileWriter << endl;
					RecursiveWriterTxtNotificationFile(0, User->getNotificationHeap()->getSize() - 1);
				}
				FileWriter.close();
			}
		}
		else
			return;
	}
}
void Crehana::DisplayUserCalendar() {
	cout << "  " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << " " << char(219) << char(219) << char(187) << "     " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(219) << char(187) << "   " << char(219) << char(219) << char(187) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << "  " << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << endl;
	cout << " " << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << char(219) << char(219) << char(219) << char(219) << char(187) << "  " << char(219) << char(219) << char(186) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << endl;
	cout << " " << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << "  " << char(219) << char(219) << char(201) << char(219) << char(219) << char(187) << " " << char(219) << char(219) << char(186) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(186) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188) << endl;
	cout << " " << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(186) << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(201) << char(205) << char(205) << char(188) << "  " << char(219) << char(219) << char(186) << char(200) << char(219) << char(219) << char(187) << char(219) << char(219) << char(186) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(186) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(186) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << endl;
	cout << " " << char(200) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(186) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(186) << " " << char(200) << char(219) << char(219) << char(219) << char(219) << char(186) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(186) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(186) << endl;
	cout << "  " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << " " << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188) << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188) << endl << endl;

	RecursiveDisplayUserCalendar(0, 15);
	cin.get();
}
void Crehana::DisplayUserDiploma() {
	if (User->getDiplomaList()->getSize() == 0) {
		cout << "Usted no tiene diplomas...";
	}
	else {
		for (SimpleCircularLinkedList<Diploma>::Iterator it = User->getDiplomaList()->begin(); it != User->getDiplomaList()->end(); ++it) {
			cout << " ============================================= " << endl << endl; _sleep(PauseTime / 10);
			cout << "       ___  _______  __   ____  __  ______" << endl; _sleep(PauseTime / 10);
			cout << "      / _ " << char(92) << "/  _/ _ " << char(92) << "/ /  / __ " << char(92) << "/  |/  / _ |" << endl; _sleep(PauseTime / 10);
			cout << "     / // // // ___/ /__/ /_/ / /|_/ / __ |" << endl; _sleep(PauseTime / 10);
			cout << "    /____/___/_/  /____/" << char(92) << "____/_/  /_/_/ |_|" << endl << endl << endl; _sleep(PauseTime / 10);

			for (int i = 0; i < (43 - (11 + (*it).getDiplomaTitle().size())) / 2; i++) {
				cout << " ";
			}
			cout << "  Diploma in " << (*it).getDiplomaTitle() << endl << endl; _sleep(PauseTime / 10);
			for (int i = 0; i < (43 - (13 + (*it).getReceiverName().size())) / 2; i++) {
				cout << " ";
			}
			cout << "  Presented to " << (*it).getReceiverName() << endl << endl; _sleep(PauseTime / 10);
			for (int i = 0; i < (43 - (19 + (*it).getAchievementHonor().size())) / 2; i++) {
				cout << " ";
			}
			cout << "  For the Dregree of " << (*it).getAchievementHonor() << endl << endl; _sleep(PauseTime / 10);
			cout << "             Certified by Crehana             " << endl << endl; _sleep(PauseTime / 10);
			cout << " =============================================" << endl << endl << endl; _sleep(PauseTime / 10);
		}
	}
	cin.get();
}
void Crehana::DisplayUserNotification() {
	if (User->getNotificationHeap()->getSize() == 0) {
		cout << "Usted no tiene notificaciones...";
	}
	else {
		cout << " 01001110 01001111 01010100 01001001 0100110 01001001 01000011 01000001 01010100 01001001 01001111 01001110 01010011" << endl << endl;
		if (User->getNotificationHeap()->Peek().getType() == "Enrolment") {
			cout << "              Notification         " << endl;
			cout << "    _______________|_______________" << endl;
			cout << "    |                             |" << endl;
			cout << "    |                             |" << endl;
			cout << "    |                             |" << endl;
			cout << " You got                       In the" << endl;
			cout << "  a new                        course" << endl;
			cout << " " << User->getNotificationHeap()->Peek().getType() << "                    " << User->getNotificationHeap()->Peek().getName() << endl;
		}
		else
			if (User->getNotificationHeap()->Peek().getType() == "Diploma") {
				cout << "              Notification         " << endl;
				cout << "    _______________|_______________" << endl;
				cout << "    |                             |" << endl;
				cout << "    |                             |" << endl;
				cout << "    |                             |" << endl;
				cout << " You got                       In the" << endl;
				cout << "  a new                        course" << endl;
				cout << " " << User->getNotificationHeap()->Peek().getType() << "                    " << User->getNotificationHeap()->Peek().getName() << endl;
			}
		User->getNotificationHeap()->Pop();
		cin.get();

		CoverterTotxt = User->getStudentID() + ".txt";

		FileWriter.open(CoverterTotxt, ios::out);
		if (FileWriter.is_open()) {
			FileWriter << User->getCourseList()->getSize();
			if (User->getDiplomaList()->getSize() > 0) {
				FileWriter << endl;
				RecursiveWriterTxtCourseFile(0, User->getCourseList()->getSize() - 1);
			}

			FileWriter << endl << User->getDiplomaList()->getSize();
			if (User->getDiplomaList()->getSize() > 0) {
				FileWriter << endl;
				RecursiveWriterTxtDiplomaFile(0, User->getDiplomaList()->getSize() - 1);
			}

			FileWriter << endl << User->getNotificationHeap()->getSize();
			if (User->getNotificationHeap()->getSize() > 0) {
				FileWriter << endl;
				RecursiveWriterTxtDiplomaFile(0, User->getNotificationHeap()->getSize() - 1);
			}
			FileWriter.close();
		}
	}
}
void Crehana::DisplayCrehanaCourses() {
	RecursiveDisplayCourse(0, Courses->getSize() - 1, 'C');

	do {
		cout << " get source course ";
		cin >> Selection;
	} while (Selection < 1 || Selection > Courses->getSize());
	Selection--;

	cout << "                             "; _sleep(PauseTime / 10);
	for (int i = 0; i < 20; i++)
		cout << char(220);
	cout << endl; _sleep(PauseTime / 10);
	cout << "                             " << char(219) << "                  " << char(219) << endl; _sleep(PauseTime / 10);
	cout << "                             " << char(219) << "     Section:     " << char(219) << endl; _sleep(PauseTime / 10);
	cout << "                             " << char(219) << "                  " << char(219) << endl; _sleep(PauseTime / 10);
	cout << "                             " << char(219) << "       SX19       " << char(219) << endl; _sleep(PauseTime / 10);
	cout << "                             " << char(219) << "                  " << char(219) << endl; _sleep(PauseTime / 10);
	cout << "                             ";
	for (int i = 0; i < 20; i++)
		cout << char(223);
	cout << endl; _sleep(PauseTime / 10);
	cout << "                                   " << char(186) << "      " << char(186) << endl; _sleep(PauseTime / 10);
	cout << "                                   " << char(186) << "      " << char(186) << endl; _sleep(PauseTime / 10);
	cout << "                                   " << char(186) << "      " << char(186) << endl; _sleep(PauseTime / 10);
	cout << "                                   " << char(186) << "      " << char(186) << endl; _sleep(PauseTime / 10);
	cout << "                                   " << char(186) << "      " << char(186) << endl; _sleep(PauseTime / 10);
	cout << "                                   " << char(186) << "      " << char(186) << endl; _sleep(PauseTime / 10);
	cout << "      ";
	for (int i = 0; i < 20; i++)
		cout << char(220);
	cout << "         " << char(186) << "      " << char(186) << "         "; _sleep(PauseTime / 10);
	for (int i = 0; i < 20; i++)
		cout << char(220);
	cout << endl; _sleep(PauseTime / 10);
	cout << "      " << char(219) << "                  " << char(219) << "         " << char(186) << "      " << char(186) << "         " << char(219) << "                  " << char(219) << endl; _sleep(PauseTime / 10);
	cout << "      " << char(219) << "       Day:       " << char(219) << "         " << char(186) << "      " << char(186) << "         " << char(219) << "     Schedule:    " << char(219) << endl; _sleep(PauseTime / 10);
	cout << "      " << char(219) << "                  " << char(219) << " " << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << "      " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << " " << char(219) << "                  " << char(219) << endl; _sleep(PauseTime / 10);
	cout << "      " << char(219); _sleep(PauseTime / 10);

	if (Courses->ObtainIndex(Selection).getCalendar().getSessionDay().size() == 9) {
		cout << "     " << Courses->ObtainIndex(Selection).getCalendar().getSessionDay() << "    ";
	}
	else
		if (Courses->ObtainIndex(Selection).getCalendar().getSessionDay().size() == 8) {
			cout << "     " << Courses->ObtainIndex(Selection).getCalendar().getSessionDay() << "     ";
		}
		else
			if (Courses->ObtainIndex(Selection).getCalendar().getSessionDay().size() == 7) {
				cout << "      " << Courses->ObtainIndex(Selection).getCalendar().getSessionDay() << "     ";
			}
			else
				if (Courses->ObtainIndex(Selection).getCalendar().getSessionDay().size() == 6) {
					cout << "      " << Courses->ObtainIndex(Selection).getCalendar().getSessionDay() << "      ";
				}
	_sleep(PauseTime / 10);
	cout << char(219) << "                          " << char(219) << "   " << Courses->ObtainIndex(Selection).getCalendar().getCalendarTime().getStartTime() << "--" << Courses->ObtainIndex(Selection).getCalendar().getCalendarTime().getFinishTime() << "   " << char(219) << endl; _sleep(PauseTime / 10);
	cout << "      " << char(219) << "                  " << char(219) << "                          " << char(219) << "                  " << char(219) << endl; _sleep(PauseTime / 10);
	cout << "      "; _sleep(PauseTime / 10);
	for (int i = 0; i < 20; i++)
		cout << char(223);
	cout << "                          "; _sleep(PauseTime / 10);
	for (int i = 0; i < 20; i++)
		cout << char(223);
	cout << endl; _sleep(PauseTime / 10);

	cout << " enroll in the course: [Y/n] ";
	cin >> OptionSelective;

	if (toupper(OptionSelective.at(0)) != 'Y') {
		return;
	}

	if (User->getCourseList()->getSize() > 0) {
		RecursiveCourseEnrollment(0, User->getCourseList()->getSize() - 1);
	}
	else {
		User->getCourseList()->AddToEnd(new Course(Courses->ObtainIndex(Selection).getCourseName(), Courses->ObtainIndex(Selection).getCourseSection(), Courses->ObtainIndex(Selection).getCalendar().getSessionDay(), Courses->ObtainIndex(Selection).getCalendar().getCalendarTime().getStartTime(), Courses->ObtainIndex(Selection).getCalendar().getCalendarTime().getFinishTime(), to_string(Courses->ObtainIndex(Selection).getSessionQueue()->getSize()), float(0.0 + rand() % +6)));
		User->getNotificationHeap()->Push(Notification("Enrolment", Courses->ObtainIndex(Selection).getCourseName()));
		CoverterTotxt = User->getStudentID() + ".txt";

		FileWriter.open(CoverterTotxt, ios::out);
		if (FileWriter.is_open()) {
			FileWriter << User->getCourseList()->getSize() << endl;
			RecursiveWriterTxtCourseFile(0, User->getCourseList()->getSize() - 1);

			FileWriter << endl << User->getDiplomaList()->getSize();
			if (User->getDiplomaList()->getSize() > 0) {
				FileWriter << endl;
				RecursiveWriterTxtDiplomaFile(0, User->getDiplomaList()->getSize() - 1);
			}

			FileWriter << endl << User->getNotificationHeap()->getSize();
			if (User->getNotificationHeap()->getSize() > 0) {
				FileWriter << endl;
				RecursiveWriterTxtNotificationFile(0, User->getNotificationHeap()->getSize() - 1);
			}
			FileWriter.close();
		}
	}
}

void Crehana::RecursiveReaderTxtCrehanaDataBase(size_t Iter, int Limitation, char ClassType) {
	/// [   RECURSION LIMITATION   ]
	if (Iter > Limitation) {
		return;
	}
	/// [   RECURSION LIMITATION   ]

	if (ClassType == 'L') {
		string LastNameData;

		getline(FileReader, LastNameData);

		LastNames->Add(LastName(LastNameData));
	}
	else
		if (ClassType == 'N') {
			string NameData;

			getline(FileReader, NameData);

			Names->Add(Name(NameData));
		}

	/// [   RECURSION   ]
	RecursiveReaderTxtCrehanaDataBase(Iter + 1, Limitation, ClassType);
	/// [   RECURSION   ]
}
void Crehana::RecursiveReaderTxtCourseFile(size_t Iter, int Limitation, char ClassType) {
	/// [   RECURSION LIMITATION   ]
	if (Iter > Limitation) {
		return;
	}
	/// [   RECURSION LIMITATION   ]


	/// [   COURSE-RELATED VARIABLES   ]
	string CourseName;
	string CourseSection;
	string SessionDay;
	string StartTime;
	string FinishTime;
	/// [   COURSE-RELATED VARIABLES   ]


	/// [   CLASS SELECTION   ]
	if (ClassType == 'C') {
		if (RestartSystem == true && Iter == 0) {
			cout << "              Starting Load/Save Random Seed... " << endl; _sleep(PauseTime);
		}


		/// [   CREHANA COURSE-DATA READING   ]
		getline(FileReader, CourseName);
		getline(FileReader, CourseSection);
		getline(FileReader, SessionDay);
		getline(FileReader, StartTime);
		getline(FileReader, FinishTime);
		/// [   CREHANA COURSE-DATA READING   ]


		if (RestartSystem == true && Iter == 0) {
			cout << "              Starting Objects Construction System... " << endl << endl; _sleep(PauseTime);
		}
		/// [   COURSE CREATOR   ]
		Courses->AddToEnd(Course(CourseName, CourseSection, SessionDay, StartTime, FinishTime, to_string(3), float(0.0 + rand() % +6)));
		/// [   COURSE CREATOR   ]
	}
	else
		if (ClassType == 'S') {
			/// [   STUDENT COURSE-RELATED VARIABLES   ]
			string SessionCount;
			/// [   STUDENT COURSE-RELATED VARIABLES   ]


			/// [   STUDENT COURSE-DATA READING   ]
			getline(FileReader, CourseName);
			getline(FileReader, CourseSection);
			getline(FileReader, SessionDay);
			getline(FileReader, StartTime);
			getline(FileReader, FinishTime);
			getline(FileReader, SessionCount);
			/// [   STUDENT COURSE-DATA READING   ]


			/// [   COURSE CREATOR   ]
			Students->ObtainEnd()->getCourseList()->AddToEnd(new Course(CourseName, CourseSection, SessionDay, StartTime, FinishTime, SessionCount, float(0.0 + rand() % +6)));
			/// [   COURSE CREATOR   ]
		}
	/// [   CLASS SELECTION   ]


	/// [   RECURSION   ]
	RecursiveReaderTxtCourseFile(Iter + 1, Limitation, ClassType);
	/// [   RECURSION   ]
}
void Crehana::RecursiveReaderTxtPersonFile(size_t Iter, int Limitation, char ClassType) {
	/// [   RECURSION LIMITATION   ]
	if (Iter > Limitation) {
		return;
	}
	/// [   RECURSION LIMITATION   ]


	/// [   PERSON-RELATED VARIABLES   ]
	string FirstName;
	string SecondName;
	string LastName;
	string MothersLastName;
	string Age;
	/// [   STUDENT-RELATED VARIABLES   ]


	/// [   CLASS SELECTION   ]
	if (ClassType == 'T') {
	}
	else
		if (ClassType == 'S') {
			/// [   STUDENT-RELATED VARIABLES   ]
			string StudentID;
			string Password;
			/// [   STUDENT-RELATED VARIABLES   ]

			/// [   STUDENT-DATA INPUT   ]
			getline(FileIO, FirstName);
			getline(FileIO, SecondName);
			getline(FileIO, LastName);
			getline(FileIO, MothersLastName);
			getline(FileIO, Age);
			getline(FileIO, StudentID);
			getline(FileIO, Password);
			/// [   STUDENT-DATA INPUT   ]
			if (RestartSystem == true && Iter == Limitation) {
				cout << " [   OK   ]   Started Read File System." << endl << endl; _sleep(PauseTime);
				cout << " [   OK   ]   Started Load/Save Random Seed." << endl << endl; _sleep(PauseTime);
			}

			/// [   STUDENT CREATOR   ]
			Students->AddToEnd(new Student(FirstName, SecondName, LastName, MothersLastName, stoi(Age), StudentID, Password));
			Students2->Add(new Student(FirstName, SecondName, LastName, MothersLastName, stoi(Age), StudentID, Password));
			Students3->Add(new Student(FirstName, SecondName, LastName, MothersLastName, stoi(Age), StudentID, Password), StudentID);
			/// [   STUDENT CREATOR   ]
			if (RestartSystem == true && Iter == Limitation) {
				cout << " [   OK   ]   Started Objects Construction System." << endl << endl << endl; _sleep(PauseTime);
			}


			/// [   USER-ID TXT CONVERTER   ]
			CoverterTotxt = StudentID + ".txt";
			/// [   USER-ID TXT CONVERTER   ]


			/// [   USER FILE OPENDED   ]
			FileReader.open(CoverterTotxt, ios::in);
			/// [   USER FILE OPENDED   ]


			/// [   USER FILE VIEWER   ]
			if (FileReader.is_open()) {
				/// [   OBJECT QUANTITY INPUT   ]
				getline(FileReader, ObjectQuantity);
				/// [   OBJECT QUANTITY INPUT   ]


				/// [   COURSE RETRIEVAL   ]
				if (stoi(ObjectQuantity) != 0) {
					RecursiveReaderTxtCourseFile(0, stoi(ObjectQuantity) - 1, 'S');
				}
				/// [   COURSE RETRIEVAL   ]


				/// [   OBJECT QUANTITY INPUT   ]
				getline(FileReader, ObjectQuantity);
				/// [   OBJECT QUANTITY INPUT   ]


				/// [   DIPLOMA RETRIEVAL   ]
				if (stoi(ObjectQuantity) != 0) {
					RecursiveReaderTxtDiplomaFile(0, stoi(ObjectQuantity) - 1);
				}
				/// [   DIPLOMA RETRIEVAL   ]


				/// [   OBJECT QUANTITY INPUT   ]
				getline(FileReader, ObjectQuantity);
				/// [   OBJECT QUANTITY INPUT   ]


				/// [   NOTIFICATION RETRIEVAL   ]
				if (stoi(ObjectQuantity) != 0) {
					RecursiveReaderTxtNotificationFile(0, stoi(ObjectQuantity) - 1);
				}
				/// [   NOTIFICATION RETRIEVAL   ]


				/// [   USER FILE CLOSED   ]
				FileReader.close();
				/// [   USER FILE CLOSED   ]
			}
			/// [   USER FILE VIEWER   ]
		}
	/// [   CLASS SELECTION   ]


	/// [   RECURSION   ]
	RecursiveReaderTxtPersonFile(Iter + 1, Limitation, ClassType);
	/// [   RECURSION   ]
}
void Crehana::RecursiveReaderTxtDiplomaFile(size_t Iter, int Limitation) {
	/// [   RECURSION LIMITATION   ]
	if (Iter > Limitation) {
		return;
	}
	/// [   RECURSION LIMITATION   ]


	/// [   DIPLOMA-RELATED VARIABLES   ]
	string DiplomaTitle;
	string ReceiverName;
	string AchievementHonor;
	/// [   DIPLOMA-RELATED VARIABLES   ]


	/// [   DIPLOMA-DATA READING   ]
	getline(FileReader, DiplomaTitle);
	getline(FileReader, ReceiverName);
	getline(FileReader, AchievementHonor);
	/// [   DIPLOMA-DATA READING   ]


	/// [   DIPLOMA CREATOR   ]
	Students->ObtainEnd()->getDiplomaList()->AddToEnd(Diploma(DiplomaTitle, ReceiverName, AchievementHonor));
	/// [   DIPLOMA CREATOR   ]


	/// [   RECURSION   ]
	RecursiveReaderTxtDiplomaFile(Iter + 1, Limitation);
	/// [   RECURSION   ]
}
void Crehana::RecursiveReaderTxtNotificationFile(size_t Iter, int Limitation) {
	/// [   RECURSION LIMITATION   ]
	if (Iter > Limitation) {
		return;
	}
	/// [   RECURSION LIMITATION   ]


	/// [   DIPLOMA-RELATED VARIABLES   ]
	string Type;
	string Name;
	/// [   DIPLOMA-RELATED VARIABLES   ]


	/// [   DIPLOMA-DATA READING   ]
	getline(FileReader, Type);
	getline(FileReader, Name);
	/// [   DIPLOMA-DATA READING   ]


	/// [   DIPLOMA CREATOR   ]
	Students->ObtainEnd()->getNotificationHeap()->Push(Notification(Type, Name));
	/// [   DIPLOMA CREATOR   ]


	/// [   RECURSION   ]
	RecursiveReaderTxtNotificationFile(Iter + 1, Limitation);
	/// [   RECURSION   ]
}

void Crehana::RecursiveWriterTxtCourseFile(size_t Iter, size_t Limitation) {
	/// [   RECURSION LIMITATION   ]
	if (Iter > Limitation) {
		return;
	}
	/// [   RECURSION LIMITATION   ]


	/// [   USER COURSE-DATA WRITING   ]
	FileWriter << User->getCourseList()->ObtainIndex(Iter)->getCourseName() << endl;
	FileWriter << User->getCourseList()->ObtainIndex(Iter)->getCourseSection() << endl;
	FileWriter << User->getCourseList()->ObtainIndex(Iter)->getCalendar().getSessionDay() << endl;
	FileWriter << User->getCourseList()->ObtainIndex(Iter)->getCalendar().getCalendarTime().getStartTime() << endl;
	FileWriter << User->getCourseList()->ObtainIndex(Iter)->getCalendar().getCalendarTime().getFinishTime() << endl;
	FileWriter << User->getCourseList()->ObtainIndex(Iter)->getSessionQueue()->getSize();
	/// [   USER COURSE-DATA WRITING   ]


	/// [   LINE BREAK   ]
	if (Iter != Limitation) {
		FileWriter << endl;
	}
	/// [   LINE BREAK   ]


	/// [   RECURSION   ]
	RecursiveWriterTxtCourseFile(Iter + 1, Limitation);
	/// [   RECURSION   ]
}
void Crehana::RecursiveWriterTxtStudentFile(size_t Iter, size_t Limitation) {
	/// [   RECURSION LIMITATION   ]
	if (Iter > Limitation) {
		return;
	}
	/// [   RECURSION LIMITATION   ]


	/// [   STUDENTS-DATA WRITING   ]
	FileWriter << Students->ObtainIndex(Iter)->getFirstName() << endl;
	FileWriter << Students->ObtainIndex(Iter)->getSecondName() << endl;
	FileWriter << Students->ObtainIndex(Iter)->getLastName() << endl;
	FileWriter << Students->ObtainIndex(Iter)->getMothersLastName() << endl;
	FileWriter << Students->ObtainIndex(Iter)->getAge() << endl;
	FileWriter << Students->ObtainIndex(Iter)->getStudentID() << endl;
	FileWriter << Students->ObtainIndex(Iter)->getPassword();
	/// [   STUDENTS-DATA WRITING   ]


	/// [   LINE BREAK   ]
	if (Iter != Limitation) {
		FileWriter << endl;
	}
	/// [   LINE BREAK   ]


	/// [   RECURSION   ]
	RecursiveWriterTxtStudentFile(Iter + 1, Limitation);
	/// [   RECURSION   ]
}
void Crehana::RecursiveWriterTxtDiplomaFile(size_t Iter, size_t Limitation) {
	/// [   RECURSION LIMITATION   ]
	if (Iter > Limitation) {
		return;
	}
	/// [   RECURSION LIMITATION   ]


	/// [   USER DIPLOMA-DATA WRITING   ]
	FileWriter << User->getDiplomaList()->ObtainIndex(Iter).getDiplomaTitle() << endl;
	FileWriter << User->getDiplomaList()->ObtainIndex(Iter).getReceiverName() << endl;
	FileWriter << User->getDiplomaList()->ObtainIndex(Iter).getAchievementHonor();
	/// [   USER DIPLOMA-DATA WRITING   ]


	/// [   LINE BREAK   ]
	if (Iter != Limitation) {
		FileWriter << endl;
	}
	/// [   LINE BREAK   ]


	/// [   RECURSION   ]
	RecursiveWriterTxtDiplomaFile(Iter + 1, Limitation);
	/// [   RECURSION   ]
}
void Crehana::RecursiveWriterTxtNotificationFile(size_t Iter, int Limitation) {
	/// [   RECURSION LIMITATION   ]
	if (Iter > Limitation) {
		return;
	}
	/// [   RECURSION LIMITATION   ]


	/// [   USER NOTIFICATION-DATA WRITING   ]
	FileWriter << User->getNotificationHeap()->getHeapNode(Iter)->getObject().getType() << endl;
	FileWriter << User->getNotificationHeap()->getHeapNode(Iter)->getObject().getName();
	/// [   USER NOTIFICATION-DATA WRITING   ]


	/// [   LINE BREAK   ]
	if (Iter != Limitation) {
		FileWriter << endl;
	}
	/// [   LINE BREAK   ]


	/// [   RECURSION   ]
	RecursiveWriterTxtNotificationFile(Iter + 1, Limitation);
	/// [   RECURSION   ]
}

void Crehana::RecursiveDisplayCourse(size_t Iter, size_t Limitation, char ClassType) {
	if (Iter > Limitation)
		return;

	if (ClassType == 'C') {
		cout << " " << char(201);
		for (size_t i = 0; i < 12 + Courses->ObtainIndex(Iter).getCourseName().size(); i++)
			cout << char(205);

		cout << char(187) << endl; _sleep(PauseTime / 10);


		cout << " " << char(186) << "      " << Courses->ObtainIndex(Iter).getCourseName() << "      " << char(186) << endl;


		cout << " " << char(186) << "      ";
		for (int i = 0; i < Courses->ObtainIndex(Iter).getCourseName().size(); i++)
			cout << " ";


		cout << "      " << char(186) << endl; _sleep(PauseTime / 10);


		cout << " " << char(186) << "      ";
		for (int i = 1; i < (Courses->ObtainIndex(Iter).getCourseName().size() / 2) - 1; i++)
			cout << " ";

		cout << Courses->ObtainIndex(Iter).getCourseSection();
		for (int i = 0; i < (Courses->ObtainIndex(Iter).getCourseName().size() / 2) - 1; i++)
			if (Courses->ObtainIndex(Iter).getCourseName().size() % 2 == 0) {
				if (i > 0)
					cout << " ";
			}
			else
				cout << " ";

		cout << "      " << char(186) << endl; _sleep(PauseTime / 10);


		cout << " " << char(186) << "      ";
		for (int i = 0; i < Courses->ObtainIndex(Iter).getCourseName().size(); i++)
			cout << " ";

		cout << "      " << char(186) << endl; _sleep(PauseTime / 10);


		cout << " " << char(186);
		for (int i = 1; i < (Courses->ObtainIndex(Iter).getCourseName().size() / 2) - 1; i++)
			cout << " ";

		cout << "POR: EDIN PIERI";
		for (int i = 0; i < (Courses->ObtainIndex(Iter).getCourseName().size() / 2) - 1; i++)
			if (Courses->ObtainIndex(Iter).getCourseName().size() % 2 == 0) {
				if (i > 0)
					cout << " ";
			}
			else
				cout << " ";

		cout << " " << char(186) << endl; _sleep(PauseTime / 10);


		cout << " " << char(186) << "      ";
		for (int i = 0; i < Courses->ObtainIndex(Iter).getCourseName().size(); i++)
			cout << " ";

		cout << "      " << char(186) << endl; _sleep(PauseTime / 10);


		cout << " " << char(186) << "      ";
		for (int i = 0; i < Courses->ObtainIndex(Iter).getCourseName().size(); i++)
			cout << " ";

		cout << "      " << char(186) << endl; _sleep(PauseTime / 10);


		if (Students->getSize() < 10)
			cout << " " << char(186) << " " << 1 + rand() % 9 << " STUDENTS";
		else
			cout << " " << char(186) << " " << 10 + rand() % 90 << " STUDENTS";

		for (int i = 0; i < Courses->ObtainIndex(Iter).getCourseName().size() - 6; i++)
			cout << " ";

		cout << char(2) << " " << Courses->ObtainIndex(Iter).getCourseRating().getQuantity() << " " << char(186) << endl; _sleep(PauseTime / 10);


		cout << " " << char(200);
		for (size_t i = 0; i < 12 + Courses->ObtainIndex(Iter).getCourseName().size(); i++)
			cout << char(205);

		cout << char(188);
		cout << endl; _sleep(PauseTime / 10);


		for (int i = 1; i < (Courses->ObtainIndex(Iter).getCourseName().size() / 2); i++)
			cout << " ";

		cout << "       |" << Iter + 1 << "|" << endl << endl; _sleep(PauseTime / 10);
	}
	else
		if (ClassType == 'S') {
			cout << " " << char(201) << char(205);
			for (int i = 0; i < User->getCourseList()->ObtainIndex(Iter)->getCourseName().size(); i++)
				cout << char(205);

			cout << char(205) << char(187);

			cout << endl; _sleep(PauseTime / 10);

			cout << " " << char(186) << " " << User->getCourseList()->ObtainIndex(Iter)->getCourseName() << " " << char(186) << " |" << Iter + 1 << "|";

			cout << endl; _sleep(PauseTime / 10);

			cout << " " << char(200) << char(205);
			for (int i = 0; i < User->getCourseList()->ObtainIndex(Iter)->getCourseName().size(); i++)
				cout << char(205);

			cout << char(205) << char(188);
			cout << endl; _sleep(PauseTime / 10);


		}
	RecursiveDisplayCourse(Iter + 1, Limitation, ClassType);
}
void Crehana::RecursiveDisplayStudentsAccount(size_t Iter, size_t Limitation) {
	/// [   RECURSION LIMITATION   ]
	if (Iter > Limitation)
		return;
	/// [   RECURSION LIMITATION   ]

	if (Iter == 0) {
		cout << " root trace recruited accounts "; Message = "power:/\n\n\n";
		for (string::iterator i = Message.begin(); i != Message.end(); ++i)
			cout << i.operator*();
	}
	Message = "";

	cout << " " << Iter + 1 << "    [" << Students->ObtainIndex(Iter)->getFirstName() << "." << Students->ObtainIndex(Iter)->getLastName().at(0);

	for (size_t i = Students->ObtainIndex(Iter)->getFirstName().size() + 2; i < 15; i++) {
		cout << " ";
	}
	cout << Students->ObtainIndex(Iter)->getStudentID() << "     ";


	int step = 1;
	for (DoubleCircularLinkedList<Student*>::Iterator i = Students->begin(); i != Students->end(); ++i) {
		if (i.Index != Iter)
			if (Students->ObtainIndex(Iter)->getLastName() > Students->ObtainIndex(i.Index)->getLastName())
				step++;
	}

	for (size_t i = 0; i < ((100 * step) / Students->getSize()) / 2; i++)
		Message += char(179);

	for (size_t i = 0; i < Message.size(); i++) {
		cout << Message[i];
	}

	for (size_t i = ((100 * step) / Students->getSize()) / 2; i < 50; i++) {
		cout << " ";
	}

	cout << "]" << endl << endl;
	/// [   RECURSION   ]
	RecursiveDisplayStudentsAccount(Iter + 1, Limitation);
	/// [   RECURSION   ]
}
void Crehana::RecursiveDisplayUserCalendar(size_t Iter, size_t Limitation) {
	if (Iter == 0) {
		cout << " " << char(201);
		for (size_t i = 0; i < 6; i++)
		{
			if (i != 0) {
				cout << char(203);
			}
			for (size_t j = 0; j < 13; j++)
			{
				cout << char(205);
			}
			if (i == 5) {
				cout << char(187);
			}
		}
		cout << endl; _sleep(PauseTime / 10);
		cout << " " << char(186);
		cout << "  Hora/Dia   ";
		cout << char(186);
		cout << "      L      ";
		cout << char(186);
		cout << "      M      ";
		cout << char(186);
		cout << "      M      ";
		cout << char(186);
		cout << "      J      ";
		cout << char(186);
		cout << "      V      ";
		cout << char(186);
		cout << endl; _sleep(PauseTime / 10);
		cout << " " << char(204);
		for (size_t i = 0; i < 6; i++)
		{
			if (i != 0) {
				cout << char(206);
			}
			for (size_t j = 0; j < 13; j++)
			{
				cout << char(205);
			}
			if (i == 5) {
				cout << char(185);
			}
		}
		cout << endl; _sleep(PauseTime / 10);
	}
	if (Iter > Limitation) {
		return;
	}

	if (Iter > 0) {
		cout << endl; _sleep(PauseTime / 10);
	}
	cout << " " << char(186);
	if (Iter < 2) {
		cout << " 0" << 7 + Iter << ":00-0" << 7 + Iter + 1 << ":00 ";
	}
	else if (Iter == 2) {
		cout << " 0" << 7 + Iter << ":00-" << 7 + Iter + 1 << ":00 ";
	}
	else if (Iter > 2) {
		cout << " " << 7 + Iter << ":00-" << 7 + Iter + 1 << ":00 ";
	}

	string days[] = { "Lunes","Martes","Miercoles","Jueves","Viernes" };

	for (size_t j = 0; j < 5; j++)
	{
		if (User->getCourseList()->getSize() > 0) {
			if (Iter < 2) {
				for (size_t t = 0; t < User->getCourseList()->getSize(); t++)
				{
					if (User->getCourseList()->ObtainIndex(t)->getCalendar().getSessionDay() == days[j] && (User->getCourseList()->ObtainIndex(t)->getCalendar().getCalendarTime().getStartTime() == "0" + to_string(7 + Iter) + ":00" || User->getCourseList()->ObtainIndex(t)->getCalendar().getCalendarTime().getFinishTime() == "0" + to_string(7 + Iter + 1) + ":00")) {
						cout << char(186) << "    " << User->getCourseList()->ObtainIndex(t)->getCourseSection() << "     ";
						break;
					}
					else {
						if (t == User->getCourseList()->getSize() - 1) {
							cout << char(186) << "             ";
						}
					}
				}
			}
			else
				if (Iter == 2) {
					for (size_t t = 0; t < User->getCourseList()->getSize(); t++)
					{
						if (User->getCourseList()->ObtainIndex(t)->getCalendar().getSessionDay() == days[j] && (User->getCourseList()->ObtainIndex(t)->getCalendar().getCalendarTime().getStartTime() == "0" + to_string(7 + Iter) + ":00" || User->getCourseList()->ObtainIndex(t)->getCalendar().getCalendarTime().getFinishTime() == to_string(7 + Iter + 1) + ":00")) {
							cout << char(186) << "    " << User->getCourseList()->ObtainIndex(t)->getCourseSection() << "     ";
							break;
						}
						else {
							if (t == User->getCourseList()->getSize() - 1) {
								cout << char(186) << "             ";
							}
						}
					}
				}
				else
					if (Iter > 2) {
						for (size_t t = 0; t < User->getCourseList()->getSize(); t++)
						{
							if (User->getCourseList()->ObtainIndex(t)->getCalendar().getSessionDay() == days[j] && (User->getCourseList()->ObtainIndex(t)->getCalendar().getCalendarTime().getStartTime() == to_string(7 + Iter) + ":00" || User->getCourseList()->ObtainIndex(t)->getCalendar().getCalendarTime().getFinishTime() == to_string(7 + Iter + 2) + ":00" || User->getCourseList()->ObtainIndex(t)->getCalendar().getCalendarTime().getFinishTime() == to_string(7 + Iter + 1) + ":00")) {
								cout << char(186) << "    " << User->getCourseList()->ObtainIndex(t)->getCourseSection() << "     ";
								break;
							}
							else {
								if (t == User->getCourseList()->getSize() - 1) {
									cout << char(186) << "             ";
								}
							}
						}
					}
		}
		else {
			cout << char(186) << "             ";
		}
	}

	cout << char(186);
	cout << endl; _sleep(PauseTime / 10);

	for (size_t i = 0; i < 6; i++)
	{
		if (i == 0 && Iter == 15) {
			cout << " " << char(200);
		}
		else
			if (i == 0) {
				cout << " " << char(204);
			}

		for (size_t j = 0; j < 13; j++)
		{
			cout << char(205);
		}
		if (Iter == 15) {
			if (i == 5) {
				cout << char(188);
			}
			else {
				cout << char(202);
			}
		}
		else {
			if (i == 5) {
				cout << char(185);
			}
			else {
				cout << char(206);
			}
		}
	}
	RecursiveDisplayUserCalendar(Iter + 1, Limitation);
}
void Crehana::RecursiveCourseEnrollment(size_t Iter, size_t Limitation) {
	if (Iter > Limitation) {
		return;
	}

	if (User->getCourseList()->ObtainIndex(Iter)->getCourseName() == Courses->ObtainIndex(Selection).getCourseName()) {
		cout << " --Ya estas inscrito a este curso--";
		return;
	}
	else
		if (User->getCourseList()->ObtainIndex(Iter)->getCalendar().getSessionDay() == Courses->ObtainIndex(Selection).getCalendar().getSessionDay()) {
			if (User->getCourseList()->ObtainIndex(Iter)->getCalendar().getCalendarTime().getStartTime() == Courses->ObtainIndex(Selection).getCalendar().getCalendarTime().getStartTime() || User->getCourseList()->ObtainIndex(Iter)->getCalendar().getCalendarTime().getStartTime() == Courses->ObtainIndex(Selection).getCalendar().getCalendarTime().getFinishTime() || User->getCourseList()->ObtainIndex(Iter)->getCalendar().getCalendarTime().getFinishTime() == Courses->ObtainIndex(Selection).getCalendar().getCalendarTime().getFinishTime() || User->getCourseList()->ObtainIndex(Iter)->getCalendar().getCalendarTime().getFinishTime() == Courses->ObtainIndex(Selection).getCalendar().getCalendarTime().getStartTime()) {
				cout << " --Tienes un cruce con otro curso--";
				return;
			}
		}
		else {
			if (Iter == User->getCourseList()->getSize() - 1) {
				User->getCourseList()->AddToEnd(new Course(Courses->ObtainIndex(Selection).getCourseName(), Courses->ObtainIndex(Selection).getCourseSection(), Courses->ObtainIndex(Selection).getCalendar().getSessionDay(), Courses->ObtainIndex(Selection).getCalendar().getCalendarTime().getStartTime(), Courses->ObtainIndex(Selection).getCalendar().getCalendarTime().getFinishTime(), to_string(Courses->ObtainIndex(Selection).getSessionQueue()->getSize()), float(0.0 + rand() % +5)));
				User->getNotificationHeap()->Push(Notification("Enrolment", Courses->ObtainIndex(Selection).getCourseName()));

				CoverterTotxt = User->getStudentID() + ".txt";

				FileWriter.open(CoverterTotxt, ios::out);
				if (FileWriter.is_open()) {
					FileWriter << User->getCourseList()->getSize() << endl;
					RecursiveWriterTxtCourseFile(0, User->getCourseList()->getSize() - 1);

					FileWriter << endl << User->getDiplomaList()->getSize();
					if (User->getDiplomaList()->getSize() > 0) {
						FileWriter << endl;
						RecursiveWriterTxtDiplomaFile(0, User->getDiplomaList()->getSize() - 1);
					}
					FileWriter << endl << User->getNotificationHeap()->getSize();
					if (User->getNotificationHeap()->getSize() > 0) {
						FileWriter << endl;
						RecursiveWriterTxtNotificationFile(0, User->getNotificationHeap()->getSize() - 1);
					}
					FileWriter.close();
				}
				return;
			}
		}
	RecursiveCourseEnrollment(Iter + 1, Limitation);
}

void Crehana::FisherYatesShuffle() {
	Students->FisherYatesShuffle();
}
void Crehana::ExchangeSort() {
	for (size_t i = 0; i < Students->getSize() - 1; i++)
	{
		for (size_t j = i + 1; j < Students->getSize(); j++)
		{
			Students->ExchangeSort(Students->ObtainIndex(i)->getLastName(), i, Students->ObtainIndex(j)->getLastName(), j);
		}
	}
}
void Crehana::BubbleSort() {
	for (size_t i = 0; i < Students->getSize() - 1; i++)
	{
		for (size_t j = i + 1; j < Students->getSize(); j++)
		{
			Students->ExchangeSort(Students->ObtainIndex(i)->getStudentID(), i, Students->ObtainIndex(j)->getStudentID(), j);
		}
	}
}
#endif //!__CREHANA_H__

void Crehana_Vbeta() {
	srand(time(NULL));
	Crehana CrehanaVbeta;
	CrehanaVbeta.CrehanaVbeta();
}