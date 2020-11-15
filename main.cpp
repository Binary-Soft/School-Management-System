#include<iostream>
#include"project_name.h"
#include<fstream>
#include<cstring>
#include<windows.h>

using namespace std;

class Admission
{
    char *password;

public:
    char student_full_Name[25];
    int student_Age;
    char Gender[7];
    char father_Name[25];
    char mother_Name[25];
    char Adress[30];
    char blood_Group[4];
    char mobile_Number[13];
    void set_password(char *pass);
    char* get_password(){return password;}
};

void Admission :: set_password(char *pass)
{
    int len = strlen(pass);

    password = new char [len+1];

    if(!password){
        cout << "Memory Allocation Failed" << endl;
        return ;
    }

    strcpy(password, pass);
}

void admission_test();
char* find_Class();
int check_answer(char *line);
void save_student_information(const Admission &object, char *file_name);



int main()
{
    int x, option;

    while(1)
    {
        Project_Name();
        cout << "[1] Admission Test." << endl << "[2] something." << endl << "[3]  something." << endl << "[4] something." << endl << endl << "Enter Your Option ..";
        cin >> option;

        switch(option)
        {
            case 1 :
               admission_test();
               break;
        }
    }


    return 0;
}

void admission_test()
{
    Admission object;
    char str[25] = "Addmission Test\\";
    char str2[25] = "Student Information\\";
    char class_name[25];
    char line[100], password[15];
    int i, count, check;

    while(1){
        cout << "Enter Student Name : ";
        cin >> object.student_full_Name;
        cout << "Enter Student Mother Name : ";
        cin >> object.mother_Name;
        cout << "Enter Student Father Name : ";
        cin >> object.father_Name;
        cout << "Enter Student Address : ";
        cin >> object.Adress;
        cout << "Enter Mobile Number : ";
        cin >> object.mobile_Number;
        cout << "Enter Student Blood Group : ";
        cin >> object.blood_Group;
        cout << "Enter Student Gender : ";
        cin >> object.Gender;
        cout << "Enter Student Age : ";
        cin >> object.student_Age;
        cout << "Enter Password : ";
        cin >> password;
        object.set_password(password);
        strcpy(class_name, find_Class());
        strcat(str2, class_name);

        cout << endl << endl;

        cout << "If You Want to Save The information Than enter 1 , otherwise 2" << endl << "enter Your Option : ";
        cin >> check;
        if(check==1){
            save_student_information(object, str2);
            break;
        }
    }

    strcat(str, class_name);

    ifstream f_in(str);
    if(!f_in.is_open()){
        cout << str << "Opening Failed" << endl;
        return ;
    }

    for(i=1 ,count=0; f_in.getline(line, 100); i++){
        if(i%2)
            cout << line << endl;
        else{
            count += check_answer(line);
        }
    }

    if(count>=6){
        cout << "Successfull" << endl;
        f_in.close();
    }


}

char* find_Class()
{
    int option;

    static char Class_Name[10][15] = {"class 1.txt",
                                      "class 2.txt",
                                      "class 3.txt",
                                      "class 4.txt",
                                      "class 5.txt",
                                      "class 6.txt",
                                      "class 7.txt",
                                      "class 8.txt",
                                      "class 9.txt",
                                      "class 10.txt"};

    while(1){
        cout << "Which Class do you want to apply : ";
        cin  >>  option;

        option--;

        switch (option)
        {
        case 0:
             return Class_Name[option];
        case 1:
             return Class_Name[option];
        case 2:
            return Class_Name[option];
        case 3:
            return Class_Name[option];
        case 4:
            return Class_Name[option];
        case 5:
            return Class_Name[option];
        case 6:
            return Class_Name[option];
        case 7:
            return Class_Name[option];
        case 8:
            return Class_Name[option];
        case 9:
            return Class_Name[option];
        case 10:
            return Class_Name[option];
        default :
             cout << "Invalid Choice" << endl;
        }
    }
}
void save_student_information(const Admission &object, char *file_name)
{
    ofstream f_out(file_name);


    if(!f_out.is_open()){
        cout << file_name << " Opening Failed" << endl;
        return ;
    }

    f_out << object.student_full_Name << endl;
    f_out << object.mother_Name << endl;

    f_out.close();
}


int check_answer(char *line)
{
    int option, answer;
    char str[20], str2[20], str3[20], str4[20];

    sscanf(line , "%s %s %s %s %d", str, str2, str3, str4, &answer);

    cout << "[1]" << str  << endl;

    cout << "[2]" << str2 << endl;

    cout << "[3]" << str3 << endl;

    cout << "[4]" << str4 << endl << endl;

    cout << "Your Answer..";
    cin >> option;

    if (option == answer){
        return 1;
    }

    return 0;
}
