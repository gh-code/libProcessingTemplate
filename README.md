# libProcessingTemplate

[Processing](https://processing.org "Processing") is a flexible software sketchbook and a language for learning how to code within the context of the visual arts.
[libProcessing](https://github.com/gh-code/libProcessing "libProcessing") is a C++ library for Processing and this is an example.

![Demonstration](https://raw.githubusercontent.com/gh-code/libProcessingTemplate/master/images/capture.gif)

## Requirement
* Qt 5

## Usage
Get the source code:
```sh
$ git clone --recurse-submodules -j8 https://github.com/gh-code/libProcessingTemplate.git
```

Compile:
```sh
$ cd libProcessingTemplate/
$ qmake
$ make
```

Run:
```sh
$ LD_LIBRARY_PATH=/path/to/libProcessingTemplate/thirdparty/libProcessing/lib
$ export LD_LIBRARY_PATH
$ ./main
```

## License
MIT License
