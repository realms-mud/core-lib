//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private string EscapeQuest =
    "/areas/eledhel/under-city/escapeQuest.c";
private int IsCaveRoom = 0;

/////////////////////////////////////////////////////////////////////////////
protected void markAsCaveRoom()
{
    IsCaveRoom = 1;
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    cloneEnvironment();
    setInterior(IsCaveRoom ? "/lib/environment/interiors/cave.c" :
        "/lib/environment/interiors/ruin-hallway.c");
    setShortDescription("A narrow passage of fitted stone runs beneath "
        "the city, its joints darkened by age and torch smoke.");
}

/////////////////////////////////////////////////////////////////////////////
protected void configureTrunkSegment(int segmentIndex)
{
    int row = segmentIndex / 25;

    if (segmentIndex > 0)
    {
        string previousDirection = (segmentIndex % 25) ?
            (row % 2 ? "east" : "west") : "north";
        addExit(previousDirection, sprintf(
            "/areas/eledhel/under-city/trunk/%dx0.c", segmentIndex - 1));
    }

    if (segmentIndex < 100)
    {
        string nextDirection = (segmentIndex % 25 == 24) ? "south" :
            (row % 2 ? "west" : "east");
        addExit(nextDirection, sprintf(
            "/areas/eledhel/under-city/trunk/%dx0.c", segmentIndex + 1));
    }

    if ((segmentIndex % 10 == 9) && segmentIndex > 19)
    {
        int station = segmentIndex / 10;
        addExit("north", sprintf(
            "/areas/eledhel/under-city/stations/%dx0.c", station));
    }
}

/////////////////////////////////////////////////////////////////////////////
protected void configureFoxRouteSegment(int segmentIndex)
{
    if (segmentIndex == 0)
    {
        addExit("west", "/areas/eledhel/under-city/library-branch/0x0.c");
    }
    else if (segmentIndex == 25)
    {
        addExit("north",
            "/areas/eledhel/under-city/fox-route/24x0.c");
    }
    else
    {
        addExit(segmentIndex < 25 ? "west" : "east", sprintf(
            "/areas/eledhel/under-city/fox-route/%dx0.c",
            segmentIndex - 1));
    }

    if (segmentIndex < 24)
    {
        addExit("east", sprintf(
            "/areas/eledhel/under-city/fox-route/%dx0.c",
            segmentIndex + 1));
    }
    else if (segmentIndex == 24)
    {
        addExit("south",
            "/areas/eledhel/under-city/fox-route/25x0.c");
    }
    else if (segmentIndex < 41)
    {
        addExit("west", sprintf(
            "/areas/eledhel/under-city/fox-route/%dx0.c",
            segmentIndex + 1));
    }
    else
    {
        addExit("up", "/areas/eledhel/west-rural-two/fox-den/0x0.c");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();
}

/////////////////////////////////////////////////////////////////////////////
public int moveFromIsAllowed(object user, object fromLocation)
{
    int ret = 0;

    if (objectp(user) && user->questIsInProgress(EscapeQuest))
    {
        ret = 1;
        if (user->questState(EscapeQuest) == "escape begun")
        {
            object quest = load_object(EscapeQuest);
            quest->receiveEvent(user, "enteredUnderCity", user);
            user->onStateChanged(quest, user->questState(EscapeQuest));
        }
    }
    else if (objectp(user))
    {
        tell_object(user, "The concealed way remains sealed to you.\n");
    }

    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string escapeQuestPath()
{
    return EscapeQuest;
}
