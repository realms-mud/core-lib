//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Basil rolls his map closed and "
        "studies you before speaking. @S@'I am here on an Aegis road "
        "survey, working with Minlach's watch. The town decides for "
        "itself what people or stores it can spare.'");
    addTopic("survey briefing", "@D@Basil opens the report copy and "
        "marks three lines on the map. @S@'I need the forest "
        "waystations, the coverage the town watch can actually "
        "provide, and the stores Minlach can spare without leaving its "
        "own people short.'");
    addTopic("survey route", "@D@Basil points first to the forest trail, "
        "then to the watch roster and warehouse account. @S@'Check the "
        "records; do not promise anyone's labor or supplies for them.'");
    addTopic("survey accepted", "@D@Basil marks the three stops on his "
        "map. @S@'Bring back what the records support, even if the answer "
        "is that we must scale the plan down.'");
    addTopicEvent("survey accepted", "minlachBeginRoad");
    addTopic("survey findings", "@D@Basil compares your notes with his "
        "report. @S@'That gives us a workable picture, and leaves the "
        "decision where it belongs: with Minlach and the people doing "
        "the work.'");
    addTopic("repair plan", "@D@Basil annotates a short list of repairs. "
        "@S@'I will ask the town to approve these limited works and "
        "coordinate any local watch support.'");
    addTopicEvent("repair plan", "acceptRoadRepair");
    addTopic("stores reserved", "@D@Basil seals a copy of the account. "
        "@S@'I will keep the stores for Minlach and alter the Aegis "
        "patrol plan before asking for further support.'");
    addTopicEvent("stores reserved", "reserveStores");

    addResponse("first conversation", "Lord Argalen sent me to meet you.",
        "@D@You tell Basil that you have returned from Tol-Dhurath.");
    addResponsePrerequisite("first conversation",
        "Lord Argalen sent me to meet you.", ([
            "/areas/tol-dhurath/state-machine/tol-dhurath-quest.c":([
                "type":"quest"
            ])
        ]));
    addResponseTopic("first conversation",
        "Lord Argalen sent me to meet you.", "survey briefing");
    addResponse("survey briefing", "What should I inspect?",
        "@D@You ask Basil to mark the records and places he needs checked.");
    addResponseTopic("survey briefing", "What should I inspect?",
        "survey route");
    addResponse("survey route", "I will make the assessment.",
        "@D@You agree to check the route, watch, and stores without "
        "committing Minlach to support.");
    addResponseTopic("survey route", "I will make the assessment.",
        "survey accepted");
    addResponse("survey route", "I cannot take this on now.",
        "@D@Basil folds the map and leaves the survey open.");
    addResponse("first conversation", "I completed the road assessment.",
        "@D@You report the waystation, watch, and stores findings.");
    gateQuestResponse("first conversation",
        "I completed the road assessment.", "road-measure", "ready");
    addResponseTopic("first conversation",
        "I completed the road assessment.", "survey findings");
    addResponse("survey findings", "Recommend only limited road repairs.",
        "@D@You recommend a modest plan with local approval and support.");
    addResponseTopic("survey findings", "Recommend only limited road repairs.",
        "repair plan");
    addResponse("survey findings", "Reserve Minlach's stores.",
        "@D@You recommend protecting the town's stores and revising the "
        "Aegis patrol plan.");
    addResponseTopic("survey findings", "Reserve Minlach's stores.",
        "stores reserved");
}
