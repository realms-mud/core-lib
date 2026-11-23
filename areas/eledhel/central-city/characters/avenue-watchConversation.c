//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Haeren steps aside to let "
        "a handcart pass. @S@'There is room if everyone leaves room.'");
    addTopic("watch patrol", "@S@'I watch the crossings and keep "
        "the carts from blocking the footway. Most trouble begins "
        "when someone insists on being first.'");
    addResponse("first conversation", "What does your watch cover?",
        "@D@He looks along the avenue toward the plaza.");
    addResponseTopic("first conversation", "What does your watch "
        "cover?", "watch patrol");
}
