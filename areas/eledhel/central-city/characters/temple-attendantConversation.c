//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Mineth checks that the bowl "
        "is level. @S@'A quiet hall is easier to prepare when the "
        "ordinary work is done first.'");
    addTopic("temple service", "@S@'I keep the entry in order and "
        "help visitors find the public hall. The knights lead their "
        "own lessons inside.'");
    addResponse("first conversation", "What is your duty?",
        "@D@She turns toward the temple doors.");
    addResponseTopic("first conversation", "What is your duty?",
        "temple service");
}
