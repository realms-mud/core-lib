//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Maerin wipes the counter "
        "before welcoming you.");
    addTopic("rooms and meals", "@S@'There is a bed for the night "
        "and a warm meal when the kitchen is open. If you have an "
        "early start, tell me before you turn in.'");
    addTopic("city news", "@S@'People come through from every "
        "quarter. I listen, but I do not sell rumor as fact.'");

    addResponse("first conversation", "Can I stay here?",
        "@S@'Ask me about a room and how long you plan to stay.'");
    addResponseTopic("first conversation", "Can I stay here?",
        "rooms and meals");
    addResponse("first conversation", "Do you hear much news?",
        "@S@'A little. Tell me what you are looking for and I may "
        "know who can answer.'");
    addResponseTopic("first conversation", "Do you hear much news?",
        "city news");
}
