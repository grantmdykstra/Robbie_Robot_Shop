
#include "view.h"


































// CLI Menu system

/*

void robotModel(vector<RobotModel> &model)
{
	int i = 0;

	if (model.size() > 0) {
		cout << "\nMODELS" << endl << "------" << endl;
		cout << "Name\t\t\tModel #\tMax Speed\tCost\t" << endl;
		cout << "-----------------------------------------------------" << endl;
		for (i = 0; i < model.size(); i++) {
			cout << model[i].getName() << "\t" << model[i].getModelNumber() << "\t" << model[i].getMaxSpeed() << "\t\t" << model[i].getPrice() << endl;
		}
	}
}

void robotComponent(vector<RobotHead> &head, vector<RobotArm> &arm, vector<RobotBattery> &battery, vector<RobotTorso> &torso, vector<RobotLocomotor> &locomotor) {

	int i;
	cout << endl;
	if (head.size() > 0) {
		cout << "HEAD" << endl << "----" << endl;
		cout << "Name\tPart #\tWeight\tCost\tDescription" << endl;
		cout << "-------------------------------------------" << endl;
		for (i = 0; i < head.size(); i++) {
			cout << head[i].getName() << "\t" << head[i].getPartNumber() << "\t" << head[i].getWeight() << "\t" << head[i].getCost() << "\t" << head[i].getDescription() << endl;
		}
	}

	if (arm.size() > 0) {
		cout << endl << "ARM" << endl << "---" << endl;
		cout << "Name\tPart #\tWeight\tCost\tDescription" << endl;
		cout << "-------------------------------------------" << endl;
		for (i = 0; i < arm.size(); i++) {
			cout << arm[i].getName() << "\t" << arm[i].getPartNumber() << "\t" << arm[i].getWeight() << "\t" << arm[i].getCost() << "\t" << arm[i].getDescription() << endl;
		}
	}
	
	if (battery.size() > 0) {
		cout << endl << "BATTERY" << endl << "-------" << endl;
		cout << "Name\tPart #\tWeight\tCost\tEnergy\tPower\tDescription" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		for (i = 0; i < battery.size(); i++) {
			cout << battery[i].getName() << "\t" << battery[i].getPartNumber() << "\t" << battery[i].getWeight() << "\t" << battery[i].getCost() << "\t" << battery[i].getEnergy() << "\t" << battery[i].getMaxPower() << "\t" << battery[i].getDescription() << endl;
		}
	}

	if (torso.size() > 0) {
		cout << endl << "TORSO" << endl << "-----" << endl;
		cout << "Name\tPart #\tWeight\tCost\tBattery\tDescription" << endl;
		cout << "---------------------------------------------------" << endl;
		for (i = 0; i < torso.size(); i++) {
			cout << torso[i].getName() << "\t" << torso[i].getPartNumber() << "\t" << torso[i].getWeight() << "\t" << torso[i].getCost() << "\t" << torso[i].getCompartments() << "\t" << torso[i].getDescription() << endl;
		}
	}

	if (locomotor.size() > 0) {
		cout << endl << "LOCOMOTOR" << endl << "---------" << endl;
		cout << "Name\tPart #\tWeight\tCost\tSpeed\tDescription" << endl;
		cout << "---------------------------------------------------" << endl;
		for (i = 0; i < locomotor.size(); i++) {
			cout << locomotor[i].getName() << "\t" << locomotor[i].getPartNumber() << "\t" << locomotor[i].getWeight() << "\t" << locomotor[i].getCost() << "\t" << locomotor[i].getMaxSpeed() << "\t" << locomotor[i].getDescription() << endl;
		}
	}				

}

void makeOrder(vector<RobotHead> &head, vector<RobotArm> &arm, vector<RobotBattery> &battery, vector<RobotTorso> &torso, vector<RobotLocomotor> &locomotor, vector<RobotModel> &model, Order &order) {
	int choice, part, request, index, i;
	bool flag = true;
	bool match = false;
	do
	{
		cout << "\nORDER" << endl << "-----" << endl;
		cout << "1 - Buy a Model\n";
		cout << "2 - Buy a Component\n";
		cout << "3 - Quit to Create Menu\n";
		cout << "Your Choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			if (model.size() != 0) {
				cout << "MODELS" << endl << "----" << endl;
				cout << "Name\t\t\tModel#\tMax Speed\tCost\t" << endl;
				cout << "----------------------------------------------------" << endl;
				for (i = 0; i < model.size(); i++) {
					cout << model[i].getName() << "\t" << model[i].getModelNumber() << "\t" << model[i].getMaxSpeed() << "\t\t" << model[i].getPrice() << endl;
				}
                cout << "Enter The Part # Of The Robot Model You Desire: ";
                cin >> request;
                match = false;
                for (i = 0; i < model.size(); i++) {
                    if (model[i].getModelNumber() == request) {
                        order.addRobotModel(model[i]);
                        match = true;
                        index = i;
                    }
                }

                if (match == false) {
                    cout<<"\nThe Part # Of The Head You Desire Is Currently Not Available\n"<< endl;
                }
                else {
                    cout << model[index].getName()<<" has been added to your cart"<< endl;
					
					//update the orders vector with the checked out item
					//remove the checked out item from the vectors
					model.erase(model.begin()+(index));
                }

			}


			break;
		case 2:
			cout << "\n1 - Buy a Head\n";
			cout << "2 - Buy an Arm\n";
			cout << "3 - Buy a Battery\n";
			cout << "4 - Buy a Torso\n";
			cout << "5 - Buy a Locomotor\n";
			cout << "Your Choice:";
			cin >> part;
			cout << "\n";
			if(part == 1)
			{
				if (head.size() != 0) {
					cout << "HEAD" << endl << "----" << endl;
					cout << "Name\tPart #\tWeight\tCost\tDescription" << endl;
					cout << "-------------------------------------------" << endl;
					for (i = 0; i < head.size(); i++) {
						cout << head[i].getName() << "\t" << head[i].getPartNumber() << "\t" << head[i].getWeight() << "\t" << head[i].getCost() << "\t" << head[i].getDescription() << endl;
					}
				}
				cout<<"\nEnter The Part # Of The Head You Desire: ";
				cin>>request;

				for (int i = 0; i < head.size(); ++i )
				{
					if( request == head[i].getPartNumber() ) 
					{   
                        order.addRobotPart(head[i]);
						match = true;
						index = i;
						break;
					}
				}

				if(match == false)
				{
					cout<<"\nThe Part # Of The Head You Desire Is Currently Not Available\n"<< endl;
				}
				else
     			{
          			cout <<head[index].getName()<<" has been added to your cart"<< endl;
					
					//update the orders vector with the checked out item
					//remove the checked out item from the vectors
					head.erase(head.begin()+(index));			 
				}
			}
			else if(part == 2)
			{
				if (arm.size() != 0) {
					cout << endl << "ARM" << endl << "---" << endl;
					cout << "Name\tPart #\tWeight\tCost\tDescription" << endl;
					cout << "-------------------------------------------" << endl;
					for (i = 0; i < arm.size(); i++)
						cout << arm[i].getName() << "\t" << arm[i].getPartNumber() << "\t" << arm[i].getWeight() << "\t" << arm[i].getCost() << "\t" << arm[i].getDescription() << endl;
				}
				cout<<"\nEnter The Part # Of The Arm You Desire: ";
				cin>>request;

				for (int i = 0; i < arm.size(); ++i )
				{
					if( request == arm[i].getPartNumber() ) 
					{   
                        order.addRobotPart(arm[i]);
						match = true;
						index = i;
						break;
					}
				}

				if(match == false)
				{
					cout<<"\nThe Part # Of The Arm You Desire Is Currently Not Available\n"<< endl;
				}
				else
     			{
          			cout<<arm[index].getName()<<" has been added to your cart"<< endl;

					//update the orders vector with the checked out item
					//remove the checked out item from the vectors
					arm.erase(arm.begin()+(index));
				}
			}
			else if(part == 3)
			{
				if (battery.size() != 0) {
					cout << endl << "BATTERY" << endl << "-------" << endl;
					cout << "Name\tPart #\tWeight\tCost\tEnergy\tMax Power\tDescription" << endl;
					cout << "-------------------------------------------------------------------" << endl;
					for (i = 0; i < battery.size(); i++)
						cout << battery[i].getName() << "\t" << battery[i].getPartNumber() << "\t" << battery[i].getWeight() << "\t" << battery[i].getCost() << "\t" << battery[i].getEnergy() << "\t" << battery[i].getMaxPower() << "\t" << battery[i].getDescription() << endl;
				}

				cout<<"\nEnter The Part # Of The Battery You Desire: ";
				cin>>request;

				for (int i = 0; i < battery.size(); ++i )
				{
					if( request == battery[i].getPartNumber() ) 
					{   
                        order.addRobotPart(battery[i]);
						match = true;
						index = i;
						break;
					}
				}

				if(match == false)
				{
					cout<<"\nThe Part # Of The Battery You Desire Is Currently Not Available\n"<< endl;
				}
				else
     			{
          			cout<<battery[index].getName()<<" has been added to your cart"<< endl;
					//update the orders vector with the checked out item
					//remove the checked out item from the vectors
					battery.erase(battery.begin()+(index));
				}
			}
			else if(part == 4)
			{
				if (torso.size() != 0) {
					cout << endl << "TORSO" << endl << "-----" << endl;
					cout << "Name\tPart #\tWeight\tCost\t\tBattery Compartments\tDescription" << endl;
					cout << "----------------------------------------------------------" << endl;
					for (i = 0; i < torso.size(); i++)
						cout << torso[i].getName() << "\t" << torso[i].getPartNumber() << "\t" << torso[i].getWeight() << "\t" << torso[i].getCost() << "\t" << torso[i].getCompartments() << "\t" << torso[i].getDescription() << endl;
				}
				cout<<"\nEnter The Part # Of The Torso You Desire: ";
				cin>>request;

				for (int i = 0; i < torso.size(); ++i )
				{
					if( request == torso[i].getPartNumber() ) 
					{   
                        order.addRobotPart(torso[i]);
						match = true;
						index = i;
						break;
					}
				}

				if(match == false)
				{
					cout<<"\nThe Part # Of The Torso You Desire Is Currently Not Available\n"<< endl;
				}
				else
     			{
          			cout<<torso[index].getName()<<" has been added to your cart"<< endl;
					//update the orders vector with the checked out item
					//remove the checked out item from the vectors
					torso.erase(torso.begin()+(index));
				}
			}
			else if(part == 5)
			{
				if (locomotor.size() != 0) {
					cout << endl << "LOCOMOTOR" << endl << "---------" << endl;
					cout << "Name\tPart #\tWeight\tCost\tMax Speed\tDescription" << endl;
					cout << "----------------------------------------------------------" << endl;
					for (i = 0; i < locomotor.size(); i++)
						cout << locomotor[i].getName() << "\t" << locomotor[i].getPartNumber() << "\t" << locomotor[i].getWeight() << "\t" << locomotor[i].getCost() << "\t" << locomotor[i].getMaxSpeed() << "\t" << locomotor[i].getDescription() << endl;
				}

				cout<<"\nEnter The Part # Of The Locomotor You Desire: ";
				cin>>request;

				for (int i = 0; i < locomotor.size(); ++i )
				{
					if( request == locomotor[i].getPartNumber() ) 
					{   
                        order.addRobotPart(locomotor[i]);
						match = true;
						index = i;
						break;
					}
				}

				if(match == false)
				{
					cout<<"\nThe Part # Of The Locomotor You Desire Is Currently Not Available\n"<< endl;
				}
				else
     			{
          			cout<<locomotor[index].getName()<<" has been added to your cart"<< endl;
					//update the orders vector with the checked out item
					//remove the checked out item from the vectors
					locomotor.erase(locomotor.begin()+(index));
				}
			}
		case 3:
			flag = false;
			break;
			default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			cin >> choice;
			break;
		}
	}while(flag != false);
}

void viewCustomer(Order &order) {
    cout << "\nCUSTOMERS" << endl;
    cout << "---------" << endl;
    cout << order.this_customer->getName() << endl;
}


void viewOrder(Order &order) {

    int i;
	cout<<"\nORDER:\n------"<< endl;
    cout << "Customer Name: " << order.this_customer->getName() << endl;
	for(i = 0; i < order.robotModels.size(); ++i)
     {
         cout << order.robotModels[i].getName() << "\t\t$" << order.robotModels[i].getPrice() << endl;
     }

     for (i = 0; i < order.robotParts.size() ; i++) {
        cout << order.robotParts[i].getName() << "\t\t$" << order.robotParts[i].getCost() << endl;
     }
     order.robotPrice();
	 cout<<"TOTAL: $"<<order.totalPrice()<< endl;
}

void viewBill(Order &order) {

    int i, shipping = 10, tax = 0, total = 0;
	cout<<"\nBILL:\n-----"<< endl;
    cout << "Customer Name: " << order.this_customer->getName() << endl;
	for(i = 0; i < order.robotModels.size(); ++i)
    {
         cout << order.robotModels[i].getName() << "\t\t$" << order.robotModels[i].getPrice() << endl;
    }

     for (i = 0; i < order.robotParts.size() ; i++) {
        cout << order.robotParts[i].getName() << "\t\t$" << order.robotParts[i].getCost() << endl;
     }
     order.robotPrice();
	 tax = order.totalPrice() * 0.0825;
	 cout<<"SHIPPING: $"<<shipping<< endl;
	 cout<<"TAX: $"<<tax<<endl;
	 cout<<"TOTAL: $"<<order.totalPrice()+tax+shipping<< endl;
}

void createMenu(vector<RobotHead> &head, vector<RobotArm> &arm, vector<RobotBattery> &battery, vector<RobotTorso> &torso, vector<RobotLocomotor> &locomotor, vector<RobotModel> &model, Order &order) {
	int choice;
	bool flag = true;
	do
	{
		cout << "\nCREATE" << endl << "------" << endl;
		cout << "1 - Order\n";
		cout << "2 - Customer\n";
		cout << "3 - Robot Models\n";
		cout << "4 - Robot Components\n";
		cout << "5 - Quit to Main Menu\n";
		cout << "Your Choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			makeOrder(head, arm, battery, torso, locomotor, model, order);
			break;
		case 2:
			cout << "Customer\n";
            viewCustomer(order);
			// rest of code here
			break;
		case 3:
			cout << "Robot Model\n";
			robotModel(model);
			break;
		case 4:
			cout << "Robot Component\n";
			robotComponent(head, arm, battery, torso, locomotor);
			break;
		case 5:
			cout << "Quit to Main Menu\n";
			flag = false;
			break;
			default:
			cout << "Not a Valid Choice \n";
			cout << "Please Choose Again: ";
			cin >> choice;
			break;
		}
	} while (flag != false);
}


void createReport(vector<RobotHead> &head, vector<RobotArm> &arm, vector<RobotBattery> &battery, vector<RobotTorso> &torso, vector<RobotLocomotor> &locomotor, vector<RobotModel> &model, Order &order) {
	int choice;
	bool flag = true;
	do
	{
		cout << "\nREPORT" << endl << "------" << endl;
		cout << "1 - View Order\n";
		cout << "2 - View Bill\n";
		cout << "3 - Quit to Main Menu\n";
		cout << "Your Choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			viewOrder(order);
			break;
		case 2:
			viewBill(order);
			break;
		case 3:
			cout << "Quit to Main Menu\n";
			flag = false;
			break;
			default:
			cout << "Not a Valid Choice \n";
			cout << "Please Choose Again: ";
			cin >> choice;
			break;
		}
	} while (flag != false);
}


*/
