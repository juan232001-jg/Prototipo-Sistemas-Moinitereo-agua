import csv

def analizar_datos(archivo_csv):
    niveles = []
    
    with open(archivo_csv, 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            niveles.append(float(row['nivel']))
    
    promedio = sum(niveles) / len(niveles)
    print(f"Nivel promedio: {promedio:.2f} cm")

if __name__ == "__main__":
    analizar_datos('../datos/ejemplo_lecturas.csv')