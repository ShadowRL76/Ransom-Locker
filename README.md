Thanks for the clarification! Here's an updated version of the README that includes your specific choices of **GPL-3.0 license**, **wxWidgets** for the GUI, and **hand-rolled encryption**:

---

# **RansomLocker**

## **Overview**

**RansomLocker** is a C++ application that simulates file encryption with multiple encryption algorithms. The application features an intuitive **wxWidgets-based GUI** and allows users to encrypt and decrypt files with a variety of custom encryption methods, providing a controlled and educational experience of how ransomware works.

> **Warning**: This project is intended for **educational purposes only**. Unauthorized file encryption is illegal and unethical. Use responsibly and only in a controlled environment.

## **Features**

- **Multiple Custom Encryption Algorithms**: A variety of hand-rolled encryption methods to lock files.
- **wxWidgets GUI**: A simple and intuitive graphical user interface for file encryption and decryption.
- **Simulated Ransomware Behavior**: Encrypt files, lock them, and simulate ransomware by requiring a decryption key.
- **Cross-Platform**: Compatible with both Windows and Linux.
- **Secure File Management**: Organize and manage encrypted files.

## **Prerequisites**

- C++11 or later.
- CMake for building the project.
- **wxWidgets** for the GUI.
- **OpenSSL** or other libraries (if used) for encryption support.

### Install wxWidgets (on Linux)

For Ubuntu/Debian-based systems:

```bash
sudo apt-get install libwxgtk3.0-gtk3-dev
```

### Install wxWidgets (on Windows)

Follow the instructions to install wxWidgets on Windows from the [official wxWidgets website](https://www.wxwidgets.org/downloads/).

### Install OpenSSL (if using for encryption)

For Ubuntu/Debian-based systems:

```bash
sudo apt-get install libssl-dev
```

On Windows, download OpenSSL from [here](https://slproweb.com/products/Win32OpenSSL.html).

## **Installation**

1. **Clone the repository**:

   ```bash
   git clone https://github.com/ShadowRL76/Ransom-Locker.git
   ```

2. **Navigate to the project directory**:

   ```bash
   cd Ransom-Locker
   ```

3. **Install dependencies**:

   - On Ubuntu:
     ```bash
     sudo apt-get install libssl-dev libwxgtk3.0-gtk3-dev
     ```
   - On Windows, ensure wxWidgets and OpenSSL (or other libraries you’re using for encryption) are installed.

4. **Build the project**:

   ```bash
   cmake .
   make
   ```

   This will compile the project and generate the executable.

## **Usage**

### **Encrypting Files**

1. Launch the application.
2. Click the **Encrypt** button.
3. Select the file you wish to encrypt.
4. Choose your encryption algorithm.
5. Enter a secure key for the encryption process.

### **Decrypting Files**

1. Launch the application.
2. Click the **Decrypt** button.
3. Select the encrypted file you wish to decrypt.
4. Enter the decryption key used during encryption.
5. The file will be decrypted and restored to its original state.

## **How It Works**

- **Encryption**: RansomLocker uses custom hand-rolled encryption algorithms to lock files, making them inaccessible without the correct decryption key.
- **Ransomware Simulation**: After a file is encrypted, the application displays a "ransom note" prompting the user to enter the decryption key (simulating a ransomware attack).
- **Decryption**: The encrypted file can only be restored by entering the correct key, which the user receives during encryption.

## **Important Notes**

- **Educational Use Only**: This tool is meant for learning and demonstration in controlled environments. Do not use it on production systems or without permission.
- **Legal Considerations**: Using this tool for malicious purposes is illegal and unethical. Ensure proper authorization before encrypting any files.
- **Backup**: Always create backups before using encryption tools to prevent data loss.

## **Contributing**

If you'd like to contribute to the project, follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## **License**

This project is licensed under the **GPL-3.0 License**. See the [LICENSE.txt](LICENSE.txt) file for more details.

---

## **LICENSE**

For the **GPL-3.0 License**, include the following text in the `LICENSE` file:

```
GNU GENERAL PUBLIC LICENSE
Version 3, 29 June 2007

Copyright (C) 2024 [Your Name or Your Organization]
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>.
```

`[ShadowRL76]` 

---
