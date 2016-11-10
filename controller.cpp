#include <iostream>
#include <vector>
#include <string>
#include "robot_model.h"
#include "robot_head.h"
#include "robot_part.h"
#include "robot_locomotor.h"
#include "robot_torso.h"
#include "robot_battery.h"
#include "robot_arm.h"
#include "view.h"
#include "order.h"
#include "customer.h"
#include "sales_associate.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_bar.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Input.H>


class OrderWindow;
class SelectPart;
void OrderCB(Fl_Widget *w, void *p);
void SelectPartCB(Fl_Widget *w, void *p);
void CreateRobotCB(Fl_Widget *w, void *p);
void CreatePartCB(Fl_Widget *w, void *p);

Fl_Window *win;
Fl_Menu_Bar *menubar;
View *view;
OrderWindow *orderWindow;
SelectPart *selectPart;
vector<RobotModel> robots;
vector<RobotHead> heads;
vector<RobotArm> arms;
vector<RobotBattery> batteries;
vector<RobotTorso> torsos;
vector<RobotLocomotor> locomotors;

class SelectPart {
	public:
		SelectPart() {
			window = new Fl_Window(340, 100, "Create Model");
			choice = new Fl_Choice(120, 20, 210, 25, "Type:");
			next = new Fl_Button(270, 50, 60, 25, "Next");

			next->callback((Fl_Callback *)CreatePartCB);

			choice->value(0);
			choice->add("Head", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Locomotor", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Torso", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Battery", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Arm", 0, (Fl_Callback *)SelectPartCB);
			choice->value(0);


		}

		void show() {
			window->show();
		}

		void createHead() {
			Fl_Window *head;
			Fl_Input *name;

			head = new Fl_Window(200,200, "Creating Head");
			name = new Fl_Input(200, 200, 30, 25, "Name:");
			head->show();
		}

	private:
		Fl_Window *window;
		Fl_Choice *choice;
		Fl_Button *next;
};

class OrderWindow {

	public:
		OrderWindow() {
			window = new Fl_Window(500,500, "Create Robot Part");
			button = new Fl_Button(50, 50, 60, 25, "Click me");
			choice = new Fl_Choice(100, 100, 130, 25, "Type:");
//			multiText = new Fl_Multiline_Output(200, 200, 100, 100);


			choice->add("Robot Model", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Robot Head", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Robot Locomotor", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Robot Torso", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Robot Battery", 0, (Fl_Callback *)SelectPartCB);
			choice->add("Robot Arm", 0, (Fl_Callback *)SelectPartCB);
			choice->value(0);

			button->callback((Fl_Callback *)OrderCB, 0);

//			multiText->value("Hello");

//			text = new Fl_Text_Selection();
			window->color(FL_WHITE);
			window->end();
		}

		void show() {
			window->show();
		}

		void hide() {
			window->hide();
		}

		int value() {
			cout << robots[0].getName();
			return choice->value();

		}



	private:
//		Fl_Text_Selection *text;
		Fl_Window *window;
		Fl_Button *button;
		Fl_Choice *choice;
//		Fl_Multiline_Output *multiText;
	
};





void PokeCB(Fl_Widget *w, void *p) {
	cout << "Hey\n";
}

void OrderRobotCB(Fl_Widget *w, void *p) {
	orderWindow->show();
}

void CreateRobotCB(Fl_Widget *w, void *p) {
	selectPart->show();
}

void SelectPartCB(Fl_Widget *w, void *p) {
	cout << "Changing choice\n";
}

void CreatePartCB(Fl_Widget *w, void *p) {
	selectPart->createHead();
}

void OrderCB(Fl_Widget *w, void *p) {
	cout << "Order going in\n";
}


Fl_Menu_Item menuitems[] = {
	{"&File", 0, 0, 0, FL_SUBMENU},
		{"&New", FL_ALT + 'N', (Fl_Callback *)PokeCB},
		{"&Open", FL_ALT + 'O', (Fl_Callback *)PokeCB},
		{"&Save", FL_ALT + 'S', (Fl_Callback *)PokeCB},
		{"&Save As", FL_ALT + 'H', (Fl_Callback *)PokeCB},
		{"&Quit", FL_ALT + 'Q', (Fl_Callback *)PokeCB},
		{0},
	{"&Edit", 0, 0, 0, FL_SUBMENU},
		{"&Undo", FL_ALT + 'Z', (Fl_Callback *)PokeCB},
		{"&Cut", FL_ALT + 'X', (Fl_Callback *)PokeCB},
		{"&Copy", FL_ALT + 'C', (Fl_Callback *)PokeCB},
		{"&Paste", FL_ALT + 'P', (Fl_Callback *)PokeCB},
		{0},
	{"&Create", 0, 0, 0, FL_SUBMENU},
		{"&Order", 0, (Fl_Callback *)OrderRobotCB, 0, FL_MENU_DIVIDER},
		{"&Customer", 0, (Fl_Callback *)PokeCB},
		{"&Sales Associate", 0, (Fl_Callback *)PokeCB, 0, FL_MENU_DIVIDER},
		{"&Robot Part", 0, (Fl_Callback *)CreateRobotCB},
		{"&Robot Model", 0, (Fl_Callback *)PokeCB},
		{0},
	{"&Report", 0, 0, 0, FL_SUBMENU},
		{"&Invoice", 0, (Fl_Callback *)PokeCB, 0, FL_MENU_DIVIDER},
		{"&All Orders", 0, (Fl_Callback *)PokeCB},
		{"&Order by Customer", 0, (Fl_Callback *)PokeCB},
		{"&Orders by Sales Associate", 0, (Fl_Callback *)PokeCB, 0, FL_MENU_DIVIDER},
		{"&All Customers", 0, (Fl_Callback *)PokeCB},
		{"&All Sales Associate", 0, (Fl_Callback *)PokeCB, 0, FL_MENU_DIVIDER},
		{"&All Robot Parts", 0, (Fl_Callback *)PokeCB},
		{0},
	{"&Help", 0, 0, 0, FL_SUBMENU},
		{"&Manual", 0, (Fl_Callback *)PokeCB},
		{"&About", 0, (Fl_Callback *)PokeCB},
		{0},
	{0}
};





