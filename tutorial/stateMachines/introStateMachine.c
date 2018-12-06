//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/stateMachine.c";

private object Player;
private object Galadhel;
private object Berenar;

/////////////////////////////////////////////////////////////////////////////
private void setUpActors()
{
    if (!Galadhel)
    {
        Galadhel = clone_object("/lib/tutorial/characters/galadhel/galadhel.c");
        registerStateActor(Galadhel);
        Galadhel->registerEvent(this_object());
    }

    if (!Berenar)
    {
        Berenar = clone_object("/lib/tutorial/characters/berenar/berenar.c");
        registerStateActor(Berenar);
        Berenar->registerEvent(this_object());
    }
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        "stateMachine"::reset(arg);
        addState("initiate story", "");
        addEntryAction("initiate story", "displayIntroduction");

        addState("regain consciousness", "");
        addEntryAction("regain consciousness", "galadhelAwakensPlayer");
        addTransition("initiate story", "regain consciousness", "regainConsciousness");

        addState("berenar interjects", "");
        addEntryAction("berenar interjects", "berenarBeginsConversation");
        addTransition("regain consciousness", "berenar interjects", "berenarInterjects");

        setInitialState("initiate story");

        setUpActors();
    }
}

/////////////////////////////////////////////////////////////////////////////
public void beginIntroduction(object player)
{
    Player = player;
    startStateMachine();
}

/////////////////////////////////////////////////////////////////////////////
public void galadhelAwakensPlayer()
{
    notify("onTriggerConversation", "galadhel awakens player");
}

/////////////////////////////////////////////////////////////////////////////
public void berenarBeginsConversation()
{
    notify("onTriggerConversation", "berenar interjects");
}

/////////////////////////////////////////////////////////////////////////////
public void partThree(object player)
{
    tell_object(player,
        "\n\x1b[0;36mBasil was an expert in crushing hope too. \x1b[0;32m`An ill "
        "omen...'\x1b[0m\x1b[0;36m muttered Basil.\n\x1b[0;32m`Blood will be spilled "
        "today.'\x1b[0m\x1b[0;36m Captain Basil, was never one for euphemisms.\n"
        "Poor bastard. Little did he know at the time that the blood would "
        "be his own...\x1b[0m\n");
    call_out("receiveEvent", 4, player, "regainConsciousness", player);
}

/////////////////////////////////////////////////////////////////////////////
public void partTwo(object player)
{
    tell_object(player, format(
        "\n\x1b[0;36mBasil, your company commander, imparted these words of wisdom "
        "on you countless times in the past. He'd said as much with a wry "
        "smile as he ordered you to patrol this accursed road for the 26th "
        "time since the stalemate was broken. It's funny. As the first "
        "flame-red rays of the new day pierced the thin wisps of fog, "
        "you couldn't help but think of how beautiful it was, despite your "
        "mundane and lamentably never-ending task.\x1b[0m", 78));
    call_out("partThree", 4, player);
}

/////////////////////////////////////////////////////////////////////////////
public void partOne(object player)
{
    tell_object(player, format(
        "\x1b[0;36mOn a long campaign, sometimes routine is the only thing that "
        "keeps one going. Any good commander knows this - keep your men "
        "focused on the task at hand and keep them too exhausted for idle "
        "thought. Dig a ditch if you must, if for no other reason than to "
        "keep 'em busy. Another day can be spent filling the damned thing "
        "later.\x1b[0m", 78));
    call_out("partTwo", 4, player);
}

/////////////////////////////////////////////////////////////////////////////
public void displayIntroduction()
{
    move_object(Galadhel, "/lib/tutorial/rooms/battleScene.c");
    move_object(Berenar, "/lib/tutorial/rooms/battleScene.c");
    call_out("partOne", 2, Player);
}

/////////////////////////////////////////////////////////////////////////////
public void finishBackgroundStory()
{
    // introductionCompleted(Player);
}
