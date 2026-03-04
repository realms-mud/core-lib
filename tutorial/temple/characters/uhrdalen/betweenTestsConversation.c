//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

private string HoldingRoom =
    "/tutorial/temple/environment/rooms/uhrdalen-holding.c";

/////////////////////////////////////////////////////////////////////////////
private void AfterMagicSquare()
{
    addTopic("second test", "@D@Uhrdalen's wispy form materializes before "
        "you. He regards you with what might be approval.\n\n"
        "@S@'You solved the grid. Interesting. The rune you found speaks "
        "of negation - the denial of that which terrifies us. It is a "
        "powerful word, but an incomplete one.' @D@He pauses. @S@'Tell "
        "me, ##ActorName## - can you truly negate fear, or merely push "
        "it aside for a time?'");

    addResponse("second test", "Fear can be overcome.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::reply##, @S@'Fear "
        "is a thing to be faced and conquered.'");
    addResponse("second test", "I do not know.",
        "@D@@C@##InitiatorName## honestly ##ResponseInfinitive::admit##, "
        "@S@'I am not certain.'");

    addTopic("after magic square end", "@D@Uhrdalen tilts his skeletal "
        "head. @S@'A fair answer, either way. Fear is the thread that "
        "runs through all of this - through the poem, through my story, "
        "through yours. You will come to understand it better before "
        "the end.'\n\n@D@He gestures toward the pedestals. @S@'The "
        "orbs have shifted. A new path opens. Continue, seeker.'");
    addResponseTopic("second test", "Fear can be overcome.",
        "after magic square end");
    addResponseTopic("second test", "I do not know.",
        "after magic square end");

    addResponse("after magic square end", "@I@Continue@E@", "@I@Continue@E@");
    addResponseEffect("after magic square end", "@I@Continue@E@",
        (["move": HoldingRoom]));
}

