#include<iostream>
#include<cstring>
#define max 100
using namespace std;
class patient{
    public:
    char name[100];int age;char phone[20]; int booking_id;
    };
class Room{
    public:
    char AC;int bedsavailables;int bedsprice;int roomsNumber;int status;

    class patient pat;
    class Room addroom(int);
    void searchroom(int);
    void displayroom(Room);
    };
// global declarations
class Room rooms[max];
int count = 0;
Room Room::addroom(int roomno){
    class Room room;
    room.roomsNumber=roomno;
    cout<<"\n Type AC/Non-AC(A/N):"<<endl;;
    cin>>room.AC;
    cout<<"\nBeds Price:";
    cin>>room.bedsprice;
    cout<<"\nBeds Availables:"<<endl;
    cin>>room.bedsavailables;
    room.status=0;

    cout<<"Room Added Successfully!"<<endl;
    return room;
} 
void Room::searchroom(int roomno){
    int i,found=0;
    for(i=0;i<count;i++){
        if(rooms[i].roomsNumber==roomno){
            found=1;
            break;
            }
    }
    if(found==1){
        cout<<"Room Details"<<endl;
        if(rooms[i].status==1) {
            cout<<"\nRoom is Reserved";
        }
        else{
            cout<<"\nRoom is Aavilable";
        }
        displayroom(rooms[i]);
    }
    else{
        cout<<"\nRoom not found";

    }
}
void Room::displayroom(Room temproom){
    cout<<"\nRoom Number:"<<temproom.roomsNumber;
    cout<<"\nType AC/Non-AC(A/N)"<<temproom.AC;
    cout<<"\nBeds Availables:"<<temproom.bedsavailables;
    cout<<"\nEach Beds Price: "<<temproom.bedsprice<<endl;

}
class Hospital:protected Room{
    public:
    void checkIn();
    void getAvailableRoom();
    void searchpatient(char*);
    void checkOut(int);
};
//hospital management revervation of room
void hospital::checkIN(){
    int i,found=0,roomno;
    class Room room;
    cout<<"\nEnter Room Number:";
    cin>>roomno;
    for(i=0;i<count;i++){
        if(room[i].roomsNumber==roomno){
            found=1;
            break;
        }
    }
    if(found==1){
        if(rooms[i],status==1){
            cout<<"\nRoom is already Booked ";
            return;
        }
        cout<<"\nEnter Patient Name:"<<endl;
        cin>>rooms[i].pat.name;
        cout<<"\nEnter Phone no.: "<<endl;
        cin>>rooms[i].pat.phone;
        cout<<"\nEnter Age of Patient:"<<endl;
        cin>>rooms[i].pat.age;
        cout<<"\nEnter Booking ID:"<<endl;
        cin>>rooms[i].pat.booking_id;

        rooms[i].status=1;
        cout<<"\n Patient Checked-in Successfully....."<<endl;

        
    }
}
void Hospital::getAvailableRoom(){
    int i,found=0;
    for(i=0;i<count;i++){
        if(rooms[i].status==0){
            displayroom(rooms[i]);
            cout<<"\nPress enter for next room";
            found=1;
        }
    }
    if(found==0){
        cout<<"\nAll rooms are reserved";

    }
}
//hospital management shows all persons that have boooked rooms
void Hospital::searchpatient(char*bname){
    int i,found=0;
    for(i=0;i<count;i++){
        if(rooms[i].status==1 && strcmp(rooms[i].pat.name,bname)==0){
            cout<<"\n Patient Name:"<<rooms[i].pat.name;
            cout<<"\nRoom Number:"<<rooms[i].roomsNumber;

            cout<"\n\n Press enter for next record";
            found=1;
        }
    }
    if(found==0){
        cout<<"\nPerson not found in hospital.";
    }
}
//hospital management generates the bill
void Hospital::checkOut(int roomnum){
    int i,found=0,days,roomno;
    float billamount=0;
    for(i=0;i<count;i++) {
        if (rooms[i].status==1 && rooms[i].roomsNumber==roomnum){
            found=1;
            break;
        }
    }
    if(found==1){
        cout<<"\nEnter Number of days:"<<endl;
        cin>>days;
        billamount=days*rooms[i].bedsprice;

        cout<<"\n\t*************CheckOut Details*************\n";
        cout<<"\n Patient Name:"<<rooms[i].pat.name;
        cout<<"\n Room Number:"<<rooms[i].roomsNumber;
        cout<<"\n Phone Number:"<<rooms[i].pat.phone;
        cout<<"\n Total Amouont :"<<billamount<<"/"<<endl;

        rooms[i].status=0;
    }
}
//managing avialables rooms and search rooms and add rooms
void managerooms(){
class Room room;
int opt,roomno,i,flag=0;
char ch;
do{
    system("cls");
    cout<<"\n*************Manage Rooms**************";
    cout<<"\n1.add room";
    cout<<"\n2. seach room";
    cout<<"\n3.back to main menu"<<endl;
    cin>>opt;

    switch(opt){
        case 1:
        cout<<"\nenter Room number:";
        cin>>roomno;
        i=0;
        for(i=0;i<count;i++){
            if(rooms[i].roomsNumber==roomno){
                flag=1;
            }
        }
        if (flag ==1){
            cout<<"\nRoom Number is present.\nplease enter unique number";
            flag =0;
            getch();
        }
        else{
            rooms[count] = room.addroom(roomno);
            count++;
        }
        break;
        case 1:
        cout<<"\nEnter room number:";
        cin>>roomno;
        room.searchroom(roomno);
        break;
        case 3:
        defualt:
        cout<<"\nPlease enter correct option"<<endl;
        break;
    } 
    
} while (opt!=3);
}
int main(){
    class Hospital hp;
    int i,j,opt,roomno;
    char ch;
    char bname[100];
    system("cls");
    do
    {
        system ("cls");
        cout << "######## Hospital Management #########\n";  
        cout << "\n1. Manage Rooms";  
        cout << "\n2. Check-In Room";  
        cout << "\n3. Available Rooms";  
        cout << "\n4. Search Patient";  
        cout << "\n5. Check-Out Room";  
        cout << "\n6. Exit";  
        cout << "\n\nEnter Option: "<<endl;  
        cin >> opt;  
        switch (opt){  
        case 1:  
            manageRooms();  
            break;  
        case 2:  
            if (count == 0){  
                cout << "\nRooms data is not available.\nPlease add the rooms first.";  
                getch();  
            }  
            else  
                hp.checkIn();  
            break;  
            case 3:  
            if (count == 0){  
                cout << "\nRooms data is not available.\nPlease add the rooms first.";  
                getch();  
            }  
            else  
                hp.getAvailableRoom();  
            break;  
        case 4:  
            if (count == 0){  
                cout << "\nRooms are not available.\nPlease add the rooms first.";  
                getch();  
            }  
            else{  
                cout << "Enter Patient Name: ";  
                cin >> bname;  
                hp.searchCustomer(bname);  
            }  
            break;  
        case 5:  
            if (count == 0){  
                cout << "\nRooms are not available.\nPlease add the rooms first.";  
                getch();  
            }  
            else{  
                cout << "Enter Room Number : ";  
                cin >> rno;  
                hp.checkOut(roomno);  
            }  
            break;   
        case 6:  
            cout << "\nTHANK YOU!";  
            break;  
        default:  
            cout << "\nPlease Enter correct option";  
            break;  
            }  
    } while (opt != 6);  
    getch();  
    return 0;
}  

 

// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// class Patient {
// private:
//     string name;
//     string condition;

// public:
//     Patient(const string& name, const string& condition) : name(name), condition(condition) {}

//     string getName() const {
//         return name;
//     }

//     string getCondition() const {
//         return condition;
//     }
// };

// class Hospital {
// private:
//     string name;
//     string address;
//     vector<Patient> patients;
//     int availableBeds;
//     vector<string> doctors;

// public:
//     Hospital(const string& name, const string& address, int availableBeds) : name(name), address(address), availableBeds(availableBeds) {}

//     void addPatient(const string& name, const string& condition) {
//         Patient patient(name, condition);
//         patients.push_back(patient);
//         cout << "Patient '" << name << "' added successfully." << endl;
//     }

//     void viewPatientHistory() {
//         cout << "Patient History:" << endl;
//         for (const auto& patient : patients) {
//             cout << "Name: " << patient.getName() << ", Condition: " << patient.getCondition() << endl;
//         }
//     }

//     void checkAvailableBeds() {
//         cout << "Available beds: " << availableBeds << endl;
//     }

//     void addDoctor(const string& doctorName) {
//         doctors.push_back(doctorName);
//         cout << "Doctor '" << doctorName << "' added successfully." << endl;
//     }

//     void viewDoctors() {
//         cout << "Available Doctors:" << endl;
//         for (const auto& doctor : doctors) {
//             cout << doctor << endl;
//         }
//     }

