#include <iostream>
using namespace std;

namespace DBErrors{
    class SQLException {};
    class KeyException : public SQLException {};
    class PrimaryKeyException : public KeyException {};
    class ForeignKeyException : public KeyException {};

    class DBCon{
        public: static void print_err(int eno = 0){
            try{
                if(eno==0)
                    throw PrimaryKeyException();
                else if(eno < 0)
                    throw ForeignKeyException();
                else if(eno>0 && eno<5)
                    throw KeyException();
                else
                    throw SQLException();
            }
            catch(KeyException&){ cout << "DBErrors::KeyException";}
        }
    }; // end of the class here GEEEEZ
}

int main(){
    try{
        DBErrors::DBCon::print_err(123);
        //LINE-1
        // figure line-1 out such that output is NOT DBErrors::KeyException
    }
    catch(DBErrors::PrimaryKeyException&) {cout << "DBErrors::PrimaryKeyException&";}
    catch(DBErrors::ForeignKeyException&) {cout << "DBErrors::ForeignKeyException&";}
    // catch(DBErrors::SQLException&) {cout << "DBErrors::SQLExceptionWEHWD";}
    catch(DBErrors::SQLException) {cout << "DBErrors::HEHEHE";}
    return 0;
}