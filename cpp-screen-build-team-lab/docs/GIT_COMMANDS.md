# Git Command Reference for Build Operators

```bash
git clone <repo-url>
git status
git branch -a
git fetch origin
git switch <branch>
git switch -c <new-branch>
git pull --ff-only
git log --oneline -5
git show --stat <commit>
git diff main...HEAD
git rev-parse HEAD
git add <files>
git commit -m "type: short description"
git push -u origin <branch>
```

## Safe operating habits

- Run `git status` before changing branches or committing.
- Fetch before checking whether a remote branch is current.
- Verify the branch and SHA before every requested build.
- Do not use `git reset --hard`, force-push, or delete branches unless authorized.
- Do not commit secrets, credentials, generated build folders, or local configuration.
