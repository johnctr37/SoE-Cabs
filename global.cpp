#include "global.h"
#include <QString>
#include <QMessageBox>

int Book_a_cab::check_cab_status(){
    for(int i=0;i<no_of_cabs;i++){
        if(cabs[i] == 1){
            return 1;
        }
    }
    return 0;
    }
void Book_a_cab::Cab_availability_info(){
    for(int i = 0 ;i<no_of_cabs;i++){
        if(cabs[i] == 1){

        }
    }
}

Book_a_cab a;
int charge_per_km = 6;

