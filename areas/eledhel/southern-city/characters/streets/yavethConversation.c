//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Yaveth steps aside as a loaded "
        "cart passes. @S@'The shop doors are clear again.'");
    addTopic("shop watch", "@S@'We watch the crossings and the busy "
        "entrances. Most trouble starts when a lane gets blocked.'");
    addResponse("first conversation", "What does the watch do here?",
        "@D@He looks toward the next crossing.");
    addResponseTopic("first conversation", "What does the watch do here?",
        "shop watch");
}
