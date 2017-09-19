//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Environment;
object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    Environment = clone_object("/lib/tests/support/environment/testEnvironment.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Environment);
    destruct(Dictionary);
}

/////////////////////////////////////////////////////////////////////////////
void DefaultDescriptionDisplaysCorrectlyForTerrain()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddFeature("/lib/tests/support/environment/fakeSimpleFeature.c", "south");
    Environment->testAddFeature("fake feature", "west");
    Environment->testAddFeature("fake feature", "east");

    ExpectSubStringMatch("a forest. To the south you see a dark and foreboding cave largely obscured by foliage. To the north, west and east you see a stand of majestic oak trees with branches laden with acorns.",
        Environment->long());
}

/////////////////////////////////////////////////////////////////////////////
void DefaultDescriptionDisplaysCorrectlyForInteriors()
{
    Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeInteriorFeature.c", "north");

    ExpectSubStringMatch("a stone hallway. To the north you see an impressive tapestry of Tantor the Unclean dueling an undead unicorn with his trusty plunger.",
        Environment->long());
}

/////////////////////////////////////////////////////////////////////////////
void IsEnvironmentalElementReturnsFalseWhenElementNotInEnvironment()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");

    ExpectFalse(Environment->isEnvironmentalElement("raddish"));
}

/////////////////////////////////////////////////////////////////////////////
void IsEnvironmentalElementReturnsTrueWhenElementInEnvironment()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");

    ExpectTrue(Environment->isEnvironmentalElement("fake feature"));
}

/////////////////////////////////////////////////////////////////////////////
void IsEnvironmentalElementReturnsTrueWhenAliasInEnvironment()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");

    ExpectTrue(Environment->isEnvironmentalElement("oak"), "oak is alias");
    ExpectTrue(Environment->isEnvironmentalElement("stand"), "stand is alias");
    ExpectTrue(Environment->isEnvironmentalElement("stand of oak trees"), "stand of oak trees is alias");
}

/////////////////////////////////////////////////////////////////////////////
void AliasesForStateNotAvailableWhenNotInProperState()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");

    ExpectTrue(Environment->isEnvironmentalElement("oak"), "oak is alias");
    ExpectTrue(Environment->isEnvironmentalElement("stand"), "stand is alias");
    ExpectTrue(Environment->isEnvironmentalElement("stand of oak trees"), "stand of oak trees is alias");
    ExpectFalse(Environment->isEnvironmentalElement("charred stumps"), "charred stumps is not alias");
    ExpectFalse(Environment->isEnvironmentalElement("tree stumps"), "tree stumps is not alias");
    ExpectFalse(Environment->isEnvironmentalElement("stumps"), "stumps is not alias");

    Environment->currentState("deadified");
    ExpectFalse(Environment->isEnvironmentalElement("oak"), "oak is not alias");
    ExpectFalse(Environment->isEnvironmentalElement("stand"), "stand is not alias");
    ExpectFalse(Environment->isEnvironmentalElement("stand of oak trees"), "stand of oak trees is not alias");
    ExpectTrue(Environment->isEnvironmentalElement("charred stumps"), "charred stumps is alias");
    ExpectTrue(Environment->isEnvironmentalElement("tree stumps"), "tree stumps is alias");
    ExpectTrue(Environment->isEnvironmentalElement("stumps"), "stumps is alias");
}

/////////////////////////////////////////////////////////////////////////////
void LongShowsInventory()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    object person = clone_object("/lib/realizations/player.c");
    person->Name("dwight");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    ExpectSubStringMatch("Dwight", Environment->long());
    ExpectSubStringMatch("Sword of Blah", Environment->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongShowsNoObviousExits()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");

    ExpectSubStringMatch("-=-=- There are no obvious exits",
        Environment->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongShowsOneObviousExit()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/some/path.c");
    ExpectSubStringMatch("-=-=- There is one obvious exit: north",
        Environment->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongShowsTwoObviousExits()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/some/path.c");
    Environment->testAddExit("south", "/some/path2.c");
    ExpectSubStringMatch("-=-=- There are two obvious exits: [a-z]+, [a-z]+",
        Environment->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongShowsManyObviousExits()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/some/path.c");
    Environment->testAddExit("south", "/some/path2.c");
    Environment->testAddExit("east", "/some/path3.c");
    Environment->testAddExit("west", "/some/path4.c");
    Environment->testAddExit("up", "/some/path5.c");

    ExpectSubStringMatch("-=-=- There are five obvious exits: [a-z, ]+",
        Environment->long());
}

/////////////////////////////////////////////////////////////////////////////
void LongOnlyShowsExitsWhenInCorrectState()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/some/path.c");
    Environment->testAddExit("south", "/some/path2.c", "weasels");

    ExpectSubStringMatch("-=-=- There is one obvious exit: north",
        Environment->long());

    Environment->currentState("weasels");
    ExpectSubStringMatch("-=-=- There are two obvious exits: [a-z]+, [a-z]+",
        Environment->long());
}

/////////////////////////////////////////////////////////////////////////////
void CanMoveToAttachedLocation()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/realizations/player.c");
    person->Name("dwight");
    move_object(person, Environment);
    ExpectEq("lib/tests/support/environment/testEnvironment.c", program_name(environment(person)));

    command("north", person);
    ExpectEq("lib/tests/support/environment/toLocation.c", program_name(environment(person)));
}

/////////////////////////////////////////////////////////////////////////////
void MovesToLocationForAppropriateState()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");
    Environment->testAddExit("north", "/lib/tests/support/environment/fromLocation.c", "deadified");
    Environment->currentState("deadified");

    object person = clone_object("/lib/realizations/player.c");
    person->Name("dwight");
    move_object(person, Environment);
    ExpectEq("lib/tests/support/environment/testEnvironment.c", program_name(environment(person)));

    command("north", person);
    ExpectEq("lib/tests/support/environment/fromLocation.c", program_name(environment(person)));
}

/////////////////////////////////////////////////////////////////////////////
void MovesToDefaultLocationWhenNotDefinedInState()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");
    Environment->testAddExit("north", "/lib/tests/support/environment/fromLocation.c", "deadified");
    Environment->currentState("otherstate");

    object person = clone_object("/lib/realizations/player.c");
    person->Name("dwight");
    move_object(person, Environment);
    ExpectEq("lib/tests/support/environment/testEnvironment.c", program_name(environment(person)));

    command("north", person);
    ExpectEq("lib/tests/support/environment/toLocation.c", program_name(environment(person)));
}

/////////////////////////////////////////////////////////////////////////////
void DefaultMoveLocationsStillAvailableWhenInDifferentStateAndNotOverridden()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("south", "/lib/tests/support/environment/toLocation.c");
    Environment->testAddExit("north", "/lib/tests/support/environment/fromLocation.c", "deadified");
    Environment->currentState("deadified");

    object person = clone_object("/lib/realizations/player.c");
    person->Name("dwight");
    move_object(person, Environment);
    ExpectEq("lib/tests/support/environment/testEnvironment.c", program_name(environment(person)));

    command("south", person);
    ExpectEq("lib/tests/support/environment/toLocation.c", program_name(environment(person)));
}