#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;

struct node{ 
  string username;
  int id;
  char grade;
  int score;
  node *next;
};

class linkedList{
  private:
    node *head;
  public:
    linkedList(){
      head = nullptr;
    }

    int getSize(linkedList list){
      int size = 0;
      node *cu =head;
      while (cu != nullptr){
        size++;
        cu = cu->next;
      }
      return size;
    }
    
    void swap(node* cu, node* prev){
      int _id = prev->id;
      string _username = prev->username;
      int _score = prev->score;
      char _grade = prev->grade;
  
      prev ->id = cu->id;
      prev->username = cu->username;
      prev->score = cu->score;
      prev ->grade = cu->grade;
  
      cu->id = _id;
      cu ->username = _username;
      cu->score = _score;
      cu->grade = _grade;
    }


    void addAtend(string _username, int _id, char _grade, int _score){
      node *temp = new node;
      
      //fill node
      temp->username = _username;
      temp->id = _id;
      temp->grade = _grade;
      temp->score = _score;
      temp->next = nullptr;
      //update
      if(head == nullptr){
        head = temp;
      }
      else{
        node *cu = head;
        //checks head for id dupes
        if(cu->id == temp->id){
          cu->username = _username;
          cu->grade = _grade;
          cu->score = _score;
          return;
        }
        //ignores if username is the same
        else if(cu->username == temp->username){
          return;
        }        
        while(cu->next != nullptr){ //while not at the end of the list
          //cout << cu->id << " " << temp->id << endl
          cu = cu->next;
          if(cu->id == temp->id){ 
            cu->username = _username;
            cu->grade = _grade;
            cu->score = _score;
            return;
          }
          else if(cu->username == temp->username){
            return;
          }
          //cout << cu->id << " " << temp->id << endl;
        }
        //checks end of the list for id dupes
        if(cu->id == temp->id){
          cu->username = _username;
          cu->grade = _grade;
          cu->score = _score;
          return;
        }
        else if(cu->username == temp->username){
          return;
        }        
        cu->next = temp;
      }
    }

    void addatPos(int index, string _username, int _id, char _grade, int _score, linkedList list){
      //create node
      node *temp = new node;
      //fill node
      temp->username = _username;
      temp->id = _id;
      temp->grade = _grade;
      temp->score = _score;
      temp->next = nullptr;
      //cout << _username << " " << _id << " " << _grade << " " << _score << endl;

      node *cu = head;
      node *prev = nullptr;

      if(index > getSize(list)){
        return;
      }
      else if(cu == nullptr){
        head = temp;
        return;
      }
      else if(index == getSize(list)){
        while(cu->next != nullptr){
          cu = cu->next;
          if(cu->id == temp->id){
            cu->username = temp->username;
            cu->score = temp->score;
            cu->grade = temp->grade;
            return;
          }
          else if(cu->username == temp->username){
            return;
          }
        }
        cu->next = temp;
      }
      else if(index == 0){
        if(head->id == temp->id){
          head->username = temp->username;
          head->score = temp->score;
          head->grade = temp->grade;
        }
        else if(head->username == temp->username){
          return;
        }
        else{
          head = temp;
          temp->next = cu;
        }
      }
      else if((index > 0) && (index < getSize(list))){
        for(int i=0; i<index; i++){
          prev = cu;
          cu = cu->next;
          if(cu->id == temp->id){
            cu->username = temp->username;
            cu->score = temp->score;
            cu->grade = temp->grade;
            return;
          }
          else if(cu->username == temp->username){
            return;
          }
        }
        prev->next = temp;
        temp->next = cu;
      }
      }


