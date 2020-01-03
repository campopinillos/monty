![Holberton school logo](https://secure.meetupstatic.com/photos/event/b/c/5/6/highres_475548214.jpeg)
# monty

## Table of Contents
* [Description](#description)
* [File Structure](#file-structure)
* [The monty program](#The-monty-program)
* [Quick Start](#quick-start)
* [Usage](#usage)
* [Bugs](#bugs)
* [Authors](#authors)

## Description
This is collaborative project made by Juan Pablo Zuluaga and Campo Elias Pinillos, students of Software Engineering at Holberton School. This repository contains the files for Holberton's **monty project**. The goal of this project is to create an interpreter for Monty ByteCodes files.


## File Structure

These are the files with the custom funtions and system calls, each one contains a brief description:

|   ***File***    |  ***Description***                   |
|---------------|---------------------------------------|
|  [`monty.h`](./holberton.h)	|  Header file with the prototypes	|
|  [`monty.c`](./lsh.c) |  Main File functions to execute |
|  [`README.md`](./README.md)  | Readme.md file	|

## The monty program
* Usage: `monty file`
  - where `file` is the path to the file containing Monty byte code

* If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`

* If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
  - where `<file>` is the name of the file

* If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
  - where is the line number where the instruction appears.
  - Line numbers always start at 1

* The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file
  - it finds an error in the file
  - an error occured

* If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.

* You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, …)


## Quick Start
1. Clone repo
```
git clone https://github.com/campopinillos/monty.git
```
2. Change directory to simple_shell
```
cd monty/
```
3. Compile all the `.c` files in /monty
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```

## Usage

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files

### Monty byte code files:
IFiles containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```

## Bugs
No known bugs. Please contact any of the authors if a bug appears.


## Authors
* **Juan Pablo Zuluaga** - [juanzuluaga91](https://github.com/juanzuluaga91) - [@juanzuluaga91](https://twitter.com/juanzuluaga91)

* **Campo Elias Pinillos** - [campopinillos](https://github.com/campopinillos) - [@campopinillos](https://twitter.com/CampoPinillos)