//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Region;
object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player->Name("bob");
    Player->addCommands();
    Player->colorConfiguration("8-bit");
    Player->charsetConfiguration("unicode");

    Region = clone_object("/lib/tests/support/environment/regionHelper.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Region);
    destruct(Player);
}

/////////////////////////////////////////////////////////////////////////////
void SettingInvalidRegionTypeThrowsError()
{
    string err = catch (Region->setRegionType("bad region name"));
    string expectedError = "*ERROR - region: The region must be a valid type "
        "as defined in /lib/dictionaries/regions/region-types.h\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid names");
}

/////////////////////////////////////////////////////////////////////////////
void CannotGenerateRegionWithoutType()
{
    Region->setRegionName("a forest");

    string err = catch (Region->createRegion());
    string expectedError = "*ERROR - region: The region type must be set before it is generated.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid names");
}

/////////////////////////////////////////////////////////////////////////////
void CannotGenerateRegionWithoutName()
{
    Region->setRegionType("forest");

    string err = catch (Region->createRegion());
    string expectedError = "*ERROR - region: The region name must be set before it is generated.\n";

    ExpectEq(expectedError, err, "The correct exception is thrown when setting invalid names");
}

/////////////////////////////////////////////////////////////////////////////
void SendingEntryCreatesMapWithCorrectEntryPoint()
{
    Region->setRegionName("a forest");
    Region->setRegionType("forest");

    Region->setDimensions(5, 5);
    ExpectEq("north", Region->createRegion("south"));
    ExpectEq("west", Region->createRegion("east"));
}

