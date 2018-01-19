//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, Realms MUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Armor;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Armor = clone_object("/lib/items/armor");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Armor);
}

/////////////////////////////////////////////////////////////////////////////
void ItemPropertiesCanBeSet()
{
    // Only test a few of these - the full set is tested in items/itemTest
    ExpectTrue(Armor->set("bonus armor class", 5), "bonus armor class can be set");
    ExpectEq(5, Armor->query("bonus armor class"), "bonus armor class query returns correctly");

    ExpectTrue(Armor->set("value", 850), "value can be set");
    ExpectEq(850, Armor->query("value"), "850 value was returned");

    ExpectTrue(Armor->set("no sell", 1), "no sell can be set");
    ExpectEq(1, Armor->query("no sell"), "1 no sell was returned");

    ExpectTrue(Armor->set("name", "blah"), "name can be set");
    ExpectEq("blah", Armor->query("name"), "'blah' name was returned");
}

/////////////////////////////////////////////////////////////////////////////
void ArmorClassCanBeSet()
{
    ExpectTrue(Armor->set("armor class", 5), "armor class can be set");
    ExpectEq(5, Armor->query("armor class"), "5 armor class was returned");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidArmorClassCannotBeSet()
{
    string expected = "*Armor: The passed 'armor class' data must be an integer.\n";

    string err = catch (Armor->set("armor class", "spaghetti"));
    ExpectEq(expected, err, "armor class cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void ArmorTypeCanBeSet()
{
    // A comprehensive test of the valid armor types is in the materialsDictionary test
    ExpectTrue(Armor->set("armor type", "chainmail"), "armor type can be set");
    ExpectEq("chainmail", Armor->query("armor type"), "'chainmail' armor type was returned");

    ExpectTrue(Armor->set("armor type", "plate armor"), "armor type can be set");
    ExpectEq("plate armor", Armor->query("armor type"), "'plate armor' armor type was returned");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidArmorTypeCannotBeSet()
{
    string expected = "*Armor: The 'armor type' element must be a string as defined in the keys of the itemTypes mapping in /lib/dictionaries/materialsDictionary.c.\n";

    string err = catch (Armor->set("armor type", "blah"));
    ExpectEq(expected, err, "armor type cannot be set");
}

/////////////////////////////////////////////////////////////////////////////
void BlueprintCanBeSet()
{
    ExpectTrue(Armor->set("blueprint", "chainmail"), "blueprint can be set");
    ExpectEq("chainmail", Armor->query("blueprint"), "'chainmail' blueprint was returned");
}

/////////////////////////////////////////////////////////////////////////////
void InvalidBlueprintCannotBeSet()
{
    string expected = "*Armor: The 'blueprint' element must be a string as defined in the keys of the armorBlueprints mapping in /lib/dictionaries/materialsDictionary.c.\n";

    string err = catch (Armor->set("blueprint", "blah"));
    ExpectEq(expected, err, "blueprint cannot be set");
}


