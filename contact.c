#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
    //define
    printf("---------------Contact list---------------\n");
    printf("Sr.\tName\t\t\tPhone\t\tEmail\t\t\t\tAddress\n\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%-7d %-23s %-15s %-31s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
    }
    printf("---------------Exiting Contact list---------------\n\n");
}

void createContact(AddressBook *addressBook) 
{
    printf("\n----------Create Contact----------\n");
    char name[50],phone[20],email[50],address[50];
    printf("Enter the Name: ");
    scanf(" %[^\n]",name);
    validate_name(addressBook,name);
    printf("Enter the Contact number: ");
    scanf(" %[^\n]",phone);
    validate_phone(addressBook,phone);
    search_phone(addressBook,phone);
    printf("Enter the Email id: ");
    scanf(" %[^\n]",email);
    validate_email(addressBook,email);
    search_email(addressBook,email);
    printf("Enter the Address: ");
    scanf(" %[^\n]",address);
    validate_address(addressBook,address);
    addressBook->contacts[addressBook->contactCount].sr = (addressBook->contactCount)+1;
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);
    strcpy(addressBook->contacts[addressBook->contactCount].address, address);
    (addressBook->contactCount)++;
    printf("Contact created Successfully.\n");
    printf("\n---------------Exiting Create Contact---------------\n\n");
}

void searchContact(AddressBook *addressBook) 
{
    printf("\n----------Search Contact----------\n");
    char name[50],phone[20],email[50],address[50];
    int op;
    do
    {
        printf("Choose option to search: \n1. Search by Name\n2. Search by Phone\n3. Search by Email\n4. Search by Address\n5. for Exit\nEnter the option: "); 
        scanf("%d",&op); 
        switch (op)
        {
        case 1:
            int flag1=0;
            printf("Enter the Name to search: ");
            scanf(" %[^\n]",name);
            validate_name(addressBook,name);
            for(int i=0;i<addressBook->contactCount;i++){
                if(strstr(addressBook->contacts[i].name,name)!=NULL){
                    flag1=1;
                    printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                }
            }
            if(flag1==0){
                printf("Not found.\n");
            }
            break;

        case 2:
            int flag2=0;
            printf("Enter the Phone number to search: ");
            scanf(" %[^\n]",phone);
            validate_phone(addressBook,phone);
            for(int i=0;i<addressBook->contactCount;i++){
                if(strcmp(addressBook->contacts[i].phone,phone)==0){
                    printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                    flag2=1;
                }
            }
            if(flag2==0){
                printf("Not found.\n");
            }
            break;

        case 3:
            int flag3=0;
            printf("Enter the Email id to search: ");
            scanf(" %[^\n]",email);
            validate_email(addressBook,email);
            for(int i=0;i<addressBook->contactCount;i++){
                if(strcmp(addressBook->contacts[i].email,email)==0){
                    printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                    flag3=1;
                }
            }
            if(flag3==0){
                printf("Not found.\n");
            }
            break;

        case 4:
            int flag4=0;
            printf("Enter the Address to search: ");
            scanf(" %[^\n]",address);
            validate_address(addressBook,address);
            for(int i=0;i<addressBook->contactCount;i++){
                if(strstr(addressBook->contacts[i].address,address)!=NULL){
                    printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                    flag4=1;
                }
            }
            if(flag4==0){
                printf("Not found.\n");
            }
            break;

        case 5:
            printf("\n---------------Exiting Search Contact---------------\n\n");
            break;
        
        default:
            printf("Invalid input.\n");
            break;
        }
    }while(op!=5);
}

