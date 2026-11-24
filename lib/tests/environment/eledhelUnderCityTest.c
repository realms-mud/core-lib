//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
#include <functionlist.h>
inherit "/lib/tests/framework/testFixture.c";

object Player;
object *Harvested = ({});

/////////////////////////////////////////////////////////////////////////////
void Init()
{
}

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Player = clone_object("/lib/tests/support/services/mockPlayer.c");
    Player.Name("bob");
    Player.addCommands();
    Player.colorConfiguration("none");
    Harvested = ({});
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    foreach (object item in Harvested)
    {
        if (objectp(item))
        {
            destruct(item);
        }
    }
    if (objectp(Player))
    {
        destruct(Player);
    }
}

/////////////////////////////////////////////////////////////////////////////
void SendralCanGrantEscapeQuest()
{
    string questPath = "/areas/eledhel/under-city/escapeQuest.c";
    object room = clone_object(
        "/areas/eledhel/central-city/palace/2x3.c");
    object resident = clone_object(
        "/areas/eledhel/central-city/palace/characters/sendral.c");
    object events = load_object(
        "/areas/eledhel/central-city/palace/characters/sendralEvents.c");
    Harvested += ({ room, resident });
    move_object(Player, room);
    move_object(resident, room);

    ExpectTrue(resident->hasTopic("escape route") > -1);
    ExpectTrue(events->receiveEvent(resident, "beginEledhelEscape", Player));
    ExpectEq("escape begun", Player->questState(questPath));
    ExpectTrue(events->receiveEvent(resident, "beginEledhelEscape", Player));
    ExpectEq("escape begun", Player->questState(questPath));
}

/////////////////////////////////////////////////////////////////////////////
void UnderCityRoomsAreQuestGated()
{
    string questPath = "/areas/eledhel/under-city/escapeQuest.c";
    object palace = clone_object(
        "/areas/eledhel/central-city/palace/2x3.c");
    object passage = clone_object(
        "/areas/eledhel/central-city/palace/hidden-passage.c");
    Harvested += ({ palace, passage });

    ExpectFalse(passage->moveFromIsAllowed(Player, palace));
    ExpectTrue(Player->beginQuest(questPath));
    ExpectTrue(passage->moveFromIsAllowed(Player, palace));
    ExpectEq("under city", Player->questState(questPath));
}

/////////////////////////////////////////////////////////////////////////////
void JusticeMustBeReachedBeforeTheFoxDen()
{
    string questPath = "/areas/eledhel/under-city/escapeQuest.c";
    object palace = clone_object(
        "/areas/eledhel/central-city/palace/2x3.c");
    object passage = clone_object(
        "/areas/eledhel/central-city/palace/hidden-passage.c");
    object hall = load_object(
        "/areas/eledhel/southern-city/halls-of-justice/0x0.c");
    object justice = clone_object(
        "/areas/eledhel/under-city/justice-branch/20x2.c");
    object foxMouth = clone_object(
        "/areas/eledhel/under-city/natural-caverns/4x5.c");
    object mechanism = clone_object(
        "/areas/eledhel/under-city/justice-mechanism/20x7.c");
    Harvested += ({ palace, passage, justice, foxMouth, mechanism });

    ExpectTrue(mechanism->isEnvironmentalElement("sighting tube"));
    ExpectTrue(mechanism->isEnvironmentalElement("lever"));
    ExpectTrue(mechanism->isEnvironmentalElement("counterweight assembly"));
    ExpectTrue(hall->isEnvironmentalElement("battle mural"));

    Player->beginQuest(questPath);
    passage->moveFromIsAllowed(Player, palace);
    ExpectTrue(foxMouth->moveFromIsAllowed(Player, justice));
    ExpectEq("under city", Player->questState(questPath));
    ExpectFalse(hall->moveToIsAllowed(Player, justice));

    move_object(Player, mechanism);
    ExpectFalse(mechanism->moveToIsAllowed(Player, justice));
    command("pull lever", Player);
    ExpectTrue(mechanism->moveToIsAllowed(Player, justice));
    ExpectTrue(justice->moveFromIsAllowed(Player, palace));
    ExpectEq("justice reached", Player->questState(questPath));
    ExpectTrue(hall->moveToIsAllowed(Player, justice));
    ExpectTrue(foxMouth->moveFromIsAllowed(Player, justice));
    ExpectEq("escaped", Player->questState(questPath));
}

