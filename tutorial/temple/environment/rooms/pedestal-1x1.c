//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/lib/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("lib/tutorial/temple/environment/features/amethyst-ceiling.c");
    addFeature("lib/tutorial/temple/environment/features/purple-liquid.c");
    addFeature("lib/tutorial/temple/environment/features/pedestal.c");

    addExit("north", "/lib/tutorial/temple/environment/rooms/pedestal-entry.c");

    addObject("/lib/tutorial/temple/objects/rune-wall.c");
    addObject("/lib/tutorial/temple/objects/pedestal.c");

    addObject("/lib/tutorial/temple/objects/rune-resistance.c", "entered room");
    setCoordinates("temple of obedience", 21, 25);

    setStateMachine(load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c"));

    // First test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-1x2.c", "first test");

    // Second test
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-2x1.c", "second test");

    // Third test
    addExit("southeast", "/lib/tutorial/temple/environment/rooms/pedestal-2x2.c", "third test");

    // Fourth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-1x2.c", "fourth test");

    // Fifth test
    addExit("east", "/lib/tutorial/temple/environment/rooms/pedestal-1x2.c", "fifth test");

    // Sixth test
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-2x1.c", "sixth test");

    // Seventh test
    addExit("south", "/lib/tutorial/temple/environment/rooms/pedestal-2x1.c", "seventh test");
}

/////////////////////////////////////////////////////////////////////////////
public void spawnUhrdalen(object stateMachine, object player)
{
    object uhrdalen = clone_object("/lib/tutorial/temple/characters/uhrdalen/uhrdalen.c");
    uhrdalen->registerEvent(this_object());
    move_object(uhrdalen, this_object());
    command("talk uhrdalen", player);
}

/////////////////////////////////////////////////////////////////////////////
public int canGet(object target)
{
    if (objectp(target) && (target->getRuneType() == "resistance"))
    {
        if (this_player())
        {
            this_player()->beginQuest("lib/tutorial/temple/stateMachine/obedienceStateMachine.c");

            object stateMachine =
                load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");

            if (stateMachine)
            {
                stateMachine->receiveEvent(this_player(), "gotRuneFromFloor");
            }
        }
    }
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
void uhrdalenLeft(object uhrdalen, object player)
{
    object stateMachine =
        load_object("/lib/tutorial/temple/stateMachine/obedienceStateMachine.c");

    stateMachine->receiveEvent(player, "uhrdalenLeft");
}
