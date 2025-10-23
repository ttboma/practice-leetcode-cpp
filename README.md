# Table of Content

- [Table of Content](#table-of-content)
  - [Introduction](#introduction)
  - [Build, Test, Docs and Install](#build-test-docs-and-install)
    - [Build on MacOS with Single-Configuration Generator (Unix Makefiles)](#build-on-macos-with-single-configuration-generator-unix-makefiles)
  - [Project Architecture](#project-architecture)
    - [Directory Structure](#directory-structure)
    - [Build System Architecture](#build-system-architecture)
    - [Code Organization](#code-organization)
      - [Solution Pattern](#solution-pattern)
      - [Data Structures](#data-structures)
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

- [ ] use more c++ tool, like sanitizer? [Standard C++ Toolset - Anastasia Kazakova - C++ on Sea 2023](https://www.youtube.com/watch?v=kLNCphYSggY)
