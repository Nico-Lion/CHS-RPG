/* Author: Nico Lionetti
Filename: RPG.cpp
Project Name: RPG
Purpose: To be a playable RPG.
Pseudocode: Declares Variables, HP, AP, and name, Introduces player to the game and begins the story.
Maintenance Log: Created 9/25/19
Continued 9/26/19
Continued 9/27/19
Cotinued 9/30/19
Continued 10/25/19
Continued 10/29/19
Continued 10/4/19
Continued 10/5/19
Continued 10/7/19
Continued 10/8/19
Continued 1/27/20
Continued 1/28/20
Continued 1/29/20
Continued 2/24/20
Continued 2/25/20
Continued 2/27/20
Continued 3/2/20
Continued 3/3/20
Continued 4/15/20
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <atomic>
#include <iostream>
#include <fstream>
using namespace std;

struct Monster
{
	int HP, AP, DP, GV;
	bool dead, claimed, found;
};
struct Player
{
	int HP, AP, DP, GP, SC, Room, Choice;
	string name;
	bool PenA, PenB, PenC, PenD, Flee; // Miyoshi, Wrestling, Theater, Counseling Center

};
int PAttack(int PAP, int MDP)
{
	int Return;
	Return = PAP - MDP;
	return Return;
}
int MAttack(int MAP, int PDP)
{
	int Return;
	Return = MAP - PDP;
	return Return;
}
int EntranceF()
{
	string Entrance;
	int Room = 1;
	bool Run = false;
	// Entrance 
	while (Run == false)
	{
		printf("Where would you like to enter? The West entrance, or the South entrance, or the East entrance?\n");
		getline(cin, Entrance);
		printf("\n");
		// West Entrance
		if (Entrance == "West")
		{
			printf("You have chosen the %s entrance.\n", Entrance.c_str());
			Room = 1;
			Run = true;
			return Room;
		}
		// South Entrance
		else if (Entrance == "South")
		{
			printf("You have chosen the %s entrance.\n", Entrance.c_str());
			Room = 2;
			Run = true;
			return Room;
		}
		// East Entrance
		else if (Entrance == "East")
		{
			printf("You have chosen the %s entrance.\n", Entrance.c_str());
			Room = 3;
			Run = true;
			return Room;

		}
		// Error Loop
		else
		{
			printf("That is not an option, please try again!\n");
			Run = false;
		}
	}
	return Room;
}

int main()
{
	// Files
	ifstream inL;
	// Players Monsters Setup

	// Init
	Player User;
	int NdmgM = 0;
	int NdmgP = 0;
	bool Run = false;
	bool EntranceRun = false;

	// Declare
	printf("Would you like to start again or load a saved game?\n1) Restart\n2) Load a Saved Game\n");
	int temp;
	cin >> temp;

	if (temp == 1)
	{
		inL.open("BaseState.txt");
		if (!inL.is_open())
		{
			printf("File Not Found\n");
			return 0;
		}
	}
	else if (temp == 2)
	{
		inL.open("SaveState.txt");
		if (!inL.is_open())
		{
			printf("File Not Found\n");
			return 0;
		}
	}
	else
	{
		printf("An error has occured, the program will now close.\n");
		return 0;
	}


	// Save/Load
	string baseload;
	// Monsters
	Monster Buffer;
	Monster Lunchroom;
	Monster Server;
	Monster Kiln;
	Monster Gym;
	Monster Brodie;
	int o = 0;
	for (int i = 0; i < 5; i++)
	{
		getline(inL, baseload, ',');
		Buffer.HP = stoi(baseload);
		getline(inL, baseload, ',');
		Buffer.AP = stoi(baseload);
		getline(inL, baseload, ',');
		Buffer.DP = stoi(baseload);
		getline(inL, baseload, ',');
		Buffer.GV = stoi(baseload);
		getline(inL, baseload, ',');
		Buffer.claimed = stoi(baseload);
		getline(inL, baseload, ',');
		Buffer.dead = stoi(baseload);
		getline(inL, baseload);
		Buffer.found = stoi(baseload);
		o++;
		if (o == 1)
		{
			Lunchroom.HP = Buffer.HP;
			Lunchroom.AP = Buffer.AP;
			Lunchroom.DP = Buffer.DP;
			Lunchroom.GV = Buffer.GV;
			Lunchroom.claimed = Buffer.claimed;
			Lunchroom.dead = Buffer.dead;
			Lunchroom.found = Buffer.found;
		}
		if (o == 2)
		{
			Server.HP = Buffer.HP;
			Server.AP = Buffer.AP;
			Server.DP = Buffer.DP;
			Server.GV = Buffer.GV;
			Server.claimed = Buffer.claimed;
			Server.dead = Buffer.dead;
			Server.found = Buffer.found;
		}
		if (o == 3)
		{
			Kiln.HP = Buffer.HP;
			Kiln.AP = Buffer.AP;
			Kiln.DP = Buffer.DP;
			Kiln.GV = Buffer.GV;
			Kiln.claimed = Buffer.claimed;
			Kiln.dead = Buffer.dead;
			Kiln.found = Buffer.found;
		}
		if (o == 4)
		{
			Gym.HP = Buffer.HP;
			Gym.AP = Buffer.AP;
			Gym.DP = Buffer.DP;
			Gym.GV = Buffer.GV;
			Gym.claimed = Buffer.claimed;
			Gym.dead = Buffer.dead;
			Gym.found = Buffer.found;
		}
		if (o == 5)
		{
			Brodie.HP = Buffer.HP;
			Brodie.AP = Buffer.AP;
			Brodie.DP = Buffer.DP;
			Brodie.GV = Buffer.GV;
			Brodie.claimed = Buffer.claimed;
			Brodie.dead = Buffer.dead;
			Brodie.found = Buffer.found;
		}
	}
	// Player
	getline(inL, baseload, ',');
	User.HP = stoi(baseload);
	getline(inL, baseload, ',');
	User.AP = stoi(baseload);
	getline(inL, baseload, ',');
	User.DP = stoi(baseload);
	getline(inL, baseload, ',');
	User.GP = stoi(baseload);
	getline(inL, baseload, ',');
	User.SC = stoi(baseload);
	getline(inL, baseload, ',');
	User.Room = stoi(baseload);
	getline(inL, baseload, ',');
	User.Choice = stoi(baseload);
	getline(inL, baseload, ',');
	User.PenA = stoi(baseload);
	getline(inL, baseload, ',');
	User.PenB = stoi(baseload);
	getline(inL, baseload, ',');
	User.PenC = stoi(baseload);
	getline(inL, baseload, ',');
	User.PenD = stoi(baseload);
	getline(inL, baseload, '\n');
	User.Flee = stoi(baseload);
	inL.close();

	// Room Setup
	/* Rooms are based on Room numbers, West hall is 1, South hall is 2,
	Commons is 3, Bathroom is 4, Counseling Center is 5,
	Career Center is 6, Gym is 7, Library is 8, Wrestling Room is 9*/
	bool Shop1 = true;
	bool Shop2 = true;
	bool Shop3 = true;
	Run = true;
	string Entrance;


	// Name Input
	printf("Welcome Traveler, I am Falconhoof and I will be your guide\nWhat is your name traveler?\n");
	string Namein;
	cin >> Namein;
	User.name = Namein;
	printf("\n");

	// Name Responses
	if (Namein == "Victory")
	{
		printf("You have slain the great beast that conquered the school!\n\nCongratulations, You Win!\n\n");
		return 0;
	}
	else if (Namein == "Failure")
	{
		Run = false;
	}
	else
	{
		printf("Ah, %s is it, well be off on your quest, You have %i Health and %i Attack and %i Defense\n", User.name.c_str(), User.HP, User.AP, User.DP);
		EntranceRun = true;
	}

	// Entrance
	User.Room = EntranceF();

	// Rooms
	while (Run == true)
	{
		// West hall, Entrance Complete
		while (User.Room == 1)
		{
			User.Choice = 0;
			printf("You are in the West Hallway, Where would you like to go?\n1) Into the art room on the left\n2) Into the Computer room on the right\n3) Into the server room down the hall\n4) Into the Shop on the left\n5) Into the large room at the end of the hallway.\n");
			cin >> (User.Choice);
			printf("\n");
			fseek(stdin, 0, SEEK_END);
			if (User.Choice == 1)
			{
				printf("You have chosen to go into the Art Room.\n");
				User.Room = 141;
			}
			else if (User.Choice == 2)
			{
				printf("You have chosen to go into the Computer Room.\n");
				User.Room = 126;
			}
			else if (User.Choice == 3)
			{
				printf("You have chosen to go into the Server Room.\n");
				User.Room = 140;
			}
			else if (User.Choice == 4)
			{
				printf("You have chosen to go into the Shop Room.\n");
				User.Room = 149;
			}
			else if (User.Choice == 5)
			{
				printf("You have chosen to go into the large Room.\n");
				User.Room = 3;
			}
			else
			{
				printf("Unacceptable input, please try again.\n");
			}
		}
		// South Hall, Entrance Complete
		while (User.Room == 2)
		{
			User.Choice = 0;
			printf("You are in the South Hallway, Where would you like to go?\n1) Into the bathroom on the left\n2) Into the counseling center on the right\n3) Into the large room at the end of the hallway\n");
			cin >> (User.Choice);
			printf("\n");
			if (User.Choice == 1)
			{
				printf("The Bathroom is closed, you cannot get in.\n");
				User.Room = 2;
			}
			else if (User.Choice == 2)
			{
				printf("You have chosen to go into the counseling center\n");
				User.Room = 5;
			}
			else if (User.Choice == 3)
			{
				printf("You have chosen to go into the large room.\n");
				User.Room = 3;
			}
			else
			{
				printf("Unacceptable input, please try again.\n");
			}
		}
		// Commons, Lunch Monster Encounter, Entrance Complete
		while (User.Room == 3)
		{
			User.Flee = false;
			//Flee/dead bounce
			if (Lunchroom.dead == true || User.Flee == true)
			{
				printf("You return to the hallway.\n");
				User.Room = 1;
			}
			//Combat
			if (Lunchroom.dead == false && User.Flee == false)
			{
				//Intro
				if (Lunchroom.found == false)
				{
					printf("You discover a great beast,\nit is comprised of tables and trashcans.\nIt lumbers forwards to engange you!\nIt has %i Health, %i Defense, and %i Attack\n", Lunchroom.HP, Lunchroom.DP, Lunchroom.AP);
					Lunchroom.found = true;
				}
				if (Lunchroom.HP > 0)
				{
					printf("The Monster has %i Health, You have %i Health,\nWhat would you like to do?\n1) Attack\n2) Run Away\n", Lunchroom.HP, User.HP);
					User.Choice = 0;
					cin >> User.Choice;
					if (User.Choice == 1)
					{
						NdmgP = PAttack(User.AP, Lunchroom.DP);
						NdmgM = MAttack(Lunchroom.AP, User.DP);
						if (NdmgP > 0)
						{
							Lunchroom.HP = Lunchroom.HP - NdmgP;
							printf("You attack the Monster for %i damage,\nDue to its defense it only recieves %i damage,\nThe monster now has %i Health.\n", User.AP, NdmgP, Lunchroom.HP);
						}
						else
						{
							printf("You attack the Monster for %i damage,\nDue to its defense it recieves no damage.\n", User.AP);
						}
						if (NdmgM > 0)
						{
							User.HP = User.HP - NdmgM;
							printf("The Monster attacks you for %i damage,\nDue to your defense you only recieve %i damage,\n You now have %i Health.\n", Lunchroom.AP, NdmgM, User.HP);
						}
						else
						{
							printf("The Monster attacks you for %i damage,\nDue to your defense you recieve no damage.\n", Lunchroom.AP);
						}
					}
					else if (User.Choice == 2)
					{
						User.Flee = true;
					}
				}
				//Victory
				else
				{
					printf("The Beast is slain\nIn the ruins of the beast you discover a sandwich.\n+15 HP\n+10 GP\n");
					User.HP = User.HP + 15;
					User.GP = User.GP + 10;
					Lunchroom.claimed = true;
					Lunchroom.dead = true;
				}
			}
			if (Lunchroom.claimed == true)
			{
				User.Choice = 0;
				printf("You are in the Commons, Where would you like to go?\n1) The Gym\n2) The West Hall\n3) The South Hall\n4) The Career Center\n5) The Theater\n");
				cin >> (User.Choice);
				printf("\n");
				if (User.Choice == 1)
				{
					printf("You have chosen to go into the Gym\n");
					User.Room = 7;
				}
				else if (User.Choice == 2)
				{
					printf("You have chosen to go into the West Hall\n");
					User.Room = 1;
				}
				else if (User.Choice == 3)
				{
					printf("You have chosen to go into the The South Hall\n");
					User.Room = 2;
				}
				else if (User.Choice == 4)
				{
					printf("You have chosen to go into the Career Center\n");
					User.Room = 6;
				}
				else if (User.Choice == 5)
				{
					printf("You have chosen to go into the Theater\n");
					User.Room = 164;
				}
				else
				{
					printf("Unacceptable input, please try again.\n");
				}
			}
		}
		// Gym, Gym Monster Encounter Complete
		while (User.Room == 7)
		{
			User.Flee = false;
			//Flee/dead bounce
			if (Gym.dead == true || User.Flee == true)
			{
				printf("You return to the hallway.\n");
				User.Room = 1;
			}
			//Combat
			if (Gym.dead == false && User.Flee == false)
			{
				//Intro
				if (Gym.found == false)
				{
					printf("You discover a great beast,\nit is comprised of barbells and mats.\nIt lumbers forwards to engange you!\nIt has %i Health, %i Defense, and %i Attack\n", Kiln.HP, Kiln.DP, Kiln.AP);
					Gym.found = true;
				}
				if (Gym.HP > 0)
				{
					printf("The Monster has %i Health, You have %i Health,\nWhat would you like to do?\n1) Attack\n2) Run Away\n", Gym.HP, User.HP);
					User.Choice = 0;
					cin >> User.Choice;
					if (User.Choice == 1)
					{
						NdmgP = PAttack(User.AP, Kiln.DP);
						NdmgM = MAttack(Kiln.AP, User.DP);
						if (NdmgP > 0)
						{
							Gym.HP = Gym.HP - NdmgP;
							printf("You attack the Monster for %i damage,\nDue to its defense it only recieves %i damage,\nThe monster now has %i Health.\n", User.AP, NdmgP, Gym.HP);
						}
						else
						{
							printf("You attack the Monster for %i damage,\nDue to its defense it recieves no damage.\n", User.AP);
						}
						if (NdmgM > 0)
						{
							User.HP = User.HP - NdmgM;
							printf("The Monster attacks you for %i damage,\nDue to your defense you only recieve %i damage,\n You now have %i Health.\n", Gym.AP, NdmgM, User.HP);
						}
						else
						{
							printf("The Monster attacks you for %i damage,\nDue to your defense you recieve no damage.\n", Gym.AP);
						}
					}
					else if (User.Choice == 2)
					{
						User.Flee = true;
					}
				}
				//Victory
				else
				{
					printf("The Beast is slain\nIn the ruins of the beast you discover a protein shake.\n+15 HP\n+10 GP\n");
					User.HP = User.HP + 15;
					User.GP = User.GP + 10;
					Gym.claimed = true;
					Gym.dead = true;
				}
			}
			printf("Where would you like to go?\n1) The Wrestling Room\n2) The Commons\n");
			User.Choice = 0;
			cin >> User.Choice;
			fseek(stdin, 0, SEEK_END);
			if (User.Choice == 1)
			{
				printf("You have chosen to go into The Wrestling Room.\n");
				User.Room = 9;
			}
			else if (User.Choice == 2)
			{
				printf("You have chosen to go into The Commons.\n");
				User.Room = 3;
			}
			else
			{
				printf("That is not an option, please try again.\n");
			}
		}
		// Library, Brodie/REDD Encounter, Final Boss Complete 1111111111111111
		while (User.Room == 8)
		{
			User.Flee = false;
			//Flee/dead bounce
			if (Brodie.dead == true || User.Flee == true)
			{
				printf("You return to the hallway.\n");
				User.Room = 1;
			}
			//Combat
			if (Brodie.dead == false && User.Flee == false)
			{
				//Intro
				if (Brodie.found == false)
				{
					printf("You discover a great beast,\nit is comprised of tables and trashcans.\nIt lumbers forwards to engange you!\nIt has %i Health, %i Defense, and %i Attack\n", Brodie.HP, Brodie.DP, Brodie.AP);
					Brodie.found = true;
				}
				if (Brodie.HP > 0)
				{
					printf("The Monster has %i Health, You have %i Health,\nWhat would you like to do?\n1) Attack\n2) Run Away\n", Brodie.HP, User.HP);
					User.Choice = 0;
					cin >> User.Choice;
					if (User.Choice == 1)
					{
						NdmgP = PAttack(User.AP, Brodie.DP);
						NdmgM = MAttack(Brodie.AP, User.DP);
						if (NdmgP > 0)
						{
							Brodie.HP = Brodie.HP - NdmgP;
							printf("You attack the Monster for %i damage,\nDue to its defense it only recieves %i damage,\nThe monster now has %i Health.\n", User.AP, NdmgP, Brodie.HP);
						}
						else
						{
							printf("You attack the Monster for %i damage,\nDue to its defense it recieves no damage.\n", User.AP);
						}
						if (NdmgM > 0)
						{
							User.HP = User.HP - NdmgM;
							printf("The Monster attacks you for %i damage,\nDue to your defense you only recieve %i damage,\n You now have %i Health.\n", Brodie.AP, NdmgM, User.HP);
						}
						else
						{
							printf("The Monster attacks you for %i damage,\nDue to your defense you recieve no damage.\n", Brodie.AP);
						}
					}
					else if (User.Choice == 2)
					{
						User.Flee = true;
					}
				}
				//Victory
				else
				{
					printf("You have slain the beast that has conquered the school!\n Congratulations you win!\n\n");
					return o;
				}
			}
		}
		// Art room, kiln monster encounter Complete
		while (User.Room == 141)
		{
			User.Flee = false;
			//Flee/dead bounce
			if (Kiln.dead == true || User.Flee == true)
			{
				printf("You return to the hallway.\n");
				User.Room = 1;
			}
			//Combat
			if (Kiln.dead == false && User.Flee == false)
			{
				//Intro
				if (Kiln.found == false)
				{
					printf("You discover a great beast,\nit is comprised of clay and pottery shards.\nIt lumbers forwards to engange you!\nIt has %i Health, %i Defense, and %i Attack\n", Kiln.HP, Kiln.DP, Kiln.AP);
					Kiln.found = true;
				}
				if (Kiln.HP > 0)
				{
					printf("The Monster has %i Health, You have %i Health,\nWhat would you like to do?\n1) Attack\n2) Run Away\n", Kiln.HP, User.HP);
					User.Choice = 0;
					cin >> User.Choice;
					if (User.Choice == 1)
					{
						NdmgP = PAttack(User.AP, Kiln.DP);
						NdmgM = MAttack(Kiln.AP, User.DP);
						if (NdmgP > 0)
						{
							Kiln.HP = Kiln.HP - NdmgP;
							printf("You attack the Monster for %i damage,\nDue to its defense it only recieves %i damage,\nThe monster now has %i Health.\n", User.AP, NdmgP, Kiln.HP);
						}
						else
						{
							printf("You attack the Monster for %i damage,\nDue to its defense it recieves no damage.\n", User.AP);
						}
						if (NdmgM > 0)
						{
							User.HP = User.HP - NdmgM;
							printf("The Monster attacks you for %i damage,\nDue to your defense you only recieve %i damage,\n You now have %i Health.\n", Kiln.AP, NdmgM, User.HP);
						}
						else
						{
							printf("The Monster attacks you for %i damage,\nDue to your defense you recieve no damage.\n", Kiln.AP);
						}
					}
					else if (User.Choice == 2)
					{
						User.Flee = true;
					}
				}
				//Victory
				else
				{
					printf("The Beast is slain\nIn the ruins of the beast you discover a weapon.\n+15 ATK\n+10 GP\n");
					User.AP = User.AP + 15;
					User.GP = User.GP + 10;
					Kiln.claimed = true;
					Kiln.dead = true;
				}
			}
		}
		// Server room, server monster encounter Complete
		while (User.Room == 140)
		{
			User.Flee = false;
			//Flee/dead bounce
			if (Server.dead == true || User.Flee == true)
			{
				printf("You return to the hallway.\n");
				User.Room = 1;
			}
			//Combat
			if (Server.dead == false && User.Flee == false)
			{
				//Intro
				if (Server.found == false)
				{
					printf("You discover a great beast,\nit is comprised of several server racks and rolls of paper.\nIt lumbers forwards to engange you!\nIt has %i Health, %i Defense, and %i Attack\n", Server.HP, Server.DP, Server.AP);
					Server.found = true;
				}
				if (Server.HP > 0)
				{
					printf("The Monster has %i Health, You have %i Health,\nWhat would you like to do?\n1) Attack\n2) Run Away\n", Server.HP, User.HP);
					User.Choice = 0;
					cin >> User.Choice;
					if (User.Choice == 1)
					{
						NdmgP = PAttack(User.AP, Server.DP);
						NdmgM = MAttack(Server.AP, User.DP);
						if (NdmgP > 0)
						{
							Server.HP = Server.HP - NdmgP;
							printf("You attack the Monster for %i damage,\nDue to its defense it only recieves %i damage,\nThe monster now has %i Health.\n", User.AP, NdmgP, Server.HP);
						}
						else
						{
							printf("You attack the Monster for %i damage,\nDue to its defense it recieves no damage.\n", User.AP);
						}
						if (NdmgM > 0)
						{
							User.HP = User.HP - NdmgM;
							printf("The Monster attacks you for %i damage,\nDue to your defense you only recieve %i damage,\n You now have %i Health.\n", Server.AP, NdmgM, User.HP);
						}
						else
						{
							printf("The Monster attacks you for %i damage,\nDue to your defense you recieve no damage.\n", Server.AP);
						}
					}
					else if (User.Choice == 2)
					{
						User.Flee = true;
					}
				}
				//Victory
				else
				{
					printf("The Beast is slain\nIn the ruins of the beast you discover a piece of armor.\n+10 DEF\n+10 GP\n");
					User.DP = User.DP + 10;
					User.GP = User.GP + 10;
					Server.claimed = true;
					Server.dead = true;
				}
			}
		}
		// Shop, Item Shop Complete
		while (User.Room == 149)
		{
			printf("Welcome Traveller, to the Shop, I am Mr. Thomas.\nMy staff and I have bunkered down in My Office.\nI run a shop out of this room.\n");
			Shop2 = true;
			while (Shop2 == true)
			{
				User.SC = 0;
				printf("\nWhat would you like to buy? \nWe have Metal Flowers to increase your attack, Bird Houses to increase your defense, or Fire Blankets to increase your health.\n");
				printf("You have %i GP.\n1) Buy Metal Flowers for +20 ATK, Costing 5 GP\n2) Buy Bird Houses +20 DEF, Costing 5 GP\n3) Buy Fire Blankets +20 HP, Costing 5 GP\n4) Buy Nothing\n", User.GP);
				cin >> User.SC;
				printf("\n");
				fseek(stdin, 0, SEEK_END);
				if (User.SC == 1)
				{
					if (User.GP >= 5)
					{
						printf("Thank you for buying Metal Flowers, Your attack has increased by 20!\n");
						User.AP = User.AP + 20;
						User.SC = 0;
						User.GP = User.GP - 5;
					}
					else
					{
						printf("You do not have enough gold to buy this.\n");
						User.SC = 0;
					}
				}
				else if (User.SC == 2)
				{
					if (User.GP >= 5)
					{
						printf("Thank you for buying Bird Houses, Your defense has increased by 20!\n");
						User.DP = User.DP + 20;
						User.SC = 0;
						User.GP = User.GP - 5;
					}
					else
					{
						printf("You do not have enough gold to buy this.\n");
						User.SC = 0;
					}
				}
				else if (User.SC == 3)
				{
					if (User.GP >= 5)
					{
						printf("Thank you for buying Fire Blankets, Your health has increased by 20!\n");
						User.HP = User.HP + 20;
						User.SC = 0;
						User.GP = User.GP - 5;
					}
					else
					{
						printf("You do not have enough gold to buy this.\n");
						User.SC = 0;
					}
				}
				else if (User.SC == 4)
				{
					printf("Please Come Again, Goodbye\n");
					User.SC = 0;
					Shop2 = false;
				}
				else
				{
					printf("Please Choose an option.\n");
					User.SC = 0;
				}
			}
			printf("Where would you like to go?\n1) The West Hall\n2) The Commons\n");
			User.Choice = 0;
			cin >> (User.Choice);
			printf("\n");
			if (User.Choice == 1)
			{
				printf("You have chosen to go into The West Hall.\n");
				User.Room = 1;
			}
			else if (User.Choice == 2)
			{
				printf("You have chosen to go into The Commons.\n");
				User.Room = 3;
			}
			else
			{
				printf("That is not an option, please try again.\n");
			}
		}
		// Music room, Item Shop Complete
		while (User.Room == 163)
		{
			printf("Welcome Traveller, to the Music Room, I am Mr. Hughes.\nMy staff and I have bunkered down in the Theater.\nI run a shop out of this room.\n");
			Shop3 = true;
			while (Shop3 == true)
			{
				User.SC = 0;
				printf("\nWhat would you like to buy? \nWe have Trumpets to increase your attack, Tuba Helmets to increase your defense, or Drums to increase your health.\n");
				printf("You have %i GP.\n1) Buy Trumpet for +25 ATK, Costing 5 GP\n2) Buy Tuba Helmet +25 DEF, Costing 5 GP\n3) Buy Drums +25 HP, Costing 5 GP\n4) Buy Nothing\n", User.GP);
				cin >> User.SC;
				printf("\n");
				fseek(stdin, 0, SEEK_END);
				if (User.SC == 1)
				{
					if (User.GP >= 5)
					{
						printf("Thank you for buying Trumpet, Your attack has increased by 25!\n");
						User.AP = User.AP + 25;
						User.SC = 0;
						User.GP = User.GP - 5;
					}
					else
					{
						printf("You do not have enough gold to buy this.\n");
						User.SC = 0;
					}
				}
				else if (User.SC == 2)
				{
					if (User.GP >= 5)
					{
						printf("Thank you for buying Tuba Helmet, Your defense has increased by 25!\n");
						User.DP = User.DP + 25;
						User.SC = 0;
						User.GP = User.GP - 5;
					}
					else
					{
						printf("You do not have enough gold to buy this.\n");
						User.SC = 0;
					}
				}
				else if (User.SC == 3)
				{
					if (User.GP >= 5)
					{
						printf("Thank you for buying Drums, Your health has increased by 25!\n");
						User.HP = User.HP + 25;
						User.SC = 0;
						User.GP = User.GP - 5;
					}
					else
					{
						printf("You do not have enough gold to buy this.\n");
						User.SC = 0;
					}
				}
				else if (User.SC == 4)
				{
					printf("Please Come Again, Goodbye\n");
					User.SC = 0;
					Shop3 = false;
				}
				else
				{
					printf("Please Choose an option.\n");
					User.SC = 0;
				}
			}
			printf("Where would you like to go?\n1) The Theater\n2) The Gym\n3) The Commons\n");
			User.Choice = 0;
			cin >> (User.Choice);
			printf("\n");
			if (User.Choice == 1)
			{
				printf("You have chosen to go into The Theater.\n");
				User.Room = 164;
			}
			else if (User.Choice == 2)
			{
				printf("You have chosen to go into The Gym.\n");
				User.Room = 7;
			}
			else if (User.Choice == 3)
			{
				printf("You have chosen to go into The Commons.\n");
				User.Room = 3;
			}
			else
			{
				printf("That is not an option, please try again.\n");
			}
		}
		// Career Center, Item Shop Complete
		while (User.Room == 6)
		{
			User.Choice = 0;
			printf("Welcome Traveller, to the Career Center, I am Mr. Clifford.\nMy staff and I have bunkered down in the Counseling Center.\nI run a shop out of this room.\n");
			Shop1 = true;
			while (Shop1 == true)
			{
				User.SC = 0;
				printf("\nWhat would you like to buy? \nWe have Pencils to increase your attack, Notebooks to increase your defense, or Water to increase your health.\n");
				printf("You have %i GP.\n1) Buy Sharp Pencils for +15 ATK, Costing 5 GP\n2) Buy Notebook Armor +15 DEF, Costing 5 GP\n3) Buy water +15 HP, Costing 5 GP\n4) Buy Nothing\n", User.GP);
				cin >> User.SC;
				printf("\n");
				fseek(stdin, 0, SEEK_END);
				if (User.SC == 1)
				{
					if (User.GP >= 5)
					{
						printf("Thank you for buying Sharp Pencils, Your attack has increased by 15!\n");
						User.AP = User.AP + 15;
						User.SC = 0;
						User.GP = User.GP - 5;
					}
					else
					{
						printf("You do not have enough gold to buy this.\n");
						User.SC = 0;
					}
				}
				else if (User.SC == 2)
				{
					if (User.GP >= 5)
					{
						printf("Thank you for buying Notebook Armor, Your defense has increased by 15!\n");
						User.DP = User.DP + 15;
						User.SC = 0;
						User.GP = User.GP - 5;
					}
					else
					{
						printf("You do not have enough gold to buy this.\n");
						User.SC = 0;
					}
				}
				else if (User.SC == 3)
				{
					if (User.GP >= 5)
					{
						printf("Thank you for buying Water, Your health has increased by 15!\n");
						User.HP = User.HP + 15;
						User.SC = 0;
						User.GP = User.GP - 5;
					}
					else
					{
						printf("You do not have enough gold to buy this.\n");
						User.SC = 0;
					}
				}
				else if (User.SC == 4)
				{
					printf("Please Come Again, Goodbye\n");
					User.SC = 0;
					Shop1 = false;
				}
				else
				{
					printf("Please Choose an option.\n");
					User.SC = 0;
				}
			}
			printf("Where would you like to go?\n1) The Commons\n2) The Counseling Center\n");
			User.Choice = 0;
			cin >> (User.Choice);
			printf("\n");
			if (User.Choice == 1)
			{
				printf("You have chosen to go into The Commons.\n");
				User.Room = 3;
			}
			else if (User.Choice == 2)
			{
				printf("You have chosen to go into The Counseling Center.\n");
				User.Room = 5;
			}
			else
			{
				printf("That is not an option, please try again.\n");
			}
		}
		// Stage/Theater, NPC Encounter Complete
		while (User.Room == 164)
		{
			if (User.PenC == false)
			{
				printf("Welcome to the theater.\nAs the hero who has returned to liberate the school we present you with this gift.\n You have been given the Token of the Actors.\nIt will increase your health by 30.\n");
				User.PenC = true;
				User.HP = User.HP + 30;
			}
			printf("Where would you like to go?\n1) The Music Room\n2) The Commons\n");
			User.Choice = 0;
			cin >> User.Choice;
			fseek(stdin, 0, SEEK_END);
			if (User.Choice == 1)
			{
				printf("You have chosen to go into The Music Room.\n");
				User.Room = 163;
			}
			else if (User.Choice == 2)
			{
				printf("You have chosen to go into The Commons.\n");
				User.Room = 3;
			}
			else
			{
				printf("That is not an option, please try again.\n");
			}
		}
		// Wrestling Room, NPC Encounter Complete
		while (User.Room == 9)
		{
			if (User.PenB == false)
			{
				printf("Welcome to the Wrestling Room.\nAs the hero who has returned to liberate the school we present you with this gift.\n You have been given the Token of the Athletes.\nIt will increase your defense by 30.\n");
				User.PenB = true;
				User.DP = User.DP + 30;
			}
			printf("You head back into the Gym.\n");
			User.Room = 7;
		}
		// Miyoshi's room, NPC Encounter, Complete put trail in background, mayby easteregg? 
		while (User.Room == 126)
		{
			if (User.PenA == false)
			{
				printf("Welcome to the Computer Lab.\nAs the hero who has returned to liberate the school we present you with this gift.\n You have been given the Token of the Technologies.\nIt will increase your attack by 30.\n");
				User.PenA = true;
				User.AP = User.AP + 30;
			}
			printf("Would you like to save while here?\n1) Yes\n2) No\n");
			int saveg = 0;
			cin >> saveg;
			if (saveg == 1)
			{
				ofstream outS("Savestate.txt");
				printf("Your game has saved.\n\n");
				int q = 1;
				for (int i = 0; i < 5; i++)
				{
					if (q == 1)
					{
						Buffer.HP = Lunchroom.HP;
						Buffer.AP = Lunchroom.AP;
						Buffer.DP = Lunchroom.DP;
						Buffer.GV = Lunchroom.GV;
						Buffer.dead = Lunchroom.dead;
						Buffer.claimed = Lunchroom.claimed;
					}
					if (q == 2)
					{
						Buffer.HP = Server.HP;
						Buffer.AP = Server.AP;
						Buffer.DP = Server.DP;
						Buffer.GV = Server.GV;
						Buffer.dead = Server.dead;
						Buffer.claimed = Server.claimed;
					}
					if (q == 3)
					{
						Buffer.HP = Kiln.HP;
						Buffer.AP = Kiln.AP;
						Buffer.DP = Kiln.DP;
						Buffer.GV = Kiln.GV;
						Buffer.dead = Kiln.dead;
						Buffer.claimed = Kiln.claimed;
					}
					if (q == 4)
					{
						Buffer.HP = Gym.HP;
						Buffer.AP = Gym.AP;
						Buffer.DP = Gym.DP;
						Buffer.GV = Gym.GV;
						Buffer.dead = Gym.dead;
						Buffer.claimed = Gym.claimed;
					}
					if (q == 5)
					{
						Buffer.HP = Brodie.HP;
						Buffer.AP = Brodie.AP;
						Buffer.DP = Brodie.DP;
						Buffer.GV = Brodie.GV;
						Buffer.dead = Brodie.dead;
						Buffer.claimed = Brodie.claimed;
					}
					q++;
					baseload = to_string(Buffer.HP);
					outS << baseload << ',';
					baseload = to_string(Buffer.AP);
					outS << baseload << ',';
					baseload = to_string(Buffer.DP);
					outS << baseload << ',';
					baseload = to_string(Buffer.GV);
					outS << baseload << ',';
					baseload = to_string(Buffer.dead);
					outS << baseload << ',';
					baseload = to_string(Buffer.claimed);
					outS << baseload << '\n';
				}
				outS << User.HP << ',' << User.AP << ',' << User.DP << ',' << User.GP << ',' << User.SC << ',' << User.Room << ',' << User.Choice << ',' << User.PenA << ',' << User.PenB << ',' << User.PenC << ',' << User.PenD << ',' << User.Flee << '\n';
				outS.close();
			}
			printf("You head back into the hallway.\n");
			User.Room = 1;
		}
		// Counseling Center, NPC Encounter Complete
		while (User.Room == 5)
		{
			printf("Welcome to the Counseling Center.\n");
			if (User.PenD == false)
			{
				printf("As the hero who has returned to liberate the school we present you with this gift.\nYou have been given the Token of the Staff.\nIf you return here with all the other Tokens \nyou will be allowed to enter the library and \ndefeat the evil lord who has taken over the school.\n");
				User.PenD = true;
			}
			if (User.PenA == true && User.PenB == true && User.PenC == true && User.PenD == true)
			{
				printf("Would you like to enter the library and face the mighty REDD.\n1) Yes\n2) No\n");
				User.Choice = 0;
				cin >> (User.Choice);
				fseek(stdin, 0, SEEK_END);
				if (User.Choice == 1)
				{
					printf("\nI hope you are ready to face him.\n");
					User.Room = 8;
				}
				else
				{
					printf("\nWe hope you return soon to defeat him.\n");
					printf("Where would you like to go?\n1) The South Hallway\n2) The Career Center\n");
					cin >> (User.Choice);
					if (User.Choice == 1)
					{
						User.Room = 2;
					}
					else if (User.Choice == 2)
					{
						User.Room = 6;
					}
					else
					{
						printf("\nThat is not an acceptable option.\n");
					}
				}
			}
			else
			{
				printf("Where would you like to go?\n1) The South Hallway\n2) The Career Center\n");
				User.Choice = 0;
				cin >> (User.Choice);
				fseek(stdin, 0, SEEK_END);
				if (User.Choice == 1)
				{
					User.Room = 2;
				}
				else if (User.Choice == 2)
				{
					User.Room = 6;
				}
				else
				{
					printf("\nThat is not an acceptable option.\n");
				}
			}
		}
	}

	printf("You have failed in your quest, Game Over.\n");
	return 0;
}