# Simple CMake template for [rayfork](https://github.com/SasLuca/rayfork) using [glfw] (https://github.com/glfw/glfw)

## Notes:
- Bear in mind that rayfork is still under development and not officially released yet, you can use this template to experiment with rayfork if you are curious until it gets officially released.

- The CMake file will also setup an `ASSETS_PATH` macro that will be an absolute path to the assets folder on your computer, if you wanna share the executable with other people then check lines 17 and 18 in the cmake file.

- The gitignore file of this template works by first ignoring all files using `*` and then allowing specific files/folders like `!file` `!folder` `!folder/**`. If you don't like this setup feel free to change the gitignore, but if you keep it be aware in case you add new folders, or files in the root of the project. 

- Feel free to delete this readme.

## Building

```
mkdir build
cd build
cmake ..
cmake --build .
```

##### This template uses: 
- [rayfork](https://github.com/SasLuca/rayfork) (the amalgamated version).
- [glad](https://github.com/Dav1dde/glad) for OpenGL loading.
- [glfw](https://github.com/glfw/glfw) for Window and Input handling
