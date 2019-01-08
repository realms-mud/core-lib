//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("aye but how", "@S@`Aye, but how?' @D@asks "
        "Halgaladh as he steps up next to Galadhel.");
    addTopicInterjection("aye but how",
        "/lib/tutorial/characters/halgaladh/halgaladh.c",
        "I do not know", 1);
}
