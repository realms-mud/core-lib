//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Lord Argalen sets aside the "
        "maps on his study table and gives you his full attention. "
        "@S@'There is no shortage of reports from the roads. I would "
        "rather wait for a careful account than make a decision from "
        "rumor.'");
    addTopic("basil report", "@D@Lord Argalen opens the letter and "
        "points to the route marks. @S@'Basil has measured the forest "
        "waystations, the watch's coverage, and what the town can spare. "
        "He has made no claim on Minlach's stores or people. Go and meet "
        "him before anyone decides what the road requires.'");
    addTopic("dispatch", "@D@Lord Argalen folds the letter and looks "
        "back to you. @S@'Take the northern route to Minlach and speak "
        "with Basil at the watch yard. Bring me the town's own view as "
        "well as his report.'");

    addResponse("first conversation", "What did Basil report?",
        "@D@You ask about the letter from Minlach.");
    addResponsePrerequisite("first conversation", "What did Basil report?",
        ([
            "/areas/tol-dhurath/state-machine/tol-dhurath-quest.c":([
                "type":"quest"
            ])
        ]));
    addResponseTopic("first conversation", "What did Basil report?",
        "basil report");
    addResponse("basil report", "I will go to Minlach and meet Basil.",
        "@D@You agree to hear the surveyor's findings in person.");
    addResponseTopic("basil report",
        "I will go to Minlach and meet Basil.", "dispatch");
}
