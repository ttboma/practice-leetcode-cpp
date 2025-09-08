# Table of Content

- [Table of Content](#table-of-content)
  - [Introduction](#introduction)
  - [Build](#build)
    - [Build on Linux and MacOS with single-configuration generator (Unix Makefiles)](#build-on-linux-and-macos-with-single-configuration-generator-unix-makefiles)
    - [Build on Windows with Multi-configuration Generator (Visual Studio 17 2022)](#build-on-windows-with-multi-configuration-generator-visual-studio-17-2022)
    - [Having Problem of Building on Windows with Clang](#having-problem-of-building-on-windows-with-clang)
  - [Development Note](#development-note)
    - [How to debug with CodeLLDB](#how-to-debug-with-codelldb)
  - [To Do](#to-do)

## Introduction

This project is a collection of solutions to LeetCode problems provided by ***SHIEH YUEH-CHANG*** written in **C++20**. The purpose of the project is to practice:

- Classical data structures and algorithms and Developing proficiency with modern C++20 features.
- Building a C++ project with [CMake](https://cmake.org) for multiple platforms
- Version-controlling using [Git](https://git-scm.com)
- Design program options with [Boost.Program_options](https://www.boost.org/doc/libs/1_62_0/doc/html/program_options.html)
- Unit-tests using [Google Test](https://github.com/google/googletest)
- Generating documentation from annotated C++ sources using [Doxygen](https://www.doxygen.nl)
  - and maybe we can try to use in combination with sphinx (breathe bridge plugin) -> [reference](https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/)
- Gain proficiency with your preferred IDE and its associated extensions.
For example, when using Visual Studio Code, the [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) provides essential features. In particular, ensure familiarity with language server support (IntelliSense) and integrated debugging capabilities.

## Build

### Build on Linux and MacOS with single-configuration generator (Unix Makefiles)

Dependencies:

- cxx compiler
- make
- cmake
- boost
- google-test (optional)
- doxygen (optional)

The following commands create `build` directory under the current working directory, and run the generator of your choice (in this example, Unix Makefiles) with debug or release build type. Then, run google-test to check if everything is successful.
And finally, run the binary `solution`:

```sh
# build with debug build type
% cmake -S . -G "Unix Makefiles" -B build -D CMAKE_BUILD_TYPE=Debug
% cmake --build build -j16
% ./build/tests/test_solution
% ./build/src/bin/solution --help

# or with release build type
% cmake -S . -G "Unix Makefiles" -B build -D CMAKE_BUILD_TYPE=Release
% cmake --build build -j16
% ./build/tests/test_solution
% ./build/src/bin/solution --help
```

To build and open Doxygen documentation:

```sh
% cmake --build build --target docs
% open ./build/docs/html/index.html
```

### Build on Windows with Multi-configuration Generator (Visual Studio 17 2022)

Dependencies:

- [Visual Studio](https://code.visualstudio.com/docs/cpp/config-msvc#_run-vs-code-outside-the-developer-command-prompt), make sure that your **Desktop development with C++** includes:
  - MSVC
  - clang (optional)
  - cmake
- [boost](https://boostorg.jfrog.io/artifactory/main/release/1.84.0/source/boost_1_84_0.7z)
- google-test (optional)
- doxygen (optional)

To install boost with default toolset:

```powershell
> cd C:\Program Files\boost\boost_1_82_0
> bootstrap.bat
> b2 install --prefix="C:\Program Files\boost" --with-date_time --with-filesystem --with-program_options --with-regex --with-system
```

To build with MSBuild and Visual C++ (MSVC)

```powershell
> cmake -S . -G "Visual Studio 17 2022" -B build

# build with debug build type
> cmake --build build --config Debug -j16
> .\build\tests\Debug\test_solution.exe
> .\build\src\bin\Debug\solution.exe

# or with release build type
> cmake --build build --config Release -j16
> .\build\tests\Release\test_solution.exe
> .\build\src\bin\Release\solution.exe
```

### Having Problem of Building on Windows with Clang

Note that if I am going to build with MSBuild and Clang or with Ninga and Clang, linking to boost libraries will fail:

```powershell
> cmake -G "Visual Studio 17 2022" -B build -T ClangCL
-- Selecting Windows SDK version 10.0.22621.0 to target Windows 10.0.19044.
-- The CXX compiler identification is Clang 17.0.3 with MSVC-like command-line
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/x64/bin/clang-cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
CMake Error at C:/Program Files/boost/lib/cmake/Boost-1.82.0/BoostConfig.cmake:141 (find_package):
  Found package configuration file:

    C:/Program Files/boost/lib/cmake/boost_program_options-1.82.0/boost_program_options-config.cmake

  but it set boost_program_options_FOUND to FALSE so package
  "boost_program_options" is considered to be NOT FOUND.  Reason given by
  package:

  No suitable build variant has been found.

  The following variants have been tried and rejected:

  * libboost_program_options-vc143-mt-gd-x64-1_82.lib (vc143, detected
  clangw17, set Boost_COMPILER to override)

  * libboost_program_options-vc143-mt-x64-1_82.lib (vc143, detected clangw17,
  set Boost_COMPILER to override)

Call Stack (most recent call first):
  C:/Program Files/boost/lib/cmake/Boost-1.82.0/BoostConfig.cmake:262 (boost_find_component)
  C:/Program Files/CMake/share/cmake-3.29/Modules/FindBoost.cmake:594 (find_package)
  cmake/find-dependency.cmake:2 (find_package)
  CMakeLists.txt:11 (include)

-- Configuring incomplete, errors occurred!
```

```powershell
> cmake -B build -G Ninja -DCMAKE_C_COMPILER="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\Llvm\bin\clang.exe" -DCMAKE_CXX_COMPILER="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\Llvm\bin\clang++.exe"
-- The CXX compiler identification is Clang 17.0.3 with GNU-like command-line
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/bin/clang++.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
CMake Error at C:/Program Files/boost/lib/cmake/Boost-1.82.0/BoostConfig.cmake:141 (find_package):
  Found package configuration file:

    C:/Program Files/boost/lib/cmake/boost_program_options-1.82.0/boost_program_options-config.cmake

  but it set boost_program_options_FOUND to FALSE so package
  "boost_program_options" is considered to be NOT FOUND.  Reason given by
  package:

  No suitable build variant has been found.

  The following variants have been tried and rejected:

  * libboost_program_options-vc143-mt-gd-x64-1_82.lib (64 bit, need 32)

  * libboost_program_options-vc143-mt-x64-1_82.lib (64 bit, need 32)

Call Stack (most recent call first):
  C:/Program Files/boost/lib/cmake/Boost-1.82.0/BoostConfig.cmake:262 (boost_find_component)
  C:/Program Files/CMake/share/cmake-3.29/Modules/FindBoost.cmake:594 (find_package)
  cmake/find-dependency.cmake:2 (find_package)
  CMakeLists.txt:11 (include)

-- Configuring incomplete, errors occurred!
```

And if I try to build boost with clang, it fails:

```powershell
> b2 toolset=clang install --prefix="C:\Program Files\boost" --with-date_time --with-filesystem --with-program_options --with-regex --with-system
clang-linux.compile.c++ bin.v2\libs\date_time\build\clang-linux-17\debug\address-model-64\link-static\threading-multi\visibility-hidden\gregorian\greg_month.obj
clang-linux.compile.c++ bin.v2\libs\program_options\build\clang-linux-17\debug\address-model-64\link-static\threading-multi\visibility-hidden\convert.obj
clang-linux.archive bin.v2\libs\date_time\build\clang-linux-17\debug\address-model-64\link-static\threading-multi\visibility-hidden\libboost_date_time-clang17-mt-d-x64-1_82.lib
CreateProcessA() Windows API failed: 2 - 系統找不到指定的檔案。

(略)

...failed updating 12 targets...
...skipped 36 targets...
...updated 17123 targets...
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
- [markdownlint](https://marketplace.visualstudio.com/items?itemName=DavidAnson.vscode-markdownlint)
- [Code Spell Checker](https://marketplace.visualstudio.com/items?itemName=streetsidesoftware.code-spell-checker)
- [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb)
- [Error Lens](https://marketplace.visualstudio.com/items?itemName=usernamehw.errorlens)
- [GitLens — Git supercharged](https://marketplace.visualstudio.com/items?itemName=eamodio.gitlens)
- [pre-commit](https://marketplace.visualstudio.com/items?itemName=elagil.pre-commit-helper)

If you are using Visual Studio Code and showing some error messages for include headers, set Cmake: `Build Directory` to `${workspaceFolder}/build` or `${workspaceFolder}/build-debug` or `${workspaceFolder}/build-release` or whatever
your cmake binary directory

Please use this cmake custom command to exploit clang-format on all cpp and hpp files, where `build` followed by `--build` option is the cmake build directory you specified by, for example, `cmake -S . -G "Unix Makefiles" -B build`

```bash
% cmake --build build-debug --target clang-format
```

### How to debug with CodeLLDB

To debug using CodeLLDB, press `ctrl+shift+D` and choose names besides the green triangle button from `simple debugging solution` and `simple debugging test_solution`, if you got `.vscode/launch.json` as the following.
Note that if you need to pass arguments to binary `solution`, just change the field `args`

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "type": "lldb",
            "request": "launch",
            "name": "simple debugging solution",
            "program": "${workspaceFolder}/build/src/bin/solution",
            "args": ["--fib"],
            "cwd": "${workspaceFolder}"
        },
        {
            "type": "lldb",
            "request": "launch",
            "name": "simple debugging test_solution",
            "program": "${workspaceFolder}/build/tests/test_solution",
            "args": [],
            "cwd": "${workspaceFolder}"
        }
    ]
}
```

## To Do

- [ ] `find_program(CLANG_TIDY "clang-tidy")` is not successful on Mac?
- [ ] more pre-commit hook (currently commented out) are not available on Mac?
- [ ] use more c++ tool, like sanitizer? [Standard C++ Toolset - Anastasia Kazakova - C++ on Sea 2023](https://www.youtube.com/watch?v=kLNCphYSggY)
