//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private string EscapeQuest =
    "/areas/eledhel/under-city/escapeQuest.c";
private string MapExit =
    "/areas/eledhel/under-city/phaedra-branch/0x0.c";
private string MapProgram =
    "/areas/eledhel/northern-city/phaedra-headquarters/1x2.c";
private string *expectedMoves = ({
    "serach 45 counterclockwise",
    "eledhel 90 clockwise",
    "serach 135 clockwise",
    "ethyl tirath 180 counterclockwise",
    "hillgarath 360 clockwise",
    "eledhel 180 counterclockwise"
});
private mapping puzzleSteps = ([]);

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/environment/interiors/stone-keep.c");
    setShortDescription("The Phaedra library of tactics and history");
    addDecorator("keep interior floor");
    addItem("/lib/environment/items/lighting/lit-sconce.c", "north");
    addExit("east",
        "/areas/eledhel/northern-city/phaedra-headquarters/2x2.c");
    addExit("down", MapExit);
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();
    add_action("turnCitadel", "turn");
    add_action("pressCitadel", "press");
}

/////////////////////////////////////////////////////////////////////////////
public int turnCitadel(string move)
{
    return load_object(MapProgram)->turnCitadelFor(
        this_player(), move);
}

/////////////////////////////////////////////////////////////////////////////
public int turnCitadelFor(object player, string move)
{
    int ret = 0;
    if (objectp(player) && stringp(move) && sizeof(move))
    {
        ret = 1;
        string playerKey = object_name(player);
        int step = member(puzzleSteps, playerKey) ?
            puzzleSteps[playerKey] : 0;
        if (step < sizeof(expectedMoves) &&
            lower_case(move) == expectedMoves[step])
        {
            puzzleSteps[playerKey] = step + 1;
            tell_object(player, "One of the map's citadels "
                "turns with a faint click.\n");
        }
        else
        {
            puzzleSteps[playerKey] = 0;
            tell_object(player, "The mechanism grinds and "
                "the citadels settle back into place.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int pressCitadel(string citadel)
{
    return load_object(MapProgram)->pressCitadelFor(
        this_player(), citadel);
}

/////////////////////////////////////////////////////////////////////////////
public int pressCitadelFor(object player, string citadel)
{
    int ret = 0;
    if (objectp(player) && stringp(citadel) &&
        lower_case(citadel) == "eledhel")
    {
        ret = 1;
        string playerKey = object_name(player);
        int step = member(puzzleSteps, playerKey) ?
            puzzleSteps[playerKey] : 0;
        if (step == sizeof(expectedMoves))
        {
            puzzleSteps[playerKey] = step + 1;
            tell_object(player, "The citadels spring upright. "
                "A hidden panel opens in the north wall.\n");
        }
        else
        {
            puzzleSteps[playerKey] = 0;
            tell_object(player, "The citadel will not depress. "
                "The map resets with a muted click.\n");
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void closeMapDoor(object player)
{
    if (objectp(player))
    {
        m_delete(puzzleSteps, object_name(player));
    }
}

/////////////////////////////////////////////////////////////////////////////
public int mapDoorIsOpenFor(object player)
{
    int ret = 0;
    if (objectp(player) && player->questIsInProgress(EscapeQuest))
    {
        string playerKey = object_name(player);
        ret = member(puzzleSteps, playerKey) &&
            puzzleSteps[playerKey] == sizeof(expectedMoves) + 1;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;
    if (objectp(toLocation) && program_name(toLocation) == MapExit)
    {
        if (!load_object(MapProgram)->mapDoorIsOpenFor(user))
        {
            ret = 0;
            if (objectp(user))
            {
                tell_object(user, "The map's hidden panel remains "
                    "closed.\n");
            }
        }
    }
    return ret;
}
