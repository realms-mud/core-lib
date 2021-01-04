//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("default", "We start talking.");
    addResponse("default", "First", "First response");
    addResponse("default", "Second", "Second response");
    addResponse("default", "Third", "Third response");

    addTopic("first topic", "First topic.");
    addResponse("first topic", "Back", "Going back");
    addResponseTopic("default", "First", "first topic");
    addResponseTopic("first topic", "Back", "default");
}
