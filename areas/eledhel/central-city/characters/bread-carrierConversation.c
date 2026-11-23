//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Selwen settles a cloth over "
        "her basket. @S@'The loaves keep better if I do not let the "
        "dust in.'");
    addTopic("fresh bread", "@S@'I carry only what the baker finished "
        "recently. The shops can ask for more if their shelves empty.'");
    addResponse("first conversation", "What is in the basket?",
        "@D@She lifts the cloth enough to show the warm loaves.");
    addResponseTopic("first conversation", "What is in the basket?",
        "fresh bread");
}
