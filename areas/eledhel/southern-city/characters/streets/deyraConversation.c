//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Deyra folds the household list "
        "into her pocket. @S@'I have the staples for the week.'");
    addTopic("household goods", "@S@'I buy ordinary goods in small "
        "amounts. There is less to carry and less to spoil.'");
    addResponse("first conversation", "What did you need today?",
        "@D@She checks the parcels in her basket.");
    addResponseTopic("first conversation", "What did you need today?",
        "household goods");
}
