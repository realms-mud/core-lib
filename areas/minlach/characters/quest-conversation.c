//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void gateQuestResponse(string topic, string response,
    string quest, string state)
{
    addResponsePrerequisite(topic, response, ([
        "local assignment":([
            "type":"state",
            "state key":"/areas/minlach/quests/" + quest + ".c",
            "value":state
        ])
    ]));
}
