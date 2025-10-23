# Table of Content

- [Table of Content](#table-of-content)
  - [Introduction](#introduction)
  - [Build, Test, Docs and Install](#build-test-docs-and-install)
    - [Build on MacOS with Single-Configuration Generator (Unix Makefiles)](#build-on-macos-with-single-configuration-generator-unix-makefiles)
    - [Build on Windows with Multi-Configuration Generator (Visual Studio 17 2022)](#build-on-windows-with-multi-configuration-generator-visual-studio-17-2022)
    - [Having Problem of Building on Windows with Clang](#having-problem-of-building-on-windows-with-clang)
  - [Project Architecture](#project-architecture)
    - [Directory Structure](#directory-structure)
    - [Build System Architecture](#build-system-architecture)
    - [Code Organization](#code-organization)
      - [Solution Pattern](#solution-pattern)
      - [Data Structures](#data-structures)
    - [Suggestions for Improvement](#suggestions-for-improvement)
      - [1. **Separate Header Files per Problem**](#1-separate-header-files-per-problem)
      - [2. **Categorize Solutions by Topic**](#2-categorize-solutions-by-topic)
      - [3. **Add Problem Metadata**](#3-add-problem-metadata)
      - [4. **Improve Test Coverage**](#4-improve-test-coverage)
      - [5. **Add Continuous Integration**](#5-add-continuous-integration)
      - [6. **Performance Benchmarking**](#6-performance-benchmarking)
      - [7. **Better CLI Experience**](#7-better-cli-experience)
      - [8. **Documentation Generation Improvements**](#8-documentation-generation-improvements)
      - [9. **CMake Modern Practices**](#9-cmake-modern-practices)
      - [10. **Add Solution Templates**](#10-add-solution-templates)
    - [Summary](#summary)
  - [Development Note](#development-note)
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
  - For example, when using Visual Studio Code, the [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) provides essential features. In particular, ensure familiarity with language server support (IntelliSense) and integrated debugging capabilities.
  - Nice to have: [Todo Tree](https://marketplace.visualstudio.com/items?itemName=Gruntfuggly.todo-tree), [Code Spell Checker](https://marketplace.visualstudio.com/items?itemName=streetsidesoftware.code-spell-checker), [Markdown All in One](https://marketplace.visualstudio.com/items?itemName=yzhang.markdown-all-in-one)

## Build, Test, Docs and Install

### Build on MacOS with Single-Configuration Generator (Unix Makefiles)

Build with debug build type:

```sh
# Set parallelism for all build steps in the workflow preset
% export CMAKE_BUILD_PARALLEL_LEVEL=8
% cmake --workflow --preset x64-Darwin-Debug
```

If you needs to run individual tests:

```sh
# Lists all tests
% ctest --preset x64-Darwin-Debug -N

# You can also pass filters through ctest and just run the test you want
# The -V (verbose) will show the actual executable path and args, which help debug the test
% ctest --preset x64-Darwin-Debug -R fib.example1 -V

# Debug with lldb or gdb
% lldb -- /Users/shiehyuehchang/Projects/leetcode/leetcode_cpp/out/build/x64-Darwin-Debug/tests/solution/tests_solution "--gtest_filter=fib.example1" "--gtest_also_run_disabled_tests"
```

Open Doxygen documentation:

```sh
% open out/build/x64-Darwin-Debug/docs/html/index.html
```

Build with release build type and install the release package:

```sh
% cmake --workflow --preset x64-Darwin-Release
```

### Build on Windows with Multi-Configuration Generator (Visual Studio 17 2022)

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

## Project Architecture

### Directory Structure

```text
leetcode_cpp/
├── bin/                    # Executable applications
│   └── solution/           # Main solution runner with CLI
├── src/                    # Source code libraries
│   ├── solution/           # LeetCode problem implementations
│   └── design_pattern/     # Design pattern examples
├── tests/                  # Unit tests (Google Test)
│   ├── solution/           # Tests for LeetCode solutions
│   └── design_pattern/     # Tests for design patterns
├── include/                # Public header files
│   └── solution.hpp        # Main solution class and data structures
├── docs/                   # Documentation
│   ├── README.md           # This file
│   └── Doxyfile            # Doxygen configuration
├── cmake/                  # CMake modules and utilities
│   ├── FindDependency.cmake      # Dependency management
│   ├── ClangCxxDevTools.cmake    # Clang tooling setup
│   └── RequireOutOfSourceBuilds.cmake
├── .vscode/                # VS Code workspace settings
├── CMakeLists.txt          # Root CMake configuration
└── CMakePresets.json       # CMake workflow presets
```

### Build System Architecture

The project uses **modern CMake** (3.25+) with the following design principles:

1. **Modular Structure**: Each directory has its own `CMakeLists.txt`, creating distinct library targets
   - `src_solution`: Shared library containing all LeetCode solutions
   - `src_design_pattern`: Shared library for design pattern implementations
   - `bin_solution`: Executable CLI tool linking to solution libraries
   - `tests_solution` & `tests_design_pattern`: Test executables

2. **Interface Library Pattern**: The `compiler_flags` interface library propagates C++20 requirements and compiler warnings to all targets

3. **Dependency Management**:
   - **Boost**: For program options in CLI tool
   - **Google Test**: Either system-installed or fetched automatically via `FetchContent`
   - **Doxygen**: Optional, for documentation generation

4. **Cross-Platform Support**:
   - Unix Makefiles for macOS/Linux (single-configuration)
   - Visual Studio generators for Windows (multi-configuration)
   - CMake presets for standardized workflows (`x64-Darwin-Debug`, `x64-Darwin-Release`)

### Code Organization

#### Solution Pattern

Each LeetCode problem follows a consistent pattern:

- **Implementation**: `src/solution/problemName.cpp` - Contains the solution method(s)
- **Test**: `tests/solution/problemName.cpp` - Contains Google Test cases
- **Declaration**: `include/solution.hpp` - Public interface via `Solution` class

All solutions are methods of a single `Solution` class, making them easy to discover and test individually.

#### Data Structures

Common data structures (`ListNode`, `TreeNode`, `Node`, etc.) are defined in `solution.hpp` and shared across all solutions.

### Suggestions for Improvement

#### 1. **Separate Header Files per Problem**

**Current Issue**: The monolithic `solution.hpp` (266+ lines) contains all problem declarations, making it harder to maintain and increasing compilation dependencies.

**Recommendation**:

```text
include/
├── solution/
│   ├── addBinary.hpp
│   ├── fib.hpp
│   ├── dayOfTheWeek.hpp
│   └── ...
├── data_structures/
│   ├── list_node.hpp
│   ├── tree_node.hpp
│   └── ...
└── solution.hpp  # Main header that includes necessary sub-headers
```

**Benefits**: Faster compilation, clearer dependencies, easier to navigate

#### 2. **Categorize Solutions by Topic**

**Current Issue**: 50+ solutions in a flat directory structure make it difficult to find related problems.

**Recommendation**:

```text
src/solution/
├── array/
│   ├── removeDuplicates.cpp
│   ├── maxSubArray.cpp
│   └── ...
├── dynamic_programming/
│   ├── fib.cpp
│   ├── climbStairs.cpp
│   ├── rob.cpp
│   └── ...
├── linked_list/
│   ├── mergeTwoLists.cpp
│   ├── hasCycle.cpp
│   └── ...
└── tree/
    ├── maxDepth.cpp
    ├── isBalanced.cpp
    └── ...
```

**Benefits**: Better organization, easier to study problems by category, clearer learning path

#### 3. **Add Problem Metadata**

**Recommendation**: Create a `problems.json` or use Doxygen tags to track:

- LeetCode problem number
- Difficulty level (Easy/Medium/Hard)
- Problem categories/tags
- Time/space complexity
- Related problems

Example in Doxygen:

```cpp
/**
 * @brief Day of the Week (LeetCode #1185)
 * @difficulty Easy
 * @topics Math, Array
 * @leetcode https://leetcode.com/problems/day-of-the-week/
 * @complexity Time: O(1), Space: O(1)
 */
std::string dayOfTheWeek(int day, int month, int year);
```

#### 4. **Improve Test Coverage**

**Current Observation**: Only ~18 test files for 50+ solution implementations.

**Recommendation**:

- Aim for 100% test coverage
- Add edge case tests (empty inputs, boundary values, large inputs)
- Use parameterized tests for multiple test cases
- Add performance benchmarks for time-critical solutions

#### 5. **Add Continuous Integration**

**Recommendation**: Set up GitHub Actions for:

- Automated builds on multiple platforms (Ubuntu, macOS, Windows)
- Run all tests on every commit
- Code coverage reports
- Clang-tidy static analysis
- Format checking with clang-format

Example workflow:

```yaml
.github/workflows/
├── build-and-test.yml
├── code-coverage.yml
└── static-analysis.yml
```

#### 6. **Performance Benchmarking**

**Recommendation**: Add Google Benchmark integration to measure:

- Execution time for different input sizes
- Memory usage
- Comparison between different solution approaches

#### 7. **Better CLI Experience**

**Current**: `bin/solution.cpp` likely runs specific solutions

**Recommendation**: Enhance the CLI tool to:

- List all available problems
- Filter by difficulty/category
- Run custom test inputs
- Show solution explanations
- Display time/space complexity

Example usage:

```bash
./solution list --difficulty=medium --category=dp
./solution run fib --input=10
./solution test dayOfTheWeek
./solution info --problem=climbStairs
```

#### 8. **Documentation Generation Improvements**

**Current**: Doxygen generates API docs

**Recommendation**:

- Add a solutions index page with problem summaries
- Include algorithm explanations and approach notes
- Add complexity analysis to each solution
- Consider Sphinx + Breathe for richer documentation (as noted in TODO)

#### 9. **CMake Modern Practices**

**Recommendations**:

- Use `target_sources()` instead of globbing for explicit source lists
- Add `PRIVATE`/`PUBLIC`/`INTERFACE` keywords consistently for better encapsulation
- Consider using CMake's `FetchContent` for Boost on Windows to avoid version conflicts
- Add a `version.hpp.in` for version information

#### 10. **Add Solution Templates**

**Recommendation**: Create scripts/templates for adding new problems:

```bash
./scripts/add_problem.sh mergeSortedArray array easy 88
```

This would generate:

- `src/solution/array/mergeSortedArray.cpp` with boilerplate
- `tests/solution/mergeSortedArray.cpp` with test template
- Update `solution.hpp` with declaration
- Update CMakeLists.txt

### Summary

This project demonstrates solid C++ practices with modern CMake, good testing infrastructure, and cross-platform support. The suggested improvements focus on scalability, maintainability, and developer experience as the solution collection grows.

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

## To Do

- [ ] `find_program(CLANG_TIDY "clang-tidy")` is not successful on Mac?
- [ ] more pre-commit hook (currently commented out) are not available on Mac?
- [ ] use more c++ tool, like sanitizer? [Standard C++ Toolset - Anastasia Kazakova - C++ on Sea 2023](https://www.youtube.com/watch?v=kLNCphYSggY)
