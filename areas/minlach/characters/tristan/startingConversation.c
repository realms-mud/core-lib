//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Tristan closes his notebook and "
        "gives you a measured look.");
    addTopic("the town", "@S@'Minlach keeps its gates watched and its "
        "harbor busy. The militia handles the walls; the constable's "
        "office hears the townsfolk.'");
    addTopic("the watch", "@D@Tristan folds his hands over the "
        "notebook. @S@'A watch is not only the people carrying "
        "weapons. It is the baker who reports a broken latch, the "
        "sailor who notices an unfamiliar boat, and the neighbor "
        "who checks on someone who has not been seen.'");
    addTopic("reporting trouble", "@S@'Tell me what you saw, where "
        "you saw it, and when. Do not follow a suspect or embellish "
        "the account. A clear report is more useful than a brave "
        "story.'");
    addTopic("checking evidence", "@S@'Keep to what you observed. "
        "A mark in the mud may be useful; a guess about who left it "
        "is not evidence until we have more to go on.'");
    addTopic("keeping the peace", "@S@'Listen to both sides before "
        "you decide what happened. A uniform does not make a person "
        "right, and an angry voice does not make one wrong.'");

    addResponse("first conversation", "What should a visitor know?",
        "@S@'Keep to the roads after dark and leave the harbor stores "
        "alone. If trouble finds you, come here before you answer it.'");
    addResponseTopic("first conversation", "What should a visitor know?",
        "the town");
    addResponse("first conversation", "How do I report a crime?",
        "@S@'Start with what happened. I will ask the questions "
        "needed to make a proper report.'");
    addResponseTopic("first conversation", "How do I report a crime?",
        "reporting trouble");
    addResponse("first conversation", "Are the gates safe?",
        "@S@'The gates are watched. That does not make the town "
        "invulnerable, so use the marked roads and tell the watch "
        "about anything unusual.'");
    addResponseTopic("first conversation", "Are the gates safe?",
        "the watch");
    addResponse("the town", "Who patrols the roads?",
        "@S@'The local watch covers the town. The Werric Knights "
        "patrol beyond it when their duties allow. Check with them "
        "before you travel far.'");
    addResponseTopic("the town", "Who patrols the roads?", "the watch");
    addResponse("reporting trouble", "What if I am not certain?",
        "@S@'Say so. We can check a doubtful report; we cannot "
        "correct a confident falsehood after it has caused harm.'");
    addResponse("reporting trouble", "Should I bring proof?",
        "@S@'Bring what you found, but do not disturb a place or "
        "risk yourself to collect more. Tell me where it was.'");
    addResponseTopic("reporting trouble", "Should I bring proof?",
        "checking evidence");
    addResponse("checking evidence", "What if I suspect someone?",
        "@S@'Tell me why, and separate what you saw from what you "
        "believe it means. We will decide what can be checked.'");
    addResponseTopic("checking evidence",
        "What if I suspect someone?", "reporting trouble");
    addResponse("the watch", "How do you handle a dispute?",
        "@S@'We hear each person, keep tempers from rising, and "
        "look for facts we can verify.'");
    addResponseTopic("the watch",
        "How do you handle a dispute?", "keeping the peace");
    addResponse("keeping the peace", "What if both sides are angry?",
        "@S@'Then we give each room to speak without threats. "
        "If someone is in immediate danger, we separate them first.'");
    addResponseTopic("keeping the peace",
        "What if both sides are angry?", "reporting trouble");

    addTopic("witness briefing", "@D@Tristan opens a separate page. "
        "@S@'A traveler has been accused of a warehouse break-in. "
        "The story is confident. The times are not.'");
    addResponse("first conversation", "Do you need evidence checked?",
        "@D@You offer to compare the reports.");
    addResponseTopic("first conversation", "Do you need evidence checked?",
        "witness briefing");
    addTopic("witness route", "@S@'Read the gate statement at the "
        "south gate, inspect the warehouse latch east of the quay, "
        "then read the inn witness account. Use investigate with "
        "those names. Bring contradictions as well as agreements.'");
    addResponse("witness briefing", "Which evidence can I check?",
        "@D@You ask for records and the physical scene.");
    addResponseTopic("witness briefing", "Which evidence can I check?",
        "witness route");
    addResponse("witness briefing", "Why suspect a traveler?",
        "@S@'An unfamiliar face is easy to remember and easier "
        "to blame. It is not sufficient evidence.'");
    addResponseTopic("witness briefing", "Why suspect a traveler?",
        "witness route");
    addTopic("witness accepted", "@S@'Record what each account "
        "actually says. Do not question anyone under threat.'");
    addTopicEvent("witness accepted", "minlachBeginWitness");
    addResponse("witness route", "I will compare the evidence.",
        "@D@You accept the investigation.");
    addResponseTopic("witness route", "I will compare the evidence.",
        "witness accepted");
    addResponse("witness route", "I cannot investigate now.",
        "@D@Tristan closes the page without asking for a guess.");
    addTopic("witness finding", "@D@Tristan compares your notes "
        "with his own. @S@'Those times do not support the accusation. "
        "The outward break raises another question entirely.'");
    addResponse("first conversation", "The break-in evidence contradicts the charge.",
        "@D@You give the gate time, latch damage, and inn account.");
    gateQuestResponse("first conversation",
        "The break-in evidence contradicts the charge.",
        "constables-witness", "ready");
    addResponseTopic("first conversation",
        "The break-in evidence contradicts the charge.", "witness finding");
    addTopic("witness cleared", "@S@'I will correct the accusation "
        "publicly. A private release does not undo public suspicion.'");
    addTopicEvent("witness cleared", "clearAccusedTraveler");
    addTopic("witness inquiry", "@S@'Released, with the incident "
        "still open. We will not replace one unsupported name with another.'");
    addTopicEvent("witness inquiry", "keepWarehouseInquiry");
    addResponse("witness finding", "Clear the traveler publicly.",
        "@D@You ask for a correction as visible as the accusation.");
    addResponseTopic("witness finding", "Clear the traveler publicly.",
        "witness cleared");
    addResponse("witness finding", "Keep investigating the warehouse incident.",
        "@D@You distinguish release from solving the break-in.");
    addResponseTopic("witness finding",
        "Keep investigating the warehouse incident.", "witness inquiry");

    addTopic("courier briefing", "@D@Tristan produces a routing slip. "
        "@S@'A sealed packet meant for our archive went to the "
        "warehouse. Someone changed the destination. Do not break "
        "the seal to satisfy your curiosity.'");
    addResponse("first conversation", "Is there other investigative work?",
        "@D@You ask about the slip beside his notebook.");
    addResponseTopic("first conversation", "Is there other investigative work?",
        "courier briefing");
    addTopic("courier route", "@S@'Check the courier receipt "
        "at the old relay marker, the packet seal in the warehouse, "
        "then the courier register at the archive north of here.'");
    addResponse("courier briefing", "Where did the route go wrong?",
        "@D@You ask where the packet was last correctly recorded.");
    addResponseTopic("courier briefing", "Where did the route go wrong?",
        "courier route");
    addResponse("courier briefing", "Does it concern Tol-Dhurath?",
        "@S@'We do not know its contents. Check its registered "
        "purpose before connecting it to your other affairs.'");
    addResponseTopic("courier briefing", "Does it concern Tol-Dhurath?",
        "courier route");
    addTopic("courier accepted", "@S@'Follow the paperwork. "
        "A routing error is not an excuse to search every traveler.'");
    addTopicEvent("courier accepted", "minlachBeginCourier");
    addResponse("courier route", "I will trace the sealed delivery.",
        "@D@You agree to preserve the seal.");
    addResponseTopic("courier route", "I will trace the sealed delivery.",
        "courier accepted");
    addResponse("courier route", "Leave it with me for another time.",
        "@S@'The packet stays in its store. Return when you can check it.'");
    addTopic("courier finding", "@S@'A local repair assessment, "
        "intact, with the outside routing slip altered. That "
        "narrows the matter considerably.'");
    addResponse("first conversation", "I traced the diverted packet.",
        "@D@You explain the receipt, intact seal, and archive entry.");
    gateQuestResponse("first conversation", "I traced the diverted packet.",
        "couriers-packet", "ready");
    addResponseTopic("first conversation", "I traced the diverted packet.",
        "courier finding");
    addTopic("courier corrected", "@D@Tristan writes the proper "
        "destination. @S@'The archive gets its packet and a corrected record.'");
    addTopicEvent("courier corrected", "correctCourierRoute");
    addTopic("courier inquiry", "@S@'I will keep the false slip "
        "and trace who handled it. Only those who actually handled it.'");
    addTopicEvent("courier inquiry", "investigateCourierRoute");
    addResponse("courier finding", "Correct the delivery.",
        "@D@You recommend restoring the proper route.");
    addResponseTopic("courier finding", "Correct the delivery.",
        "courier corrected");
    addResponse("courier finding", "Investigate the altered slip.",
        "@D@You recommend a narrow inquiry into the diversion.");
    addResponseTopic("courier finding", "Investigate the altered slip.",
        "courier inquiry");
}
