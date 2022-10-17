#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

string namee; /*Name eingabe */
string namep; /*vergleicher*/
fstream sp; /*spieler datei*/
fstream version; /*vergleicher*/
fstream passwda; /*passwd abfrage*/
string versiono; /*vergleicher*/
int Befehl(); /*funkton*/
string Befehlein; /**/
int i; /*schleifen zähler*/
string passwd;/*gib es ein passwd*/
string Wort;
int j;
map<string, string> passmap;
int Passwortdata();

int main() {
	string erstellt;
/*

LOGIN

*/

	cout << "Haben sie schon einen acount?" << endl;
	cin >> erstellt;
	if (erstellt == "nein" ) {
		cout << "Geben ihren Namen ein:" << endl;
		cin >> Wort;
		sp.open("alloa.txt",ios::app);
		sp << "\n" << Wort;
		sp.close();
	}
	else if(erstellt == "ja"){
		cout << "wie ist ihr name?\n";
		cin >> namee;
		sp.open("alloa.txt",ios::in);
		while (namee != namep) {
			namep="";
			getline(sp, namep);
		}

		/*
		Passwd abfrage
		*/
		passwda.open("passwd.txt",ios::in);
		while (!passwda.eof()) {
			while (passwd != namee) {
				passwd="";
				getline(passwda, passwd);

			}
			Passwortdata();
		}
		j = 1;
		/*
		WIRD GEMACHT
		*/
		cout << "Du bist eingelogt\n";
		while (i != 1) {
		Befehl();
		}
	}
return 0;
}

int Befehl(){
	cin >> Befehlein;
	if (Befehlein == "zeige -v" || "zg -v") {
		version.open("/etc/issue",ios::in);
		getline(version, versiono);
		std::cout << versiono << endl;
	}
	return 0;
}

int Passwortdata(){
		passmap.insert(make_pair("Elijas", "Computer"));
}
