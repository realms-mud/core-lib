//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Vehicle;
object Target;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Vehicle = clone_object("/lib/items/vehicle.c");
    Vehicle->set("vehicle type", "wagon");
    Vehicle->set("components", ([ "hull": "basic wooden hull", "cargo": "small cargo hold" ]));
    Vehicle->set("location", "Test Location");
    Vehicle->set("cargo", ([ "itemA": 5 ]));
    Vehicle->set("crew", ([ "captain": this_object() ]));
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    if (objectp(Vehicle)) destruct(Vehicle);
    if (objectp(Target)) destruct(Target);
}

/////////////////////////////////////////////////////////////////////////////
void GetCapacityIncludesComponentBonuses()
{
    int base = Vehicle->getBlueprint()["capacity"];
    int bonus = Vehicle->getComponent("cargo")["capacity bonus"];
    ExpectEq(base + bonus, Vehicle->getCapacity());
}

/////////////////////////////////////////////////////////////////////////////
void AddCargoAndRemoveCargoRespectsCapacity()
{
    Vehicle->set("cargo", ([]));
    int cap = Vehicle->getCapacity();

    // Add up to capacity
    ExpectTrue(Vehicle->addCargo("itemA", cap));
    ExpectEq(cap, Vehicle->getCargoQuantity("itemA"));

    // Cannot add more than capacity
    ExpectFalse(Vehicle->addCargo("itemA", 1));

    // Remove some, then add again
    ExpectTrue(Vehicle->removeCargo("itemA", 5));
    ExpectEq(cap - 5, Vehicle->getCargoQuantity("itemA"));
    ExpectTrue(Vehicle->addCargo("itemA", 5));
    ExpectEq(cap, Vehicle->getCargoQuantity("itemA"));

    // Remove all
    ExpectTrue(Vehicle->removeCargo("itemA", cap));
    ExpectEq(0, Vehicle->getCargoQuantity("itemA"));
}

/////////////////////////////////////////////////////////////////////////////
void InstallComponentAndRemoveComponentAffectsStats()
{
    int baseProtection = Vehicle->getTradeProtection();
    int baseSpeed = Vehicle->getSpeed();

    // Install a component with bonuses
    ExpectTrue(Vehicle->installComponent("sail", "arcane sail"));
    int sailProtection = Vehicle->getComponent("sail")["protection"];
    int sailSpeed = Vehicle->getComponent("sail")["speed bonus"];

    ExpectEq(baseProtection + sailProtection, Vehicle->getTradeProtection());
    ExpectEq(baseSpeed + sailSpeed, Vehicle->getSpeed());

    // Remove the component and stats revert
    ExpectTrue(Vehicle->removeComponent("sail"));
    ExpectEq(baseProtection, Vehicle->getTradeProtection());
    ExpectEq(baseSpeed, Vehicle->getSpeed());
}

/////////////////////////////////////////////////////////////////////////////
void StructureReflectsComponentBonuses()
{
    int base = Vehicle->getBlueprint()["structure"];
    int bonus = Vehicle->getComponent("hull")["structure"];
    ExpectEq(base + bonus, Vehicle->getMaxStructure());
}

/////////////////////////////////////////////////////////////////////////////
void CurrentStructureInitializesToMax()
{
    int max = Vehicle->getMaxStructure();
    ExpectEq(max, Vehicle->getCurrentStructure());
}

/////////////////////////////////////////////////////////////////////////////
void TakeDamageReducesCurrentStructure()
{
    int max = Vehicle->getMaxStructure();
    Vehicle->takeDamage(5);
    ExpectEq(max - 5, Vehicle->getCurrentStructure());
}

/////////////////////////////////////////////////////////////////////////////
void TakeDamageCannotGoBelowZero()
{
    int max = Vehicle->getMaxStructure();
    Vehicle->takeDamage(max + 10);
    ExpectEq(0, Vehicle->getCurrentStructure());
}

/////////////////////////////////////////////////////////////////////////////
void RepairRestoresCurrentStructureUpToMax()
{
    int max = Vehicle->getMaxStructure();
    Vehicle->takeDamage(10);
    Vehicle->repair(5);
    ExpectEq(max - 5, Vehicle->getCurrentStructure());
    Vehicle->repair(1000);
    ExpectEq(max, Vehicle->getCurrentStructure());
}

/////////////////////////////////////////////////////////////////////////////
void IsDestroyedReturnsTrueWhenStructureZero()
{
    int max = Vehicle->getMaxStructure();
    Vehicle->takeDamage(max);
    ExpectTrue(Vehicle->isDestroyed());
    Vehicle->repair(1);
    ExpectFalse(Vehicle->isDestroyed());
}

/////////////////////////////////////////////////////////////////////////////
void AttackVehicleDealsCorrectDamage()
{
    Target = clone_object("/lib/items/vehicle.c");
    Target->set("vehicle type", "wagon");
    Target->set("components", ([ "hull": "basic wooden hull" ]));
    int initial = Target->getCurrentStructure();
    int dealt = Vehicle->attackVehicle(Target);
    ExpectTrue(dealt >= 1);
    ExpectEq(initial - dealt, Target->getCurrentStructure());
}

/////////////////////////////////////////////////////////////////////////////
void AssignCrewAndRemoveCrewWorks()
{
    object crewMember = this_object();
    Vehicle->assignCrew("first mate", crewMember);
    mapping crew = Vehicle->getCrew();
    ExpectEq(crewMember, crew["first mate"]);

    Vehicle->removeCrew("first mate");
    ExpectFalse(member(Vehicle->getCrew(), "first mate"));
}

/////////////////////////////////////////////////////////////////////////////
void GetCargoReturnsCopy()
{
    mapping cargo = Vehicle->getCargo();
    ExpectTrue(mappingp(cargo));
    cargo["itemA"] = 999;
    ExpectNotEq(999, Vehicle->getCargo()["itemA"]);
}

/////////////////////////////////////////////////////////////////////////////
void SetEnforcesRequiredElements()
{
    ExpectTrue(catch(Vehicle->set("vehicle type", 0)), "Should throw error for invalid vehicle type");
    ExpectTrue(catch(Vehicle->set("location", 0)), "Should throw error for invalid location");
    ExpectTrue(catch(Vehicle->set("components", 0)), "Should throw error for invalid components");
}

/////////////////////////////////////////////////////////////////////////////
void SetHandlesOptionalElements()
{
    ExpectTrue(Vehicle->set("cargo", 0));
    ExpectTrue(Vehicle->set("crew", 0));
}

/////////////////////////////////////////////////////////////////////////////
void GetUsedSpaceAndGetFreeSpaceAreConsistent()
{
    Vehicle->set("cargo", ([ "itemA": 5, "itemB": 3 ]));
    int used = Vehicle->getUsedSpace();
    int free = Vehicle->getFreeSpace();
    ExpectEq(Vehicle->getCapacity(), used + free);
}
