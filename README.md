# createProject: my personalized C++ template

The *createProject* software creates a barebone boiler-plate directory for a small to medium-sized CPP project on Unix-based systems.

### Installation

The *createProject* software is installed per-user (can't be installed globally) and only works on POSIX-compatible systems, particularly Linux distros.

1. Install gcc, cmake, git, and g++: (on Debian and derivatives) `apt install gcc cmake git g++`
1. cd to your home directory: `cd ~`
2. clone this repository: `git clone https://github.com/sethvan/createProject.git`
3. cd into the cloned repo: `cd createProject`
4. run the build script: `./build`
  - (Note: Presently, the `./build` command only just creates a symlink on your PATH at `~/.local/bin/create-project`, though this will be expanded in the future.)

Additionally, if `~/.local/bin/create-project` isn't on your local user's PATH, then you will have to add this to `~/.profile`:

```sh
# Append this to the bottom of your ~/.profile script

# set PATH so it includes user's private bin if it exists
if [ -d "$HOME/.local/bin" ] ; then
    PATH="$HOME/.local/bin:$PATH"
fi
```

After adding the above text to your `~/.profile`, you will either need to close and reopen your terminal or run the command `export PATH="$HOME/.local/bin:$PATH"` to temporarily fix your session.

### Usage

Run `create-project <name of project>` in a terminal opened/cd-ed to your projects' directory:

- `create-project <name of project>`
  - Creates a directory named `<name of project>` in your current working directory.
  - Copies all the template files to this directory to set things up for you.
  - If you use VS Code and would like the project to be opened there upon creation then just un-comment out the bottom line in the `create-project` script.
    - (Note: the `create-project` script can be located by running the command `command -v create-project`)

Example resulting file structure from `cd /home/user/code/ && create-project code-as-images`:

- `/home/user/code/code-as-images`: project directory.
- `/home/user/code/code-as-images/include` directory for .h files.
- `/home/user/code/code-as-images/res` directory for resource files.
- `/home/user/code/code-as-images/build` directory for CMake-generated files.
- `/home/user/code/code-as-images/src` directory for .cpp files, containing a *Hello World* `main.cpp` file to start with.
- `/home/user/code/code-as-images/CMakeLists.txt` file set to C++17, many warning flags and an address sanitizer.
- `/home/user/code/code-as-images/run` script that is used to call CMake to compile project and then send the execution file to top of project directory where it is ran.
- `/home/user/code/code-as-images/createclass` script that is used to create basic boilerplate for class .h file, create a .cpp file and add path of .cpp file to CMakeLists.txt.


### Demonstration Video

The following video demonstrates me running the `create-project` command on my Linux Mint 20 laptop.

<div align="center">
    <video width="200" src="https://user-images.githubusercontent.com/78233173/206831297-c7798826-17fc-462f-a926-9490824f9977.mp4" />
</div>
  
### Notes

There's three important things to be aware of:

* Unless you modify the CMakeLists.txt, you will need a compiler that can handle C++17 minimum and your CMake needs to be a minimum version of 3.16 . 

* There are some further notes in the script files if you view them, I would also recommend viewing the `createclass` script before attempting to run it.  

* I may make this more extendible but there are also already many CMake boiler-plate apps currently available and most users should probably already be working on learning how to fill in and modify the CMake fields that are currently just being provided here as they are. So we will see. It was in most part
a small and very rewarding learning project for shell scripting.  



