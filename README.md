# 🏥 Hospital Management System (PF Based)

## 📌 Project Description

This project is a **Hospital Management System** developed using C++ and structured around three main entities:

- `Patient`
- `Doctor`
- `Appointments`

Each entity is defined in its **own header file** using C++ structures, and all related functions are implemented in their respective files.

---

## 🧩 Entities and Their Attributes

### 1. Patient
- **Patient ID**
- **Patient Name**
- **Patient Age**
- **Patient Email**

### 2. Doctor
- **Doctor ID**
- **Patient Count**
- **Doctor Age**
- **Work Hours**

### 3. Appointments
- **Doctor ID**
- **Patient ID**
- **Time**
- **Fees**

---

## 📁 Header Files

The following header files are used in the project to modularize the functionality:

- `Patient.h`
- `Doctor.h`
- `Appointments.h`

Each file contains:
- The structure definition for the entity
- Functions for Add, View, Search, Update, Delete (where applicable)
- File I/O functions for storing and retrieving data

---

## 🧰 Entity Functionalities

### 🔹 Patient

- `Add()` – Add a new patient record
- `View()` – View all saved patient records
- `Search(value)` – Search and display a patient record based on a given value
- `Update(value)` – Search and update a patient record
- `Delete(value)` – Search and delete a patient record
- `ReadFromFile()` – Read all patient records from file to a structure array
- `WriteToFile()` – Write patient records from structure array to file

---

### 🔹 Doctor

- `Add()` – Add a new doctor record
- `View()` – View all saved doctor records
- `Search(value)` – Search and display a doctor record based on a given value
- `Update(value)` – Search and update a doctor record
- `Delete(value)` – Search and delete a doctor record
- `ReadFromFile()` – Read all doctor records from file to a structure array
- `WriteToFile()` – Write doctor records from structure array to file

---

### 🔹 Appointments

- `Add()` – Add a new appointment record
- `View()` – View all saved appointment records
- `Search(value)` – Search and display an appointment record based on a given value
- `ReadFromFile()` – Read all appointment records from file to a structure array
- `WriteToFile()` – Write appointment records from structure array to file

---

## 💡 Notes

- All file operations ensure data persistence between sessions.
- Structure arrays are used to handle multiple records efficiently.
- Modular code design is followed using header files for each entity.

---

## ✅ Technologies Used

- Language: **C++**
- File Handling: **Text/Binary Files**
- Code Modularity: **Header Files & Functions**

---

## 📂 How to Run

1. Ensure all header files (`Patient.h`, `Doctor.h`, `Appointments.h`) are in the same directory as your main `.cpp` file.
2. Compile the main program using a C++ compiler.
3. Run the executable and interact with the system using console input.

---

## 📤 Outputs

![image](https://github.com/user-attachments/assets/982b6c49-d62a-480c-ba2d-de74cc26f937)
![image](https://github.com/user-attachments/assets/0c83497e-be01-4b1f-bf23-513213c3d4a3)
![image](https://github.com/user-attachments/assets/f73b7c50-ad9f-41d8-bc1d-78ce7e1ef15e)
![image](https://github.com/user-attachments/assets/dc34e015-4734-445b-bdea-91f90eae4453)
![image](https://github.com/user-attachments/assets/504ee8e2-0022-445a-83df-569b04cdcddb)
