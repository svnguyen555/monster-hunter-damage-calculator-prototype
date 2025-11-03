#include "utils.h"

//Arrays
Weapon savedWeapons[2];
vector<Attack> savedAttacks;
vector<Combo> savedCombos;

int main() {
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
	//Anything with labeled green comment next to them are ok to change within this box
	savedWeapons[0] = Weapon(
		"burst 2",		//Name (Make sure it is surrounded by "")
		241,			//Raw (Use Display Raw)
		40,				//Elem (Use True Raw)
		1.32,			//Sharpness
		1.13,			//Elem Sharpness
		1.34,			//CritBoost
		1,			//CritElement
		1,				//Other raw multipliers
		1				//Other elem multipliers
	);				
	savedWeapons[1] = Weapon(
		"agi 2 off",			//Name (Make sure it is surrounded by "")
		239,			//Raw (Use Display Raw)
		38,				//Elem (Use True Raw)
		1.32,			//Sharpness
		1.13,			//Elem Sharpness
		1.34,			//CritBoost
		1,				//CritElement
		1,				//Other raw Multipliers
		1				//Other elem multipliers
	);				
	float rawMV = 0.53;	//Attack Motion Value
	float elemMV = 1;	//Elemental Motion Value
	float numOfHits=1;	//Amount of times attack hits
	rawHZV = 0.63;		//Monster Raw Hitzone Value
	elemHZV = 0.08;		//Monster Elemental Hitzone Value
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	/*savedAttacks.push_back(Attack("ed1", rawMV, elemMV, numOfHits));
	savedAttacks.push_back(Attack("ed2", 0.35, 1, 1));
	savedAttacks.push_back(Attack("ed2ii", 0.58, 1, 1));
	savedAttacks.push_back(Attack("savageTicks", 0.14, 0.2, 12));
	savedAttacks.push_back(Attack("impactPhialExplosions", 0.1*1.2, 0, 3, true));*/

	//savedCombos.push_back(Combo("Pizza Combo", savedAttacks));

	savedAttacks.push_back(Attack("lateral slash", 0.27, 1.2, 1));
	savedAttacks.push_back(Attack("return stroke", 0.28, 1.2, 1));
	savedAttacks.push_back(Attack("spinning rising slash", 0.39, 1.2, 1));
	savedAttacks.push_back(Attack("spinning reaper", 0.65, 1, 1));
	savedAttacks.push_back(Attack("charged chop 1st hit", 0.18, 1, 1));
	savedAttacks.push_back(Attack("charged chop 2nd hit", 0.28, 1.2, 1));
	savedAttacks.push_back(Attack("enhanced charged chop", 0.28, 1.25, 3));
	savedCombos.push_back(Combo("sns", savedAttacks));


	displayWeaponStatComparisons(savedWeapons[0], savedWeapons[1]);
	displayComboComparison(savedCombos[0], savedWeapons[0], savedWeapons[1]);

	//displayMenu();
}

















void displayMenu() {
	while (true) { // Main menu loop
		system("cls"); // Clear screen (Windows)

		displayWeaponStatComparisons(savedWeapons[0], savedWeapons[1]);
		// Menu options
		printf("[Main Menu]\n");
		std::cout << "[1] Edit Weapons and Hitzone Values\n"
			<< "[2] Create Attack\n"
			<< "[3] Edit Attack\n"
			<< "[4] Create Combo\n"
			<< "[5] Edit Combo\n"
			<< "[6] Exit\n\n"  // Added exit option
			<< "Enter your choice [1-6]: ";

		int choice = getValidInput(1, 6); // Now accepts 6 for exit

		switch (choice) {
		case 1:
			system("cls");
			displayWeaponEditMenu();
			break;
		case 2:
			system("cls");
			// createAttack();
			break;
		case 3:
			system("cls");
			// editAttack();
			break;
		case 4:
			system("cls");
			// createCombo();
			break;
		case 5:
			system("cls");
			// editCombo();
			break;
		case 6:
			std::cout << "Exiting...\n";
			return; // Exit the menu entirely
		}
	}
}

