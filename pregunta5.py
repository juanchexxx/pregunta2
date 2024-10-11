import multiprocessing

# Función que calcula una parte de la serie de Leibniz
def calcular_parcial(start, end):
    pi_parcial = 0.0
    signo = 1 if start % 2 == 0 else -1  # Alterna el signo según el índice

    for i in range(start, end):
        pi_parcial += signo * (4.0 / (2 * i + 1))
        signo *= -1  # Cambia de signo
    
    return pi_parcial

def calcular_pi(num_terminos):
    num_procesadores = multiprocessing.cpu_count()  # Número de CPUs disponibles
    pool = multiprocessing.Pool(processes=3)  # Usar al menos 3 procesadores
    
    # Dividir el trabajo entre los procesadores
    rango_por_proceso = num_terminos // 3
    rangos = [(i * rango_por_proceso, (i + 1) * rango_por_proceso) for i in range(3)]
    rangos[-1] = (rangos[-1][0], num_terminos)  # Ajustar el último rango para cubrir el total
    
    # Ejecutar el cálculo en paralelo
    resultados = pool.starmap(calcular_parcial, rangos)
    
    # Cerrar el pool de procesos
    pool.close()
    pool.join()
    
    # Sumar los resultados parciales de cada proceso
    pi_final = sum(resultados)
    
    return pi_final

if __name__ == "__main__":
    num_terminos = 1000000  # Número de términos a calcular
    
    # Calcular el valor de pi
    pi = calcular_pi(num_terminos)
    
    print(f"Valor de Pi calculado con multiprocessing: {pi:.15f}")
