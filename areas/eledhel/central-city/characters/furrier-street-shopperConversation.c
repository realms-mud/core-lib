//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Faren looks from the shop "
        "window to the sky. @S@'I have a cloak that will do for now, "
        "unless the wind changes.'");
    addTopic("winter cloaks", "@S@'A good lining lasts for years. "
        "I would rather mend a sound cloak than replace it after "
        "one wet season.'");
    addResponse("first conversation", "Are you going inside?",
        "@D@He studies the furrier's window again.");
    addResponseTopic("first conversation", "Are you going inside?",
        "winter cloaks");
}
