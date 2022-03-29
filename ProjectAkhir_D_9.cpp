#include <iostream>
#include <string>
#include <iomanip>

const int MIN_YEARS = 1800;
const int MAX_YEARS = 9999;
const int month_day[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

using namespace std; 

	int tesla_s = 3;
	int tesla_x = 3;
	int honda_crv = 2;
	int honda_brio = 3;
	int daihatsu_xenia =2;
	int toyota_gat = 3;
	int mercedes_c = 2;

int menu();
void Register(string *nama_pelanggan, string *password, string *kendaraan_pelanggan, int *lama_rental, int *harga_mobil, int *hari_check_in, int *bulan_check_in, int *tahun_check_in, int *hari_out, int *bulan_out, int *tahun_out, int &batas, int &id);
void Informasi(string *nama_pelanggan, string *kendaraan_pelanggan, int *lama_rental, int *harga_mobil, int *hari_check_in, int *bulan_check_in, int *tahun_check_in,  int *hari_out, int *bulan_out, int *tahun_out, int *hari_check_out, int *bulan_check_out, int *tahun_check_out, int &id);
void pembayaran(string *nama_pelanggan, string *password, string *kendaraan_pelanggan, int *lama_rental, int *harga_mobil, int *harga, int &batas, int &id);
void syarat_check(int day, int month, int year, bool &syarat_tanggal);
void Check_Out (string *nama_pelanggan, string *password, int *hari_out, int *bulan_out, int *tahun_out, int *hari_check_out, int *bulan_check_out, int *tahun_check_out, int *harga_mobil, string *kendaraan_pelanggan, int &id);
void count_punishment(int *hari_out, int *bulan_out, int *tahun_out, int *hari_check_out, int *bulan_check_out, int *tahun_check_out, int *harga_mobil, string *kendaraan_pelanggan, int &id, int &ids);
bool is_LeapYear(int year);
void tanggal(int &day, int &month, int &year, int&rental);
int add_day(int day, int &month, int d_max);
int add_month(int month, int &year, int m_max);

int main (){
	int no_menu = menu();
	int id =0, batas=1, kapasitas = 100;
	int lama_rental[kapasitas];
	int harga_mobil[kapasitas]; 
	int hari_check_in[kapasitas];
	int bulan_check_in[kapasitas];
	int tahun_check_in[kapasitas];
	int hari_out[kapasitas];
	int bulan_out[kapasitas];
	int tahun_out[kapasitas];
	int hari_check_out[kapasitas]={};
	int bulan_check_out[kapasitas]={};
	int tahun_check_out[kapasitas]={};
	
	enum pilihan {REGISTER = 1, INFORMASI, CHECK_OUT, EXIT};
	string nama_pelanggan[kapasitas], password[kapasitas];
	string kendaraan_pelanggan[kapasitas], lagi;
	
	while (no_menu != EXIT){
		system("cls");
		switch (no_menu){
			case REGISTER:
				Register(nama_pelanggan, password, kendaraan_pelanggan, lama_rental, harga_mobil, hari_check_in, bulan_check_in, tahun_check_in, hari_out, bulan_out, tahun_out, batas, id);
				no_menu = menu();
				break;
			case INFORMASI:
				Informasi(nama_pelanggan, kendaraan_pelanggan,lama_rental, harga_mobil, hari_check_in, bulan_check_in, tahun_check_in, hari_out, bulan_out, tahun_out, hari_check_out, bulan_check_out, tahun_check_out, id);
				no_menu = menu();
				break;
			case CHECK_OUT:
				Check_Out(nama_pelanggan, password, hari_out, bulan_out, tahun_out, hari_check_out, bulan_check_out, tahun_check_out, harga_mobil, kendaraan_pelanggan, id);
				no_menu = menu();
				break;
			default:
				cout << "Pilihan tidak ditemukan" << endl;
				system("pause");
				no_menu = menu();
				break;
		}
	}	
	
	cout << "\nSekian Dan Terimakasih" << endl;
	
	cin.get ();
	return 0;
}

int menu(){
	system("cls");
	int input;
	cout << "+----------------------------------------------------------+" << endl;
	cout << "|" << setw(48) << "SELAMAT DATANG DI PROGRAM RENTAL MOBIL" << setw(11) << "|" << endl;
	cout << "+----------------------------------------------------------+" << endl << endl;
	cout << "1. Registrasi / Mendaftar Rental Kendaraan" << endl;
	cout << "2. Informasi Rental Kendaraan" << endl;
	cout << "3. Check Out" << endl;
	cout << "4. Keluar Program" << endl << endl;
	
	cout << "Silahkan pilih nomor menu (1-4) : ";
	cin >> input; cout << endl;
	cin.ignore();
	system("pause");
	return input;
}

void Register(string *nama_pelanggan, string *password, string *kendaraan_pelanggan, int *lama_rental, int *harga_mobil, int *hari_check_in, int *bulan_check_in, int *tahun_check_in, int *hari_out, int *bulan_out, int *tahun_out, int &batas, int &id){
	int input_kendaraan;
	int harga[100];
	int rental;
	int day, month, year;
	string nama, pass, pesan, kendaraan, pass_ulang;
	bool syarat_user = true;
	do{
		system("cls");
		cout << "\n\n\n\n\t\t\t\t+------------------------------------------------+" << endl;
		cout << "\t\t\t\t|" << setw(37) <<"SILAHKAN REGISTRASI AKUN ANDA" << setw(12) << "|" << endl;
		cout << "\t\t\t\t+------------------------------------------------+" << endl << endl << endl;
		cout << "\t\t\t\tMasukkan username anda\t: ";
		getline(cin, nama);
		cout << "\t\t\t\tMasukkan password anda\t: ";
		getline(cin, pass); 
		cout << "\t\t\t\tUlangi password anda\t: ";
		getline(cin, pass_ulang);cout << endl;
		
		for(int i=0; i<=id; i++){
			if (nama_pelanggan[i] == nama){
				syarat_user = false;
				cout << "\t\t\t\tUsername telah digunakan / username anda kosong, ganti username anda" << endl;
				break;
			}else {
				syarat_user = true;
			}
		}
		cout << "\t\t\t\t" << system("pause");
	} while(pass != pass_ulang || syarat_user == false);
	
	do{
		id++;
		bool syarat_tanggal = true;
		nama_pelanggan[id] = nama;
		password[id] = pass;
		system("cls");
		cout << "+----------------------------------------------------+" << endl;
		cout << "|" << setw(48) << "SILAHKAN REGISTRASI MOBIL YANG AKAN DIRENTAL" << setw(5) << "|" << endl;
		cout << "+----------------------------------------------------+" << endl << endl;
		cout << "1. Mobil Tesla Model S\t\t(" << setw(11) << "Auto Pilot" << setw(2) << ")" << endl;
		cout << "2. Mobil Tesla Model X\t\t(" << setw(11) << "Auto Pilot" << setw(2) << ")" << endl;
		cout << "3. Mobil Honda CRV\t\t(" << setw(9) << "Matic" << setw(4) << ")" << endl;
		cout << "4. Mobil Honda Brio\t\t(" << setw(9) << "Matic" << setw(4) << ")" << endl;
		cout << "5. Mobil Daihatsu Xenia\t\t(" << setw(10) << "Manuals" << setw(3) << ")" << endl;
		cout << "6. Mobil Toyota GA/T\t\t(" << setw(10) << "Manuals" << setw(3) << ")" << endl;
		cout << "7. Mobil Mercedes C Class\t(" << setw(10) << "Manuals" << setw(3) << ")" << endl << endl;
		cout << "===========================================================" << endl;
		cout << "Pilih no kendaraan apa yang ingin anda rental\t: ";
		cin >> input_kendaraan;
		cin.ignore();
		if ((input_kendaraan == 1 && tesla_s == 0)||(input_kendaraan == 2 && tesla_x == 0)||(input_kendaraan == 3 && honda_crv == 0)||(input_kendaraan == 4 && honda_brio == 0)||(input_kendaraan == 5 && daihatsu_xenia == 0)||(input_kendaraan == 6 && toyota_gat == 0)||(input_kendaraan == 7 && mercedes_c == 0)){
			cout << "Mobil yang anda pilih tidak tersedia" << endl;
			id--;
		}else if(input_kendaraan == 1 || input_kendaraan == 2 || input_kendaraan == 3 || input_kendaraan == 4 || input_kendaraan == 5 ||  input_kendaraan == 6 || input_kendaraan == 7 ){			
			do{
				cout << "Tanggal merental(dd/mm/yy)\t\t\t: " << endl;
				cout << "hari\t: "; cin >> day;
				cout << "bulan\t: "; cin >> month;
				cout << "tahun\t: "; cin >> year;
				cout << "Berapa lama merental\t\t\t\t: ";
				cin >> rental;
				cin.ignore();
				syarat_check(day, month, year, syarat_tanggal);			
			} while (syarat_tanggal == false);
			lama_rental[id] = rental;
			hari_check_in[id] = day;
			bulan_check_in[id] = month;
			tahun_check_in[id] = year;
			tanggal(day, month, year, rental);
			hari_out[id] = day;
			bulan_out[id] = month;
			tahun_out[id] = year;
			cout << "Tanggal wajib check out(dd/mm/yy)\t\t: ";
			cout << hari_out[id] << "/" << bulan_out[id] << "/" << tahun_out[id] << endl;		
			
			if (input_kendaraan == 1){
				tesla_s--;
				kendaraan = "Mobil Tesla Model S";
				harga[id] = 3600000;
			}else if (input_kendaraan == 2){
				tesla_x--;
				kendaraan = "Mobil Tesla Model X";
				harga[id] = 1500000;
			}else if (input_kendaraan == 3){
				honda_crv--;
				kendaraan = "Mobil Honda CRV";
				harga[id] = 460000;
			}else if (input_kendaraan == 4){
				honda_brio--;
				kendaraan = "Mobil Honda Brio";
				harga[id] = 200000;
			}else if (input_kendaraan == 5){
				daihatsu_xenia--;
				kendaraan = "Mobil Daihatsu Xenia";
				harga[id] = 200000;
			}else if (input_kendaraan == 6){
				toyota_gat--;
				kendaraan = "Mobil Toyota GA/T";
				harga[id] = 110000;
			}else if (input_kendaraan == 7){
				mercedes_c--;
				kendaraan = "Mobil Mercedes C Class";
				harga[id] = 950000;
			}
			harga_mobil[id] = harga[id];
			kendaraan_pelanggan[id] = kendaraan;
		}else {
			cout << "Input yang anda masukkan salah" << endl;
			id--;
		}
	cout << "Ingin Merental lagi (y/n) ? ";
	cin >> pesan; 
	cin.ignore();
	cout << "===========================================================" << endl;
	system("pause");
	
	}while (pesan =="y" || pesan == "Y");
	pembayaran(nama_pelanggan, password, kendaraan_pelanggan, lama_rental, harga_mobil, harga, batas, id);
}

void pembayaran(string *nama_pelanggan, string *password, string *kendaraan_pelanggan, int *lama_rental, int *harga_mobil, int *harga, int &batas, int &id){
	int kelipatan_diskon, pembayaran; 
	float diskon;
	long int total_pembayaran, kembalian, nominal_diskon;
	int harga_sementara =0;
	system("cls");
	cout << "\t\t\t\t+---------------------------------------------------+" << endl;
	cout << "\t\t\t\t||" << setw(34) << "STRUCK PEMBAYARAN" << setw(17) << "||" << endl;
	cout << "\t\t\t\t+---------------------------------------------------+" << endl;
	cout << "\t\t\t\t1. Nama Pembeli\t: " << nama_pelanggan[id] << endl;
	cout << "\t\t\t\t2. Tabel Pembayaran" << endl << endl;
	cout << "\t+========================================================================================================+" << endl;
	cout << "\t|" << setw(27) << "Jenis Mobil" << setw(15) << "|" << setw(14) << "Lama Rental" << setw(4) << "|" << setw(13) << "Harga/Hari" << setw(5) << "|" << setw(15) << "Total Harga" << setw(5) << "|" << setw(4) << "ID" << setw(3) << "|" << endl;
	cout << "\t+========================================================================================================+" << endl;
	
	for(int i=batas; i<=id; i++){
		cout << "\t|" << setw(32) << kendaraan_pelanggan[i] << setw(10);
		cout << "|" << setw(15) << lama_rental[i] << setw(3);
		cout << "|" << setw(15) << harga[i] << setw(3);
		harga_mobil[i] = harga[i]*lama_rental[i];
		cout << "|" << setw(17) << harga_mobil[i] << setw(3);
		cout << "|" << setw(4) << i << setw(3) << "|";
		harga_sementara += harga_mobil[i];  cout << endl;
		cout << "\t+--------------------------------------------------------------------------------------------------------+" << endl;
	}
	batas = id+1;
	cout << "\t| Harga Sebelum Diskon = " << harga_sementara << setw(74) << "|" << endl;
	cout << "\t+========================================================================================================+" << endl;
	
	kelipatan_diskon = harga_sementara/1000000;
	diskon = kelipatan_diskon*2.0/100;
	
	if (diskon >= 0.2){
		diskon = 0.2;
	}
		
	nominal_diskon = diskon*harga_sementara;
	total_pembayaran = harga_sementara-nominal_diskon;
	
	cout << "\n\t\t\t\t----------------------------------------------------\n" << endl;
	cout << "\t\t\t\tTotal Harga\t\t\t: " << total_pembayaran << " Rupiah" << endl;
	cout << "\n\t\t\t\t---------------(Diskon 2,0% per 1jt)---------------\n" << endl;	
			
	cout << "\t\t\t\tPresentase Diskon\t\t: " << diskon*100 << "%" << endl; 
	cout << "\t\t\t\tNominal Diskon\t\t\t: " << nominal_diskon << " Rupiah" << endl;
	cout << "\t\t\t\tTotal Pembayaran Setelah Diskon\t: " << total_pembayaran << " Rupiah" << endl;
	cout << "\n\t\t\t\t----------------------------------------------------\n" << endl;
	do{	
		cout << "\t\t\t\tJumlah Uang yang Dibayarkan\t: ";
		cin >> pembayaran;
		cin.ignore ();
		kembalian = pembayaran - total_pembayaran;
	
		if (pembayaran >= total_pembayaran){
			cout << "\t\t\t\tJumlah kembalian\t\t: " << kembalian << " Rupiah" << endl;
			cout << "\n\t\t\t\t----------------------------------------------------\n" << endl;

			system("pause");
			system("cls");		
			} else {
				cout << "\n\t\t\t\tUang yang dibayarkan kurang !" << endl;
				system("pause");
			}
	}while (pembayaran < total_pembayaran);
}

void syarat_check(int day, int month, int year, bool &syarat_tanggal){
	bool ly = is_LeapYear(year);
	if(year<MIN_YEARS || year>MAX_YEARS){
		syarat_tanggal = false;
	} else if(month<1 || month > 12){
		syarat_tanggal = false;
	} else if((day > 29) && (month == 2) && (ly == true)){
		syarat_tanggal = false;
	} else if((day > 28) && (month == 2) && (ly == false)){
		 syarat_tanggal = false;
	} else if(month != 2 && (day<1 || day > month_day[month-1])){
		syarat_tanggal = false;
	} else {
		syarat_tanggal = true;
	}
}

void tanggal(int &day, int &month, int &year, int &rental){
	int d_max; 
	int m_max = 12;
	day += rental;
	bool ly = is_LeapYear(year);
	if (month != 2){
		d_max = month_day[month-1];
	} else{
		if (ly == false){
			d_max = 28;
		}else{
			d_max = 29;
		}
	}

	int days = add_day(day, month, d_max);
	int months = add_month(month, year, m_max);
	day = days;
	month = months;
	year = year;
}

int add_day(int day, int &month, int d_max){
	if(day <= d_max){
		return day;
	}else {
		return add_day(day-d_max, ++month, d_max);
	}
}

int add_month(int month, int &year, int m_max){
	if(month <= m_max){
		return month;
	}else {
		return add_month(month-m_max, ++year, m_max);
	}
}

bool is_LeapYear(int year){
	if(year%400 == 0){
		return true;
	} else if(year%100 == 0){
		return false;
	} else if(year%4 == 0){
		return true;
	} else {
		return false;
	}
}

void Check_Out(string *nama_pelanggan, string *password, int *hari_out, int *bulan_out, int *tahun_out, int *hari_check_out, int *bulan_check_out, int *tahun_check_out, int *harga_mobil, string *kendaraan_pelanggan, int &id){
	string user, pw, lagi;
	int ids;
	bool syarat_user, syarat_pw, syarat_id;
	do{
		system("cls");
		cout << "+------------------------------------------------+" << endl;
		cout << "|" << setw(42) << "SILAHKAN CHECK OUT MOBIL RENTAL ANDA" << setw(7) << "|" << endl;
		cout << "+------------------------------------------------+" << endl;
		
		cout << "Masukkan username anda\t: ";
		getline(cin, user);
		cout << "Masukkan password anda\t: ";
		getline(cin, pw);
		
		for(int i=1; i<=id; i++){
			if(nama_pelanggan[i] == user){
				syarat_user = true;
			} else{
				syarat_user = false;
			}
			if(password[i] == pw){
				syarat_pw = true;
			} else{
				syarat_pw = false;
			}
			if(syarat_user == true){
				break;
			}
		}
		
		if(syarat_user == true && syarat_pw == false){
			cout << "Paswword anda salah" << endl;
		} else if(syarat_user == true && syarat_pw == true){
			cout << "Login Berhasil" << endl;	
				do{
					system ("pause");
					system ("cls");
					cout << "+===========================================================+" << endl;
					cout << "|" << setw(40) << "CHECK OUT RENTAL MOBIL" << setw(20) << "|" << endl;
					cout << "+===========================================================+" << endl;
					cout << "Masukkan id rental mobil anda\t: ";
					cin >> ids;
					cin.ignore();
					for(int i=1; i<=id; i++){
						if(i == ids && user == nama_pelanggan[i]){
							syarat_id = true;
						} else{
							syarat_id = false;
						}
						if(syarat_id == true){
							break;
						}	
					}
				}while(syarat_id == false);
			
			count_punishment(hari_out, bulan_out, tahun_out, hari_check_out, bulan_check_out, tahun_check_out, harga_mobil, kendaraan_pelanggan, id, ids);
		} else{
			cout << "username atau password anda belum terdaftar atau salah" << endl;
			cout << "pilih register untuk mendaftar" << endl;					
		}
		
		cout << "Login lagi ? (y/n) ";
		getline(cin, lagi);
		system("pause");
	} while(lagi == "y" || lagi == "Y");
	 
}

void count_punishment(int *hari_out, int *bulan_out, int *tahun_out, int *hari_check_out, int *bulan_check_out, int *tahun_check_out, int *harga_mobil, string *kendaraan_pelanggan, int &id, int &ids){
	int day, month, year, day1, month1, year1, kembalian;
	long int denda, dendas;
	bool syarat_tanggal = true;
	long int day_diff=0;
	do{
		cout << "Tanggal Check Out(dd/mm/yy)\t\t\t: " << endl;
		cout << "hari\t: "; cin >> day;
		cout << "bulan\t: "; cin >> month;
		cout << "tahun\t: "; cin >> year;
		cin.ignore();
		syarat_check(day, month, year, syarat_tanggal);
	} while(syarat_tanggal == false);
	hari_check_out[ids] = day; 
	bulan_check_out[ids] = month;
	tahun_check_out[ids] = year;
	
	if(kendaraan_pelanggan[ids]=="Mobil Tesla Model S"){
		tesla_s++;
	}else if(kendaraan_pelanggan[ids]=="Mobil Tesla Model X"){
		tesla_x++;
	}else if(kendaraan_pelanggan[ids]=="Mobil Honda CRV"){
		honda_crv++;
	}else if(kendaraan_pelanggan[ids]=="Mobil Honda Brio"){
		honda_brio++;
	}else if(kendaraan_pelanggan[ids]=="Mobil Daihatsu Xenia"){
		daihatsu_xenia++;
	}else if(kendaraan_pelanggan[ids]=="Mobil Toyota GA/T"){
		toyota_gat++;
	}else if(kendaraan_pelanggan[ids]=="Mobil Mercedes C Class"){
		mercedes_c++;
	}
	
	day1 = hari_out[ids];
	month1 = bulan_out[ids];
	year1 = tahun_out[ids];
	
	if(year>year1){
		if(month1==2){
			if(is_LeapYear(year1) == true){
				day_diff += 29- day1;
			}else {
				day_diff += 28 - day1;
			}
		}else {
			day_diff = month_day[month1-1] - day1;
		}
		month1++;

		for(int i=month1;i<=12;i++){
			if(i==2){
				if(is_LeapYear(year1) == true){
					day_diff += 29;
				}else {
					day_diff += 28;
				}
			}else {
				day_diff += month_day[i-1];
			}
        }
		year1++;

		for(int i=year1;i<year;i++){
			if(is_LeapYear(i) == true){
				day_diff += 366;
			}else {
				day_diff += 365;
			}
		}

		for(int i=1;i<month;i++){
			if(i==2){
				if(is_LeapYear(year) == true){
					day_diff += 29;
				}else {
					day_diff += 28;
				}
				}else {
					day_diff += month_day[i-1];
				}
		}

		day_diff += day;

	}else if(year1==year){
		if(month>month1){
			if(month1==2){
				if(is_LeapYear(year1)==true){
					day_diff += 29- day1;
				}else {
					day_diff += 28 - day1;
				}
			} else {
				day_diff = month_day[month1-1] - day1;
			}
			month1++;
			for(int i=month1;i<month;i++){
				if(i==2){
					if(is_LeapYear(year1)==true){
						day_diff += 29;
					}else {
						day_diff += 28;
					}
				}else {
					day_diff += month_day[i-1];
				}
			}
			day_diff += day;
		}else if(month1==month){
			if(day>day1){
				day_diff = day - day1;
			}else if(day1==day){
				day_diff = 0;
			}
		}
	}
	cout << "Keterlambatan\t: " << day_diff << endl;
	
	if(day_diff > 0){
		do{
			cout << "Anda telat mengembalikan, Anda mendapatkan denda!!!" << endl;
			cout << "denda yang diberikan sebesar harga mobil * lama rental * lama keterlambatan" << endl;
			denda =  harga_mobil[ids]*day_diff;
			cout << "Anda mendapat denda sebesar Rp" << denda << ",Silahkan dibayar!" << endl;
			cout << "Masukkan nominal\t: ";
			cin >> dendas;
			cin.ignore();
		}while (denda > dendas);
			kembalian = dendas-denda;
			cout << "kembalian anda Rp. " << kembalian  << endl;
	}else{
		cout << "Terima kasih karena mengembalikan tidak telat :)" << endl;
	}
}

void Informasi(string *nama_pelanggan, string *kendaraan_pelanggan, int *lama_rental, int *harga_mobil, int *hari_check_in, int *bulan_check_in, int *tahun_check_in,  int *hari_out, int *bulan_out, int *tahun_out, int *hari_check_out, int *bulan_check_out, int *tahun_check_out, int &id){
	system("cls");
	cout << "+----------------------------------------------------------+" << endl;
	cout << "|" << setw(51) << "SILAHKAN REGISTRASI MOBIL YANG AKAN DIRENTAL" << setw(8) << "|" << endl;
	cout << "+----------------------------------------------------------+" << endl << endl;
	
	cout << "+======================================================================================================+" << endl;
	cout << "|" << setw(19) << "Nama Pelangan" << setw(7) << "|" << setw(25)<< "Kendaraan Yang Dirental" << setw(3) << "|" << setw(11) << "Check In" << setw(4) << "|" << setw(12) << "Check Out" << setw(4) << "|" << setw(16) << "Wajib Check Out" << setw(2) << "|" << endl;	
	for (int i=1; i<=id; i++){
		cout << "+======================================================================================================+" << endl;

		cout << "| " << setw(23) << nama_pelanggan[i];
		cout << " | " << setw(25) << kendaraan_pelanggan[i];
		cout << " | " << setw(4) << hari_check_in[i];
		cout << "/" << setw(2) << bulan_check_in[i];
		cout << "/" << setw(4) << tahun_check_in[i];
		
		cout << " | " <<  setw(5) << hari_check_out[i];
		cout << "/" << setw(2) << bulan_check_out[i];
		cout << "/" << setw(4) << tahun_check_out[i];
		
		cout << " | " << setw(7) << hari_out[i];
		cout << "/" << setw(2) << bulan_out[i];
		cout << "/" << setw(4) << tahun_out[i];
		cout << " |";
		cout << endl;
	}
	cout << "+======================================================================================================+" << endl;
	system("pause");
}
