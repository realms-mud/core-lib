//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Selyra pauses beside a "
        "half-finished sleeve. @S@'Welcome. I can help with "
        "clothing for work, travel, or a formal occasion.'");
    addTopic("formal clothing", "@S@'Court clothing should fit "
        "comfortably and move well. Fine trim is no substitute "
        "for careful stitching.'");
    addTopic("fittings", "@S@'The measuring room is through the "
        "east door. I take measurements there before cutting "
        "cloth for a new garment.'");

    addResponse("first conversation", "Do you make formal clothes?",
        "@D@She smooths the cloth on the counter.");
    addResponseTopic("first conversation", "Do you make formal clothes?",
        "formal clothing");
    addResponse("first conversation", "Where do you take measurements?",
        "@D@Selyra gestures toward the room beyond the counter.");
    addResponseTopic("first conversation",
        "Where do you take measurements?", "fittings");
}
