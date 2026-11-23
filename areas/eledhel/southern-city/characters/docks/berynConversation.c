//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Beryn sorts fish into clean "
        "baskets. @S@'The market will take these first.'");
    addTopic("fish baskets", "@S@'We keep the catch shaded and the "
        "baskets clean. The buyers can inspect each lot before paying.'");
    addResponse("first conversation", "How is the catch sorted?",
        "@D@She lifts the edge of the cloth cover.");
    addResponseTopic("first conversation", "How is the catch sorted?",
        "fish baskets");
}
