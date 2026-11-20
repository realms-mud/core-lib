//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Edda labels a drying tray "
        "before answering. @S@'The common beds are for gathering. "
        "These beds are closed until I trust their water again.'");
    addTopic("stream briefing", "@S@'The garden sluice runs cloudy. "
        "I will not turn doubtful roots into somebody's remedy.'");
    addTopic("stream route", "@S@'Investigate the garden water "
        "here, the settling ditch north by the quarry lane, and "
        "the clear spring east of the stream. Follow the water "
        "rather than deciding the plants must be cursed.'");
    addTopic("stream accepted", "@D@Edda ties a marker across the "
        "affected bed. @S@'An honest answer is more useful than "
        "a promise of healing.'");
    addTopicEvent("stream accepted", "minlachBeginStream");
    addTopic("stream finding", "@S@'Silt from the blocked ditch, "
        "and clean water above it. We have practical choices.'");
    addTopic("stream repair arranged", "@D@Edda writes to the "
        "foreman. @S@'The ditch gets repaired; these roots remain withheld.'");
    addTopicEvent("stream repair arranged", "arrangeDitchRepair");
    addTopic("stream supply arranged", "@S@'Spring deliveries "
        "will keep the nursery supplied while the affected beds rest.'");
    addTopicEvent("stream supply arranged", "arrangeCleanWater");
    addResponse("first conversation", "What is wrong with the garden?",
        "@D@You ask about the closed beds.");
    addResponseTopic("first conversation", "What is wrong with the garden?",
        "stream briefing");
    addResponse("stream briefing", "Where does the water come from?",
        "@D@You ask to trace the sluice.");
    addResponseTopic("stream briefing", "Where does the water come from?",
        "stream route");
    addResponse("stream briefing", "Can the plants cure the problem?",
        "@S@'No plant cures a blocked drain. Find the cause first.'");
    addResponseTopic("stream briefing", "Can the plants cure the problem?",
        "stream route");
    addResponse("stream route", "I will trace the water.",
        "@D@You agree to inspect the garden, ditch, and spring.");
    addResponseTopic("stream route", "I will trace the water.",
        "stream accepted");
    addResponse("stream route", "I will return later.",
        "@D@Edda leaves the affected trays clearly marked.");
    addResponse("first conversation", "I found the source of the cloudy water.",
        "@D@You report the diverted runoff and clean upper spring.");
    gateQuestResponse("first conversation",
        "I found the source of the cloudy water.", "roots-by-the-stream", "ready");
    addResponseTopic("first conversation",
        "I found the source of the cloudy water.", "stream finding");
    addResponse("stream finding", "Arrange repairs with the quarry crew.",
        "@D@You recommend fixing the source.");
    addResponseTopic("stream finding", "Arrange repairs with the quarry crew.",
        "stream repair arranged");
    addResponse("stream finding", "Arrange clean spring water for now.",
        "@D@You recommend a temporary supply while repairs are organized.");
    addResponseTopic("stream finding", "Arrange clean spring water for now.",
        "stream supply arranged");
}
