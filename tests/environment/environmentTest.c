//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Environment;
object Dictionary;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    Dictionary->setYear(1);
    Dictionary->setDay(92);
    Dictionary->timeOfDay("noon");
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
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "west");
    Environment->testAddFeature("fake feature", "east");
    Environment->testAddItem("/lib/tests/support/environment/fakeItem.c", "north");

    ExpectSubStringMatch("a deciduous forest. To the south is a dark and foreboding cave largely obscured by foliage.*To the east, north and west is a stand of majestic oak trees with branches laden with acorns.*To the north is a sign.",
        regreplace(Environment->long(), "\n", " ", 1));
}

/////////////////////////////////////////////////////////////////////////////
void BuildingWithoutExitDisplaysCorrectly()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddBuilding("/lib/tests/support/environment/fakeBuilding.c", "north");
    Environment->testAddFeature("/lib/tests/support/environment/fakeSimpleFeature.c", "south");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "west");
    Environment->testAddFeature("fake feature", "east");
    Environment->testAddItem("/lib/tests/support/environment/fakeItem.c", "north");

    ExpectSubStringMatch("a deciduous forest. To the south is a dark and foreboding cave largely obscured by foliage.*To the east and west is a stand of majestic oak trees with branches laden with acorns.*To the north is a sign. To the north is a building.*no obvious exits",
        regreplace(Environment->long(), "\n", " ", 1));
}

/////////////////////////////////////////////////////////////////////////////
void BuildingWithExitDisplaysCorrectly()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddBuilding("/lib/tests/support/environment/fakeBuilding.c", "north", "/lib/tests/support/environment/toLocation.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeSimpleFeature.c", "south");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "west");
    Environment->testAddFeature("fake feature", "east");
    Environment->testAddItem("/lib/tests/support/environment/fakeItem.c", "north");

    ExpectSubStringMatch("a deciduous forest. To the south is a dark and foreboding cave largely obscured by foliage.*To the east and west is a stand of majestic oak trees with branches laden with acorns.*To the north is a sign. To the north is a building.*one obvious exit: north",
        regreplace(Environment->long(), "\n", " ", 1));
}

/////////////////////////////////////////////////////////////////////////////
void SuppressMessageHidesYouSeeFromFeature()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/suppressEntryFeature.c", "south");

    ExpectSubStringMatch("a deciduous forest. To the south a stand of majestic oak",
        regreplace(Environment->long(), "\n", " ", 1));
}

/////////////////////////////////////////////////////////////////////////////
void DefaultDescriptionDisplaysCorrectlyForInteriors()
{
    Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeInteriorFeature.c", "north");

    ExpectSubStringMatch("a stone hallway. To the north is an impressive tapestry of Tantor the Unclean dueling an undead unicorn with his trusty plunger.",
        regreplace(Environment->long(), "\n", " ", 1));
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
void IdReturnsFalseWhenElementNotInEnvironment()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");

    ExpectFalse(Environment->id("raddish"));
}

/////////////////////////////////////////////////////////////////////////////
void IdReturnsTrueWhenElementInEnvironment()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");

    ExpectTrue(Environment->id("fake feature"));
}

