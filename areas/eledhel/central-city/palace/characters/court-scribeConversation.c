//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@The scribe checks the labels "
        "on three stacks before answering. @S@'Petitions, household "
        "orders, and council minutes each have their own place.'");
    addTopic("records", "@S@'I keep the record as it was given. "
        "If a page is corrected, the change is marked rather than "
        "quietly written over.'");
    addTopic("petition", "@S@'Write plainly, sign your name, and "
        "state what you are asking for. A clear request is easier "
        "to deliver to the right adviser.'");

    addResponse("first conversation", "Can you help me submit a petition?",
        "@D@You point to the folded papers on the desk.");
    addResponseTopic("first conversation",
        "Can you help me submit a petition?", "petition");
    addResponse("first conversation", "What do these records contain?",
        "@S@'The work of the household: requests, decisions, "
        "and the minutes that preserve what was said.'");
    addResponseTopic("first conversation",
        "What do these records contain?", "records");
    addResponse("petition", "Can you write it for me?",
        "@S@'I can explain the format. The words and the request "
        "must be yours.'");
}
