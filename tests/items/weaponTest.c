//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
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
void WeaponClassIsAffectedByCraftingWeaponClass()
{
    ExpectTrue(Weapon->set("weapon class", 5), "value can be set");
    ExpectEq(5, Weapon->query("weapon class"), "5 value was returned");
    ExpectTrue(Weapon->set("crafting weapon class", 1), "value multiplier can be set");
    ExpectEq(6, Weapon->query("weapon class"), "6 value was returned");
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
void DefenseClassIsAffectedByCraftingDefenseClass()
{
    ExpectTrue(Weapon->set("defense class", 5), "value can be set");
    ExpectEq(5, Weapon->query("defense class"), "5 value was returned");
    ExpectTrue(Weapon->set("crafting defense class", 1), "value multiplier can be set");
    ExpectEq(6, Weapon->query("defense class"), "6 value was returned");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponAttackCanBeSet()
{
    ExpectTrue(Weapon->set("weapon attack", 5), "defense class can be set");
    ExpectEq(5, Weapon->query("weapon attack"), "5 defense class was returned");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidWeaponAttackCannotBeSet()
{
    string expected = "*Weapon: The passed 'weapon attack' data must be an integer.\n";

    string err = catch (Weapon->set("weapon attack", "spaghetti"));
    ExpectEq(expected, err, "weapon attack cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void WeaponAttackIsAffectedByCraftingWeaponAttack()
{
    ExpectTrue(Weapon->set("weapon attack", 5), "value can be set");
    ExpectEq(5, Weapon->query("weapon attack"), "5 value was returned");
    ExpectTrue(Weapon->set("crafting attack", 1), "value multiplier can be set");
    ExpectEq(6, Weapon->query("weapon attack"), "6 value was returned");
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

/////////////////////////////////////////////////////////////////////////////
void CorrectDamageTypeReturnedWhenNonPhysicalDamageSet()
{
    ExpectTrue(Weapon->set("material", "galvorn"), "type set to galvorn");
    ExpectTrue(Weapon->set("primary damage type", "fire"));
    ExpectEq("fire", Weapon->getDamageType());
    ExpectEq(({ "fire", "magical" }), Weapon->query("damage type"));
}

/////////////////////////////////////////////////////////////////////////////
void BlueprintCanBeSet()
{
    ExpectTrue(Weapon->set("blueprint", "long sword"), "blueprint can be set");
    ExpectEq("long sword", Weapon->query("blueprint"), "'long sword' blueprint was returned");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidBlueprintCannotBeSet()
{
    string expected = "*Weapon: The 'blueprint' element must be a string as defined in the keys of the weaponBlueprints mapping in /lib/dictionaries/materialsDictionary.c.\n";

    string err = catch (Weapon->set("blueprint", "blah"));
    ExpectEq(expected, err, "blueprint cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void CanDamageEtherealReturnsFalseByDefault()
{
    Weapon->set("blueprint", "long sword");
    ExpectFalse(Weapon->canDamageEthereal());
}

/////////////////////////////////////////////////////////////////////////////
void CanDamageEtherealReturnsTrueIfItIsMasterwork()
{
    Weapon->set("blueprint", "long sword");
    Weapon->set("craftsmanship", 100);
    ExpectTrue(Weapon->canDamageEthereal());
}

/////////////////////////////////////////////////////////////////////////////
void CanDamageEtherealReturnsTrueIfMaterialHasCorrectProperties()
{
    Weapon->set("blueprint", "long sword");
    Weapon->set("material", "galvorn");
    ExpectTrue(Weapon->canDamageEthereal());
}

/////////////////////////////////////////////////////////////////////////////
void CanDamageEtherealReturnsTrueIfEnchantmentHasCorrectProperties()
{
    Weapon->set("blueprint", "long sword");
    Weapon->set("enchantments", (["energy": 20]));
    ExpectTrue(Weapon->canDamageEthereal());
}

/////////////////////////////////////////////////////////////////////////////
void CanDamageEtherealReturnsFalseIfEnchantmentCannotDamageEthereal()
{
    Weapon->set("blueprint", "long sword");
    Weapon->set("enchantments", (["cold":20]));
    ExpectFalse(Weapon->canDamageEthereal());
}

/////////////////////////////////////////////////////////////////////////////
void EnchantmentsAddModifiersItemResearchAndTraitEnchantments()
{
    object player = clone_object("/lib/tests/support/services/mockPlayer.c");
    player->Str(20);
    player->Int(20);
    player->Wis(20);
    player->Dex(20);
    player->Con(20);
    player->Chr(20);

    move_object(Weapon, player);

    ExpectTrue(Weapon->set("enchantments", (["fire":1, "chaos":1 ])), "enchantments can be set");
    ExpectEq((["fire":1, "chaos":1]), Weapon->query("enchantments"), "item enchantments displayed");

    ExpectTrue(player->initiateResearch("lib/tests/support/research/testEnchantmentResearchItem.c"), "initiate research");
    ExpectEq((["fire":3, "chaos": 1, "magical": 1, "electricity": 5]), Weapon->query("enchantments"), "item enchantments displayed");

    ExpectTrue(player->initiateResearch("lib/tests/support/research/anotherEnchantmentResearch.c"), "initiate research");
    ExpectEq((["fire":6, "chaos" : 1, "magical" : 1, "electricity" : 5]), Weapon->query("enchantments"), "item enchantments displayed");

    ExpectTrue(player->addTrait("lib/tests/support/traits/testEnchantmentTrait.c"), "initiate research");
    ExpectEq((["fire":8, "chaos" : 1, "magical" : 2, "electricity" : 10]),
        Weapon->query("enchantments"));

    ExpectTrue(player->addTrait("lib/tests/support/traits/anotherEnchantmentTrait.c"), "initiate research");
    ExpectEq((["fire":12, "chaos" : 1, "magical" : 2, "electricity" : 10]),
        Weapon->query("enchantments"));

    object modifier = clone_object("/lib/items/modifierObject");
    modifier->set("fully qualified name", "blah");
    modifier->set("bonus fire enchantment", 3);
    modifier->set("bonus crafting air enchantment", 3);
    ExpectEq(1, modifier->set("registration list", ({ player })), "registration list can be set");
    ExpectEq((["fire":15, "chaos" : 1, "magical" : 2, "electricity" : 10]),
        Weapon->query("enchantments"));

    destruct(modifier);
    destruct(player);
}
