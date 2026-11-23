//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Lethen warms her hands "
        "beside the hearth. @S@'I am glad to be indoors for a little "
        "while.'");
    addTopic("north road", "@S@'My cart came down from the north "
        "with wool and a few small parcels. The last stretch was "
        "slower than the maps promised.'");
    addResponse("first conversation", "Where did you travel from?",
        "@D@She nods toward the road outside.");
    addResponseTopic("first conversation", "Where did you travel from?",
        "north road");
}
