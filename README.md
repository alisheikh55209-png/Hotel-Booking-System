# 🏨 Hotel Booking/Reservation System

> A sophisticated console-based hotel booking and reservation system built in **C++** demonstrating professional software engineering practices and core programming concepts.

![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg) ![Platform](https://img.shields.io/badge/Platform-Windows-brightgreen.svg) ![Version](https://img.shields.io/badge/Version-2.0-orange.svg) ![Status](https://img.shields.io/badge/Status-Active-success.svg)

---

## 📋 Quick Navigation

[Overview](#overview) • [Features](#features) • [System Requirements](#system-requirements) • [Setup](#setup) • [Usage](#usage) • [Team](#team) • [License](#license)

---

## Overview

This is a **professional-grade hotel management system** enabling efficient room booking and customer reservation management through an intuitive menu-driven interface. The system demonstrates core C++ concepts including file handling, structs, string manipulation, and comprehensive application design.

### Core Capabilities

✅ **Secure Authentication** | ✅ **Room Booking** | ✅ **Record Viewing** | ✅ **Advanced Search** | ✅ **Data Editing** | ✅ **Record Deletion** | ✅ **Data Persistence** | ✅ **Enhanced UI**

---

## ✨ Features

### 🔐 Security & Authentication
- **User Authentication**: Secure login system with credential validation
- **Access Control**: Prevents unauthorized access to bookings
- **Credentials**: Username: `user` | Password: `pass`

### 🛏️ Room Booking System  
- Comprehensive room reservation management
- Detailed customer information tracking
- Support for up to 10 active rooms
- Flexible stay duration management

### 📊 Record Management
- **View All Records**: Complete booking history in organized tables
- **Advanced Search**: Quickly locate bookings by room number
- **Edit Records**: Modify any customer information anytime
- **Delete Records**: Securely remove outdated bookings

### 💾 Data Persistence & 🎨 UI Enhancements
- **Automatic Storage**: File-based data persistence (`add.txt`)
- **Colored Console**: Professional Windows console color support
- **Table Formatting**: Clean, easy-to-read record displays
- **Professional UI**: ASCII art headers and intuitive menus

---

## 🛠️ System Requirements

| Component | Requirement |
|-----------|-------------|
| **OS** | Windows (Vista or later) |
| **Compiler** | GCC/G++, MSVC, or MinGW |
| **Memory** | 50 MB minimum |
| **Storage** | 10 MB minimum |
| **Terminal** | Command Prompt or PowerShell |

### Required Libraries
`iostream` • `fstream` • `cstring` • `windows.h` • `conio.h` • `cctype`

---

## 🚀 Setup & Installation

### Step 1: Compile the Program
```bash
# Using G++
g++ "Hotel Reservation or Booking System.cpp" -o HotelSystem

# Or using MSVC
cl "Hotel Reservation or Booking System.cpp"
```

### Step 2: Run the Application
```bash
HotelSystem.exe
```

### Step 3: Login
- **Username**: `user`
- **Password**: `pass`

---

## 📖 Usage Guide

### Main Menu Operations

```
╔════════════════════════════════════════╗
║   HOTEL BOOKING SYSTEM - MAIN MENU    ║
╠════════════════════════════════════════╣
║  1. 🛏️  BOOK A ROOM                   ║
║  2. 📋 VIEW ALL RECORDS               ║
║  3. 🗑️  DELETE RECORD                 ║
║  4. 🔍 SEARCH RECORD                  ║
║  5. ✏️  EDIT RECORD                   ║
║  6. 🚪 EXIT                           ║
╚════════════════════════════════════════╝
```

### Operation Details

**1️⃣ Book a Room**  
Enter room number → Name → Address → Phone → Nationality → Email → Period → Arrival Date

**2️⃣ View All Records**  
Displays all active bookings in professional table format with complete details

**3️⃣ Delete Record**  
Enter room number → Confirm deletion → Record permanently removed

**4️⃣ Search Record**  
Enter room number → View complete customer information

**5️⃣ Edit Record**  
Locate record → Update customer details → Changes saved automatically

**6️⃣ Exit**  
Close application → All data automatically saved

---

## 🗂️ File Structure

```
Hotel-Booking-System/
│
├── Hotel Reservation or Booking System.cpp    ⭐ Main source code (450+ lines)
├── README.md                                   📖 Documentation (this file)
├── PROJECT_INFO.md                             ℹ️  Project & team information
├── LICENSE                                     ⚖️  MIT License
├── add.txt                                     💾 Database file (auto-created)
└── input.txt                                   🧪 Test input data
```

---

## 📊 Technical Details

### Data Structure
```cpp
struct Customer {
    char roomnumber[10];      // Room identifier (1-10)
    char name[20];            // Customer full name
    char address[25];         // Residential address
    char phonenumber[35];     // Contact phone number
    char nationality[15];     // Customer nationality
    char email[20];           // Email address
    char period[10];          // Stay duration (days)
    char arrivaldate[10];     // Check-in date (DD-MM-YYYY)
};
```

### Core Functions

| Function | Purpose |
|----------|---------|
| `login()` | User authentication and credential validation |
| `add()` | Add new room booking |
| `list()` | Display all records in table format |
| `search()` | Find specific record by room number |
| `edit()` | Modify existing customer information |
| `delete1()` | Remove booking record |
| `setcolor()` | Console color management |

### Configuration Constants

| Constant | Value | Purpose |
|----------|-------|---------|
| MAX_ROOM_NO | 10 | Maximum available rooms |
| MAX_NAME | 20 | Name field size |
| MAX_ADDRESS | 25 | Address field size |
| MAX_PHONE | 35 | Phone number field size |
| MAX_NATIONALITY | 15 | Nationality field size |
| MAX_EMAIL | 20 | Email field size |

---

## 👥 Project Creator & Developer

| Role | Name | Student ID | Responsibility |
|------|------|-----------|-----------------|
| 🎯 **Project Creator & Developer** | Muhammad Ali Sheikh | 70151489 | Complete project development, design, implementation, and documentation |

---

## 📈 Project Timeline

| Phase | Duration | Date Range | Status |
|-------|----------|------------|--------|
| **Design** | 2 days | 14-05-2024 to 15-05-2024 | ✅ Complete |
| **Development** | 6 days | 15-05-2024 to 20-05-2024 | ✅ Complete |
| **Testing & QA** | 10 days | 21-05-2024 to 30-05-2024 | ✅ Complete |
| **v1.0 Release** | 1 day | 31-05-2024 | ✅ Released |
| **v2.0 Enhancement** | 7 months | 01-06-2024 to 31-12-2025 | ✅ Complete |

---

## 💡 Learning Outcomes

### Programming Concepts Demonstrated
- **Data Structures**: Struct design and implementation
- **File I/O**: Binary and text file operations
- **Functions**: Modular code design and decomposition
- **String Handling**: Character array manipulation
- **Control Flow**: Loops, conditionals, menu systems

### Software Engineering Skills Acquired
- Input validation and bounds checking
- Error handling and exception management
- Code organization and architecture
- Data persistence design
- User experience optimization

---

## 📄 License

This project is licensed under the **MIT License** - see [LICENSE](LICENSE) file for full details.

---

## 🚀 Version History

### Version 2.0 (31-12-2025)
- ✨ Enhanced input validation with bounds checking
- ✨ Improved error handling mechanisms
- ✨ Better file management with safety checks
- ✨ Secure password input with backspace support
- ✨ Record counting in list view
- ✨ Optimized code structure
- ✨ Comprehensive inline comments

### Version 1.0 (31-05-2024)
- 🎉 Initial release
- 🎉 Core functionality implemented
- 🎉 Basic UI with color support

---

## 🔮 Future Roadmap

### Short-term (v2.1)
- [ ] Cross-platform compatibility
- [ ] Enhanced validation
- [ ] Better error messages

### Medium-term (v3.0)
- [ ] SQLite database integration
- [ ] Advanced search filters
- [ ] Report generation
- [ ] Email notifications

### Long-term (v4.0)
- [ ] GUI implementation (Qt/wxWidgets)
- [ ] Web interface
- [ ] Mobile application
- [ ] Cloud synchronization

---

## 📞 Support & Contact

- **Report Issues**: Open an issue on GitHub
- **Questions**: Contact team lead
- **Suggestions**: We welcome pull requests!

---

**Status**: ✅ Active & Maintained | **Version**: 2.0 | **Last Updated**: 31 December 2025

*Educational project for Programming Fundamentals course. Fully functional for learning purposes.*
