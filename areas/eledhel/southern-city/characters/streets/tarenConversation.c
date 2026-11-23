//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Taren watches a cart turn toward "
        "the harbor. @S@'The road carries more than cargo.'");
    addTopic("old voyages", "@S@'I sailed the southern coast for years. "
        "A calm berth and a sound rope are worth more than fine paint.'");
    addResponse("first conversation", "What do you remember of sailing?",
        "@D@He smiles at the sound of the rigging.");
    addResponseTopic("first conversation", "What do you remember of sailing?",
        "old voyages");
}