/////////////////////////////////////////////////////////////////////////////
void PhaedraMapPuzzleOpensTheUnderCityDoor()
{
    string questPath = "/areas/eledhel/under-city/escapeQuest.c";
    object library = clone_object(
        "/areas/eledhel/northern-city/phaedra-headquarters/1x2.c");
    object passage = clone_object(
        "/areas/eledhel/under-city/phaedra-branch/2x3.c");
    object mechanism = load_object(
        "/areas/eledhel/under-city/phaedra-mechanism/2x2.c");
    object otherPlayer = clone_object(
        "/lib/tests/support/services/mockPlayer.c");
    otherPlayer.Name("jane");
    Harvested += ({ library, passage, otherPlayer });

    ExpectTrue(library->isEnvironmentalElement("war map"));
    ExpectTrue(library->isEnvironmentalElement("book shelf"));
    ExpectTrue(mechanism->isEnvironmentalElement("counterweight machine"));
    ExpectTrue(mechanism->isEnvironmentalElement("cotter pin"));

    move_object(Player, library);
    ExpectFalse(library->moveToIsAllowed(Player, passage));
    Player->beginQuest(questPath);
    command("turn Eledhel 90 clockwise", Player);
    ExpectFalse(library->moveToIsAllowed(Player, passage));

    command("turn Serach 45 counterclockwise", Player);
    command("turn Eledhel 90 clockwise", Player);
    command("turn Serach 135 clockwise", Player);
    command("turn Ethyl Tirath 180 counterclockwise", Player);
    command("turn Hillgarath 360 clockwise", Player);
    command("turn Eledhel 180 counterclockwise", Player);
    command("press Eledhel", Player);
    ExpectTrue(library->moveToIsAllowed(Player, passage));
    otherPlayer->beginQuest(questPath);
    ExpectFalse(library->moveToIsAllowed(otherPlayer, passage));

    move_object(Player, passage);
    command("pull lever", Player);
    ExpectFalse(library->moveToIsAllowed(Player, passage));
}

/////////////////////////////////////////////////////////////////////////////
void StalagmiteMustBeMovedToEnterTheNaturalCavern()
{
    object stoneDoor = clone_object(
        "/areas/eledhel/under-city/fox-route/0x1.c");
    object cave = clone_object(
        "/areas/eledhel/under-city/natural-caverns/0x0.c");
    Harvested += ({ stoneDoor, cave });

    move_object(Player, stoneDoor);
    ExpectFalse(stoneDoor->moveToIsAllowed(Player, cave));
    command("push stalagmite", Player);
    ExpectTrue(stoneDoor->moveToIsAllowed(Player, cave));
}

