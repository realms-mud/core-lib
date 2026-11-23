//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Korin folds the shopping "
        "list and smiles. @S@'I cook for a household near the "
        "palace road. Fresh roots save me a trip across town.'");
    addTopic("provisions", "@S@'There is room for specialists "
        "and for counters like this one. The market cannot be "
        "the only place to buy supper.'");

    addResponse("first conversation", "Why shop here?",
        "@D@He checks the list once more.");
    addResponseTopic("first conversation", "Why shop here?",
        "provisions");
}
