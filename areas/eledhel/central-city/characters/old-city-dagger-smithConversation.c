//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Hethor turns a small blade "
        "carefully by its hilt. @S@'A short weapon is still a weapon. "
        "What do you need it to do?'");
    addTopic("dagger work", "@S@'I make working knives and daggers, "
        "not toys. Balance, a secure grip, and a sound sheath matter "
        "as much as the edge.'");
    addTopic("sharpening", "@S@'A clean edge is safer than a ragged "
        "one. Keep it dry and let me see it before the steel pits.'");
    addResponse("first conversation", "What kinds do you make?",
        "@D@He sets the blade down on a folded cloth.");
    addResponseTopic("first conversation", "What kinds do you make?",
        "dagger work");
    addResponse("dagger work", "Can you sharpen one?",
        "@S@'If the steel is sound, I can put a working edge back on it.'");
    addResponseTopic("dagger work", "Can you sharpen one?",
        "sharpening");
}
