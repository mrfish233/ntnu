# hw01

41247039S 韓欣劭

First homework of Computer Programming (I)

# Tables of Content

* [Run](#run)
* [Execute](#execute)
	* [Question 1](#question-1)
	* [Question 2](#question-2)
	* [Question 3](#question-3)
	* [Question 4](#question-4)
	* [Question 5](#question-5)
	* [Bonus Question](#bonus-question)

# Run

This is just a homework. Therefore it's easy to run these codes. Make sure to `unzip` thie file after download. To run the code, simply just type

```
make
```

and all the c language codes will be compiled by using `gcc`. There will be 5 compiled file, naming `hw010x` where `x` is the question number.

This homework has 5+1 questions. The [question](https://drive.google.com/file/d/1f3jhf9QXumxkfKaonHeTw8yjof8K-x_h/view) and question's [additional information](https://hackmd.io/@cp2023/cp1-hw1-info) is here (since both links are not mine, the link may become invalid).

The first 5 questions are written in `c` language, and the last question is written in [hw0106.md](hw0106.md).

# Execute

The first 5 questions are executable, by typing
```
./hw010x
```
where `x` is range from 1 to 5.

## Question 1

```
./hw0101
```

### Description

The first question is about printing <span style='color: red;'>colorful</span> <span style='color: blue;'>texts</span>. By using [ANSI Escape Codes](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797), the font of printed words can be changed. For example, by typing `\e[0;31m` before a word will change the printed color to <span style='color: red;'>red</span> until the next color code or `\e[0m` is added, which is resetting the color.

The question requires changing name color to <span style='color: blue;'>blue</span> and quoted text to <span style='color: red;'>red</span> from the given paragraph. There's no input requirement in this question.

### What I have learned/encountered

* The amazing [ANSI Escape Codes](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797).
* One paragraph is too long, and I don't change line to print it, which makes it difficult to read.

## Question 2

```
./hw0102
```

### Description

Question 2 is about printing **beautiful** multiplication process. The range of input numbers are between `0` and `99`.

After executing the file, the user is required to input 2 integers, ranging from 0 to 99. One of the result is shown below.

```
$ ./hw0102
Please enter the first  number: 99
Please enter the second number: 99
      9 9
*)    9 9
---------
    8 9 1
  8 9 1
---------
  9 8 0 1
```

If the given integers are outside of range, an error message will print out and the program will be terminated.

```
$ ./hw0102
Please enter the first  number: -1
Wrong input, your input must between 0 ~ 99.
```

### What I have learned/encountered

* The question requires not to use array or loop, therefore the codes are too redundancy.
* Using too many `if` insides another `if`, and I don't know how to flatten it.

## Question 3

```
./hw0103
```

### Description

Question 3 is required to calculate the bounded area by x-axis, y-axis and given line. The user is required to input 2 distinct points A and B by the format `x,y` (including comma). The given line will be drawn from the 2 points.

```
$ ./hw0103
Please enter the point A (x,y): 4,10
Please enter the point B (x,y): 5,20
Area: 45.00
```

If the given line can't form a bounded area, a result of `0` will be given.

```
Please enter the point A (x,y): 1,2
Please enter the point B (x,y): 1,3
Area: 0
```
### What I have learned/encountered

* Revised about bounded area.
* Usage of printing format of `float`.
* If the user does not input the comma, the program will be terminated immediately.

## Question 4

```
./hw0104
```

### Description

Question 4 is about Contract Bridge. The user is required to input 13 cards, and the program will calculate the best opening bidding choice. The bidding rule is given by [Modified Precision in Taiwan(中華精準制)](http://www.weweweb.net/game/webpage/bridge/precision_1.html).

The card encoding rule is given here:

*  1-13: ♠ A, 2, . . ., 9, 10, J, Q, K
* 14-26: ♡ A, 2, . . ., 9, 10, J, Q, K
* 27-39: ♢ A, 2, . . ., 9, 10, J, Q, K
* 40-52: ♣ A, 2, . . ., 9, 10, J, Q, K

One of the result is shown here:

```
$ ./hw0104
1st  card: 1
2nd  card: 12
3rd  card: 13
4th  card: 14
5th  card: 24
6th  card: 25
7th  card: 26
8th  card: 28
9th  card: 29
10th card: 30
11th card: 49
12th card: 50
13th card: 51
HCP: 22 pts
Suit: 3-4-3-3
The bidding choice: 2NT
```

The output HCP and suit order has a more detailed pattern defined in [this pdf file](https://drive.google.com/file/d/1f3jhf9QXumxkfKaonHeTw8yjof8K-x_h/view).

If the user inputs out-of-range integers (besides 1-52), an error message will be given and the program will be terminated immediately.

```
$ ./hw0104
1st  card: -1
Wrong input, your input must between 1 ~ 52
```

### What I have learned/encountered

* The Contract Bridge looks fun to play. I hope one day can play with TAs.
* As it requires 13 inputs, it's hard to debug. I will try to find a way to debug the code.

## Question 5

```
./hw0105
```

### Description

Question 5 is about simulating to write Email to TA. The user is required to input emails, subjects and content scores. The email will be assigned to one of 6 TAs if all input tests are passed.

```
$ ./hw0105
Please enter the sender address      > 41247039s@gapps.ntnu.edu.tw
Please enter the email subject       > [general] Teach me
Please enter the email content score > 202310052359
================================================================================

Sender Address Test : Passed
Email Subject Test  : Passed
Email Content Test  : Passed
--------------------------------------------------------------------------------

Assigned to QB
```

The test requirements are given in [this pdf file](https://drive.google.com/file/d/1f3jhf9QXumxkfKaonHeTw8yjof8K-x_h/view).

If one of the tests failed (e.g. domain name is not authorised), it will reject the Email.

```
$ ./hw0105
Please enter the sender address      > hello@gmail.com
Please enter the email subject       > [general] What is this
Please enter the email content score > 202310052359
================================================================================

Sender Address Test : Failed, domain is not authorised
Email Subject Test  : -
Email Content Test  : -
--------------------------------------------------------------------------------

Rejected
```

### What I have learned/encountered

* Learned more about `scanf`. Also thanks to my friend teaching me about some rules of it.
* There's still a lot of bugs that I don't know how to fix. For example, if extra characters behind a valid email (e.g. `asdf@csie.coolll`) is given, the email test will still pass.
* This question is really hard.

## Bonus Question

### Description

This question is about Makefile. We need to find a way so that even error message is given, the Makefile will still continue to execute the following commands.

As this question is written in [this file](hw0106.md), this place just provides a quick link to jump there.

### What I have learned/encountered

* Makefile is so strong and amazing.

