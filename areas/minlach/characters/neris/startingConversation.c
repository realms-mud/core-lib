//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Neris closes her signal book "
        "on one finger. @S@'You came by the road? Then at least "
        "you did not have to choose between two harbor lights.'");
    addTopic("beacon briefing", "@S@'A boat followed a light "
        "below our beacon. I want its crew heard before the story "
        "becomes a joke at their expense.'");
    addTopic("beacon route", "@D@She points along the headland. "
        "@S@'Read the beacon log north of the workyards. Follow "
        "the cliff path to the false lantern in the cove, then "
        "check the boat slate on the landing beach. Investigate each.'");
    addTopic("beacon accepted", "@S@'Stay on the marked cliff path. "
        "Do not risk a fall to make the inquiry more impressive.'");
    addTopicEvent("beacon accepted", "minlachBeginBeacon");
    addTopic("beacon finding", "@D@Neris sets the signal book down. "
        "@S@'Coerced unloading, not a foolish crew. Their safety "
        "comes before the next tide's gossip.'");
    addTopic("beacon crew protected", "@S@'I will keep the crew "
        "at the refuge and send their statement privately to Tristan.'");
    addTopicEvent("beacon crew protected", "protectHarborCrew");
    addTopic("beacon inquiry opened", "@S@'I will preserve the "
        "slate and lantern, and open a proper harbor inquiry.'");
    addTopicEvent("beacon inquiry opened", "openHarborInquiry");
    addResponse("first conversation", "What happened to the boat?",
        "@D@You ask about the competing lights.");
    addResponseTopic("first conversation", "What happened to the boat?",
        "beacon briefing");
    addResponse("beacon briefing", "Where can I check the signals?",
        "@D@You ask for the log and the sighting place.");
    addResponseTopic("beacon briefing", "Where can I check the signals?",
        "beacon route");
    addResponse("beacon briefing", "Could the crew be mistaken?",
        "@S@'Of course. That is why we compare the log with "
        "what remains on the shore rather than laugh them away.'");
    addResponseTopic("beacon briefing", "Could the crew be mistaken?",
        "beacon route");
    addResponse("beacon route", "I will follow the evidence.",
        "@D@You agree to check the official and false signals.");
    addResponseTopic("beacon route", "I will follow the evidence.",
        "beacon accepted");
    addResponse("beacon route", "Not until I am prepared.",
        "@D@Neris turns her attention back to the water.");
    addResponse("first conversation", "I found the false signal.",
        "@D@You explain the log, shuttered lantern, and boat slate.");
    gateQuestResponse("first conversation", "I found the false signal.",
        "false-harbor-light", "ready");
    addResponseTopic("first conversation", "I found the false signal.",
        "beacon finding");
    addResponse("beacon finding", "Protect the crew's account first.",
        "@D@You recommend shelter and a private report.");
    addResponseTopic("beacon finding", "Protect the crew's account first.",
        "beacon crew protected");
    addResponse("beacon finding", "Open a formal harbor inquiry.",
        "@D@You recommend preserving the physical evidence.");
    addResponseTopic("beacon finding", "Open a formal harbor inquiry.",
        "beacon inquiry opened");
}
