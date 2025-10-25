# Code Quality Tools

This document describes the code quality tools configured for this project and how to use them.

## Overview

The project uses two primary tools for maintaining code quality:
- **clang-format**: Automatic code formatting
- **clang-tidy**: Static analysis and linting

Both tools are integrated with:
1. Pre-commit hooks (recommended for development)
2. CMake targets (for manual runs)

## Naming Conventions

This project follows a unified naming convention across all C++ code. Consistency is essential for maintainability and readability.

### File and Folder Names

**Convention**: `snake_case`

- Use lowercase letters and underscores to separate words
- Examples: `abstract_factory.hpp`, `clone_graph.cpp`, `data_structures/`, `design_pattern/`

**Good Examples:**
```
include/data_structures/tree_node.hpp
include/design_pattern/abstract_factory.hpp
include/graph/breadth_first_search.hpp
src/solution/array/find_subsequences.cpp
src/solution/dynamic_programming/climb_stairs.cpp
```

**Bad Examples (Don't use):**
```
include/data_structures/TreeNode.hpp           ✗ PascalCase for files
include/design_pattern/abstractFactory.hpp     ✗ camelCase for files
src/solution/array/FindSubsequences.cpp        ✗ PascalCase for files
```

### Class Names

**Convention**: `PascalCase`

- First letter uppercase, capitalize start of each word
- No underscores or hyphens
- Use nouns to represent objects/entities

**Good Examples:**
```cpp
class Solution { };
class TreeNode { };
class GraphNode { };
class CloneGraphVisitor { };
class MedianFinder { };
```

**Bad Examples (Don't use):**
```cpp
class solution { };              ✗ lowercase
class tree_node { };             ✗ snake_case
class TREENODE { };              ✗ all uppercase
```

### Function and Method Names

**Convention**: `camelCase`

- First letter lowercase, capitalize first letter of each subsequent word
- Use verbs to represent actions
- No underscores or hyphens

**Good Examples:**
```cpp
void addBinary(std::string a, std::string b);
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
int findKthLargest(std::vector<int>& nums, int k);
void discoverGreyTarget(Node* u, Node* v);
bool isBalanced(TreeNode* root);
```

**Bad Examples (Don't use):**
```cpp
void add_binary(std::string a, std::string b);    ✗ snake_case
void AddBinary(std::string a, std::string b);     ✗ PascalCase
void ADDBINARY(std::string a, std::string b);     ✗ all uppercase
```

### Variable Names

**Convention**: `camelCase`

- First letter lowercase, capitalize first letter of each subsequent word
- Use descriptive, meaningful names
- No trailing underscores or prefixes
- Use nouns to represent data

**Good Examples:**
```cpp
int nodeCount;
std::vector<int> neighbors;
std::unordered_map<int, int> nodeMap;
TreeNode* root;
int maximumDepth;
bool isVisited;
```

**Bad Examples (Don't use):**
```cpp
int node_count;              ✗ snake_case
int NodeCount;               ✗ PascalCase
int count_;                  ✗ trailing underscore
int _count;                  ✗ leading underscore
int c;                       ✗ non-descriptive
```

### Type Aliases and Templates

**Convention**: `PascalCase`

- Use PascalCase for typedef/using declarations
- Capitalize first letter of each word

**Good Examples:**
```cpp
using VertexType = GraphNode*;
using ColorMap = std::unordered_map<GraphNode*, Color>;
using AdjacencyList = std::vector<std::vector<int>>;
template<typename ValueType>
class Container { };
```

**Bad Examples (Don't use):**
```cpp
using vertex_type = GraphNode*;        ✗ snake_case
using vertexType = GraphNode*;         ✗ mixed case
using VERTEX_TYPE = GraphNode*;        ✗ all uppercase
```

### Constants

**Convention**: `UPPER_SNAKE_CASE`

- Use all uppercase letters with underscores
- Should be `constexpr` or `const`

**Good Examples:**
```cpp
constexpr int MAX_ARRAY_SIZE = 1000;
constexpr double PI = 3.14159;
const std::string DEFAULT_NAME = "Unknown";
```

### Enum Values

**Convention**: `UPPER_SNAKE_CASE`

- Enum values follow the same convention as constants

**Good Examples:**
```cpp
enum class Color {
    RED,
    GREEN,
    BLUE,
    UNKNOWN
};

enum Status {
    IN_PROGRESS,
    COMPLETED,
    FAILED
};
```

### Private/Protected Members

**Convention**: `camelCase` (no trailing underscores)

- Use regular camelCase without special prefixes or suffixes
- Let access specifiers (private/protected) indicate visibility
- Avoid trailing underscores like `root_` or `count_`

**Good Examples:**
```cpp
class TreeNode {
private:
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;
    std::vector<int> neighbors;

public:
    void addNeighbor(int neighbor);
};
```

**Bad Examples (Don't use):**
```cpp
class TreeNode {
private:
    int value_;              ✗ trailing underscore
    int m_value;             ✗ Hungarian notation
    int _value;              ✗ leading underscore
    TreeNode* left_child;    ✗ snake_case
};
```

### Lambda Variables

**Convention**: `camelCase`

- Same as regular variables
- Use descriptive names even for short lambdas

**Good Examples:**
```cpp
auto isEven = [](int x) { return x % 2 == 0; };
auto multiply = [factor](int x) { return x * factor; };
```

**Bad Examples (Don't use):**
```cpp
auto is_even = [](int x) { return x % 2 == 0; };   ✗ snake_case
auto f = [](int x) { return x * 2; };              ✗ non-descriptive
```

### Summary Table

| Element | Convention | Example |
|---------|-----------|---------|
| Folders | `snake_case` | `data_structures`, `design_pattern` |
| Files | `snake_case` | `tree_node.hpp`, `clone_graph.cpp` |
| Classes | `PascalCase` | `Solution`, `TreeNode`, `GraphNode` |
| Functions | `camelCase` | `addTwoNumbers()`, `findLargest()` |
| Variables | `camelCase` | `nodeCount`, `neighbors` |
| Type Aliases | `PascalCase` | `VertexType`, `ColorMap` |
| Constants | `UPPER_SNAKE_CASE` | `MAX_SIZE`, `DEFAULT_VALUE` |
| Enums | `UPPER_SNAKE_CASE` | `RED`, `IN_PROGRESS` |
| Private Members | `camelCase` | `nodeValue`, `leftChild` |

## CMake Naming Conventions

To maintain consistency with C++ naming standards, CMake files follow specific conventions for variables, filenames, functions, and targets.

### CMake Variable Names

**Convention**: `camelCase`

- First letter lowercase, capitalize first letter of each subsequent word
- Use descriptive names for file collections and configuration variables

**Good Examples:**

```cmake
set(gccLikeCxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvcCxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
set(srcSolutionCpps ...)
set(testsSolutionCpps ...)
set(gtestForceSharedCrt ON)
```

**Bad Examples (Don't use):**

```cmake
set(gcc_like_cxx ...)        # snake_case
set(GccLikeCxx ...)          # PascalCase
set(src_solution_cpps ...)   # snake_case
```

### CMake Filenames

**Convention**: `snake_case`

- Use lowercase letters and underscores to separate words
- Apply the same convention as C++ source files

**Good Examples:**
- `cmake/find_dependency.cmake`
- `cmake/require_out_of_source_builds.cmake`

**Bad Examples (Don't use):**
- `cmake/FindDependency.cmake` ✗ PascalCase
- `cmake/find-dependency.cmake` ✗ hyphens

### CMake Function Names

**Convention**: `camelCase`

- First letter lowercase, capitalize first letter of each subsequent word
- Use verbs to represent actions
- Follow the same convention as C++ function names

**Good Examples:**

```cmake
function(requireOutOfSourceBuild)
    # ...
endfunction()

function(findAndLinkDependencies)
    # ...
endfunction()
```

**Bad Examples (Don't use):**

```cmake
function(require_out_of_source_build)   # snake_case
function(RequireOutOfSourceBuild)       # PascalCase
function(REQUIRE_OUT_OF_SOURCE_BUILD)   # all uppercase
```

### CMake Target Names

**Convention**: `snake_case`

- Use lowercase letters and underscores to separate words
- Target names should be descriptive and indicate their purpose

**Good Examples:**

```cmake
add_library(src_solution ...)
add_executable(tests_solution ...)
add_library(src_design_pattern ...)
add_executable(tests_design_pattern ...)
add_executable(bin_solution ...)
```

**Bad Examples (Don't use):**

```cmake
add_library(SrcSolution ...)            # PascalCase
add_library(src-solution ...)           # hyphens
add_executable(TestsSolution ...)       # PascalCase
```

### CMake Summary Table

| Element | Convention | Example |
|---------|-----------|---------|
| Variables | `camelCase` | `gccLikeCxx`, `srcSolutionCpps` |
| Filenames | `snake_case` | `find_dependency.cmake` |
| Functions | `camelCase` | `requireOutOfSourceBuild()` |
| Targets | `snake_case` | `src_solution`, `tests_solution` |

### Examples from Project

**CMakeLists.txt References:**

```cmake
# Including cmake modules with snake_case filenames
include(require_out_of_source_builds)
include(find_dependency)

# Calling camelCase functions
requireOutOfSourceBuild()

# File collections with camelCase variables
file(GLOB_RECURSE srcSolutionCpps ...)
file(GLOB testsSolutionCpps ...)

# Creating snake_case targets
add_library(src_solution ${srcSolutionCpps})
add_executable(tests_solution ${testsSolutionCpps})
```

**cmake/find_dependency.cmake (snake_case filename):**

```cmake
# camelCase variables
set(gtestForceSharedCrt ON CACHE BOOL "" FORCE)
```

**cmake/require_out_of_source_builds.cmake (snake_case filename):**

```cmake
# camelCase function name
function(requireOutOfSourceBuild)
    file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" locPath)
    # ...
endfunction()
```

## Configuration Files

### .clang-format
Located at the project root, this file configures automatic code formatting based on Google C++ Style Guide with customizations:
- **Base Style**: Google
- **Indent Width**: 4 spaces
- **Column Limit**: 120 characters
- **Standard**: C++20
- **Pointer Alignment**: Left (`int* ptr` not `int *ptr`)

### .clang-tidy
Located at the project root, this file configures static analysis checks:
- **Enabled Check Categories**:
  - `bugprone-*`: Bug-prone code patterns
  - `concurrency-*`: Concurrency issues
  - `cppcoreguidelines-*`: C++ Core Guidelines
  - `modernize-*`: Modern C++ features
  - `performance-*`: Performance improvements
  - `portability-*`: Portability issues
  - `misc-*`: Miscellaneous checks

- **Disabled Checks** (for LeetCode context):
  - Magic numbers (common in examples)
  - Identifier naming (flexible for problem-solving)
  - Named parameters (not always needed)
  - Internal linkage suggestions (test macros)

## Using Pre-commit Hooks (Recommended)

Pre-commit hooks automatically check your code before each commit.

### Installation
```bash
# Install pre-commit (if not already installed)
pip install pre-commit

# Install the git hooks
pre-commit install
```

### Usage
Pre-commit runs automatically on `git commit`. To run manually:

```bash
# Run on all files
pre-commit run --all-files

# Run only clang-format
pre-commit run clang-format --all-files

# Run only clang-tidy
pre-commit run clang-tidy --all-files
```

### What Gets Checked
1. **Trailing whitespace removal**
2. **End-of-file fixer**
3. **YAML syntax validation**
4. **Large file detection**
5. **clang-format** (auto-formats C/C++ files)
6. **clang-tidy** (static analysis, excludes lib/ and design_pattern/)

## Using CMake Targets

CMake targets allow running the tools independently of git.

### Build the Project First
```bash
# Generate build files and compile
cmake --workflow --preset x64-Darwin-Debug
```

This creates `compile_commands.json` needed for clang-tidy.

### Run clang-format
```bash
# Format all source files in-place
make -C out/build/x64-Darwin-Debug clang-format
```

### Run clang-tidy
```bash
# Run static analysis on all source files
make -C out/build/x64-Darwin-Debug clang-tidy
```

**Note**: The clang-tidy CMake target is stricter than pre-commit and may report warnings in test files. This is expected and doesn't block commits.

## Compilation Database

clang-tidy requires `compile_commands.json` to understand include paths and compiler flags.

- **Generated by**: CMake with `CMAKE_EXPORT_COMPILE_COMMANDS=ON`
- **Location**: `out/build/x64-Darwin-Debug/compile_commands.json`
- **Symlink**: Project root has a symlink for convenience
- **Git**: Symlink is ignored via `.gitignore`

To regenerate:
```bash
cmake --workflow --preset x64-Darwin-Debug
```

## Workflow Recommendations

### Daily Development
1. Install pre-commit hooks once: `pre-commit install`
2. Write code normally
3. Commit as usual - hooks run automatically
4. If formatting issues are found, they're auto-fixed
5. If linting issues are found, review and fix them

### Manual Code Cleanup
```bash
# Format all code
make -C out/build/x64-Darwin-Debug clang-format

# Or use pre-commit
pre-commit run clang-format --all-files
```

### Before Pull Requests
```bash
# Run all checks
pre-commit run --all-files

# Build and test
cmake --workflow --preset x64-Darwin-Debug
```

## Customizing Checks

### Disabling Specific Warnings

Add comments in code:
```cpp
// NOLINT - disable all checks for this line
int x = 42;  // NOLINT

// NOLINTNEXTLINE - disable all checks for next line
// NOLINTNEXTLINE
int y = 42;

// Disable specific check
int z = 42;  // NOLINT(readability-magic-numbers)
```

### Updating .clang-tidy

Edit `.clang-tidy` to add/remove checks:
```yaml
Checks: >
  -*,
  bugprone-*,
  -bugprone-easily-swappable-parameters,  # Disable this check
  performance-*,
  my-new-check-*  # Enable new check category
```

## Troubleshooting

### Pre-commit fails with "compile_commands.json not found"
```bash
# Rebuild project to regenerate
cmake --workflow --preset x64-Darwin-Debug
```

### clang-format/clang-tidy not found
```bash
# macOS with Homebrew
brew install llvm
# Add to PATH if needed
export PATH="/opt/homebrew/opt/llvm/bin:$PATH"
```

### Pre-commit hooks not running
```bash
# Reinstall hooks
pre-commit install
```

### Too many clang-tidy warnings
This is normal - clang-tidy is comprehensive. Pre-commit configuration excludes test files and external libraries to reduce noise.

## Files Modified

- `.clang-format` - Formatting rules
- `.clang-tidy` - Linting rules
- `.pre-commit-config.yaml` - Pre-commit hook configuration
- `cmake/ClangCxxDevTools.cmake` - CMake targets for tools
- `.gitignore` - Ignore compile_commands.json symlink
- `CMakePresets.json` - Enable CMAKE_EXPORT_COMPILE_COMMANDS
- `compile_commands.json` - Symlink to build directory (created automatically)

## References

- [clang-format documentation](https://clang.llvm.org/docs/ClangFormat.html)
- [clang-tidy documentation](https://clang.llvm.org/extra/clang-tidy/)
- [pre-commit framework](https://pre-commit.com/)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
