# Trabalho de Verificação e Validação - Analisadores Estáticos

## Utilizando os programas

### Clang Static Analyser

Esta ferramenta é um analisador de código fonte que acha bugs em códigos C/C++. A última build disponível da ferramenta pode ser encontrada no [site oficial](https://clang-analyzer.llvm.org/). Também há uma versão em python da ferramenta desenvolvida nesse [repositório](https://github.com/rizsotto/scan-build)

##### Instalação
Para instalar a versão original:
```
sudo apt-get install clang-tools
```
Para instalar a versão em Python:

```
sudo apt-get install clang
pip install scan-build # O comando pip3 tambem pode ser utilizado
```

##### Utilização
Ambas as ferramentas apresentam a mesma forma de uso e diferem apenas em alguns argumentos que podem ser passados na chamada do programa. Para utilizá-la no gedit basta modificar o comando com o "ninja" para fazer a build:
```
ninja -C _build scan-build # build gedit and scan
```

O projeto será compilado e a análise será salva em um diretório temporário. O endereço é dado no final da execução do programa. O relatório pode ser encontrado em **_build/meson-logs/scanbuild/** em formato html.