void editContact(AddressBook *addressBook) 
{
    printf("\n----------Edit Contact----------\n");
    char name[50],phone[20],email[50],address[50];
    int op,count=0;
    do
    {
        printf("Choose option to Edit: \n1. Search Name to Edit\n2. Search Phone to Edit\n3. Search Email to Edit\n4. Search Address to Edit\n5. Exit\nEnter the option: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            count=0;
            printf("Search Name to Edit: ");
            scanf(" %[^\n]",name);
            validate_name(addressBook,name);
            for(int i=0;i<addressBook->contactCount;i++){
                if(strstr(addressBook->contacts[i].name,name)!=0){
                    count++;
                }
            }
            if(count==1){
                edit_contact(addressBook,name,count);
            }
            else if(count>1){
                edit_contact(addressBook,name,count);
            }
            else if(count==0){
                printf("Not found.\n");
            }
            break;

        case 2:
            count=0;
            printf("Search Phone to Edit: ");
            scanf(" %[^\n]",phone);
            validate_phone(addressBook,phone);
            for(int i=0;i<addressBook->contactCount;i++){
                if(strcmp(phone,addressBook->contacts[i].phone)==0){
                    count++;
                }
            }
            if(count==1){
                edit_contact(addressBook,phone,count);
            }
            else if(count>1){
                edit_contact(addressBook,phone,count);
            }
            else if(count==0){
                printf("Not found.\n");
            }
            break;

        case 3:
            count=0;
            printf("Search Email id to Edit: ");
            scanf(" %[^\n]",email);
            validate_email(addressBook,email);
            for(int i=0;i<addressBook->contactCount;i++){
                if(strcmp(email,addressBook->contacts[i].email)==0){
                    count++;
                }
            }
            if(count==1){
                edit_contact(addressBook,email,count);
            }
            else if(count>1){
                edit_contact(addressBook,email,count);
            }
            else if(count==0){
                printf("Not found.\n");
            }
            break;

        case 4:
            count=0;
            printf("Search Address to Edit: ");
            scanf(" %[^\n]",address);
            validate_address(addressBook,address);
            for(int i=0;i<addressBook->contactCount;i++){
                if(strcmp(addressBook->contacts[i].address,address)==0){
                    count++;
                }
            }
            if(count==1){
                edit_contact(addressBook,address,count);
            }
            else if(count>1){
                edit_contact(addressBook,address,count);
            }
            else if(count==0){
                printf("Not found.\n");
            }
            break;

        case 5:
            printf("\n---------------Exiting Edit Contact---------------\n\n");
            break;

        default:
            printf("Invalid input.\n");
            break;
        }

    }while(op!=5);

}

void deleteContact(AddressBook *addressBook) 
{
    printf("\n----------Delete Contact----------\n");
    char name[50],phone[20],email[50],address[50];
    int count=0,op;
    do
    {
        printf("Choose option to Delete: \n1. Delete by Name\n2. Delete by Phone\n3. Delete by Email id\n4. Delete by Address\n5. for Exit\nEnter the option: "); 
        scanf("%d",&op); 
        switch (op)
        {
            case 1:
                count=0;
                printf("Enter the Name to delete Contact: ");
                scanf(" %[^\n]",name);
                validate_name(addressBook, name);
                for(int i=0;i<addressBook->contactCount;i++){
                    if(strstr(addressBook->contacts[i].name,name)!=NULL){
                        count++;
                    }
                }
                if(count==1){
                    delect_contact(addressBook,name,count);   
                }
                else if(count>1){
                    delect_contact(addressBook,name,count);
                }
                else{
                    printf("Contact not found.\n");
                }
                break;

            case 2:
                count=0;
                printf("Enter the Phone to delete Contact: ");
                scanf(" %[^\n]",phone);
                validate_phone(addressBook, phone);
                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcmp(addressBook->contacts[i].phone,phone)==0){
                        count++;
                    }
                }
                if(count==1){
                   delect_contact(addressBook,phone,count); 
                }
                else if(count>1){
                    delect_contact(addressBook,phone,count);
                }
                else{
                    printf("Contact not found.\n");
                }
                break;

            case 3:
                count=0;
                printf("Enter the Email id to delete Contact: ");
                scanf(" %[^\n]",email);
                validate_email(addressBook, email);
                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcmp(addressBook->contacts[i].email,email)==0){
                        count++;
                    }
                }
                if(count==1){
                    delect_contact(addressBook,email,count);
                }
                else if(count>1){
                    delect_contact(addressBook,email,count);
                }
                else{
                    printf("Contact not found.\n");
                }
                break;

            case 4:
                count=0,count=0;
                printf("Enter the Address to delete Contact: ");
                scanf(" %[^\n]",address);
                validate_address(addressBook, address);
                for(int i=0;i<addressBook->contactCount;i++){
                    if(strcmp(addressBook->contacts[i].address,address)==0){
                        count++;
                    }
                }
                if(count==1){
                    delect_contact(addressBook,address,count);
                }
                else if(count>1){
                    delect_contact(addressBook,address,count);
                }
                else{
                    printf("Contact not found.\n");
                }
                break;

            case 5:
                printf("\n---------------Exiting Delete Contact---------------\n\n");
                break;

            default:
                printf("Invalid input.\n");
                break;
        }
    }while(op!=5);
}

