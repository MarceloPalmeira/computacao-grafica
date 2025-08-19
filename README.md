# Computação Gráfica – Atividades

Este repositório contém as atividades da disciplina de **Computação Gráfica**, implementadas em **C/OpenGL** utilizando a biblioteca **FreeGLUT**.  

Cada atividade possui seu próprio diretório (`atividade_1`, `atividade_2`, `atividade_3`), contendo:
- O código-fonte (`cg.c`)
- Arquivos de configuração (`c_cpp_properties.json`)
- Executável gerado (`cg.exe`)
- Objeto de compilação (`cg.o`)
- Um `README.md` específico da atividade

## 🚀 Como rodar qualquer atividade

1. Entre no diretório da atividade desejada. Exemplo, para a **atividade 3**:

   cd atividade_3

2. Compile o código-fonte (`cg.c`) com o **GCC** e as bibliotecas do OpenGL:

   gcc cg.c -o cg.exe -lfreeglut -lopengl32 -lglu32

3. Execute o programa:

   ./cg.exe

## 📂 Estrutura do projeto

.
|-- atividade_1
| 
|   |-- c_cpp_properties.json
|   |-- cg.c
|   |-- cg.exe
|   `-- cg.o
|-- atividade_2
| 
|   |-- c_cpp_properties.json
|   |-- cg.c
|   |-- cg.exe
|   `-- cg.o
`-- atividade_3
|   |-- c_cpp_properties.json
|   |-- cg.c
|   |-- cg.exe
|   `-- cg.o
|--README.md

## 📝 Observações

- O código foi desenvolvido e testado no **Windows (MinGW + FreeGLUT)**.  
- Em sistemas **Linux**, a compilação pode exigir ajustes nos parâmetros, por exemplo:

   gcc cg.c -o cg -lGL -lGLU -lglut

- Cada atividade tem um `README.md` próprio com detalhes específicos de implementação.
