// Requirements: 
// 1. Ability to select an item
// 2. Ability to pay for a item (cash / credit card)
// 3. Dispense the selected item
// 4. Notify the owner (serving agent) about inventory status (running low on change or items)
// 5. Payment gateway system for credit card


#include<iostream>
using namespace std;
#include "mutex"

// Interface which contains method for all vending machine states
class VendingMachine;

class VMState{
    public:
    virtual void insertMoney(VendingMachine* machine)=0;
    virtual void dispenseItem() =0;
};

class VendingMachine {
    VendingMachine(){}
	static VendingMachine* vmInstance;
	static mutex mtx;
	VMState* currentState;
	public:
	static VendingMachine* getVendingMachine();
    void insertMoney(){
        currentState->insertMoney(vmInstance);
    }
    void dispenseItem(){
       currentState->dispenseItem();
    }
    void setState(VMState* state){
        currentState = state;
    }
    void getHasMoneyState(){
        cout<<"!";
    }
};



VendingMachine* VendingMachine::vmInstance = nullptr;
mutex VendingMachine::mtx;

VendingMachine* VendingMachine::getVendingMachine() {
	if (vmInstance == nullptr) {
		mtx.lock();
		if (vmInstance == nullptr) {
		    VMState* state;
			vmInstance = new VendingMachine();
		}
		mtx.unlock();
	}
	return vmInstance;
}

class HasMoneyState : public VMState {
    public:
    void insertMoney(VendingMachine* machine) override
    {
        cout<< "Money already inserted. Please select an item."<<endl;
    }
    void dispenseItem() override
    {
        cout<< "Dispensing item..."<< endl;
    }
};

class IdleState : public VMState {
    public:
    void insertMoney( VendingMachine* machine) override
    {
        cout<< "Money inserted. Please select an item."<<endl;
        machine->setState(new HasMoneyState());
    }
    void dispenseItem() override
    {
        cout<< "Please insert money first"<< endl;
    }
};

int main(){
    VendingMachine* machine = VendingMachine::getVendingMachine();
    IdleState* d = new IdleState();
    machine->setState(d);
    machine->insertMoney();
    machine->dispenseItem();
    return 0;  
}
