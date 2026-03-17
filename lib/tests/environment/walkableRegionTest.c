//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

object Region;
object Player;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    getService("environment");
    ToggleCallOutBypass();

    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("grayscale");
    Player.charsetConfiguration("unicode");

    Region = clone_object("/lib/environment/walkableRegion.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Region);
    destruct(Player);

    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void CanCreateWalkableRegion()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);

    string exitTo = Region.initialize("south", "/some/location", 12, 0);

    ExpectEq("north", exitTo, "Exit direction is north");
}

/////////////////////////////////////////////////////////////////////////////
void RegionHasCorrectDimensions()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.initialize("south", "/some/location", 12, 0);

    ExpectEq(25, Region.xDimension(), "Width is 25");
    ExpectEq(10, Region.yDimension(), "Height is 10");
}

/////////////////////////////////////////////////////////////////////////////
void InitializeGeneratesCellsAroundEntry()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.setExpansionRadius(4);
    Region.initialize("south", "/some/location", 12, 0);

    ExpectTrue(Region.isCellGenerated(12, 0),
        "Entry cell is generated");
    ExpectTrue(Region.isCellGenerated(12, 1),
        "Cell north of entry is generated");
    ExpectTrue(Region.isCellGenerated(12, 4),
        "Cell 4 north of entry is generated");
    ExpectTrue(Region.isCellGenerated(10, 2),
        "Cell 2 west and 2 north is generated");
    ExpectFalse(Region.isCellGenerated(0, 0),
        "Distant cell is not generated");
}

/////////////////////////////////////////////////////////////////////////////
void EntryCoordinatesAreCorrect()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.initialize("south", "/some/location", 12, 0);

    int *entry = Region.getEntry();

    ExpectTrue(pointerp(entry), "Entry coordinates exist");
    ExpectEq(12, entry[0], "Entry x is 12");
    ExpectEq(0, entry[1], "Entry y is 0");
}

/////////////////////////////////////////////////////////////////////////////
void GetEnvironmentReturnsRoomForGeneratedCell()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.initialize("south", "/some/location", 12, 0);

    object room = Region.getEnvironment("12x0");

    ExpectTrue(objectp(room), "Entry room exists");
}

/////////////////////////////////////////////////////////////////////////////
void GetEnvironmentExpandsGridOnAccess()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.setExpansionRadius(2);
    Region.initialize("south", "/some/location", 12, 0);

    ExpectFalse(Region.isCellGenerated(20, 5),
        "Distant cell not yet generated");

    object room = Region.getEnvironment("20x5");

    ExpectTrue(objectp(room), "Room was generated on access");
    ExpectTrue(Region.isCellGenerated(20, 5),
        "Cell is now generated");
    ExpectTrue(Region.isCellGenerated(20, 6),
        "Neighbor cell also generated");
}

/////////////////////////////////////////////////////////////////////////////
void GetEnvironmentReturnsNullForOutOfBounds()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.initialize("south", "/some/location", 12, 0);

    object room = Region.getEnvironment("25x10");

    ExpectFalse(objectp(room), "Out of bounds returns null");
}

/////////////////////////////////////////////////////////////////////////////
void GeneratedCellHasExitsToNeighbors()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.initialize("south", "/some/location", 12, 2);

    mapping cell = Region.coordinateToMapping(12, 2);

    ExpectTrue(mappingp(cell), "Cell data exists");
    ExpectTrue(member(cell["exits"], "north") > 0,
        "Has north exit");
    ExpectTrue(member(cell["exits"], "south") > 0,
        "Has south exit");
    ExpectTrue(member(cell["exits"], "east") > 0,
        "Has east exit");
    ExpectTrue(member(cell["exits"], "west") > 0,
        "Has west exit");
}

/////////////////////////////////////////////////////////////////////////////
void EdgeCellHasLimitedExits()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.initialize("south", "/some/location", 0, 0);

    mapping cell = Region.coordinateToMapping(0, 0);

    ExpectTrue(mappingp(cell), "Cell data exists");
    ExpectTrue(member(cell["exits"], "north") > 0,
        "Has north exit");
    ExpectTrue(member(cell["exits"], "east") > 0,
        "Has east exit");
    ExpectFalse(member(cell["exits"], "south"),
        "No south exit at bottom edge");
    ExpectFalse(member(cell["exits"], "west"),
        "No west exit at left edge");
}

/////////////////////////////////////////////////////////////////////////////
void CanLinkNeighborRegions()
{
    object neighbor = clone_object("/lib/environment/walkableRegion.c");
    neighbor.setRegionName("east forest");
    neighbor.setRegionType("forest");
    neighbor.setDimensions(25, 10);

    Region.setRegionName("west forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.initialize("south", "/some/location", 12, 0);

    Region.linkNeighborRegions(neighbor, "east");

    ExpectEq(neighbor, Region.getNeighborRegion("east"),
        "East neighbor is set");
    ExpectEq(Region, neighbor.getNeighborRegion("west"),
        "West neighbor back-reference is set");

    destruct(neighbor);
}

/////////////////////////////////////////////////////////////////////////////
void MiniMapCanBeGenerated()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.initialize("south", "/some/location", 12, 0);

    object room = Region.getEnvironment("12x0");
    move_object(Player, room);

    string *miniMap = Region.getMiniMap(room, Player);

    ExpectTrue(pointerp(miniMap), "Mini map is an array");
    ExpectTrue(sizeof(miniMap) > 0, "Mini map has content");
}

/////////////////////////////////////////////////////////////////////////////
void DisplayMapShowsGeneratedArea()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.setExpansionRadius(4);
    Region.initialize("south", "/some/location", 12, 0);

    string map = Region.displayMap(Player);

    ExpectTrue(sizeof(map) > 0, "Map has content");
    ExpectNotEq("", map, "Map is not empty");
}

/////////////////////////////////////////////////////////////////////////////
void SettlementChanceCanBeSet()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");

    Region.setSettlementChance(50);

    ExpectEq(50, Region.settlementChance(),
        "Settlement chance is 50");
}

/////////////////////////////////////////////////////////////////////////////
void SettlementChanceDefaultsToNegativeOne()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");

    ExpectEq(-1, Region.settlementChance(),
        "Default settlement chance is -1");
}

/////////////////////////////////////////////////////////////////////////////
void HasSettlementReturnsFalseBeforeInitialization()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");

    ExpectFalse(Region.hasSettlement(),
        "No settlement before initialization");
}

/////////////////////////////////////////////////////////////////////////////
void SettlementOriginIsNullWithoutSettlement()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.setSettlementChance(0);
    Region.initialize("south", "/some/location", 12, 0);

    ExpectFalse(Region.hasSettlement(),
        "No settlement with 0% chance");
    ExpectFalse(Region.settlementOrigin(),
        "Settlement origin is null");
}

/////////////////////////////////////////////////////////////////////////////
void SettlementCanBeForcedWithFullChance()
{
    Region.setRegionName("test forest");
    Region.setRegionType("forest");
    Region.setDimensions(25, 10);
    Region.setSettlementChance(100);
    Region.initialize("south", "/some/location", 12, 0);

    ExpectTrue(Region.hasSettlement(),
        "Settlement exists with 100% chance");

    int *origin = Region.settlementOrigin();
    ExpectTrue(pointerp(origin), "Settlement origin exists");
    ExpectEq(2, sizeof(origin), "Origin has x and y");
}
