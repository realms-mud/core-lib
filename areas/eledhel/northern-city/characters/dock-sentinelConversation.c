//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Kerren shifts aside to leave "
        "the quay clear. @S@'Keep this lane open for cargo. "
        "The public pier is farther east.'");
    addTopic("service quay", "@S@'This route joins the dock to the "
        "naval stores. Visitors may pass when they have business, "
        "but must not block a working crew.'");
    addTopic("reporting trouble", "@S@'Tell the watch what you saw "
        "and where. Do not confront a stranger over a guess.'");

    addResponse("first conversation", "Why is this quay guarded?",
        "@D@He gestures toward the loaded carts.");
    addResponseTopic("first conversation", "Why is this quay guarded?",
        "service quay");
    addResponse("first conversation", "What if I see something wrong?",
        "@S@'Report it to the watch. A clear account is more useful "
        "than a rumor passed along the pier.'");
    addResponseTopic("first conversation", "What if I see something wrong?",
        "reporting trouble");
    addResponse("service quay", "Can I help unload a ship?",
        "@S@'Ask its crew or the dockmaster. The cargo has an order "
        "and the crew knows where each piece belongs.'");
}
