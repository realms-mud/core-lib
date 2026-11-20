//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@S@'Phaedra keeps its records and "
        "maps here. The northern avenue is open to the public; the rooms "
        "beyond this hall are not.'");
    addResponse("first conversation", "What does Phaedra study here?",
        "@S@'Tactics, campaigns, and the roads that join the kingdom. "
        "The library is for military history, not private correspondence.'");
}
