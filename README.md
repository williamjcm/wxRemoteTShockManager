# wxRemoteTShockManager

## Description

wxRemoteTShockManager is a C++ application that allows people to administrate [TShock](https://tshock.co/xf/index.php "TShock official website") servers using the REST API.

Like TShock, this application is released under the GNU General Public License version 3 (a copy of which is available both in the app itself, and in the LICENSE file).

## Getting the application

To get a prebuilt Windows binary, see the Releases page.
If, however, you want to build binaries yourself, or are on Linux, use the `git clone` command to clone the repository.

## Building prerequisites

* If you use MSYS2 on Windows, run a MSYS shell (not MinGW), and type `pacman -S mingw-w64-<arch>-toolchain mingw-w64-<arch>-wxWidgets`, replacing `<arch>` with either `i686` or `x86_64`, depending on whether you want to build a 32-bit or 64-bit binary, respectively.
* If you build on Linux, you must install GCC and wxWidgets:
  * On Arch Linux, you need to install the `base-devel` group and the `wxgtk` package.
  * On Debian and its derivatives, install `gcc`, `g++` and `libwxgtk3.0-dev`.
* If you want to use Code::Blocks, make sure it is version 16.01 or later.

### Target notes

In the Code::Blocks project file, you can find a total of six targets:
* The four targets that start with "Win" are Windows and MSYS2-specific targets. They will generate a statically-linked binary. You can find generated binaries in `bin/<buildtype><arch>/`, where `<buildtype>` is either `Debug` or `Release`, and `<arch>` is either `32` or `64`.
* The two targets that start with "Linux" should be available on all GNU/Linux platforms. They will generate a dynamically-linked binary. You can find generated binaries in `bin/<buildtype>`, where `<buildtype>` is either `Debug` or `Release`.
  * The Makefile was created from the two Linux-based targets. Use `make debug` or `make release` to generate the corresponding binary. This Makefile should be compatible with MSYS2.

## Technical information

* Version 1.0 is designed for [TShock 4.3.23](https://github.com/NyxStudios/TShock/releases) or later.
* GUI coded using [wxWidgets](https://wxwidgets.org/), and designed with [wxFormBuilder](https://github.com/wxFormBuilder/wxFormBuilder).
