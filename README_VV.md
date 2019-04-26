# Trabalho de Verificação e Validação - Analisadores Estáticos

## Instalando programas:

    sudo apt-get install clang-tools # Instala o Clang Static Analyser
    sudo apt-get install cppcheck    # Instala o Cppcheck

## Utilizando os programas

### Clang Static Analyser


```
meson _build					# run the `configure' script
ninja -C _build scan-build	  # build gedit and scan
```

O projeto será compilado e a análise será salva em um diretório temporário, o endereço é dado no final da execução do programa. O log pode ser encontrado em "/_build/meson-logs/scanbuild/"
