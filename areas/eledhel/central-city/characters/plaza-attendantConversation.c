//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Galeth brushes grit from "
        "a bench. @S@'The square belongs to everyone who needs "
        "to cross it or rest for a moment.'");
    addTopic("public square", "@S@'People come through on their "
        "way to the offices, the temple, and the shops. I try to "
        "keep a little room for each.'");
    addResponse("first conversation", "What is your work here?",
        "@D@He indicates the row of benches.");
    addResponseTopic("first conversation", "What is your work here?",
        "public square");
}
