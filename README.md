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
- make
- cmake
- boost
- google-test (optional)
- doxygen (optional)

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
> cmake -G "Visual Studio 17 2022" -B build
-- Selecting Windows SDK version 10.0.22621.0 to target Windows 10.0.19044.
-- The CXX compiler identification is MSVC 19.39.33521.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.39.33519/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Boost: C:/Program Files/boost/lib/cmake/Boost-1.82.0/BoostConfig.cmake (found version "1.82.0") found components: program_options
-- Could NOT find GTest (missing: GTEST_LIBRARY GTEST_INCLUDE_DIR GTEST_MAIN_LIBRARY)
fetching google-test from https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip ...
-- The C compiler identification is MSVC 19.39.33521.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.39.33519/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Found Python: C:/Program Files (x86)/Microsoft Visual Studio/Shared/Python39_64/python.exe (found version "3.9.13") found components: Interpreter
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - not found
-- Found Threads: TRUE
-- Could NOT find Doxygen (missing: DOXYGEN_EXECUTABLE)
CMake Warning at cmake/find-dependency.cmake:26 (message):
  Doxygen need to be installed to generate the doxygen documentation.
Call Stack (most recent call first):
  CMakeLists.txt:11 (include)


-- Configuring done (15.8s)
-- Generating done (0.1s)
-- Build files have been written to: C:/Users/Johns575/Projects/leetcode_cpp-main/build

# debug build
> cmake --build build --config Debug -j16
> .\build\tests\Debug\test_solution.exe
> .\build\src\bin\Debug\solution.exe

# and release build
> cmake --build build --config Release -j16
> .\build\tests\Release\test_solution.exe
> .\build\src\bin\Release\solution.exe
```

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
