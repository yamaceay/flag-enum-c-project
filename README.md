<!-- PROJECT LOGO -->
<br />
<div align="center">
    <img src="https://cdn-icons-png.flaticon.com/512/395/395841.png" alt="Logo" width="80" height="80">

  <h3 align="center">REFLAG</h3>

  <p align="center">
    A modern redefinition of flags in C programming. You can define 
    <br />
    your flags as enum objects and enjoy the abstraction. It is minimal, 
    <br />
    fast and reusable.
    <br />
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about">About</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#structure">Structure</a></li>
    <li><a href="#api">API</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT -->
## About

C Programming might not be beginner-friendly, especially when it comes to bitwise operations and flags, which are basically ones and zeros.
 
With flags one can:
* configure a function as wished
* control the program flow
* make the code more dynamic 

I assume you don't want to deal with bitwise operations in flagging, me neither. Or maybe you want to just level up your program. I implemented a brand new data structure so that you don't have to and here's why:

It can:
* be useful at debugging because it has a print method
* hold the names of enumeration variables
* be easily extended because it is created in OOP-like style

Of course, this has still thousand problems. I'll be testing and developing more in the near future. You may also suggest changes by forking this repo and creating a pull request or opening an issue. Thanks to all the people have contributed to expanding this template!


<p align="right">(<a href="#top">back to top</a>)</p>


### Built With

Here are the dependencies:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
```

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

### Prerequisites

These are the list of things you need to install:
* A C Compiler, preferably [gnu](https://www.gnu.org) or [clang](https://clang.llvm.org)
* [cmake](https://cmake.org)

### Installation

All you need is to clone the repo. Here's the code:

```sh
git clone https://github.com/yamaceay/reflag.git
```

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- STRUCTURE -->
## Structure

- [X] (_means the content of the folder can be changed_)

- *src* (Source files)
- *include* (Header files)
- [X] *test* (Test files)
    - *my\_test.c*
    - *your\_test.c*
- [X] *output* (Output)
    - *my\_test*
    - *your\_test*
- [X] *input* (Input)
    - *all.c* (Don't modify) 
    - *my\_enum.txt*
    - *your\_enum.txt*
- [X] *CMakeLists.txt* (Build & Run Configurations)
- Other files

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- API EXAMPLES -->
## API

<!-- API: TABLE OF CONTENTS -->
<details>
  <summary> API: TABLE OF CONTENTS</summary>
  <ol>
    <li>Flag (Flag.h)
      <ul>
        <li>Flag - Attributes</li>
        <li>Flag - Methods</li>
      </ul>
    </li>
    <li>
      Enum (Enum.h)
      <ul>
        <li>Enum - Attributes</li>
        <li>Enum - Methods</li>
      </ul>
    </li>
    <li>
      Renum (Renum.h)
      <ul>
        <li>Renum - Attributes</li>
        <li>Renum - Methods</li>
      </ul>
    </li>
  </ol>
</details>

### Flag (Flag.h)

#### Flag - Attributes

| Attributes | Type | Description |
|------------|------|-------------|
| __flags | uint32_t | Stores the flags as an unsigned integer value |
| __names | char \* | (optional) Renames the flags for printing purposes |

#### Flag - Methods

| Methods | Type | Arguments | Description |
|---------|------|-----------|-------------|
| init | void | char *names | Initializes a flag object |
| get | uint32_t | void \*\_self | Returns the \_\_flags |
| is | bool | void \*\_self, uint32_t aFlag | Checks if the new flag has been already set (using bitwise AND)|
| set | void | void \*\_self, uint32_t aFlag | Adds the new flag to the flag (using bitwise OR) |
| reset | void | void \*\_self, uint32_t aFlag | Removes the new flag from the flag (using bitwise OR and bitwise NOT)|
| getNames | char \* | void \*\_self | Gets the names attribute |
| setNames | void | void \*\_self | Sets the names attribute
| print | void | void \*\_self | Prints the actual state of flag (optionally renamed)

### Enum (Enum.h)

#### Enum - Attributes

| Attributes | Type | Description |
|------------|------|-------------|
| flag | Flag | Extends flag |
| __len | uint32_t | Defines the number of items in enum |

#### Enum - Methods

| Methods | Type | Arguments | Description |
|---------|------|-----------|-------------|
| init | void | char *names, uint32_t len | Initializes an enum object |
| get | uint32_t | void \*\_self | Returns the flag.\_\_flags |
| is | bool | void \*\_self, uint32_t anEnum | Checks if the new enum has been already added (1 << anEnum is given as parameter to Flag.is(...))|
| set | void | void \*\_self, uint32_t anEnum | Adds the new enum to the enum (1 << anEnum is given as parameter to Flag.set(...)) |
| reset | void | void \*\_self, uint32_t anEnum | Removes the new enum from the enum (1 << anEnum is given as parameter to Flag.reset(...))|
| getNames | char \* | void \*\_self | Gets the names attribute |
| setNames | void | void \*\_self | Sets the names attribute
| print | void | void \*\_self | Prints the actual state of enum (optionally renamed)

### Renum (Renum.h)

#### Renum - Attributes

| Attributes | Type | Description |
|------------|------|-------------|
| flag | Flag | Extends flag |
| __len | uint32_t | Defines the number of items in renum |

#### Renum - Methods

| Methods | Type | Arguments | Description |
|---------|------|-----------|-------------|
| init | void | char *names, uint32_t len | Initializes a renum object |
| get | uint32_t | void \*\_self | Returns the flag.\_\_flags |
| any | bool | void \*\_self, uint32_t aRenum | Checks if there is any renum that has been already added (for each renum in aRenum: 1 << renum is given as parameter to Flag.is(...))|
| all | bool | void \*\_self, uint32_t aRenum | Checks if all renums have been already added (for each renum in aRenum: 1 << renum is given as parameter to Flag.is(...))|
| set | void | void \*\_self, uint32_t aRenum | Sets each renum (for each renum in aRenum: 1 << renum is given as parameter to Flag.set(...)) |
| reset | void | void \*\_self, uint32_t aRenum | Removes the new renum (for each renum in aRenum: 1 << renum is given as parameter to Flag.reset(...))|
| getNames | char \* | void \*\_self | Gets the names attribute |
| setNames | void | void \*\_self | Sets the names attribute
| print | void | void \*\_self | Prints the actual state of renum (optionally renamed)


<p align="right">(<a href="#top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

For development and testing purposes, you need to follow the steps below:

1. *input*: Create the enum by writing a text file in input directory *your\_enum* and list as follows: 
```txt
    your_item_1
    your_item_2
    your_item_3
    your_item_4