void validate_name(AddressBook *addressBook, char name[])
{
    int flag=0;
    for(int i=0;name[i]!='\0';i++){
        if(isalpha(name[i]) || name[i]==' '){
            continue;
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Enter the valid Name: ");
        scanf(" %[^\n]",name);
        validate_name(addressBook, name);
    }
}

void validate_phone(AddressBook *addressBook, char phone[])
{
    int count=0,flag=0,num;
    for(int i=0;phone[i]!='\0';i++){
        if(phone[i]>='0' && phone[i]<='9' && phone[0]!='0'){
            count++;
            continue;
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag==1 || count!=10){
        printf("Enter the valid Contact number: ");
        scanf(" %[^\n]",phone);
        validate_phone(addressBook,phone);
    }
}

void validate_email(AddressBook *addressBook, char email[])
{
    int flag=0,count=0,count1=0,num=0,size,count2=0;
    if((email[0]>='a' && email[0]<='z')){
        flag=1;
    }
    for(int i=0;email[i]!='\0';i++){
        if(email[i]=='@' && (email[i+1]>='a' && email[i+1]<='z')){
            count=1;
        }
        if(email[i]=='@'){
            count2++;
        }
        if(email[i]==' '){
            count1=1;
        }
    }
    size=strlen(email);
    if(email[size-1]=='m' && email[size-2]=='o' && email[size-3]=='c' && email[size-4]=='.'){
        num=1;     
    }
    if(flag==1 && count == 1 && num == 1 && count2==1 && count1==0){
        return;
    }
    else{
        printf("Enter valid Email id: ");
        scanf(" %[^\n]",email);
        validate_email(addressBook,email);
    }
}

void validate_address(AddressBook *addressBook, char address[])
{
    int flag=0;
    for(int i=0;address[i]!='\0';i++){
        if(isalpha(address[i]) || address[i]==' '){
            continue;
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Enter the valid Address: ");
        scanf(" %[^\n]",address);
        validate_name(addressBook,address);
    }
}

void  search_phone(AddressBook *addressBook, char phone[])
{
    int flag=0;
    for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(phone,addressBook->contacts[i].phone)==0){
            flag=1;
            break;
        }
    }
    if(flag==0){
        return;
    }
    else if(flag==1){
        printf("Contact number Already exists!\nEnter another Contact number: ");
        scanf(" %[^\n]",phone);
        validate_phone(addressBook,phone);
        search_phone(addressBook,phone);
    }
}

void search_email(AddressBook *addressBook, char email[])
{
    int flag=0;
    for(int i=0;i<addressBook->contactCount;i++){
        if(strcmp(email,addressBook->contacts[i].email)==0){
            flag=1;
            break;
        }
    }
    if(flag==0){
        return;
    }
    else{
        printf("Email id Already exists!\nEnter another Email id: ");
        scanf(" %[^\n]",email);
        validate_email(addressBook,email);
        search_email(addressBook,email);
    }
}

void edit_contact(AddressBook *addressBook, char contact[], int count)
{
    char name[50],phone[20],email[50],address[50];
    int op,flag,sr;
    printf("%d Contacts found.\n",count);
    for(int i=0;i<addressBook->contactCount;i++){ 
        if(strstr(addressBook->contacts[i].name,contact)!=NULL || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(addressBook->contacts[i].address,contact)==0){
            printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
        }
    }
    printf("Choose option to Edit: \n1. Edit Name\n2. Edit Phone\n3. Edit Email\n4. Edit Address\n5. Exit\nEnter the option: ");
    scanf("%d",&op);
    switch(op)
    {
        case 1:
            if(count==1){
                for(int i=0;i<addressBook->contactCount;i++){
                    if(strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0){
                        printf("Enter Name to update: ");
                        scanf(" %[^\n]",name);
                        validate_name(addressBook,name);
                        strcpy(addressBook->contacts[i].name,name);
                        printf("Data updated successflly.\nUpdated data.\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        break;
                    }
                }
            }
            else if(count>1){
                printf("Select Serial number to Edit: ");
                scanf("%d",&sr);
                for(int i=0;i<addressBook->contactCount;i++){
                    flag=0;
                    if((sr==addressBook->contacts[i].sr) && (strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0)){
                        printf("Contact found.\nContact data:\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        printf("Enter Name to update: ");
                        scanf(" %[^\n]",name);
                        validate_name(addressBook,name);
                        strcpy(addressBook->contacts[i].name,name);
                        printf("Data updated successflly.\nUpdated data.\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        break;
                    }
                    else{
                       flag=1;
                    }
                }
                if(flag==1){
                    printf("Wrong serial number entered.\n");
                }
            }
            break;

        case 2:
            if(count==1){
                for(int i=0;i<addressBook->contactCount;i++){
                    if(strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0){
                        printf("Enter Phone to update: ");
                        scanf(" %[^\n]",phone);
                        validate_phone(addressBook,phone);
                        search_phone(addressBook,phone);
                        strcpy(addressBook->contacts[i].phone,phone);
                        printf("Data updated successflly.\nUpdated data.\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        break;
                    }
                }
            }
            else if(count>1){
                printf("Select Serial number to Edit: ");
                scanf("%d",&sr);
                for(int i=0;i<addressBook->contactCount;i++){
                    flag=0;
                    if((sr==addressBook->contacts[i].sr) && (strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0)){
                        printf("Contact found.\nContact data:\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        printf("Enter Phone to update: ");
                        scanf(" %[^\n]",phone);
                        validate_phone(addressBook,phone);
                        search_phone(addressBook,phone);
                        strcpy(addressBook->contacts[i].phone,phone);
                        printf("Data updated successflly.\nUpdated data.\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        break;
                    }
                    else{
                       flag=1;
                    }
                }
                if(flag==1){
                    printf("Wrong serial number entered.\n");
                }
            }
            break;

        case 3:
            if(count==1){
                for(int i=0;i<addressBook->contactCount;i++){
                    if(strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0){
                        printf("Enter Email id to update: ");
                        scanf(" %[^\n]",email);
                        validate_email(addressBook,phone);
                        search_email(addressBook,email);
                        strcpy(addressBook->contacts[i].email,email);
                        printf("Data updated successflly.\nUpdated data.\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        break;
                    }
                }
            }
            else if(count>1){
                printf("Select Serial number to Edit: ");
                scanf("%d",&sr);
                for(int i=0;i<addressBook->contactCount;i++){
                    flag=0;
                    if((sr==addressBook->contacts[i].sr) && (strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0)){
                        printf("Contact found.\nContact data:\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        printf("Enter Email id to update: ");
                        scanf(" %[^\n]",email);
                        validate_email(addressBook,email);
                        search_email(addressBook,email);
                        strcpy(addressBook->contacts[i].email,email);
                        printf("Data updated successflly.\nUpdated data.\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        break;
                    }
                    else{
                       flag=1;
                    }
                }
                if(flag==1){
                    printf("Wrong serial number entered.\n");
                }
            }
            break;

        case 4:
            if(count==1){
                for(int i=0;i<addressBook->contactCount;i++){
                    if(strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0){
                        printf("Enter Address to update: ");
                        scanf(" %[^\n]",address);
                        validate_address(addressBook,address);
                        strcpy(addressBook->contacts[i].address,address);
                        printf("Data updated successflly.\nUpdated data.\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        break;
                    }
                }
            }
            else if(count>1){
                printf("Select Serial number to Edit: ");
                scanf("%d",&sr);
                for(int i=0;i<addressBook->contactCount;i++){
                    flag=0;
                    if((sr==addressBook->contacts[i].sr) && (strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0)){
                        printf("Contact found.\nContact data:\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        printf("Enter Address to update: ");
                        scanf(" %[^\n]",address);
                        validate_address(addressBook,address);
                        strcpy(addressBook->contacts[i].address,address);
                        printf("Data updated successflly.\nUpdated data.\n");
                        printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                        break;
                    }
                    else{
                       flag=1;
                    }
                }
                if(flag==1){
                    printf("Wrong serial number entered.\n");
                }
            }
            break;

        case 5:
            printf("Edit operation cancled.\n");
            break;

        default:
            printf("Invalid input.\n");
            break;
    }
}

void delect_contact(AddressBook *addressBook, char contact[], int count)
{
    char name[50],phone[20],email[50],address[50];
    int op,flag,sr,choice;
    printf("%d Contacts found.\n",count);
    for(int i=0;i<addressBook->contactCount;i++){ 
        if(strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0){
            printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
        }
    }
    if(count==1){
        printf("Enter your Choice.\nPress\t1->DELETE\t0->CANCLE\n");
        scanf("%d",&choice);
        if(choice==1){
            for(int i=0;i<addressBook->contactCount;i++){
                if(strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0){
                    for(int j=i;j<addressBook->contactCount;j++){
                        (addressBook->contacts[j+1].sr)--;
                        addressBook->contacts[j]=addressBook->contacts[j+1];
                    }
                    (addressBook->contactCount)--;
                    break;
                }
            }
            printf("Contact deleted successfully.\n");
        }
        else if(choice==0){
            printf("Contact not Deleted\n");
        }
        else{
            printf("Wrong Choice entered!\nContact not Deleted.\n");
        }
    }
    else if(count>1){
        printf("Select Serial number to Delete: ");
        scanf("%d",&sr);
        for(int i=0;i<addressBook->contactCount;i++){
            if((sr==addressBook->contacts[i].sr) && (strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0)){
                printf("Contact found.\n");
                printf("%-5d %-25s %-15s %-30s %-20s\n\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
                break;
            }
        }
        for(int k=0;k<addressBook->contactCount;k++){
            flag=0;
            if((sr==addressBook->contacts[k].sr) && (strstr(addressBook->contacts[k].name,contact)!=0 || strcmp(contact,addressBook->contacts[k].phone)==0 || strcmp(contact,addressBook->contacts[k].email)==0 || strcmp(contact,addressBook->contacts[k].address)==0)){
                printf("Enter your Choice.\nPress\t1->DELETE\t\t0->CANCLE\n");
                scanf("%d",&choice);
                if(choice==1){   
                    for(int i=0;i<addressBook->contactCount;i++){
                        if((sr==addressBook->contacts[i].sr) && (strstr(addressBook->contacts[i].name,contact)!=0 || strcmp(contact,addressBook->contacts[i].phone)==0 || strcmp(contact,addressBook->contacts[i].email)==0 || strcmp(contact,addressBook->contacts[i].address)==0)){
                            for(int j=i;j<addressBook->contactCount;j++){
                                (addressBook->contacts[j+1].sr)--;
                                addressBook->contacts[j]=addressBook->contacts[j+1];
                            }
                            (addressBook->contactCount)--;
                            break;
                        }
                    }
                    printf("Contact deleted successfully.\n");
                }
                else if(choice==0){
                    printf("Contact not Deleted\n");
                }
                else{
                    printf("Wrong Choice entered!\nContact not Deleted.\n");
                }
                break;
            }
            else{
                flag=1;
            } 
        }
        if(flag==1){
            printf("You Selected wrong Serial number.\nContact not found!\n");
        }
    }
}

void load_contacts(AddressBook *addressBook){
    FILE *fptr=fopen("contacts.csv","r");
    if(fptr==NULL){
        printf("Error, file not found!\n");
        return ;
    }
    fscanf(fptr,"#%d\n",&(addressBook->contactCount));
    for(int i=0;i<addressBook->contactCount;i++){
        fscanf(fptr,"%d %[^,],%[^,],%[^,],%[^\n]",&addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
    }
    fclose(fptr);
}

void save_contacts(AddressBook *addressBook)
{
    FILE *fptr=fopen("contacts.csv","w");
    if(fptr==NULL){
        printf("Error, file not found!\n");
        return ;
    }
    fprintf(fptr,"#%d\n",addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr,"%d %s,%s,%s,%s\n",addressBook->contacts[i].sr,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email,addressBook->contacts[i].address);
    }
    fclose(fptr);
}