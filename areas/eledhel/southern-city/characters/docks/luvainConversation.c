//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Luvain sets two covered flasks "
        "beside the gangplank. @S@'Clean water for the crew.'");
    addTopic("ship water", "@S@'The flasks are sealed before loading. "
        "A crew should not need to draw from an unknown source at sea.'");
    addResponse("first conversation", "Who is taking the water?",
        "@D@She points toward the waiting crew.");
    addResponseTopic("first conversation", "Who is taking the water?",
        "ship water");
}
