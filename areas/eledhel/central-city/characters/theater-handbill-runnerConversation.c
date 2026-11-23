//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Elmor keeps the handbills "
        "flat beneath his arm. @S@'The manager wants these posted "
        "before the next audience arrives.'");
    addTopic("handbills", "@S@'The notices name the play and the "
        "hours. I leave the rest to the performers.'");
    addResponse("first conversation", "What is playing?",
        "@D@He turns a handbill so its title faces you.");
    addResponseTopic("first conversation", "What is playing?",
        "handbills");
}
