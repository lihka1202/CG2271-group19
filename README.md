# Introduction
Use this to store labs and project related work. Could be reusable

# Setup
I think using [lazygit](https://github.com/jesseduffield/lazygit?tab) is a good idea, good gui, helps with amends and rebasing if any since we dont have vscode anymore

## scoop
`scoop` is a cli mananger for windows. Use these comamnds to install them in powershell.

```bash
# Set control policies
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser

# Use this first
irm get.scoop.sh | iex

# You can use proxies if you have network trouble in accessing GitHub, e.g.
irm get.scoop.sh -Proxy 'http://<ip:port>' | iex
```
Check if it installed correctly by using `scoop help`

## lazygit
`lazygit` is a CLI based GUI service for git with some enhancements. This works best with `powershell` over `git bash`. Install using `scoop` in the following way:
```bash
# Add the extras bucket
scoop bucket add extras

# Install lazygit
scoop install lazygit
```
Verify functional by using `lazygit` in a git repo, the GUI should turn up with a welcome message.

If you're planning on using `git bash` use the following command to activate lazygit instead:
```bash
winpty lazygit
```
