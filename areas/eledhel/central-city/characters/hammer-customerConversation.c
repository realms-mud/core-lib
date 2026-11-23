//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Aelion holds the old hammer "
        "at arm's length. @S@'It served me well, but I will not swing "
        "it with that head moving.'");
    addTopic("stonework", "@S@'I dress stone for doorways and "
        "foundations. The tools take a beating, but a careful mason "
        "does not ask a cracked haft to last forever.'");
    addResponse("first conversation", "What work do you do?",
        "@D@He brushes pale dust from his sleeves.");
    addResponseTopic("first conversation", "What work do you do?",
        "stonework");
}
