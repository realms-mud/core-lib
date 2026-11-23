//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Rianor checks the ties "
        "around his bundle. @S@'The pieces are sorted by thickness. "
        "That saves the worker time at the bench.'");
    addTopic("leather trade", "@S@'I sell prepared scraps to "
        "craftspeople who need patches and smaller fittings. Good "
        "material should not be wasted.'");
    addResponse("first conversation", "Who buys the scraps?",
        "@D@He turns the bundle so its labels show.");
    addResponseTopic("first conversation", "Who buys the scraps?",
        "leather trade");
}
