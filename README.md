# Operating Systems Lab - GitHub Repository

## 📌 Introduction
Welcome to the **Operating Systems Lab** repository! This repository contains **C and C++ programs** that demonstrate various fundamental **operating system concepts**, including process synchronization, scheduling, memory management, file systems, and inter-process communication.

Each program is well-documented and tested to help students and developers understand **OS fundamentals** practically.

---

## 📂 Directory Structure
```
OS-Lab/
│── README.md           # Documentation
│── Process_Scheduling/
│   │── fcfs.c          # First Come First Serve Scheduling
│   │── sjf.c           # Shortest Job First Scheduling
│   │── priority.c      # Priority Scheduling
│   │── round_robin.c   # Round Robin Scheduling
│
│── Synchronization/
│   │── producer_consumer.c  # Producer-Consumer Problem using Semaphores
│   │── readers_writers.c    # Readers-Writers Problem
│   │── dining_philosophers.c # Dining Philosophers Problem
│
│── Memory_Management/
│   │── paging.c        # Implementation of Paging
│   │── segmentation.c  # Implementation of Segmentation
│
│── File_Management/
│   │── file_creation.c # File creation and writing
│   │── file_read.c     # Reading from a file
│
│── Interprocess_Communication/
│   │── pipes.c         # IPC using Pipes
│   │── shared_memory.c # IPC using Shared Memory
│
└── Compilation_Scripts/
    │── compile_all.sh  # Bash script to compile all programs
```

---

## 🚀 Getting Started

### 🔹 Prerequisites
Ensure you have the following installed on your system:
- **GCC Compiler** (For C programs)
- **G++ Compiler** (For C++ programs)
- **Make** (Optional, for build automation)

### 🔹 Compilation & Execution
To compile any specific program, use:
```bash
 gcc filename.c -o outputfile
 ./outputfile
```
To compile all programs at once (Linux/macOS):
```bash
 chmod +x Compilation_Scripts/compile_all.sh
 ./Compilation_Scripts/compile_all.sh
```

---

## 📜 Code Explanation
Below are the key programs included in this repository along with their explanations:

### **1️⃣ Process Scheduling Algorithms**
- **First Come First Serve (FCFS):**
  - Implements the simplest CPU scheduling algorithm where the first process in the queue gets executed first.
  - 📄 [Code](Process_Scheduling/fcfs.c)

- **Shortest Job First (SJF):**
  - Executes the process with the shortest burst time first.
  - 📄 [Code](Process_Scheduling/sjf.c)

- **Round Robin Scheduling:**
  - Assigns a fixed time quantum for each process and cycles through the queue.
  - 📄 [Code](Process_Scheduling/round_robin.c)

### **2️⃣ Process Synchronization**
- **Producer-Consumer Problem (Semaphore-Based):**
  - Uses semaphores to coordinate the producer and consumer threads.
  - 📄 [Code](Synchronization/producer_consumer.c)

- **Dining Philosophers Problem:**
  - Prevents deadlock when multiple philosophers try to eat using limited chopsticks.
  - 📄 [Code](Synchronization/dining_philosophers.c)

### **3️⃣ Memory Management**
- **Paging:**
  - Demonstrates memory management using page tables.
  - 📄 [Code](Memory_Management/paging.c)

- **Segmentation:**
  - Implements segmentation for memory allocation.
  - 📄 [Code](Memory_Management/segmentation.c)

### **4️⃣ File Management**
- **File Creation and Writing:**
  - Demonstrates opening, writing, and closing a file in C.
  - 📄 [Code](File_Management/file_creation.c)

- **File Reading:**
  - Reads and displays content from a file.
  - 📄 [Code](File_Management/file_read.c)

### **5️⃣ Interprocess Communication (IPC)**
- **Pipes:**
  - Implements IPC using unnamed pipes to communicate between processes.
  - 📄 [Code](Interprocess_Communication/pipes.c)

- **Shared Memory:**
  - Uses `shmget()` and `shmat()` to allocate shared memory between processes.
  - 📄 [Code](Interprocess_Communication/shared_memory.c)

---

## 📌 Contribution Guidelines
We welcome contributions! Follow these steps:
1. **Fork** the repository.
2. Create a **feature branch** (`git checkout -b new-feature`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin new-feature`).
5. Open a **Pull Request** (PR).

---

## 🛠 Issues & Support
- If you encounter any issues, open an **Issue** in the repository.
- For discussions, join our community forum or message on GitHub Discussions.

---

## ⚡ Author
👤 **[Your Name]**  
📧 Email: your.email@example.com  
🔗 LinkedIn: [Your Profile](https://linkedin.com/in/yourprofile)

---

## 📜 License
This repository is licensed under the **MIT License**. Feel free to use and modify the code.

---

🎯 Happy Coding! 🚀

