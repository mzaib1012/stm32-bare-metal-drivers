# Bare-Metal ARM Cortex-M Driver Architecture

A professional-grade firmware project demonstrating low-level peripheral driver development for the **STM32F401RE (ARM Cortex-M4)**. This project bypasses all vendor abstraction layers (HAL/LL) to interface directly with hardware registers, showcasing deep understanding of MCU architecture and memory-mapped I/O.

## 🎯 Project Objectives

* **Hardware Abstraction from Scratch:** Develop modular C drivers by mapping peripheral register structures to physical memory addresses.
* **Register-Level Manipulation:** Implement bitwise operations for peripheral configuration, clock gating, and data management.
* **Industry Standard Workflow:** Utilize a professional toolchain including GCC ARM Cross-Compiler and STM32CubeIDE for development and debugging.

## 🛠 Tech Stack

* **Language:** Pure C (ISO C11)
* **Architecture:** ARM Cortex-M4F
* **IDE:** STM32CubeIDE
* **Toolchain:** GNU Arm Embedded Toolchain (arm-none-eabi)
* **Version Control:** Git

## 🚀 Key Features Implemented

### 1. Custom Hardware Header (`stm32f401xe.h`)

* Manually defined peripheral base addresses for AHB/APB buses.
* Mapped GPIO register structures using `volatile` keyword to ensure thread-safe hardware access and prevent compiler optimization errors.

### 2. GPIO Driver

* Implemented Clock Gating via RCC (Reset and Clock Control).
* Configured Pin Modes (Input, Output, Alternate Function, Analog) using bit-masking.
* High-performance pin toggling utilizing the ODR (Output Data Register).

## 💻 How to Build

1. Import the project into **STM32CubeIDE**.
2. Right-click on the project in the Project Explorer.
3. Select **Build Project**.
4. The output `.elf` and `.bin` files will be generated in the `Debug/` or `Release/` directory.

## 📂 Project Structure

```text
.
├── Inc/
│   └── stm32f401xe.h         # Custom register definitions & memory map
├── Src/
│   ├── main.c                # Application logic & peripheral initialization
│   ├── syscalls.c            # Standard system calls for ARM
│   └── sysmem.c              # Memory management for the toolchain
├── Startup/
│   └── startup_stm32f401.s   # Assembly startup code (Vector table & Reset handler)
├── .gitignore                # Optimized to exclude build artifacts
├── STM32F401RETX_FLASH.ld    # Linker script for Flash memory layout
├── STM32F401RETX_RAM.ld      # Linker script for RAM layout
└── README.md                 # Project documentation

```
