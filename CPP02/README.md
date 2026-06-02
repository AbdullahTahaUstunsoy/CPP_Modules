CPP Module 02 - Fixed-Point Numbers

Bu proje, C++ programlama dilinde Ad-hoc polymorphism, operatör aşırı yüklemesi (operator overloading) ve Orthodox Canonical Class Form kavramlarını öğrenmek ve uygulamak amacıyla geliştirilmiştir. Proje boyunca, tam sayıların ve kayan noktalı sayıların (float) sabit noktalı (fixed-point) sayılara dönüştürülmesi ve bu sayılar üzerinde aritmetik/karşılaştırma işlemlerinin yapılması üzerine çalışılmıştır.
Proje İçeriği

Proje, birbirini geliştiren üç ana aşamadan oluşmaktadır:
1. Exercise 00: My First Class in Orthodox Canonical Form

    Amaç: C++'da standart bir sınıf yapısı olan "Orthodox Canonical Class Form" yapısını kavramak.

    İçerik: Fixed sınıfı; varsayılan kurucu (default constructor), kopyalama kurucusu (copy constructor), kopya atama operatörü (copy assignment operator) ve yıkıcı (destructor) içerir.

    Özellik: Sabit noktalı değerleri saklamak için bir int ve kesirli bit sayısını belirlemek için 8 değerinde statik bir int kullanır.

2. Exercise 01: Towards a more useful fixed-point number class

    Amaç: Sınıfı daha kullanışlı hale getirmek için farklı türlerden dönüşüm eklemek.

    İçerik: int ve float parametre alan kurucu fonksiyonlar eklenmiştir.

    Fonksiyonlar: * toFloat() ve toInt() metotları ile sabit noktalı sayı ile diğer türler arasında dönüşüm sağlanır.

        << operatörü aşırı yüklenerek nesnenin doğrudan yazdırılması sağlanmıştır.

3. Exercise 02: Now we’re talking

    Amaç: Matematiksel ve mantıksal operatörlerin aşırı yüklenmesini uygulamak.

    İçerik: Fixed sınıfı için kapsamlı operatör setleri tanımlanmıştır:

        Karşılaştırma Operatörleri: >, <, >=, <=, ==, !=.

        Aritmetik Operatörleri: +, -, *, /.

        Artırma/Azaltma Operatörleri: Ön ek (prefix) ve son ek (postfix) ++ ve --.

    Ekstra: İki sabit noktalı sayı arasından en küçüğünü veya en büyüğünü döndüren statik min ve max fonksiyonları eklenmiştir.

Teknik Detaylar

    Standart: Tüm kodlar C++98 standartlarına uygun olarak yazılmıştır.

    Hassasiyet: Kesirli bit sayısı (fractional bits) olarak 8 kullanılmıştır.

    Bellek Yönetimi: Dinamik bellek kullanımı gerektirmeyen, doğrudan değer odaklı bir yapı kurulmuştur.

Kurulum ve Çalıştırma

Her bölüm kendi Makefile dosyasını içerir. Derlemek için ilgili klasöre gidip aşağıdaki komutu kullanabilirsiniz:
Bash

make

Derleme sonrası oluşan çalıştırılabilir dosyayı başlatmak için:
Bash

./main

Description

Bu proje, C++'da sayısal veri türlerinin arka planda nasıl işlendiğini anlamak ve sabit noktalı aritmetik gibi düşük seviyeli kavramları yüksek seviyeli nesne yönelimli programlama teknikleriyle birleştirmek için tasarlanmıştır. Operatör aşırı yüklemesi sayesinde, özel sınıfların yerleşik veri türleri gibi doğal bir şekilde kullanılabilmesi hedeflenmiştir.
