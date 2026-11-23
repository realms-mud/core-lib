//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Calven checks a tally against "
        "the crates. @S@'The stores belong to the harbor crews. "
        "If you need provisions for a voyage, ask the stall on the pier.'");
    addTopic("stores", "@S@'I record what comes in and what goes out. "
        "A crew gets what is assigned to its vessel; a loose crate "
        "is not free cargo.'");
    addTopic("cargo records", "@S@'The tally lets us trace a missing "
        "supply without blaming the first person who walks past.'");

    addResponse("first conversation", "Can I buy supplies here?",
        "@S@'No. These stores serve the watch and assigned ships. "
        "Taviel sells provisions at the pier.'");
    addResponse("first conversation", "How do you track the cargo?",
        "@D@He turns the tally board so you can see the columns.");
    addResponseTopic("first conversation",
        "How do you track the cargo?", "cargo records");
    addResponse("cargo records", "What if a crate is missing?",
        "@S@'I compare the marks and ask the people who handled it. "
        "A missing entry is a question, not proof of theft.'");
    addResponseTopic("cargo records", "What if a crate is missing?",
        "stores");
}
