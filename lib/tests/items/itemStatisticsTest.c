//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

private nosave string DetailsText = "\x1b[0;36m    %s: \x1b[0m\x1b[0;33m%d\x1b[0m\x1b[0;33m to %d\x1b[0m\n";
private nosave string SingleDetailText = "\x1b[0;36m    %s: \x1b[0m\x1b[0;33m%d\x1b[0m\n";
private nosave string DetailString = "\x1b[0;36m    %s: \x1b[0m\x1b[0;33m%s\x1b[0m\n";
private nosave string NormalEquipment = "\x1b[0;37;1m%s\x1b[0m";
private nosave string StrongEnchantment = "\x1b[0;35;1m%s\x1b[0m";
private nosave string WellCrafted = "\x1b[0;32m%s\x1b[0m";
private nosave string Value = "\x1b[0;33m%s\x1b[0m";
private nosave string Masterwork = "\x1b[0;32;1m%s\x1b[0m";
private nosave string Enchanted = "\x1b[0;35m%s\x1b[0m";
private nosave string Unidentified = "\x1b[0;36m%s\x1b[0m";

object Weapon;
object Player;
object Statistics;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Statistics = clone_object("/lib/dictionaries/materialsDictionary.c");
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.Str(10);
    Player.Dex(10);
    Player.Con(10);
    Player.Int(10);
    Player.Wis(10);
    Player.colorConfiguration("3-bit");

    Weapon = clone_object("/lib/items/weapon");
    Weapon.set("weapon type", "long sword");
    Weapon.set("short", "Sword of Blah");
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
    Weapon.set("craftsmanship", 50);

    string expected = sprintf(Masterwork, "This long sword is a masterwork item.\n") +
        sprintf(SingleDetailText, "Weight", 5) + 
        sprintf(Unidentified, "This item has not been identified.\n");
    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void ExceptionalCraftsmanshipItemsCorrectlyDisplayed()
{
    Weapon.set("craftsmanship", 30);

    string expected = sprintf(WellCrafted, "This long sword is a well-crafted item.\n") +
        sprintf(SingleDetailText, "Weight", 5) + 
        sprintf(Unidentified, "This item has not been identified.\n");
    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void EnchantedItemsCorrectlyDisplayed()
{
    Weapon.set("bonus attack", 1);

    string expected = sprintf(Enchanted, "This long sword is enchanted.\n") +
        sprintf(SingleDetailText, "Weight", 5) + 
        sprintf(Unidentified, "This item has not been identified.\n");
    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void StrongEnchantmentItemsCorrectlyDisplayed()
{
    Weapon.set("bonus attack", 5);
    Weapon.set("bonus strength", 5);

    string expected = sprintf(StrongEnchantment, "This long sword is enchanted with a powerful aura.\n") +
        sprintf(SingleDetailText, "Weight", 5) + 
        sprintf(Unidentified, "This item has not been identified.\n");
    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsNotShownWhenNotIdentified()
{
    Weapon.set("enchantments", (["fire":10, "magical" : 2]));

    string expected = sprintf(Enchanted, "This long sword is enchanted.\n") +
        sprintf(SingleDetailText, "Weight", 5) + 
        sprintf(Unidentified, "This item has not been identified.\n");

    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsWithDetailsShownWhenIdentified()
{
    Weapon.set("identified");

    string expected = sprintf(NormalEquipment, "This long sword is typical for its type.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", -5, 95) +
        sprintf(DetailsText, "Damage", 4, 5) +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 15) +
        sprintf(SingleDetailText, "Weight", 5);

    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsModifiedByMaterial()
{
    Weapon.set("identified");
    Weapon.set("material", "galvorn");

    string expected = sprintf(NormalEquipment, "This long sword is typical for its type.\n") +
        sprintf(DetailString, "Material", "Galvorn") +
        sprintf(DetailsText, "Attack", 0, 100) +
        sprintf("\x1b[0;36m    %s: \x1b[0m\x1b[0;33m%d\x1b[0m\x1b[0;33m to %d\x1b[0m", "Damage", 11, 14) +
        sprintf("\x1b[0;31m [+%d %s]\x1b[0m\n", 5, "magical") +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 17) +
        sprintf(SingleDetailText, "Weight", 7);

    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsModifiedByEnchantment()
{
    Weapon.set("identified");
    Weapon.set("material", "galvorn");
    Weapon.set("enchantments", (["fire":10, "magical" : 2]));

    string expected = sprintf(Enchanted, "This long sword is enchanted.\n") +
        sprintf(DetailString, "Material", "Galvorn") +
        sprintf(DetailsText, "Attack", 0, 100) +
        sprintf("\x1b[0;36m    %s: \x1b[0m\x1b[0;33m%d\x1b[0m\x1b[0;33m to %d\x1b[0m", "Damage", 11, 14) +
        sprintf("\x1b[0;31m [+%d %s]\x1b[0m", 10, "fire") +
        sprintf("\x1b[0;31m [+%d %s]\x1b[0m\n", 7, "magical") +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 17) +
        sprintf(SingleDetailText, "Weight", 7);

    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsDisplayBonuses()
{
    Weapon.set("identified");
    Weapon.set("bonus strength", 2);
    Weapon.set("bonus attack", 1);
    Weapon.set("bonus hit points", 10);

    string expected = sprintf(StrongEnchantment, "This long sword is enchanted with a powerful aura.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", -5, 95) +
        sprintf(DetailsText, "Damage", 4, 5) +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 15) +
        sprintf(Value, sprintf("    %s: %d\n", "Bonus attack", 1)) +
        sprintf(Value, sprintf("    %s: %d\n", "Bonus hit points", 10)) +
        sprintf(Value, sprintf("    %s: %d\n", "Bonus strength", 2)) +
        sprintf(SingleDetailText, "Weight", 5);

    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsModifiedBySkillOfUser()
{
    Weapon.set("identified");
    Player.addSkillPoints(100);
    Player.advanceSkill("long sword", 8);

    string expected = sprintf(NormalEquipment, "This long sword is typical for its type.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", 9, 109) +
        sprintf(DetailsText, "Damage", 10, 13) +
        sprintf(DetailsText, "Defense", 3, 4) +
        sprintf(SingleDetailText, "Encumberance", 1) +
        sprintf(SingleDetailText, "Weight", 5);

    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void WeaponStatisticsModifiedByItemCraftsmanship()
{
    Weapon.set("identified");
    Weapon.set("craftsmanship", 35);

    string expected = sprintf(WellCrafted, "This long sword is a well-crafted item.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", -1, 99) +
        sprintf(DetailsText, "Damage", 7, 10) +
        sprintf(DetailsText, "Defense", 0, 1) +
        sprintf(SingleDetailText, "Encumberance", 15) +
        sprintf(SingleDetailText, "Weight", 5);

    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
}

/////////////////////////////////////////////////////////////////////////////
void AutoIdentifyWhenSkillSufficientlyHigh()
{
    Player.addSkillPoints(100);
    Player.advanceSkill("metal crafting", 5);
    Player.advanceSkill("weapon smithing", 10);

    string expected = sprintf(NormalEquipment, "This long sword is typical for its type.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", -5, 95) +
        sprintf(DetailsText, "Damage", 4, 5) +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 15) +
        sprintf(SingleDetailText, "Weight", 5);

    ExpectFalse(Weapon.query("identified"));
    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
    ExpectTrue(Weapon.query("identified"));
}

/////////////////////////////////////////////////////////////////////////////
void AutoIdentifyMagicWhenSpellcraftSufficientlyHigh()
{
    Weapon.set("bonus attack", 1);
    Player.addSkillPoints(100);
    Player.advanceSkill("metal crafting", 5);
    Player.advanceSkill("weapon smithing", 10);
    Player.advanceSkill("spellcraft", 10);

    string expected = sprintf(Enchanted, "This long sword is enchanted.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(DetailsText, "Attack", -5, 95) +
        sprintf(DetailsText, "Damage", 4, 5) +
        sprintf(DetailsText, "Defense", -2, -3) +
        sprintf(SingleDetailText, "Encumberance", 15) +
        sprintf(Value, sprintf("    %s: %d\n", "Bonus attack", 1)) +
        sprintf(SingleDetailText, "Weight", 5);

    ExpectFalse(Weapon.query("identified"));
    ExpectEq(expected, Statistics.getEquipmentStatistics(Weapon, Player));
    ExpectTrue(Weapon.query("identified"));
}

/////////////////////////////////////////////////////////////////////////////
void ArmorStatisticsCorrectlyDisplayed()
{
    object armor = clone_object("/lib/items/armor.c");
    armor.set("armor type", "chainmail");
    armor.set("short", "Chainmail of Blah");
    armor.set("identified");

    string expected = sprintf(NormalEquipment, "This chainmail is typical for its type.\n") +
        sprintf(DetailString, "Material", "Iron") +
        sprintf(SingleDetailText, "Damage Protection", 6) +
        sprintf(SingleDetailText, "Encumberance", 30) +
        sprintf(SingleDetailText, "Weight", 8);

    ExpectEq(expected, Statistics.getEquipmentStatistics(armor, Player));
}

/////////////////////////////////////////////////////////////////////////////
void ArmorStatisticsModifiedByMaterial()
{
    object armor = clone_object("/lib/items/armor.c");
    armor.set("armor type", "chainmail");
    armor.set("short", "Chainmail of Blah");
    armor.set("material", "galvorn");
    armor.set("identified");

    string expected = sprintf(NormalEquipment, "This chainmail is typical for its type.\n") +
        sprintf(DetailString, "Material", "Galvorn") +
        sprintf("\x1b[0;36m    %s: \x1b[0m\x1b[0;33m%d\x1b[0m", "Damage Protection", 11) +
        sprintf("\x1b[0;31m [+%d %s]\x1b[0m", 3, "electricity") +
        sprintf("\x1b[0;31m [+%d %s]\x1b[0m\n", 3, "fire") +
        sprintf(SingleDetailText, "Encumberance", 32) +
        sprintf(SingleDetailText, "Weight", 10);

    ExpectEq(expected, Statistics.getEquipmentStatistics(armor, Player));
}

/////////////////////////////////////////////////////////////////////////////
void ArmorProtectionNotModifiedBySkill()
{
    object armor = clone_object("/lib/items/armor.c");
    armor.set("armor type", "chainmail");
    armor.set("short", "Chainmail of Blah");
    armor.set("material", "galvorn");
    armor.set("identified");

    Player.addSkillPoints(100);
    Player.advanceSkill("chainmail", 10);

    string expected = sprintf(NormalEquipment, "This chainmail is typical for its type.\n") +
        sprintf(DetailString, "Material", "Galvorn") +
        sprintf("\x1b[0;36m    %s: \x1b[0m\x1b[0;33m%d\x1b[0m", "Damage Protection", 11) +
        sprintf("\x1b[0;31m [+%d %s]\x1b[0m", 3, "electricity") +
        sprintf("\x1b[0;31m [+%d %s]\x1b[0m\n", 3, "fire") +
        sprintf(SingleDetailText, "Encumberance", 19) +
        sprintf(SingleDetailText, "Weight", 10);

    ExpectEq(expected, Statistics.getEquipmentStatistics(armor, Player));
}

/////////////////////////////////////////////////////////////////////////////
void NonEquipmentItemsShowMagicalProperties()
{
    object item = clone_object("/lib/items/item.c");
    item.set("identified");
    item.set("enchantments", (["fire":5, "air":3]));
    item.set("resistances", (["fire":5]));
    item.set("bonus attack", 3);

    string expected = sprintf(Enchanted, "This item is enchanted.\n") +
        sprintf("\x1b[0;33m    %s: \x1b[0m%s", "Enchantments", 
        sprintf("\x1b[0;31m [+%d %s]\x1b[0m", 3, "air") +
        sprintf("\x1b[0;31m [+%d %s]\x1b[0m\n", 5, "fire")) +
        sprintf("\x1b[0;33m    %s: \x1b[0m%s", "Resistances",
        sprintf("\x1b[0;31m [+%d %s]\x1b[0m\n", 5, "fire")) +
        sprintf("\x1b[0;33m    %s: %d\n\x1b[0m", "Bonus attack", 3);

    ExpectEq(expected, Statistics.getEquipmentStatistics(item, Player));
}
