//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Sella turns a loaf of bread "
        "over in her hands as she studies you.");
    addTopic("the harbor", "@S@'The harbor brings salt fish, timber, "
        "and news. In winter we see fewer ships, but the road still "
        "keeps the town supplied.'");
    addTopic("the market", "@D@Sella lays the loaf aside and straightens "
        "the cloth over her stall. @S@'I sell what keeps well and "
        "what the town needs. If the boats are late, we make do with "
        "the stores already here.'");
    addTopic("food for travel", "@S@'Hard bread and dried fish will "
        "keep longer than fresh fruit. Wrap them well and keep them "
        "out of the rain.'");
    addTopic("winter stores", "@S@'We set aside grain, dried fish, "
        "and roots before the cold closes the roads. A careful "
        "market keeps a reserve instead of selling everything at once.'");
    addTopic("fair measures", "@S@'A fair measure is the same for "
        "a wealthy customer and a poor one. If a family is short, "
        "we can talk about what they truly need.'");

    addResponse("first conversation", "What can I buy for the road?",
        "@S@'Bread keeps, apples travel well, and the dried fish is "
        "better than it looks.'");
    addResponseTopic("first conversation", "What can I buy for the road?",
        "the harbor");
    addResponse("first conversation", "How long have you had this stall?",
        "@S@'Long enough to know which customers bargain for sport "
        "and which are truly short of coin. I try to be fair to both.'");
    addResponseTopic("first conversation",
        "How long have you had this stall?", "the market");
    addResponse("the harbor", "What if the ships are delayed?",
        "@S@'Then I sell from the stores we have and keep the good "
        "fish for the families who need it most. No one should go "
        "hungry because the wind changed.'");
    addResponseTopic("the harbor", "What if the ships are delayed?",
        "the market");
    addResponse("the market", "What keeps best on the road?",
        "@S@'Dried fish and hard bread. Take a little more than you "
        "think you need, but do not waste it.'");
    addResponseTopic("the market", "What keeps best on the road?",
        "food for travel");
    addResponse("food for travel", "What do you recommend for a long trip?",
        "@S@'Bread, dried fish, and a flask of clean water. If you "
        "can stop at farms along the way, carry less and buy fresh.'");
    addResponse("the harbor", "What happens when the winter ships are late?",
        "@S@'We use what we stored and share out what is left. "
        "The town cannot depend on every ship arriving on time.'");
    addResponseTopic("the harbor",
        "What happens when the winter ships are late?", "winter stores");
    addResponse("winter stores", "Can the market sell its reserve?",
        "@S@'Only when there is need. A reserve is there to keep "
        "people fed through a delay, not to earn a quick coin.'");
    addResponseTopic("winter stores",
        "Can the market sell its reserve?", "fair measures");
    addResponse("the market", "What if someone cannot afford food?",
        "@S@'We find out what they need and help where we can. "
        "No one should be turned away without a conversation.'");
    addResponseTopic("the market",
        "What if someone cannot afford food?", "fair measures");
    addResponse("fair measures", "How can I help?",
        "@S@'Buy what you need, waste nothing, and tell me if "
        "you know of a neighbor who has gone without.'");
    addResponseTopic("fair measures", "How can I help?", "winter stores");

    addTopic("net briefing", "@D@Sella lays down a coil of worn line. "
        "@S@'One fishing household cannot work until its net is "
        "repaired. They think someone cut it; the chandler is less sure.'");
    addResponse("first conversation", "Is there work beyond the market?",
        "@D@You ask about the people supplying her stall.");
    addResponseTopic("first conversation", "Is there work beyond the market?",
        "net briefing");
    addTopic("net route", "@S@'Check the torn net north at the "
        "workyard, the net rack on the shore, then the repair record "
        "at the chandler's. Investigate each before you name a culprit.'");
    addResponse("net briefing", "Where can I inspect the damage?",
        "@D@You ask Sella to mark the three places.");
    addResponseTopic("net briefing", "Where can I inspect the damage?",
        "net route");
    addResponse("net briefing", "Does the family need food now?",
        "@S@'They have a share of the reserve. Help me restore their "
        "livelihood, not merely keep them waiting beside my stall.'");
    addResponseTopic("net briefing", "Does the family need food now?",
        "net route");
    addTopic("net accepted", "@S@'Thank you. I will keep their share "
        "aside while you find out what happened.'");
    addTopicEvent("net accepted", "minlachBeginNet");
    addResponse("net route", "I will inspect the net and records.",
        "@D@You agree to check damage and maintenance together.");
    addResponseTopic("net route", "I will inspect the net and records.",
        "net accepted");
    addResponse("net route", "I cannot take this on yet.",
        "@D@Sella folds the line carefully rather than pressing you.");
    addTopic("net settlement", "@D@Sella works a frayed knot loose. "
        "@S@'Worn lashings and an animal in the rack. A thief is "
        "convenient to blame, but a new line is what they need.'");
    addResponse("first conversation", "I checked the damaged net.",
        "@D@You describe the frayed knots, tracks, and overdue repair.");
    gateQuestResponse("first conversation", "I checked the damaged net.",
        "net-for-winter", "ready");
    addResponseTopic("first conversation", "I checked the damaged net.",
        "net settlement");
    addTopic("net shared repair", "@S@'I will bring the net maker "
        "and family together. Each can contribute without pretending "
        "the damage was somebody else's crime.'");
    addTopicEvent("net shared repair", "arrangeNetRepair");
    addTopic("net replacement credit", "@S@'A replacement against "
        "the next catch, with the amount written plainly. No "
        "ever-growing debt hidden in the small print.'");
    addTopicEvent("net replacement credit", "arrangeNetCredit");
    addResponse("net settlement", "Arrange a shared repair.",
        "@D@You suggest the net maker and household work together.");
    addResponseTopic("net settlement", "Arrange a shared repair.",
        "net shared repair");
    addResponse("net settlement", "Negotiate a replacement on credit.",
        "@D@You propose a written, limited repayment arrangement.");
    addResponseTopic("net settlement", "Negotiate a replacement on credit.",
        "net replacement credit");
}
