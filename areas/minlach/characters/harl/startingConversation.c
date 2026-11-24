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
    addTopic("seam briefing", "@D@Harl turns his slate over and says, "
        "@S@'A narrow copper seam has shown in the old forest workings. "
        "The roof was never cleared after the fall, so I will not send "
        "anyone in on a guess.'");
    addTopic("seam location", "@S@'Copper Hollow is north of the old "
        "waykeeper's trail, beyond the split creek. The ruined chapel "
        "nearby has the old maintenance register.'");
    addTopic("seam accepted", "@D@Harl marks the cave and chapel on your "
        "map. @S@'Check the spring, the seam, the roof props, and that "
        "register. "
        "Do not enter the lower gallery.'");
    addTopicEvent("seam accepted", "minlachBeginSeam");
    addTopic("seam finding", "@D@Harl studies your notes and says, "
        "@S@'A poor vein, a standing roof with shifted props, and a "
        "record that no house claimed it. The lower gallery stays shut.'");
    addTopic("seam closed", "@D@Harl adds a clear warning to his slate. "
        "@S@'The lower adit stays sealed. The exposed face above it may "
        "be worked with a pick, but nobody goes below the warning line.'");
    addTopicEvent("seam closed", "keepSeamClosed");
    addTopic("seam survey", "@D@Harl marks the approach and says, "
        "@S@'I will allow a small, supervised harvest from the exposed "
        "seam. No descent into the old gallery.'");
    addTopicEvent("seam survey", "allowLimitedSurvey");
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
    addResponse("first conversation", "Is there work beyond the old adit?",
        "@D@You ask about the seam marked on his slate.");
    addResponseTopic("first conversation", "Is there work beyond the old adit?",
        "seam briefing");
    addResponse("seam briefing", "Where is Copper Hollow?",
        "@D@You ask Harl to mark the approach and the old chapel.");
    addResponseTopic("seam briefing", "Where is Copper Hollow?",
        "seam location");
    addResponse("seam briefing", "Why not reopen the workings?",
        "@D@Harl shakes his head and says, @S@'The seam is small. "
        "A collapse would cost more than the copper is worth.'");
    addResponseTopic("seam briefing", "Why not reopen the workings?",
        "seam location");
    addResponse("seam location", "I will inspect the seam and the old record.",
        "@D@You agree to make the survey without entering the lower gallery.");
    addResponseTopic("seam location",
        "I will inspect the seam and the old record.", "seam accepted");
    addResponse("first conversation", "I surveyed Copper Hollow.",
        "@D@You report the seam, the shifted props, and the chapel register.");
    gateQuestResponse("first conversation", "I surveyed Copper Hollow.",
        "safe-seam", "ready");
    addResponseTopic("first conversation", "I surveyed Copper Hollow.",
        "seam finding");
    addResponse("seam finding", "Keep the adit closed.",
        "@D@You recommend leaving the old workings undisturbed.");
    addResponseTopic("seam finding", "Keep the adit closed.", "seam closed");
    addResponse("seam finding", "Allow a supervised surface survey.",
        "@D@You recommend a limited extraction from the exposed face, "
        "without descending.");
    addResponseTopic("seam finding", "Allow a supervised surface survey.",
        "seam survey");
}
