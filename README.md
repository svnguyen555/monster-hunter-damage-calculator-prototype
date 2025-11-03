# monster-hunter-damage-calculator-prototype
A personal calculator developed with C++ that is made for the Monster Hunter game series. Allows the user to calculate the damage they inflict based on inputted weapon stats, attack values, and monster defense values. Currently a prototype version made for practicing what I learned from my classes. Will likely remake the project from scratch in the future.

---

## Overview

This tool simulates Monster Hunter damage calculations using:
- Weapon attributes (raw, element, sharpness, critical modifiers, etc.)
- Attack motion values and Monster hitzone values
- Combo sequences with total, raw, and elemental damage breakdowns

The user can store information about weapons, attack values, and combo strings as objects into the program.

The tool also allows users to compare how damage differs between weapons.


## Motivations

- I wanted a calculator that didn't rely on preset weapon/attack value data info since existing calculators were prone to becoming inaccurate whenever Capcom updated the games.
- As such I thought it would be a good idea to have a calculator where the user can freely input any values they want for weapon stats, attack motion values, and monster hitzones so that the calculator can be useful longterm and not rely on developers to update values.
- I also wanted an easy way to compare damage differences between weapons using the tool's output.

## Shortcomings and Future Plans

- As this is a prototype build, while the calculator itself is functional the current program itself not ready for enduser use.
- I was working on creating a console-based menu system which I haven't finished yet.
- To use the current calculator, the user will need to adjust hardcoded values as instructed in the comments of the code.
- In the future I would like to recreate this project from scratch using new techniques I am learning from my current Object Oriented Programming class. The first step will be to design the project using a UML diagram
- I would also like to eventually turn this into a program that can be managed using gui

## How to use the calculator
It is highly recommended to put the files into an IDE like VS Studio and run the program there. As I mentioned earlier, the user will need to manually create their own weapon/attack/combo objects through the code itself. Instructions on what parts of the code can be changed are written as comments in MHDamageCalc.cpp

## Author
Sang Nguyen | California State University, Sacramento student
