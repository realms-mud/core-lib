//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Ilden braces one foot "
        "against the boat ramp and tests a plank with his heel. "
        "@S@'If you are here to admire the boat, stand on the "
        "landward side. If you are here to hire it, tell me "
        "where you mean to go.'");
    addTopic("the boats", "@S@'The rowboat is for the inner "
        "shore. I will not take it past the outer rocks. A "
        "proper sea boat needs a crew, a sound mast, and someone "
        "who knows when to come home.'");
    addTopic("the catch", "@S@'The catch changes with the "
        "current. We keep the small fish for the smokehouse and "
        "send the good salt catch south before it spoils. The "
        "market takes more than the sea does.'");
    addTopic("your finger", "@D@He flexes the shortened finger "
        "and gives a quiet shrug. @S@'A split oar under load. "
        "I had a hand on the wrong side of it. I teach apprentices "
        "that story before I let them touch a boat.'");
    addTopic("the north coast", "@S@'The coves look close together "
        "from the ridge. On foot they are cut off by cliffs and "
        "tide pools. A stranded skiff can sit there for half a "
        "day before anyone can reach it.'");
    addTopic("the apprentices", "@S@'Two children help me after "
        "the morning tide. They argue about knots and agree "
        "about everything else. I let them argue; a rope that "
        "fails will settle it soon enough.'");

    addResponse("first conversation", "Can I hire the rowboat?",
        "@D@Ilden checks the tide beyond the boat shed. "
        "@S@'Not alone, and not into a rising tide. If you need "
        "to cross the sheltered inlet, I will come with you "
        "when the weather clears.'");
    addResponseTopic("first conversation", "Can I hire the rowboat?",
        "the boats");
    addResponse("the boats", "Why not go farther along the coast?",
        "@D@He gives the outer rocks a weathered look. "
        "@S@'Because I like my boats in one piece and my crew "
        "alive. The outer rocks are not a challenge. They are "
        "a warning.'");
    addResponse("first conversation", "What fish do you catch?",
        "@D@Ilden scans the water for a change in its color. "
        "@S@'Whatever the current brings close enough to shore. "
        "If I name a species, the next tide will prove me wrong.'");
    addResponseTopic("first conversation", "What fish do you catch?",
        "the catch");
    addResponse("first conversation", "How did you lose your finger?",
        "@D@He turns the shortened finger over in his hand. "
        "@S@'A bad grip and a split oar. I was younger than the "
        "boat and thought that meant I was stronger.'");
    addResponseTopic("first conversation",
        "How did you lose your finger?", "your finger");
    addResponse("first conversation", "What lies beyond the coves?",
        "@D@Ilden points past the headland. "
        "@S@'More coast, more wind, and a long stretch where "
        "you cannot see a roof. Take food and a second dry "
        "layer if you mean to go.'");
    addResponseTopic("first conversation", "What lies beyond the coves?",
        "the north coast");
    addResponse("the apprentices", "Will they inherit your boat?",
        "@D@He runs a hand along the repaired gunwale. "
        "@S@'They will build their own. Mine has my mistakes "
        "worked into it, and those are mine to keep.'");
    addResponse("the catch", "Why salt the fish before selling?",
        "@D@Ilden gestures toward the smokehouse racks. "
        "@S@'The southern market is a long walk. Salt buys time "
        "and pays for the next net.'");
    addResponse("the north coast", "Have you seen a stranded skiff?",
        "@D@He shades his eyes and looks along the cliffs. "
        "@S@'A blue one last month. Empty, with a split bow. "
        "We tied it above the tide line and left the owner a "
        "note at the outpost.'");
}
