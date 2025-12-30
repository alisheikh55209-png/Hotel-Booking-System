/*
	================================================================================
	Project Title	: Hotel Booking/Reservation System
	Language		: C++
	Version			: 2.0 (Enhanced)
	
	Team Members:
	- M. Ali Sheikh (70151489) - Team Lead
	- Zaid (70149441)
	- Anas Abid (70150234)
	- Hussain Muavia (70147427)
	
	Date Created	: 14-05-2024
	Last Updated	: 31-12-2025
	Submitted to	: Miss Areej
	
	Enhancements:
	- Improved input validation
	- Enhanced error handling
	- Better file management
	- Input bounds checking
	- Safer string operations
	================================================================================
*/

#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<cctype>

using namespace std;

// Constants for validation
const int MAX_ROOM_NO = 10;
const int MAX_NAME = 20;
const int MAX_ADDRESS = 25;
const int MAX_PHONE = 35;
const int MAX_NATIONALITY = 15;
const int MAX_EMAIL = 20;
const int MAX_PERIOD = 10;
const int MAX_DATE = 10;
const int MAX_USERNAME = 10;
const int MAX_PASSWORD = 10;
const string DATABASE_FILE = "add.txt";

void add();
void list();
void edit();
void delete1();
void search();

void setcolor(int ForgC) {
 
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut,&csbi)) { 
    
        wColor = (csbi.wAttributes & 0xB0)+(ForgC & 0x0B);
        SetConsoleTextAttribute(hStdOut,wColor);
        
    }
}

