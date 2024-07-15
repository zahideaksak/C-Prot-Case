# C-Prot-Case

C-Prot-Case, C dilinde yazılmış dört farklı uygulamayı içeren bir projedir. Her uygulama farklı bir problemi çözmek için tasarlanmıştır ve hepsi ortak bir modül (`common`) kullanır. Bu projede, kodun modüler yapısını korumak ve yeniden kullanılabilirliği artırmak amacıyla ortak fonksiyonlar `common` klasöründe toplanmıştır.

## İçerik

- `app1`: Tam yolu verilecek olan bir dosyanın ilk 2 baytı okunup ekrana yazdırılmasını sağlayan uygulama.
- `app2`: Bir dosyada belirtilen kelimeyi arayan ve bulunduğu konumun offset değerini yazdıran uygulama.
- `app3`: Bir klasör içerisindeki tüm dosyalara app2'deki arama işlemlerini uygular.
- `app4`: Bir klasör içerisindeki dosyaların PE dosya formatında olup olmadığını tespit eder.
- `common`: Ortak fonksiyonları içeren modül.
  
## Kurulum

Projeyi yerel makinenize klonlayarak başlayın:

```bash
git clone https://github.com/username/C-Prot-Case.git
cd C-Prot-Case
