//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Olyne checks a note before "
        "the fitting begins. @S@'I am here to have a work coat "
        "adjusted before the next council sitting.'");
    addTopic("work clothes", "@S@'The sleeves catch when I reach "
        "for a ledger. Selyra is checking the fit so I can work "
        "without worrying about the seams.'");

    addResponse("first conversation", "What are you having made?",
        "@D@She folds the note and waits for her turn.");
    addResponseTopic("first conversation", "What are you having made?",
        "work clothes");
}
