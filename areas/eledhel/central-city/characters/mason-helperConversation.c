//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Arthen checks a knot in "
        "his measuring line. @S@'A crooked wall begins with one "
        "careless mark.'");
    addTopic("stonework", "@S@'I help set and carry the blocks. "
        "The mason lays the line, and I make sure the next stone "
        "is ready before it is called for.'");
    addResponse("first conversation", "What are you building?",
        "@D@He winds the line around his hand.");
    addResponseTopic("first conversation", "What are you building?",
        "stonework");
}