```
which will create the following enum in the Step 3:
```c
typedef enum your_enum {
    your_item_1,
    your_item_2,
    your_item_3,
    your_item_4
} your_enum;
```
In Step 3: If you set is\_flag to t (true), it adds an extra feature:
```c
typedef enum your_enum {
    your_item_1 = 1,
    your_item_2 = 2,
    your_item_3 = 4,
    your_item_4 = 8
} your_enum;
```

2. *test*: Testing file should be included in test directory and has a name *your*\_test.c

3. *CMakelists.txt*: 
    ```c
    // list of file names separated by ;
    set(test_files my1 ; my2 ; *your*)
    
    // set t 
    // if your enum uses flag
    // else f
    set(are_flags t ; f ; *f*)
    ```

4. *Terminal*: Run the following code:
    ```sh
    cmake .
    ```
    As the result, you can now run the test output file using:
    ```sh
    ./output/*your*_test
    ```


<p align="right">(<a href="#top">back to top</a>)</p>




<!-- CONTRIBUTING -->
## Contributing

Contributions are what make this community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request.
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/your_feature`)
3. Commit your Changes (`git commit -m 'Add some your_feature'`)
4. Push to the Branch (`git push origin feature/your_feature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Yamac Eren Ay - [LinkedIn Account](https://www.linkedin.com/in/yamaceay)

Project Link: [https://github.com/yamaceay/reflag](https://github.com/yamaceay/reflag)

<p align="right">(<a href="#top">back to top</a>)</p>
