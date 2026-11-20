//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Orlen holds a page flat "
        "with two smooth stones. @S@'Names last longer when "
        "someone bothers to write them correctly.'");
    addTopic("tower briefing", "@S@'Salvagers want the old relay "
        "tower's stone. Its cellar records may tell us which "
        "households maintained it. I would save those first.'");
    addTopic("tower route", "@S@'Investigate the relay marker "
        "on the old road, the tower ledger in the cellar farther "
        "north, then the household register here in the archive.'");
    addTopic("tower accepted", "@D@Orlen sets out a clean copying "
        "sheet. @S@'Copy names faithfully. Do not improve them into nobles.'");
    addTopicEvent("tower accepted", "minlachBeginTower");
    addTopic("tower finding", "@S@'Local workers and a common "
        "repair fund. Ordinary names, and worth preserving.'");
    addTopic("tower copies preserved", "@D@Orlen sorts the names "
        "by household. @S@'Copies here, and family entries returned "
        "to the people whose memories they carry.'");
    addTopicEvent("tower copies preserved", "preserveTowerRecords");
    addTopic("tower ownership recorded", "@S@'I will post a "
        "salvage notice. Stone can be reused without losing the records.'");
    addTopicEvent("tower ownership recorded", "recordTowerOwnership");
    addResponse("first conversation", "Do any old records need saving?",
        "@D@You ask about papers outside the town archive.");
    addResponseTopic("first conversation", "Do any old records need saving?",
        "tower briefing");
    addResponse("tower briefing", "Where are the records?",
        "@D@You ask for the route and identifying register.");
    addResponseTopic("tower briefing", "Where are the records?", "tower route");
    addResponse("tower briefing", "Was it a noble fortress?",
        "@S@'A relay tower, until evidence says otherwise. "
        "A grand guess is no substitute for a modest fact.'");
    addResponseTopic("tower briefing", "Was it a noble fortress?", "tower route");
    addResponse("tower route", "I will compare the names.",
        "@D@You agree to trace the records back to local households.");
    addResponseTopic("tower route", "I will compare the names.",
        "tower accepted");
    addResponse("tower route", "I need more time.",
        "@D@Orlen folds the copying sheet for your eventual return.");
    addResponse("first conversation", "I identified the tower's records.",
        "@D@You compare the marker, ledger, and household register.");
    gateQuestResponse("first conversation", "I identified the tower's records.",
        "watchtowers-names", "ready");
    addResponseTopic("first conversation", "I identified the tower's records.",
        "tower finding");
    addResponse("tower finding", "Preserve copies and return family entries.",
        "@D@You recommend both public preservation and family copies.");
    addResponseTopic("tower finding",
        "Preserve copies and return family entries.", "tower copies preserved");
    addResponse("tower finding", "Record ownership before salvage.",
        "@D@You ask for a notice protecting records during dismantling.");
    addResponseTopic("tower finding", "Record ownership before salvage.",
        "tower ownership recorded");
}
