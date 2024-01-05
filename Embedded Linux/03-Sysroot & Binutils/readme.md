## Sysroot

A sysroot is a directory which is considered to be the root directory for the purpose of locating headers and libraries.  Besides our own code files, compilers may use many other files to generate  output. In this case, C and C++ compilers search for headers and libraries.

By default, the compiler searches for those files in standard locations (ex: */usr/include/* and */usr/lib/*). However, we may want to use alternative directories. For instance, when cross-compiling binaries targeted at other platforms or when preparing experimental builds using non-standard headers and/or libraries. In cross-compilation, a sysroot is a scaled down version of your target’s filesystem, it works as a root for the libraries and headers which we will compile/link against. 

## Binutil *(Binary Utilities)* 

 A collection of various binary tools, such as the linker, assembler, and other software tools that allow us to inspect and manipulate object files and binaries. 	