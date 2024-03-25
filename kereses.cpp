//Herczeg Martinez OV1GNP
#include <iostream> //cin és cout 
#include <fstream> // fileba irás olvasás
#include <string>
#include <list> //lista használata

using namespace std;

//txt : marka, nev, evjarat, tipus, rendszam
struct Gepjarmuvek
{
    string marka;
    string nev;
    string evjarat; // stoi-val string conversion hibát adott ki
    string tipus;
    string rendszam;

    //Valamiért az strtok nem müködött ezért van
    string Split (string s,int num,char tores){
        int seged =0;
        string megadni="";
        //végig megy a string-en
        for(int i=0; i<s.length();i++){
            if(s[i] == tores){
                seged++;
            }
            //csak a megadottat olvassabe
            if(seged == num){
                if(s[i] != ';'){
                    megadni+= s[i];
                }
               
            }
            // Amikor a kért rész megvan akkor megállítja
            else if(seged>num){ break;}
        }
        return megadni;
    }
    
    //Konstruktor
    Gepjarmuvek(string sor) {
        marka = Split(sor, 0, ';');
        nev = Split(sor,1,';');
        evjarat = Split(sor,2,';');
        tipus = Split(sor,3,';');
        rendszam = Split(sor,4,';');

    };
};

list<Gepjarmuvek> lista;
string filename = "GepjarmuAdatok.txt"; //beolv file
ifstream FileOlv; 

//File beolvasása és letárolása structba
void Beolvasas(){
    FileOlv.open(filename);
    string line = " ";
    //a fájl végéig olvas
    while(getline(FileOlv,line, '\n')){
        lista.push_back(line);
    }
    FileOlv.close();
}
void Kiir(){
    int hanyadik =0;
    for(auto i : lista){
        cout << ++hanyadik << endl;
        cout<< "-------------------------" << endl;
        cout << i.marka << " " << i.nev  << endl;
        cout << "Motor: " << i.tipus<< endl;
        cout << "Rendszám: " << i.rendszam << endl;
        cout<< "-------------------------" << endl;
    }
}

int main(){
    Beolvasas();
    Kiir();
    return 0;
}