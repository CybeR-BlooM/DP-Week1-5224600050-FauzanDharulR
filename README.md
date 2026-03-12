1. What is the invariant structure?
- Struktur invariant-nya adalah kelas RunSession dan urutan 6 fase di dalamnya (Generate Input -> Base Score -> Reward -> Update Money -> Shop -> Advance Round). Ini adalah fondasi yang tidak berubah.

2. Which parts are mutable?
- Bagian yang mutable adalah implementasi dari aturan-aturan tersebut, yaitu kelas-kelas yang mewarisi (inherit) antarmuka IInputGenerator, IScoringRule, dan IRewardRule. Perilaku mereka bisa diubah, ditambah, atau diganti.

3. Why didn't RunSession change?
- Karena kita menggunakan prinsip Polymorphism dan Dependency Injection. RunSession tidak peduli dengan kelas spesifik (seperti RandomInputGenerator), ia hanya berkomunikasi melalui "kontrak" atau antarmuka (IInputGenerator). Selama kelas baru mematuhi kontrak tersebut, RunSession bisa menerimanya tanpa perlu diubah kodenya.

4. What if scoring logic was inside RunSession?
- Jika logika scoring ada di dalam RunSession, sistem akan kehilangan fleksibilitas (melanggar prinsip Open-Closed Principle dari SOLID). Setiap kali ada perubahan cara hitung skor, kita harus memodifikasi kelas inti, yang mana berisiko merusak alur (loop) permainan dan membuat testing menjadi sangat sulit.

  Kesimpulan Proyek: Memisahkan Invariant dan Mutable

  Fokus utama dari tugas ini bukanlah membuat game yang seru dimainkan, melainkan menciptakan sistem yang kebal terhadap perubahan (robust). Kita berhasil mencapai ini dengan menerapkan prinsip SOLID, khususnya Open-Closed Principle (sistem harus terbuka untuk perluasan, tapi tertutup untuk modifikasi).

  Berikut adalah poin-poin kunci dari arsitektur yang telah kita bangun:

- Sang Invariant (RunSession):
Kelas ini adalah jantung permainan yang menjaga aturan mutlak. Urutan 6 fase (Generate Input, Base Score, Reward, Update Money, Shop, Advance Round) telah dikunci rapat di dalam RunSession.cpp. Bagian ini tidak boleh dan tidak perlu diubah lagi, apa pun permintaan balancing atau desain game barunya nanti.

- Sang Mutable (Interfaces & Concrete Classes):
Aturan perhitungan skor, cara mendapatkan input, dan logika uang adalah fitur yang sangat sering berubah dalam pengembangan game. Oleh karena itu, kita mengisolasinya menggunakan Interface murni (IInputGenerator, IScoringRule, IRewardRule). Kelas-kelas spesifik seperti RandomInputGenerator atau BonusRewardRule adalah implementasi nyata yang sifatnya mutable (bisa diganti-ganti sesuka hati).
