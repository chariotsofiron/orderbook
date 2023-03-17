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

```shell
# format
fd '\.(cpp|hpp)$' src/ | xargs clang-format -i

# lint
clang-tidy src/main.cpp -extra-arg=-std=c++20 -p build --
```

## Usage

```
curl -H "Content-Type: application/json" -d '{"price": 3, "side": "Sell", "amount": 5, "symbol": "AAPL"}' localhost:3000/order | jq
{
    "id": "ef1c4f22-ff16-4b40-9c92-881b1f1db8ca",
    "amount": 5,
    "symbol": "AAPL",
    "price": 3,
    "side": "Sell"
}
```


## See also

- https://github.com/bigfatwhale/orderbook/tree/master/cpp
- https://sanket.tech/posts/rustbook/