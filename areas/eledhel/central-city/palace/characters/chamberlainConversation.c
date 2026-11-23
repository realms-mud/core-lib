//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Tiriel checks a note against "
        "her appointment book. @S@'The palace is a household as well "
        "as a court. What do you need help finding?'");
    addTopic("appointments", "@S@'I keep requests in order and "
        "pass them to the person who can answer. A place in the book "
        "is not a promise that the king will agree.'");
    addTopic("household stores", "@S@'The staff records what is "
        "needed and what has been issued. Ask before taking anything "
        "from the service rooms.'");

    addResponse("first conversation", "How do I request an audience?",
        "@D@She opens the book to a clean page.");
    addResponseTopic("first conversation",
        "How do I request an audience?", "appointments");
    addResponse("first conversation", "Who manages the palace stores?",
        "@S@'The household keeps a careful account. Tell me what "
        "you need and I will send the request to the proper person.'");
    addResponseTopic("first conversation",
        "Who manages the palace stores?", "household stores");
    addResponse("appointments", "How long will I have to wait?",
        "@S@'That depends on the court's business. I can record "
        "your request, not set the king's day for him.'");
}
