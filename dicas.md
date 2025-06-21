- para testar os códigos

```bash
./programa < [arquivo_de_entrada] > [arquivo_de_saída]
```

ou

```bash
./programa < [arquivo_de_entrada] | diff [arquivo_de_teste] -
```

- para zipar todos os códigos juntos:

```bash
zip -r codigo.zip . -i '*.c' '*.h'
```

- para compilar todos os cógios juntos

```bash
gcc ./*.c -o a.out
```
