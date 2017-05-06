//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Weapon;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Weapon = clone_object("/lib/items/weapon");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Weapon);
}

/////////////////////////////////////////////////////////////////////////////
void ItemPropertiesCanBeSet()
{
    // Only test a few of these - the full set is tested in items/itemTest
    ExpectTrue(Weapon->set("bonus armor class", 5), "bonus armor class can be set");
    ExpectEq(5, Weapon->query("bonus armor class"), "bonus armor class query returns correctly");

    ExpectTrue(Weapon->set("value", 850), "value can be set");
    ExpectEq(850, Weapon->query("value"), "850 value was returned");

    ExpectTrue(Weapon->set("no sell", 1), "no sell can be set");
    ExpectEq(1, Weapon->query("no sell"), "1 no sell was returned");

    ExpectTrue(Weapon->set("name", "blah"), "name can be set");
    ExpectEq("blah", Weapon->query("name"), "'blah' name was returned");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponClassCanBeSet()
{
    ExpectTrue(Weapon->set("weapon class", 5), "weapon class can be set");
    ExpectEq(5, Weapon->query("weapon class"), "5 weapon class was returned");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidWeaponClassCannotBeSet()
{
    string expected = "*Weapon: The passed 'weapon class' data must be an integer.\n";

    string err = catch (Weapon->set("weapon class", "spaghetti"));
    ExpectEq(expected, err, "weapon class cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void DefenseClassCanBeSet()
{
    ExpectTrue(Weapon->set("defense class", 5), "defense class can be set");
    ExpectEq(5, Weapon->query("defense class"), "5 defense class was returned");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidDefenseClassCannotBeSet()
{
    string expected = "*Weapon: The passed 'defense class' data must be an integer.\n";

    string err = catch (Weapon->set("defense class", "spaghetti"));
    ExpectEq(expected, err, "defense class cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetHitMethodOnItems()
{
    ExpectTrue(Weapon->set("hit method", "query"), "hit method can be set");
    ExpectEq("query", Weapon->query("hit method"), "'query' hit method was returned");
}

/////////////////////////////////////////////////////////////////////////////
void HitMethodMustExistOnObjectToBeSet()
{
    string expected = "*Weapon: The passed 'blah' hit method must be a function that exists in this item.\n";

    string err = catch (Weapon->set("hit method", "blah"));
    ExpectEq(expected, err, "hit method must exist on the item");
}

/////////////////////////////////////////////////////////////////////////////
void OffhandCannotBeSet()
{
    string expected = "*Equipment: It is illegal to set the 'offhand' element for this type of object.\n";

    string err = catch (Weapon->set("offhand", 1));
    ExpectEq(expected, err, "offhand cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponTypeCanBeSet()
{
    // A comprehensive test of the valid Weapon types is in the materialsDictionary test
    ExpectTrue(Weapon->set("weapon type", "long sword"), "weapon type can be set");
    ExpectEq("long sword", Weapon->query("weapon type"), "'long sword' weapon type was returned");

    ExpectTrue(Weapon->set("weapon type", "mace"), "weapon type can be set");
    ExpectEq("mace", Weapon->query("weapon type"), "'mace' weapon type was returned");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidWeaponTypeCannotBeSet()
{
    string expected = "*Weapon: The 'weapon type' element must be a string as defined in the keys of the itemTypes mapping in /lib/dictionaries/materialsDictionary.c.\n";

    string err = catch (Weapon->set("weapon type", "blah"));
    ExpectEq(expected, err, "weapon type cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void EquipDoesNotSetOffhandByDefault()
{
    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Weapon, owner);
    Weapon->set("name", "thingy");
    Weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Weapon->equip("thingy"), "equip");
    ExpectFalse(Weapon->query("offhand"), "offhand is false");
}

/////////////////////////////////////////////////////////////////////////////
void EquipDoesNotEquipIfIdDoesNotMatch()
{
    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Weapon, owner);
    Weapon->set("name", "thingy");
    Weapon->set("equipment locations", OnehandedWeapon);

    ExpectFalse(Weapon->equip("blarg"), "equip");
    ExpectFalse(Weapon->query("offhand"), "offhand is false");
}

/////////////////////////////////////////////////////////////////////////////
void EquipOffhandSetsOffhand()
{
    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Weapon, owner);
    Weapon->set("name", "thingy");
    Weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Weapon->equip("thingy offhand"), "equip offhand");
    ExpectTrue(Weapon->query("offhand"), "offhand is true");
}

/////////////////////////////////////////////////////////////////////////////
void OffhandEquipsWeaponOffhand()
{
    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Weapon, owner);
    Weapon->set("name", "thingy");
    Weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Weapon->offhand("thingy"), "offhand");
    ExpectTrue(Weapon->query("offhand"), "offhand is true");
}

/////////////////////////////////////////////////////////////////////////////
void OffhandOnlyEquipsIfIdMatches()
{
    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Weapon, owner);
    Weapon->set("name", "thingy");
    Weapon->set("equipment locations", OnehandedWeapon);

    ExpectFalse(Weapon->offhand("blarg"), "offhand");
    ExpectFalse(Weapon->query("offhand"), "offhand is true");
}

/////////////////////////////////////////////////////////////////////////////
void UnequipOffhandClearsOffhand()
{
    object owner = clone_object("/lib/tests/support/services/mockUserWithInventory.c");
    owner->Name("Bob");
    move_object(Weapon, owner);
    Weapon->set("name", "thingy");
    Weapon->set("equipment locations", OnehandedWeapon);

    ExpectTrue(Weapon->equip("thingy offhand"), "equip offhand");
    ExpectTrue(Weapon->query("offhand"), "offhand is true");

    ExpectTrue(Weapon->unequip("thingy"), "unequip offhand");
    ExpectFalse(Weapon->query("offhand"), "offhand is false");
}

/////////////////////////////////////////////////////////////////////////////
void CorrectDamageTypeReturnedForQueryDamageType()
{
    ExpectTrue(Weapon->set("material", "iron"), "type set to iron");
    ExpectEq(1, sizeof(Weapon->query("damage type")), "one damage type returned for iron");
    ExpectEq("physical", Weapon->query("damage type")[0], "physical damage type returned");

    ExpectTrue(Weapon->set("material", "galvorn"), "type set to galvorn");
    ExpectEq(2, sizeof(Weapon->query("damage type")), "two damage type returned for galvorn");
    ExpectTrue(member(Weapon->query("damage type"), "magical") > -1, "magical damage type returned");
    ExpectTrue(member(Weapon->query("damage type"), "physical") > -1, "physical damage type returned");

    ExpectTrue(Weapon->set("weapon type", "long sword"), "weapon type set to long sword");
    ExpectEq(2, sizeof(Weapon->query("damage type")), "two damage type returned for long sword");
    ExpectTrue(member(Weapon->query("damage type"), "magical") > -1, "magical damage type returned");
    ExpectTrue(member(Weapon->query("damage type"), "slash") > -1, "slash damage type returned");

}

