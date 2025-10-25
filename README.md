# Table of Content

- [Table of Content](#table-of-content)
  - [Introduction](#introduction)
  - [Dependencies](#dependencies)
    - [Required](#required)
    - [Libraries](#libraries)
    - [Development Tools (Installed in Virtual Environment)](#development-tools-installed-in-virtual-environment)
    - [Documentation](#documentation)
  - [Build, Test, Docs and Install](#build-test-docs-and-install)
    - [Quick Start](#quick-start)
    - [build.sh Options (macOS/Linux)](#buildsh-options-macoslinux)
    - [build.bat Options (Windows)](#buildbat-options-windows)
    - [Examples](#examples)
  - [Running Individual Tests](#running-individual-tests)
    - [Running Code Quality Tools](#running-code-quality-tools)
      - [clang-format](#clang-format)
      - [clang-tidy](#clang-tidy)
      - [Using pre-commit hooks](#using-pre-commit-hooks)
  - [Project Architecture](#project-architecture)
    - [Directory Structure](#directory-structure)
    - [Build System Architecture](#build-system-architecture)
    - [Code Organization](#code-organization)
      - [Solution Pattern](#solution-pattern)
      - [Data Structures](#data-structures)
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
- Use chrome and [Clip LeetCode](https://chrome.google.com/webstore/detail/clip-leetcode/cnghimckckgcmhbdokjielmhkmnagdcp/related) for easy documentation of each solution implementation

## Dependencies

### Required

- **C++20 Compiler**:
  - **macOS**: AppleClang (Xcode Command Line Tools)
  - **Linux**: GCC ≥ 10 or Clang ≥ 11
  - **Windows**: Visual Studio 2022 with C++ tools, MinGW-w64, or Clang
- **CMake** (≥ 3.25): Build system generator
- **Python** (≥ 3.8): For development tools (pre-commit, clang-format, clang-tidy)

### Libraries

- **Boost** (≥ 1.85.0): Program options library
  - Component: `program_options`
- **Google Test** (1.14.0): Unit testing framework
  - Automatically fetched via CMake FetchContent if not found
- **nlohmann/json** (master): JSON library for modern C++
  - Git submodule: `external/nlohmann/json`

### Development Tools (Installed in Virtual Environment)

All development tools are automatically installed in `.venv/` when running `./scripts/setup-dev-environment.sh`:

- **pre-commit** (4.3.0): Git hooks framework for code quality checks
- **clang-format** (21.1.2): Code formatter
- **clang-tidy** (21.1.1): Static analyzer and linter

### Documentation

- **Doxygen** (≥ 1.9.0): Documentation generator (optional)
  - Required only if generating documentation

## Build, Test, Docs and Install

The project supports cross-platform builds on macOS, Linux, and Windows.

### Quick Start

**On macOS/Linux**:

```bash
# Simple release build
./build.sh

# Clean debug build with tests
./build.sh -c -t Debug -r

# Build with 8 parallel jobs and verbose output
./build.sh -j 8 -v

# Build and open documentation
./build.sh --open-docs

# Build and install to custom location
./build.sh -i /usr/local

# Just run tests
./build.sh --tests-only
```

**On Windows**:

```cmd
REM Simple release build
build.bat

REM Clean debug build with tests
build.bat --clean -t Debug -r

REM Build with 8 parallel jobs and verbose output
build.bat -j 8 -v

REM Build and open documentation
build.bat --open-docs

REM Build and install to custom location
build.bat -i C:\local

REM Just run tests
build.bat --tests-only
```

**Before first use**, the script will automatically:

- Check for required dependencies (CMake, C++ compiler)
- Warn if Doxygen is not found
- Create a Python virtual environment (`.venv/`) (Unix systems only)
- Install pre-commit, clang-format, and clang-tidy (Unix systems only)
- Set up pre-commit hooks (Unix systems only)

### build.sh Options (macOS/Linux)

```text
OPTIONS:
    -h, --help              Show this help message
    -c, --clean             Clean build (remove build directory first)
    -t, --type TYPE         Build type: Debug, Release, RelWithDebInfo, MinSizeRel (default: Release)
    -d, --build-dir DIR     Build directory (default: ${sourceDir}/out/build/${BUILD_TYPE})
    -j, --jobs N            Number of parallel jobs (default: auto-detected CPU cores)
    -r, --run-tests         Run tests after building
    -i, --install PREFIX    Install to PREFIX directory (default: ${sourceDir}/out/install/${BUILD_TYPE})
    -v, --verbose           Verbose build output
    --no-tests              Don't build tests
    --tests-only            Build and run tests only (implies --run-tests)
    --docs                  Build documentation (requires Doxygen)
    --open-docs             Build and open documentation in browser (implies --docs)
```

### build.bat Options (Windows)

```text
OPTIONS:
    -h, --help              Show this help message
    -c, --clean             Clean build (remove build directory first)
    -t, --type TYPE         Build type: Debug, Release, RelWithDebInfo, MinSizeRel (default: Release)
    -d, --build-dir DIR     Build directory (default: out\build\<type>)
    -j, --jobs N            Number of parallel jobs (default: number of processors)
    -r, --run-tests         Run tests after building
    -i, --install PREFIX    Install to PREFIX directory (default: out\install\<type>)
    -v, --verbose           Verbose build output
    --no-tests              Don't build tests
    --tests-only            Build and run tests only (implies --run-tests)
    --docs                  Build documentation (requires Doxygen)
    --open-docs             Build and open documentation in browser (implies --docs)
```

### Examples

**macOS/Linux**:

```bash
# Development workflow - clean debug build with tests
./build.sh -c -t Debug -r

# Release build with documentation
./build.sh -t Release --open-docs

# Quick test verification
./build.sh --tests-only

# Production build and install
./build.sh -c -t Release -i /usr/local

# Parallel build with all features
./build.sh -c -t Debug -j 12 -r --docs -v
```

**Windows**:

```cmd
REM Development workflow - clean debug build with tests
build.bat --clean -t Debug -r

REM Release build with documentation
build.bat -t Release --open-docs

REM Quick test verification
build.bat --tests-only

REM Production build and install
build.bat --clean -t Release -i C:\local

REM Parallel build with all features
build.bat --clean -t Debug -j 12 -r --docs -v
```

## Running Individual Tests

After building, you can run specific tests using ctest:

**macOS/Linux**:

```sh
# Using --test-dir to specify build directory (CMake 3.20+)
% ctest --test-dir out/build/Debug -R "fib.example1" --output-on-failure

# List all available tests
% ctest --test-dir out/build/Debug -N

# Run a specific test with verbose output
% ctest --test-dir out/build/Debug -R "fib.example1" --output-on-failure -V

# Run all tests matching a pattern (e.g., all fib tests)
% ctest --test-dir out/build/Debug -R "fib\." --output-on-failure

# Run all tests
% ctest --test-dir out/build/Debug --output-on-failure

# Alternative: Navigate to build directory first
% cd out/build/Debug
% ctest -R "fib.example1" --output-on-failure
```

**Windows**:

```cmd
REM Using --test-dir to specify build directory (CMake 3.20+)
ctest --test-dir out\build\Debug -R "fib.example1" --output-on-failure -C Debug

REM List all available tests
ctest --test-dir out\build\Debug -N -C Debug

REM Run a specific test with verbose output
ctest --test-dir out\build\Debug -R "fib.example1" --output-on-failure -V -C Debug

REM Run all tests matching a pattern (e.g., all fib tests)
ctest --test-dir out\build\Debug -R "fib\." --output-on-failure -C Debug

REM Run all tests
ctest --test-dir out\build\Debug --output-on-failure -C Debug

REM Alternative: Navigate to build directory first
cd out\build\Debug
ctest -R "fib.example1" --output-on-failure -C Debug
```

You can also debug tests directly:

**macOS/Linux with lldb**:

```sh
# Debug with lldb
% lldb -- out/build/Debug/tests/solution/tests_solution "--gtest_filter=fib.example1" "--gtest_also_run_disabled_tests"
```

**Windows with Visual Studio Debugger**:

```cmd
REM Open the test executable in Visual Studio or use the debugger from VS Code
REM You can also run tests with the --gtest_filter flag:
out\build\Debug\tests\solution\Debug\tests_solution.exe --gtest_filter=fib.example1 --gtest_also_run_disabled_tests
```

### Running Code Quality Tools

**Important**: The project uses clang-format and clang-tidy from the virtual environment. Make sure to activate it first:

```sh
# Activate the virtual environment (created by build.sh)
% source .venv/bin/activate
```

#### clang-format

Format your code automatically:

```sh
# Activate virtual environment first
% source .venv/bin/activate

# Format a specific file
% clang-format -i -style=file src/solution/array/merge.cpp

# Format all C++ files in the project
% find . \( -name "*.cpp" -o -name "*.hpp" \) -not -path "./external/*" -not -path "./out/*" | xargs clang-format -i -style=file

# Check formatting without modifying files (useful for CI)
% clang-format --dry-run --Werror -style=file src/solution/array/merge.cpp

# Format all files using the task (doesn't require virtual environment)
% ./build.sh -t Debug  # Ensure build directory exists
% cmake --build out/build/x64-Darwin-Debug --target format-all
```

The `.clang-format` file in the project root defines the formatting style.

#### clang-tidy

Run static analysis on your code:

```sh
# Activate virtual environment first
% source .venv/bin/activate

# Run clang-tidy on a specific file (requires compile_commands.json)
% clang-tidy -p out/build/x64-Darwin-Debug src/solution/array/merge.cpp

# Run with automatic fixes
% clang-tidy -p out/build/x64-Darwin-Debug --fix src/solution/array/merge.cpp

# Run on all source files
% find src -name "*.cpp" | xargs clang-tidy -p out/build/x64-Darwin-Debug

# Run with specific checks
% clang-tidy -p out/build/x64-Darwin-Debug --checks='-*,modernize-*' src/solution/array/merge.cpp
```

The `.clang-tidy` file in the project root defines the analysis rules. The `-p` option points to the build directory containing `compile_commands.json`.

#### Using pre-commit hooks

The project uses pre-commit hooks to automatically run these tools:

```sh
# Activate the virtual environment (created by build.sh)
% source .venv/bin/activate

# Run pre-commit on all files
% pre-commit run --all-files

# Run pre-commit on staged files only
% pre-commit run

# Run specific hook
% pre-commit run clang-format --all-files
% pre-commit run clang-tidy --all-files
```

Pre-commit hooks are automatically installed when you run `build.sh` for the first time.

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

## To Do

- [ ] use more c++ tool, like sanitizer? [Standard C++ Toolset - Anastasia Kazakova - C++ on Sea 2023](https://www.youtube.com/watch?v=kLNCphYSggY)
