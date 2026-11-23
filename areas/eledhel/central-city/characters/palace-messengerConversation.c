//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Selenel checks that the "
        "wax on her message is intact. @S@'I have a delivery for "
        "the palace staff, not a story to tell in the street.'");
    addTopic("palace service", "@S@'Most work is ordinary: carry "
        "a note, wait for a reply, and make sure the right person "
        "receives it.'");
    addResponse("first conversation", "Do you work at the palace?",
        "@D@She keeps the sealed message close.");
    addResponseTopic("first conversation", "Do you work at the palace?",
        "palace service");
}
