# hw01

41247039S 韓欣劭

Computer Programming (I), hw03

## Table of Contents

* [Run & Execute](#run-and-execute)
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

and all the c language codes will be compiled by using `gcc`. There will be 5 compiled file, naming `hw0x0x` where `x` is the question number.

This homework has 5+2 questions. The [question](https://drive.google.com/file/d/18eUmUuUBb_tfIyJvcjrOakSlaVVAlhRp/view) and question's [additional information](https://hackmd.io/@cp2023/cp1-hw3-info) is here (since both links are not mine, the link may become invalid).

The first 5 questions are written in C language, and the bonus questions are written in [hw0306.md](hw0306.md) and [hw0307.md](hw0307.md). The first 5 questions are executable, by typing

```console
./hw030x
```

where `x` is 1, 2, 3, 5. To execute question 1 and 2, additional files of `hw0301.c` and `hw0302.c` are required. For question 4, by tying

```console
./hw0304-y
```

where `y` is 1 and 2.

## Question 1

Question 1 is about implementing the functions of a circle. The center of the circle is at the origin of Cartesian coordinate. After setting radius of a circle, the program will be able to calculate the following answers:

* The circumference of the circle
* The area of the circle
* The area bounded by the tangent line at the point (x,y) on the circle, x-axis and y-axis.
* The area of a inscribed regular polygon
* The area of a circumscribed regular polygon

As there's no need to implement main function, the example of this question is skipped.

### What I have learned/encountered

* Calculate the area of inscribed and circumscribed regular polygon.

## Question 2

Question 2 is about controlling the position of a character. After setting the position and angle of a character, the program will be able to do the following features:

* Walk forward the given length at facing direction
* Turn the character clockwise or counter clockwise
* Print the current position and angle (unit: rad/pi)

As there's no need to implement main function, the example of this question is skipped.

### What I have learned/encountered

* Calculate the (x,y) point of the character.

## Question 3

Question 3 is about printing the binary form of a 32-bit signed integer. The user is required to input a number, and the program will print the binary form of the given number. Loop and bitwise operation are not allowed in this question.

```console
$ ./hw0303
Please enter the number: -2147483648
10000000 00000000 00000000 00000000
```

If the given number is out of range, an error message will be given and the program will be terminated.

```console
$ ./hw0303
Please enter the number: 2147483648
Error: the number is out of range
```

### What I have learned/encountered

* Print binary number in recursive form.

## Question 4

Question 4 requires to print the procedure of Tower of Hanoi. The user is required to input an integer between 2 and 20 (included) and the program will output the result of procedure with the given number of disks.

The output of `hw0304-1` and `hw0304-2` are the same. The difference of these 2 files is the implementation of the function. `hw0304-1` uses recursion while `hw0304-2` uses iteration.

```console
$ ./hw0304-1
Please enter the disk number (2-20): 2
move disk 1 to rod 3
move disk 2 to rod 2
move disk 1 to rod 2
$ ./hw0304-2
Please enter the disk number (2-20): 3
move disk 1 to rod 2
move disk 2 to rod 3
move disk 1 to rod 3
move disk 3 to rod 2
move disk 1 to rod 1
move disk 2 to rod 2
move disk 1 to rod 2
```

If the given number is out of range, an error message will be given and the program will be terminated.

```console
$ ./hw0304-1
Please enter the disk number (2-20): 25
Error: the number is out of range
```

### What I have learned/encountered

* Print the Tower of Hanoi in both iteration and recursion ways.

## Question 5

Question 5 is about implementing the function of rolling dices. When executing the file, a main menu is ptinted out.

```console
$ ./hw0305
Welcome to the Dice Roll 3000!

 ____  _            _____ _____ _ _    ___ ___ ___ ___
|    \|_|___ ___   | __  |     | | |  |_  |   |   |   |
|  |  | |  _| -_|  |    -|  |  | | |  |_  | | | | | | |
|____/|_|___|___|  |__|__|_____|_|_|  |___|___|___|___|

Please refer to README.md for more instructions.
0. Exit the roller
1. Roll a 6-sided dice
2. Roll given number of given-sided dices
3. Roll given number of given-sided dices, keep given dices and set the value to add to the sum
4. Roll given number of given-sided dices, keep given, highest and lowest dices and set the value to add to the sum
8. Print this menu
9. Clear the screen and print this menu
99. Let's play the game CPI-SRPG!

---------------------------------------------------------------------
Menu choice:
```

The user is required to input one of the menu options. After selecting the option, the program will execute the corresponding feature.

### Notes of Q5

Some **notes** about this question are given here:

* The program will keep running until [option 0](#option-0) is given in menu choice or any reasonable linux signals are called. If the process of the given option is ended, the program will return to main menu.
* The source of ASCII art of "Dice Roll 3000" and "CPI SRPG" is given [here](https://patorjk.com/software/taag/#p=display&f=Rectangles&t=Dice%20Roll%203000).
* There are 2 different ASCII arts used to print the dice. The complex one is used in option 1 to option 4, while the simpler one is used in option 99 for readability.
* The comparison of a complex dice's ASCII art and a simple dice's ASCII art:

  ```console
  Complex:  | Simple:
    *---*   | [  1]
   /     \  |
  *  001  * |
   \     /  |
    *---*   |
  ```

* The value of the *complex dice* is printed in 3 digits with leading zeros. For example, `65` will be printed in `065` and `1` will be printed in `001`.
* "Rolling **A** dices with **X** faces each" is written as " roll AdX". For example, "roll 3d6" means "rolling 3 dices with 6 faces each".
* **Constraints** of the dices input:
  * The number of dices **A**: 0 ≤ A ≤ 10
  * The number of faces of a dice **X**: 2 ≤ X ≤ 100
  * The number **B** to add to the sum: -10 ≤ B ≤ 10
  * The number of dices to keep **Y**, the number of highest dices to keep **H** and the number of lowest dices to keep **L**: 0 ≤ Y + H + L ≤ 10
* User's selected kept dices are colored in **green**, highest kept dices are **red** and lowest kept dices are **cyan**. As colored custom text is not available in default markdown file, please refer to the executable file for colored text.
* If any inputs of **A, B, Y, H** and **L** are out of range, the process of that option will be terminated and the program will return to main menu.

Each options's manual is listed below:

* [Option 0](#option-0)
* [Option 1](#option-1)
* [Option 2](#option-2)
* [Option 3](#option-3)
* [Option 4](#option-4)
* [Option 8](#option-8)
* [Option 9](#option-9)
* [Option 99](#option-99)

### Option 0

**Option 0** terminates the program.

```console
---------------------------------------------------------------------
Menu choice: 0

Goodbye!
```

### Option 1

**Option 1** rolls 1d6.

```console
---------------------------------------------------------------------
Menu choice: 1

==== Roll 1d6 ====
  *---*
 /     \
*  003  *
 \     /
  *---*

Result: 3

---------------------------------------------------------------------
Menu choice:
```

### Option 2

**Option 2** rolls **AdX**, where **A** and **X** are given by the user. The program will print the dices and calculate the sum of all dices.

```console
---------------------------------------------------------------------
Menu choice: 2

==== Roll the dice ====
Number of dices(0<=A<=10): 5
Number of sides(2<=X<=100): 20

==== Roll 5d20 ====
  *---*     *---*     *---*     *---*     *---*
 /     \   /     \   /     \   /     \   /     \
*  003  * *  016  * *  011  * *  007  * *  017  *
 \     /   \     /   \     /   \     /   \     /
  *---*     *---*     *---*     *---*     *---*

Result: 3 + 16 + 11 + 7 + 17 = 54

---------------------------------------------------------------------
Menu choice:
```

Any out-of-range numbers will stop the following process and back to main menu.

```console
---------------------------------------------------------------------
Menu choice: 2

==== Roll the dice ====
Number of dices(0<=A<=10): 10
Number of sides(2<=X<=100): 1000
Uh oh, the number of sides (X) is out of range (2~100).

---------------------------------------------------------------------
Menu choice:
```

### Option 3

**Option 3** rolls **AdX**, keeps the user's selected **Y** dices and adds value **B** to sum. The user should follow the steps below:

1. Enter the number of dices **A** and sides **X**. The program will print the rolled dices with index.
2. Enter the number of dices to keep **Y**. If picking none or all of the dices, *step 3 is skipped*.
3. Enter the index of the dices to keep the dice. If the input index is selected or invalid, an error message will be given and the user is required to input again.
4. Enter the value **B** to add to the sum. The program will print the result and calculate the sum of the kept dices.

As stated in the [notes](#notes-of-q5), the kept dices will be printed in green color for readability. Any out-of-range numbers will stop the following process and back to main menu.

```console
---------------------------------------------------------------------
Menu choice: 3

==== Roll the dice ====
Number of dices(0<=A<=10): 5
Number of sides(2<=X<=100): 20

==== Roll 5d20 ====
1.        2.        3.        4.        5.
  *---*     *---*     *---*     *---*     *---*
 /     \   /     \   /     \   /     \   /     \
*  004  * *  008  * *  018  * *  003  * *  010  *
 \     /   \     /   \     /   \     /   \     /
  *---*     *---*     *---*     *---*     *---*

==== Keep the selected dices ====
Number of selected dices (0<=Y<=5): 2
Dice 1: 3
Dice 2: 5

==== Add number to sum ====
Number to add to the sum (-10<=B<=10): 1

==== Selected dices ====
  *---*     *---*     *---*     *---*     *---*
 /     \   /     \   /     \   /     \   /     \
*  004  * *  008  * *  018  * *  003  * *  010  *
 \     /   \     /   \     /   \     /   \     /
  *---*     *---*     *---*     *---*     *---*

Result: 18 + 10 + 1 = 29

---------------------------------------------------------------------
Menu choice:
```

### Option 4

**Option 4** rolls **AdX**, keeps the highest **H**, lowest **L** and user's selected **Y** dices, then adds the value **B** to sum. The user should follow the steps below:

1. Enter the number of dices **A** and sides **X**. The program will print the rolled dices with index.
2. Enter the number of highest dices **H** to keep. If **H** equals to number of dices **A**, *step 3, 4 and 5 is skipped*.
3. Enter the number of lowest dices **L** to keep. If sum of **H** and **L** is equal to **A**, *step 4 and 5 is skipped*.
4. Enter the number of dices **Y** to keep. If picking none or the sum of **H, L, Y** is equal to **A**, *step 5 is skipped*.
5. Enter the index of the dices to keep the dice. If the input index is selected or invalid, an error message will be given and the user is required to input again.
6. Enter the value **B** to add to the sum. The program will print the result and calculate the sum of the kept dices.

As stated in the [notes](#notes-of-q5), the kept dices will be printed in different color (*red* for highest, *cyan* for lowest, *green* for selected) for readability. Any out-of-range numbers will stop the following process and back to main menu.

```console
---------------------------------------------------------------------
Menu choice: 4

==== Roll the dice ====
Number of dices(0<=A<=10): 5
Number of sides(2<=X<=100): 100

==== Roll 5d100 ====
1.        2.        3.        4.        5.
  *---*     *---*     *---*     *---*     *---*
 /     \   /     \   /     \   /     \   /     \
*  022  * *  015  * *  036  * *  037  * *  071  *
 \     /   \     /   \     /   \     /   \     /
  *---*     *---*     *---*     *---*     *---*

==== Keep highest and lowest dices ====
Number of highest dices to keep (0<=H<=5): 1
Number of lowest  dices to keep (0<=L<=4): 1

==== Selected dices ====
1.        2.        3.        4.        5.
  *---*     *---*     *---*     *---*     *---*
 /     \   /     \   /     \   /     \   /     \
*  022  * *  015  * *  036  * *  037  * *  071  *
 \     /   \     /   \     /   \     /   \     /
  *---*     *---*     *---*     *---*     *---*

==== Keep the selected dices ====
Number of selected dices (0<=Y<=3): 1
Dice 1: 1

==== Add number to sum ====
Number to add to the sum (-10<=B<=10): 1

==== Selected dices ====
  *---*     *---*     *---*     *---*     *---*
 /     \   /     \   /     \   /     \   /     \
*  022  * *  015  * *  036  * *  037  * *  071  *
 \     /   \     /   \     /   \     /   \     /
  *---*     *---*     *---*     *---*     *---*

Result: 22 + 15 + 71 + 1 = 109

---------------------------------------------------------------------
Menu choice:
```

### Option 8

**Option 8** prints the main menu.

### Option 9

**Option 9** clears the console screen and print the menu.

### Option 99

**Option 99** clears the console and plays the game "CPI-SRPG".

```console
Welcome to CPI-SRPG (Simple RPG)!

 _____ _____ _____    _____ _____ _____ _____ 
|     |  _  |     |  |   __| __  |  _  |   __|
|   --|   __|-   -|  |__   |    -|   __|  |  |
|_____|__|  |_____|  |_____|__|__|__|  |_____|

--- Introduction ---
You are a new adventurer at CPI Town. You are excited to start your new life here. You will have to make many decisions in your future. Now, let's start your journey!

--- Select Class ---
You can select one of the following classes:
1. WARRIOR, a class with higher STR and HP
2. ROGUE,   a class with higher DEX and Luck
3. MAGE,    a class with higher INT and SAN

Select your class:
```

Some features of this game:

* The story is written by me and is assisted by AI.
* Three unique classes with different bonuses.
* For simplicity, the player attributes only have **STR**, **INT** and **DEX**. The player stats only have **HP**, **SAN** and **Luck**.
* Each attribute rolls **4d6, drop lowest**. The attribute score has a minimum of 6 and a maximum of 18. Each stat is decided by some calculation of the attributes.
* All attributes check will roll a **d20**. If the rolled value is not higher than the player's attribute, the roll is a **"success"** roll, otherwise a **"failure"** roll. There's 2 exceptions: rolling 1 is **"critical success"** and 20 is **"critical failure"**.
* Unique boss fight.
* A total of 4 endings are included in this game.
* Reference of the [rules](https://roll20.net/compendium/dnd5e/Rules:Ability%20Scores?expansion=0#toc_1) and [spell names](https://www.fantasynamegenerators.com/spell-names.php).

For more contents of the game, please play the game! Any suggestions are welcomed for this game.

### What I have learned/encountered

* I thought that a simple version of TRPG is easy to write, but seems like it's not that easy.

## Bonus Question

Bonus questions are written in [hw0306.md](hw0306.md) and [hw0307.md](hw0307.md).
