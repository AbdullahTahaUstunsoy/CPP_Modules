CPP Module 04 - Polymorphism (Çok Biçimlilik)

Bu proje, C++ programlama dilinde Subtype Polymorphism (Alt Tip Çok Biçimliliği), Abstract Classes (Soyut Sınıflar) ve Deep Copy (Derin Kopya) kavramlarını anlamak ve uygulamak amacıyla geliştirilmiştir. Proje, Ecole 42 müfredatındaki C++ modüllerinin dördüncüsüdür.
Proje İçeriği

Proje üç ana bölümden (exercise) oluşmaktadır:
1. Exercise 00: Polymorphism

    Amaç: Temel kalıtım ve sanal (virtual) fonksiyonların işleyişini kavramak.

    İçerik: Animal adında bir temel sınıf ve ondan türeyen Dog ve Cat sınıfları implement edilmiştir.

    Özellik: makeSound() fonksiyonu sanal olarak tanımlanmış, böylece çalışma zamanında (runtime) doğru sınıfa ait sesin çıkarılması sağlanmıştır.

    Ekstra: Hatalı implementasyonun sonuçlarını görmek için WrongAnimal ve WrongCat sınıfları da eklenmiştir.

2. Exercise 01: I don’t want to set the world on fire

    Amaç: Bellek yönetimi ve derin kopyalama (deep copy) prensiplerini uygulamak.

    İçerik: Cat ve Dog sınıflarına özel birer Brain sınıfı (yüz adet fikir içeren) eklenmiştir.

    Özellik: Nesneler kopyalandığında (copy constructor veya assignment operator kullanıldığında), bellek adresleri yerine içeriklerin kopyalandığı "Derin Kopya" mekanizması kurulmuştur. Bu sayede bir nesnenin silinmesi diğerini etkilemez.

3. Exercise 02: Abstract Class

    Amaç: Sınıf hiyerarşisinde nesne oluşturulmasını engellemek için soyut sınıfları kullanmak.

    İçerik: Animal sınıfı, makeSound() fonksiyonunun saf sanal (pure virtual) hale getirilmesiyle soyut bir sınıfa dönüştürülmüştür.

    Özellik: Bu aşamadan sonra Animal sınıfından doğrudan bir nesne üretilemez (örn: new Animal() hata verir), yalnızca türetilmiş sınıflar (Cat, Dog) kullanılabilir.

Kurulum ve Çalıştırma

Projedeki her bölüm kendi Makefile dosyasını içerir. Derlemek için ilgili klasöre gidip aşağıdaki komutu çalıştırabilirsiniz:
Bash

make

Programı çalıştırmak için:
Bash

./main

Bellek sızıntısı kontrolü (Valgrind ile):
Bash

valgrind --leak-check=full ./main

Temel Kurallar (C++98)

    Kodlar C++98 standartlarına uygun olarak yazılmıştır.

    Sınıflar "Orthodox Canonical Class Form" (Default constructor, Copy constructor, Copy assignment operator ve Destructor) yapısına uygundur.

    Bellek sızıntılarını önlemek için sanal yıkıcılar (virtual destructors) kullanılmıştır.

Not: Bu proje kapsamında geliştirilen tüm sınıflar, nesne yönelimli programlamanın (OOP) temel direklerinden olan kalıtım ve çok biçimlilik üzerine inşa edilmiştir.
