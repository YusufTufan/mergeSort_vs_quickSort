
---

## 📄 Merge Sort ve Quick Sort Karşılaştırma Raporu

### 🔍 Giriş

Bu çalışmada **Merge Sort** ve **Quick Sort** algoritmalarını farklı boyutlardaki rastgele oluşturulmuş diziler üzerinde test ettim. Her dizi boyutu için sıralama işlemini **50 kez** çalıştırarak **ortalama süreleri** hesapladım.

Teorik olarak:

$$
T(n) ≈ c \cdot n \log_2 n
$$

Katsayı:

$$
c = \frac{T(n)}{n \log_2 n}
$$

---

### 💻 Kodlar (Yorumlu)

**Amaç:**
Farklı dizi boyutları üzerinde Quick Sort ve Merge Sort’un sıralama sürelerini ölçmek ve katsayı `c = T(n) / (n log₂n)` hesaplayarak analiz etmek.

* **Test Sayısı:** Her dizi boyutu için 50 kez çalıştırılıyor.
* **Ölçüm:** `clock()` fonksiyonu ile sıralama işlemi süresi ölçülerek karşılaştırma yapılıyor.

---

### 🧮 Merge Sort & Quick Sort Uygulamaları

#### 🔸 Merge Sort

* `mergeSort()` fonksiyonu diziyi sürekli ikiye bölerek çalışır.
* `merge()` fonksiyonu ile sıralama tamamlanır.
* **Bellek kullanımı yüksektir.**

#### 🔹 Quick Sort

* `quickSort()` fonksiyonu pivot seçerek çalışır.
* `partition()` ile elemanlar sıralanır.
* **Yerinde sıralama** yaptığı için belleği daha verimli kullanır.

---

### ⏱ Ortalama Çalışma Süresi Hesaplama

`avgTime()` fonksiyonu ile:

* Her testte rastgele dizi üretilir.
* 50 testin ortalaması alınır.
* Hem **T(n)** hem **c** katsayısı hesaplanır.

---

## 📊 Deneysel Sonuçlar

### 📈 Merge Sort Sonuçları

| n (Dizi Boyutu) | T(n) (İşlem Süresi) | c (Katsayı) |
| --------------- | ------------------- | ----------- |
| 1000            | 0.000154            | 0.00000002  |
| 5000            | 0.000761            | 0.00000001  |
| 10000           | 0.001507            | 0.00000001  |
| 50000           | 0.008892            | 0.00000001  |
| 100000          | 0.018873            | 0.00000001  |
| 200000          | 0.039673            | 0.00000001  |

### 📈 Quick Sort Sonuçları

| n (Dizi Boyutu) | T(n) (İşlem Süresi) | c (Katsayı) |
| --------------- | ------------------- | ----------- |
| 1000            | 0.000080            | 0.00000001  |
| 5000            | 0.000424            | 0.00000001  |
| 10000           | 0.000920            | 0.00000001  |
| 50000           | 0.005542            | 0.00000001  |
| 100000          | 0.012721            | 0.00000001  |
| 200000          | 0.027074            | 0.00000001  |

---

## 📚 Genel Değerlendirme

* Merge Sort her zaman **O(n log n)** garantisi verir.
* Quick Sort daha hızlıdır ama kötü pivot seçiminde **O(n²)** olabilir.
* Küçük veri setlerinde Quick Sort avantajlı.
* Büyük veri setlerinde Merge Sort’un **RAM kullanımı** önemli hale gelir.

---

## 📉 Teorik ve Deneysel Kıyaslamalar


```markdown
<div style="display: flex; justify-content: center; gap: 10px;">
  <img src="https://github.com/YusufTufan/YusufTufan-mergeSort_vs_quickSort/blob/main/images/Ekran%20g%C3%B6r%C3%BCnt%C3%BCs%C3%BC%202025-05-24%20193333.png" width="250"/>
  <img src="https://github.com/YusufTufan/YusufTufan-mergeSort_vs_quickSort/blob/main/images/Ekran%20g%C3%B6r%C3%BCnt%C3%BCs%C3%BC%202025-05-24%20193311.png" width="250"/>
  <img src="https://github.com/YusufTufan/YusufTufan-mergeSort_vs_quickSort/blob/main/images/Ekran%20g%C3%B6r%C3%BCnt%C3%BCs%C3%BC%202025-05-24%20193351.png" width="250"/>
</div>
```

> Dosyalarını `images` klasörüne ekleyerek README ile birlikte GitHub'a yüklemen gerekir.

---

## 📌 Sonuç ve Tartışma

### Gerçek Hayatta `c` Değerleri Neden Değişiyor?

* **Cache Etkisi:** Quick Sort diziyi yerinde sıralar → daha iyi önbellek performansı.
* **Fonksiyon Çağrısı Yükü:** Merge Sort daha fazla fonksiyon çağırır → CPU döngüsü tüketimi artar.
* **Bellek Kullanımı:** Merge Sort ek dizi kullanır → RAM tüketimi artar.
* **Donanım/Derleyici Farkı:**

  * CPU mimarisi
  * Derleyici optimizasyonları
  * Arka plan işlemler

### 🎯 Son Söz

* Teorik analiz, büyüme oranını anlamak için önemlidir.
* Gerçek hayatta **donanım, bellek, CPU, önbellek** gibi faktörler sonucu etkiler.
* Quick Sort genellikle daha hızlıdır.
* Merge Sort ise **kararlı ve garantili** bir algoritmadır.

---
