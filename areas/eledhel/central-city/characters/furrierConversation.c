//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Othrel smooths a dark fur "
        "cloak on the counter. @S@'Looking for something warm, or "
        "something repaired?'");
    addTopic("pelts", "@S@'I buy sound pelts and turn them into "
        "cloaks, collars, and lining. Poorly cured hides are no "
        "use to anyone.'");
    addTopic("northern road", "@S@'Travelers bring me most of my "
        "news from the northern road. The cold reaches the city "
        "before the first snow does.'");

    addResponse("first conversation", "What do you make?",
        "@D@He gestures toward the fur-lined clothing.");
    addResponseTopic("first conversation", "What do you make?",
        "pelts");
    addResponse("first conversation", "Do you hear much from the north?",
        "@D@Othrel folds the cloak and looks toward the street.");
    addResponseTopic("first conversation",
        "Do you hear much from the north?", "northern road");
}
