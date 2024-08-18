#ifndef GLOBAL_H
#define GLOBAL_H
#define no_of_cabs 5

#include <QString>

class Book_a_cab
{
    int cabs[no_of_cabs];
public:
    Book_a_cab(){
        for(int i = 0;i<no_of_cabs;i++){
            cabs[i] = 1;
        }
    }

    int check_cab_status();
    void Booking(Book_a_cab);
    void Cab_availability_info();
    friend class Customer_services;
    friend class Admin_services;
    friend class bookingdestopt;
    friend class PaymentConfirmation;
    friend class Update_cab_status;
};

extern Book_a_cab a;
extern int charge_per_km;


#endif // GLOBAL_H
