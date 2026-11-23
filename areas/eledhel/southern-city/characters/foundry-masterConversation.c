//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Bereth studies the work "
        "laid out on a bench before she answers.");
    addTopic("foundry work", "@S@'The foundry takes sound metal "
        "from the smelter and shapes it for tools, fittings, and "
        "the city's repairs.'");
    addTopic("quality checks", "@S@'A piece is checked before it "
        "leaves this shop. If it is flawed, it goes back to the "
        "bench, not into someone's hands.'");

    addResponse("first conversation", "What does the foundry make?",
        "@S@'Useful work for the city: fittings, tools, and "
        "replacement parts made to fit their purpose.'");
    addResponseTopic("first conversation", "What does the foundry make?",
        "foundry work");
    addResponse("foundry work", "How do you check the work?",
        "@S@'By fit, finish, and a careful inspection. The next "
        "person who uses it should not have to guess.'");
    addResponseTopic("foundry work", "How do you check the work?",
        "quality checks");
}
