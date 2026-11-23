//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Morleth turns from his jars "
        "and gives you a measured look. @S@'I sell herbs and remedies. "
        "Tell me what you need before you reach for anything.'");
    addTopic("herb safety", "@S@'A familiar smell is not proof of "
        "safety. Use only a plant you can identify and prepare correctly.'");
    addTopic("herb stocks", "@S@'The shelves change with the season. "
        "I keep what can be gathered responsibly and do not promise "
        "a remedy I cannot make.'");

    addResponse("first conversation", "Can you help me choose a remedy?",
        "@S@'Describe the problem, and I will tell you what I can "
        "offer. If it is beyond an herbalist, I will say so.'");
    addResponseTopic("first conversation",
        "Can you help me choose a remedy?", "herb safety");
    addResponse("first conversation", "Do you always have the same herbs?",
        "@D@He gestures toward the drying rack and jars.");
    addResponseTopic("first conversation",
        "Do you always have the same herbs?", "herb stocks");
    addResponse("herb stocks", "Can I gather the plants myself?",
        "@S@'Only if you know them. Leave a patch enough to seed, "
        "and never test an unknown plant on a wound.'");
    addResponseTopic("herb stocks", "Can I gather the plants myself?",
        "herb safety");
}