/////////////////////////////////////////////////////////////////////////////
void CanCreateWithSpecificEntryPoint()
{
    Region->setRegionName("a forest");
    Region->setRegionType("forest");

    Region->setDimensions(5, 5);
    Region->createRegion("south", 0, ({ 3, 0}));

    ExpectEq(({ 3, 0 }), Region->EntryLocation());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectNumberOfRoomsGenerated()
{
    Region->setRegionName("a forest");
    Region->setRegionType("forest");

    Region->setDimensions(5, 5);
    Region->createRegion();

    // At least 5 rooms and an entrance are created. There may also be an
    // exit, but this is not guaranteed.
    ExpectTrue(Region->generatedRoomCount() >= 6);
}

/////////////////////////////////////////////////////////////////////////////
void AllGeneratedRoomsHaveExits()
{
    Region->setRegionName("a forest");
    Region->setRegionType("forest");

    Region->setDimensions(5, 5);
    Region->createRegion();

    foreach(mapping room in Region->rooms())
    {
        ExpectTrue(sizeof(room["exits"]));
    }
}

/////////////////////////////////////////////////////////////////////////////
void CanCreateGeneratedRegionFromRealEnvironment()
{
    object environment = 
        load_object("/lib/tests/support/environment/startingRoom.c");

    object region = environment->addGeneratedRegion("north", "forest", 5, 5);
    move_object(Player, environment);

    command("n", Player);
    ExpectEq(region->getEntryCoordinates(), environment(Player)->getCoordinates());
    ExpectEq(region->getEnvironment(region->getEntryCoordinates()),
        environment(Player));

    command("s", Player);
    ExpectEq(environment, environment(Player));

    destruct(environment);
}

/////////////////////////////////////////////////////////////////////////////
void CanCreateManualRegions()
{
    Player->colorConfiguration("none");
    Player->charsetConfiguration("ascii");

    Region->setRegionName("a forest");
    Region->setRegionType("forest");

    Region->setDimensions(5, 5);
    Region->setEntryCoordinate(0, 0, 
        "/lib/tests/support/environment/region/0x0.c", "west",
        "/lib/tests/support/environment/darkRoom.c");

    Region->setCoordinate(0, 1, "/lib/tests/support/environment/region/0x1.c");
    Region->setCoordinate(1, 0, "/lib/tests/support/environment/region/1x0.c",
        "path");
    Region->setCoordinate(1, 1, "/lib/tests/support/environment/region/1x1.c",
        "path");
    Region->setCoordinate(1, 2, "/lib/tests/support/environment/region/1x2.c",
        "path");
    Region->setCoordinate(2, 2, "/lib/tests/support/environment/region/2x2.c");
    Region->setCoordinate(1, 3, "/lib/tests/support/environment/region/1x3.c",
        "path");
    Region->setExitCoordinate(1, 4, "/lib/tests/support/environment/region/1x4.c",
        "north");

    ExpectEq("\n    |          \n"
        "    X          \n"
        "    |          \n"
        "    |          \n"
        "    o          \n"
        "    |          \n"
        "    |          \n"
        "    o--#       \n"
        "    |          \n"
        "    |          \n"
        " #--o          \n"
        "    |          \n"
        "    |          \n"
        "-#--o          \n"
        "               \n", Region->displayMap(Player));
}

/////////////////////////////////////////////////////////////////////////////
void MapsChangeWithStateTransitions()
{
    Player->colorConfiguration("none");
    Player->charsetConfiguration("ascii");
    move_object(Player,
        "/lib/tutorial/temple/environment/rooms/entry-to-pedestal.c");

    command("s", Player);
    
    object region = environment(Player)->getRegion();
    object stateMachine = environment(Player)->stateMachine();

    ExpectEq("\n"
        " |                   \n"
        " #  o  o  o  o  #    \n"
        "                     \n"
        "                     \n"
        " o  o  o  o  o  #    \n"
        "                     \n"
        "                     \n"
        " o  o  o  o  o       \n"
        "                     \n"
        "                     \n"
        " o  o  o  o  o       \n"
        "                     \n"
        "                     \n"
        " o  o  o  o  o       \n"
        "                     \n"
        "                     \n"                     
        "                     \n"
        "                     \n"
        "                     \n"
        "                     \n"
        "                     \n", region->displayMap(Player, stateMachine->getCurrentState()));

    command("get rune", Player);
    command("place rune", Player);
    stateMachine->receiveEvent(Player, "startFirstTest");

    ExpectEq("\n"
        " |                   \n"
        " #--o  o  o  o--#-   \n"
        "    |        |       \n"
        "    |        |       \n"
        " o  o--o--o  o  #    \n"
        "          |  |       \n"
        "          |  |       \n"
        " o  o  o--o  o       \n"
        "       |     |       \n"
        "       |     |       \n"
        " o  o  o--o--o       \n"
        "                     \n"
        "                     \n"
        " o  o  o  o  o       \n"
        "                     \n"
        "                     \n"
        "                     \n"
        "                     \n"
        "                     \n"
        "                     \n"
        "                     \n", region->displayMap(Player, stateMachine->getCurrentState()));
}

/////////////////////////////////////////////////////////////////////////////
void CanGenerateSettlement()
{
    ToggleCallOutBypass();
    Player->colorConfiguration("none");
    Player->charsetConfiguration("unicode");

    Region->setRegionName("a forest");
    Region->setRegionType("forest");
    Region->setDimensions(10,10);
    Region->setSettlementChance(0);
    Region->createRegion();

    ExpectFalse(sizeof(Region->decorators()));
    ExpectTrue(sizeof(Region->rooms()));

    Region->setSettlementChance(100);
    Region->createRegion();

    ExpectTrue(sizeof(Region->decorators()));
    ExpectTrue(sizeof(Region->rooms()));

    move_object(Player, Region->getSettlementEntrance());

    command("l", Player);
    ExpectSubStringMatch("north.*building", Player->caughtMessage());
    ExpectSubStringMatch("south.*building", Player->caughtMessage());

    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void CanGenerateFiles()
{
    string originalDir = "/lib/generated_region/";
    mkdir(originalDir);

    string *files = get_dir(originalDir, 0x10);
    ExpectEq(({ }), files);

    Player->colorConfiguration("none");
    Player->charsetConfiguration("unicode");

    Region->setRegionName("a forest");
    Region->setRegionType("forest");

    Region->setDimensions(10, 10);
    Region->setSettlementChance(0);
    Region->createRegion("west", "/lib/tests/support/environment/startingRoom.c");

    Region->generateStaticFiles("/lib/generated_region");

    files = get_dir(originalDir, 0x10);
    ExpectEq(({ "lib/generated_region/a-forest--lib-tests-support-environment-startingRoom-c" }), 
        files);
    string dirToDelete = files[0];

    files = get_dir(files[0] + "/", 0x10);

    // This is one for each room file and one for the region
    ExpectEq(sizeof(Region->rooms()) + 1, sizeof(files));

    foreach(string file in files)
    {
        // First, verify that the generated file is loadable
        ExpectTrue(load_object(file));
        rm(file);
    }
    rmdir(dirToDelete);
    rmdir(originalDir);
}

/////////////////////////////////////////////////////////////////////////////
void CanEnterTemplatedRegion()
{
    ToggleCallOutBypass();
    Player->colorConfiguration("none");
    Player->charsetConfiguration("unicode");

    Region->setRegionName("a forest");
    Region->setRegionType("forest");
    Region->setDimensions(10, 10);

    Region->setSettlementChance(100);
    Region->createRegion();

    move_object(Player, Region->getSettlementEntrance());

    command("s", Player);
    ExpectNotEq(object_name(Region->getSettlementEntrance()),
        object_name(environment(Player)));

    command("n", Player);
    ExpectEq(object_name(Region->getSettlementEntrance()), 
        object_name(environment(Player)));

    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
/*void Y()
{
    ToggleCallOutBypass();

    object region = 
        load_object("/lib/tutorial/eledhel/central-city/central-city.c");

    ExpectEq("x", region->displayMap(Player));

    ToggleCallOutBypass();
}
*/
/////////////////////////////////////////////////////////////////////////////
/*void L()
{
    Region = clone_object("/lib/tutorial/eledhel/southwest-rural-one/region.c");

    string originalDir = "/lib/tutorial/eledhel/";
    mkdir(originalDir);

    Player->colorConfiguration("none");
    Player->charsetConfiguration("unicode");

    Region->setRegionName("southwest-rural-x");
    Region->setRegionType("rural");

    Region->setDimensions(25, 5);
    Region->setSettlementChance(100);
    Region->createRegion("east", "/lib/tutorial/eledhel/southwest-rural-one/0x2.c");

    Region->generateStaticFiles("/lib/tutorial/eledhel/");
    ExpectEq("x", Region->displayMap(Player));
}
*/
