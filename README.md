DISCONTINUATION OF PROJECT.

This project will no longer be maintained by Intel.

Intel has ceased development and contributions including, but not limited to, maintenance, bug fixes, new releases, or updates, to this project. 

Intel no longer accepts patches to this project.

If you have an ongoing need to use this project, are interested in independently developing it, or would like to maintain patches for the open source software community, please create your own fork of this project. 
# GNU Multiple Precision Arithmetic Trusted Library for Intel&reg; Software Guard Extensions

This is the README for the Intel SGX port of libgmp\*. For the original README for the GMP Library, see [README_GMP](README_GMP).

For more information about this project, see the accompanying article "[Building the GNU\* Multiple Precision\* Arithmetic Library for Intel® Software Guard Extensions](https://software.intel.com/en-us/articles/building-the-gnu-multiple-precision-library-for-intel-software-guard-extensions)".

## Introduction

This project is a proof-of-concept modification of the GNU\* Multiple Precision Arithmetic Library as an Intel SGX trusted library. It is intended to serve as an example of how a relatively complex library can be adapted to work as a trusted library for Intel SGX enclaves. This project focuses on the first steps when doing such a port:

 1. Integrating Intel SGX into the target library's build system.

 1. Making a first-pass at the library to address code segments that are not compatible with the Intel SGX trusted C library.

This project produces a functional, trusted GMP library that can be used in an Intel SGX enclave, but comes with the following caveats:

  * The library's full functionality has not been tested.

  * No effort has been made to tune the performance of the library for Intel SGX enclaves.

  * GMP's I/O routines have been excluded (specifically, code modules that read stdin or write to stdout).

  * The build checks and speed test applications are not available when building as a trusted library as this would require writing enclave-aware versions of the utilities.

This is based on GMP 6.1.2 which was the latest version available as of October 4th, 2018.

## Requirements

This project was built and tested with the following configuration:

 * Ubuntu\* Linux\* 16.04, 18.04
 * CentOS\* Linux 7.4
 * [Intel SGX SDK v2.5](https://github.com/intel/linux-sgx)

Other Intel SGX capable operating systems may work, but have not been tested.

## Building

You can build both the stock (complete) GMP library and its associated utilities, or the Intel SGX trusted library from the same build system. It's recommended that you build GMP _without_ SGX support first to ensure you have all the prerequisites: GMP requires the _bison_ and _texinfo_ packages, which are not normally installed by default.

To configure the Intel SGX trusted library, use the following arguments to configure:

<pre>
    configure --enable-sgx --enable-static --disable-shared --enable-assembly --prefix=<i>install_dir</i>
</pre>

A sample wrapper around `configure` has been provided in `sgx-configure`.

You will need to have the Intel SGX SDK in your PATH, or in a location that the configuration script will be able to detect (e.g., `/opt/intel/sgxsdk`).

To build, run `make`:

```
    $ make
```

The trusted library will be named `libsgx_tgmp.a`.

`make install` works for both the trusted and stock GMP library builds, and you can install both libraries to the same location.

### Sample build configuration

See the `sgx-configure` script for an example set of build options. This build is set to install GMP in <code>/opt/libgmp/<i>version</i></code>, enable assembly code loops, and enable Intel SGX.

## License

See [README_GMP](README_GMP) for details.
