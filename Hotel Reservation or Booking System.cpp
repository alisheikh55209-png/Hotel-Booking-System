/*

	Project Title	: Hotel Booking/Reservation System
	Language		: C++
	
	Presented BY	: M. Ali Sheikh (70151489)
					  Zaid (70149441)
					  Anas Abid (70150234)
					  Hussain Muavia (70147427)
					  								
	Date			: 14-05-2024
	Submitted to	: Miss Areej

*/

#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>

using namespace std;

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
	
    int a=0, i=0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do { 
    
        system("cls");
        
        cout << "\n   +----------------------------------------------------------------+  ";
        cout << "\n   |               STEP  INTO   OUR  DIGITAL  HOTEL(AZAH)           |  ";
        cout << "\n   +________________________________________________________________+  ";
        cout << endl;

        cout << "\n   **************************  LOGIN FORM  **************************  ";
        cout << "\n                    	    ENTER USERNAME:-";
        cin >> uname;
        cout << "\n                       	ENTER PASSWORD:-";
        
		while(i<10) {
        	
            int getch;
			pword[i]= getch;
            c=pword[i];
            if(c==13) break;
            else cout << "*";
            i++;
        }
        
        pword[i]='\0';
        i=0;
        
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0) {
        	
            cout << "  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL";
            break;
        }
        
		else {
            
			cout << "\n        SORRY !!!!  LOGIN IS UNSUCESSFUL";
            a++;
            cin.get();

        }
        
    } 
	
	while(a<=2);
    
	if (a>2) {
    	
        cout << "\nSorry you have entered the wrong username and password for three times!!!";
        cin.get();
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
    	f.open("add.txt",ios::app);
    	if(!f.is_open()) {
    	
        f.open("add.txt",ios::out);
        system("cls");
        cout << "Please hold on while we set our database in your computer!!";
        cout << "\n Process completed press any key to continue!! ";
        cin.get();
    } 
	
	while(true)
    
    {
        system("cls");
        cout << "\n Enter Customer Details:";
        cout << "\n**************************";
        cout << "\n Enter Room number:\n";
        cin >> s.roomnumber;
        cin.ignore();
        cout << "Enter Name:\n";
        cin >> s.name;
        cout << "Enter Address:\n";
        cin >> s.address;
        cout << "Enter Phone Number:\n";
        cin >> s.phonenumber;
        cout << "Enter Nationality:\n";
        cin >> s.nationality;
        cout << "Enter Email:\n";
        cin >> s.email;
        cout << "Enter Period(\'x\'days):\n";
        cin >> s.period;
        cout << "Enter Arrival date(dd\\mm\\yyyy):\n";
        cin >> s.arrivaldate;
        f.write((char*)&s,sizeof(s));
        cin.ignore();
        cout << "\n\n1 Room is successfully booked!!";
        cout << "\n Press esc key to exit,  any other key to add another customer detail:";
        test = _getche();
        
		if(test == 27)
            break;
    }
    
	f.close();
}

	void list() {
    
		ifstream f;
   	 	int i;
    	f.open("add.txt",ios::in);
    
		if(!f.is_open())
        exit(0);
    	system("cls");
    	cout << "ROOM    ";
    	cout << "NAME\t ";
    	cout << "\tADDRESS ";
    	cout << "\tPHONENUMBER ";
    	cout << "\tNATIONALITY ";
    	cout << "\tEMAIL ";
    	cout << "\t\tPERIOD ";
    	cout << "\t\tARRIVALDATE \n";

    	for(i=0;i<118;i++)
        	cout << "-";
    		cout << endl;
    	
		while(f.read((char*)&s,sizeof(s))) {
    	
        cout << "\n" << s.roomnumber << "\t" << s.name << "\t\t" << s.address << "\t" << s.phonenumber << "\t" << s.nationality << "\t" << s.email << "\t" << s.period << "\t" << s.arrivaldate;
    
	}
    
    cout << "\n";
    for(i=0;i<118;i++)
        cout << "-";
    cout << endl;
    f.close();
    cin.get();
}

	void delete1() {
    	ifstream f;
    	ofstream t;
    	int i=1;
    	char roomnumber[20];
    	t.open("temp.txt",ios::out);
    	if(!t.is_open())
        exit(0);
    	f.open("add.txt",ios::in);
    	if(!f.is_open())
        exit(0);
    	system("cls");
    	cout << "Enter the Room Number of the hotel to be deleted from the database: \n";
    	cin >> roomnumber;
    	
		while(f.read((char*)&s,sizeof(s))) {
        
		if(strcmp(s.roomnumber,roomnumber)==0) {
            i=0;
            continue;
        }
        
        else
            t.write((char*)&s,sizeof(s));
    }
    
    if(i==1) {
    
	    cout << "\n\n Records of Customer in this  Room number is not found!!";
        cin.get();
        f.close();
        t.close();
        remove("add.txt");
        rename("temp.txt","add.txt");
        main();
        
    }
    
	cout << "\n\nThe Customer is successfully removed....";
    f.close();
    t.close();
    cin.get();
}

	void search() {
	
    	system("cls");
    	ifstream f;
    	char roomnumber[20];
    	int flag=1;
    	f.open("add.txt",ios::in);
    	if(!f.is_open())
        exit(0);
    	cout << "Enter Room number of the customer to search its details: \n";
    	cin >> roomnumber;
    	
		while(f.read((char*)&s,sizeof(s))) {
    	
        if(strcmp(s.roomnumber,roomnumber)==0) {
        	
            flag=0;
            cout << "\n\tRecord Found\n ";
            cout << "\nRoom Number:\t" << s.roomnumber;
            cout << "\nName:\t" << s.name;
            cout << "\nAddress:\t" << s.address;
            cout << "\nPhone number:\t" << s.phonenumber;
            cout << "\nNationality:\t" << s.nationality;
            cout << "\nEmail:\t" << s.email;
            cout << "\nPeriod:\t" << s.period;
            cout << "\nArrival date:\t" << s.arrivaldate;
            flag=0;
            break;
        }
    }
    
	if(flag==1) {
       
	    cout << "\n\tRequested Customer could not be found!";
	    
    }
    
	f.close();
    cin.get();
}

	void edit() {
	
    	fstream f;
    	int k=1;
    	char roomnumber[20];
    	long int size=sizeof(s);
    	f.open("add.txt",ios::in|ios::out);
    	if(!f.is_open())
        exit(0);
    	system("cls");
    	cout << "Enter Room number of the customer to edit:\n\n";
    	cin >> roomnumber;
    	cin.ignore();
    
    while(f.read((char*)&s,sizeof(s))) {
        
		if(strcmp(s.roomnumber,roomnumber)==0) {
        	
            k=0;
            cout << "\nEnter Room Number     :";
            cin >> s.roomnumber;
            cout << "\nEnter Name    :";
            cin >> s.name;
            cout << "\nEnter Address        :";
            cin >> s.address;
            cout << "\nEnter Phone number :";
            cin >> s.phonenumber;
            cout << "\nEnter Nationality :";
            cin >> s.nationality;
            cout << "\nEnter Email :";
            cin >> s.email;
            cout << "\nEnter Period :";
            cin >> s.period;
            cout << "\nEnter Arrival date :";
            cin >> s.arrivaldate;
            f.seekp(-size,ios::cur);
            f.write((char*)&s,sizeof(s));
            break;
        }
    }
    
    if(k==1) {
    	
        cout << "\n\nTHE RECORD DOESN'T EXIST!!!!";
        f.close();
        cin.get();
    }
    
    else {
        
		f.close();
        cout << "\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!";
        cin.get();
    }
}

