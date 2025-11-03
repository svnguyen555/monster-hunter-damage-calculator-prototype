#pragma once
#include <string>
#include "Weapon.h"
#include "Attack.h"
#include <vector>
#include "globals.h"


class Combo {
public:
	std::string comboName;
	vector<Attack> attacks;
	float totalDamage;
	float totalRawComboDamage;
	float totalElemComboDamage;
	std::string weaponName;

	Combo() {
		comboName = "";
		totalDamage = 0;
		weaponName = "";
		totalRawComboDamage = 0;
		totalElemComboDamage = 0;
	}

	Combo(std::string comboName, Attack attack) {
		this->comboName = comboName;
		this->attacks.push_back(attack);
		totalDamage += attack.damage;
		totalRawComboDamage += attack.rawDamage;
		totalElemComboDamage += attack.elemDamage;
		weaponName = attacks[0].weaponName;
	}

	Combo(std::string comboName, vector<Attack>& attacks) {
		this->comboName = comboName;
		totalDamage = 0;
		totalRawComboDamage = 0;
		totalElemComboDamage = 0;
		size_t attacksSize = attacks.size();

		for (const auto& attack : attacks) {
			if (!attack.attackName.empty()) {
				this->attacks.push_back(attack);
				totalDamage += attack.damage;
				totalRawComboDamage += attack.rawDamage;
				totalElemComboDamage += attack.elemDamage;
			}
		}

		weaponName = this->attacks.empty() ? "no weapon" : this->attacks[0].weaponName;
	}

	void addAttack(Attack attack) {
		attacks.push_back(attack);
		totalDamage += attack.damage;
		totalRawComboDamage += attack.rawDamage;
		totalElemComboDamage += attack.elemDamage;
		//printf("%s %f\n", attack.attackName.c_str(), attack.damage);
	}

	void changeWeapon(Weapon weapon) {
		weaponName = weapon.weaponName;
		totalDamage = 0;
		totalRawComboDamage = 0;
		totalElemComboDamage = 0;

		for (auto& attack : attacks) {
			attack.changeWeapon(weapon);
			//printf("%s %f\n", attack.attackName.c_str(), attack.damage);
			totalDamage += attack.damage;
			totalRawComboDamage += attack.numOfHits * attack.rawDamage;
			totalElemComboDamage += attack.numOfHits * attack.elemDamage;
		}
	}
};

