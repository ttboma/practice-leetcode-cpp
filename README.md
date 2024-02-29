# README

## Introduction

This project is a collection of solutions to LeetCode problems provided by ***SHIEH YUEH-CHANG*** written in **C++20**. The purpose of the project is to practice:

- code compilation using [Apple clang version 13.0.0](https://developer.apple.com/xcode/cpp/) with [C++20](https://en.cppreference.com/w/cpp/20) language support
- debugging using [LLDB](https://lldb.llvm.org)
- building a c++ project with [CMake](https://cmake.org)
- version-controlling using [Git](https://git-scm.com)
- unit-tests using [Google Test](https://github.com/google/googletest)
- generating documentation from annotated C++ sources using [Doxygen](https://www.doxygen.nl)
  - maybe we can try to use in combination with sphinx (breathe bridge plugin) -> [reference](https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/)

## Build on Linux and MacOS

The following commands create `build` directory under the current working directory, and run the generator (Unix Makefiles) with debug build type.

```sh
cmake -G "Unix Makefiles" -B build . && cmake --build build --config Debug -j16
```

To run Google-Tests

```sh
./build/tests/test_solution
```

To run executable:

```sh
./build/src/bin/solution --help
```

## Build and Open Doxygen Documentation

```sh
make docs -C build && open ./build/docs/html/index.html
```

## Development Note

Please follow the conventions, as noted below, to contribute to this project.

- Use chrome and [Clip LeetCode](https://chrome.google.com/webstore/detail/clip-leetcode/cnghimckckgcmhbdokjielmhkmnagdcp/related)
   extension to maintain documentation of each method of [`Solution`]
- Please install the [git hook](https://git-scm.com/book/zh-tw/v2/Customizing-Git-Git-Hooks) scripts by the following [pre-commit](https://pre-commit.com/) command:

   ```bash
   pre-commit install --hook-type commit-msg --hook-type pre-commit --hook-type pre-push
   ```

It is recommended to use [Visual Studio Code](https://code.visualstudio.com/) and plugins listed in the following to maintain your code quality:

- [C/C++ for Visual Studio Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) and [CMake](https://marketplace.visualstudio.com/items?itemName=twxs.cmake)
- [Makefile Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.makefile-tools)
- [GitLens — Git supercharged](https://marketplace.visualstudio.com/items?itemName=eamodio.gitlens)
- [Code Spell Checker](https://marketplace.visualstudio.com/items?itemName=streetsidesoftware.code-spell-checker)
- [markdownlint](https://marketplace.visualstudio.com/items?itemName=DavidAnson.vscode-markdownlint)

If you are using Visual Studio Code and showing some error messages for include headers, set Cmake: `Build Directory` to `${workspaceFolder}/build`

use this command to clang-format all cpp and hpp files:

```bash
make -C build clang-format
```

## To Do

- [ ] How to use debugger tools on Visual Studio Code?
- [ ] How to add clang format, tidy, and sanitizer? [Standard C++ Toolset - Anastasia Kazakova - C++ on Sea 2023](https://www.youtube.com/watch?v=kLNCphYSggY)
