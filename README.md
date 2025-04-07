# 📐 Bison Calculator Project

Este proyecto implementa un **calculador avanzado** utilizando **Flex** y **Bison**, basado en los ejercicios del **Capítulo 3** del libro _Flex & Bison_ de John Levine.

## 📚 Descripción

El objetivo es construir un intérprete para expresiones matemáticas que incluye soporte para:

- Operaciones aritméticas básicas.
- Uso de variables y su asignación.
- Definición de funciones personalizadas.
- Funciones matemáticas integradas (`sqrt`, `exp`, `log`, etc.).
- Estructuras de control (`if`, `while`).
- Evaluación usando Árboles de Sintaxis Abstracta (AST).
- Manejo básico de errores sintácticos.

Se utilizan herramientas clásicas para la construcción de compiladores:

- **Flex** para el análisis léxico.
- **Bison** para el análisis sintáctico.


## ⚙️ Requisitos

- [Flex](https://github.com/westes/flex)
- [Bison](https://www.gnu.org/software/bison/)
- GCC o compilador C equivalente
- Sistema tipo Unix (Linux, macOS o WSL en Windows)


## 🛠️ Compilación

Desde el directorio correspondiente (`BISONPRUEBA/` o `BISONPRUEBAMEJORADA/`), ejecutar:

```bash
bison -d fb3-2.y          # o fb3-3.y
flex fb3-2.l              # o fb3-3.l
gcc -o calc2 fb3-2.tab.c fb3-2funcs.c fb3-2.lex.c -lm -lfl
```

> 🔧 Usa `calc3` y `fb3-3.*` si estás trabajando con la versión mejorada.


## ▶️ Ejecución

Una vez compilado, ejecuta:

```bash
./calc2    # o ./calc3
```

Puedes escribir expresiones directamente:

```txt
let x = 5;
let y = 10;
print sqrt(x * x + y * y);
```


## ✨ Funcionalidades

- ✅ Soporte para números enteros.
- ✅ Aritmética básica: `+`, `-`, `*`, `/`, `| |` (valor absoluto).
- ✅ Variables (`let x = 10;`)
- ✅ Funciones matemáticas (`sqrt`, `log`, `exp`)
- ✅ Funciones definidas por el usuario (`let cuadrado(a) = a * a;`)
- ✅ Instrucciones de control (`if`, `while`)
- ✅ Árboles de sintaxis abstracta (AST)
- ✅ Mecanismo básico de manejo de errores



## 📁 Estructura del proyecto

```bash
bison-main/
├── BISONPRUEBA/
│   ├── fb3-2.y          # Archivo de gramática Bison
│   ├── fb3-2.l          # Reglas léxicas en Flex
│   ├── fb3-2funcs.c     # Funciones para construcción y evaluación del AST
│   ├── fb3-2.h          # Declaraciones y estructuras compartidas
│   ├── Archivos generados (.tab.c, .lex.c, .tab.h)
│   └── calc2            # Binario compilado (opcional)
├── BISONPRUEBAMEJORADA/
│   ├── fb3-3.y          # Versión mejorada de la gramática
│   ├── fb3-3.l          # Reglas léxicas mejoradas
│   ├── fb3-3funcs.c     # Funciones AST extendidas
│   ├── fb3-3.h          # Encabezado extendido
│   ├── Archivos generados (.tab.c, .lex.c, .tab.h)
│   └── calc3            # Binario compilado (opcional)
```


## 📘 Referencia

Este proyecto se basa en el capítulo 3 del libro:

**_Flex & Bison_**  
Autor: John Levine  
Editorial: O'Reilly Media  
ISBN: 978-0-596-15597-1


## 👨‍💻 Autores

Este proyecto fue desarrollado por:

- **Juan David Sánchez**
- **Santiago Camacho**
- **Kevin Soler**


## 📜 Licencia

Uso estrictamente educativo. Basado en material público del libro _Flex & Bison_.
```