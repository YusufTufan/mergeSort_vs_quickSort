import numpy as np
import matplotlib.pyplot as plt

# Veriler
n_values = np.array([1000, 5000, 10000, 50000, 100000, 200000])

# QuickSort deneysel süreleri ve c değerleri
qs_times = np.array([0.000080, 0.000424, 0.000920, 0.005542, 0.012721, 0.027074])
qs_c = np.array([t / (n * np.log2(n)) for t, n in zip(qs_times, n_values)])
qs_c_avg = np.mean(qs_c)
qs_teorik = qs_c_avg * n_values * np.log2(n_values)

# MergeSort deneysel süreleri ve c değerleri
ms_times = np.array([0.000154, 0.000761, 0.001507, 0.008892, 0.018873, 0.039673])
ms_c = np.array([t / (n * np.log2(n)) for t, n in zip(ms_times, n_values)])
ms_c_avg = np.mean(ms_c)
ms_teorik = ms_c_avg * n_values * np.log2(n_values)

# QuickSort grafiği
plt.figure(figsize=(10, 5))
plt.plot(n_values, qs_times, marker='o', label='QuickSort - Deneysel')
plt.plot(n_values, qs_teorik, linestyle='--', label='QuickSort - Teorik (T=c·n·logn)')
plt.title('QuickSort: Deneysel vs Teorik Süre')
plt.xlabel('n')
plt.ylabel('T(n) [saniye]')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

# MergeSort grafiği
plt.figure(figsize=(10, 5))
plt.plot(n_values, ms_times, marker='o', label='MergeSort - Deneysel')
plt.plot(n_values, ms_teorik, linestyle='--', label='MergeSort - Teorik (T=c·n·logn)')
plt.title('MergeSort: Deneysel vs Teorik Süre')
plt.xlabel('n')
plt.ylabel('T(n) [saniye]')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
