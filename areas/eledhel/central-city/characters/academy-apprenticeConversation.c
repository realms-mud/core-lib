//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Gwineth checks the folded "
        "notes in her hands. @S@'I am meant to bring these back "
        "before the next lesson.'");
    addTopic("school day", "@S@'The academy teaches more than "
        "how to hold a weapon. We study discipline, service, and "
        "what to do after a mistake.'");
    addResponse("first conversation", "What are you studying?",
        "@D@She carefully refolds the notes.");
    addResponseTopic("first conversation", "What are you studying?",
        "school day");
}