void displayWeaponEditMenu() {
	displayWeaponStatComparisons(savedWeapons[0], savedWeapons[1]);
	printf("[Weapon Edit Menu]\n");
	printf("[1] Edit Weapon 1\n");
	printf("[2] Edit Weapon 2\n");
	printf("[3] Edit Hitzone Values\n");
	printf("[4] Return to Main Menu\n\n");

	printf("Please enter a choice [1-5]: ");

	int choice = getValidInput(1, 4);

	switch (choice) {
	case (1): {
		system("cls");
		editWeapon(savedWeapons[0]);
		break;
	}
	case (2): {
		system("cls");
		editWeapon(savedWeapons[1]);
		break;
	}
	case (3): {
		system("cls");
		editHZV();
		break;
	}
	case (4): {
		return;
	}
	}
}

void editWeapon(Weapon& weapon) {
	displayWeaponStatComparisons(savedWeapons[0], savedWeapons[1]);

	string inputString;
	float inputVal = readFloat();

	// Weapon Name
	std::cout << "Enter Weapon Name: ";
	std::getline(std::cin, inputString);
	weapon.setName(inputString);

	// Numeric inputs
	printf("[Editting Weapon]\n");
	std::cout << "Enter True Raw Value: ";
	weapon.setRaw(readFloat());

	std::cout << "Enter True Element Value: ";
	weapon.setElem(readFloat());

	std::cout << "Enter Raw Sharpness Value: ";
	weapon.setRawSharpness(readFloat());

	std::cout << "Enter Elemental Sharpness Value: ";
	weapon.setElemSharpness(readFloat());

	std::cout << "Enter Crit Boost Value: ";
	weapon.setCritBoost(readFloat());

	std::cout << "Enter Crit Elem Value: ";
	weapon.setCritElem(readFloat());

	std::cout << "Enter Other Raw Multipliers: ";
	weapon.setOtherRawBoosts(readFloat());

	std::cout << "Enter Other Elemental Multipliers: ";
	weapon.setOtherElemBoosts(readFloat());
}

