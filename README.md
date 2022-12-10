# createProject
#### Creates a barebone boiler-plate directory for a small to medium-sized CPP project on Unix-based systems.  
<div align="center">
    <video width="200" src="https://user-images.githubusercontent.com/78233173/206831297-c7798826-17fc-462f-a926-9490824f9977.mp4">
</div>.  
  
##### To install, cd into your `~` directory and clone repository:
```
cd ~ && git clone https://github.com/sethvan/createProject.git
```
##### Then cd into `createProject` and run `build` script ( this just adds symlink of the command to your PATH ):
```
cd createProject && ./build
```

##### The `create-project` command is now ready to run on your system as follows:  
```
create-project <name of project>
```
##### A project directory will be created inside the working directory where command is ran and will come with:
- Empty sub-directories `include` ( for .h files ), `res` ( for resources ) and `build` ( for CMake-generated code ).
- `src` directory ( for .cpp files ) containing a "hello world" `main.cpp` file to start with.
- `CMakeLists.txt` file set to C++17, many warning flags and an address sanitizer.
- `run` script that is used to call CMake to compile project and then send the execution file to top of project directory where it is ran.
- `createclass` that is used to create basic boilerplate for class .h file, create a .cpp file and add path of .cpp file to CMakeLists.txt.

Unless you modify the CMakeLists.txt, you will need a compiler that can handle C++17 minimum and your CMake needs to be a minimum version of 3.16 . 

There are some further notes in the script files if you view them, I would also recommend viewing the `createclass` script before attempting to run it.  

If you use VS Code and would like the project to be opened there upon creation then just un-comment out the bottom line in the `create-project` script.  

I may make this more extendible but there are also already many CMake boiler-plate apps currently available and most users should probably already be working on learning how to fill in and modify the CMake fields that are currently just being provided here as they are. So we will see. It was in most part
a small and very rewarding learning project for shell scripting.  



