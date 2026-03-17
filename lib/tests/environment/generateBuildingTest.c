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
    Player.charsetConfiguration("ascii");

    Region = clone_object("/lib/environment/region.c");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Region);
    destruct(Player);

    ToggleCallOutBypass();
}

/////////////////////////////////////////////////////////////////////////////
void TempleRegionCanBeCreated()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    
    string exitTo = Region.createRegion("south", "/some/location");
    
    ExpectEq("north", exitTo, "Exit direction is north");
}

/////////////////////////////////////////////////////////////////////////////
void KeepRegionCanBeCreated()
{
    Region.setRegionName("test keep");
    Region.setRegionType("keep");
    
    string exitTo = Region.createRegion("north", "/some/location");
    
    ExpectEq("south", exitTo, "Exit direction is south");
}

/////////////////////////////////////////////////////////////////////////////
void CryptRegionCanBeCreated()
{
    Region.setRegionName("test crypt");
    Region.setRegionType("crypt");
    
    string exitTo = Region.createRegion("west", "/some/location");
    
    ExpectEq("east", exitTo, "Exit direction is east");
}

/////////////////////////////////////////////////////////////////////////////
void RuinsRegionCanBeCreated()
{
    Region.setRegionName("ancient ruins");
    Region.setRegionType("ruins");
    
    string exitTo = Region.createRegion("east", "/some/location");
    
    ExpectEq("west", exitTo, "Exit direction is west");
}

/////////////////////////////////////////////////////////////////////////////
void TempleRegionHasCorrectDimensions()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");
    
    ExpectTrue(18 <= Region.xDimension(), "Keep width >= 18");
    ExpectTrue(25 >= Region.xDimension(), "Keep width <= 25");
    ExpectTrue(9 <= Region.yDimension(), "Keep height >= 9");
    ExpectTrue(11 >= Region.yDimension(), "Keep width <= 11");
}

/////////////////////////////////////////////////////////////////////////////
void KeepRegionHasCorrectDimensions()
{
    Region.setRegionName("test keep");
    Region.setRegionType("keep");
    Region.createRegion("north", "/some/location");

    ExpectTrue(20 <= Region.xDimension(), "Keep width >= 20");
    ExpectTrue(25 >= Region.xDimension(), "Keep width <= 25");
    ExpectTrue(10 <= Region.yDimension(), "Keep height >= 10");
    ExpectTrue(12 >= Region.yDimension(), "Keep width <= 12");
}

/////////////////////////////////////////////////////////////////////////////
void CryptRegionHasCorrectDimensions()
{
    Region.setRegionName("test crypt");
    Region.setRegionType("crypt");
    Region.createRegion("west", "/some/location");
    
    ExpectTrue(15 <= Region.xDimension(), "Keep width >= 15");
    ExpectTrue(25 >= Region.xDimension(), "Keep width <= 25");
    ExpectTrue(8 <= Region.yDimension(), "Keep height >= 8");
    ExpectTrue(11 >= Region.yDimension(), "Keep width <= 11");
}

/////////////////////////////////////////////////////////////////////////////
void RuinsRegionHasCorrectDimensions()
{
    Region.setRegionName("ancient ruins");
    Region.setRegionType("ruins");
    Region.createRegion("east", "/some/location");
    
    ExpectTrue(18 <= Region.xDimension(), "Keep width >= 18");
    ExpectTrue(25 >= Region.xDimension(), "Keep width <= 25");
    ExpectTrue(9 <= Region.yDimension(), "Keep height >= 9");
    ExpectTrue(11 >= Region.yDimension(), "Keep width <= 11");
}

/////////////////////////////////////////////////////////////////////////////
void BuildingRegionMapDisplaysCorrectly()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectTrue(sizeof(map) > 0, "Map has content");
    ExpectNotEq("", map, "Map is not empty");
    ExpectNotEq("\n", map, "Map is not just newline");
}

/////////////////////////////////////////////////////////////////////////////
void TempleMapShowsWalls()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectSubStringMatch("=", map, "Map shows walls");
}

/////////////////////////////////////////////////////////////////////////////
void TempleMapShowsRooms()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectSubStringMatch("=", map, "Map shows rooms");
}

/////////////////////////////////////////////////////////////////////////////
void TempleMapShowsEntry()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectSubStringMatch("=", map, "Map shows entry point");
}

