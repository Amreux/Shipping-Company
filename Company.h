#pragma once
#include "Event.h"
#include "CancelEvent.h"
#include "PreparationEvent.h"
#include "PromoteEvent.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "LinkedList.h"
#include "Cargo.h"
#include <fstream>

class Company
{
	int AutoPromotion;
	Queue < Event* > EventsList;
	Queue<Cargo*> WaitingSpecialCargos;
	PriorityQueue<Cargo*> WaitingVIPCargos;
	LinkedList<Cargo*> WaitingNormalCargos;
	/*PriorityQueue<Cargo*> MovingSpecialCargos;
	PriorityQueue<Cargo*> MovingNormalCargos;
	PriorityQueue<Cargo*> MovingVIPCargos;*/
	Queue<Cargo*> DeliveredCargos;
	/*Queue<Cargo> DeliveredVIPCargos;
	Queue<Cargo> DeliveredSpecialCargos;*/
public:
	//      CONSTRUCTORS
	
	Company();

	//-----------------------------------------------------//
	
	//      ENQUEUING/INSERTING FUNCTIONS
	
	// function to enqueue a cargo into Waiting Special Queue
	
	void enqueueWSC(Cargo* SC);

	// function to enqueue a cargo into Waiting VIP Queue

	void enqueueWVC(Cargo* VC);

	// function to insert a cargo into Waiting Normal List

	void insertWNC(Cargo* NC);

	// function to insert a cargo in the beginning of the Waiting Normal List

	void insertFirstWNC(Cargo* NC);

	// function to enqueue a cargo into Events Queue

	void AddEvent(Event* E);


	// function to enqueue a cargo into Moving Special Queue

	void EnqueueMSC(Cargo* SC);


	// function to enqueue a cargo into Moving Normal Queue

	void EnqueueMNC(Cargo* NC);


	// function to enqueue a cargo into Moving VIP Queue


	void EnqueueMVC(Cargo* VC);


	// function to enqueue a cargo into Delivered Special queue

	void EnqueueDC(Cargo* SC);


	//// function to enqueue a cargo into Delivered Normal Queue


	//void EnqueueDNC(Cargo NC);


	//// function to enqueue a cargo into Delivered VIP Queue


	//void EnqueueDVC(Cargo VC);


	//-----------------------------------------------------//


	//      DEQUEUEING/REMOVING FUNCTIONS


	// function to remove a cargo from Waiting Normal List according to ID


	Cargo* RemoveWNC(int id);
	
	
	// function to Dequeue a cargo from Waiting VIP Cargos

	
	bool DequeueWVC(Cargo*& VC);

	// function to Dequeue a cargo from Waiting Special Cargos


	bool DequeueWSC(Cargo*& SC);


	// function to Dequeue a cargo from Events Queue


	bool DequeueEvent(Event*& E);


	// function to Dequeue a cargo from Moving VIP Cargos


	bool DequeueMVC(Cargo*& VC);


	// function to Dequeue a cargo from Moving Special Cargos


	bool DequeueMSC(Cargo*& SC);


	// function to Dequeue a cargo from Waiting VIP Cargos


	bool DequeueMNC(Cargo*& NC);


	// function to Remove First cargo from Waiting Normal Cargos List


	bool RemoveFirstWNC(Cargo*& NC);


	//-----------------------------------------------------//


	//      PRINTING OF QUEUES/LISTS FUNCTIONS  BY CALLING  PRINT FUNCTIONG IN QUEUES



	// function to print Waiting Normal Cargos List


	void PrintWNC();



	// function to print Waiting Speical Cargos Queue


	void PrintWSC();


	// function to print Waiting Moving Cargos


	void PrintWVC();



	// function to print Moving Normal Cargos Queue


	void PrintMNC();



	// function to print Moving Special Cargos Queue


	void PrintMSC();



	// function to print Moving VIP Cargos Queue


	void PrintMVC(); 


	// function to print Delivered Normal Cargos Queue



	void PrintDC();



	//// function to print Delivered Special Cargos Queue



	//void PrintDSC();



	//// function to print Delivered VIP Cargos Queue



	//void PrintDVC();



	//-----------------------------------------------------//


	//      LOADING FUNCTION


	void LoadFile(string Input);


	//-----------------------------------------------------//


	//      OTHER FUNCTIONS

	//function to return count of all Waiting Cargos


	int WaitingCount();
	
	
	//function to return count of all Moving Cargos

	
	int MovingCount();


	//function to return count of all Delivered Cargos


	int DeliveredCount();


	//function to check whether all CARGOS are delivered or not

	bool AllIsDelivered();


	//function to Get AutoPromotion

	int GetAutoPromotion();

	//function to Set AutoPromotion
	void SetAutoPromotion(int AP);

	//function to Autopromote
	void AutoPromote(int time);

	//-----------------------------------------------------//


};

