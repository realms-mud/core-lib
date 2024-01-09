//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************

/////////////////////////////////////////////////////////////////////////////
public void slipIntoUnconsciousnessPartThree(object player)
{
    load_object("/lib/dictionaries/guildsDictionary.c");
    load_object("/guilds/background/background.c");

    if (!player->memberOfGuild("background"))
    {
        player->joinGuild("background");
    }
    else
    {
        player->notify("onJoinGuild");
    }
}

/////////////////////////////////////////////////////////////////////////////
public void slipIntoUnconsciousnessPartTwo(object player)
{
    tell_object(player, format(
        "\n\x1b[0;36mWith crystal clarity, the "
        "fog in your mind clears. You are back in time... that very day "
        "you made the decisions that started the chain of events "
        "leading you to your current, sorry state.\n\n"
        "\x1b[0;33;1mThis is where the background quest stuff would "
        "normally get triggered. Since I don't have any here, we will "
        "short-circuit that right now.\x1b[0m", 78));
    call_out("slipIntoUnconsciousnessPartThree", 8, player);
}

/////////////////////////////////////////////////////////////////////////////
public void slipIntoUnconsciousness(object player)
{
    tell_object(player, format(
        "\n\x1b[0;36mAs Berenar and Galadhel tend to your injuries, it hurts "
        "like nothing you've felt before. Unbidden, the thought comes to your "
        "mind, \x1b[0;32m`So this is what it feels like to die.'\x1b[0;36m "
        "Angry that those thoughts came so easily... angry that you're lying "
        "in a pool of your own damned blood, you shake your head. That act "
        "proves to be most unwise as a wave of lightheadedness overtakes "
        "you and your eyesight goes blurry.\n\x1b[0m", 78));
    call_out("slipIntoUnconsciousnessPartTwo", 8, player);
}
