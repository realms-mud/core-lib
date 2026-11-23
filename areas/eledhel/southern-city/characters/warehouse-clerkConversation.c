//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Tavrin marks a crate with "
        "chalk, then closes the ledger.");
    addTopic("warehouse tallies", "@S@'Every load is counted before "
        "it is stored. The mark, condition, and owner go in the "
        "ledger, so a missing crate can be traced.'");
    addTopic("cargo damage", "@S@'Damaged cargo is set apart and "
        "reported before it is moved. That protects the owner and "
        "the workers who handle it.'");

    addResponse("first conversation", "How is cargo tracked?",
        "@S@'By its mark and a written tally. I record damage "
        "before the goods leave the quay.'");
    addResponseTopic("first conversation", "How is cargo tracked?",
        "warehouse tallies");
    addResponse("warehouse tallies", "What if a crate is damaged?",
        "@S@'It is separated and reported at once. No one should "
        "have to argue later about when the damage occurred.'");
    addResponseTopic("warehouse tallies",
        "What if a crate is damaged?", "cargo damage");
}
