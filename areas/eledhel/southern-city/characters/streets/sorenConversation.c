//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Soren folds a paper packet closed. "
        "@S@'The spice is measured and wrapped.'");
    addTopic("spice packets", "@S@'I keep the dry packets sealed. Damp "
        "air takes the sharpness out of them.'");
    addResponse("first conversation", "How do you keep the spice fresh?",
        "@D@He presses the packet flat.");
    addResponseTopic("first conversation", "How do you keep the spice fresh?",
        "spice packets");
}
