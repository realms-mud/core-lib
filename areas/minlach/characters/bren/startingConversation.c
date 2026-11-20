//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Bren lowers a practice "
        "staff. @S@'A watch needs eyes before it needs another sword.'");
    addTopic("watch briefing", "@S@'I give visitors a short "
        "observation exercise. No oath and no guild enrollment. "
        "You learn what needs a guard and what needs a carpenter.'");
    addTopic("watch route", "@S@'Investigate the gate inspection "
        "board at the south gate, the watch signals here in the "
        "yard, then the supply roster beside them.'");
    addTopic("watch accepted", "@S@'Report only what you can "
        "check. There is no prize for the most alarming story.'");
    addTopicEvent("watch accepted", "minlachBeginWatch");
    addTopic("watch finding", "@D@Bren listens without interrupting. "
        "@S@'A loose latch, a safe assembly signal, and an "
        "unconfirmed rumor. You know the difference. Good.'");
    addTopic("civil watch offered", "@S@'That completes the "
        "exercise. You can help the civil watch without joining an order.'");
    addTopicEvent("civil watch offered", "offerCivilWatch");
    addTopic("watch training requested", "@S@'I will record your "
        "interest. Further training and membership have their own requirements.'");
    addTopicEvent("watch training requested", "requestWatchTraining");
    addResponse("first conversation", "Can a visitor help the watch?",
        "@D@You ask about service without an oath.");
    addResponseTopic("first conversation", "Can a visitor help the watch?",
        "watch briefing");
    addResponse("watch briefing", "What do I need to observe?",
        "@D@You ask for the exercise.");
    addResponseTopic("watch briefing", "What do I need to observe?", "watch route");
    addResponse("watch briefing", "Will this make me a knight?",
        "@S@'No. It may make you a more useful neighbor.'");
    addResponseTopic("watch briefing", "Will this make me a knight?", "watch route");
    addResponse("watch route", "I will check the boards.",
        "@D@You agree to compare the gate, signals, and roster.");
    addResponseTopic("watch route", "I will check the boards.", "watch accepted");
    addResponse("watch route", "Another time.",
        "@D@Bren returns to the recruits without taking offense.");
    addResponse("first conversation", "I completed the observation exercise.",
        "@D@You distinguish repairs, alarms, and unconfirmed reports.");
    gateQuestResponse("first conversation",
        "I completed the observation exercise.", "place-at-the-wall", "ready");
    addResponseTopic("first conversation",
        "I completed the observation exercise.", "watch finding");
    addResponse("watch finding", "Keep this as civil watch service.",
        "@D@You choose service without guild enrollment.");
    addResponseTopic("watch finding", "Keep this as civil watch service.",
        "civil watch offered");
    addResponse("watch finding", "Record my interest in further training.",
        "@D@You ask about a later training inquiry, not automatic membership.");
    addResponseTopic("watch finding",
        "Record my interest in further training.", "watch training requested");
}
