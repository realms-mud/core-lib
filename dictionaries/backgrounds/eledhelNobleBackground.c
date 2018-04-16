//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/dictionaries/backgrounds/baseBackground.c";

/////////////////////////////////////////////////////////////////////////////
protected nomask void Setup()
{
    setStartingLocation("/lib/tutorial/rooms/battleScene.c");
}

/////////////////////////////////////////////////////////////////////////////
public void displayIntro(object player)
{
    call_out("partOne", 4, player);
}

/////////////////////////////////////////////////////////////////////////////
public void partOne(object player)
{
    tell_object(player, format(
        "[0;36mOn a long campaign, sometimes routine is the only thing that "
        "keeps one going. Any good commander knows this - keep your men "
        "focused on the task at hand and keep them too exhausted for idle "
        "thought. Dig a ditch if you must, if for no other reason than to "
        "keep 'em busy. Another day can be spent filling the damned thing "
        "later.[0m", 78));
    call_out("partTwo", 4, player);
}

/////////////////////////////////////////////////////////////////////////////
public void partTwo(object player)
{
    tell_object(player, format(
        "\n[0;36mBasil, your company commander, imparted these words of wisdom "
        "on you countless times in the past. He'd said as much with a wry "
        "smile as he ordered you to patrol this accursed road for the 26th "
        "time since the stalemate was broken. It's funny. As the first "
        "flame-red rays of the new day pierced the thin wisps of fog, "
        "you couldn't help but think of how beautiful it was, despite your "
        "mundane and lamentably never-ending task.[0m", 78));
    call_out("partThree", 4, player);
}

/////////////////////////////////////////////////////////////////////////////
public void partThree(object player)
{
    tell_object(player,
        "\n[0;36mBasil was an expert in crushing hope too. [0;32m`An ill "
        "omen...'[0m[0;36m muttered Basil.\n[0;32m`Blood will be spilled "
        "today.'[0m[0;36m Captain Basil, was never one for euphemisms.\n"
        "Poor bastard. Little did he know at the time that the blood would "
        "be his own...[0m\n");
    introductionCompleted(player);
}
