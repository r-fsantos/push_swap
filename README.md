# push_swap
Because Swap_push isn’t as natural

Hack 1

```bash
seq 3 | shuf
# 2
# 1
# 3

seq 5 | shuf | paste -s -d ' ' # 4 1 2 5 3

ARG=$(seq 100 | shuf | paste -s -d ' '); ./push_swap $ARG
ARG=$(seq -42 42 | shuf); ./push_swap $ARG
```

Hack 2

```bash
export ARGS="$(shuf -i 1-5 | xargs)" && valgrind ./push_swap $ARGS | wc -l && ./push_swap $ARGS | ./checker_linux $ARGS
```
