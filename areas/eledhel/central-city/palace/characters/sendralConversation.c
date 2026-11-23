//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Sendral gives you a courteous "
        "nod. @S@'The household has many duties. If you have business "
        "with the crown, I can explain where to begin.'");
    addTopic("household", "@S@'The chamberlain keeps the appointments "
        "and the scribe keeps the records. I see that the household "
        "and its doors are properly attended.'");
    addTopic("old passages", "@S@'The palace has older passages, "
        "but they are not public routes. Leave closed doors alone "
        "and speak to the household if you have a proper concern.'");
    addTopic("escape route", "@D@Sendral studies you for a moment. "
        "@S@'If you must leave unseen, I can show you one of the "
        "old royal ways. The route is dangerous and must remain "
        "unknown to those who would misuse it.'");
    addTopicEvent("escape route", "beginEledhelEscape");

    addResponse("first conversation", "Who can receive a petition?",
        "@D@He gestures toward the reception rooms.");
    addResponseTopic("first conversation",
        "Who can receive a petition?", "household");
    addResponse("first conversation", "Are there other ways through?",
        "@S@'Not for visitors. The household passages are kept "
        "closed unless duty requires otherwise.'");
    addResponseTopic("first conversation",
        "Are there other ways through?", "old passages");
    addResponse("old passages", "I need to leave the city unseen.",
        "@D@Sendral weighs the request before answering.");
    addResponseTopic("old passages", "I need to leave the city unseen.",
        "escape route");
    addResponse("household", "Who should I ask about an appointment?",
        "@S@'Tiriel manages the household's appointments. "
        "I can direct you to her.'");
}
