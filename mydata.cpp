//https://tio.run/#

#include <iostream>
#include <cstring>

//Struct class
class Struct {
    char* username;
    char* password;
    char* fname;
    char* lname;
    unsigned int id;

public:

    Struct() = default;
    //setter functions
    void setUsername (const char wusername[]) {
        int len = strlen(wusername);
        char* pusername = new char[len+1];
        for(int i = 0; i < len; i++){
            *(pusername+i) = wusername[i];
        }
        username = pusername;
    }

    void setPassword (const char wpassword[]) {
        int len = strlen(wpassword);
        char* ppassword = new char[len+1];
        for(int i = 0; i < len; i++){
            *(ppassword+i) = wpassword[i];
        }
        password = ppassword;
    }

    void setFirstname (const char wfname[]){
        int len = strlen(wfname);
        char* pfname = new char[len+1];
        for(int i = 0; i < len; i++){
            *(pfname+i) = wfname[i];
        }
        fname = pfname;
    }

    void setLastname (const char wlname[]){
        int len = strlen(wlname);
        char* plname = new char[len+1];
        for(int i = 0; i < len; i++){
            *(plname+i) = wlname[i];
        }
        lname = plname;
    }

    void setID (unsigned int wid){
        id = wid;
    }



    //getter functions
    char* getUsername () {
        return username;
    }

    char* getPassword () {
        return password;
    }

    unsigned int getID () {
        return id;
    }
};




// Table class
class Table {
    Struct* tbstruct[10];
    static unsigned int HiddenID;

public:

    Table () = default;

    void addNew (const char wusername[], const char wpassword[], const char wfname[], const char wlname[]) {
        ++HiddenID;

        tbstruct[HiddenID-1] = new Struct();

        tbstruct[HiddenID-1]->setID(HiddenID);
        tbstruct[HiddenID-1]->setUsername(wusername);
        tbstruct[HiddenID-1]->setPassword(wpassword);
        tbstruct[HiddenID-1]->setFirstname(wfname);
        tbstruct[HiddenID-1]->setLastname(wlname);

        tbstruct[(HiddenID - 1)]->setID(HiddenID);
    }

    void updateUname (const char wusername[], unsigned int wid) {
        tbstruct[(wid - 1)]->setUsername(wusername);

    }
    void updatePass (const char wpassword[], unsigned int wid) {
        tbstruct[(wid - 1)]->setPassword(wpassword);

    }

    char* getUname (unsigned int wid) {
        return tbstruct[(wid - 1)]->getUsername();
    }

    char* getPass (unsigned int wid) {
        return tbstruct[(wid - 1)]->getPassword();
    }
};





class DataBase{
    char* usernameDB = new char[5]{'r','o','o','t'};
    char* passwordDB = new char[16]{'s','r','2','4','f','a','r','5','v','o','w','b','8','y','i'};
    bool sign = false;
    Table table;
public:
    DataBase() = default;

    void login (const char wusernameDB[], const char wpasswordDB[]) {
        int a = 0;
        int b = 0;

        for (int i = 0; i < 4; i++) {
            if (usernameDB[i] == wusernameDB[i]) {
                a++;
            }
        }
        for (int i = 0; i < 15; i++) {
            if (passwordDB[i] == wpasswordDB[i]) {
                b++;
            }
        }

        if(a == 4 && b == 15){
            sign = true;
        }else{
            std::cout<<"Wrong Password!\n";
        }
    }

    void addNew (const char wusername[], const char wpassword[], const char wfname[], const char wlname[]) {
        if(sign == true){
            table.addNew(wusername, wpassword, wfname, wlname);
        }
    }

    char* getPass(unsigned int wid) {
        if (sign == true) {
            return table.getPass(wid);
        }
    }

    char* getUname(unsigned int wid) {
        if (sign == true) {
            return table.getUname(wid);
        }
    }







};




//main
unsigned int Table::HiddenID = 0;

int main(){

    DataBase db;
    db.login("root", "sr24far5vowb8yi");
    db.addNew("samir12","salam313", "Samir", "Hasanli");
    db.addNew("irland2","jkiro", "Irland", "Grop");
    db.addNew("alop24","tryapo21", "Alop" , "Opera");

    //db.getUname(2);
    std::cout << db.getUname(2);
    return 0;
}
