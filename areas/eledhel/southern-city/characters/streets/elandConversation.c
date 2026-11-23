//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Eland refolds a length of cloth "
        "before offering it to a customer. @S@'The weave is sturdy.'");
    addTopic("cloth sales", "@S@'Households buy plain cloth for "
        "repairs. The finer patterns sell more slowly.'");
    addResponse("first conversation", "Who buys the plain cloth?",
        "@D@He gestures toward the houses.");
    addResponseTopic("first conversation", "Who buys the plain cloth?",
        "cloth sales");
}
