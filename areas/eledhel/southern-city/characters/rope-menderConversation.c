//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Lirwen draws a length of "
        "hemp through her hands. @S@'A line is cheaper to mend "
        "now than to replace after a load goes overboard.'");
    addTopic("tide work", "@S@'The water shifts against the pilings "
        "all day. We check the moorings at each change, especially "
        "when a ship is heavy with cargo.'");

    addResponse("first conversation", "Why mend the lines here?",
        "@D@She points toward the ships along the quay.");
    addResponseTopic("first conversation", "Why mend the lines here?",
        "tide work");
}
