# hw01

41247039S 韓欣劭

Computer Programming (I), hw04

## Table of Contents

* [Run and Execute](#run-and-execute)
* [Question 1](#question-1)
* [Question 2](#question-2)
* [Question 3](#question-3)
* [Question 4](#question-4)
* [Question 5](#question-5)
* [Bonus Question](#bonus-question)

## Run And Execute

This is just a homework. Therefore it's easy to run these codes. Make sure to `unzip` thie file after download. To run the code, simply just type

```console
make
```

and all the c language codes will be compiled by using `gcc`. There will be 5 compiled file, naming `hw040x` where `x` is the question number.

This homework has 5+1 questions. The [question](https://drive.google.com/file/d/1CoD-XguMi5RskmxI4_HpFgJ9vYKVL2Ev/view) and question's [additional information](https://hackmd.io/@cp2023/cp1-hw4-info) is here (since both links are not mine, the link may become invalid).

The first 5 questions are written in C language, and the bonus question is written in [hw0406.md](hw0406.md). The first 5 questions are executable, by typing

```console
./hw040x
```

where `x` is range from 1 to 5.

## Question 1

Question 1 requires sorting the integer array with given policy:

1. All even numbers should be before odd numbers.
2. All odd numbers are in ascending order.
3. All even numbers are in descending order.

Two functions are given in `hw0401.h` which is `mysort()` and `myprint()`.

* `mysort()` is used to sort the integer array by given policies.
* `myprint()` is used to print the array, separating each numbers by space.

The question does not require to implement main function, therefore there's no example output given.

### What I have learned/encountered in Q1

* Nothing special in this question.

## Question 2

Question 2 requires to calculate the derivative of multiplication and division of 2 functions.

The user is required to input degrees and coefficients of 2 functions, starting from highest degree. the program will print the following output:

```console
./hw0402
Please enter f(x) degree: 3
Please enter f(x) coefficients: 2 1 1 0
Please enter g(x) degree: 2
Please enter g(x) coefficients: 3 0 0
f(x): 2x^3+x^2+x
g(x): 3x^2
(f(x)g(x))': 30x^4+12x^3+9x^2
 f(x)    2x^2-1
(----)': ------
 g(x)    3x^2
```

An error message will be given if any of the following inputs are given:

* Invalid degree or coefficients
* The degree is out of range (range of `uint8_t`)
* The coefficient is out of range (range of `int32_t`)
* First coefficient of each function is `0`

### What I have learned/encountered

* Nothing special in this question.

## Question 3

Question 3 requires to calculate the five standards of GSAT scores. The program will output the result given from `gsat.h` with the following format:

```console
./hw0403
        CHINESE | ENGLISH | MATH_A  | MATH_B  | SOCIAL  | SCIENCE
TOP 12%    15        14        15         0        15        15
TOP 25%    15        13        15         0        15        15
TOP 50%    12        11        15         0         5        10
TOP 75%     7         8        15         0         5         7
TOP 88%     6         7        15         0         5         7
```

### What I have learned/encountered

* Nothing special in this question.

## Question 4

Question 4 is about playing Xiangqi. The question requires to find all possible moves for red side to checkmate the black side.

In `mychess.h`, the function `checkmate()` is used to find the required moves from the given board.

The function will output the result with given format:

```console
*) Move <piece> from (<x1>,<y1>) to (<x2>,<y2>)
```

* `*` is the possible move's counter.
* `<piece>` is replaced by the piece name.
* `<x1>` and `<y1>` is replaced by the initial position of the piece.
* `<x1>` and `<y1>` is replaced by the final position of the piece.

One of the possible results are given below:

```console
1) Move Horse from (4,1) to (5,3)
2) Move Horse from (4,1) to (6,2)
3) Move Chariot from (8,7) to (8,4)
4) Move Cannon from (4,7) to (4,4)
5) Move Cannon from (4,7) to (7,7)
6) Move Soldier from (7,6) to (7,5)
```

`checkmate()` will return the amount of possible moves of the board, and `-1` if any of the following board occurs:

* Invalid amount of pieces
* Invalid piece's position

### What I have learned/encountered

* Play Xiangqi.

## Question 5

Question 5 is about Japanese Mahjong. The question requires to calculate the score of input hand. The policies of tile is given below:

* 1 to 9: 1 Pin to 9 Pin
* 10 to 18: 1 So to 9 So
* 19 to 27: 1 Man to 9 Man
* 28 to 31: East, South, West, North
* 32 to 34: White, Green, Red

The user is required to input the tiles meld by meld, stopping with the integer `0`. For simplicity, the input tiles are not required to find the higher combination. Only **"seven pairs"** and **"thirteen orphans"** are inputed as 1 meld.

The user is then requires to input pairs, winning tile, self-drawn win, player's wind and prevailing wind. The program will then calculate the scores and output all possible yakus or yakumans. Output yakus or yakumans are in decreasing order according to hans, then followed by lexicographic order.

One of the possible outputs are given below.

```console
./hw0405
Please input meld: 2 3 1 0
Is open/closed group(1: open 0: closed): 0
Please input meld: 3 2 1 0
Is open/closed group(1: open 0: closed): 0
Please input meld: 8 9 7 0
Is open/closed group(1: open 0: closed): 0
Please input meld: 7 9 8 0
Is open/closed group(1: open 0: closed): 0
Please input pair: 1 1
Please input winning tile: 1
Is Self-drawn win?(1: YES 0: NO): 1
Player's wind(0:E 1:S 2:W 3:N): 0
Prevailing wind(0:E 1:S 2:W 3:N): 0
The Score is...
    Flush (6 Han)
    Terminal in each set (3 Han)
    Two sets of identical sequences (2 Han)
    No points Hand (1 Han)
Total: 12 Han
```

Some yakus are not required to implement:

* Ready hand
* Nagashi mangan
* Self-pick
* One-shot
* Last tile from the wall
* Last discard
* Dead wall draw
* Robbing a quad
* Double-ready
* Heavenly hand
* Hand of earth
* Hand of man
* Ancient or local yaku

If no yaku or yakuman for the given hand, it will output `No Yaku`.

```console
./hw0405
Please input meld: 1 2 3 0
Is open/closed group(1: open 0: closed): 1
Please input meld: 30 30 30 0
Is open/closed group(1: open 0: closed): 1
Please input meld: 4 4 4 0
Is open/closed group(1: open 0: closed): 0
Please input meld: 7 8 9 0
Is open/closed group(1: open 0: closed): 0
Please input pair: 12 12
Please input winning tile: 12
Is Self-drawn win?(1: YES 0: NO): 1
Player's wind(0:E 1:S 2:W 3:N): 0
Prevailing wind(0:E 1:S 2:W 3:N): 0
The Score is...
    No Yaku
Total: 0 Han
```

If the program encounters any of the following errors, it will output `Unreasonable case` and the program will be terminated:

* Invalid tile number (1 to 34)
* Invalid open/closed group
* The amount of same tile is larger than 4
* Invalid number of tiles in a meld
* Invalid meld
* Invalid pairs, winning tile, self-drawn, player's wind or prevailing wind

```console
./hw0405
Please input meld: 35
The Score is...
    Unreasonable case
Total: 0 Han
```

### What I have learned/encountered

* Play Japanese Mahjong.

## Bonus Question

The bonus question is written in [hw0406.md](hw0406.md).
