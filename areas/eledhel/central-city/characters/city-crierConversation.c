//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@The crier checks the notices "
        "before speaking. @S@'The plaza is a good place to learn "
        "where the city's public doors lead.'");
    addTopic("the plaza", "@S@'The palace is east. The streets "
        "north and south lead around the square, and the notice "
        "board carries public announcements.'");
    addTopic("the institutions", "@S@'The Aegis academy has a "
        "practice yard to the west. The Werric outpost stands "
        "north of the plaza.'");

    addResponse("first conversation", "Where is the palace?",
        "@D@The crier points across the square.");
    addResponseTopic("first conversation", "Where is the palace?",
        "the plaza");
    addResponse("first conversation", "Where can I find training?",
        "@D@He turns toward the western street.");
    addResponseTopic("first conversation", "Where can I find training?",
        "the institutions");
    addResponse("the plaza", "Where are public notices posted?",
        "@S@'On the board beside the benches. I repeat important "
        "announcements here when people gather.'");
}