//     void displayHospitalInformation() {
//         cout << "Hospital Information:" << endl;
//         cout << "Name: " << name << endl;
//         cout << "Address: " << address << endl;
//     }
// };

// int main() {
//     int choice;
//     string hospitalName, hospitalAddress;
//     int availableBeds;
//     Hospital hospital("", "", 0);
//     string patientName, patientCondition;

//     cout << "Hospital Management System" << endl;

//     while (true) {
//         cout << "1. Hospital" << endl;
//         cout << "2. Patient" << endl;
//         cout << "3. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;

//         cin.ignore(); // Ignore the newline character left in the input buffer

//         if (choice == 1) {
//             cout << "Enter Hospital Name: ";
//             getline(cin, hospitalName);

//             cout << "Enter Hospital Address: ";
//             getline(cin, hospitalAddress);

//             cout << "Enter Available Beds: ";
//             cin >> availableBeds;

//             cin.ignore(); // Ignore the newline character left in the input buffer

//             hospital = Hospital(hospitalName, hospitalAddress, availableBeds);

//             hospital.displayHospitalInformation();

//             int operation;
//             string doctorName;

//             while (true) {
//                 cout << "1. Add Patient" << endl;
//                 cout << "2. View Patient History" << endl;
//                 cout << "3. Check Available Beds" << endl;
//                 cout << "4. Add Doctor" << endl;
//                 cout << "5. View Doctors" << endl;
//                 cout << "6. Go Back" << endl;
//                 cout << "Enter the operation to perform: ";
//                 cin >> operation;

//                 cin.ignore(); // Ignore the newline character left in the input buffer

//                 switch (operation) {
//                     case 1:
//                         cout << "Enter Patient Name: ";
//                         getline(cin, patientName);

//                         cout << "Enter Patient Condition: ";
//                         getline(cin, patientCondition);

//                         hospital.addPatient(patientName, patientCondition);
//                         break;

//                     case 2:
//                         hospital.viewPatientHistory();
//                         break;

//                     case 3:
//                         hospital.checkAvailableBeds();
//                         break;

//                     case 4:
//                         cout << "Enter Doctor Name: ";
//                         getline(cin, doctorName);
//                         hospital.addDoctor(doctorName);
//                         break;

//                     case 5:
//                         hospital.viewDoctors();
//                         break;

//                     case 6:
//                         cout << "Going back to the main menu." << endl;
//                         break;

//                     default:
//                         cout << "Invalid choice!" << endl;
//                         break;
//                 }

//                 if (operation == 6) {
//                     break;
//                 }
//             }
//         }
//         else if (choice == 2) {
//             int operation;

//             while (true) {
//                 cout << "1. Add Patient" << endl;
//                 cout << "2. View Patient History" << endl;
//                 cout << "3. Check Hospital Details" << endl;
//                 cout << "4. Go Back" << endl;
//                 cout << "Enter the operation to perform: ";
//                 cin >> operation;

//                 cin.ignore(); // Ignore the newline character left in the input buffer

//                 switch (operation) {
//                     case 1:
//                         cout << "Enter Patient Name: ";
//                         getline(cin, patientName);

//                         cout << "Enter Patient Condition: ";
//                         getline(cin, patientCondition);

//                         hospital.addPatient(patientName, patientCondition);
//                         break;

//                     case 2:
//                         hospital.viewPatientHistory();
//                         break;

//                     case 3:
//                         hospital.displayHospitalInformation();
//                         break;

//                     case 4:
//                         cout << "Going back to the main menu." << endl;
//                         break;

//                     default:
//                         cout << "Invalid choice!" << endl;
//                         break;
//                 }

//                 if (operation == 4) {
//                     break;
//                 }
//             }
//         }
//         else if (choice == 3) {
//             cout << "Exiting the program." << endl;
//             break;
//         }
//         else {
//             cout << "Invalid choice!" << endl;
//         }
//     }

//     return 0;
// }