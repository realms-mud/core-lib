//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Hithen checks the stitching "
        "on his satchel. @S@'The coat is being mended. I can make "
        "the next run as soon as it is ready.'");
    addTopic("courier clothes", "@S@'A courier needs clothes that "
        "move freely and pockets that stay closed. I do not need "
        "a badge stitched on every sleeve.'");
    addResponse("first conversation", "What do you carry?",
        "@D@He shifts the satchel to his other shoulder.");
    addResponseTopic("first conversation", "What do you carry?",
        "courier clothes");
}
