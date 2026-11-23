//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Goven rests a hand on the "
        "strap of his pack. @S@'I have put my things upstairs. I "
        "am taking a walk before the next meal.'");
    addTopic("work day", "@S@'I came to settle a small account with "
        "a shopkeeper. The business is done, so I can travel home "
        "without worrying about it.'");
    addResponse("first conversation", "What brought you here?",
        "@D@He glances toward the Golden Flask.");
    addResponseTopic("first conversation", "What brought you here?",
        "work day");
}
