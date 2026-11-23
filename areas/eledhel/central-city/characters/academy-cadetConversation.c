//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Haldor finishes tying his "
        "bracer. @S@'The drill floor is quieter when we arrive ready.'");
    addTopic("academy training", "@S@'Our instructors correct the "
        "stance first. Strength cannot fix a poor footing.'");
    addResponse("first conversation", "What do you practice?",
        "@D@He gives the bracer one final tug.");
    addResponseTopic("first conversation", "What do you practice?",
        "academy training");
}
