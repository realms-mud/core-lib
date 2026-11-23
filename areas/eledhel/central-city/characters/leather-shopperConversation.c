//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Rovin tests the buckle on "
        "his old belt. @S@'I have one more stretch of road before "
        "I can replace this properly.'");
    addTopic("travel gear", "@S@'A belt that holds its stitching "
        "is worth more to me than a polished one. Tavren says this "
        "piece can be repaired, so I am weighing the cost.'");

    addResponse("first conversation", "Are you buying a belt?",
        "@D@Rovin turns the cracked leather over in his hands.");
    addResponseTopic("first conversation", "Are you buying a belt?",
        "travel gear");
}
