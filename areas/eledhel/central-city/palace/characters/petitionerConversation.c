//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@The petitioner folds her paper "
        "again, keeping it carefully in both hands. @S@'I am waiting "
        "for someone to hear my request.'");
    addTopic("petition", "@S@'I wrote down what happened and what "
        "I hope the court can do. The scribe told me to be clear "
        "and patient.'");
    addTopic("the wait", "@S@'There are other people with matters "
        "to bring. I would rather wait my turn than lose my place "
        "by making a scene.'");

    addResponse("first conversation", "What is your petition about?",
        "@D@She keeps the page folded and does not offer it to you.");
    addResponseTopic("first conversation", "What is your petition about?",
        "petition");
    addResponse("first conversation", "Have you been waiting long?",
        "@D@She glances toward the inner door.");
    addResponseTopic("first conversation", "Have you been waiting long?",
        "the wait");
    addResponse("petition", "Did the scribe help you?",
        "@S@'She explained where it should go. The request itself "
        "has to be mine.'");
}
