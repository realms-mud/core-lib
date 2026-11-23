//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Lethwyn pins a fresh "
        "handbill beside the theater door. @S@'We keep the stage "
        "small, the stories local, and the benches open to all.'");
    addTopic("performances", "@S@'The players borrow stories "
        "from the harbor, the market, and the old roads. A good "
        "audience knows all three.'");

    addResponse("first conversation", "What is showing?",
        "@D@She taps the handbill.");
    addResponseTopic("first conversation", "What is showing?",
        "performances");
}
