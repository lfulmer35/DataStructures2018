//Lucas Fulmer
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;
struct Event //I chose to use a structure for this assignment because I did not believe the simulation was in depth enough to require member functions
{
	int arrivalTime;
	int transactionTime;
	int departureTime = 0;
	int priority;
	char customer;
	bool operator <(const Event& right) const;//overloading the < operator, in order to use the priority queue
	bool operator >(const Event& right) const;
};
void processArrival(Event& _arrivalEvent, Event& _departureEvent, priority_queue<Event>& _eventPQueue, queue<Event>& _bankQueue);
void processDeparture(Event& _departureEvent, priority_queue<Event>& _eventPQueue, queue<Event>& _bankQueue);
char customer = '@';
bool tellerAvailable = true;
int waitTime, previousDeparture = 0, currentTime = 1;
double averageWait = 0.0;

int main()
{
	int numCustomers;
	Event arrivalEvent, departureEvent, newEvent;
	ifstream infile;
	queue<Event> bankQueue;//line of customers
	priority_queue<Event> eventPQueue;//queue of arrival/departure events

	infile.open("simulationInput.txt");//opening the file containing arrival and transaction times

	//Create and add arrival events
	if (!infile.good())
		cout << "Error opening simulation file." << endl;
	else
	{
		while (infile.good())//looping through the file and adding each arrival event to our priority queue
		{
			infile >> arrivalEvent.arrivalTime;
			arrivalEvent.priority = (1000 - arrivalEvent.arrivalTime);//in order to prioritize earliest events to front of the queue
			infile >> arrivalEvent.transactionTime;
			eventPQueue.push(arrivalEvent);
		}
		numCustomers = eventPQueue.size();
		cout << "*********Simulation Output*********" << endl;
		cout << "Cust.     Arrival   Depart     Wait" << endl;
		while (!eventPQueue.empty())
		{
			newEvent = eventPQueue.top();//getting the highest priority event
		
			//establishing the current time
			if (previousDeparture == 0 || newEvent.arrivalTime > previousDeparture)//if event is an arrival event
				currentTime = newEvent.arrivalTime;
			else//if event is an arrival, but the customer is in line
				currentTime = previousDeparture;

			if (newEvent.departureTime == 0)//if event is an arrival event
				processArrival(newEvent, departureEvent, eventPQueue, bankQueue);
			else//event is a departure
				processDeparture(newEvent, eventPQueue, bankQueue);
		}
	}
	cout << "Final Statistics: " << endl << "Number of Customers: " << numCustomers << endl;
	cout << "Average Wait: " << averageWait / numCustomers << endl;
	return 0;
}
void processArrival(Event& _arrivalEvent, Event& _departureEvent, priority_queue<Event>& _eventPQueue, queue<Event>& _bankQueue)
{//this function processes each arrival, if there is a teller available then we simulate the event
	_eventPQueue.pop();
	customer += 1;
	_arrivalEvent.customer = customer;
	cout << "Processing arrival event at time " << _arrivalEvent.arrivalTime << endl;
	if (_bankQueue.empty())
	{
		_arrivalEvent.departureTime = (currentTime + _arrivalEvent.transactionTime);
		previousDeparture = _arrivalEvent.departureTime;
		_arrivalEvent.priority = (1000 - _arrivalEvent.departureTime);
		_departureEvent = _arrivalEvent;
		_eventPQueue.push(_departureEvent);
		tellerAvailable = false;
	}
	else//if the teller is not available, the arrival enters the queue(line)
		_bankQueue.push(_arrivalEvent);//i think there's a problem here
}
void processDeparture(Event& _departureEvent, priority_queue<Event>& _eventPQueue, queue<Event>& _bankQueue)
{
	_eventPQueue.pop();
	if (!_bankQueue.empty() && tellerAvailable == true)//if there's no line and the teller is available
	{
 		_departureEvent = _bankQueue.front();//getting the top priority departure event
		_bankQueue.pop();
		_departureEvent.departureTime = (currentTime + _departureEvent.transactionTime);
		_departureEvent.priority = (1000 - _departureEvent.departureTime);
		_eventPQueue.push(_departureEvent);
	}
	else
	{
		tellerAvailable = true;
		waitTime = ((_departureEvent.departureTime - _departureEvent.arrivalTime) - _departureEvent.transactionTime);
		cout << "Processing Departure Event at " << _departureEvent.departureTime << "." << endl;
		//cout << _departureEvent.customer << "          " << _departureEvent.arrivalTime << "         " <<
			//_departureEvent.departureTime << "         " << waitTime << endl;
		averageWait += waitTime;
	}
}
bool Event::operator <(const Event& right) const
{
	if (priority < right.priority)
		return true;
	else
		return false;
}
bool Event::operator >(const Event& right) const
{//this was not necessary, but I didn't know that until after I finished coding.
	if (priority > right.priority)
		return true;
	else
		return false;
}