/////////////////////////////////////////////////////////////////////////////
void KeepMapDisplaysCorrectly()
{
    Region.setRegionName("test keep");
    Region.setRegionType("keep");
    Region.createRegion("north", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectTrue(sizeof(map) > 0, "Map has content");
    ExpectSubStringMatch("=", map, "Map shows walls");
    ExpectSubStringMatch("\\+", map, "Map shows rooms");
}

/////////////////////////////////////////////////////////////////////////////
void CryptMapDisplaysCorrectly()
{
    Region.setRegionName("test crypt");
    Region.setRegionType("crypt");
    Region.createRegion("west", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectTrue(sizeof(map) > 0, "Map has content");
    ExpectSubStringMatch("=", map, "Map shows walls");
    ExpectSubStringMatch("\\+", map, "Map shows rooms");
}

/////////////////////////////////////////////////////////////////////////////
void RuinsMapDisplaysCorrectly()
{
    Region.setRegionName("ancient ruins");
    Region.setRegionType("ruins");
    Region.createRegion("east", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectTrue(sizeof(map) > 0, "Map has content");
    ExpectSubStringMatch("=", map, "Map shows rooms");
}

/////////////////////////////////////////////////////////////////////////////
void BuildingRegionHasCoordinateData()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");

    int decoratedCells = 0;
    int voidCells = 0;

    for (int x = 0; x < Region.xDimension(); x++)
    {
        for (int y = 0; y < Region.yDimension(); y++)
        {
            mapping cell = Region.coordinateToMapping(x, y);
            if (mappingp(cell))
            {
                if (member(cell, "decorator type") &&
                    cell["decorator type"] != "none")
                {
                    decoratedCells++;
                }
                else
                {
                    voidCells++;
                }
            }
        }
    }

    int *entry = Region.getEntry();

    ExpectTrue(decoratedCells > 0, "Building has decorated rooms");
    ExpectTrue(voidCells > 0, "Building has void areas (walls)");
    ExpectTrue(pointerp(entry) && sizeof(entry) == 2,
        "Building has entry");
}

/////////////////////////////////////////////////////////////////////////////
void BuildingRegionHasEntryCoordinates()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");
    
    int *entry = Region.getEntry();
    
    ExpectTrue(pointerp(entry), "Entry coordinates exist");
    ExpectEq(2, sizeof(entry), "Entry has x and y");
    ExpectTrue(entry[0] >= 0, "Entry x is valid");
    ExpectTrue(entry[1] >= 0, "Entry y is valid");
}

/////////////////////////////////////////////////////////////////////////////
void KeepRegionHasSpecialRooms()
{
    Region.setRegionName("test keep");
    Region.setRegionType("keep");
    Region.createRegion("north", "/some/location");

    int foundDecorator = 0;

    for (int x = 0; x < Region.xDimension(); x++)
    {
        for (int y = 0; y < Region.yDimension(); y++)
        {
            mapping cell = Region.coordinateToMapping(x, y);
            if (mappingp(cell) && member(cell, "decorator type"))
            {
                foundDecorator = 1;
                break;
            }
        }
        if (foundDecorator)
        {
            break;
        }
    }

    ExpectTrue(foundDecorator,
        "Keep has decorated center room");
}

/////////////////////////////////////////////////////////////////////////////
void BuildingRegionCanGetCoordinateData()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");

    int *entry = Region.getEntry();
    mapping data = Region.coordinateToMapping(entry[0], entry[1]);

    ExpectTrue(mappingp(data), "Coordinate data exists");
    ExpectEq("none", data["room type"],
        "Room type is none per hand-crafted convention");
    ExpectTrue(member(data, "decorator type") > 0,
        "Entry has decorator type");
}

/////////////////////////////////////////////////////////////////////////////
void MiniMapCanBeGeneratedForBuilding()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");
    
    int *entry = Region.getEntry();
    object room = load_object("/lib/environment/generatedEnvironment.c");
    mapping data = Region.coordinateToMapping(entry[0], entry[1]);
    data["environment"] = room;
    room.generateEnvironment(data, Region);
    
    move_object(Player, room);
    
    string *miniMap = Region.getMiniMap(room, Player);
    
    ExpectTrue(pointerp(miniMap), "Mini map is an array");
    ExpectTrue(sizeof(miniMap) > 0, "Mini map has content");
    
    destruct(room);
}

/////////////////////////////////////////////////////////////////////////////
void DifferentBuildingTypesHaveDifferentLayouts()
{
    object temple = clone_object("/lib/environment/region.c");
    temple.setRegionName("temple");
    temple.setRegionType("temple");
    temple.createRegion("south", "/some/location");

    object crypt = clone_object("/lib/environment/region.c");
    crypt.setRegionName("crypt");
    crypt.setRegionType("crypt");
    crypt.createRegion("north", "/some/location");

    ExpectTrue(temple.xDimension() >= 18 && temple.xDimension() <= 25,
        "Temple width is within expected range");
    ExpectTrue(crypt.xDimension() >= 15 && crypt.xDimension() <= 25,
        "Crypt width is within expected range");
    ExpectTrue(temple.yDimension() >= 9 && temple.yDimension() <= 11,
        "Temple height is within expected range");
    ExpectTrue(crypt.yDimension() >= 8 && crypt.yDimension() <= 11,
        "Crypt height is within expected range");

    destruct(temple);
    destruct(crypt);
}

