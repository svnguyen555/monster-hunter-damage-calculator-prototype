#pragma once
#include <string>
#include "globals.h"
using namespace std;

class Weapon {
public:
	std::string weaponName;
	float raw;
	float elem;
	float rawSharpness;
	float elemSharpness;
	float critBoost;
	float critElem;
	float otherRawBoosts;
	float otherElemBoosts;

	Weapon() {
		weaponName = "";
		raw = 0;
		elem = 0;
		rawSharpness = 0;
		elemSharpness = 0;
		critBoost = 0;
		critElem = 0;
		otherRawBoosts = 0;
		otherElemBoosts = 0;
	}

	Weapon(std::string weaponName, float raw, float elem, float rawSharpness, float elemSharpness, float critBoost, float critElem, float otherRawBoosts, float otherElemBoosts) {
		this->weaponName = weaponName;
		this->raw = raw;
		this->elem = elem;
		this->rawSharpness = rawSharpness;
		this->elemSharpness = elemSharpness;
		this->critBoost = critBoost;
		this->critElem = critElem;
		this->otherRawBoosts = otherRawBoosts;
		this->otherElemBoosts = otherElemBoosts;
	}

	void setName(string input) {
		weaponName = input;
	}

	void setRaw(float input) {
		raw = input;
	}

	void setElem(float input) {
		elem = input;
	}

	void setRawSharpness(float input) {
		rawSharpness = input;
	}

	void setElemSharpness(float input) {
		elemSharpness = input;
	}

	void setCritBoost(float input) {
		critBoost = input;
	}

	void setCritElem(float input) {
		critElem = input;
	}

	void setOtherRawBoosts(float input) {
		otherRawBoosts = input;
	}

	void setOtherElemBoosts(float input) {
		otherElemBoosts = input;
	}
};
