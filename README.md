
CMake Shell Application Project Template
===========
[![Build status](https://ci.appveyor.com/api/projects/status/823njdu3qfdg7ddh/branch/main?svg=true)](https://ci.appveyor.com/project/jgonzalezdr/projecttemplateshellapp/branch/main)
[![codecov](https://codecov.io/gh/jgonzalezdr/ProjectTemplateShellApp/branch/main/graph/badge.svg)](https://codecov.io/gh/jgonzalezdr/ProjectTemplateShellApp)
## About

This repository is just a template for a shell (command line) application built using [CMake](https://cmake.org/), and using [cpputest](http://cpputest.github.io/) for unit test execution.

## Usage

1.  Download all the [files from this repository as a ZIP file](https://github.com/jgonzalezdr/projecttemplateshellapp/archive/main.zip) and unzip them to your project base directory.

> The _main_ branch is populated with some example files. You may download a [version without any examples](https://github.com/jgonzalezdr/projecttemplateshellapp/archive/unpopulated.zip) from the _unpopulated_ branch.

2. Edit the top level `CMakefile.txt` and replace _ProjectTemplate_ in the project command with your own project name (leave the .Top suffix).

3. Put the headers for your private functions and classes and the implementation files in `app/sources/`.

4. Edit `app/CMakefile.txt` and replace _ProjectTemplate_ in the project command with your own project name (this time without any suffix). This will be the base name for the executable file. You may also update your project version in the project command.

5. Edit `app/CMakefile.txt` and set the list of source and header files, and modify any other parameters that you like.

6. Add your common mocks and expectation functions to `test/Mocks`. 

7. To create unit tests, copy the `test/TestTemplate/` directory to another directory under `test/` renaming it with the test name, then:
   - Rename the test implementation file `TestModule_test.cpp` according to your test module name (It's recommended to leave the _ _test_ suffix).
   - Edit the test's `CMakefile.txt`:
       - Replace _ProjectTemplate_ and _TestModule_ in the project command with your own project name and test module name (e.g. "_YourProjectName_.Test._YourTestModuleName_").
       - Set the list of production source files to be tested, and the list of test source files (test, mocks, other test helper functions, etc.).
   - Edit the test implementation file to add your tests.

8. Edit `test/CMakefile.txt` and add all the subdirectories for your tests.

9. Delete all example files and directories from the `test/` and `app/` directories.

10. Replace `LICENSE.txt` with your project's license file.

11. Create a build directory under the top directory (e.g. `build/`), and inside it execute `cmake .. G "<GeneratorOfYourChoice>"` (add any other configuration options that you like).

## CMake Project Options

| OPTION                | Description |
| -                     | - |
| `-DCMAKE_BUILD_TYPE`  | Selects build type<br>_(only for single-config generators)_<br>`Debug`<br>`Release`_(default)_<br>`RelWithDebInfo` (Release with debug info)<br>`MinSizeRel`(Release with size optimization)<br> `Coverage`(Debug with code coverage enabled) |
| `-DENABLE_TEST`       | Enables compilation and execution of tests<br>`ON`_(default)_<br>`OFF` |
| `-DCPPUTEST_HOME`     | Path to your CppUTest installation directory<br>`<filesystem path>` |
| `-DLCOV_HOME`         | Path to your LCOV installation directory<br>`<filesystem path>` |
| `-DENABLE_INSTALLER`  | Enables generation of installer packages<br>`ON`_(default)_<br>`OFF` |
| `-DCOVERAGE`          | Enables code coverage in tests<br>_(only for multi-config generators)_<br>`ON`_(default)_<br>`OFF` |
| `-DCOVERAGE_VERBOSE`  | Enables verbose code coverage<br>`ON`<br>`OFF`_(default)_ |
| `-DCI_MODE`           | Enables Continous Integration mode<br>`ON`<br>`OFF`_(default)_ |

## Requirements

- [cmake](https://cmake.org/) (≥ v3.3, tested with v3.16.2, 3.17.2 and v3.18.4)
- [CppUTest](http://cpputest.github.io/) [Optional, not needed if tests are disabled] (≥ v4.0, tested with [v4.0-gdr0](https://github.com/jgonzalezdr/cpputest/releases/tag/v4.0-gdr0))
- On Windows:
  - A C/C++ compiler, either:
    - [MinGW-w64](https://sourceforge.net/projects/mingw-w64/) (tested with v7.3.0, v8.1.0 and [TDM-GCC v9.2.0](https://jmeubank.github.io/tdm-gcc/download/))
    - [Microsoft Visual Studio](https://www.visualstudio.com/es/downloads/) (tested with Visual Studio Community 2019)
  - [LCOV for Windows](https://github.com/jgonzalezdr/lcov/releases) [Optional, needed if tests and coverage are enabled using MinGW] (tested with [v1.15.alpha1w](https://github.com/jgonzalezdr/lcov/releases/download/v1.15.alpha1w/lcov-v1.15.alpha1w.zip))
  - [OpenCppCoverage](https://github.com/OpenCppCoverage/OpenCppCoverage) [Optional, needed if tests and coverage are enabled using Visual Studio 2019] (tested with v0.9.8.0)
- On Linux:
  - [GCC](https://gcc.gnu.org/) (tested with v7.5.0, v8.4.0 and v9.3.0)
  - [LCOV](http://ltp.sourceforge.net/coverage/lcov.php) [Optional, needed if tests and coverage are enabled using GCC] (tested with v1.14)
