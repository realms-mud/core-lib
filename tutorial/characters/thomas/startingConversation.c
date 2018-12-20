//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("get moving", "@S@`Our illustrious commander said...' "
        "@D@Thomas clears his throat and does his best immitation of Donald, "
        "@S@``Get that stupid shit ##ActorName## back here! We have enemies "
        "at hand!' Seriously, ##ActorName##.... what the hell are you doing?' "
        "@D@Without waiting for a response, Thomas runs off.");
}
