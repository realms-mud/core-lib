//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Teren clears a place at the "
        "table. @S@'You can sit first and ask questions after. The "
        "road has a way of making both seem urgent.'");
    addTopic("lodging", "@S@'There is a clean room upstairs when one "
        "is free. I keep the rates plain and the common room quiet "
        "after the late meal.'");
    addTopic("trade street", "@S@'Carts pass through all day. Some "
        "carry goods south; others come back looking for a place to "
        "rest before the gates grow busy.'");
    addResponse("first conversation", "Do you have a room?",
        "@D@He points toward the stair.");
    addResponseTopic("first conversation", "Do you have a room?",
        "lodging");
    addResponse("lodging", "Is the street busy?",
        "@D@Teren glances toward the front shutters.");
    addResponseTopic("lodging", "Is the street busy?", "trade street");
}
