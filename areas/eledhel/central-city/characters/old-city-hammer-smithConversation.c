//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Gorwen tests the haft of a "
        "hammer against the bench. @S@'A tool must suit the hand that "
        "uses it. What sort of work do you do?'");
    addTopic("hammers", "@S@'I make hammers for smiths and builders. "
        "The weight should do the work, not the wrist.'");
    addTopic("tool repair", "@S@'A split haft can be replaced. If the "
        "head is loose, do not keep swinging it until someone is hurt.'");
    addResponse("first conversation", "What tools do you sell?",
        "@D@She points to a line of finished tools.");
    addResponseTopic("first conversation", "What tools do you sell?",
        "hammers");
    addResponse("hammers", "Can you repair a loose head?",
        "@D@Gorwen reaches for a wedge and a mallet.");
    addResponseTopic("hammers", "Can you repair a loose head?",
        "tool repair");
}
