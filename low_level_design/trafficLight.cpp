// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

//Interface which contains method for all states
class TrafficLightState{
    public:
    virtual void handle()=0;
};

class GreenState : public TrafficLightState{
    public:
    void handle() override
    {
        cout<< "Traffic light 🤢"<<endl;
    }
};

class RedState : public TrafficLightState{
    public:
    void handle() override
    {
        cout<< "Traffic light 😡"<<endl;
    }
};

class YellowState : public TrafficLightState{
    public:
    void handle() override
    {
        cout<< "Traffic light 😊"<<endl;
    }
};

class TrafficLight{
    private:
    TrafficLightState* state;
    public:
    TrafficLight() : state(new RedState()) {}
    void setState(TrafficLightState* newState)
    {
        delete state;
        state = newState;
    }
    
    void change(){
        state->handle();
    }
};

int main()
{
	TrafficLight t;

	t.change(); // Initial state: Red
	t.setState(new YellowState());
	t.change();
	t.setState(new GreenState());
	t.change(); // State changed to Green

	return 0;
}
