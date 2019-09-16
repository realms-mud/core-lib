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
    Player->colorConfiguration("3-bit");
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

    Region->setDimensions(10, 5);
    ExpectEq("north", Region->createRegion("south"));
    ExpectEq("west", Region->createRegion("east"));
}

/////////////////////////////////////////////////////////////////////////////
void CanCreateWithSpecificEntryPoint()
{
    Region->setRegionName("a forest");
    Region->setRegionType("forest");

    Region->setDimensions(10, 5);
    Region->createRegion("south", 0, ({ 3, 0}));

    ExpectEq(({ 3, 0 }), Region->EntryLocation());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectNumberOfRoomsGenerated()
{
    Region->setRegionName("a forest");
    Region->setRegionType("forest");

    Region->setDimensions(15, 5);
    Region->createRegion();

    ExpectEq(7, Region->generatedRoomCount());
}

/////////////////////////////////////////////////////////////////////////////
void AllGeneratedRoomsHaveExits()
{
    Region->setRegionName("a forest");
    Region->setRegionType("forest");

    Region->setDimensions(10, 5);
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

    object region = environment->addGeneratedRegion("north", "forest", 15, 10);

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
void CanRestoreRegion()
{
/*    object environment =
        load_object("/lib/tests/support/environment/startingRoom.c");

    object region = environment->addGeneratedRegion("north", "forest", 15, 10);
    region->save();
    */
}
