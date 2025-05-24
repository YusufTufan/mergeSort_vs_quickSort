import numpy as np
import matplotlib.pyplot as plt

# Veriler
n_values = np.array([1000, 5000, 10000, 50000, 100000, 200000])

# Deneysel süreler
qs_times = np.array([0.00000001, 0.00000001, 0.00000001,0.00000001, 0.00000001, 0.00000001])
ms_times = np.array([0.00000002, 0.00000001, 0.00000001,0.00000001, 0.00000001, 0.00000001])

# c katsayıları
qs_c = np.array([t / (n * np.log2(n)) for t, n in zip(qs_times, n_values)])
ms_c = np.array([t / (n * np.log2(n)) for t, n in zip(ms_times, n_values)])

# Grafik
plt.figure(figsize=(10, 5))
plt.plot(n_values, qs_c, marker='o', label='QuickSort - c katsayısı')
plt.plot(n_values, ms_c, marker='o', label='MergeSort - c katsayısı')
plt.title('Farklı n Değerleri İçin c Katsayıları')
plt.xlabel('n')
plt.ylabel('c = T(n) / (n·log₂n)')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