    void remove(string type, string value){
      node *temp = head;
      node *prev = nullptr;

      
      if(type == "username"){
        if(temp != nullptr && temp->username == value){ //deletes head if found
          head = temp->next;
          delete temp;
          return;
        }
        else{
        while(temp != nullptr && temp->username != value){
          prev = temp;
          temp = temp->next;
        }
        if(temp == nullptr){
          return;
        }
        prev->next = temp->next;
        delete temp;
        }
      }

      if(type == "id"){
        int convertValID = stoi(value);
        if(temp != nullptr && temp->id == convertValID){
          head = temp->next;
          //cout << "Deleting: " << convertValID << endl;
          delete temp;
          return;
        }
        else{
          while(temp != nullptr && temp->id != convertValID){
            prev = temp;
            temp = temp->next;
          }
          if(temp == nullptr){
            return;
          }
          prev->next = temp->next;
          //cout << "Deleting: " << convertValID << endl;
          delete temp;
        }
      }

      if(type == "grade"){
        char convertValGrade = value[0];
        if(temp != nullptr && temp->grade == convertValGrade){
          head = temp->next;
          //cout << "Deleting: " << convertValGrade << endl;
          delete temp;
          return;
        }
        else{
          while(temp != nullptr && temp->grade != convertValGrade){
            prev = temp;
            temp = temp->next;
          }
          if(temp == nullptr){
            return;
          }
          prev->next = temp->next;
          //cout << "Deleting: " << convertValGrade << endl;
          delete temp;
        }        
      }
      if(type == "score"){
        int convertValScore = stoi(value);
        if(temp != nullptr && temp->score == convertValScore){
          head = temp->next;
          //cout << "Deleting: " << convertValScore << endl;
          delete temp;
          return;
        }
        else{
          while(temp != nullptr && temp->score != convertValScore){
            prev = temp;
            temp = temp->next;
          }
          if(temp == nullptr){
            return;
          }
          prev->next = temp->next;
          //cout << "Deleting: " << convertValScore << endl;
          delete temp;
        }        
      }
    }

    void sortID(linkedList list){
      node *cu = head;
      node *pr = head->next;
        while (cu != nullptr)
        {
          while (pr != nullptr)
          {
              if (pr->id < cu->id)
              {
                swap(pr, cu);
              }
              pr = pr-> next;
          }
          cu = cu-> next;
          if (cu!=nullptr)
          {
            pr = cu->next;
          }
        }
      
    }

    void sortScore(linkedList list){
      node *cu = head;
      node *pr = head->next;
        while (cu != nullptr)
        {
          while (pr != nullptr)
          {
              if (pr->score > cu->score)
              {
                swap(pr, cu);
              }
              pr = pr-> next;
          }
          cu = cu-> next;
          if (cu!=nullptr)
          {
            pr = cu->next;
          }
        }      
    }


    void sortName(linkedList list){
      node *cu = head;
      node *pr = head->next;
        while (cu != nullptr)
        {
          while (pr != nullptr)
          {
              if (pr->username < cu->username)
              {
                swap(pr, cu);
              }
              pr = pr-> next;
          }
          cu = cu-> next;
          if (cu!=nullptr)
          {
            pr = cu->next;
          }
        }            
    }

    void sortGrade(linkedList list){
      node *cu = head;
      node *pr = head->next;
        while (cu != nullptr)
        {
          while (pr != nullptr)
          {
              if (pr->grade < cu->grade)
              {
                swap(pr, cu);
              }
              pr = pr-> next;
          }
          cu = cu-> next;
          if (cu!=nullptr)
          {
            pr = cu->next;
          }
        }             
    }


    void print(ofstream &outputFile){
      node *cu = head;
      while(cu != nullptr){
        outputFile << "[id:" << cu->id << ";username:" << cu->username <<";score:"<<cu->score << ";grade:" << cu->grade << "]" << endl;
        cu = cu->next; 
        if(cu->next == nullptr){
          outputFile << "[id:" << cu->id << ";username:" << cu->username <<";score:"<<cu->score << ";grade:" << cu->grade << "]" << endl;
          break;
        }
      }
    }

    void printList(){
      node *cu = head;
      if(cu == nullptr){
        return;
      }
      while(cu != nullptr){
        cout << "[id:" << cu->id << ";username:" << cu->username <<";score:"<<cu->score << ";grade:" << cu->grade << "]" << endl;
        cu = cu->next;
      }
    }
    
};