/////////////////////////////////////////////////////////////////////////////
void UnderCityRoomsRemainShared()
{
    object *regions = ({
        load_object("/areas/eledhel/under-city/region.c"),
        load_object("/areas/eledhel/under-city/fox-route/region.c"),
        load_object("/areas/eledhel/under-city/natural-caverns/region.c")
    });

    foreach (object region in regions)
    {
        Harvested += ({ region });
        for (int x = 0; x < region->xDimension(); x++)
        {
            for (int y = 0; y < region->yDimension(); y++)
            {
                mapping cell = region->coordinateToMapping(x, y);
                if (mappingp(cell) && cell["is placed"])
                {
                    object room = cell["environment"];
                    room->enterEnvironment(Player);
                    ExpectEq(0, room->cloneOwner());
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void DrainageGratesProvideOnlyFaintDaylight()
{
    object timeService = getService("environment");
    object grateRoom = clone_object(
        "/areas/eledhel/under-city/northern-city/5x6.c");
    Harvested += ({ grateRoom });
    grateRoom->enterEnvironment(Player);

    timeService.setYear(1);
    timeService.setDay(92);
    timeService.timeOfDay("noon");
    object grate = load_object(
        "/areas/eledhel/under-city/items/drainage-grate.c");
    ExpectEq(2, grate->isSourceOfLight("default", grateRoom));
    ExpectEq(2, grateRoom->isIlluminated());

    timeService.timeOfDay("night");
    ExpectEq(0, grateRoom->isIlluminated());
    timeService.timeOfDay("noon");
}

/////////////////////////////////////////////////////////////////////////////
void PrisonRouteJoinsTheSecretWays()
{
    object prisonEgress = load_object(
        "/areas/eledhel/northern-city/prison/0x2.c");
    object park = load_object("/areas/eledhel/northern-city/5x7.c");
    object approach = load_object("/areas/eledhel/northern-city/5x6.c");
    object phaedraEntry = load_object(
        "/areas/eledhel/northern-city/phaedra-headquarters/2x4.c");
    object memorialHall = load_object(
        "/areas/eledhel/northern-city/phaedra-headquarters/2x3.c");
    object pillaredChamber = load_object(
        "/areas/eledhel/northern-city/phaedra-headquarters/2x2.c");
    object library = load_object(
        "/areas/eledhel/northern-city/phaedra-headquarters/1x2.c");
    object underCity = load_object(
        "/areas/eledhel/under-city/phaedra-branch/2x3.c");
    object climb = load_object(
        "/areas/eledhel/under-city/natural-caverns/7x4.c");

    ExpectEq("/areas/eledhel/northern-city/5x7.c",
        prisonEgress->getExitDirections()["default"]["east"]);
    ExpectEq("/areas/eledhel/northern-city/5x6.c",
        park->getExitDirections()["default"]["south"]);
    ExpectEq(
        "/areas/eledhel/northern-city/phaedra-headquarters/2x4.c",
        approach->getExitDirections()["default"]["south"]);
    ExpectEq(
        "/areas/eledhel/northern-city/phaedra-headquarters/2x3.c",
        phaedraEntry->getExitDirections()["default"]["south"]);
    ExpectEq(
        "/areas/eledhel/northern-city/phaedra-headquarters/2x2.c",
        memorialHall->getExitDirections()["default"]["south"]);
    ExpectEq(
        "/areas/eledhel/northern-city/phaedra-headquarters/1x2.c",
        pillaredChamber->getExitDirections()["default"]["west"]);
    ExpectEq("/areas/eledhel/under-city/phaedra-branch/2x3.c",
        library->getExitDirections()["default"]["down"]);
    ExpectEq(
        "/areas/eledhel/northern-city/phaedra-headquarters/1x2.c",
        underCity->getExitDirections()["default"]["up"]);

    ExpectTrue(load_object(
        "/areas/eledhel/northern-city/phaedra-headquarters/2x4.c")->
            isEnvironmentalElement("lion statues"));
    ExpectTrue(memorialHall->isEnvironmentalElement(
        "statues of former commanders"));
    ExpectTrue(climb->isEnvironmentalElement("two climbing ropes"));
}

/////////////////////////////////////////////////////////////////////////////
void PhaedraHeadquartersCanHaveStormKnightPatrols()
{
    object chamber = load_object(
        "/areas/eledhel/northern-city/phaedra-headquarters/2x2.c");
    chamber->enterEnvironment(Player);

    object patrol = present("knight of the storm", chamber);
    ExpectTrue(objectp(patrol));
    if (objectp(patrol))
    {
        destruct(patrol);
    }
}

/////////////////////////////////////////////////////////////////////////////
void PhaedraFloorTileOpensAHiddenDispatchRoom()
{
    object hall = load_object(
        "/areas/eledhel/northern-city/phaedra-headquarters/2x3.c");
    object hiddenRoom = load_object(
        "/areas/eledhel/northern-city/phaedra-headquarters/1x3.c");
    object region = load_object(
        "/areas/eledhel/northern-city/phaedra-headquarters/region.c");
    object otherPlayer = clone_object(
        "/lib/tests/support/services/mockPlayer.c");
    otherPlayer.Name("jane");
    Harvested += ({ otherPlayer });

    mapping hiddenCell = region->coordinateToMapping(1, 3);
    ExpectEq(
        "/areas/eledhel/northern-city/phaedra-headquarters/1x3.c",
        hiddenCell["name"]);
    move_object(Player, hall);
    ExpectFalse(hall->moveToIsAllowed(Player, hiddenRoom));
    command("press floor tile", Player);
    ExpectTrue(hall->moveToIsAllowed(Player, hiddenRoom));
    ExpectFalse(hall->moveToIsAllowed(otherPlayer, hiddenRoom));

    ExpectTrue(hiddenRoom->isEnvironmentalElement("field dispatches"));
    ExpectTrue(hiddenRoom->isEnvironmentalElement("book shelf"));

    object patrol = present("knight of the storm", hall);
    if (objectp(patrol))
    {
        destruct(patrol);
    }
}

/////////////////////////////////////////////////////////////////////////////
void UnderCityRegionHasAConnectedSpine()
{
    object central = load_object("/areas/eledhel/under-city/region.c");
    object northern = load_object(
        "/areas/eledhel/under-city/northern-city/region.c");
    object southern = load_object(
        "/areas/eledhel/under-city/southern-city/region.c");
    object *regions = ({ central, northern, southern });
    int *expectedCounts = ({ 34, 34, 33 });
    int index = 0;
    Harvested += regions;

    foreach (object region in regions)
    {
        int placedRooms = 0;
        ExpectEq(25, region->xDimension());
        ExpectEq(10, region->yDimension());

        for (int x = 0; x < region->xDimension(); x++)
        {
            for (int y = 0; y < region->yDimension(); y++)
            {
                mapping cell = region->coordinateToMapping(x, y);
                if (mappingp(cell) && cell["is placed"])
                {
                    placedRooms++;
                }
            }
        }
        ExpectEq(expectedCounts[index], placedRooms);
        index++;
    }

    mapping centralEntry = central->coordinateToMapping(14, 5);
    ExpectEq("/areas/eledhel/under-city/central-city/14x5.c",
        centralEntry["name"]);
    mapping aegisEntry = central->coordinateToMapping(11, 4);
    ExpectEq("/areas/eledhel/under-city/aegis-branch/11x4.c",
        aegisEntry["name"]);
    mapping northernMuseum = northern->coordinateToMapping(17, 8);
    ExpectEq("/areas/eledhel/under-city/museum-branch/17x8.c",
        northernMuseum["name"]);
    mapping southernJustice = southern->coordinateToMapping(20, 7);
    ExpectEq("/areas/eledhel/under-city/justice-mechanism/20x7.c",
        southernJustice["name"]);

    mapping grateCell = northern->coordinateToMapping(5, 6);
    object grateRoom = grateCell["environment"];
    ExpectTrue(grateRoom->isEnvironmentalElement("drainage grate"));
    ExpectTrue(grateRoom->isEnvironmentalElement("street grate"));
    object stationRoom = southern->coordinateToMapping(12, 2)["environment"];
    ExpectTrue(stationRoom->isEnvironmentalElement("cistern hand pump"));
    ExpectTrue(stationRoom->isEnvironmentalElement("torch bin"));

    object foxRegion = load_object(
        "/areas/eledhel/under-city/fox-route/region.c");
    object caveRegion = load_object(
        "/areas/eledhel/under-city/natural-caverns/region.c");
    Harvested += ({ foxRegion, caveRegion });
    ExpectEq(9, foxRegion->xDimension());
    ExpectEq(10, foxRegion->yDimension());
    ExpectEq(8, caveRegion->xDimension());
    ExpectEq(6, caveRegion->yDimension());

    int foxRooms = 0;
    for (int x = 0; x < foxRegion->xDimension(); x++)
    {
        for (int y = 0; y < foxRegion->yDimension(); y++)
        {
            mapping cell = foxRegion->coordinateToMapping(x, y);
            if (mappingp(cell) && cell["is placed"])
            {
                foxRooms++;
            }
        }
    }
    ExpectEq(26, foxRooms);

    int caveRooms = 0;
    for (int x = 0; x < caveRegion->xDimension(); x++)
    {
        for (int y = 0; y < caveRegion->yDimension(); y++)
        {
            mapping cell = caveRegion->coordinateToMapping(x, y);
            if (mappingp(cell) && cell["is placed"])
            {
                caveRooms++;
            }
        }
    }
    ExpectEq(16, caveRooms);

    object stoneDoor = load_object(
        "/areas/eledhel/under-city/fox-route/0x1.c");
    mapping doorExits = stoneDoor->getExitDirections()["default"];
    ExpectEq("/areas/eledhel/under-city/natural-caverns/0x0.c",
        doorExits["down"]);
    mapping caveMouth = caveRegion->coordinateToMapping(4, 5);
    object foxMouth = caveMouth["environment"];
    mapping mouthExits = foxMouth->getExitDirections()["default"];
    ExpectEq("/areas/eledhel/west-rural-two/fox-den/0x0.c",
        mouthExits["up"]);
}
