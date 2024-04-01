#include<iostream>

using namespace std;

vector<vector<string>> kutuphane;
void yeniOgrenci (string ogrNo,string adSoyad);
void oduncKayit(string ogrenciNo, string kitapAdi);
void kitapIade(string ogrNo, string kitapAdi);
void rapor();
void tumKayitlariGoruntule();

int main(int argc, char **argv)
{
    string secim,ogrNo,kitapAdi,adSoyad;
    while(1){

        cout << "Yeni öğrenci eklemek için: 1" << endl;
        cout << "Kitap ödünç vermek için: 2" << endl;
        cout << "Kitap iadesi yapmak için: 3" << endl;
        cout << "Rapor almak için : 4" << endl;
        cout << "Tüm kayıtları görüntülemek için: 5" << endl;
        cout << "Çıkış yapmak için: X" << endl;
        cout << "Yapmak istediğiniz işlemi seçin: ";

        cin >> secim;
        cin.ignore();

        if (secim == "1")
        {
            cout << "Öğrencinin numarası: ";
            getline(cin,ogrNo);
            cout << "Öğrencinin adı soyadı: ";
            getline(cin,adSoyad);
            yeniOgrenci(ogrNo,adSoyad);
        }
        else if (secim == "2")
        {
            cout << "Öğrencinin numarası: ";
            getline(cin,ogrNo);
            cout << "Kitap adı: ";
            getline(cin,kitapAdi);
            oduncKayit(ogrNo,kitapAdi);
        }
        else if (secim == "3")
        {
            cout << "Öğrenci numarası: ";
            getline(cin,ogrNo);
            cout << "Kitap Adı: ";
            getline(cin,kitapAdi);
            kitapIade(ogrNo,kitapAdi);
        }
        else if (secim == "4")
            rapor();
        else if (secim == "5")
            tumKayitlariGoruntule();
        else if (secim == "X")
            break;
        else
            cout << "Lütfen istenilen değerlerden birini giriniz!" << endl;
    }
    return 0;
}

void yeniOgrenci(string ogrNo, string adSoyad)
{
    int flag = 0; //öğrencinin kayıtlı olup olmadığını sorgulamak
    for (int i=0;i<kutuphane.size();i++)
    {
        if (kutuphane[i][0] == ogrNo)
            flag = 1;
    }

    if (flag == 1)
        cout << "Kayıtlı öğrenci bulundu" << endl;
    else
    {
        vector<string> temp = {ogrNo,adSoyad};
        kutuphane.push_back(temp);
        cout << "Öğrenci kaydı başarıyla gerçekleştirildi."<< endl;
    }
}

void oduncKayit(string ogrenciNo, string kitapAdi)
{
    int flag = -1;
    int kitapVar = 0;

    for(int i=0;i<kutuphane.size();i++)
    {
        if (kutuphane[i][0] == ogrenciNo)
        {
            flag = i;
            break;
        }
    }

    if (flag = -1)
        cout << "Böyle bir öğrencinin kaydı bulunmamaktadır.";

    else
    {
        if (kutuphane[flag].size()>1)
        {
            for (int i=2;i<kutuphane[flag].size();i++)
            {
                if (kutuphane[flag][i] == kitapAdi)
                {
                    kitapVar = 1;
                    break;
                }

            }

            if(kitapVar == 1)
                cout << "Kitap bu öğrenci tarafından daha önce alınmış." << endl;

            else
            {
                kutuphane[flag].push_back(kitapAdi);

                for(int i=2;i<kutuphane[flag].size();i++)
                {
                    for (int j = 2; j < kutuphane[flag].size() -i -1; ++j) {
                        if (kutuphane[flag][j]> kutuphane[flag][j+1])
                            kutuphane[flag][j].swap(kutuphane[flag][j+1]);
                    }
                }
            }
        }
    }
}

void kitapIade(string ogrNo, string kitapAdi)
{
    int flag = -1;
    int kitapIndex = -1;

    for (int i = 0; i < kutuphane.size(); ++i) {
        if (kutuphane[i][0] == ogrNo)
        {
            flag = i;
            break;
        }
    }

    if (flag == -1)
        cout << "Kayıtlı öğrenci bulunamadı."<< endl;
    else
    {
        if (kutuphane[flag].size() > 1)
        {
            for (int i = 2; i <kutuphane[flag].size() ; ++i) {
                if (kutuphane[flag][i] == kitapAdi)
                {
                    kitapIndex = i;
                    break;
                }
            }

            if (kitapIndex > -1)
                kutuphane[flag][kitapIndex] .erase();
            else
                cout << "Bu öğrenci tarafından alınmış" << kitapAdi << "isimli kitap alınmamıştır." << endl;
        }
    }
}


void rapor()
{
    int max = kutuphane[0][0].size();
    int index = 0;

    for (int i = 1; i < kutuphane.size(); ++i) {

        if (max < kutuphane[i].size())
        {
            max = kutuphane[i].size();
            index = i;
        }
    }

    cout << "En çok kitap alan öğrenci " << kutuphane[index][0] << " nolu" << kutuphane[index][1] << " isimli öğrencidir" << endl;

    int min = kutuphane[0][0].size();
    index = 0;

    for (int i = 1; i < kutuphane.size(); i++)
    {
        if (min > kutuphane[i].size()){
            min = kutuphane[i].size();
            index = i;
        }
    }

    cout << "En az kitap alan öğrenci " << kutuphane[index][0] << " nolu" << kutuphane[index][1] << " isimli öğrencidir" << endl;

    int toplam = 0;
    for (int i = 0; i < kutuphane.size(); ++i) {
        if (kutuphane[i].size() > 2)
            toplam += kutuphane[i].size() -2;
    }

    cout << "Her öğrencide ortalama " << toplam / kutuphane.size() << "adet kitap bulunmaktadır." << endl;
}

void tumKayitlariGoruntule()
{
    cout << endl;

    for (int i = 0; i < kutuphane.size(); ++i) {
        for(int j=0; j < kutuphane[i].size();j++)
        {
            cout << kutuphane[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}