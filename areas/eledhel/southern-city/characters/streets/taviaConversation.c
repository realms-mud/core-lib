//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Tavia checks the final line on "
        "her shopping list. @S@'I have enough for the household.'");
    addTopic("provisions list", "@S@'I buy flour and dried goods first. "
        "Fresh food comes last so it spends less time in the basket.'");
    addResponse("first conversation", "What do you buy first?",
        "@D@She folds the list and puts it away.");
    addResponseTopic("first conversation", "What do you buy first?",
        "provisions list");
}
