Food Delivery System

Description:
This is a modular C-based application designed to manage food order processing through a multi-level Command Line Interface (CLI). The system is engineered with a focus on modularity, efficient memory management, and persistent data storage.

Key Features:
Multi-level CLI Navigation: Employs dynamic menu logic and string buffers to provide a structured user interface for order management.
Persistent Data Storage: Utilizes Binary File I/O to ensure that all order records and system data are saved and maintained across application restarts.
Automated Input Validation: Includes robust data sanitization and error-handling routines to prevent invalid entries and maintain record integrity.
Real-time Revenue Statistics: Features integrated arithmetic logic to track financial data and generate performance statistics instantly.

Modular Architecture: Decouples file handling, UI logic, and data models to ensure the codebase is maintainable and scalable.

Tech Stack:
Language: C (Standard C99/C11)
Build System: CMake
Concepts: Binary File I/O, Modular Programming, Buffer Management, Data Structures.

Project Structure:
The repository is organized to separate declarations from implementations, facilitating easier debugging and compilation:
<img width="703" height="275" alt="image" src="https://github.com/user-attachments/assets/c2d2187f-7a3c-4736-94d5-a1337ae589da" />


Installation and Build:
To compile and run this system, you will need a C compiler (such as GCC or Clang) and CMake installed on your machine.

Clone the Repository:
git clone https://github.com/yourusername/food-delivery-system.git
cd food-delivery-system

Generate Build Files:
mkdir build
cd build
cmake ..

Compile the Project:
cmake --build .

Run the Executable:
./FoodDeliverySystem

Technical Highlights:
Binary Persistence: By using binary formats rather than text files, the system achieves higher data density and faster read/write speeds for complex data structures.
Memory Optimization: The application is designed to handle menu transitions with minimal memory overhead through the strategic use of string buffers.
Build Portability: The inclusion of CMakeLists.txt allows for consistent compilation across different operating systems and development environments.
