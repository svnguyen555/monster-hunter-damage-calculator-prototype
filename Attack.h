#pragma once
#include <string>
#include "Weapon.h"
#include "globals.h"


class Attack {
public:
	Weapon weapon;
	std::string attackName;
	std::string weaponName;
	float rawDamage;
	float elemDamage;
	float damage;
	float rawMV;
	float elemMV;
	float numOfHits;
	bool phialDamage;
	float rawPhialMV;
	float elemPhialMV;

	Attack() {
		weapon = Weapon();
		attackName = "";
		weaponName = "";
		rawMV = 0;
		elemMV = 0;
		rawDamage = 0;
		elemDamage = 0;
		damage = 0;
		numOfHits = 0;
		phialDamage = false;
		rawPhialMV = 0;
		elemPhialMV = 0;
	}

	Attack(std::string attackName, float rawMV, float elemMV, float numOfHits) {
		this->attackName = attackName;
		this->rawMV = rawMV;
		this->elemMV = elemMV;
		this->numOfHits = numOfHits;
		this->rawDamage = floor((weapon.raw * weapon.rawSharpness * weapon.critBoost * weapon.otherRawBoosts * rawMV * rawHZV) * floorval) / floorval;
		this->elemDamage = floor((weapon.elem * weapon.elemSharpness * weapon.critElem * weapon.otherElemBoosts * elemMV * elemHZV) * floorval) / floorval;
		this->damage = numOfHits * (rawDamage + elemDamage);
		this->weaponName = weapon.weaponName;
	}

	Attack(std::string attackName, float rawPhialMV, float elemPhialMV, float numOfHits, bool phialDamage) {
		this->phialDamage = phialDamage;
		this->attackName = attackName;
		this->rawPhialMV = rawPhialMV;
		this->elemPhialMV = elemPhialMV;
		this->numOfHits = numOfHits;
		this->rawDamage = floor((weapon.raw * weapon.otherRawBoosts * rawPhialMV) * floorval) / floorval;
		this->elemDamage = floor((weapon.elem * weapon.otherElemBoosts * elemHZV * elemPhialMV) * floorval) / floorval;
		this->damage = numOfHits * (rawDamage + elemDamage);
		this->weaponName = weapon.weaponName;
	}

	void changeWeapon(Weapon& weapon) {
		this->weaponName = weapon.weaponName;

		if (phialDamage == true) {
			this->rawDamage = floor((weapon.raw * weapon.otherRawBoosts * rawPhialMV) * floorval) / floorval;
			this->elemDamage = floor((weapon.elem * weapon.otherElemBoosts * elemHZV * elemPhialMV) * floorval) / floorval;
		}
		else {
			this->rawDamage = floor((weapon.raw * weapon.rawSharpness * weapon.critBoost * weapon.otherRawBoosts * rawMV * rawHZV) * floorval) / floorval;
			this->elemDamage = floor((weapon.elem * weapon.elemSharpness * weapon.critElem * weapon.otherElemBoosts * elemMV * elemHZV) * floorval) / floorval;
		}

		this->damage = numOfHits * (rawDamage + elemDamage);
	}

	void setAttackName(const std::string& name) {
		attackName = name;
	}

	void setRawMV(float input) {
		rawMV = input;
	}

	void setElemMV(float input) {
		elemMV = input;
	}

	void setRawDamage(Weapon weapon) {
		rawDamage = weapon.raw * weapon.rawSharpness * weapon.critBoost * rawMV * rawHZV;
	}

	void setElemDamage(Weapon weapon) {
		elemDamage = weapon.elem * weapon.elemSharpness * weapon.critBoost * elemMV * elemHZV;
	}

	void setAttackDamage() {
		damage = rawDamage + elemDamage;
	}
};
