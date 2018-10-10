# ENPM 808X Midterm Project - RRT Path Planning
[![Build Status](https://travis-ci.org/bsaisudh/CPP-RRT.svg?branch=master)](https://travis-ci.org/bsaisudh/CPP-RRT)
[![Coverage Status](https://coveralls.io/repos/github/bsaisudh/CPP-RRT/badge.svg?branch=master)](https://coveralls.io/github/bsaisudh/CPP-RRT?branch=master)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://raw.githubusercontent.com/bsaisudh/CPP-RRT/master/LICENSE)

---
## Overview

Path planning for a point robot using Rapidly Exploring Random Trees (RRT) on a known 2D space. The algorithm
returns coordinate points in the path, which when interfaced with a simple position control system can be used to
drive a robot in the planned path.

RRTs are kinodynamic planners that can be used to calculate the trajectory of a robot in real time. Given that the
algorithm uses incremental motions, it can be used in Collision detection. The RRT algorithm can be used to
produce good guesses for variational optimization techniques.

## UML Diagrams
### Class Diagrams
![alt text](https://raw.githubusercontent.com/bsaisudh/CPP-RRT/master/UML/Initial/classDescriptions.png)

### Activity Diagrams
![alt text](https://raw.githubusercontent.com/bsaisudh/CPP-RRT/master/UML/Initial/Activity%20Diagram%20Compute%20Path.png)
![alt text](https://raw.githubusercontent.com/bsaisudh/CPP-RRT/master/UML/Initial/activityDiagram_RRT.png)

## Dependencies
Cmake
Google Test
GNU Plot

## Agile Development Process
Pair programming is an agile software development technique in which two programmers work together at one workstation. One, the driver, writes code while the other, the observer or navigator, reviews each line of code as it is typed in. The two programmers switch roles frequently.. You can view the product backlog and development process in this [SPREADSHEET](https://docs.google.com/spreadsheets/d/1cJVLNv9pZ2T4a17OsMPn_WnxRS6tAkfYJKaMcSRo6MA/edit#gid=904828225)

## Standard install via command-line
```
git clone --recursive https://github.com/bsaisudh/CPP-RRT.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/bsaisudh/CPP-RRT.git
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of CPP-RRT

```
cd ~/workspace
mkdir -p RRT-eclipse
cd RRT-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../CPP-RRT/
```

## Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

# Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


## Build

To build the project, in Eclipse, unfold RRT-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

## Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)
