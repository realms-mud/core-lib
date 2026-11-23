//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Nareth checks the marks on "
        "a cargo slate. @S@'Keep to the clear side of the quay. "
        "Those lines are under strain.'");
    addTopic("cargo tally", "@S@'We count each load as it comes "
        "ashore. If a crate is damaged, it is marked before "
        "anyone carries it inland.'");

    addResponse("first conversation", "What is coming through the docks?",
        "@D@He taps the slate with a blunt finger.");
    addResponseTopic("first conversation",
        "What is coming through the docks?", "cargo tally");
}
