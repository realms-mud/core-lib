//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Pethren checks the list "
        "in his hand. @S@'I am picking up food and water before "
        "the next watch begins.'");
    addTopic("harbor watch", "@S@'A watch is easier when the crew "
        "has eaten and the water casks are full. The foreman "
        "keeps the loading order sensible.'");

    addResponse("first conversation", "Are you sailing soon?",
        "@D@He folds the list and looks toward the quay.");
    addResponseTopic("first conversation", "Are you sailing soon?",
        "harbor watch");
}
