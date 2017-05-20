## OpenFF8

An open-source re-implementation of Final Fantasy VIII

## Usage

The solution comes with 2 projects built using Visual Studio 2015.
The implementation only currently supports the Steam english version and the original 2000 version (this is selected by setting the VERSION to 1 and is relatively untested).
> Injector - this project is used to inject and remove the OpenFF8 dll from Final Fantasy 8, this should be kept running in the background if you intend to work on the dll
> OpenFF8 - this project is the core dll file, it can be used to replace existing functions in Final Fantasy VIII and aid in reverse engineering and debugging.

Access to memory in Final Fantasy VIII is by using the structs ff8vars and ff8funcs defined in memory.h, you can use these to directly access memory used by the game.
