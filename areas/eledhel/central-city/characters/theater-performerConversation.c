//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Vesra closes her songbook "
        "and listens to the room's echo. @S@'A tune should carry "
        "without making the neighbors regret the walls.'");
    addTopic("road songs", "@S@'Carters bring songs from the "
        "south and sailors bring them from the harbor. I change "
        "the verses so the people here recognize themselves.'");

    addResponse("first conversation", "Where do you find songs?",
        "@D@She opens the book to a page marked with a ribbon.");
    addResponseTopic("first conversation", "Where do you find songs?",
        "road songs");
}
