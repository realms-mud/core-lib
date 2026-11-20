//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Nareth closes the crop book "
        "against the wind. @S@'If you need the village, start at "
        "the green. The keep road is private beyond the outer yard.'");
    addTopic("the water turns", "@S@'The mill and the lower gardens "
        "share the brook. We write down each turn so a dry week "
        "does not become a quarrel at harvest.'");
    addResponse("first conversation", "What grows on the estate?",
        "@S@'Grain, kitchen crops, and the orchard fruit. The "
        "household stores some and sends the contracted share "
        "toward the city.'");
    addResponse("first conversation", "How is the brook divided?",
        "@S@'The mill and the lower gardens share it by a recorded "
        "turn, agreed before the dry weeks begin.'");
    addResponseTopic("first conversation", "How is the brook divided?",
        "the water turns");
    addResponse("the water turns", "Can I gather from the fields?",
        "@S@'The marked tenant garden is worked by the village. "
        "The other fields are under House Aladain's care.'");
}
