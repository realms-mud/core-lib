//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Renveth sets down a worn practice "
        "blade. @S@'I live here in Minlach. I am studying the Scions of "
        "Dhuras, though I never belonged to them. The order has been gone "
        "for generations.'");
    addTopic("the Scions", "@S@'They were warrior-scholars: disciplined "
        "with weapons, and careful with magic. Their halls in the southern "
        "city are abandoned. I will not claim their name until there is "
        "an order to inherit.'");
    addTopic("the release", "@D@Renveth listens as you describe freeing "
        "the prisoner beneath Tol-Dhurath. His attention turns to the "
        "history book. @S@'Then the old warning is no longer enough. "
        "Someone must rebuild the order to face what comes next.'");
    addTopicEvent("the release", "tolDhurathReleaseReported");

    addResponse("first conversation", "What are you studying?",
        "@D@You ask about the histories spread across his table.");
    addResponseTopic("first conversation", "What are you studying?",
        "the Scions");
    addResponse("first conversation", "Why study a vanished order?",
        "@S@'Their fall is a warning, and their discipline may be useful "
        "again. The history book in the household archive explains both.'");
    addResponse("first conversation",
        "Bring Renveth the Scions' history book.",
        "@D@You offer Renveth the history book.");
    addResponseEffect("first conversation",
        "Bring Renveth the Scions' history book.",
        (["receive":"/areas/items/books/scions-of-dhuras.c"]));
    addResponse("first conversation",
        "I freed the prisoner beneath Tol-Dhurath.",
        "@D@You tell Renveth what happened beneath the ruins.");
    addResponsePrerequisite("first conversation",
        "I freed the prisoner beneath Tol-Dhurath.", ([
            "/areas/tol-dhurath/state-machine/tol-dhurath-quest.c":([
                "type":"quest"
            ])
        ]));
    addResponseTopic("first conversation",
        "I freed the prisoner beneath Tol-Dhurath.", "the release");
    addConditionalTopicAddendum("first conversation", "restored order", ([
        "/areas/minlach/quests/scions-restoration.c":([
            "type":"quest"
        ])
    ]), " @D@Renveth has taken responsibility as the first master of the "
        "renewed Scions of Dhuras.");
}
