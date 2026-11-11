# C++ Screen Build Team Lab

A deliberately multi-module C++/CMake project for practicing Git collaboration, pull requests, code review, CI builds, and build-failure troubleshooting.

This is a **training project**, not production software. It uses a small terminal-based screen flow to represent screen modules. It does not assume any proprietary "screen" file format.

## Requirements

- Git
- CMake 3.20+
- A C++17 compiler (GCC, Clang, or MSVC)
- Optional: GitHub account for team collaboration and pull requests

Check your tools:

```bash
git --version
cmake --version
g++ --version       # Linux/WSL; on Windows use your configured compiler
```

## Build locally

Run from the repository root:

```bash
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

Run the app:

```bash
./build/screen_demo
```

On Windows, the executable is usually `build/Debug/screen_demo.exe` or `build/screen_demo.exe`, depending on the generator.

## Project map

```text
cpp-screen-build-team-lab/
├── CMakeLists.txt
├── CMakePresets.json
├── include/
│   └── common/
├── src/
│   ├── app/
│   ├── screens/
│   └── services/
├── tests/
├── docs/
└── .github/
    ├── workflows/
    ├── PULL_REQUEST_TEMPLATE.md
    └── ISSUE_TEMPLATE/
```

## Team exercise

Use a shared GitHub repository. One person creates the repository and pushes `main`; teammates clone it and work on separate branches. Never have everyone commit directly to `main`.

Suggested roles:
- **Repository owner:** creates the remote repository, protects `main`, reviews PRs.
- **Developer A:** adds or changes a screen module.
- **Developer B:** adds a service or test.
- **Build operator:** checks out the requested branch, builds it, inspects logs, and reports the result.
- Rotate roles so everyone practices each activity.

See [`docs/TEAM_WORKFLOW.md`](docs/TEAM_WORKFLOW.md) for the complete exercise.

## Important

- Do not commit the `build/` directory.
- Do not force-push shared branches.
- Before building a branch, verify the repository, branch, and commit SHA.
- Report the first meaningful error and the failing pipeline stage; avoid sending only "build failed".
mm