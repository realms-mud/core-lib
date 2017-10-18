//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"
#include "/lib/include/itemFormatters.h"

private nosave string DetailsText = "\t[0;36m%s: [0m[0;33m%d to %d[0m\n";
private nosave string SingleDetailText = "\t[0;36m%s: [0m[0;33m%d[0m\n";
private nosave string DetailString = "\t[0;36m%s: [0m[0;33m%s[0m\n";

object Weapon;
object Player;
object Statistics;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Statistics = clone_object("/lib/dictionaries/materialsDictionary.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->Str(10);
    Player->Dex(10);
    Player->Con(10);
    Player->Int(10);
    Player->Wis(10);

    Weapon = clone_object("/lib/items/weapon");
    Weapon->set("weapon type", "long sword");
    Weapon->set("short", "Sword of Blah");
    move_object(Weapon, Player);
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Weapon);
    destruct(Player);
    destruct(Statistics);
}

/////////////////////////////////////////////////////////////////////////////
void MasterworkItemsCorrectlyDisplayed()
{
    Weapon->set("craftsmanship", 50);

    string expected = sprintf(Masterwork, "This long sword is a masterwork item.\n") + sprintf(Unidentified, "This item has not been identified.\n");
    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void ExceptionalCraftsmanshipItemsCorrectlyDisplayed()
{
    Weapon->set("craftsmanship", 30);

    string expected = sprintf(WellCrafted, "This long sword is a well-crafted item.\n") + sprintf(Unidentified, "This item has not been identified.\n");
    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void EnchantedItemsCorrectlyDisplayed()
{
    Weapon->set("bonus attack", 1);

    string expected = sprintf(Enchanted, "This long sword is enchanted.\n") + sprintf(Unidentified, "This item has not been identified.\n");
    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void StrongEnchantmentItemsCorrectlyDisplayed()
{
    Weapon->set("bonus attack", 5);
    Weapon->set("bonus strength", 5);

    string expected = sprintf(StrongEnchantment, "This long sword is enchanted with a powerful aura.\n") + sprintf(Unidentified, "This item has not been identified.\n");
    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsNotShownWhenNotIdentified()
{
    string expected = sprintf(NormalEquipment, "This long sword is typical for its type.\n") + sprintf(Unidentified, "This item has not been identified.\n");

    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsWithDetailsShownWhenIdentified()
{
    Weapon->set("identified");

    string expected = sprintf(NormalEquipment, "This long sword is typical for its type.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", -5, 95) +
        sprintf(DetailsText, "Damage", 4, 5) +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 15);

    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsModifiedByMaterial()
{
    Weapon->set("identified");
    Weapon->set("material", "galvorn");

    string expected = sprintf(NormalEquipment, "This long sword is typical for its type.\n") +
        sprintf(DetailString, "Material", "Galvorn") +
        sprintf(DetailsText, "Attack", 0, 100) +
        sprintf("\t[0;36m%s: [0m[0;33m%d to %d[0m", "Damage", 11, 14) +
        sprintf("[0;31m [+%d %s][0m\n", 5, "magical") +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 17);

    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsModifiedByEnchantment()
{
    Weapon->set("identified");
    Weapon->set("material", "galvorn");
    Weapon->set("enchantments", (["fire":10, "magical" : 2]));

    string expected = sprintf(Enchanted, "This long sword is enchanted.\n") +
        sprintf(DetailString, "Material", "Galvorn") +
        sprintf(DetailsText, "Attack", 0, 100) +
        sprintf("\t[0;36m%s: [0m[0;33m%d to %d[0m", "Damage", 11, 14) +
        sprintf("[0;31m [+%d %s][0m", 10, "fire") +
        sprintf("[0;31m [+%d %s][0m\n", 7, "magical") +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 17);

    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsDisplayBonuses()
{
    Weapon->set("identified");
    Weapon->set("bonus strength", 2);
    Weapon->set("bonus attack", 1);
    Weapon->set("bonus hit points", 10);

    string expected = sprintf(StrongEnchantment, "This long sword is enchanted with a powerful aura.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", -5, 95) +
        sprintf(DetailsText, "Damage", 4, 5) +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 15) +
        sprintf(Value, sprintf("\t%s: %d\n", "Bonus attack", 1)) +
        sprintf(Value, sprintf("\t%s: %d\n", "Bonus hit points", 10)) +
        sprintf(Value, sprintf("\t%s: %d\n", "Bonus strength", 2));

    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsModifiedBySkillOfUser()
{
    Weapon->set("identified");
    Player->addSkillPoints(100);
    Player->advanceSkill("long sword", 8);

    string expected = sprintf(NormalEquipment, "This long sword is typical for its type.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", 9, 109) +
        sprintf(DetailsText, "Damage", 10, 13) +
        sprintf(DetailsText, "Defense", 3, 4) +
        sprintf(SingleDetailText, "Encumberance", 1);

    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsModifiedByItemCraftsmanship()
{
    Weapon->set("identified");
    Weapon->set("craftsmanship", 35);

    string expected = sprintf(WellCrafted, "This long sword is a well-crafted item.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", -1, 99) +
        sprintf(DetailsText, "Damage", 7, 10) +
        sprintf(DetailsText, "Defense", 0, 1) +
        sprintf(SingleDetailText, "Encumberance", 15);

    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void AutoIdentifyWhenSkillSufficientlyHigh()
{
    Player->addSkillPoints(100);
    Player->advanceSkill("metal crafting", 5);
    Player->advanceSkill("weapon smithing", 10);

    string expected = sprintf(NormalEquipment, "This long sword is typical for its type.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", -5, 95) +
        sprintf(DetailsText, "Damage", 4, 5) +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 15);

    ExpectFalse(Weapon->query("identified"));
    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
    ExpectTrue(Weapon->query("identified"));
}

/////////////////////////////////////////////////////////////////////////////
void AutoIdentifyMagicWhenSpellcraftSufficientlyHigh()
{
    Weapon->set("bonus attack", 1);
    Player->addSkillPoints(100);
    Player->advanceSkill("metal crafting", 5);
    Player->advanceSkill("weapon smithing", 10);
    Player->advanceSkill("spellcraft", 10);

    string expected = sprintf(Enchanted, "This long sword is enchanted.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", -5, 95) +
        sprintf(DetailsText, "Damage", 4, 5) +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 15) +
        sprintf(Value, sprintf("\t%s: %d\n", "Bonus attack", 1));

    ExpectFalse(Weapon->query("identified"));
    ExpectEq(expected, Statistics->getEquipmentStatistics(Weapon, Player));
    ExpectTrue(Weapon->query("identified"));
}

/////////////////////////////////////////////////////////////////////////////
void ArmorStatisticsCorrectlyDisplayed()
{
    object armor = clone_object("/lib/items/armor.c");
    armor->set("armor type", "chainmail");
    armor->set("short", "Chainmail of Blah");
    armor->set("identified");

    string expected = sprintf(NormalEquipment, "This chainmail is typical for its type.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(SingleDetailText, "Damage Protection", 5) +
        sprintf(SingleDetailText, "Encumberance", 30);

    ExpectEq(expected, Statistics->getEquipmentStatistics(armor, Player));
}

/////////////////////////////////////////////////////////////////////////////
void ArmorStatisticsModifiedByMaterial()
{
    object armor = clone_object("/lib/items/armor.c");
    armor->set("armor type", "chainmail");
    armor->set("short", "Chainmail of Blah");
    armor->set("material", "galvorn");
    armor->set("identified");

    string expected = sprintf(NormalEquipment, "This chainmail is typical for its type.\n") +
        sprintf(DetailString, "Material", "Galvorn") +
        sprintf("\t[0;36m%s: [0m[0;33m%d[0m", "Damage Protection", 10) +
        sprintf("[0;31m [+%d %s][0m", 3, "electricity") +
        sprintf("[0;31m [+%d %s][0m\n", 3, "fire") +
        sprintf(SingleDetailText, "Encumberance", 32);

    ExpectEq(expected, Statistics->getEquipmentStatistics(armor, Player));
}

/////////////////////////////////////////////////////////////////////////////
void ArmorProtectionNotModifiedBySkill()
{
    object armor = clone_object("/lib/items/armor.c");
    armor->set("armor type", "chainmail");
    armor->set("short", "Chainmail of Blah");
    armor->set("material", "galvorn");
    armor->set("identified");

    Player->addSkillPoints(100);
    Player->advanceSkill("chainmail", 10);

    string expected = sprintf(NormalEquipment, "This chainmail is typical for its type.\n") +
        sprintf(DetailString, "Material", "Galvorn") +
        sprintf("\t[0;36m%s: [0m[0;33m%d[0m", "Damage Protection", 10) +
        sprintf("[0;31m [+%d %s][0m", 3, "electricity") +
        sprintf("[0;31m [+%d %s][0m\n", 3, "fire") +
        sprintf(SingleDetailText, "Encumberance", 19);

    ExpectEq(expected, Statistics->getEquipmentStatistics(armor, Player));
}

/////////////////////////////////////////////////////////////////////////////
void NonEquipmentItemsShowMagicalProperties()
{
    object item = clone_object("/lib/items/item.c");
    item->set("identified");
    item->set("enchantments", (["fire":5, "air":3]));
    item->set("resistances", (["fire":5]));
    item->set("bonus attack", 3);

    string expected = sprintf(Enchanted, "This item is enchanted.\n") +
        sprintf(Value, sprintf("\t%s: %s", "Enchantments", 
        sprintf("[0;31m [+%d %s][0m", 3, "air") +
        sprintf("[0;31m [+%d %s][0m\n", 5, "fire"))) +
        sprintf(Value, sprintf("\t%s: %s", "Resistances",
        sprintf("[0;31m [+%d %s][0m\n", 5, "fire"))) +
        sprintf(Value, sprintf("\t%s: %d\n", "Bonus attack", 3));

    ExpectEq(expected, Statistics->getEquipmentStatistics(item, Player));
}
