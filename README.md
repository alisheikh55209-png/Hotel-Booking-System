# Hotel Booking/Reservation System

A console-based hotel booking and reservation system built in **C++** as a fundamental programming project. This system demonstrates core C++ concepts including file handling, structs, string manipulation, and menu-driven applications.

## 📋 Overview

This is a basic hotel management system that allows users to:
- Book rooms with customer details
- View all customer records
- Search for specific customer bookings
- Edit customer information
- Delete customer records
- Secure login system

## ✨ Features

- **Login System**: User authentication (default credentials - username: `user`, password: `pass`)
- **Room Booking**: Add customer details including room number, name, address, phone, nationality, email, booking period, and arrival date
- **View Records**: Display all booking records in a formatted table
- **Search Function**: Find specific customer bookings by room number
- **Edit Records**: Modify existing customer booking information
- **Delete Records**: Remove customer records from the database
- **File Storage**: Data persistence using file operations
- **Colored Console Output**: Enhanced UI using Windows console color support

## 🛠️ System Requirements

- C++ Compiler (GCC/G++ or MSVC)
- Windows OS (uses Windows-specific libraries like `windows.h` and `conio.h`)
- Terminal/Command Prompt

## 📝 Project Details

| Aspect | Detail |
|--------|--------|
| **Language** | C++ |
| **Type** | Console Application |
| **Database** | Text File (add.txt) |
| **Concepts Used** | File I/O, Structs, Functions, String Operations, Basic UI |
| **Date Created** | 14-05-2024 |

## 🏃 How to Run

### On Windows:

1. **Compile the program**:
   ```bash
   g++ "Hotel Reservation or Booking System.cpp" -o "Hotel Reservation or Booking System"
   ```

2. **Run the executable**:
   ```bash
   "Hotel Reservation or Booking System"
   ```

### Login Credentials:
- **Username**: `user`
- **Password**: `pass`

## 📖 Usage Guide

### Main Menu Options:

1. **Book a Room (Option 1)**
   - Enter room number
   - Provide customer details
   - Confirm booking

2. **View Customer Records (Option 2)**
   - Displays all bookings in tabular format
   - Shows room details, customer info, and dates

3. **Delete Customer Record (Option 3)**
   - Enter room number to delete
   - Record removed from database

4. **Search Customer Record (Option 4)**
   - Enter room number
   - View specific customer details

5. **Edit Record (Option 5)**
   - Update existing customer information
   - Modify any field

6. **Exit (Option 6)**
   - Safely close the application

## 🗂️ File Structure

```
Hotel Reservation or Booking System/
├── Hotel Reservation or Booking System.cpp    # Main source code
├── add.txt                                     # Customer database (auto-created)
├── README.md                                   # Documentation
├── LICENSE                                     # MIT License
└── .gitignore                                  # Git ignore rules
```

## 📊 Data Structure

The system uses a struct to store customer details:

```cpp
struct CustomerDetails {
    char roomnumber[10];
    char name[20];
    char address[25];
    char phonenumber[35];
    char nationality[15];
    char email[20];
    char period[10];
    char arrivaldate[10];
};
```

## 💡 Learning Objectives

This project demonstrates:
- **File I/O Operations**: Reading and writing to files
- **Structs**: Creating and using custom data types
- **Function Decomposition**: Breaking down logic into separate functions
- **String Manipulation**: Working with character arrays and strings
- **Conditional Logic**: Menu-driven application flow
- **Data Persistence**: Storing data in files

## ⚠️ Known Limitations

- Windows-specific code (uses `windows.h` and `conio.h`)
- No database - uses text file storage
- Single-threaded application
- No input validation
- Credentials hardcoded
- Limited error handling

## 👥 Contributors

- M. Ali Sheikh (70151489)
- Zaid (70149441)
- Anas Abid (70150234)
- Hussain Muavia (70147427)

## 📄 License

This project is licensed under the MIT License - see [LICENSE](LICENSE) file for details.

## 🚀 Future Improvements

- Cross-platform compatibility
- Database integration (SQLite/MySQL)
- Input validation and error handling
- User-friendly GUI
- Advanced search and filter options
- Report generation
- Secure password management

## 📞 Support

For issues or questions, please open an issue on GitHub.

---

**Note**: This is a fundamental programming project for educational purposes. It demonstrates basic C++ concepts and is not recommended for production use.
