//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Edran turns the slate "
        "under his arm to keep the writing from rubbing away. "
        "@S@'I have one exercise left before I can put this away.'");
    addTopic("study", "@S@'I study letters and figures at the "
        "academy. If I learn them well, I can help with records "
        "instead of carrying crates.'");
    addResponse("first conversation", "What are you studying?",
        "@D@He looks down at the marks on the slate.");
    addResponseTopic("first conversation", "What are you studying?",
        "study");
}
