//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Marta peers at you over a "
        "crate of turnips, her shrewd eyes sizing you up in an "
        "instant. @S@'Traveler, eh? You'll be wanting provisions "
        "then. I've got the best stock between here and the "
        "capital, and my prices are fair - don't let anyone tell "
        "you otherwise.'");
    addTopic("village gossip", "@S@'What I know is what passes "
        "over this counter. The western farms have asked for more "
        "lamp oil and axle grease, and fewer loads have come in "
        "from the old track.' @D@She counts a few coins into a "
        "wooden tray. @S@'That may mean nothing. It still changes "
        "what I order for next week.'");
    addTopic("keeping the market", "@D@Marta checks a chalk mark "
        "beside the day's prices. @S@'I buy in small lots and keep "
        "the account where my customers can see it. If the harvest "
        "is poor, we stretch what we have. I will not charge a "
        "neighbor twice because a cart arrived late.'");
    addTopic("the western road", "@S@'Harlan Reed knows the farm "
        "track better than I do. He says unfamiliar carts have been "
        "moving after dusk, but he has not accused anyone. Ask him "
        "what he saw before you ask me what it means.'");

    addResponse("first conversation", "Show me what you have.",
        "@D@She straightens up and gestures at the laden shelves "
        "with evident pride. @S@'Dried meats, hard cheese, road "
        "bread that'll last a fortnight, herbs and simples for "
        "what ails you. Everything a body needs.' @D@She taps "
        "the counter. @S@'Just say `shop` and we'll get down to "
        "business.'");
    addResponse("first conversation", "You seem to know everyone here.",
        "@S@'When you've sold turnips to the same families for "
        "forty years, you learn a thing or two.' @D@She leans "
        "on the counter conspiratorially. @S@'I know who's "
        "courting whom, who's behind on their debts, and who's "
        "been sneaking extra cream from the dairy.'");
    addResponseTopic("first conversation",
        "You seem to know everyone here.", "village gossip");
    addResponse("first conversation", "How do you decide what to charge?",
        "@D@You ask how Marta keeps the market fair.");
    addResponseTopic("first conversation",
        "How do you decide what to charge?", "keeping the market");

    addResponse("village gossip", "A siege? From whom?",
        "@D@Marta pauses over her ledger and gives you a firm look. "
        "@S@'I said a late delivery, not a siege. Find out what "
        "happened before you frighten people who have done nothing "
        "wrong.'");
    addResponseTopic("village gossip", "A siege? From whom?",
        "the western road");
    addResponse("keeping the market", "What if the delivery never comes?",
        "@S@'Then I record the loss, speak with the carter, and "
        "change the next order. There is no sense making a second "
        "problem out of the first.'");
    addResponse("the western road", "What should I ask Harlan?",
        "@D@Marta points toward the farm lane. @S@'Ask what he "
        "saw, when he saw it, and which way the carts went. Do "
        "not ask him to guess at a stranger's intentions.'");
}