void editHZV() {
	displayWeaponStatComparisons(savedWeapons[0], savedWeapons[1]);
	// Numeric inputs
	auto readFloat = []() {
		float val;
		while (!(std::cin >> val)) {
			std::cout << "Invalid input. Please enter a number: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cin.ignore(); // Clear the newline
		return val;
		};

	printf("[Changing Hitzone Value]\n");
	std::cout << "Enter Raw Hitzone Value: ";
	rawHZV = readFloat();
	std::cout << "Enter Elemental Hitzone Value: ";
	elemHZV = readFloat();
}




















void displayWeaponStatComparisons(Weapon& weapon1, Weapon& weapon2) {
	// Table header
	printf("Monster Raw Hitzone: %.2f\n", rawHZV);
	printf("Monster Elemental Hitzone: %.2f\n", elemHZV);
	printf("+--------------------------------------------------+\n");
	printf("|              %20s              |\n",
		"Weapon Stat Comparison");
	printf("+--------------------------------------------------+\n");
	printf("| %-12s | %-15s | %-15s |\n",
		"Weapons", weapon1.weaponName.c_str(), weapon2.weaponName.c_str());
	printf("+--------------+-----------------+-----------------+\n");

	// Helper lambda for printing rows
	auto printStat = [](const char* name, float v1, float v2) {
		printf("| %-12s | %15.2f | %15.2f |\n", name, v1, v2);
		};

	// Stats
	printStat("Raw", weapon1.raw, weapon2.raw);
	printStat("Element", weapon1.elem, weapon2.elem);
	printStat("Raw Sharp", weapon1.rawSharpness, weapon2.rawSharpness);
	printStat("Elem Sharp", weapon1.elemSharpness, weapon2.elemSharpness);
	printStat("Crit Boost", weapon1.critBoost, weapon2.critBoost);
	printStat("Crit Elem", weapon1.critElem, weapon2.critElem);
	printStat("OtherRawMul", weapon1.otherRawBoosts, weapon2.otherRawBoosts);
	printStat("OtherElemMul", weapon1.otherElemBoosts, weapon2.otherElemBoosts);

	printf("+--------------+-----------------+-----------------+\n\n\n");
}

void displayAttackComparison(Attack& attack, Weapon& weapon1, Weapon& weapon2) {
	attack.changeWeapon(weapon1);
	float weapon1Damage = attack.damage;
	attack.changeWeapon(weapon2);
	float weapon2Damage = attack.damage;

	printf("+----------------------------------+\n");
	printf("| %-17s | %12s |\n", "Comparing: ", attack.attackName.c_str());
	printf("+----------------------------------+\n");
	printf("| %-17s | %12.2f |\n", weapon1.weaponName.c_str(), weapon1Damage);
	printf("| %-17s | %12.2f |\n", weapon2.weaponName.c_str(), weapon2Damage);
	printf("+-------------------+--------------+\n");
	compareWeaponDamage(weapon1.weaponName, weapon2.weaponName, weapon1Damage, weapon2Damage);
}


void displayComboComparison(Combo& combo, Weapon& weapon1, Weapon& weapon2) {
	combo.changeWeapon(weapon1);
	float weapon1TotalDamage = combo.totalDamage;
	float weapon1RawDamage = combo.totalRawComboDamage;
	float weapon1ElemDamage = combo.totalElemComboDamage;
	combo.changeWeapon(weapon2);
	float weapon2TotalDamage = combo.totalDamage;
	float weapon2RawDamage = combo.totalRawComboDamage;
	float weapon2ElemDamage = combo.totalElemComboDamage;

	// Table header
	printf("Combo Name: %s\n", combo.comboName.c_str());
	printf("+--------------------------------------------------+\n");
	printf("|              %20s             |\n",
		"Combo Damage Comparison");
	printf("+--------------------------------------------------+\n");
	printf("| %-12s | %-15s | %-15s |\n",
		"Weapons", weapon1.weaponName.c_str(), weapon2.weaponName.c_str());
	printf("+--------------+-----------------+-----------------+\n");

	// Helper lambda for printing rows
	auto printStat = [](const char* name, float v1, float v2) {
		printf("| %-12s | %15.2f | %15.2f |\n", name, v1, v2);
		};

	// Stats
	printStat("Total", weapon1TotalDamage, weapon2TotalDamage);
	printStat("Raw", weapon1RawDamage, weapon2RawDamage);
	printStat("Element", weapon1ElemDamage, weapon2ElemDamage);

	printf("+--------------+-----------------+-----------------+\n");
	compareWeaponDamage(weapon1.weaponName, weapon2.weaponName, weapon1TotalDamage, weapon2TotalDamage);
}


void compareWeaponDamage(string weapon1Name, string weapon2Name, float weapon1Damage, float weapon2Damage) {
	calcDamageDiff(weapon1Damage, weapon2Damage);
	if (weapon1Damage > weapon2Damage) {
		printf("%s does more damage than %s by %.2f percent\n", weapon1Name.c_str(), weapon2Name.c_str(), getPercentageDiff(weapon1Damage, weapon2Damage));
	}
	else if (weapon1Damage < weapon2Damage) {
		printf("%s does more damage than %s by %.2f percent\n", weapon2Name.c_str(), weapon1Name.c_str(), getPercentageDiff(weapon1Damage, weapon2Damage));
	}
	else {
		printf("Both weapons deal the same exact amount of damage\n");
	}
}



float getPercentageDiff(float num1, float num2) {
	float biggerNum;
	float smallerNum;
	if (num1 > num2) {
		biggerNum = num1;
		smallerNum = num2;
	}
	else if (num1 < num2) {
		biggerNum = num2;
		smallerNum = num1;
	}
	else {
		return 0;
	}

	return ((biggerNum - smallerNum) / smallerNum) * 100;
}


void calcDamageDiff(float num1, float num2) {
	float biggerNum;
	float smallerNum;
	if (num1 > num2) {
		biggerNum = num1;
		smallerNum = num2;
	}
	else if (num1 < num2) {
		biggerNum = num2;
		smallerNum = num1;
	}
	else {
		printf("Damage Difference: 0");
	}

	printf("Damage Difference: %.2f\n", (biggerNum - smallerNum));
}




/*sns combo
savedAttacks.push_back(Attack("lateral slash", 0.27, 1.2, 1));
savedAttacks.push_back(Attack("return stroke", 0.28, 1.2, 1));
savedAttacks.push_back(Attack("spinning rising slash", 0.39, 1.2, 1);
savedAttacks.push_back(Attack("spinning reaper", 0.65, 1, 1));
savedAttacks.push_back(Attack("charged chop 1st hit", 18, 1, 1));
savedAttacks.push_back(Attack("charged chop 2nd hit", 0.28, 1.2, 1));
savedAttacks.push_back(Attack("enhanced charged chop", 0.28, 1.25, 3));*/

