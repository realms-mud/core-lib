//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Sarneth shifts the tally "
        "stick to her other hand. @S@'A count made twice is still "
        "faster than looking for a missing crate.'");
    addTopic("storehouse work", "@S@'Porters keep the lanes open by "
        "moving each load inside quickly. We mark what arrives before "
        "the next cart takes its place.'");
    addResponse("first conversation", "What is your tally for?",
        "@D@She taps the marks cut into the stick.");
    addResponseTopic("first conversation", "What is your tally for?",
        "storehouse work");
}
