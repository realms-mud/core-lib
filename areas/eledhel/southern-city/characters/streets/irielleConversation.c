//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Irielle tests the hook on her "
        "ladder. @S@'These lamps need checking before dusk.'");
    addTopic("street lamps", "@S@'The lamps along this row are tended "
        "by hand. I carry oil and a spare wick for each one.'");
    addResponse("first conversation", "Who looks after the lamps?",
        "@D@She nods toward the nearest post.");
    addResponseTopic("first conversation", "Who looks after the lamps?",
        "street lamps");
}
