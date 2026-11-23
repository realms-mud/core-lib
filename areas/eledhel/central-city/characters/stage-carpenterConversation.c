//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Velwen checks the buckles "
        "on her tool roll. @S@'A loose board is easy to fix before "
        "the benches fill.'");
    addTopic("stage work", "@S@'The painted scenery gets attention, "
        "but I watch the hinges and braces. Those are what keep a "
        "scene safe.'");
    addResponse("first conversation", "What do you repair?",
        "@D@She points toward the theater doors.");
    addResponseTopic("first conversation", "What do you repair?",
        "stage work");
}
