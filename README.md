# Operating Systems Lab - GitHub Repository

## 📌 Introduction
Welcome to the **Operating Systems Lab** repository! This repository contains **C programs** that demonstrate fundamental **operating system concepts**, as per the R22 B.Tech. AI & DS syllabus at JNTU Hyderabad. The lab covers **CPU scheduling, deadlock management, file and memory management, and inter-process communication**.

Each program is well-documented and tested to help students understand **OS principles** practically.

---

## 📂 Directory Structure
```
OS-Lab/
│── README.md           # Documentation
│── CPU_Scheduling/
│   │── fcfs.c          # First Come First Serve Scheduling
│   │── sjf.c           # Shortest Job First Scheduling
│   │── priority.c      # Priority Scheduling
│   │── round_robin.c   # Round Robin Scheduling
│
│── File_Management/
│   │── file_operations.c # UNIX file system calls (open, read, write, close, fcntl, seek, stat, opendir, readdir)
│
│── Deadlock_Management/
│   │── bankers_algorithm.c # Banker's Algorithm for Deadlock Avoidance and Prevention
│
│── Synchronization/
│   │── producer_consumer.c  # Producer-Consumer Problem using Semaphores
│
│── Interprocess_Communication/
│   │── pipes.c         # IPC using Pipes
│   │── fifos.c         # IPC using FIFOs
│   │── message_queues.c # IPC using Message Queues
│   │── shared_memory.c # IPC using Shared Memory
│
│── Memory_Management/
│   │── paging.c        # Implementation of Paging
│   │── segmentation.c  # Implementation of Segmentation
│
│── Page_Replacement/
│   │── fcfs_replacement.c  # FCFS Page Replacement Algorithm
│   │── lru_replacement.c   # Least Recently Used (LRU) Algorithm
│   │── optimal_replacement.c # Optimal Page Replacement Algorithm
│
└── Compilation_Scripts/
    │── compile_all.sh  # Bash script to compile all programs
```

---

## 🚀 Getting Started

### 🔹 Prerequisites
Ensure you have the following installed on your system:
- **GCC Compiler** (For C programs)
- **Linux/UNIX-based system** (recommended for system calls execution)

### 🔹 Compilation & Execution
To compile a specific program, use:
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

### **1️⃣ CPU Scheduling Algorithms**
- **First Come First Serve (FCFS)** – Executes the first process in the queue first.
- **Shortest Job First (SJF)** – Executes the process with the shortest burst time first.
- **Priority Scheduling** – Assigns priority values to processes.
- **Round Robin Scheduling** – Uses time quantum for fair CPU allocation.

### **2️⃣ UNIX System Calls for File Management**
- Demonstrates **open, read, write, close, fcntl, seek, stat, opendir, readdir** system calls.

### **3️⃣ Deadlock Management**
- **Banker’s Algorithm** – Prevents and avoids deadlocks in resource allocation.

### **4️⃣ Process Synchronization**
- **Producer-Consumer Problem** – Uses semaphores for synchronized data exchange.

### **5️⃣ Interprocess Communication (IPC)**
- **Pipes** – Unidirectional communication between processes.
- **FIFOs** – Named pipes for IPC.
- **Message Queues** – Queue-based IPC.
- **Shared Memory** – Fastest IPC using shared memory segments.

### **6️⃣ Memory Management**
- **Paging** – Implements page-based memory management.
- **Segmentation** – Implements segment-based memory management.

### **7️⃣ Page Replacement Algorithms**
- **FCFS Page Replacement** – Replaces the oldest page first.
- **LRU Page Replacement** – Replaces the least recently used page.
- **Optimal Page Replacement** – Replaces the page that will not be used for the longest time.

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

## 📚 References
- **Operating System Principles** - Abraham Silberchatz, Peter B. Galvin, Greg Gagne.
- **Advanced Programming in the UNIX Environment** - W.R. Stevens.
- **Operating Systems – Internals and Design Principles** - William Stallings.
- **Modern Operating Systems** - Andrew S. Tanenbaum.

---

## ⚡ Author
👤 **[Yuvaraj]**  
📧 Email: dudukuruyuvaraj55@gmail.com  
🔗 LinkedIn: [Yuvaraj](https://linkedin.com/in/yuvaraj-dudukuru)

---

## 📜 License
This repository is licensed under the **MIT License**. Feel free to use and modify the code.

---

🎯 Happy Coding! 🚀

