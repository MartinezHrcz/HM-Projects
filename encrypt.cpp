// Herczeg Martinez OV1GNP
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

//Titkosítandó file
string filename = "FileTitkos.txt";
//kulcs
string encKey= "";

ofstream FileIras;
ifstream Fileolv;

//Titkosításra használt kulcsot generálja le
void GenerateEncryptionKey(int hossz){
    int random;
    //a pillanatnyi idő --> seed a random számoknak
    time_t curr_time = time(NULL);
    srand(curr_time);
    for(int i =0; i < hossz; i++){
        random = rand()%128;
        //titkosító kulcs
        encKey+=char(random);
    }   
}
//Soronkénti titkosít 
string XORencryption(string sor){
    int inkey=0;
    //végig megy a sor elemein
    for(int i=0; i < sor.length();i++){   
        //kulcs elemein végig megy 
        if(inkey == encKey.length()){
            //vissza az elejére
            inkey=0;
        }
        sor[i] = char(sor[i] ^ encKey[inkey]) ;
        // Vissza fejtéshez csak egy második XoR kell
        //sor[i] = char(char(sor[i] ^ encKey[inkey]) ^ encKey[inkey]) ;
        inkey++;
    }
    return sor;
}

void Filebeolvasas(){
    Fileolv.open(filename);
    FileIras.open("encryptedFile.txt");
    string line = "";
    //File végéig megy
    while (getline(Fileolv,line))
    {
        FileIras << XORencryption(line) << "\n";
    }
    FileIras.close();
    Fileolv.close();
}

int main(){
    //A kulcs méretét adjuk meg
    GenerateEncryptionKey(3);
    //File beolvasás és letitkosítása külön fájlba
    Filebeolvasas();
    return 0;
}