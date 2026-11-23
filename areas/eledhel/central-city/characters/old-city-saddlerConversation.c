//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Myrwen draws a strap through "
        "her hands to check its stitching. @S@'Tack must hold when a "
        "horse shies. What has failed on yours?'");
    addTopic("harnesses", "@S@'I fit bridles and harness to the animal, "
        "not to a drawing. A strap that rubs raw will not last a week.'");
    addTopic("leather care", "@S@'Keep mud out of the seams and dry "
        "leather slowly. Heat makes it brittle, however impatient you "
        "are to ride.'");
    addResponse("first conversation", "What work do you take?",
        "@D@She lays the strap across the workbench.");
    addResponseTopic("first conversation", "What work do you take?",
        "harnesses");
    addResponse("harnesses", "How should I care for leather?",
        "@S@'A clean cloth and patience will save you a costly repair.'");
    addResponseTopic("harnesses", "How should I care for leather?",
        "leather care");
}
