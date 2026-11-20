//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'Anor is a working harbor. "
        "The coast road is open, but check the tide before taking a boat.'");
    addResponse("first conversation", "Have there been wrecks?",
        "@S@'A broken beacon stands north of town. The shore there "
        "is dangerous, and someone has been taking salvage before "
        "the owners can claim it.'");
}
