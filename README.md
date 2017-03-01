# DisplayIPCam
This code is used to display OnCam IP Cam stream.

## Usage

The syntax for running the program is `./display ip type`.   
example usage `./display 192.168.1.50 vivotek`  
Current code by default gets both oncam and vivotek mjpeg, but their main stream is H.264. See user manual for more.

## Pre-requisite
You will need OpenCV 3 (not version 2.4.11 or anything previous). It can be downloaded from the
[OpenCV download page](http://opencv.org/downloads.html).   
Once installed, build from the terminal:

```sh
$ mkdir build        # Create a build directory
$ cd build
$ cmake ..           # Use CMake to generate the Makefile
$ make -j20           # Compiles four files in parallel, best for quad-core computers
```



## Issue
