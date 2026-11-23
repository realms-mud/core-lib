//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Zoran studies a route note. "
        "@S@'I have the right turn this time.'");
    addTopic("inn directions", "@S@'Follow the busy street toward the "
        "harbor, then ask at the inn if you need a room.'");
    addResponse("first conversation", "Where are you headed?",
        "@D@He folds the note along its old crease.");
    addResponseTopic("first conversation", "Where are you headed?",
        "inn directions");
}
