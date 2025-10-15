//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    
    ExpectEq(7, Region.xDimension(), "Temple width is 7");
    ExpectEq(9, Region.yDimension(), "Temple height is 9");
}

/////////////////////////////////////////////////////////////////////////////
void KeepRegionHasCorrectDimensions()
{
    Region.setRegionName("test keep");
    Region.setRegionType("keep");
    Region.createRegion("north", "/some/location");
    
    ExpectEq(9, Region.xDimension(), "Keep width is 9");
    ExpectEq(11, Region.yDimension(), "Keep height is 11");
}

/////////////////////////////////////////////////////////////////////////////
void CryptRegionHasCorrectDimensions()
{
    Region.setRegionName("test crypt");
    Region.setRegionType("crypt");
    Region.createRegion("west", "/some/location");
    
    ExpectEq(5, Region.xDimension(), "Crypt width is 5");
    ExpectEq(7, Region.yDimension(), "Crypt height is 7");
}

/////////////////////////////////////////////////////////////////////////////
void RuinsRegionHasCorrectDimensions()
{
    Region.setRegionName("ancient ruins");
    Region.setRegionType("ruins");
    Region.createRegion("east", "/some/location");
    
    ExpectEq(6, Region.xDimension(), "Ruins width is 6");
    ExpectEq(8, Region.yDimension(), "Ruins height is 8");
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
    
    ExpectSubStringMatch("#", map, "Map shows walls");
}

/////////////////////////////////////////////////////////////////////////////
void TempleMapShowsRooms()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectSubStringMatch("o", map, "Map shows rooms");
}

/////////////////////////////////////////////////////////////////////////////
void TempleMapShowsEntry()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectSubStringMatch("E", map, "Map shows entry point");
}

/////////////////////////////////////////////////////////////////////////////
void KeepMapDisplaysCorrectly()
{
    Region.setRegionName("test keep");
    Region.setRegionType("keep");
    Region.createRegion("north", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectTrue(sizeof(map) > 0, "Map has content");
    ExpectSubStringMatch("#", map, "Map shows walls");
    ExpectSubStringMatch("o", map, "Map shows rooms");
}

/////////////////////////////////////////////////////////////////////////////
void CryptMapDisplaysCorrectly()
{
    Region.setRegionName("test crypt");
    Region.setRegionType("crypt");
    Region.createRegion("west", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectTrue(sizeof(map) > 0, "Map has content");
    ExpectSubStringMatch("#", map, "Map shows walls");
    ExpectSubStringMatch("o", map, "Map shows rooms");
}

/////////////////////////////////////////////////////////////////////////////
void RuinsMapDisplaysCorrectly()
{
    Region.setRegionName("ancient ruins");
    Region.setRegionType("ruins");
    Region.createRegion("east", "/some/location");
    
    string map = Region.displayMap(Player);
    
    ExpectTrue(sizeof(map) > 0, "Map has content");
    ExpectSubStringMatch("o", map, "Map shows rooms");
}

/////////////////////////////////////////////////////////////////////////////
void BuildingRegionHasCoordinateData()
{
    Region.setRegionName("test temple");
    Region.setRegionType("temple");
    Region.createRegion("south", "/some/location");
    
    int foundRooms = 0;
    int foundWalls = 0;
    int foundEntry = 0;
    
    for (int x = 0; x < Region.xDimension(); x++)
    {
        for (int y = 0; y < Region.yDimension(); y++)
        {
            mapping cell = Region.coordinateToMapping(x, y);
            if (mappingp(cell) && member(cell, "room type"))
            {
                if (cell["room type"] == "room") foundRooms = 1;
                if (cell["room type"] == "wall") foundWalls = 1;
                if (cell["room type"] == "entry") foundEntry = 1;
            }
        }
    }
    
    ExpectTrue(foundRooms, "Building has rooms");
    ExpectTrue(foundWalls, "Building has walls");
    ExpectTrue(foundEntry, "Building has entry");
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
    
    int foundThrone = 0;
    
    for (int x = 0; x < Region.xDimension(); x++)
    {
        for (int y = 0; y < Region.yDimension(); y++)
        {
            mapping cell = Region.coordinateToMapping(x, y);
            if (mappingp(cell) && member(cell, "room type"))
            {
                if (cell["room type"] == "throne") foundThrone = 1;
            }
        }
    }
    
    ExpectTrue(foundThrone, "Keep has throne room");
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
    ExpectEq("entry", data["room type"], "Entry room type is correct");
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
    
    ExpectNotEq(temple.xDimension(), crypt.xDimension(), 
        "Different building types have different dimensions");
    
    destruct(temple);
    destruct(crypt);
}
