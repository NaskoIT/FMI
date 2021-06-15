#include <iostream>
#include "1/LimitedTwowayCounter.hpp"
#include "2/TeamLead.hpp"

void testCounters();

using namespace std;

int main() {
    testCounters();

    TeamLead teamLead("Atanas Vasilev", 5000);
    Developer developer("Nasko");
    teamLead.addDeveloperToTeam(&developer, 300);

    cout << developer.getSalary() << endl;

    teamLead.increaseTeamSalariesBy(500);
    cout << developer.getSalary() << endl;

    teamLead.decreaseTeamSalariesBy(300);
    cout << developer.getSalary() << endl;
}

void testCounters() {
    cout << "Hello, World!" << endl;
    LimitedTwowayCounter test(-10, 10);
    cout << test.getTotal() << " " << test.getStep() << endl;

    test.increment();
    cout << test.getTotal() << endl;

    test.decrement();
    cout << test.getTotal() << endl;
}
