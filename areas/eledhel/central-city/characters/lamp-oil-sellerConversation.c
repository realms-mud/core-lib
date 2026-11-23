//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Yalwen checks the stoppers "
        "in a crate. @S@'I would rather sell one less flask than "
        "clean oil from the street.'");
    addTopic("lamplight", "@S@'Householders bring their own lamps. "
        "The street fittings belong to the city and are tended by "
        "its workers.'");
    addResponse("first conversation", "Who buys the oil?",
        "@D@She settles the crate on a folded cloth.");
    addResponseTopic("first conversation", "Who buys the oil?",
        "lamplight");
}
