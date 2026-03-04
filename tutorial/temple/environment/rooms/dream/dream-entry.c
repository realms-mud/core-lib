//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private object returnPool = 0;
private int choicesMade = 0;

private mapping dreamColors = ([
    "vision":([
        "none": "",
        "grayscale": "\x1b[0;38;5;248;1m",
        "3-bit": "\x1b[0;35;1m",
        "8-bit": "\x1b[0;38;5;128;1m",
        "24-bit": "\x1b[0;38;2;190;90;210;1m"
    ]),
    "failure":([
        "none": "",
        "grayscale": "\x1b[0;38;5;236;1m",
        "3-bit": "\x1b[0;31;1m",
        "8-bit": "\x1b[0;38;5;124;1m",
        "24-bit": "\x1b[0;38;2;180;0;0;1m"
    ]),
]);

/////////////////////////////////////////////////////////////////////////////
public mapping getDreamColors()
{
    return dreamColors;
}

/////////////////////////////////////////////////////////////////////////////
public void setReturnPool(object pool)
{
    returnPool = pool;
}

/////////////////////////////////////////////////////////////////////////////
public object getReturnPool()
{
    return returnPool;
}

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setInterior("/tutorial/temple/environment/interiors/pedestal-chamber.c");
    addFeature("/tutorial/temple/environment/features/amethyst-floor.c");
    addFeature("/tutorial/temple/environment/features/amethyst-ceiling.c");

    addExit("north",
        "/tutorial/temple/environment/rooms/dream/dream-temptation.c");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    ::init();

    if (present(this_player()))
    {
        string colorConfig = (objectp(this_player()) && 
            this_player()->colorConfiguration()) ?
            this_player()->colorConfiguration() : "none";
        string closing = (colorConfig == "none") ? "" : "\x1b[0m";

        tell_object(this_player(), format(
            dreamColors["vision"][colorConfig] +
            "The purple mist clears. You find yourself in a "
            "chamber that feels familiar yet wrong - as though you are "
            "seeing it through another's eyes. You are Uhrdalen, long "
            "before the binding. The world is younger and so are you.\n\n"
            "A corridor leads north." + closing + "\n", 78));
    }
}

/////////////////////////////////////////////////////////////////////////////
public void resetDream(object player)
{
    choicesMade = 0;

    string colorConfig = (objectp(player) && player->colorConfiguration()) ?
        player->colorConfiguration() : "none";
    string closing = (colorConfig == "none") ? "" : "\x1b[0m";

    tell_object(player,
        dreamColors["failure"][colorConfig] +
        "The vision shatters! The world spins and reforms. "
        "You are back at the beginning. You cannot change what was - "
        "you must relive it as it happened." + closing + "\n");
    move_object(player, this_object());
}

/////////////////////////////////////////////////////////////////////////////
public void completeDream(object player)
{
    string colorConfig = (objectp(player) && player->colorConfiguration()) ?
        player->colorConfiguration() : "none";
    string closing = (colorConfig == "none") ? "" : "\x1b[0m";

    tell_object(player,
        dreamColors["vision"][colorConfig] +
        "The dream dissolves into purple mist. You feel the "
        "weight of Uhrdalen's centuries of regret settle into your bones "
        "before fading. Understanding lingers." + closing + "\n");

    object pool = returnPool;
    object returnRoom = pool ? environment(pool) : 0;
    if (returnRoom)
    {
        move_object(player, returnRoom);
        pool->dreamCompleted(player);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void advanceDream(object player, string choice)
{
    choicesMade++;
    if (choicesMade >= 3)
    {
        completeDream(player);
    }
}

/////////////////////////////////////////////////////////////////////////////
public string suppressDeath()
{
    return "The dream protects you from true death, but the pain "
        "feels very real.\n";
}