int main(int argc, char *argv[]){
  
  ArgumentManager am(argc, argv);
  ifstream inputFile(am.get("input"));
  ifstream commandFile(am.get("command"));
  ofstream outputFile(am.get("output"));

  /*ifstream inputFile("input3.txt");
  ifstream commandFile("command3.txt");
  ofstream outputFile("output3.txt");*/

  linkedList list;
  string inStr; //input string
  int idIndex, userIndex, scoreIndex, gradeIndex = 0;

  while(getline(inputFile, inStr)){

    //Lines 20 & 21: Removing '\n' and '\r' from inStr
    inStr.erase(remove(inStr.begin(), inStr.end(), '\n'), inStr.end());
    inStr.erase(remove(inStr.begin(), inStr.end(), '\r'), inStr.end());

    //Getting the first index of each substring that is found from inStr
    idIndex = inStr.find("id:");  
    userIndex = inStr.find("username:");
    scoreIndex = inStr.find("score:");
    gradeIndex = inStr.find("grade:");
    string holdID = "";
    string holdUser = "";
    string holdScore = "";
    string holdGrade = "";
    int convertID;
    int convertScore;
    char convertGrade;

    /*cout << idIndex << endl;
    cout << userIndex << endl;
    cout << scoreIndex << endl;
    cout << gradeIndex << endl;*/
    
    //If there is a missing attribute, continue
    if(idIndex == -1 || userIndex == -1 || scoreIndex == -1 || gradeIndex == -1){
      continue;
    }
    

    //Check to see if attributes are in order by doing something like:
    if(idIndex > userIndex || userIndex > scoreIndex || scoreIndex > gradeIndex){
      continue;
    }
    //cout << inStr << endl;
    //Continue to parse inStr
    if(idIndex == 1){
      holdID = inStr.substr(inStr.find(":")+1, 4);
      convertID = stoi(holdID);
      //cout << holdID << endl;
      //cout << inStr << endl;
    }
    if(userIndex > idIndex && userIndex < scoreIndex){
      string temp = inStr.substr(userIndex);
      string temp2 = temp.substr(temp.find(":")+1);
      holdUser = temp2.substr(0,temp2.find(";")); //gets names
      //cout << temp << endl;
      //holdUser = inStr.substr();
      //cout << holdUser << endl;
    }
    if(scoreIndex > userIndex && scoreIndex < gradeIndex){
      string temp = inStr.substr(scoreIndex);
      string temp2 = temp.substr(temp.find(":")+1);
      holdScore = temp2.substr(0,temp2.find(";")); // gets score
      convertScore = stoi(holdScore);
      //cout << holdScore << endl;
    }
    if(gradeIndex > scoreIndex && inStr.length()){
      string temp = inStr.substr(gradeIndex);
      string temp2 = temp.substr(temp.find(":")+1);
      holdGrade = temp2.substr(0,temp2.find("]"));
      convertGrade = holdGrade[0]; //convert to char
      //cout << holdGrade << endl;
    }
  list.addAtend(holdUser,convertID,convertGrade,convertScore);
    //list.print(outputFile);
    //Input into linked list

  }
  //list.print(outputFile);
  //list.printList();


  //Read from commandFile
  //cout << "size of list . . . " << list.getSize(list) << endl;
  string cmdInput;
  int idInc, userInc, scoreInc, gradeInc, addInc, removeInc, sortInc = 0;
  while (getline(commandFile, cmdInput)){
    cmdInput.erase(remove(cmdInput.begin(), cmdInput.end(), '\n'), cmdInput.end());
    cmdInput.erase(remove(cmdInput.begin(), cmdInput.end(), '\r'), cmdInput.end());
    cmdInput.erase(remove(cmdInput.begin(), cmdInput.end(), ' '), cmdInput.end());

    idInc = cmdInput.find("id:");  
    userInc = cmdInput.find("username:");
    scoreInc = cmdInput.find("score:");
    gradeInc = cmdInput.find("grade:");
    addInc = cmdInput.find("Add");
    removeInc = cmdInput.find("Remove");
    sortInc = cmdInput.find("Sort");

    string holdID = "";
    string holdUser = "";
    string holdScore = "";
    string holdGrade = "";
    string holdRemove ="";
    int convertID;
    int convertScore;
    char convertGrade;


    //cout << cmdInput << endl;
    
    //cout << "id index: " << idInc << endl;
    //cout << "user index: " << userInc << endl;
    //cout << "score index: " << scoreInc << endl;
    //cout << "grade index: " << gradeInc << endl;
    //cout << "add index: " << addInc << endl;
    //cout << "remove index: " << removeInc << endl;
    //cout << "sort index: " << sortInc << endl;
    if(sortInc == 0){
      string temp = cmdInput.substr(cmdInput.find("(")+1);
      string type = temp.substr(0,temp.find(")"));
      if(type == "id"){
        list.sortID(list);
      }
      else if(type == "score"){
        list.sortScore(list);
      }
      else if(type == "username"){
        list.sortName(list);
      }
      else if(type == "grade"){
        list.sortGrade(list);
      }
      
      //cout << "sort by: " << type << endl;
      
      //call sort
      //cout << "sort" << endl;
    }

    if(removeInc == 0){
      string Ttemp = cmdInput.substr(cmdInput.find("(")+1);
      string Vtemp = cmdInput.substr(cmdInput.find(":")+1);
      string value = Vtemp.substr(0,Vtemp.find(")"));
      string type = Ttemp.substr(0, Ttemp.find(":"));
      
      //cout << value << endl;
      //cout << type << endl;
      for(int i=0;i<list.getSize(list);i++){
        list.remove(type,value);
      }
      
      //cout << "remove" << endl;
      //call remove;
    }
    
    if(idInc == -1 || userInc == -1 || scoreInc == -1 || gradeInc == -1){
      continue;
    }    

    if(idInc > userInc || userInc > scoreInc || scoreInc > gradeInc){
      continue;
    }   

    if(idInc > addInc){
      holdID = cmdInput.substr(cmdInput.find(":")+1, 4);
      convertID = stoi(holdID);
      //cout << "converted id " << convertID << endl;
      //cout << holdID << endl;
      
    }
    
    if(userInc > idInc && userInc < scoreInc){
      string temp = cmdInput.substr(userInc);
      string temp2 = temp.substr(temp.find(":")+1);
      holdUser = temp2.substr(0,temp2.find(";")); //gets names
      //cout << temp << endl;
      //holdUser = inStr.substr();
      //cout << holdUser << endl;
    }
    
    if(scoreInc > userInc && scoreInc < gradeInc){
      string temp = cmdInput.substr(scoreInc);
      string temp2 = temp.substr(temp.find(":")+1);
      holdScore = temp2.substr(0,temp2.find(";")); // gets score
      convertScore = stoi(holdScore);
      //cout << holdScore << endl;
    }

    if(gradeInc > scoreInc && cmdInput.length()){
      string temp = cmdInput.substr(gradeInc);
      string temp2 = temp.substr(temp.find(":")+1);
      holdGrade = temp2.substr(0,temp2.find("]"));
      convertGrade = holdGrade[0]; //convert to char
      //cout << holdGrade << endl;
    }    
    
    if(addInc == 0){
      int holdPos;
      string temp = cmdInput.substr(cmdInput.find("(")+1);
      temp = temp.substr(0, temp.find(")"));
      //cout << temp << endl;
      holdPos = stoi(temp);
      list.addatPos(holdPos, holdUser, convertID, convertGrade, convertScore, list);
      //cout << temp << endl;
      //cout << holdPos << endl;
    }
    
    //cout << cmdInput << endl;
  
    
  }
  //list.printList();
  //Perform commands on linked list

  //Output to outputFile
  list.print(outputFile);
  list.printList();
  return 0;
}