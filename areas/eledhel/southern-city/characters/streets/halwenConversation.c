//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Halwen spins the repaired wheel "
        "once. @S@'The axle turns cleanly now.'");
    addTopic("wheel repairs", "@S@'A cart wheel must run true under "
        "load. The wainwright checks the hub before replacing a spoke.'");
    addResponse("first conversation", "What was wrong with the wheel?",
        "@D@He points to the new spoke.");
    addResponseTopic("first conversation", "What was wrong with the wheel?",
        "wheel repairs");
}