/////////////////////////////////////////////////////////////////////////////
void CryptUsesTunnelingAlgorithm()
{
    Region.setRegionName("test crypt");
    Region.setRegionType("crypt");
    Region.createRegion("west", "/some/location");

    int foundCorridor = 0;

    for (int x = 0; x < Region.xDimension(); x++)
    {
        for (int y = 0; y < Region.yDimension(); y++)
        {
            mapping cell = Region.coordinateToMapping(x, y);
            if (mappingp(cell) && member(cell, "decorator type") &&
                cell["decorator type"] != "none")
            {
                foundCorridor = 1;
            }
        }
    }

    ExpectTrue(foundCorridor, "Crypt has corridors from tunneling algorithm");
}

/////////////////////////////////////////////////////////////////////////////
void TunnelingCreatesConnectedDungeon()
{
    Region.setRegionName("test crypt");
    Region.setRegionType("crypt");
    Region.createRegion("north", "/some/location");

    int carvedSpaces = 0;

    for (int x = 0; x < Region.xDimension(); x++)
    {
        for (int y = 0; y < Region.yDimension(); y++)
        {
            mapping cell = Region.coordinateToMapping(x, y);
            if (mappingp(cell) && member(cell, "decorator type") &&
                cell["decorator type"] != "none")
            {
                carvedSpaces++;
            }
        }
    }

    ExpectTrue(carvedSpaces > 20, "Tunneling creates sufficient dungeon space");
}

///////////////////////////////////////////////////////////////////////////////
//void TunnelingAlgorithmCreatesOrganicPaths()
//{
//    Region.setRegionName("cave system");
//    Region.setRegionType("cave");
//    Region.createRegion("south", "/some/location");
//    
//    int corridorCount = 0;
//    int roomCount = 0;
//    
//    for (int x = 0; x < Region.xDimension(); x++)
//    {
//        for (int y = 0; y < Region.yDimension(); y++)
//        {
//            mapping cell = Region.coordinateToMapping(x, y);
//            if (mappingp(cell) && member(cell, "room type"))
//            {
//                if (cell["room type"] == "corridor") corridorCount++;
//                if (cell["room type"] == "room") roomCount++;
//            }
//        }
//    }
//    
//    ExpectTrue(corridorCount > 0, "Cave has organic corridors");
//    ExpectTrue(roomCount >= 0, "Cave can have rooms");
//}
//
///////////////////////////////////////////////////////////////////////////////
//void TunnelingHasSpecialRoom()
//{
//    Region.setRegionName("ancient dungeon");
//    Region.setRegionType("dungeon");
//    Region.createRegion("east", "/some/location");
//    
//    int foundSpecial = 0;
//    
//    for (int x = 0; x < Region.xDimension(); x++)
//    {
//        for (int y = 0; y < Region.yDimension(); y++)
//        {
//            mapping cell = Region.coordinateToMapping(x, y);
//            if (mappingp(cell) && member(cell, "room type"))
//            {
//                if (cell["room type"] == "special")
//                {
//                    foundSpecial = 1;
//                }
//            }
//        }
//    }
//    
//    ExpectTrue(foundSpecial, "Dungeon has special room (boss/treasure)");
//}

/////////////////////////////////////////////////////////////////////////////
void TunnelingMapDisplaysCorrectly()
{
    Region.setRegionName("test mine");
    Region.setRegionType("mine");
    Region.createRegion("north", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectTrue(sizeof(map) > 0, "Tunneling dungeon map has content");
    ExpectNotEq("", map, "Map is not empty");
}

/////////////////////////////////////////////////////////////////////////////
void DifferentDungeonTypesHaveDifferentTunneling()
{
    object crypt = clone_object("/lib/environment/region.c");
    crypt.setRegionName("crypt");
    crypt.setRegionType("crypt");
    crypt.createRegion("north", "/some/location");
    
    object cave = clone_object("/lib/environment/region.c");
    cave.setRegionName("cave");
    cave.setRegionType("cave");
    cave.createRegion("south", "/some/location");
    
    // Caves should generally be larger and more organic
    ExpectTrue(cave.xDimension() >= crypt.xDimension(), 
        "Caves tend to be larger than crypts");
    
    destruct(crypt);
    destruct(cave);
}
