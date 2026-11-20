//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

private mapping clues = ([]);

/////////////////////////////////////////////////////////////////////////////
protected void addClue(string name, string quest, string event, string account)
{
    clues[name] = ([
        "quest":"/areas/minlach/quests/" + quest + ".c",
        "event":event,
        "account":account
    ]);
}

/////////////////////////////////////////////////////////////////////////////
public int investigate(string subject)
{
    int handled = 0;
    if (stringp(subject) && member(clues, lower_case(subject)))
    {
        handled = 1;
        mapping clue = clues[lower_case(subject)];
        object player = this_player();
        tell_object(player, format(clue["account"] + "\n", 78));
        if (player->questIsActive(clue["quest"]))
        {
            if (!load_object(clue["quest"])->receiveEvent(player, clue["event"]))
            {
                tell_object(player, "Your journal needs an earlier step "
                    "of this investigation before this finding can advance it.\n");
            }
        }
        else
        {
            tell_object(player, "Ask the resident responsible for this "
                "matter if you want to take on the investigation.\n");
        }
    }
    return handled;
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    environment::init();
    add_action("investigate", "investigate");
}
