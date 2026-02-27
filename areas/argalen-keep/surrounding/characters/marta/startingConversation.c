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
    addTopic("village gossip", "@S@'What I don't know is what's "
        "going on up at the keep. Lord Edran's been keeping to "
        "himself more than usual, and his captain's been buying "
        "up every scrap of dried food I can supply.' @D@She "
        "frowns. @S@'You don't stockpile like that unless "
        "you're expecting trouble. Or a siege.' @D@She shakes "
        "her head. @S@'But what do I know? I'm just an old "
        "woman who sells turnips.'");

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

    addResponse("village gossip", "A siege? From whom?",
        "@D@Marta waves a hand dismissively, but her eyes "
        "betray concern. @S@'Who knows? Could be bandits "
        "grown bold, could be something worse. There've been "
        "noises from the old mines to the east - the kind "
        "that make the goats nervous. And goats don't spook "
        "easy.'");
}
