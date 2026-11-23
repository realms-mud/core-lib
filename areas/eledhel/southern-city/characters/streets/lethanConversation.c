//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Lethan watches a handcart clear "
        "the crossing. @S@'That lane is open again.'");
    addTopic("watch patrol", "@S@'We keep the crossings clear and send "
        "a runner if a cart blocks the street or a shop needs help.'");
    addResponse("first conversation", "What does your patrol watch for?",
        "@D@He looks along the row of houses.");
    addResponseTopic("first conversation",
        "What does your patrol watch for?", "watch patrol");
}
