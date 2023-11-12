# efficient-bayes

## Build

```console
$ cmake -Bbuild
$ cd bin
$ make -j
```

Requires a recent `g++` version (>= 11).

## Test

```console
$ cmake -Bbuildtest -DEB_BUILD_TEST=ON -DEB_BUILD_EXAMPLE=OFF
$ cd bin
$ make -j tests
```

Requires a recent `g++` version (>= 11).

## Dependencies

- Eigen C++ template library for linear algebra: [eigen.tuxfamily.org](https://eigen.tuxfamily.org/index.php?title=Main_Page) (MPL2 License)
- dco/c++ for algorithmic differentiation: [nag.com](https://www.nag.com/content/algorithmic-differentiation-software) (Requires Licence)
- OpenMP is used for parallelization: [openmp.org](https://www.openmp.org) (Apache 2.0 License)
- Intel MKL can be used on Intel CPUs to accelerate matrix and vector operations: [intel.com](https://www.intel.com/content/www/us/en/develop/documentation/get-started-with-mkl-for-dpcpp/top.html)
