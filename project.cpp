#include<iostream>
#include<vector>
using namespace std;
class Participant{
    public:
    int id;
    string name;
    Participant(int id, string name){
        this->id = id;
        this->name = name;
    }
    Participant()=default;
    void printdetails(){
        cout<<"Id of participant:"<<id<<endl<<"Name of participant:"<<name<<endl;
    }
};

class Workforce: public Participant{
     public:
     string event;
     vector<Participant> participants;
     Workforce(string event){
        this->event=event;
    }
    void Add_Participant(int id,string name){
         Participant p(id,name);
         participants.push_back(p);
    }
    void print_participants(){
        cout<<"Event:"<<event<<endl;
        cout<<"Participant Details:"<<endl;
        for(int i = 0 ; i < participants.size();i++){
            cout<<participants[i].id<<participants[i].name<<endl;
        }
    }
};
class Coordinator{
    public:
    
    string team;
    vector<Workforce> workforces;
    Coordinator(string tteam){
        this->team=tteam;
    }
   void Add_Workforce(string event){
        Workforce w(event);
        workforces.push_back(w);
    }
    void print_participants(){
        cout<<"Event Name\t"<<"No. of Participants\t"<<endl;
        for(int i = 0 ; i < workforces.size();i++){
            cout<<workforces[i].event<<workforces[i].participants.size()<<endl;
        }
    }
};
class CoreMembers:public Coordinator{
    public:
    string specialization;
    vector<Coordinator> coordinators;
    CoreMembers(string specialization):Coordinator(team){
        this->specialization = specialization;
    }
    void Add_Coordinator(string team){
        Coordinator c(team);
        coordinators.push_back(c);
    }
    void print_coordinator(){
        cout<<"Team Name\t"<<"Workforce size\t"<<endl;
        for(int i = 0 ; i < coordinators.size();i++){
            cout<<coordinators[i].team<<coordinators[i].workforces.size()<<endl;
        }
    }
};

  int main(){
   int id;
   Participant p1(3,"parul");
   Workforce w("dance");
   Coordinator c1("micheal");
   CoreMembers cm1("dbms");
   c1.Add_Workforce("Manan");
   p1.printdetails();
   c1.print_participants();
   w.Add_Participant(4,"Shaivi");
}