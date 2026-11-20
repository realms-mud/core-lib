//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Othyl pauses beside the "
        "trough to listen as a cart rolls past. @S@'That one is "
        "sound. The left wheel only complains when it is empty.'");
    addTopic("the yard work", "@S@'I water the teams, check "
        "harness pins, and keep the hand-cart ready. The mill "
        "sends flour here; the farms send it back out as bread.'");
    addTopic("cart wheels", "@D@She points to a pale line in "
        "the dirt. @S@'A wobble leaves paired tracks. A broken "
        "spoke leaves a scrape. Listen first; then look before "
        "you tell a driver to lose half a day.'");
    addTopic("the road", "@S@'The market crossing is south. "
        "Pera is west, and the managed orchard is north of her. "
        "The old cart track bends away beyond the coppice; "
        "that is not a shortcut to Minlach.'");
    addTopic("the horses", "@D@Othyl checks the water level "
        "with the back of her hand. @S@'A thirsty horse gets "
        "water before a long pull. A tired one gets a rest, "
        "not a harder rein.'");

    addResponse("first conversation", "What do you do here?",
        "@D@You ask about the leather thong at her belt.");
    addResponseTopic("first conversation", "What do you do here?",
        "the yard work");
    addResponse("the yard work", "Can I borrow the hand-cart?",
        "@S@'Ask Rethan and leave your name on his slate. "
        "The cart carries grain for several households.'");
    addResponse("first conversation", "How can you tell a wheel is bad?",
        "@D@You ask about the marks in the dirt.");
    addResponseTopic("first conversation", "How can you tell a wheel is bad?",
        "cart wheels");
    addResponse("cart wheels", "Can you repair every wheel?",
        "@S@'I can tighten a pin and bind a cracked rim for "
        "a short journey. A split axle belongs at the city "
        "wheelwright, not on this road.'");
    addResponse("first conversation", "Where does the track north lead?",
        "@D@You ask about the orchard beyond the yard.");
    addResponseTopic("first conversation",
        "Where does the track north lead?", "the road");
    addResponse("first conversation", "May I water my horse?",
        "@D@You ask about the trough.");
    addResponseTopic("first conversation", "May I water my horse?",
        "the horses");
}
