//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Faren steadies the wrapped jar "
        "against his hip. @S@'The firing went well this time.'");
    addTopic("pottery", "@S@'Clay pots travel better wrapped in straw. "
        "My master sends the sound ones to the market.'");
    addResponse("first conversation", "Where are you taking the jar?",
        "@D@He checks the wrapping before answering.");
    addResponseTopic("first conversation", "Where are you taking the jar?",
        "pottery");
}
