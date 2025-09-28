#include "contact.h"

int main()
{
    AddressBook addressbook;
    load_contacts(&addressbook);
    // initialize(&addressbook);
    int option;
    do
    {
        printf("Address Book Menu:\n1. List Contacts\n2. Create Contact\n3. Search Contact\n4. Edit Contact\n5. Delete Contact\n6. Save\n7. Exit\n");
        printf("Enter the option: ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            listContacts(&addressbook);
            break;
        case 2:
            createContact(&addressbook);
            break;
        case 3:
            searchContact(&addressbook);
            break;
        case 4:
            editContact(&addressbook);
            break;
        case 5:
            deleteContact(&addressbook);
            break;
        case 6:
            save_contacts(&addressbook);
            printf("---------------Changes saved successfully---------------\n\n");
            break;
        case 7:
            printf("Exiting AddressBook!\n");
            printf("\n---------------Thank you---------------\n");
            break;
        default:
            printf("Enter valid option.\n");
            break;
        }
    } while (option!=7);
    return 0;
}
