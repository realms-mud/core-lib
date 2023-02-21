//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("test", "This is a test message");
    addTopic("test 2", "This is another test message");
    addTopicPrerequisite("test 2", ([
        "spoken topic":([
            "type": "spoken topics",
            "value": ({ "test" })
        ])
    ]));
}
