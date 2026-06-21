# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

A learning repository following *"Data Structures and Algorithms in C++"* and *"Intro to Python for Computer Science and Data Science"*. The actively developed part is the C++ project under `Cplusplus/`; `Python/` holds independent book exercises.

## Dependencies (one-time setup)

GoogleTest and HippoMocks are git submodules that must be installed **system-wide**:

```sh
git submodule update --init
cd googletest && mkdir -p build && cd build && cmake .. && make && sudo make install   # -> /usr/local/{include,lib}
cd hippomocks && sudo make install                                                     # -> /usr/include/HippoMocks
```

(In this environment they are already installed: gtest at `/usr/local`, hippomocks at `/usr/include/HippoMocks`.)

## Building & running

There is **no Makefile or CMake** for `Cplusplus/` — builds are plain `g++` invocations (canonically driven by `.vscode/tasks.json`). Every build recompiles the whole module source tree from scratch; there are no intermediate `.o` files or static archive. `Cplusplus/bin/` is gitignored.

The glob `Cplusplus/source/*/*.cpp` = **all module sources** (every category subdirectory: LinkedList, Stack, Recursion, …). The two files directly in `source/` are `Main.cpp` (entry point) and `ProjectConfiguration.cpp`.

Build & run the main executable:

```sh
g++ -O0 -g -Wall -Werror -fopenmp -I Cplusplus/include/ \
  Cplusplus/source/*/*.cpp Cplusplus/source/*.cpp \
  -o Cplusplus/bin/project_entry
./Cplusplus/bin/project_entry
```

Build & run a **single** unit test — each test file compiles to its own standalone executable; there is no aggregate test runner:

```sh
g++ -O0 -g -Wall -Werror -fopenmp -I Cplusplus/include/ \
  Cplusplus/source/*/*.cpp Cplusplus/source/ProjectConfiguration.cpp \
  Cplusplus/test/LinkedList/SinglyLinkedList_UnitTest.cpp \
  -lgtest -lgtest_main -lgmock -lgmock_main \
  -o Cplusplus/bin/SinglyLinkedList_UnitTest
./Cplusplus/bin/SinglyLinkedList_UnitTest        # gtest flags: --gtest_filter=…, --gtest_shuffle, --gtest_brief=1
```

A test links **module sources + `ProjectConfiguration.cpp` + the one test file** — *not* `Main.cpp`. Substitute any file under `Cplusplus/test/` to run a different suite.

In VS Code, `Run Build Task` offers **"Build by specified optimization"** (main) and **"Build active test by specified optimization"** (current test file); both prompt for the optimization level (`-O0`…`-O3`). Debug configs are in `.vscode/launch.json` (gdb).

Notes: `-Werror` makes warnings fail the build; `-fopenmp` is always on; `-std` is left at the compiler default (the code targets C++11+). `removing_build_files.sh` clears `Cplusplus/bin/`.

## Architecture & conventions

- **Single include root.** All includes are relative to `Cplusplus/include/`, e.g. `#include "LinkedList/SinglyLinkedList.h"`, `#include "ProjectConfiguration.h"`. `include/` mirrors `source/`, and components are grouped in namespaces (`LinkedList::`, …).

- **Header-only templates.** Templated data structures put their full implementation in the header — the code comments call out the classic *"undefined reference to template"* reason. The paired `source/<Category>/X.cpp` is then an empty stub (`namespace … { /** No code here */ }`) that exists only so the source glob has something to compile. Non-templated code (e.g. `ProjectConfiguration.cpp`) keeps real definitions in the `.cpp`.

- **Section-banner file layout.** Every `.h`/`.cpp` uses the same comment banners in this order — match it when creating files:
  `/* Header */`, `/* Macro */`, `/* Type */`, `/* Prototype */`, `/* Variable */`, `/* Function */`.
  Headers use `#ifndef _NAME_H` guards and Doxygen `@brief`/`@param`/`@return` comments.

- **ProjectConfiguration** (`include/ProjectConfiguration.h` + `.cpp`) holds build-time feature flags (`USE_OPENMP`, `USE_EXCEPTION`, `PRINT_STATISTICS_INTO_FILE`) and a single global `STATISTICS output_statistics` that writes a stats file when a program exits — this is why running any binary leaves the untracked `default_file` / `Output_file` artifacts. Every test links this `.cpp`.

- **Tests** use GoogleTest (HippoMocks available for mocking). Conventions: filename `…_UnitTest.cpp`, fixture `class <Component>_TestSuite : public testing::Test`, Arrange/Act/Assert comment blocks, `sut` for the system-under-test, `TEST_P` + `INSTANTIATE_TEST_SUITE_P` for parameterized cases. Some test files define their own `main()` calling `RUN_ALL_TESTS()`, others rely on `gtest_main`; both work with the link line above.

## Formatting

`.clang-format` (repo root, custom) is the C/C++ formatter — run clang-format before committing. Its style is reflected throughout: Allman braces, vertically aligned assignments and declarations.

## Python

`Python/` is independent of the C++ build. Per `Python/README.md`: `python3 -m venv .virtualEnvironment` then `pip install -r requirements.txt`. Contents are book exercises (`IntroToPython/ChapterNN/`) and Bokeh chart demos (`Python/Bokeh/`, generated `.html` is gitignored).
