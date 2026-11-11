# Team Exercises

Complete in order and use a separate branch for each exercise.

1. **Branch basics:** create a branch, make a documentation change, push it and open a PR.
2. **New screen:** add `HelpScreen` following the existing screen pattern.
3. **CMake registration:** add a new `.cpp` file to the correct target.
4. **Test update:** add a test for the new screen.
5. **Build operator drill:** check out another teammate's branch and run configure, build and tests.
6. **Intentional configure failure:** temporarily reference a nonexistent `.cpp` file in CMake, push to a test branch, inspect CI failure, then fix.
7. **Intentional compile failure:** temporarily introduce a syntax error on a test branch, inspect the compiler output, then fix.
8. **Merge conflict:** edit the same line on two branches and resolve the conflict.
9. **Review practice:** leave one constructive PR comment and respond to a review request.
10. **Release drill:** merge an approved PR, fetch `main`, build the merged commit, and complete a build report.

Never perform intentional failure exercises on `main` or a shared production repository.
