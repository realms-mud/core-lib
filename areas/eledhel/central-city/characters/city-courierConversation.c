//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Mereth checks the knot on her "
        "message case. @S@'If the seal is sound, the right person will "
        "get it.'");
    addTopic("city routes", "@S@'I cross the old city on foot. The "
        "plaza is quickest when it is clear; the side streets are "
        "better when carts crowd the paving.'");
    addResponse("first conversation", "Do you carry messages?",
        "@D@She rests a hand on the case at her side.");
    addResponseTopic("first conversation", "Do you carry messages?",
        "city routes");
}
