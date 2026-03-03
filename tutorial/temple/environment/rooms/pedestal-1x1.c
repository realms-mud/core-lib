//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    cloneEnvironment();
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("/tutorial/temple/environment/features/purple-liquid.c");
    addFeature("/tutorial/temple/environment/features/pedestal.c");

    addExit("north", "/tutorial/temple/environment/rooms/entry-to-pedestal.c",
        "entered room");

    addObject("/tutorial/temple/objects/rune-wall.c");
    addObject("/tutorial/temple/objects/pedestal.c");

    addObject("/tutorial/temple/objects/rune-resistance.c", "entered room");

    addDecorator("ruined interior amethyst floor", "default");

    setStateMachine("/tutorial/temple/stateMachine/obedienceStateMachine.c");

    // First test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-1x2.c", "first test");

    // Second test
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-2x1.c", "second test");

    // Third test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-1x2.c", "third test");

    // Fourth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-1x2.c", "fourth test");

    // Fifth test
    addExit("east", "/tutorial/temple/environment/rooms/pedestal-1x2.c", "fifth test");

    // Sixth test
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-2x1.c", "sixth test");

    // Seventh test
    addExit("south", "/tutorial/temple/environment/rooms/pedestal-2x1.c", "seventh test");
}

/////////////////////////////////////////////////////////////////////////////
public void spawnUhrdalen(object stateMachine, object player)
{
    object uhrdalen = StateMachine ?
        StateMachine->getUhrdalen() : 0;

    if (objectp(uhrdalen))
    {
        string owner = cloneOwner();
        object location = (owner && member(instances, owner)) ?
            instances[owner] : this_object();

        uhrdalen->registerEvent(this_object());
        move_object(uhrdalen, location);
        command("talk uhrdalen", player);
    }
}

/////////////////////////////////////////////////////////////////////////////
public int canGet(object target)
{
    if (objectp(target) && (target->getRuneType() == "resistance"))
    {
        if (this_player())
        {
            this_player()->beginQuest("/tutorial/temple/stateMachine/obedienceStateMachine.c");

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
public void onStateChanged(object caller, string newState)
{
    ::onStateChanged(caller, newState);

    if (pedestal())
    {
        switch(newState)
        {
            case "second test":
            {
                pedestal()->startSecondTest();
                break;
            }
            case "third test":
            {
                pedestal()->startThirdTest();
                break;
            }
            case "fourth test":
            {
                pedestal()->startFourthTest();
                break;
            }
            case "fifth test":
            {
                pedestal()->startFifthTest();
                break;
            }
            case "sixth test":
            {
                pedestal()->startSixthTest();
                break;
            }
            case "seventh test":
            {
                pedestal()->startSeventhTest();
                break;
            }
            case "quest complete":
            {
                pedestal()->startEighthTest();
                break;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public int moveToIsAllowed(object user, object toLocation)
{
    int ret = 1;

    if (pedestal() && sizeof(regexp(({ object_name(toLocation) }), 
        "pedestal-[0-9]+x[0-9]+")))
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
    this_player()->resetQuest("/tutorial/temple/stateMachine/obedienceStateMachine.c");
    load_object("/tutorial/temple/characters/uhrdalen/uhrdalen.c")->resetConversationState();
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
