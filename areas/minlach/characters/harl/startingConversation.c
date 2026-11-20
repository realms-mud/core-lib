//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Harl touches a chalk mark "
        "on his slate. @S@'Nobody goes below that water line. "
        "There is enough trouble above it.'");
    addTopic("quarry briefing", "@S@'An old adit flooded. The "
        "upper refuge needs a recovery route checked before "
        "I send people in. This is not treasure hunting.'");
    addTopic("quarry route", "@S@'Investigate the adit watermark "
        "east of here, the upper props above it, and the crew "
        "refuge slate. Stay in the marked upper passage.'");
    addTopic("quarry accepted", "@D@Harl traces the upper route. "
        "@S@'Report the bad supports as carefully as the sound ones.'");
    addTopicEvent("quarry accepted", "minlachBeginQuarry");
    addTopic("quarry finding", "@S@'An upper approach, with the "
        "lower gallery closed. That gives the recovery crew "
        "a route and a firm limit.'");
    addTopic("quarry recovery sent", "@D@Harl calls to his crew "
        "and marks the lower entrance closed. @S@'Trained workers, "
        "by the upper route only.'");
    addTopicEvent("quarry recovery sent", "sendQuarryRecovery");
    addTopic("quarry support requested", "@S@'I will ask the "
        "watch for support and keep a warning posted at the adit.'");
    addTopicEvent("quarry support requested", "requestQuarrySupport");
    addResponse("first conversation", "What happened in the workings?",
        "@D@You ask about the water mark on his slate.");
    addResponseTopic("first conversation", "What happened in the workings?",
        "quarry briefing");
    addResponse("quarry briefing", "Which route is safe to survey?",
        "@D@You ask for the upper passage rather than the flooded gallery.");
    addResponseTopic("quarry briefing", "Which route is safe to survey?",
        "quarry route");
    addResponse("quarry briefing", "Could we pull out the lower props?",
        "@D@Harl shakes his head sharply. @S@'Not without an "
        "engineer's plan. Do not trade a flooded working for a collapse.'");
    addResponseTopic("quarry briefing", "Could we pull out the lower props?",
        "quarry route");
    addResponse("quarry route", "I will survey the upper approach.",
        "@D@You agree to check the marks and crew slate.");
    addResponseTopic("quarry route", "I will survey the upper approach.",
        "quarry accepted");
    addResponse("quarry route", "I cannot take the survey now.",
        "@D@Harl keeps the entrance warning in place.");
    addResponse("first conversation", "I checked the upper recovery route.",
        "@D@You report the water mark, props, and refuge plan.");
    gateQuestResponse("first conversation", "I checked the upper recovery route.",
        "flooded-workings", "ready");
    addResponseTopic("first conversation", "I checked the upper recovery route.",
        "quarry finding");
    addResponse("quarry finding", "Send the trained quarry crew.",
        "@D@You recommend a recovery confined to the upper approach.");
    addResponseTopic("quarry finding", "Send the trained quarry crew.",
        "quarry recovery sent");
    addResponse("quarry finding", "Request watch support too.",
        "@D@You recommend assistance and a clearly closed lower entrance.");
    addResponseTopic("quarry finding", "Request watch support too.",
        "quarry support requested");
}
