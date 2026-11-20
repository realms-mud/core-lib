//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Vessa lifts her veil "
        "clear of her mouth. @S@'Speak softly near the active "
        "skeps. The empty stands are another matter; I need to "
        "know what broke them before I set more bees there.'");
    addTopic("the empty stands", "@S@'Three are empty. Two bodies "
        "were crushed where they stood, and the third was dragged "
        "a little way. I found wax and straw, not a cut strap or "
        "a wheel mark.'");
    addTopic("the ravine", "@D@She touches the gouges on a splinter. "
        "@S@'The binding was torn by something strong. The marks "
        "point toward the creek hollow, where bears sometimes "
        "come down to drink. That is a lead, not proof.'");
    addTopic("the active skeps", "@S@'Do not lift a lid or smoke "
        "a hive without my leave. A frightened swarm can kill "
        "bees and people alike. I sell measured comb when it is "
        "ready.'");

    addResponse("first conversation", "What are you looking for?",
        "@D@You point to the empty hive stands.");
    addResponseTopic("first conversation", "What are you looking for?",
        "the empty stands");
    addResponse("the empty stands", "Could thieves have taken them?",
        "@S@'A thief would leave wheel ruts or cut bindings. These "
        "were battered in place, then dragged.'");
    addResponse("the empty stands", "Where did the tracks lead?",
        "@D@You ask where the crushed comb was found.");
    addResponseTopic("the empty stands", "Where did the tracks lead?",
        "the ravine");
    addResponse("first conversation", "May I gather honey?",
        "@D@You glance at the active skeps.");
    addResponseTopic("first conversation", "May I gather honey?",
        "the active skeps");
}
