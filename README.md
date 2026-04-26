## Project README

### Overview
The project is a simple implementation of a hash map in C that supports various operating systems and environments. It includes support for Linux, Windows (using Wine), web assembly, and cross-compilation for Windows on Linux.

### Features
- Hash map data structure
- Insertion (`Hashmap_Add`)
- Removal (`Hashmap_Remove`)
- Lookup (`Hashmap_Find`)
- Printing (`Hashmap_Print`)
- Support for different operating systems and environments

### Project Structure
The project directory contains the following files:

```
# Project Root/
├── build/             # Compiled .exe, .so, .dll files produced by Main.c
├── libs/              # Contains library source files
├── src/               # Source code directory
│   ├── Main.c         # Entry point
│   └── *.h            # Header files for various utilities and data structures
├── Makefile.linux     # Linux build configuration
├── Makefile.windows   # Windows build configuration
├── Makefile.wine      # Wine build configuration for cross-compiling to Windows on Linux
└── Makefile.web       # Web assembly build configuration using Emscripten or wasmtime
```

### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools
- Libraries needed in specific projects (none explicitly listed in the provided files)

## Build & Run

### Building on Linux
To build the project on Linux:
```bash
cd /path/to/project
make -f Makefile.linux all
```
This will compile the source code and generate an executable named `Main` in the `build/` directory.

### Building on Windows (using Wine)
To build the project on Linux for Windows using Wine:
```bash
cd /path/to/project
make -f Makefile.wine all
```
This will cross-compile the source code and generate a Windows executable named `Main.exe` in the `build/` directory.

### Building for WebAssembly (using Emscripten)
To build the project for web assembly:
```bash
cd /path/to/project
make -f Makefile.web all
```
This will compile the source code using Emscripten and generate a WebAssembly file named `Main.wasm`.

### Running on Linux
To run the executable on Linux:
```bash
make -f Makefile.linux exe
```

### Debugging on Linux
To debug the executable on Linux:
```bash
make -f Makefile.linux debug
```
This will start GDB to debug the `Main` executable.

### Clean Build
To clean and rebuild the project:
```bash
make -f Makefile.linux clean
make -f Makefile.linux all
```

### Full Process (Build + Execute)
To build and execute the project on Linux:
```bash
make -f Makefile.linux do
```

This README provides a comprehensive overview of the project, its features, and how to build and run it across different environments.