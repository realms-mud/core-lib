//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Elen looks over the "
        "swordsmith's display. @S@'I want something I can maintain, "
        "not a blade that costs more than the rest of my gear.'");
    addTopic("sword buying", "@S@'A sound grip and a clean edge "
        "matter more to me than ornament. I will ask Tirwen what "
        "fits the work.'");
    addResponse("first conversation", "What kind of blade do you want?",
        "@D@She studies a plain sword on the rack.");
    addResponseTopic("first conversation", "What kind of blade do "
        "you want?", "sword buying");
}
