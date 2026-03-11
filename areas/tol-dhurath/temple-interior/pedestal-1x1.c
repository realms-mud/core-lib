//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/areas/tol-dhurath/interiors/pedestal-chamber.c");
    addFeature("/areas/tol-dhurath/features/amethyst-floor.c");
    addFeature("/areas/tol-dhurath/features/amethyst-ceiling.c");
    addFeature("/areas/tol-dhurath/features/purple-liquid.c");
    addFeature("/areas/tol-dhurath/features/pedestal.c");

    addExit("north", "/areas/tol-dhurath/temple-interior/entry-to-pedestal.c",
        "entered room");
    addExit("north", "/areas/tol-dhurath/temple-interior/entry-to-pedestal.c",
        "uhrdalen left");

    addObject("/areas/tol-dhurath/objects/rune-wall.c");
    addObject("/areas/tol-dhurath/objects/pedestal.c");

    addPersistentObject("/areas/tol-dhurath/objects/rune-resistance.c", "entered room");

    addDecorator("ruined interior amethyst floor", "default");

    setStateMachine("/areas/tol-dhurath/state-machine/obedience-quest.c");

    // First test
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-1x2.c", "first test");

    // Second test
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-2x1.c", "second test");

    // Third test
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-1x2.c", "third test");

    // Fourth test
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-1x2.c", "fourth test");

    // Fifth test
    addExit("east", "/areas/tol-dhurath/temple-interior/pedestal-1x2.c", "fifth test");

    // Sixth test
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-2x1.c", "sixth test");

    // Poem complete (final passage)
    addExit("south", "/areas/tol-dhurath/temple-interior/pedestal-2x1.c", "poem complete");
}

/////////////////////////////////////////////////////////////////////////////
public void spawnUhrdalen(object stateMachine, object player)
{
    object uhrdalen = StateMachine ?
        StateMachine->getUhrdalen() : 0;

    if (objectp(uhrdalen))
    {
        uhrdalen->registerEvent(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
public int canGet(object target)
{
    if (objectp(target) && (target->getRuneType() == "resistance"))
    {
        if (this_player())
        {
            this_player()->beginQuest("/areas/tol-dhurath/state-machine/obedience-quest.c");

            if (StateMachine)
            {
                StateMachine->receiveEvent(this_player(), "gotRuneFromFloor");
            }
        }
    }
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public void uhrdalenLeft(object uhrdalen, object player)
{
    if (StateMachine)
    {
        StateMachine->receiveEvent(player, "uhrdalenLeft");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void revealName(object uhrdalen, object player)
{
    if (objectp(uhrdalen))
    {
        uhrdalen->revealName();
    }
}

/////////////////////////////////////////////////////////////////////////////
private object pedestal()
{
    string owner = cloneOwner();
    return present("pedestal-hidden", (owner && member(instances, owner)) ?
        instances[owner] : this_object());
}

/////////////////////////////////////////////////////////////////////////////
public void startFirstTest(object uhrdalen, object player)
{
    if (pedestal())
    {
        pedestal()->startFirstTest();
    }

    if (StateMachine)
    {
        StateMachine->receiveEvent(player, "startFirstTest");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void startSecondTest(object caller, object player)
{
    if (pedestal())
    {
        pedestal()->startSecondTest();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void startThirdTest(object caller, object player)
{
    if (pedestal())
    {
        pedestal()->startThirdTest();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void startFourthTest(object caller, object player)
{
    if (pedestal())
    {
        pedestal()->startFourthTest();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void startFifthTest(object caller, object player)
{
    if (pedestal())
    {
        pedestal()->startFifthTest();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void startSixthTest(object caller, object player)
{
    if (pedestal())
    {
        pedestal()->startSixthTest();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void startSeventhTest(object caller, object player)
{
    if (pedestal())
    {
        pedestal()->startSeventhTest();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void startFinalPassage(object caller, object player)
{
    if (pedestal())
    {
        pedestal()->startFinalPassage();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void startEighthTest(object caller, object player)
{
    if (pedestal())
    {
        pedestal()->startEighthTest();
    }
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;

    if (pedestal() && sizeof(regexp(({ object_name(toLocation) }), 
        "pedestal-[1-5]+x[0-5]+")))
    {
        ret = pedestal()->allowMove();
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();

    if (present(this_player()))
    {
        add_action("resetEverything", "resetEverything");
        add_action("updateState", "updateState");

        if (StateMachine && member(({ "second test", "third test",
            "fourth test", "fifth test", "sixth test",
            "seventh test" }),
            currentState()) > -1)
        {
            StateMachine->placeUhrdalenForConversation(this_player());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public int updateState(string command)
{
    printf("Sent %O event to all state objects.\n", command);

    StateMachine->receiveEvent(this_object(), command, this_player());
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public int resetEverything(string command)
{
    write("Resetting all the things!\n");

    pedestal()->pressPlateOfDeath(1);
    this_player()->resetQuest("/areas/tol-dhurath/state-machine/obedience-quest.c");
    load_object("/areas/tol-dhurath/characters/uhrdalen/uhrdalen.c")->resetConversationState();
    StateMachine->startStateMachine();
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
public string **customIcon(string **baseIcon, string color, string charset)
{
    string baseColor = getService("region")->iconColor(
        decoratorType(), color);

    baseIcon[0][1] = pedestal()->getOrb("north");
    baseIcon[1][0] = pedestal()->getOrb("west");
    baseIcon[1][2] = pedestal()->getOrb("east");
    baseIcon[2][1] = pedestal()->getOrb("south");

    return baseIcon;
}
