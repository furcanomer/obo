#include <iostream>
#include <conio.h>
using namespace std;

int ekran_Silme = 0;

void ekranTemizle(){

	system("clear"); // Komut satırı için ekran temizleme kodu

}

void baslangic(){
	ekranTemizle(); 	// eğer dosya konsoldan açıldıysa konsolla alakalı yazıların ekrandan silinmeisini sağlar.
					// Ekranın sadece oyun ile alakalı olmasını istiyorum.
	
	cout << "OBO 1.3 - https://github.com/furcanomer/obo\n--------------------------------------------------------------------------------\nSaga gitmek icin 'D' tusuna basin.\tYeniden baslamak icin 'R' tusuna basin.\n\n";
	cout << "Sola gitmek icin 'A' tusuna basin.\tOyunu kapatmak icin 'X' tusuna basin.";
	cout << "\n--------------------------------------------------------------------------------\n\n";
}

void yeniden_Baslangic(){
	
	ekran_Silme = 1;
	
}



int main(){
	
	baslangic();
	
	char tus,karar;
	int adim = 0;
	// adim değişkeni sayseinde kaç adet sağa gittiğimi ölçüyorum ki programa sola git dediğimde sağa gittiğim kadar da sola gitsin.
	// ekran_Silme değişkenini sıfır yaptım ki ekran silme koşulu çalışmasın.
	// oyuncu oyuna baştan başlamak istediği zaman ekran_silme = 1 oluyor ve koşul sağlanıyor ve hemen ardından geri 0 oluyor.	
		while(true){
			
			if (ekran_Silme == 1){
				
				baslangic();
				ekran_Silme = 0;
				adim = 0;
				
			}
			
			tus = getch(); // getch() ile istedim ki ekrana D harfi basılmasın.
			
			if (tus == 'd' || tus == 'D'){
				
					if (adim < 19){ // ok sayısını 19 ile sınırlayan kod
						cout << "--> ";
						adim ++; // her sağa gittiğimizde adim 1 artıyor.
					}

					else{
						cout << "\a"; 
						// ok sınırıda rağmen hala sağa gidilmeye çalışılıyorsa sistem uyarı sesi verecek
					}
				
			}
			
			else if (tus == 'a' || tus == 'A'){ // sola git tuşu
				
				if (adim > 0){ // eğer sağa gittiysek
					
					cout << endl;
					
					cout << "<--"; 
					for (int i = adim; i > 1; i--){ // for döngüsü sayesinde sağa gittiğimiz adim sayisi kadar
													// sola gidebiliyoruz.
						cout << " <--";
						
					}
					
					cout << "\n\n"; // sola gittikten sonra 2 satır aşağı atlıyoruz.
					
					adim = 0; 	// sola gittikten sonra adimi sıfırlıyoruz
								// Sıfırlamazsak sola gitme tuşuna bastığımızda, eski sağ adim sayisi kadar sola gideriz.
					
				}
				
				else if (adim == 0){ 	// sola gitme tuşuna bastık evet ama eğer hiç sağa gitmemişsek...?
					cout << "\a"; continue;	// ...o zaman hiçbir şey yapmıyoruz ve sistem uyarı sesi çıkarıp
				}							// while döngüsünün başına dönüyoruz.
				
			}
			
			
			else if (tus == 'x' || tus == 'X'){
				ekranTemizle();
				break;

			}
				
			else if (tus == 'R' || tus == 'r'){
			
				yeniden_Baslangic();
				continue;
			
			}
			
			else
				continue; // A - D  tuşlarına basılmadıysa hiçbirşey yapılmıyor ve while döngüsünün başına dönüyoruz.
				
		}
	
	return 0;
}
