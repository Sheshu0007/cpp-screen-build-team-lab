# Team Git and Pull Request Exercise

## 1. Create the shared repository

One teammate:
1. Create an empty GitHub repository named `cpp-screen-build-team-lab`.
2. Extract this ZIP.
3. In the extracted project folder, run:

```bash
git init
git add .
git commit -m "chore: add C++ screen build training project"
git branch -M main
git remote add origin https://github.com/USERNAME/cpp-screen-build-team-lab.git
git push -u origin main
```

Replace `USERNAME` with the repository owner's GitHub username.

## 2. Every other teammate clones

```bash
git clone https://github.com/USERNAME/cpp-screen-build-team-lab.git
cd cpp-screen-build-team-lab
git switch -c feature/your-name-add-screen
```

Each person should use a unique branch name.

## 3. Assign team exercises

- Teammate A: add a `HelpScreen` class (`include/screens/help_screen.h` and `src/screens/help_screen.cpp`).
- Teammate B: add a test that verifies the help screen name and output.
- Teammate C: update `main.cpp` to register and display the help screen.
- Build operator: fetch each branch, verify its commit, run configure/build/tests, and report the result.

Avoid having multiple people edit the same file in the first exercise. Later, deliberately practice a merge conflict.

## 4. Commit and push your branch

```bash
git status
git add include src tests
git commit -m "feat: add help screen"
git push -u origin feature/your-name-add-screen
```

## 5. Open a Pull Request

On GitHub:
1. Open the repository.
2. Select **Compare & pull request** for your pushed branch.
3. Set base to `main` and compare to your feature branch.
4. Add a clear summary and test evidence.
5. Request another teammate as reviewer.
6. Wait for CI to finish.
7. Reviewer checks the code and leaves comments or approves.
8. Author makes requested changes and pushes another commit.
9. Once approved and CI passes, merge the PR using the team's agreed merge strategy.

## 6. Build operator: reproduce a teammate's branch locally

```bash
git fetch origin
git switch --track origin/feature/teammate-branch
git rev-parse HEAD
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

If the local branch already exists, use `git switch feature/teammate-branch` and then `git pull --ff-only`.

Record:
- Repository
- Branch
- Commit SHA
- Configure result
- Build result
- Test result
- First meaningful error, if any

Do not edit the developer's code on their behalf unless that is explicitly part of your assigned role.

## 7. Practice a controlled failure

On a temporary feature branch only:
1. Rename a source file in `CMakeLists.txt` to a deliberately incorrect filename.
2. Commit and push the change.
3. Open a PR and observe the CI failure.
4. Read the configure/build log and identify the missing source file.
5. Ask the author to fix it in their branch.
6. Confirm the new commit is pushed.
7. Rerun the workflow and verify it passes.

Then revert the deliberate error. Never introduce this failure on `main`.

## 8. Practice a merge conflict

Two teammates:
1. Create separate branches from the same `main`.
2. Both change the same line in `src/screens/home_screen.cpp`.
3. Push both branches and open PRs.
4. Merge one PR first.
5. Update the other branch from `main` and resolve the conflict:

```bash
git fetch origin
git switch feature/second-change
git merge origin/main
# Edit the conflicted file and remove conflict markers.
git add src/screens/home_screen.cpp
git commit -m "fix: resolve merge conflict"
git push
```

Run the build and tests again before merging.

## 9. Suggested build report

```text
Repository:
Branch:
Commit SHA:
Configure: PASS / FAIL
Build: PASS / FAIL
Tests: PASS / FAIL
Failure stage:
Error summary:
Developer notified:
Rerun result:
```
