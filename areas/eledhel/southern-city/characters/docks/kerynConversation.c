//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Keryn coils a line beside the "
        "skiff. @S@'The berth is clear for a short trip.'");
    addTopic("skiff berths", "@S@'Small craft use the sheltered berths. "
        "The larger ships need deeper water beyond the quay.'");
    addResponse("first conversation", "Where can the skiff go?",
        "@D@She points across the harbor.");
    addResponseTopic("first conversation", "Where can the skiff go?",
        "skiff berths");
}
