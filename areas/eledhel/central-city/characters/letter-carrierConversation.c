//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Caranor checks each address "
        "before tucking a letter away. @S@'A familiar street is no "
        "excuse to leave a note at the wrong door.'");
    addTopic("letters", "@S@'Most carry ordinary news. I keep the "
        "sealed ones separate and make sure they reach the named hand.'");
    addResponse("first conversation", "Do you carry many letters?",
        "@D@He gathers the bundle under his arm.");
    addResponseTopic("first conversation", "Do you carry many letters?",
        "letters");
}
