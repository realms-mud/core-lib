//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Miral checks the leaves in her "
        "basket. @S@'These were cut before the sun reached the beds.'");
    addTopic("fresh herbs", "@S@'I bring small bunches from the garden "
        "to the market. Keep the tender leaves out of the heat.'");
    addResponse("first conversation", "Where did you gather the herbs?",
        "@D@She covers the basket with a cloth.");
    addResponseTopic("first conversation", "Where did you gather the herbs?",
        "fresh herbs");
}
