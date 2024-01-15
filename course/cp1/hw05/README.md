# hw0x

41247039S 韓欣劭

Computer Programming (I), hw05

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

and all the c language codes will be compiled by using `gcc`. There will be 5 compiled file, naming `hw0x0x` where `x` is the question number.

This homework has 5+1 questions. The [question](https://drive.google.com/file/d/1X8nfw5xhvEOjvxCWtp-uDlBebc2H4VeF/view) and question's [additional information](https://hackmd.io/@cp2023/cp1-hw5-info) is here (since both links are not mine, the link may become invalid).

The first 5 questions are written in C language, and the bonus question is written in [hw0506.md](hw0506.md). The first 5 questions are executable, by typing

```console
./hw050x
```

where `x` is range from 1 to 5.

## Question 1

Question 1 is about statistics. The function will calculate the mean, variance and the standard deviation of given array of data. The result is stored in pointer.

If it is successfully calculated, the function will return 0. It will return -1 if one of the following errors occurs:

* given data array or pointer is NULL
* size is smaller than or equal to 0

### What I have learned/encountered in Q1

* Nothing special here.

## Question 2

Question 2 is about Gaussian elimination. Given a `n*n` matrix and vector `y`, solve `x` for `Ax = y`.

If the inputs are correct, the function will return 0 for no solution, 1 for one solution and 2 for many solutions. It will return -1 if one of the following errors occurs:

* `n` is smaller than or equal to 0.
* matrix `A` and vector `y` is NULL.
* vector `x` is not NULL.

### What I have learned/encountered in Q2

* Double pointer.

## Question 3

Question 3 is about sphere. The function will calculate the area of base of spherical cap cut off by a plane. The result is stored in a pointer.

If it is successfully calculated, the function will return 1. It will return 0 if no spherical cap is formed. It will return -1 if one of the following errors occurs:

* The given plane is invalid.
* The given radius of sphere is invalid.
* The area pointer is NULL.

### What I have learned/encountered in Q3

* Spherical cap.

## Question 4

Question 4 is about TLV. By giving an array of TLV data, the function can convert the data to a series of TLV commands. Each TLV commands to be implemented is given in [hw05](https://drive.google.com/file/d/1X8nfw5xhvEOjvxCWtp-uDlBebc2H4VeF/view).

If it is successfully executed, the function will return 0. It will return -1 if one of the following errors occurs:

* TLV array is NULL.
* The given size is lower than or equal to 0.
* The TLV array is invalid in size.
* The length of each TLV is invalid.
* The 'Cancel' TLV is used incorrectly.

### What I have learned/encountered in Q4

* TLVs.

## Question 5

Question 5 is about TAS speedrun. The function can generate a frame-by-frame array. This array is used to generate a `.fm2` file for TAS speedrun in NES platform.

The function will stop if one of the following errors occurs:

* Size pointer in `button_set_frame()` is NULL.
* Source array in `button_unset_frame()` is NULL.
* Start frame is larger than end frame.

### What I have learned/encountered in Q5

* The amazing of speedrun.

## Bonus Question

The bonus question is written in [hw0506.md](hw0506.md).
