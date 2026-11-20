//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/areas/minlach/investigation-room.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/city.c");
    addDecorator("village garden");
    setShortDescription("Edda's walled drying garden");
    addFeature("/lib/environment/features/water/silted-sluice.c", "east");
    addItem("/lib/environment/items/objects/clothesline.c", "north");
    addItem("/lib/environment/items/objects/flower-box.c", "west");
    addItem("/lib/environment/items/military/small-barricade.c", "west");
    addObject("/areas/minlach/characters/edda/edda.c");
    addClue("garden water", "roots-by-the-stream", "inspectGardenWater",
        "Fine stone silt settles in the sluice pan. The water "
        "comes down from the quarry's settling ditch.");
    addExitWithDoor("west", "/areas/minlach/2x3.c",
        "/lib/environment/doors/plank-door.c");
    addExitWithDoor("south", "/areas/minlach/3x2.c",
        "/lib/environment/doors/plank-door.c");
    addBuildingWithDoor("/lib/environment/buildings/shops/apothecary.c",
        "north", "/areas/minlach/3x4.c",
        "/lib/environment/doors/plank-door.c");
}
