# EulShell

This repo holds all of my [Project Euler](https://projecteuler.net/) solutions wrapped in a Shell written in C/C++. [Project Euler](https://projecteuler.net/) is a site where you solve mathematical problems with a really big calculator. The goal of this project is to integrate a limited Shell with my solutions, and support case testing to measure the efficiency of solutions written in various languages.

Instructors are free to share, modify, and distributed this code in an educational setting. Pieces of the Shell can be removed to allow students to implment their own modules. Or, students can be instructed to solve [Project Euler](https://projecteuler.net/) problems with this shell as a framework.

Future expansions include interpreting `.js` files, writting my own _Determinstic Finite State Automotan_, implementing _Autocomplete_, and _Previous Commands_.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

```
Unix OS - for cd, pwd, ls, read
g++ -std++11
```

### Installing

#### Option 1 - Clone this repo

1. `clone https://github.com/nhstaple/EulShell`
2. `cd EulShell/src/cpp`
3. `make`
4. On success `./Euler.out`

#### Option 2 - Download [release](https://github.com/nhstaple/EulShell/releases)

Grab the latest release and open with Qt Creator.

## Built With

* C++ std API.
* [Termcolor](https://github.com/ikalnytskyi/termcolor) - Color API used.

## Versioning

A.B.C
* A - Major feature release.
* B - Minor feature relaese.
* C - Project Euler solution, for A > 0.

## Authors

* [**Nick Stapleton**](https://nhstaple.github.io)

## License

Open to everyone.
