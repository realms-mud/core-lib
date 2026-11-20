//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("the squad", "@D@Galadhel listens as Berenar explains "
        "the squad's duties. @S@'A leader does not need to be the "
        "best archer, scout, or swordsman. The leader must know "
        "when to let each of us do our work.'");
    addTopic("shared responsibility", "@S@'When one of us makes "
        "a mistake, the whole squad must learn from it. That does "
        "not erase individual responsibility; it keeps blame from "
        "becoming an excuse to abandon one another.'");
    addTopicInterjection("shared responsibility",
        "/areas/tol-dhurath/characters/halgaladh/halgaladh.c",
        "the Aegis unit", 1);
    addTopic("Tinwen scouts", "@D@Galadhel glances at the raven "
        "on her shoulder. @S@'Tinwen has a better view from above, "
        "but I will not send her into danger without considering "
        "what may be waiting in the sky.'");
    addTopic("the new mission", "@S@'We are escorting Kierwen "
        "to Alpine and then helping against Vargath's stronghold. "
        "We need to listen to our allies and stay ready for a change "
        "of orders.'");

    addResponse("the squad", "Should I take command?",
        "@S@'Take responsibility when the moment needs you. "
        "The rest of us should support the person best suited "
        "to the task at hand.'");
    addResponseTopic("the squad", "Should I take command?",
        "shared responsibility");
    addResponse("the squad", "What if someone questions an order?",
        "@S@'A concern should be spoken quickly and clearly. "
        "Once the decision is made, we act together.'");
    addResponseTopic("the squad", "What if someone questions an order?",
        "shared responsibility");

    addResponse("shared responsibility", "How do we correct a mistake?",
        "@S@'Talk to the person honestly, away from those who "
        "do not need to hear it. Protect the squad and be fair.'");
    addResponse("shared responsibility", "What do you need from me?",
        "@S@'Tell us what you see, listen when we have something "
        "to add, and do not leave anyone to face danger alone.'");

    addResponse("the new mission", "Should Tinwen scout ahead?",
        "@S@'Only if we agree the risk is worth it. She is our "
        "friend, not a tool to spend carelessly.'");
    addResponseTopic("the new mission", "Should Tinwen scout ahead?",
        "Tinwen scouts");
    addResponse("the new mission", "Why is Kierwen coming?",
        "@S@'She has faced these enemies and has a right to help "
        "her family. We will make room for her in the squad.'");
    addResponse("Tinwen scouts", "What if she is spotted?",
        "@S@'Then we change our plan. No piece of information is "
        "worth pretending that her safety does not matter.'");
}