int main() {

	
	vector<int> prices;
	vector<string> names;

	Customer Doug("Douglas", 1432, 1000000);
	SalesAssociate Brandon("Brandon", 342);
	Order order(&Doug, &Brandon, 35813);


	heads.push_back(RobotHead("Doug", 1100, 25, 110, "Doug's head"));
	heads.push_back(RobotHead("Michael", 1101, 50, 510, "Michael's head"));
	heads.push_back(RobotHead("Grant", 1102, 10, 50, "Grant's head"));
	heads.push_back(RobotHead("Goku", 1103, 11, 75, "Head that looks like Goku"));
	heads.push_back(RobotHead("Ang", 1104, 17, 120, "Head that looks like Ang"));

	arms.push_back(RobotArm("Model A", 2201, 10, 20, "Useless arm"));
	arms.push_back(RobotArm("Model B", 2202, 12, 35, "Swinging arm"));
	arms.push_back(RobotArm("Model R", 2215, 13, 40, "Karate Chop arm"));
	arms.push_back(RobotArm("Model X", 2224, 14, 50, "Can pick up cups"));
	arms.push_back(RobotArm("Model Z", 2226, 15, 1000, "Can pick up any object"));

	batteries.push_back(RobotBattery("Old", 3300, 2, 10, "Short lasting batteries", 10, 30));
	batteries.push_back(RobotBattery("Dura", 3302, 2, 5, "Long lasting batteries", 5, 30));
	batteries.push_back(RobotBattery("Rechargable", 3301, 4, 35, "Rechargable batteries", 15, 25));

	locomotors.push_back(RobotLocomotor("V2", 4400, 275, 200, "Slow", 20));
	locomotors.push_back(RobotLocomotor("V4", 4401, 350, 300, "Medium", 60));
	locomotors.push_back(RobotLocomotor("V8", 4402, 500, 400, "Fast", 140));

	torsos.push_back(RobotTorso("Ver. 1", 5500, 300, 5000, "Box Shaped Torso", 2));
	torsos.push_back(RobotTorso("Ver. 2", 5502, 300, 8000, "Gold Plated Torso", 2));
	torsos.push_back(RobotTorso("Ver. 3", 5501, 300, 5000, "Green Torso", 2));

	robots.push_back(RobotModel("The Hulking Monster", 7001));
	robots[0].addPart(heads[2]);
	robots[0].addPart(arms[2]);
	robots[0].addPart(batteries[2]);
	robots[0].addPart(locomotors[1]);
	robots[0].addPart(torsos[1]);
	robots.push_back(RobotModel("Very Boring Robot", 7002));
	robots[1].addPart(heads[0]);
	robots[1].addPart(arms[0]);
	robots[1].addPart(batteries[0]);
	robots[1].addPart(locomotors[0]);
	robots[1].addPart(torsos[0]);


// GUI


	win = new Fl_Window(250, 200, "Robot Store");
	menubar = new Fl_Menu_Bar(0,0, 250, 30);
	view = new View(0, 0, 250, 200);
	orderWindow = new OrderWindow;
	selectPart = new SelectPart;

	menubar->menu(menuitems);
	win->color(FL_WHITE);

	win->end();
	win->show();
	return(Fl::run());



























// Command Line Format

/*

	int choice;
	bool shopOpen = true;

	while (shopOpen != false)
	{
		cout << "\nMAIN MENU" << endl << "---------" << endl;
		cout << "1 - Create\n";
		cout << "2 - Report\n";
		cout << "3 - Quit\n";
		cout << "Your Choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Create Robot\n";
			createMenu(heads, arms, batteries, torsos, locomotors, robots, order);
			break;
		case 2:
			cout << "Report of Robot\n";
			createReport(heads, arms, batteries, torsos, locomotors, robots, order);
			break;
		case 3:
			cout << "End of Program.\n";
			shopOpen = false;
			break;
			default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			cin >> choice;
			break;
		}
	}
	

*/

}
