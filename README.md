# Elementary Programming in C - Setting Up
Project for semester 1 of the Epitech Elementary Programming in C module (B-CPE-110).
## Introduction
Algorithm for finding the largest possible square on a game board while avoiding obstacles. The array can be obtained in two ways. The first involves reading a file passed as an argument to the program.

The full description of the project can be found in [subject.pdf](pdf/B-CPE-110_Setting_Up.pdf).

## Prerequisites
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/)
- [LibC](https://www.gnu.org/software/libc/)

## Installation
```
B-PSU-100> git clone git@github.com:WilliamJlvt/setting_up.git
...
B-PSU-100> make
...
```

## Usage
#### valid file:
```
B-CPE-110> cat -e example_file
9$
...........................$
....o......................$
............o..............$
...........................$
....o......................$
..............o............$
...........................$
......o..............o.....$
..o.......o................$
```
#### Classic execution
```
B-CPE-110> ./setting_up example_file | cat -e
.....xxxxxxx................$
....oxxxxxxx................$
.....xxxxxxxo...............$
.....xxxxxxx................$
....oxxxxxxx................$
.....xxxxxxx...o............$
.....xxxxxxx................$
......o...............o.....$
..o.......o.................$
```
#### Generating execution
```
B-CPE-110> ./setting_up 6 “..o..” | cat -e
..oxx.$
.o.xx.$
o....o$
....o.$
...o..$
..o...$
```
## Results
| test           | passed | results |
|----------------|--------|---------|
| Algorithm app  | 22/22  | 100%    |
| Basics         | 6/6    | 100%    |
| Data structure | 6/6    | 100%    |
| Optimization   | 16/16  | 100%    |
| Parsing        | 3/3    | 100%    |
| Robustness     | 25/28  | 89.3%   |
| Total          | 78/81  | 96.3%   |

## Coding style
All the source code has been written according to the [Epitech C Coding Style](https://williamjlvt.github.io/assets/coding_style/epitech_c_coding_style.pdf).
#### errors
| Fatal | Major  | Minor | Info |
|-------|--------|-------|------|
| 0     | 0      | 0     | 0    |

## Authors
* **William JOLIVET** ([GitHub](https://github.com/WilliamJlvt) / [LinkedIn](https://www.linkedin.com/in/william-jolivet/))

## License
This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](LICENSE) file for details.