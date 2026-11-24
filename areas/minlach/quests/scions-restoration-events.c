//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
private string RenvethPath =
    "/areas/minlach/characters/renveth/renveth.c";
private string RestorationQuest =
    "/areas/minlach/quests/scions-restoration.c";
private string TolDhurathQuest =
    "/areas/tol-dhurath/state-machine/tol-dhurath-quest.c";

/////////////////////////////////////////////////////////////////////////////
public varargs int receiveEvent(object resident, string event, object player)
{
    int handled = 0;

    if (objectp(resident) && program_name(resident) == RenvethPath &&
        event == "tolDhurathReleaseReported" && objectp(player) &&
        player->questIsCompleted(TolDhurathQuest) &&
        player->questIsActive(RestorationQuest))
    {
        handled = 1;
        if (!load_object(RestorationQuest)->receiveEvent(player, event))
        {
            tell_object(player, "Renveth listens, but the restoration "
                "undertaking has not yet begun.\n");
        }
    }
    return handled;
}
