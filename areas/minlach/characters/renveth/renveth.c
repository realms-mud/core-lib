//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Renveth");
    short("Renveth, a Minlach resident");
    description("Renveth keeps a practice blade beside a stack of copied "
        "histories. He is neither a Scion nor the heir to one; he has spent "
        "years studying the order's surviving records and training on his "
        "own.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 5);
    addConversation(
        "/areas/minlach/characters/renveth/startingConversation.c");
    registerEvent(load_object(
        "/areas/minlach/quests/scions-restoration-events.c"));
}

/////////////////////////////////////////////////////////////////////////////
public void onGiftReceived(object giver, object item)
{
    string questPath = "/areas/minlach/quests/scions-restoration.c";

    if (objectp(giver) && objectp(item) &&
        program_name(item) == "/areas/items/books/scions-of-dhuras.c" &&
        function_exists("questIsActive", giver) &&
        giver->questIsActive(questPath))
    {
        if (load_object(questPath)->receiveEvent(giver, "scionsBookGiven"))
        {
            tell_object(giver, "Renveth opens the history book and accepts "
                "the work of restoring the Scions.\n");
        }
    }
}
