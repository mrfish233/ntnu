# hw01

41247039S 韓欣劭

Computer Programming (I), hw02

# Table of Contents

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

and all the c language codes will be compiled by using `gcc`. There will be 5 compiled file, naming `hw020x` where `x` is the question number.

This homework has 5+1 questions. The [question](https://drive.google.com/file/d/1tgfOwr0m3uzs76lRPSEcILCMGdtTI362/view) and question's [additional information](https://hackmd.io/@cp2023/cp1-hw2-info) is here (since both links are not mine, the link may become invalid).

The first 5 questions are written in `c` language, and the last question is written in [hw0206.md](hw0206.md).

# Execute

The first 5 questions are executable, by typing
```
./hw020x
```
where `x` is range from 1 to 5.

## Question 1

```
./hw0201
```

### Description

Question 1 is about using **Continued Fraction** to derive the value of `sqrt(2)`. 

The user is required to input an unsigned 16-bits integer. The program will calculate each steps until the given input. Each value has a precision of 15 decimals.

```
$ ./hw0201
Please enter n (16-bits unsigned): 10
n = 1: 1.000000000000000 (-0.414213562373095)
n = 2: 1.500000000000000 (0.085786437626905)
n = 3: 1.400000000000000 (-0.014213562373095)
n = 4: 1.416666666666667 (0.002453104293572)
n = 5: 1.413793103448276 (-0.000420458924819)
n = 6: 1.414285714285714 (0.000072151912619)
n = 7: 1.414201183431953 (-0.000012378941142)
n = 8: 1.414215686274510 (0.000002123901415)
n = 9: 1.414213197969543 (-0.000000364403552)
n = 10: 1.414213624894870 (0.000000062521775)
```

If the user gives out-of-range value, an error message is given and the program is terminated.

```
$ ./hw0201
Please enter n (16-bits unsigned): 0
Error: input is out of range
```

### What I have learned/encountered

* The first version of the question requires 20 precision. Even using long double, it sometimes will round to double precision. This makes the values unable to calculate correctly.

## Question 2

```
./hw0202
```

### Description

Question 2 is same as last homework(multiplication), the only difference is the user can now input unsigned 32-bit integers.

The user is required to input 2 integers, and the program will print the process of multiplication.

```
Please enter the first  number: 1740580933
Please enter the second number: 1269601943
                    1 7 4 0 5 8 0 9 3 3
*)                  1 2 6 9 6 0 1 9 4 3
---------------------------------------
                    5 2 2 1 7 4 2 7 9 9
                  6 9 6 2 3 2 3 7 3 2
              1 5 6 6 5 2 2 8 3 9 7
              1 7 4 0 5 8 0 9 3 3
                              0
        1 0 4 4 3 4 8 5 5 9 8
      1 5 6 6 5 2 2 8 3 9 7
    1 0 4 4 3 4 8 5 5 9 8
    3 4 8 1 1 6 1 8 6 6
  1 7 4 0 5 8 0 9 3 3
---------------------------------------
  2 2 0 9 8 4 4 9 3 4 4 8 5 5 5 2 8 1 9
```

If the given values are out-of-range, an error message is given and the program is terminated.

```
Please enter the first  number: 2147483647
Please enter the second number: 2147483648
Error: number is out of range
```

### What I have learned/encountered

* Print the value from the most significant number.

## Question 3

```
./hw0203
```

### Description

This question is about **Non-deterministic Finite State Machine**. An Automata is given from [the question](https://drive.google.com/file/d/1tgfOwr0m3uzs76lRPSEcILCMGdtTI362/view).

The user is required to input 32-bit integers. The program will keep going until `0` is given. The result will give the current states which follow the Automata.

```
Please enter an integer: 1
Please enter an integer: 2
Please enter an integer: -1
Please enter an integer: 0
Possible States: S5, S6
```

### What I have learned/encountered

* Using one 8-bit integer to save the states of Automata.

## Question 4

```
./hw0204
```

### Description

Question 4 is about **Dollar-cost Average Calculator**. It is used to calculate the rate of return of every month, by giving the investments, date and annual rate of return.

The user is required to input initial investment, recurring monthly investment, start date(year and month), end date and annual rate of return. One of the result is given below:

```
Initial Investment:           50000
Recurring Monthly Investment: 3000
Start Month:                  1
Start Year:                   2023
End Month:                    1
End Year:                     2024
Annual Rate of Return (%):    20
--- Output ---
2023.01) 50000/50000/0/0%
2023.02) 53000/53833/833/1.55%
2023.03) 56000/57730/1730/3%
2023.04) 59000/61692/2692/4.36%
2023.05) 62000/65720/3720/5.66%
2023.06) 65000/69816/4816/6.9%
2023.07) 68000/73979/5979/8.08%
2023.08) 71000/78212/7212/9.22%
2023.09) 74000/82516/8516/10.32%
2023.10) 77000/86891/9891/11.38%
2023.11) 80000/91339/11339/12.42%
2023.12) 83000/95862/12862/13.42%
```

If any given values is out of range(ruled in [the question](https://drive.google.com/file/d/1tgfOwr0m3uzs76lRPSEcILCMGdtTI362/view)), an error message is given and the program is terminated.

```
Initial Investment:           50000
Recurring Monthly Investment: 3000
Start Month:                  1
Start Year:                   2023
End Month:                    1
End Year:                     2022
Annual Rate of Return (%):    20
Error: incorrect date range
```

### What I have learned/encountered

* Learned about dollar-cost averaged investments.
* Extra knowledges of `printf` for about printing leading and trailing zeros.

## Question 5

```
./hw0205
```

### Description

Question 5 is about Catan Simple Islands Engine(CSIE). By giving the length of an island and the number of layers, the program will print the map of Catan Island.

The user is required to input 2 integers. One of the printed result is given here.

```
Please input the length: 4
Please input the number of layer: 2
         *--*
        /    \
       /      \
   *--*        *--*
  /    \      /    \
 /      \    /      \
*        *--*        *
 \      /    \      /
  \    /      \    /
   *--*        *--*
  /    \      /    \
 /      \    /      \
*        *--*        *
 \      /    \      /
  \    /      \    /
   *--*        *--*
       \      /
        \    /
         *--*
```

If the values are out of range, or the length of the islands is too large, an error message is given and the program is terminated.

```
Please input the length: 10
Please input the number of layer: 10
Error: the island is too big
```

### What I have learned/encountered

* Print the **beautiful** islands.
* The code is too messy. Too many if/else used in the code.I'll try to find a way to clean out the code.

## Bonus Question

### Description

This question is about signed and unsigned integer conversion. The answer is written in [hw0206.md](hw0206.md)

### What I have learned/encountered

* Learned about the priority of signed and unsigned integer conversion.

