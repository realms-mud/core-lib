//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'Welcome, traveler! You look "
        "like you could use a warm meal and a cold drink. Name's Aldric "
        "- I run this place.' @D@He gestures broadly at the inn's "
        "common room, a proud grin on his face.");
    addTopic("the village", "@S@'We've got most of what you'd need "
        "here. Branna runs the smithy down the road - good steel, "
        "fair prices. Father Osric tends the church if your soul "
        "needs mending. And old Marta at the market can supply you "
        "with provisions for the road.' @D@He leans in a bit closer. "
        "@S@'Though I'll say, things have been a mite unsettled "
        "lately. Strange folk on the roads, and the soldiers at the "
        "keep seem more on edge than usual.'");
    addTopic("the inn", "@D@Aldric glances around the common room. "
        "@S@'This is the warmest room in the village, and I try to "
        "keep it welcoming. Travelers can rest here without having "
        "to explain their whole lives at the door.'");
    addTopic("the road", "@S@'The road south is usually quiet. "
        "Lately, I would tell anyone traveling alone to keep an "
        "eye out and come back before dark.'");

    addResponse("first conversation", "What can you tell me about this village?",
        "@S@'Argalen? It's a quiet place, mostly. Good folk, hard "
        "workers. The keep up on the hill watches over us, and we "
        "watch over each other. Been that way for generations.'");
    addResponseTopic("first conversation",
        "What can you tell me about this village?", "the village");
    addResponse("first conversation", "I could use a drink.",
        "@D@Aldric chuckles and reaches for a tankard. "
        "@S@'That's what I like to hear! Take a seat and I'll "
        "pour you something proper.'");
    addResponseTopic("first conversation", "I could use a drink.",
        "the inn");
    addResponse("first conversation", "Is the road safe?",
        "@S@'Safe enough in daylight, but keep your wits about you. "
        "The captain at the keep knows more than I do.'");
    addResponseTopic("first conversation", "Is the road safe?",
        "the road");

    addResponse("the village", "Strange folk?",
        "@D@Aldric glances around and lowers his voice. "
        "@S@'Aye, travelers who don't quite fit. Hooded sorts who "
        "don't stop for ale or conversation. They come through at "
        "night, headed east toward the hills. Makes a man wonder "
        "what business draws them out there.'");
    addResponse("the village", "Tell me about the keep.",
        "@S@'Argalen Keep has stood for centuries, guarding the "
        "road south. Lord Edran holds it now - a fair man, if a "
        "bit stern. His guards keep the peace, and in return we "
        "keep them fed and watered.' @D@He shrugs. @S@'It's a "
        "good arrangement.'");
    addResponse("the village", "Where can I find a meal?",
        "@S@'Here, if you have the coin. Marta can sell you food "
        "for the road, but she won't cook it for you.'");
    addResponseTopic("the village", "Where can I find a meal?",
        "the inn");
    addResponse("the road", "What should I do if I meet trouble?",
        "@S@'Do not make yourself a hero over a rumor. Return to "
        "the village and tell the keep's guards what you saw.'");
}
