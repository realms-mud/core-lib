//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@S@'A hearing comes before a cell. "
        "The records show who was brought here and who was released.'");
    addResponse("first conversation", "Are the cells occupied?",
        "@S@'Not today. The city has a court for disputes; this place "
        "is for prisoners held under the magistrate's order.'");
}
