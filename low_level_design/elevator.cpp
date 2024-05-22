#include <iostream>
#include <vector>
#include <queue>
#include <set>

enum Direction { UP, DOWN, IDLE };

class Elevator {
public:
    int id;
    int currentFloor;
    Direction direction;
    std::set<int> requestedFloors;

    Elevator(int id, int initialFloor) : id(id), currentFloor(initialFloor), direction(IDLE) {}

    void move() {
        if (requestedFloors.empty()) {
            direction = IDLE;
            return;
        }
        if (direction == UP) {
            currentFloor++;
            if (requestedFloors.find(currentFloor) != requestedFloors.end()) {
                requestedFloors.erase(currentFloor);
            }
        } else if (direction == DOWN) {
            currentFloor--;
            if (requestedFloors.find(currentFloor) != requestedFloors.end()) {
                requestedFloors.erase(currentFloor);
            }
        }
        updateDirection();
    }

    void addRequest(int floor) {
        requestedFloors.insert(floor);
        updateDirection();
    }

private:
    void updateDirection() {
        if (requestedFloors.empty()) {
            direction = IDLE;
            return;
        }
        if (*requestedFloors.begin() > currentFloor) {
            direction = UP;
        } else if (*requestedFloors.rbegin() < currentFloor) {
            direction = DOWN;
        } else {
            direction = IDLE;
        }
    }
};

class Floor {
public:
    int floorNumber;
    std::queue<int> upRequests;
    std::queue<int> downRequests;

    Floor(int number) : floorNumber(number) {}

    void addRequest(int destination, Direction dir) {
        if (dir == UP) {
            upRequests.push(destination);
        } else if (dir == DOWN) {
            downRequests.push(destination);
        }
    }

    bool hasRequests(Direction dir) {
        if (dir == UP) {
            return !upRequests.empty();
        } else {
            return !downRequests.empty();
        }
    }

    int getNextRequest(Direction dir) {
        if (dir == UP && !upRequests.empty()) {
            int next = upRequests.front();
            upRequests.pop();
            return next;
        } else if (dir == DOWN && !downRequests.empty()) {
            int next = downRequests.front();
            downRequests.pop();
            return next;
        }
        return -1; // No requests
    }
};

class ControlSystem {
public:
    std::vector<Elevator> elevators;
    std::vector<Floor> floors;

    ControlSystem(int numElevators, int numFloors) {
        for (int i = 0; i < numElevators; i++) {
            elevators.emplace_back(i, 0);
        }
        for (int i = 0; i < numFloors; i++) {
            floors.emplace_back(i);
        }
    }

    void requestElevator(int floor, Direction dir) {
        int bestElevator = findBestElevator(floor, dir);
        if (bestElevator != -1) {
            elevators[bestElevator].addRequest(floor);
        }
    }

    void step() {
        for (auto &elevator : elevators) {
            elevator.move();
        }
    }

private:
    int findBestElevator(int floor, Direction dir) {
        int bestElevator = -1;
        int minDistance = 99999;
        for (auto &elevator : elevators) {
            int distance = abs(elevator.currentFloor - floor);
            if (distance < minDistance && (elevator.direction == dir || elevator.direction == IDLE)) {
                minDistance = distance;
                bestElevator = elevator.id;
            }
        }
        return bestElevator;
    }
};

int main() {
    ControlSystem system(3, 10);

    system.requestElevator(3, UP);
    system.requestElevator(7, DOWN);

    for (int i = 0; i < 10; i++) {
        system.step();
        for (const auto &elevator : system.elevators) {
            std::cout << "Elevator " << elevator.id << " at floor " << elevator.currentFloor << " moving " << (elevator.direction == UP ? "UP" : elevator.direction == DOWN ? "DOWN" : "IDLE") << "\n";
        }
    }

    return 0;
}

