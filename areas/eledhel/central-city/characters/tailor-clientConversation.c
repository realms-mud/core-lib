//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Melwen holds the cloth "
        "carefully by its edges. @S@'I brought it before the seam "
        "pulled any farther.'");
    addTopic("tailoring", "@S@'A small alteration is cheaper than "
        "starting again. The tailor has the measure written down.'");
    addResponse("first conversation", "What needs altering?",
        "@D@She points to a line of loose stitching.");
    addResponseTopic("first conversation", "What needs altering?",
        "tailoring");
}