/////////////////////////////////////////////////////////////////////////////
void IdReturnsTrueWhenAliasInEnvironment()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");

    ExpectTrue(Environment->id("oak"), "oak is alias");
    ExpectTrue(Environment->id("stand"), "stand is alias");
    ExpectTrue(Environment->id("stand of oak trees"), "stand of oak trees is alias");
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
void LongRaisesErrorWhenTerrainOrInteriorNotSete()
{
    string expected = "*ERROR in environment.c: Either a valid terrain or interior must be set.\n";
    string err = catch (Environment->long());
    ExpectEq(expected, err);
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

/////////////////////////////////////////////////////////////////////////////
void MoveToLocationShowsDarkMessageWhenEnteringDarkArea()
{
    object player = clone_object("/lib/tests/support/services/mockPlayer.c");
    move_object(player, "/lib/tests/support/environment/startingRoom.c");

    command("south", player);
    ExpectSubStringMatch("It is too dark", player->caughtMessage());

    destruct(player);
}

/////////////////////////////////////////////////////////////////////////////
void MoveToLocationShowsCorrectMessageForTimeAndSeason()
{
    destruct(load_object("/lib/tests/support/environment/darkRoom.c"));
    object player = clone_object("/lib/tests/support/services/mockPlayer.c");
    move_object(player, "/lib/tests/support/environment/startingRoom.c");

    object x = clone_object("/lib/tutorial/characters/keeper-of-the-night.c");

    command("south", player);
    ExpectSubStringMatch("It is too dark", player->caughtMessage());

    Dictionary->timeOfDay("night");
    Dictionary->season("spring");
    move_object(player, "/lib/tests/support/environment/startingRoom.c");

    command("south", player);
    ExpectSubStringMatch("a stone hallway.*There is one obvious exit: "
        "north.*A male human", player->caughtMessage());

    destruct(player);
}

/////////////////////////////////////////////////////////////////////////////
void MoveToLocationShowsDescriptionWhenEnteringArtificiallyLightedArea()
{
    destruct(load_object("/lib/tests/support/environment/not-so-dark-room.c"));
    object player = clone_object("/lib/tests/support/services/mockPlayer.c");
    move_object(player, "/lib/tests/support/environment/startingRoom.c");

    command("west", player);
    ExpectSubStringMatch("a stone hallway.*There is one obvious exit: "
        "east.*Black-robed figure", player->caughtMessage());

    destruct(player);
}

/////////////////////////////////////////////////////////////////////////////
void AddFeatureRaisesErrorWhenUnableToRegiterObject()
{
    string expected = "*ERROR in environment.c: Unable to register '/some/bad/path.c'. Be sure that the file exists and inherits a valid environmental element.\n";
    string err = catch (Environment->testAddFeature("/some/bad/path.c", "north"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddFeatureRaisesErrorOnNamingConflict()
{
    string expected = "*ERROR in environment.c: Unable to register '/lib/tests/support/environment/fakeFeatureDuplicate.c'. A conflicting item with that name already exists.\n";
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    string err = catch (Environment->testAddFeature("/lib/tests/support/environment/fakeFeatureDuplicate.c", "north"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddFeatureRaisesErrorOnFailure()
{
    string expected = "*ERROR in environment.c: 'fake forest' is not a valid feature.\n";
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    string err = catch (Environment->testAddFeature("fake forest", "north"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddItemRaisesErrorWhenUnableToRegiterObject()
{
    string expected = "*ERROR in environment.c: Unable to register '/some/bad/path.c'. Be sure that the file exists and inherits a valid environmental element.\n";
    string err = catch (Environment->testAddItem("/some/bad/path.c", "north"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddItemRaisesErrorOnNamingConflict()
{
    string expected = "*ERROR in environment.c: Unable to register '/lib/tests/support/environment/fakeItemDuplicate.c'. A conflicting item with that name already exists.\n";
    Environment->testAddItem("/lib/tests/support/environment/fakeItem.c", "north");
    string err = catch (Environment->testAddItem("/lib/tests/support/environment/fakeItemDuplicate.c", "north"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddItemRaisesErrorOnFailure()
{
    string expected = "*ERROR in environment.c: 'fake forest' is not a valid item.\n";
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    string err = catch (Environment->testAddItem("fake forest", "north"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddExitRaisesErrorOnFailure()
{
    string expected = "*ERROR in environment.c: 'north' must be a string and '0' must be a valid destination file.\n";
    string err = catch (Environment->testAddExit("north"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddBuildingRaisesErrorWhenUnableToRegiterObject()
{
    string expected = "*ERROR in environment.c: Unable to register '/some/bad/path.c'. Be sure that the file exists and inherits a valid environmental element.\n";
    string err = catch (Environment->testAddBuilding("/some/bad/path.c", "north"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddBuildingRaisesErrorOnNamingConflict()
{
    string expected = "*ERROR in environment.c: Unable to register '/lib/tests/support/environment/fakeBuildingDuplicate.c'. A conflicting item with that name already exists.\n";
    Environment->testAddBuilding("/lib/tests/support/environment/fakeBuilding.c", "north");
    string err = catch (Environment->testAddBuilding("/lib/tests/support/environment/fakeBuildingDuplicate.c", "north"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddBuildingRaisesErrorOnFailure()
{
    string expected = "*ERROR in environment.c: 'fake forest' is not a valid building with a valid location.\n";
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    string err = catch (Environment->testAddBuilding("fake forest", "north"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void SetTerrainRaisesErrorWhenUnableToRegiterObject()
{
    string expected = "*ERROR in environment.c: Unable to register '/some/bad/path.c'. Be sure that the file exists and inherits a valid environmental element.\n";
    string err = catch (Environment->testSetTerrain("/some/bad/path.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void SetTerrainRaisesErrorOnNamingConflict()
{
    string expected = "*ERROR in environment.c: Unable to register '/lib/tests/support/environment/fakeTerrainDuplicate.c'. A conflicting item with that name already exists.\n";
    Dictionary->registerElement("/lib/tests/support/environment/fakeTerrain.c", "terrain");
    string err = catch (Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrainDuplicate.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void SetTerrainRaisesErrorOnFailure()
{
    string expected = "*ERROR in environment.c: 'fake sign' is not a valid terrain.\n";
    Environment->testAddItem("/lib/tests/support/environment/fakeItem.c", "north");
    string err = catch (Environment->testSetTerrain("fake sign"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void SetTerrainCanOnlyBeCalledOnce()
{
    string expected = "*ERROR in environment.c: Only one terrain OR one interior can be set.\n";
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    string err = catch (Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void SetTerrainCannotBeCalledIfInteriorSet()
{
    string expected = "*ERROR in environment.c: Only one terrain OR one interior can be set.\n";
    Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c");
    string err = catch (Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void SetInteriorCannotBeCalledIfTerrainSet()
{
    string expected = "*ERROR in environment.c: Only one terrain OR one interior can be set.\n";
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    string err = catch (Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void SetInteriorRaisesErrorWhenUnableToRegiterObject()
{
    string expected = "*ERROR in environment.c: Unable to register '/some/bad/path.c'. Be sure that the file exists and inherits a valid environmental element.\n";
    string err = catch (Environment->testSetInterior("/some/bad/path.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void SetInteriorRaisesErrorOnNamingConflict()
{
    string expected = "*ERROR in environment.c: Unable to register '/lib/tests/support/environment/fakeInteriorDuplicate.c'. A conflicting item with that name already exists.\n";
    Dictionary->registerElement("/lib/tests/support/environment/fakeInterior.c", "interior");
    string err = catch (Environment->testSetInterior("/lib/tests/support/environment/fakeInteriorDuplicate.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void SetInteriorRaisesErrorOnFailure()
{
    string expected = "*ERROR in environment.c: 'fake sign' is not a valid interior.\n";
    Environment->testAddItem("/lib/tests/support/environment/fakeItem.c", "north");
    string err = catch (Environment->testSetInterior("fake sign"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void SetInteriorCanOnlyBeCalledOnce()
{
    string expected = "*ERROR in environment.c: Only one terrain OR one interior can be set.\n";
    Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c");
    string err = catch (Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddObjectRaisesErrorOnFailure()
{
    string expected = "*ERROR in environment.c: '/bad/path.c' is not a valid file.\n";
    string err = catch (Environment->testAddObject("/bad/path.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void CanAddShop()
{
    Environment->testAddShop("/lib/environment/shopInventories/swordsmith.c");
    ExpectEq("lib/environment/shopInventories/swordsmith.c", Environment->getShop());
}

/////////////////////////////////////////////////////////////////////////////
void ShopInventoryUpdatesOnReset()
{
    Environment->testAddShop("/lib/environment/shopInventories/swordsmith.c");
    Environment->getShop()->resetInventory();
    ExpectEq(0, sizeof(Environment->getShop()->storeInventory()));
    Environment->reset();
    ExpectTrue(15 < sizeof(Environment->getShop()->storeInventory()));
}

/////////////////////////////////////////////////////////////////////////////
void CanOnlyAddOneShop()
{
    Environment->testAddShop("/lib/environment/shopInventories/swordsmith.c");

    string expected = "*ERROR in environment.c: a shop has already been assigned to this environment.\n";
    string err = catch (Environment->testAddShop("/lib/environment/shopInventories/tailor.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddShopRaisesErrorIfInvalidObjectPassed()
{
    string expected = "*ERROR in environment.c: '/bad/path.c' is not a valid shop.\n";
    string err = catch (Environment->testAddShop("/bad/path.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddShopRaisesErrorIfPassedFileIsNotAShop()
{
    string expected = "*ERROR in environment.c: '/lib/environment/environment.c' is not a valid shop.\n";
    string err = catch (Environment->testAddShop("/lib/environment/environment.c"));
    ExpectEq(expected, err);
}

/////////////////////////////////////////////////////////////////////////////
void AddObjectToDefaultStateCreatesObjectOnReset()
{
    Environment->testAddObject("/lib/items/weapon.c");
    ExpectFalse(sizeof(all_inventory(Environment)));
    Environment->reset();
    ExpectEq(1, sizeof(all_inventory(Environment)));
}

/////////////////////////////////////////////////////////////////////////////
void SetupIsOnlyCalledOnceByReset()
{
    Environment->reset();
    ExpectEq(1, Environment->setupCalled());
    Environment->reset();
    ExpectEq(1, Environment->setupCalled());
}

/////////////////////////////////////////////////////////////////////////////
void RepeatedResetsDoNotCreateMultiplesOfSameObject()
{
    Environment->testAddObject("/lib/items/weapon.c");
    ExpectFalse(sizeof(all_inventory(Environment)));
    Environment->reset();
    ExpectEq(1, sizeof(all_inventory(Environment)));
    Environment->reset();
    ExpectEq(1, sizeof(all_inventory(Environment)));
}

/////////////////////////////////////////////////////////////////////////////
void ResetWillRecreateOnlyObjectsThatAreNotPresent()
{
    Environment->testAddObject("/lib/items/weapon.c");
    Environment->testAddObject("/lib/items/armor.c");
    ExpectFalse(sizeof(all_inventory(Environment)));
    Environment->reset();
    ExpectEq(2, sizeof(all_inventory(Environment)));
    destruct(all_inventory(Environment)[0]);
    ExpectEq(1, sizeof(all_inventory(Environment)));
    Environment->reset();
    ExpectEq(2, sizeof(all_inventory(Environment)));
    ExpectTrue(present_clone("/lib/items/weapon.c", Environment));
    ExpectTrue(present_clone("/lib/items/armor.c", Environment));
}

/////////////////////////////////////////////////////////////////////////////
void OnlyObjectsForProperStateArePresent()
{
    ToggleCallOutBypass();
    object stateMachine = 
        load_object("/lib/dictionaries/stateMachineDictionary.c")->getStateMachine(
            "/lib/tests/support/core/simpleStateMachine.c");

    Environment->setStateMachine("/lib/tests/support/core/simpleStateMachine.c", 1);
    Environment->testAddObject("/lib/items/weapon.c");
    Environment->testAddObject("/lib/items/armor.c", "blah");
    Environment->testAddObject("/lib/items/item.c", "blah2");

    Environment->reset();
    ExpectEq(1, sizeof(all_inventory(Environment)), "1 element visible for default state");
    ExpectTrue(present_clone("/lib/items/weapon.c", Environment), "weapon present");

    stateMachine->receiveEvent(Environment, "blahTransition");
    ExpectEq(2, sizeof(all_inventory(Environment)), "2 elements visible for 'blah' state");
    ExpectTrue(present_clone("/lib/items/weapon.c", Environment), "weapon present");
    ExpectTrue(present_clone("/lib/items/armor.c", Environment), "armor present");

    stateMachine->receiveEvent(Environment, "blahTwoTransition");
    ExpectEq(2, sizeof(all_inventory(Environment)), "2 elements visible for 'blah2' state");
    ExpectTrue(present_clone("/lib/items/weapon.c", Environment), "weapon present");
    ExpectTrue(present_clone("/lib/items/item.c", Environment), "item present");
    
    destruct(stateMachine);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void CallerForOnStateChangedMustBeCurrentlySetStateMachine()
{
    ToggleCallOutBypass();
    object stateMachine =
        load_object("/lib/dictionaries/stateMachineDictionary.c")->getStateMachine(
            "/lib/tests/support/core/simpleStateMachine.c");

    Environment->setStateMachine("/lib/tests/support/core/simpleStateMachine.c", 1);
    Environment->testAddObject("/lib/items/weapon.c");
    Environment->testAddObject("/lib/items/armor.c", "blah");
    Environment->testAddObject("/lib/items/item.c", "blah2");

    Environment->reset();
    ExpectEq(1, sizeof(all_inventory(Environment)), "1 element visible for default state");
    ExpectTrue(present_clone("/lib/items/weapon.c", Environment), "weapon present");

    stateMachine->testOverrideCurrentState("blah");
    Environment->onStateChanged(this_object(), "blah");
    ExpectEq(1, sizeof(all_inventory(Environment)), "1 element visible if state machine not initiator");
    ExpectTrue(present_clone("/lib/items/weapon.c", Environment), "weapon present");
    ExpectFalse(present_clone("/lib/items/armor.c", Environment), "armor present");

    Environment->onStateChanged(stateMachine, "blah");
    ExpectEq(2, sizeof(all_inventory(Environment)), "2 elements visible for 'blah2' state");
    ExpectTrue(present_clone("/lib/items/weapon.c", Environment), "weapon present");
    ExpectTrue(present_clone("/lib/items/armor.c", Environment), "armor present");

    destruct(stateMachine);
    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void SetAdditionalLongDescriptionAddsCustomLong()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testSetAdditionalLongDescription("This is an extra message");
    ExpectSubStringMatch("a deciduous forest. To the north is a stand of majestic oak trees with branches laden with acorns.*This is an extra message",
        regreplace(Environment->long(), "\n", " ", 1));
}

/////////////////////////////////////////////////////////////////////////////
void AdditionalLongDescriptionAddsCustomLongOnlyToCorrectState()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testSetAdditionalLongDescription("This is an extra message", "blah");
    ExpectSubStringMatch("a deciduous forest. To the north is a stand of majestic oak trees with branches laden with acorns.*",
        regreplace(Environment->long(), "\n", " ", 1));

    Environment->currentState("blah");
    ExpectSubStringMatch("This is an extra message",
        regreplace(Environment->long(), "\n", " ", 1));
}

/////////////////////////////////////////////////////////////////////////////
void ParseEfunCallForCallOtherWithKeyDisplaysInLong()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddObject("/lib/tests/support/items/testSword.c");
    Environment->testSetAdditionalLongDescription("##call_other::key::/lib/tests/support/items/testSword.c::swordMessage::");
    Environment->reset();

    ExpectTrue(present_clone("/lib/tests/support/items/testSword.c", Environment), "weapon present");
    ExpectSubStringMatch("a deciduous forest. You can feel a weaselish buzz in the air",
        regreplace(Environment->long(), "\n", " ", 1));

}

/////////////////////////////////////////////////////////////////////////////
void InteriorsReturnFalseForIsIlluminatedByDefault()
{
    Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c");
    ExpectFalse(Environment->isIlluminated());
}

/////////////////////////////////////////////////////////////////////////////
void TerrainReturnValueForTimeOfDayForIsIlluminatedByDefault()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Dictionary->timeOfDay("midnight");
    Dictionary->setYear(1); 

    ExpectEq(3, Environment->isIlluminated());

    Dictionary->timeOfDay("dawn");
    ExpectEq(7, Environment->isIlluminated());

    Dictionary->timeOfDay("afternoon");
    ExpectEq(10, Environment->isIlluminated());

    Dictionary->timeOfDay("night");
    ExpectEq(3, Environment->isIlluminated());
}

/////////////////////////////////////////////////////////////////////////////
void TerrainAffectedByLightSources()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddItem("/lib/tests/support/environment/fakeLightSource.c", "north");
    Dictionary->setYear(1);

    Dictionary->timeOfDay("midnight");
    ExpectEq(3, Environment->isIlluminated());

    Dictionary->timeOfDay("night");
    ExpectEq(3, Environment->isIlluminated());

    Dictionary->season("spring");
    ExpectEq(8, Environment->isIlluminated());
}

/////////////////////////////////////////////////////////////////////////////
void TerrainLightAffectedByMoonPhase()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Dictionary->timeOfDay("night");

    Dictionary->setDay(0);
    ExpectEq(1, Environment->isIlluminated());

    Dictionary->setDay(3);
    ExpectEq(2, Environment->isIlluminated());

    Dictionary->setDay(7);
    ExpectEq(3, Environment->isIlluminated());

    Dictionary->setDay(10);
    ExpectEq(4, Environment->isIlluminated());

    Dictionary->setDay(14);
    ExpectEq(5, Environment->isIlluminated());

    Dictionary->setDay(17);
    ExpectEq(4, Environment->isIlluminated());

    Dictionary->setDay(21);
    ExpectEq(3, Environment->isIlluminated());

    Dictionary->setDay(24);
    ExpectEq(2, Environment->isIlluminated());
}

/////////////////////////////////////////////////////////////////////////////
void InteriorLightNotAffectedByOutdoorLight()
{
    Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c");

    Dictionary->timeOfDay("afternoon");
    ExpectEq(0, Environment->isIlluminated());

    Dictionary->timeOfDay("night");

    Dictionary->setDay(0);
    ExpectEq(0, Environment->isIlluminated());

    Dictionary->setDay(3);
    ExpectEq(0, Environment->isIlluminated());

    Dictionary->setDay(7);
    ExpectEq(0, Environment->isIlluminated());

    Dictionary->setDay(10);
    ExpectEq(0, Environment->isIlluminated());

    Dictionary->setDay(14);
    ExpectEq(0, Environment->isIlluminated());

    Dictionary->setDay(17);
    ExpectEq(0, Environment->isIlluminated());

    Dictionary->setDay(21);
    ExpectEq(0, Environment->isIlluminated());

    Dictionary->setDay(24);
    ExpectEq(0, Environment->isIlluminated());

}

/////////////////////////////////////////////////////////////////////////////
void InteriorsAffectedByLightSources()
{
    Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c");
    Environment->testAddItem("/lib/tests/support/environment/fakeLightSource.c", "north");

    ExpectEq(0, Environment->isIlluminated());

    Dictionary->timeOfDay("midnight");
    ExpectEq(0, Environment->isIlluminated());

    Dictionary->timeOfDay("night");
    ExpectEq(0, Environment->isIlluminated());

    Dictionary->season("spring");
    ExpectEq(8, Environment->isIlluminated());
}

/////////////////////////////////////////////////////////////////////////////
void CanAddCustomLocations()
{
    mapping location = ([
        "description": "slightly east of north and upwardish",
        "x": 100,
        "y": 10,
        "z": 125,
        "x-rotation": 270,
        "y-rotation": 60,
        "z-rotation": 90
    ]);

    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", location);
    ExpectSubStringMatch("To the slightly east of north and upwardish is .*",
        regreplace(Environment->long(), "\n", " ", 1));
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddInvalidLocations()
{
    mapping location = ([
        "description":"slightly east of north and upwardish",
            "x" : 100,
            "y" : 10,
            "z" : 125,
            "x-rotation" : 270,
            "z-rotation" : 90
    ]);

    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    string error = catch(Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", location));
    ExpectSubStringMatch("ERROR in environment.c.*slightly east of north and upwardish", error);
}

/////////////////////////////////////////////////////////////////////////////
void CannotAddUndefinedDefaultLocations()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    string error = catch (Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "turnip"));
    ExpectSubStringMatch("ERROR in environment.c.*turnip", error);
}

/////////////////////////////////////////////////////////////////////////////
void DescriptionDisplaysCorrectlyForObjectsWithoutDescriptions()
{
    Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c");
    Environment->testAddItem("/lib/tests/support/environment/itemWithoutDescription.c");

    ExpectEq("a stone hallway.\n -=-=- There are no obvious exits. \n\n",
        regreplace(Environment->long(), ".+ (a stone.+)", "\\1"));
    ExpectTrue(Environment->id("descriptionless sign"));
}

/////////////////////////////////////////////////////////////////////////////
void DescriptionDisplaysCorrectlyForObjectsWithEmptyDescriptions()
{
    Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c");
    Environment->testAddItem("/lib/tests/support/environment/itemWithEmptyDescription.c");

    ExpectEq("a stone hallway.\n -=-=- There are no obvious exits. \n\n",
        regreplace(Environment->long(), ".+ (a stone.+)", "\\1"));
    ExpectTrue(Environment->id("descriptionless sign"));
}

/////////////////////////////////////////////////////////////////////////////
void ObjectsWithoutDescriptionsCannotHaveDirection()
{
    Environment->testSetInterior("/lib/tests/support/environment/fakeInterior.c");
    string error = catch (Environment->testAddItem("/lib/tests/support/environment/itemWithoutDescription.c", "north"));

    ExpectEq("*ERROR in environment.c: You cannot specify a direction for "
        "'descriptionless sign' as it has no description.\n", error);
}

/////////////////////////////////////////////////////////////////////////////
void NoColorCorrectlyDisplayed()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("none");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("a deciduous forest. To the north.*trees.*"
        "laden with acorns.*glowing.\nThe sun is high in the summer sky.\n"
        " -=-=- There is one obvious exit: north\n"
        "Sword of Blah\n",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void ThreeBitColorCorrectlyDisplayed()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("3-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("0;33m.*a deciduous forest. To the north.*"
        "trees.*laden with acorns.*glowing.*"
        "0m..0;35m -=-=- There is one obvious exit: north\n"
        "..0m..0;36mSword of Blah..0m\n",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EightBitColorCorrectlyDisplayed()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("0;38;5;186m.*a deciduous forest. To the north.*"
        "trees.*laden with acorns.*glowing.*"
        "0m..0;38;5;238;1m -=-=- There is one obvious exit: north\n"
        "..0m..0;38;5;80mSword of Blah..0m\n",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void TwentyFourBitColorCorrectlyDisplayed()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("24-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("0;38;2;200;200;0m.*a deciduous forest. To the north.*"
        "trees.*laden with acorns.*glowing.*"
        "0m..0;38;2;60;60;70;1m -=-=- There is one obvious exit: north\n"
        "..0m..0;38;2;180;180;190mSword of Blah..0m\n",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void UnicodeCorrectlyDisplayed()
{
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->charsetConfiguration("unicode");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("\xe2\x95\x98\xe2\x95\x90\xe2\x95\x90\xe2\x95\x90\xe2\x95\x9b",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void EnvironmentNameReturnsProperValue()
{
    object environment = 
        load_object("/lib/tests/support/environment/startingRoom.c");

    ExpectEq("/lib/tests/support/environment/startingRoom",
        environment->environmentName());

    environment = clone_object("/lib/tests/support/environment/startingRoom.c");

    ExpectEq("/lib/tests/support/environment/startingRoom",
        environment->environmentName());

    destruct(environment);
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyMoveToCloneWhenCloneEnvironmentSet()
{
    object environment =
        load_object("/lib/tests/support/environment/clonedRoom.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");

    environment->enterEnvironment(person);

    ExpectFalse(clonep(environment));
    ExpectTrue(clonep(environment(person)));
    ExpectEq(environment->environmentName(),
        environment(person)->environmentName());

    destruct(person);
}

/////////////////////////////////////////////////////////////////////////////
void CanReEnterSameClone()
{
    object environment =
        load_object("/lib/tests/support/environment/clonedRoom.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");

    environment->enterEnvironment(person);

    ExpectEq("/lib/tests/support/environment/clonedRoom",
        environment(person)->environmentName());

    object firstEntry = environment(person);

    environment->enterEnvironment(person);

    ExpectEq(firstEntry, environment(person));

    destruct(person);
}

/////////////////////////////////////////////////////////////////////////////
void DifferentPeopleMoveToDifferentClonedEnvironments()
{
    object environment =
        load_object("/lib/tests/support/environment/clonedRoom.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");

    object person2 = clone_object("/lib/tests/support/services/mockPlayer.c");
    person2->Name("fred");

    environment->enterEnvironment(person);
    environment->enterEnvironment(person2);

    ExpectNotEq(object_name(environment(person2)),
        object_name(environment(person)));

    destruct(person);
    destruct(person2);
}

/////////////////////////////////////////////////////////////////////////////
void HenchmenMoveToSameClonedEnvironment()
{
    object environment =
        load_object("/lib/tests/support/environment/clonedRoom.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");

    object person2 = clone_object("/lib/realizations/henchman.c");
    person2->Name("fred");
    person2->setLeader(person);

    environment->enterEnvironment(person);
    environment->enterEnvironment(person2);

    ExpectEq(environment(person2)->environmentName(),
        environment(person)->environmentName());

    destruct(person);
    destruct(person2);
}

/////////////////////////////////////////////////////////////////////////////
void LongRecoversWhenDictionaryReset()
{
    destruct(Environment);
    Environment = load_object("/lib/tests/support/environment/darkRoom.c");
    ExpectSubStringMatch("stone hallway.*trees.*light.*long.*description",
        Environment->long());

    destruct(Dictionary);
    Dictionary = load_object("/lib/dictionaries/environmentDictionary.c");
    ExpectSubStringMatch("stone hallway.*trees.*light.*long.*description",
        Environment->long());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysDawn()
{
    Dictionary->timeOfDay("dawn");
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("a forest with a little light.*faint.*dawn.*light.*"
        "38;5;166mThe red/orange glow to the east beckons the new day.*"
        "There is one obvious exit: north.*Long sword",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysMorning()
{
    Dictionary->timeOfDay("morning");
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("a deciduous forest.*"
        "38;5;184mThe sun is low in the eastern summer sky.*"
        "There is one obvious exit: north.*Sword of Blah",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysNoon()
{
    Dictionary->timeOfDay("noon");
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("a deciduous forest.*noonish.*"
        "38;5;226mThe sun is high in the summer sky.*"
        "There is one obvious exit: north.*Sword of Blah",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysAfternoon()
{
    Dictionary->timeOfDay("afternoon");
    Dictionary->setDay(0);
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("a deciduous forest.*afternooningly.*"
        "38;5;190mThe sun has begun to wester in the spring sky.*"
        "There is one obvious exit: north.*Sword of Blah",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysEvening()
{
    Dictionary->timeOfDay("evening");
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("a deciduous forest.*late-day.*"
        "38;5;184mThe sun is low in the western summer sky.*"
        "There is one obvious exit: north.*Sword of Blah",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysDusk()
{
    Dictionary->timeOfDay("dusk");
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("a forest with a little light.*failing.*light.*"
        "38;5;166mThe red/orange glow in the western sky signals the day's end.*"
        "There is one obvious exit: north.*Long sword",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysNightWithNewMoon()
{
    Dictionary->timeOfDay("night");
    Dictionary->setDay(0);
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("very dark forest.*massive.*silhouette.*outlined in the dark.*"
        "38;5;57mA canopy of stars blankets the region.*"
        "There is one obvious exit: north.*The silhouette of an item, but it "
        "is too dark to identify it",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysNightWithWaxingCrescent()
{
    Dictionary->timeOfDay("night");
    Dictionary->setDay(4);
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("very dark forest.*massive.*silhouette.*outlined in the dark.*"
        "38;5;57mA canopy of stars blankets the region. The moon, a waxing crescent, "
        "is low in\nthe eastern sky.*"
        "There is one obvious exit: north.*The silhouette of an item, but it "
        "is too dark to identify it",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysNightWithFirstQuarter()
{
    Dictionary->timeOfDay("night");
    Dictionary->setDay(6);
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("barely-lit forest.*silhouette.*deciduous.*outlined in the dark.*"
        "38;5;57mA canopy of stars blankets the region. The moon, a first quarter, "
        "is low in\nthe eastern sky.*"
        "There is one obvious exit: north.*The silhouette of a weapon",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysMidnightWithWaxingGibbous()
{
    Dictionary->timeOfDay("midnight");
    Dictionary->setDay(10);
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("barely-lit forest.*silhouette.*deciduous.*outlined.*eery.*black.*"
        "38;5;56mA canopy of stars blankets the region. The moon, a waxing gibbous, "
        "is almost\ndirectly overhead.*"
        "There is one obvious exit: north.*The silhouette of a weapon",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysMidnightWithFullMoon()
{
    Dictionary->timeOfDay("midnight");
    Dictionary->setDay(13);
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("dimly-lit forest.*silhouette.*oak.*trees.*outlined.*eery.*black.*"
        "38;5;56mA canopy of stars blankets the region. The moon, a full moon, "
        "is almost\ndirectly overhead.*"
        "There is one obvious exit: north.*An apparent long sword",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysMidnightWithWaningGibbous()
{
    Dictionary->timeOfDay("midnight");
    Dictionary->setDay(16);
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("barely-lit forest.*silhouette.*deciduous.*outlined.*eery.*black.*"
        "38;5;56mA canopy of stars blankets the region. The moon, a waning gibbous, "
        "is almost\ndirectly overhead.*"
        "There is one obvious exit: north.*The silhouette of a weapon",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysLateNightWithLastQuarter()
{
    Dictionary->timeOfDay("late night");
    Dictionary->setDay(20);
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("barely-lit forest.*silhouette.*deciduous.*trees.*"
        "38;5;57mA canopy of stars blankets the region. The moon, a last quarter, "
        "is low in the\nwestern sky.*"
        "There is one obvious exit: north.*The silhouette of a weapon",
        person->caughtMessage());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectlyDisplaysLateNightWithWaningCrescent()
{
    Dictionary->timeOfDay("late night");
    Dictionary->setDay(24);
    Environment->testSetTerrain("/lib/tests/support/environment/fakeTerrain.c");
    Environment->testAddFeature("/lib/tests/support/environment/fakeFeature.c", "north");
    Environment->testAddExit("north", "/lib/tests/support/environment/toLocation.c");

    object person = clone_object("/lib/tests/support/services/mockPlayer.c");
    person->Name("dwight");
    person->colorConfiguration("8-bit");
    move_object(person, Environment);

    object weapon = clone_object("/lib/items/weapon.c");
    weapon->set("name", "blah");
    weapon->set("weapon type", "long sword");
    weapon->set("short", "Sword of Blah");
    move_object(weapon, Environment);

    command("look", person);
    ExpectSubStringMatch("very dark forest.*silhouette.*trees.*"
        "38;5;57mA canopy of stars blankets the region. The moon, a waning crescent, "
        "is low in\nthe western sky.*"
        "There is one obvious exit: north.*The silhouette of an item, "
        "but it is too dark to identify it",
        person->caughtMessage());
}
