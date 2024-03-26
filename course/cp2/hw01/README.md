# hw01

Name: 41247039S 韓欣劭

Course: Computer Programming II

Link:

- [Question link](https://drive.google.com/file/d/1Wdv4nLaoXsXFZX17OleQpllvq5ii_n08/view?pli=1)
- [Additional information](https://hackmd.io/@cp2023/cp2-hw1-info)

## Table of Contents

* [p1 My String Library](#p1-my-string-library)
* [p2 String Calculator](#p2-string-calculator)
* [p3 Chain Rule](#p3-chain-rule)
* [p4 Maze](#p4-maze)
* [p5 Taiko Music Generator](#p5-taiko-music-generator)
* [p6 Bonus](#p6-bonus)

## p1 My String Library

This library creates some string function that is similar to original C library included in `<string.h>`. The function lists are stated below:

```c
char *mystrchr(const char *s, int c);
char *mystrrchr(const char *s, int c);
size_t mystrspn(const char *s, const char *accept);
size_t mystrcspn(const char *s, const char *reject);
char *mystrpbrk(const char *s, const char *accept);
char *mystrstr(const char *haystack, const char *needle);
char *mystrtok(char *str, const char *delim);
```

For more information about the functions above, please refer to `mystring.h`.

## p2 String Calculator

The `calculate()` function in `mycal.h` calculates the arithmetic expression with different base, and gives result in provided base.

```c
int32_t calculate(char *pExpr, int32_t base, char **ppResult);
```

- `pExpr`: should not exceed the length of 100. `pExpr` follows the format `<operand 1> (operator 1) <operand 2> (operator 2) ... <operand n> (operator n)`
- `<operand k>`: `<digits>_<base>`. For example, `123_10` means the number 123 is in base 10; `ABC_16` means the number ABC is in base 16.
  - `<digits>`: should not exceed the range of `int32_t`.
  - `<base>`: in the range of 2 and 16 (inclusive).
- `<operator k>`: `+`, `-` and `*`
- `base`: in the range of 2 and 16 (inclusive).
- `ppResult`: the pointer to save the result string. Should be `NULL` when passing in.

The function will return 0 and save the result to `ppResult` if the input is correct, otherwise it will return -1.

## p3 Chain Rule

The `chain_rule()` function in `mychain.h` calculates the chain rule for `dz/dy * dy/dx`.

```c
int32_t chain_rule(sPoly *pResult, const sPoly *pFy, const sPoly *pFx);
```

- `pResult`: the pointer of result polynomial. Make sure that the values inside `pResult` is initialized to prevent runtime error. It should be initialized as:

```c
sPoly pResult = {
    .size = 0;
    .pPowers = NULL,
    .pCoefficients = NULL
}
```

- `pFy`: the polynomial of `f_1(y)`.
- `pFx`: the polynomial of `f_2(x)`.

The function will return 0 and save the result to `pResult` if the input is correct, otherwise it will return -1.

## p4 Maze

The function `find_min_path()` in `mymaze.h` finds the minimum cost of path that walks from upper-left corner of maze to lower-right of maze.

```c
int32_t find_min_path(const sRoom *pMaze, const uint8_t row, const uint8_t col, sPath *pMinPath);
```

- `pMaze` the maze, which includes the cost of each room and the door number of each directions of the room.
- cost: the cost required to pass that room.
- door number: check the availability to pass from that direction. It's 8 a bit numbers, `aabbccdd` and `aa`, `bb`, `cc`, `dd` represents direction of up, right, down and left respectively.
- `row`: the total row number of maze.
- `col`: the total column number of maze.
- `pMinPath`: the pointer of path to store the minimum cost of path.

The function will return 0 if there is no path, -1 if any error inputs, 1 otherwise.

## p5 Taiko Music Generator

Please refer to [question](https://drive.google.com/file/d/1Wdv4nLaoXsXFZX17OleQpllvq5ii_n08/view?pli=1) and [additional information](https://hackmd.io/@cp2023/cp2-hw1-info) for a complete description of this function.

- Input: The tja file from the game "Taiko no Tatsujin".
- Output: Translated tja file with following format:

```text
course: 3
[1, 1.646000]
[1, 1.822471]
[2, 1.998941]
...

course: 2
...
...
```

- `course: k`: specifies which course is using for following notes. `k` is range from 0 to 4 (inclusive).
- `[x, y]`: `x` describes the type of note, `y` describes the time that note appears from the song.
- `x`: only includes DON, KA, BIGDON and BIGKA, which represents as 1, 2, 3 and 4 respectively.
- `y`: the time of note in seconds.

If there's error input in the tja file, nothing will output and the program will be terminated.

## p6 Bonus

The bonus is written in [hw0106.md](hw0106.md).
