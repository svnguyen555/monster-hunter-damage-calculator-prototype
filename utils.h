#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include "Weapon.h"
#include "Attack.h"
#include "Combo.h"
using namespace std;

class Weapon;
class Attack;
class Combo;

//Function Prototypes
void displayMenu();
//void menuInputValidation();
void displayWeaponEditMenu();
void editWeapon(Weapon& weapon);
void editHZV();
void displayWeaponStatComparisons(Weapon& weapon1, Weapon& weapon2);
void displayAttackComparison(Attack& attack, Weapon& weapon1, Weapon& weapon2);
void displayComboComparison(Combo& combo, Weapon& weapon1, Weapon& weapon2);
void compareWeaponDamage(string weapon1Name, string weapon2Name, float weapon1Damage, float weapon2Damage);
float getPercentageDiff(float num1, float num2);
void calcDamageDiff(float num1, float num2);

auto getValidInput = [](int min, int max) {
	int choice;
	while (true) {
		std::cin >> choice;
		if (std::cin.fail() || choice < min || choice > max) {
			std::cout << "Invalid input. Enter a number between "
				<< min << " and " << max << ": ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			std::cin.ignore(); // Clear leftover newline
			return choice;
		}
	}
	};

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
