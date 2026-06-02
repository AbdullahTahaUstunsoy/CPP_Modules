CPP Module 03 - Inheritance (Kalıtım)

Bu proje, C++ programlama dilinde Inheritance (Kalıtım) kavramını anlamak ve uygulamak amacıyla geliştirilmiştir. Proje boyunca, nesne yönelimli programlamanın (OOP) temel taşlarından olan sınıflar arası hiyerarşi, erişim belirleyicileri (public, protected, private) ve kurucu/yıkıcı (constructor/destructor) fonksiyonların çağrılma sıraları üzerine çalışılmıştır.
Proje İçeriği

Proje, birbirini takip eden ve geliştirilen üç ana bölümden oluşmaktadır:
1. Exercise 00: Aaaaand... OPEN!

    Amaç: Temel bir sınıf yapısı oluşturmak ve "Orthodox Canonical Class Form" prensiplerini uygulamak.

    Sınıf: ClapTrap sınıfı; isim, can puanı (Hit Points), enerji puanı (Energy Points) ve saldırı gücü (Attack Damage) özelliklerine sahiptir.

    Fonksiyonlar: attack, takeDamage ve beRepaired yetenekleri ile temel bir robot simülasyonu sunar.

2. Exercise 01: Serena, my love!

    Amaç: Kalıtım mekanizmasını kullanarak mevcut bir sınıfı genişletmek.

    Sınıf: ScavTrap sınıfı, ClapTrap sınıfından türetilmiştir.

    Özellikler: ScavTrap kendine has başlangıç değerlerine (100 HP, 50 EP, 20 AD) sahiptir ve attack fonksiyonunu kendi davranışına göre özelleştirir (override).

    Ekstra: guardGate() fonksiyonu ile "Gate Keeper" moduna geçme özelliği eklenmiştir.

3. Exercise 02: Repetitive work

    Amaç: Farklı alt sınıflar oluşturarak kalıtım hiyerarşisini pekiştirmek.

    Sınıf: FragTrap sınıfı, yine ClapTrap üzerinden türetilmiştir.

    Özellikler: Daha yüksek saldırı gücüne (30 AD) sahip olan bu sınıf, kurucu ve yıkıcı mesajlarıyla hiyerarşik yapıdaki sırasını gösterir.

    Ekstra: highFivesGuys() fonksiyonu ile pozitif bir etkileşim isteği (beşlik çakma) gönderir.

Teknik Detaylar

    Erişim Yönetimi: ClapTrap sınıfındaki üye değişkenler, türetilmiş sınıfların (ScavTrap, FragTrap) erişebilmesi için protected olarak tanımlanmıştır.

    Bellek ve Yapı: Tüm sınıflar varsayılan kurucu, kopyalama kurucusu, kopyalama atama operatörü ve yıkıcıyı içeren "Orthodox Canonical Form" yapısındadır.

    Sıralama: Bir türetilmiş sınıf oluşturulduğunda önce ClapTrap kurucusu, sonra ilgili sınıfın kurucusu çalışır; yıkma aşamasında ise bu sıranın tam tersi izlenir.

Kurulum ve Çalıştırma

Her exercise klasörü kendi Makefile dosyasını içerir. Derlemek için ilgili klasöre gidip şu komutu kullanabilirsiniz:
Bash

make

Programı test etmek için oluşturulan dosyayı çalıştırın:
Bash

# Örn: ScavTrap için
./ScavTrap

Standartlar

    Yazılan tüm kodlar C++98 standartlarına uygundur.

    Hata yönetimi ve nesne durumu kontrolleri (can veya enerji bitmesi durumu) her fonksiyonda titizlikle yapılmıştır.
