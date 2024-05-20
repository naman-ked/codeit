#include <iostream>
using namespace std;
class Desktop{
  string monitor;
  string ram;
  public:
  void setMonitor(string pMonitor){
      monitor=pMonitor;
  }
  void setRam(string pRam){
      ram = pRam;
  }
  void showSpecs(){
      cout<<"------------------------"<<endl;
      cout<<"Monitor "<< monitor << endl;
      cout<<"RAM "<< ram << endl;
      cout<<"-----------------------"<<endl;
  }
};

class DesktopBuilder{
    protected:
    Desktop* desktop;
    public:
    DesktopBuilder(){
        desktop = new Desktop();
    }
    virtual void buildMonitor() = 0;
    virtual void buildRam() = 0;
    virtual Desktop* getDesktop(){
        return desktop;
    }
};


class DellDesktopbuilder: public DesktopBuilder {
    void buildMonitor(){
        desktop->setMonitor("DELL Monitor");
    }
    void buildRam(){
        desktop->setRam("32GB LDDRX");
    }
};

class HPDesktopbuilder: public DesktopBuilder {
    void buildMonitor(){
        desktop->setMonitor("HP Monitor");
    }
    void buildRam(){
        desktop->setRam("16GB LDDRX");
    }
};

class DesktopDirector{
    private:
    DesktopBuilder* desktopBuilder;
    public:
    DesktopDirector(DesktopBuilder* pDesktopBuilde){
        desktopBuilder = pDesktopBuilde;
    }
    Desktop* BuildDesktop(){
        desktopBuilder->buildMonitor();
        desktopBuilder->buildRam();
        return desktopBuilder->getDesktop();
    }
};

int main() {
    // Write C++ code here
    DellDesktopbuilder* dl = new DellDesktopbuilder();
    HPDesktopbuilder* hp = new HPDesktopbuilder();
    DesktopDirector* d1 = new DesktopDirector(dl);
    DesktopDirector* d2 = new DesktopDirector(hp);
    Desktop *desktop1 = d1->BuildDesktop();
    Desktop *desktop2 = d2->BuildDesktop();
    desktop1->showSpecs();
    desktop2->showSpecs();

    return 0;
}
