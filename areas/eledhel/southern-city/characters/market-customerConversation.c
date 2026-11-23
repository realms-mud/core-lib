//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Celya checks a list against "
        "the contents of her basket.");
    addTopic("market list", "@S@'I buy what the household will use "
        "before the next market day. Marden is honest about what "
        "will keep and what should be eaten soon.'");

    addResponse("first conversation", "Do you shop here often?",
        "@S@'Every few days. It is easier to plan when the seller "
        "knows what is in season.'");
    addResponseTopic("first conversation", "Do you shop here often?",
        "market list");
}
