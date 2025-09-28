#include "contact.h"   
// Dummy contact data
static Contact dummyContacts[] = {
    {1,"Ajinkya Kadam","9356773090","ajinkya18@gmail.com","Sangli"}, 
    {2,"Jinesh Chougule", "7666908710", "jinesh17@gmail.com","Sangli"},
    {3,"Pankaj Patil","7276723799","pankaj07@gmail.com","Ichalkaranji"},
    {4,"Rohit Mali", "8600385974", "rohit18@gmail.com","Ichalkaranji"},
    {5,"Aniket Deshmukh", "8806833571", "aniket45@gmail.com","Thane"},
    {6,"Shantanu Pakhare", "7447522148", "shantanu@gmail.com","Sangli"},
    {7,"Jaydatta Patil","8767353633","jaydatta@gmail.com","Ichalkaranji"},
    {8,"Sushil Patil","9325881904","sushil@gmail.com","Ichalkaranji"},
    {9,"Pankaj Patil", "9876543210", "panku07@gmail.com","Ichalkaranji"},
    {10,"Jinesh Chougule", "9175357511", "jinu17@gmail.com","Sangli"},
    {11,"Ashish Kothale", "8767292029", "ashish45@gmail.com","Sangli"},
};
void initialize(AddressBook *addressBook) 
{
    // assign 0 to addressBook->contactCount
    // cal size of dummyContacts (10)
    // run a loop for size of dummyContacts (10 time)
        // 1. copy dummyContacts[index] to addressbook->contacts[index]
        // 2. inc (addressBook->contactCount)++   
    addressBook->contactCount=0;
    int size = sizeof(dummyContacts) / sizeof(dummyContacts[0]);
    // printf("%d\n",size);
    for(int i=0;i<size;i++)
    {
        // addressBook->sr = (addressBook->contactCount)+1;
        addressBook->contacts[i]=dummyContacts[i];
        (addressBook->contactCount)++;
    }
}