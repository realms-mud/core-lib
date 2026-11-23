//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Tirwen checks the edge of a "
        "finished blade before setting it aside. @S@'Tell me what you "
        "need, and how soon you need it.'");
    addTopic("sword orders", "@S@'A useful sword is balanced for its "
        "owner. I keep common patterns in stock and take measured "
        "commissions when the work allows.'");
    addTopic("repairs", "@S@'Bring me the weapon before you trust it "
        "again. A loose hilt or a chipped edge can turn a small "
        "mistake into a grave one.'");
    addResponse("first conversation", "What swords do you have?",
        "@D@She gestures to the rack behind the counter.");
    addResponseTopic("first conversation", "What swords do you have?",
        "sword orders");
    addResponse("sword orders", "Can you repair a damaged blade?",
        "@D@Tirwen takes a polishing cloth from the bench.");
    addResponseTopic("sword orders", "Can you repair a damaged blade?",
        "repairs");
}
