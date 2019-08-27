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
void SendingEntryCreatesMapWithCorrectEntryPoint()
{
    Region->setDimensions(10, 5);
    ExpectEq("north", Region->createArea("dungeon", "south"));
    ExpectEq("west", Region->createArea("dungeon", "east"));
}

/////////////////////////////////////////////////////////////////////////////
void CanCreateWithSpecificEntryPoint()
{
    Region->setDimensions(10, 5);
    Region->createArea("forest", "south", ({ 3, 0}));

    ExpectEq(({ 3, 0 }), Region->EntryLocation());
}

/////////////////////////////////////////////////////////////////////////////
void CorrectNumberOfRoomsGenerated()
{
    Region->setDimensions(15, 5);
    Region->createArea();

    ExpectEq(7, Region->generatedRoomCount());
}

/////////////////////////////////////////////////////////////////////////////
void AllGeneratedRoomsHaveExits()
{
    Region->setDimensions(10, 5);
    Region->createArea();

    foreach(mapping room in Region->rooms())
    {
        ExpectTrue(sizeof(room["exits"]));
    }
}
