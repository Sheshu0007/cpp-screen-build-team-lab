# Build Troubleshooting Checklist

## Identify the failing stage

1. **Checkout:** wrong branch, missing branch, authentication or repository access.
2. **Configure:** CMake syntax, missing source, missing target, dependency or package.
3. **Compile:** C++ syntax, missing header, incompatible compiler flags.
4. **Link:** undefined reference, missing library, duplicate symbol.
5. **Test:** assertion failure, test setup, runtime issue.

## Local diagnostic commands

```bash
git status
git branch --show-current
git rev-parse HEAD
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

## Reporting standard

Include the branch, commit SHA, failed stage, exact error text, and a short reproduction note. Do not guess at the root cause if the logs do not establish it.