/////////////////////////////////////////////////////////////////////////////
private void AfterEchoPool()
{
    addTopic("third test", "@D@Uhrdalen appears once more, his form "
        "flickering at the edges.\n\n@S@'Weakness and strength. You "
        "arranged the echoes of a life - my life, though you may not "
        "have known it. The young mage who knelt before the altar was "
        "weak in his desire for power. And strong - terribly strong - "
        "in his willingness to pay any price for it.' @D@His voice "
        "drops. @S@'They are the same quality, seen from different "
        "sides of the mirror.'");

    addResponse("third test", "That mage was you.",
        "@D@@C@##InitiatorName## quietly ##ResponseInfinitive::say##, "
        "@S@'That mage was you, was he not?'");
    addResponse("third test", "@I@Say nothing@E@",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::wait## in silence.");

    addTopic("after echo pool end", "@D@Uhrdalen is still for a long "
        "moment. @S@'The poem speaks truth that I could not speak "
        "myself. \"I am weak. I am strong.\" Two lines, one truth. "
        "Perhaps, by the time you have collected all the verses, you "
        "will understand what that truth costs.'\n\n@D@He gestures "
        "toward the pedestals. @S@'Onward, ##ActorName##. The next "
        "trial awaits.'");
    addResponseTopic("third test", "That mage was you.",
        "after echo pool end");
    addResponseTopic("third test", "@I@Say nothing@E@",
        "after echo pool end");

    addResponse("after echo pool end", "@I@Continue@E@", "@I@Continue@E@");
    addResponseEffect("after echo pool end", "@I@Continue@E@",
        (["move": HoldingRoom]));
}

/////////////////////////////////////////////////////////////////////////////
private void AfterCrucible()
{
    addTopic("fourth test", "@D@Uhrdalen's form coalesces. He looks at "
        "your hands - still red from flame and white from frost.\n\n"
        "@S@'Burning. Freezing. You endured both willingly. Most who "
        "reach this chamber try to find a way around the pain. There "
        "is none.' @D@He regards you carefully. @S@'The poem does not "
        "speak of fire and ice as opposites. They are the same thing - "
        "the price of serving a master who cares nothing for your "
        "suffering. I burned cities. I was frozen in chains of light. "
        "Both were the cost of obedience.'");

    addResponse("fourth test", "Why did you obey?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@'Why "
        "did you continue to serve if the cost was so great?'");
    addResponse("fourth test", "The poem makes more sense now.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::nod## slowly, "
        "@S@'I begin to see the shape of the poem.'");

    addTopic("after crucible end", "@S@'Why did I obey?' @D@Uhrdalen "
        "echoes the question, or answers it - it is hard to tell. "
        "@S@'Because I did not know how to stop. Because the alternative "
        "was worse. Because obedience was all I knew. These are reasons "
        "and they are excuses and they are both true.'\n\n@D@He turns "
        "toward the pedestals. @S@'The pattern shifts again. Go.'");
    addResponseTopic("fourth test", "Why did you obey?",
        "after crucible end");
    addResponseTopic("fourth test", "The poem makes more sense now.",
        "after crucible end");

    addResponse("after crucible end", "@I@Continue@E@", "@I@Continue@E@");
    addResponseEffect("after crucible end", "@I@Continue@E@",
        (["move": HoldingRoom]));
}

/////////////////////////////////////////////////////////////////////////////
private void AfterMirror()
{
    addTopic("fifth test", "@D@Uhrdalen appears. His gaze lingers on "
        "the cracked mirror behind you.\n\n@S@'Fear. Doom. You faced "
        "your own shadow and chose not to fight it. That is harder than "
        "it sounds.' @D@He chuckles dryly. @S@'I fought mine for "
        "centuries. Every time I struck, it grew stronger. Every time I "
        "raged against my chains, they tightened. It was only when I "
        "stopped fighting that I began to see clearly.'");

    addResponse("fifth test", "What did you see?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@'What "
        "did you see when you stopped fighting?'");
    addResponse("fifth test", "The shadow is part of us.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::say##, @S@'The "
        "shadow was never the enemy. It was ourselves.'");

    addTopic("after mirror end", "@S@'What did I see?' @D@Uhrdalen "
        "pauses. @S@'Myself. Not the version Xyris made me into, not "
        "the wraith, not the mage. Just... myself. \"Held in my tracks "
        "by fear. My doom awaits me.\" Those lines are about the moment "
        "before understanding. The moment when you stop running and turn "
        "to look at what pursues you.'\n\n@D@He gestures to the "
        "pedestals. @S@'The next trial will ask more of you than any "
        "before it.'");
    addResponseTopic("fifth test", "What did you see?",
        "after mirror end");
    addResponseTopic("fifth test", "The shadow is part of us.",
        "after mirror end");

    addResponse("after mirror end", "@I@Continue@E@", "@I@Continue@E@");
    addResponseEffect("after mirror end", "@I@Continue@E@",
        (["move": HoldingRoom]));
}

/////////////////////////////////////////////////////////////////////////////
private void AfterDream()
{
    addTopic("sixth test", "@D@Uhrdalen appears - and something is "
        "different. He seems smaller, somehow. More fragile.\n\n@S@'You "
        "walked through my memories. You lived my choices.' @D@His voice "
        "is barely a whisper. @S@'No one has ever done that before. They "
        "solve the puzzles, fight the shadows, endure the flames. But "
        "they never... they never have to feel what it was like to be "
        "me.'\n\n@D@He steadies himself. @S@'\"Feeling wise beyond my "
        "years. Pushed past endurance.\" Now you know what those words "
        "cost.'");

    addResponse("sixth test", "I am sorry, Uhrdalen.",
        "@D@@C@##InitiatorName## softly ##ResponseInfinitive::say##, "
        "@S@'I am sorry for what was done to you.'");
    addResponse("sixth test", "Your suffering was not in vain.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::reply##, @S@'If "
        "your story teaches even one person to choose differently, then "
        "it was not in vain.'");

    addTopic("after dream end", "@D@Uhrdalen's form steadies. @S@'You "
        "are kind to say so. Kinder than I deserve, perhaps.' @D@He "
        "draws himself up. @S@'One trial remains after this next one. "
        "Steel yourself, ##ActorName##. The gauntlet ahead will push "
        "your body as the dream pushed your spirit. Survive, and we "
        "will speak one final time.'");
    addResponseTopic("sixth test", "I am sorry, Uhrdalen.",
        "after dream end");
    addResponseTopic("sixth test", "Your suffering was not in vain.",
        "after dream end");

    addResponse("after dream end", "@I@Continue@E@", "@I@Continue@E@");
    addResponseEffect("after dream end", "@I@Continue@E@",
        (["move": HoldingRoom]));
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    AfterMagicSquare();
    AfterEchoPool();
    AfterCrucible();
    AfterMirror();
    AfterDream();
}
