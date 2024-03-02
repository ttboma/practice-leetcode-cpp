# README

## Introduction

This project is a collection of solutions to LeetCode problems provided by ***SHIEH YUEH-CHANG*** written in **C++20**. The purpose of the project is to practice:

- Building a c++ project with [CMake](https://cmake.org) for multiple platforms
- Version-controlling using [Git](https://git-scm.com)
- Design program options with [Boost.Program_options](https://www.boost.org/doc/libs/1_62_0/doc/html/program_options.html)
- Unit-tests using [Google Test](https://github.com/google/googletest)
- Generating documentation from annotated C++ sources using [Doxygen](https://www.doxygen.nl)
  - and maybe we can try to use in combination with sphinx (breathe bridge plugin) -> [reference](https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/)

## Build

### Build on Linux and MacOS with single-configuration generator (Unix Makefiles)

Dependencies:

- cxx compiler
- cmake
- make
- boost
- google-test
- doxygen

The following commands create `build-debug` directory under the current working directory, and run the generator of your choice (in this example, Unix Makefiles) with debug or release build type. Then, run google-test to check if everything is successful.
And finally, run the binary `solution`:

```sh
# build with debug build type
% cmake -G "Unix Makefiles" -B build-debug .
% cmake --build build-debug --config Debug -j16
% ./build-debug/tests/test_solution
% ./build-debug/src/bin/solution --help

# or with release build type
% cmake -G "Unix Makefiles" -B build-release .
% cmake --build build-release --config Release -j16
% ./build-release/tests/test_solution
% ./build-release/src/bin/solution --help
```

To build and open Doxygen documentation:

```sh
% cmake --build build-release --target docs
% open ./build-release/docs/html/index.html
```

### Build on Windows with Multi-configuration Generator (Visual Studio 17 2022)

Dependencies:

- [Visual Studio](https://code.visualstudio.com/docs/cpp/config-msvc#_run-vs-code-outside-the-developer-command-prompt), make sure that your **Desktop development with C++** includes:
  - MSVC
  - cmake
  - clang (optional)
- boost
- google-test
- doxygen

```powershell
> cmake -G "Visual Studio 17 2022" -B build

# debug build
> cmake --build build --config Debug -j16
> .\build\tests\Debug\test_solution.exe
> .\build\src\bin\Debug\solution.exe

# and release build
> cmake --build build --config Release -j16
> .\build\tests\Release\test_solution.exe
> .\build\src\bin\Release\solution.exe
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

If you are using Visual Studio Code and showing some error messages for include headers, set Cmake: `Build Directory` to `${workspaceFolder}/build` or `${workspaceFolder}/build-debug` or `${workspaceFolder}/build-release` or whatever
your cmake binary directory

Please use this cmake custom command to exploit clang-format on all cpp and hpp files, where `build` followed by `--build` option is the cmake build directory you specified by, for example, `cmake -G "Unix Makefiles" -B build-debug .`

```bash
% cmake --build build-debug --target clang-format
```

## To Do

- [ ] How to use debugger tools on Visual Studio Code?
- [ ] `find_program(CLANG_TIDY "clang-tidy")` is not successful on Mac?
- [ ] more pre-commit hook (currently commented out) are not available on Mac?
- [ ] use more c++ tool, like sanitizer? [Standard C++ Toolset - Anastasia Kazakova - C++ on Sea 2023](https://www.youtube.com/watch?v=kLNCphYSggY)
