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

## Build

The following commands create `build` directory under the current working directory, run cmake under the `build` directory

```sh
rm -rf build
cmake . -B build && make -C build
```

To run Google-Tests

```sh
./build/tests/test_solution
```

To run executable:

```sh
./build/bin/solution --help
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

```sh
🍺  /opt/homebrew/Cellar/include-what-you-use/0.21: 32 files, 8.3MB
==> Running `brew cleanup include-what-you-use`...
==> Caveats
==> llvm
To use the bundled libc++ please add the following LDFLAGS:
  LDFLAGS="-L/opt/homebrew/opt/llvm/lib/c++ -Wl,-rpath,/opt/homebrew/opt/llvm/lib/c++"

llvm is keg-only, which means it was not symlinked into /opt/homebrew,
because macOS already provides this software and installing another version in
parallel can cause all kinds of trouble.

If you need to have llvm first in your PATH, run:
  echo 'export PATH="/opt/homebrew/opt/llvm/bin:$PATH"' >> ~/.zshrc

For compilers to find llvm you may need to set:
  export LDFLAGS="-L/opt/homebrew/opt/llvm/lib"
  export CPPFLAGS="-I/opt/homebrew/opt/llvm/include"
```
