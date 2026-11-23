//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Othwen sorts a stack of "
        "sailcloth by size. @S@'I am learning to spot a weak seam "
        "before it tears under wind.'");
    addTopic("yard training", "@S@'Master Edril starts with the "
        "materials and the joinery. There is no shortcut around "
        "learning how each part bears the strain.'");

    addResponse("first conversation", "What are you learning?",
        "@D@She gestures toward the rigging on the quay.");
    addResponseTopic("first conversation", "What are you learning?",
        "yard training");
}
