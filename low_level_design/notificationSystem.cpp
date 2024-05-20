// Online C++ compiler to run C++ program online
#include <iostream>
#include <list>
using namespace std;


class ISubscriber{
    public:
    virtual void notify(string msg) = 0;
};


class User: public ISubscriber {
    private:
     int userId;
    public:
    User(int userId){
        this->userId = userId;
    }
    void notify(string msg){
        cout<<"User "<<userId<<" recieved msg "<<msg<<endl;
    }
};

class Group{
  list<ISubscriber*> users;
  public:
  void subscribe(ISubscriber* user){
      users.push_back(user);
  }
  void unsubscribe(ISubscriber* user){
      users.remove(user);
  }
  void notify(string msg){
      for(auto user:users){
       user->notify(msg);}
  }
};

int main() {
    // Write C++ code here
    Group* group = new Group;
    
    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);
    
    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);
    
    group->notify("new msg");
    
    group->unsubscribe(user1);
    group->notify("new new msg");
    return 0;
}
