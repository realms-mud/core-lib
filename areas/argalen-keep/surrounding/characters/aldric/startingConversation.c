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
}
