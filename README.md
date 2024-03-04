# nCurses Toolkit for C++
[![License](https://shields.io/badge/License-GNU%20General%20Public%20License%20v3.0-green)](LICENSE)
[![nCurses](https://img.shields.io/badge/nCurses-6.4-red.svg)](https://en.wikipedia.org/wiki/Ncurses/)
[![Linux](https://img.shields.io/badge/Platform-Linux-blue.svg)](https://www.linux.org/)

## Introduction
Welcome to the ncurses-toolkit for C++ repository! This project aims to provide a versatile and easy-to-use toolkit for building text-based user interfaces (TUIs) in C++ using the ncurses library. Designed specifically for Linux environments, this toolkit empowers developers to create dynamic and interactive console applications with ease.

## Features
* **Menu Class:** Our toolkit includes a robust Menu class to kickstart your TUI development journey.
* **Dialog Box Class:** Our Dialog Box Class provides a versatile solution for creating interactive dialogue boxes within your text-based user interface (TUI). 

## Getting started
### Prerequisites
Before getting started with ncurses-toolkit, ensure that you have the following dependencies installed on your Linux system:

* **g++** compiler
* **ncurses** library

### Installation
To use the ncurses-toolkit in your C++ projects, follow these steps:

1. Clone the repository to your local machine:
```bash
git clone https://github.com/ignabelitzky/ncurses-toolkit.git
```

2. Include the necessary header files in your C++ code:
```cpp
#include "ncurses-toolkit/include/menu.hpp"
#include "ncurses-toolkit/include/dialog_box.hpp"
// Include other necessary headers for additional features
```

3. Compile your project with the ncurses library:
```bash
g++ -o your_program your_program.cpp -lncurses
```

### Usage
Check out the examples provided in the **misc/** directory to see how to use the ncurses-toolkit in your projects.

## Contributing
We welcome contributions from the community! Whether it's bug fixes, feature enhancements, or new ideas, feel free to open an issue or submit a pull request.

## License
This project is licensed under the [GNU General Public License v3.0](LICENSE), which means you are free to use, modify, and distribute the code for both commercial and non-commercial purposes.