void login() {
	
    int a = 0, i = 0;
    char uname[MAX_USERNAME], c = ' ';
    char pword[MAX_PASSWORD];
    const char user[] = "user";
    const char pass[] = "pass";
    
    do { 
        system("cls");
        
        cout << "\n   +----------------------------------------------------------------+  ";
        cout << "\n   |               STEP  INTO   OUR  DIGITAL  HOTEL(AZAH)           |  ";
        cout << "\n   +________________________________________________________________+  ";
        cout << endl;

        cout << "\n   **************************  LOGIN FORM  **************************  ";
        cout << "\n                          ENTER USERNAME: ";
        
        // Secure input with bounds checking
        cin.getline(uname, MAX_USERNAME);
        if(cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        
        cout << "\n                          ENTER PASSWORD: ";
        
        i = 0;
        while(i < MAX_PASSWORD - 1) {
            c = getch();
            if(c == 13) break;  // Enter key
            if(c == 8) {        // Backspace
                if(i > 0) {
                    i--;
                    cout << "\b \b";
                }
                continue;
            }
            pword[i] = c;
            cout << "*";
            i++;
        }
        
        pword[i] = '\0';
        
        if(strcmp(uname, user) == 0 && strcmp(pword, pass) == 0) {
            cout << "\n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL";
            Sleep(1500);
            break;
        }
        else {
            cout << "\n        SORRY !!!!  LOGIN UNSUCCESSFUL";
            cout << "\n        Attempt " << (a + 1) << " of 3";
            a++;
            cout << "\n Press any key to continue...";
            getch();
        }
        
    } while(a <= 2);
    
    if(a > 2) {
        cout << "\nSorry! You have exceeded maximum login attempts. Exiting...";
        Sleep(2000);
        exit(0);
    }
    
    system("cls");
}

	struct CustomerDetails {
	
    	char roomnumber[10];
    	char name[20];
    	char address[25];
    	char phonenumber[35];
    	char nationality[15];
    	char email[20];
    	char period[10];
    	char arrivaldate[10];
}s;

	int main() {
	
    	int i=0;
    	time_t t;
    	time(&t);
    	char customername;
    	char choice;
    	login();
    	system("cls");
    
		while (true) {
    	
        	system("cls");
        	setcolor(10);
        	
			for(i=0;i<80;i++)
            cout << "-";
        	cout << "\n";
        	cout << "   ******************************  |MAIN MENU|  ***************************** \n";
        
			for(i=0;i<80;i++)
            cout << "-";
        	cout << "\n";
        	setcolor(10);
        	cout << "\t\t *Please enter your choice for menu*:";
        	cout << "\n\n";
        	cout << "+-----------------------------------+";
        	cout << " \n| Enter 1 -> Book a room            |";
        	cout << "\n+----------------------------------+|";
        	cout << " \n| Enter 2 -> View Customer Record   |";
        	cout << "\n+----------------------------------+|";
        	cout << " \n| Enter 3 -> Delete Customer Record |";
        	cout << "\n+----------------------------------+|";
        	cout << " \n| Enter 4 -> Search Customer Record |";
        	cout << "\n+-----------------------------------+";
        	cout << " \n| Enter 5 -> Edit Record            |";
        	cout << "\n+-----------------------------------+";
        	cout << " \n| Enter 6 -> Exit                   |";
        	cout << "\n+-----------------------------------+";
        	cout << "\n";
        	
			for(i=0;i<80;i++)
          	  	cout << "-";
        		cout << "\nCurrent date and time : " << ctime(&t);
        		for(i=0;i<80;i++)
            	cout << "-";
        		choice = _getche();
        		choice = toupper(choice);
        		switch(choice) {
        	
            	case '1':
                	add();break;
            	case '2':
                	list();break;
            	case '3':
                	delete1();break;
            	case '4':
                	search();break;
            	case '5':
                	edit();break;
            	case '6':
                	system("cls");
                
				cout << "\n\n\t *****THANK YOU*****";
                cout << "\n\t FOR TRUSTING OUR SERVICE";
                exit(0);
                break;
            
			default:
                system("cls");
                cout << "Incorrect Input";
                cout << "\n Press any key to continue";
                cin.get();
        }
    }
}

	void add() {
	
    	ofstream f;
    	char test;
    	f.open(DATABASE_FILE, ios::app | ios::binary);
    	
    	if(!f.is_open()) {
    		f.open(DATABASE_FILE, ios::out | ios::binary);
    		if(!f.is_open()) {
    			system("cls");
    			cout << "ERROR: Cannot create database file!";
    			cout << "\nPress any key to continue...";
    			getch();
    			return;
    		}
        	system("cls");
        	cout << "Setting up database...";
        	cout << "\nProcess completed. Press any key to continue!";
        	getch();
    	}
    	
		while(true) {
        	system("cls");
        	cout << "\n Enter Customer Details:";
        	cout << "\n**************************";
        	
        	// Room number input with validation
        	cout << "\nEnter Room number (1-9999): ";
        	cin >> s.roomnumber;
        	if(cin.fail() || strlen(s.roomnumber) >= MAX_ROOM_NO) {
        		cin.clear();
        		cin.ignore(10000, '\n');
        		cout << "Invalid room number! Press any key...";
        		getch();
        		continue;
        	}
        	cin.ignore();
        	
        	cout << "Enter Name: ";
        	cin.getline(s.name, MAX_NAME);
        	if(strlen(s.name) == 0) {
        		cout << "Name cannot be empty! Press any key...";
        		getch();
        		continue;
        	}
        	
        	cout << "Enter Address: ";
        	cin.getline(s.address, MAX_ADDRESS);
        	
        	cout << "Enter Phone Number: ";
        	cin.getline(s.phonenumber, MAX_PHONE);
        	if(strlen(s.phonenumber) < 10) {
        		cout << "Phone number too short! Press any key...";
        		getch();
        		continue;
        	}
        	
        	cout << "Enter Nationality: ";
        	cin.getline(s.nationality, MAX_NATIONALITY);
        	
        	cout << "Enter Email: ";
        	cin.getline(s.email, MAX_EMAIL);
        	
        	cout << "Enter Period (e.g., 5 days): ";
        	cin.getline(s.period, MAX_PERIOD);
        	
        	cout << "Enter Arrival date (dd/mm/yyyy): ";
        	cin.getline(s.arrivaldate, MAX_DATE);
        	
        	f.write((char*)&s, sizeof(s));
        	
        	cout << "\n\n✓ Room successfully booked!";
        	cout << "\nPress ESC to exit or any other key to add another booking: ";
        	test = _getche();
        	
        	if(test == 27) break;  // ESC key
    	}
    	
    	f.close();
	}

	void list() {
    
		ifstream f;
   	 	int i, count = 0;
    	f.open(DATABASE_FILE, ios::in | ios::binary);
    
		if(!f.is_open()) {
			system("cls");
        	cout << "No records found! Please add a customer first.";
        	cout << "\nPress any key to continue...";
        	getch();
        	return;
    	}
    	
    	system("cls");
    	cout << "\n╔════════════════════════════════════════════════════════════════════════════════════════════════════╗";
    	cout << "\n║                            CUSTOMER RECORDS DATABASE                                                ║";
    	cout << "\n╚════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
    	
    	cout << "ROOM\tNAME\t\tADDRESS\t\tPHONE\t\tNATIONALITY\tEMAIL\t\tPERIOD\tDATE\n";
    	for(i = 0; i < 130; i++) cout << "-";
    	cout << endl;
    	
		while(f.read((char*)&s, sizeof(s))) {
    		cout << s.roomnumber << "\t" << s.name << "\t\t" << s.address << "\t\t" 
    		     << s.phonenumber << "\t" << s.nationality << "\t\t" 
    		     << s.email << "\t\t" << s.period << "\t" << s.arrivaldate << endl;
    		count++;
    	}
    	
    	cout << "\n";
    	for(i = 0; i < 130; i++) cout << "-";
    	cout << "\nTotal Records: " << count << endl;
    	cout << "\nPress any key to continue...";
    	
    	f.close();
    	getch();
	}

	void delete1() {
    	
    	ifstream f;
    	ofstream t;
    	int i = 1;
    	char roomnumber[MAX_ROOM_NO];
    	
    	t.open("temp.txt", ios::out | ios::binary);
    	if(!t.is_open()) {
    		cout << "ERROR: Cannot create temporary file!";
    		getch();
        	return;
    	}
    	
    	f.open(DATABASE_FILE, ios::in | ios::binary);
    	if(!f.is_open()) {
    		cout << "No records found!";
    		getch();
        	return;
    	}
    	
    	system("cls");
    	cout << "Enter the Room Number to delete: ";
    	cin >> roomnumber;
    	cin.ignore();
    	
		while(f.read((char*)&s, sizeof(s))) {
        	if(strcmp(s.roomnumber, roomnumber) == 0) {
            	i = 0;
            	continue;  // Skip this record
        	}
        	t.write((char*)&s, sizeof(s));
    	}
    	
    	f.close();
    	t.close();
    	
    	if(i == 1) {
    		system("cls");
    		cout << "Record not found for room number: " << roomnumber;
    		cout << "\nPress any key to continue...";
        	getch();
        	remove("temp.txt");
    	}
    	else {
    		remove(DATABASE_FILE.c_str());
    		rename("temp.txt", DATABASE_FILE.c_str());
    		system("cls");
    		cout << "✓ Customer record successfully deleted!";
    		cout << "\nPress any key to continue...";
    		getch();
    	}
	}

	void search() {
	
    	system("cls");
    	ifstream f;
    	char roomnumber[MAX_ROOM_NO];
    	int flag = 1;
    	
    	f.open(DATABASE_FILE, ios::in | ios::binary);
    	if(!f.is_open()) {
    		cout << "No records found!";
    		getch();
        	return;
    	}
    	
    	cout << "Enter Room number to search: ";
    	cin >> roomnumber;
    	cin.ignore();
    	
		while(f.read((char*)&s, sizeof(s))) {
    		if(strcmp(s.roomnumber, roomnumber) == 0) {
            	flag = 0;
            	system("cls");
            	cout << "\n╔═══════════════════════════════════════════════════════╗";
            	cout << "\n║              CUSTOMER RECORD FOUND                     ║";
            	cout << "\n╚═══════════════════════════════════════════════════════╝\n";
            	
            	cout << "\nRoom Number:    " << s.roomnumber;
            	cout << "\nName:           " << s.name;
            	cout << "\nAddress:        " << s.address;
            	cout << "\nPhone Number:   " << s.phonenumber;
            	cout << "\nNationality:    " << s.nationality;
            	cout << "\nEmail:          " << s.email;
            	cout << "\nPeriod:         " << s.period;
            	cout << "\nArrival Date:   " << s.arrivaldate;
            	break;
        	}
    	}
    	
	if(flag == 1) {
    	cout << "\n✗ Record not found for room: " << roomnumber;
	}
    	
	cout << "\n\nPress any key to continue...";
	f.close();
    getch();
}

	void edit() {
	
    	fstream f;
    	int k = 1;
    	char roomnumber[MAX_ROOM_NO];
    	long int size = sizeof(s);
    	
    	f.open(DATABASE_FILE, ios::in | ios::out | ios::binary);
    	if(!f.is_open()) {
    		cout << "No records found!";
    		getch();
        	return;
    	}
    	
    	system("cls");
    	cout << "Enter Room number to edit: ";
    	cin >> roomnumber;
    	cin.ignore();

    	while(f.read((char*)&s, sizeof(s))) {
        	if(strcmp(s.roomnumber, roomnumber) == 0) {
            	k = 0;
            	system("cls");
            	cout << "\nEditing record for room: " << roomnumber;
            	cout << "\n========================================\n";
            	
            	cout << "Enter Room Number: ";
            	cin.getline(s.roomnumber, MAX_ROOM_NO);
            	
            	cout << "Enter Name: ";
            	cin.getline(s.name, MAX_NAME);
            	
            	cout << "Enter Address: ";
            	cin.getline(s.address, MAX_ADDRESS);
            	
            	cout << "Enter Phone Number: ";
            	cin.getline(s.phonenumber, MAX_PHONE);
            	
            	cout << "Enter Nationality: ";
            	cin.getline(s.nationality, MAX_NATIONALITY);
            	
            	cout << "Enter Email: ";
            	cin.getline(s.email, MAX_EMAIL);
            	
            	cout << "Enter Period: ";
            	cin.getline(s.period, MAX_PERIOD);
            	
            	cout << "Enter Arrival Date: ";
            	cin.getline(s.arrivaldate, MAX_DATE);
            	
            	f.seekp(-size, ios::cur);
            	f.write((char*)&s, sizeof(s));
            	break;
        	}
    	}
    
    f.close();
    
    if(k == 1) {
    	system("cls");
        cout << "Record not found for room: " << roomnumber;
        cout << "\nPress any key to continue...";
        getch();
    }
    else {
        system("cls");
        cout << "✓ Record successfully edited!";
        cout << "\nPress any key to continue...";
        getch();
    }
}

