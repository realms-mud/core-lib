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
        "/areas/eledhel/under-city/justice-branch/0x0.c");
    object foxMouth = clone_object(
        "/areas/eledhel/under-city/fox-route/41x0.c");
    object mechanism = clone_object(
        "/areas/eledhel/under-city/justice-mechanism/0x0.c");
    Harvested += ({ palace, passage, justice, foxMouth, mechanism });

    Player->beginQuest(questPath);
    passage->moveFromIsAllowed(Player, palace);
    ExpectFalse(foxMouth->moveFromIsAllowed(Player, justice));
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
        "/areas/eledhel/under-city/phaedra-branch/0x0.c");
    object otherPlayer = clone_object(
        "/lib/tests/support/services/mockPlayer.c");
    otherPlayer.Name("jane");
    Harvested += ({ library, passage, otherPlayer });

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
        "/areas/eledhel/under-city/fox-route/29x0.c");
    object cave = clone_object(
        "/areas/eledhel/under-city/fox-route/30x0.c");
    Harvested += ({ stoneDoor, cave });

    move_object(Player, stoneDoor);
    ExpectFalse(stoneDoor->moveToIsAllowed(Player, cave));
    command("push stalagmite", Player);
    ExpectTrue(stoneDoor->moveToIsAllowed(Player, cave));
}

/////////////////////////////////////////////////////////////////////////////
void UnderCityRegionHasAConnectedSpine()
{
    object region = load_object("/areas/eledhel/under-city/region.c");
    mapping rooms = ([]);
    Harvested += ({ region });

    for (int x = 0; x < region->xDimension(); x++)
    {
        for (int y = 0; y < region->yDimension(); y++)
        {
            mapping cell = region->coordinateToMapping(x, y);
            if (mappingp(cell) && cell["is placed"])
            {
                rooms[cell["name"]] = cell["environment"];
            }
        }
    }

    ExpectEq(163, sizeof(rooms));
    for (int index = 0; index <= 100; index++)
    {
        object room = rooms[sprintf(
            "/areas/eledhel/under-city/trunk/%dx0.c", index)];
        mapping exits = objectp(room) ?
            room->getExitDirections()["default"] : ([]);
        ExpectTrue(objectp(room), sprintf("trunk room %d", index));

        if (index > 0)
        {
            string direction = (index % 25) ?
                (index / 25 % 2 ? "east" : "west") : "north";
            ExpectEq(sprintf("/areas/eledhel/under-city/trunk/%dx0.c",
                index - 1), exits[direction]);
        }
        if (index < 100)
        {
            string direction = (index % 25 == 24) ? "south" :
                (index / 25 % 2 ? "west" : "east");
            ExpectEq(sprintf("/areas/eledhel/under-city/trunk/%dx0.c",
                index + 1), exits[direction]);
        }
    }

    for (int station = 0; station < 10; station++)
    {
        int trunkIndex = (station + 1) * 10 - 1;
        object stationRoom = rooms[sprintf(
            "/areas/eledhel/under-city/stations/%dx0.c", station)];
        object trunkRoom = rooms[sprintf(
            "/areas/eledhel/under-city/trunk/%dx0.c", trunkIndex)];
        ExpectTrue(objectp(stationRoom),
            sprintf("maintenance station %d", station));
        ExpectEq(sprintf("/areas/eledhel/under-city/trunk/%dx0.c",
            trunkIndex), stationRoom->getExitDirections()["default"]["south"]);
        ExpectEq(sprintf("/areas/eledhel/under-city/stations/%dx0.c",
            station), trunkRoom->getExitDirections()["default"]["north"]);
    }

    for (int segment = 0; segment < 42; segment++)
    {
        object room = rooms[sprintf(
            "/areas/eledhel/under-city/fox-route/%dx0.c", segment)];
        ExpectTrue(objectp(room), sprintf("outbound tunnel segment %d",
            segment));
    }

    object end = rooms["/areas/eledhel/under-city/trunk/100x0.c"];
    ExpectEq("/areas/eledhel/under-city/justice-mechanism/0x0.c",
        end->getExitDirections()["default"]["south"]);
}
