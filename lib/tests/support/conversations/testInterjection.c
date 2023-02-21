//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("talk to me", "This is a conversation");
    addTopicInterjection("talk to me",
        "/lib/tests/support/conversations/testNPC.c",
        "interjected comment");
    addResponse("talk to me", "Response", "@S@'Bite me'");
}
