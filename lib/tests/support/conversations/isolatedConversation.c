//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("isolated menu", "A separate conversation menu.");
    addResponse("isolated menu", "A elf", "The elf response.");
    addResponsePrerequisite("isolated menu", "A elf", ([
        "race":([
            "type":"race",
            "value":({ "elf" })
        ])
    ]));
    addResponse("isolated menu", "B common", "The common response.");
    addTopic("isolated blocked", "This topic requires an elf.");
    addTopicPrerequisite("isolated blocked", ([
        "race":([
            "type":"race",
            "value":({ "elf" })
        ])
    ]));
}