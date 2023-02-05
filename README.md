## Dependencies

```shell
brew install llvm
```

## Build

```shell
cmake -S . -B build
cmake --build build
```

## Format + lint

```
/usr/local/opt/llvm@15/bin/clang-format
/usr/local/opt/llvm@15/bin/clang-tidy src/*.cpp -extra-arg=-std=c++20 --
```


## See also

- https://github.com/bigfatwhale/orderbook/tree/master/cpp