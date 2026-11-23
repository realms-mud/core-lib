//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
inherit "/lib/core/events.c";

private string EscapeQuest =
    "/areas/eledhel/under-city/escapeQuest.c";

/////////////////////////////////////////////////////////////////////////////
public varargs int receiveEvent(object resident, string event, object player)
{
    int handled = 0;

    if (objectp(resident) && objectp(player) &&
        environment(resident) == environment(player) &&
        program_name(resident) ==
            "/areas/eledhel/central-city/palace/characters/sendral.c" &&
        event == "beginEledhelEscape")
    {
        handled = 1;
        if (player->beginQuest(EscapeQuest))
        {
            player->onStateChanged(load_object(EscapeQuest),
                player->questState(EscapeQuest));
            tell_object(player, "Sendral records the route in your "
                "journal and shows you the hidden way below the palace.\n");
        }
        else
        {
            tell_object(player, "That passage is already recorded "
                "in your journal.\n");
        }
    }

    return handled;
}
