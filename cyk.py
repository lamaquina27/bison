import time
import matplotlib.pyplot as plt

gramatica = {
    'S': [('A', 'B'), ('B', 'C')],
    'A': [('B', 'A'), 'a'],
    'B': [('C', 'C'), 'b'],
    'C': [('A', 'B'), 'a']
}

comienzo = 'S'
ejemplos = ['ba', 'aa', 'aba', 'bab', 'aab',"ab"]

def cyk(gramatica, comienzo, string):
    n = len(string)
    if n == 0:
        return False
    
    table = [[set() for _ in range(n)] for _ in range(n)]

    for i, symbol in enumerate(string):
        for l, r in gramatica.items():
            if symbol in r:
                table[i][i].add(l)
    
    for length in range(2, n + 1):  # Tamaño de la subcadena
        for i in range(n - length + 1):  # Posición de inicio
            j = i + length - 1  # Posición final
            for k in range(i, j):  # División de la subcadena
                for lhs, rhs in gramatica.items():
                    for production in rhs:
                        if len(production) == 2 and production[0] in table[i][k] and production[1] in table[k+1][j]:
                            table[i][j].add(lhs)
    
    return comienzo in table[0][n-1]

# Medir tiempos de ejecución
tiempo_ejecucion = []

for ejemplo in ejemplos:
    start_time = time.perf_counter()
    resultado = cyk(gramatica, comienzo, ejemplo)
    end_time = time.perf_counter()
    tiempo_ejecucion.append((end_time - start_time)*1000)


print(tiempo_ejecucion)
# Graficar tiempos de ejecución
plt.figure(figsize=(8, 5))
plt.plot(ejemplos, tiempo_ejecucion, marker='o', linestyle='-', color='blue')
plt.xlabel('Cadenas de prueba')
plt.ylabel('Tiempo de ejecución (s)')
plt.title('Tiempo de ejecución del algoritmo CYK')
plt.show()
