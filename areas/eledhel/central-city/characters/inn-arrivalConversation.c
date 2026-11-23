//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Anwen studies the street "
        "signs and shakes the dust from her cloak. @S@'I know the "
        "road ends here. I am finding where to rest.'");
    addTopic("lodging", "@S@'I would rather pay for a plain room "
        "than sleep beside a loaded cart. The innkeeper can tell "
        "me what is available.'");
    addResponse("first conversation", "Have you found a room?",
        "@D@She looks toward the inn doors.");
    addResponseTopic("first conversation", "Have you found a room?",
        "lodging");
}
