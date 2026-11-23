//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Aedran tests the line against "
        "his weight. @S@'This one can take the strain.'");
    addTopic("rigging", "@S@'We check every replacement rope before "
        "it goes aloft. A frayed line is no use to a sailing crew.'");
    addResponse("first conversation", "How do you test the line?",
        "@D@He pulls the rope taut once more.");
    addResponseTopic("first conversation", "How do you test the line?",
        "rigging");
}
