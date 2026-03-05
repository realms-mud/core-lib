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
    addTopic("second test", "@D@Uhrdalen's wispy form materializes "
        "before you, his hollow gaze sweeping the chamber.\n\n"
        "@S@'The orbs have shifted. A new path opens.' @D@He pauses, "
        "tilting his skeletal head as though listening to something "
        "distant. @S@''Tis interesting. One who would be your friend "
        "has been... targeted by a rather pointed argument and even now "
        "has some rather vivid thoughts playing through his head about "
        "you feebly pawing at your leaking entrails, something large "
        "and scaly standing over your ruptured torso ready to end your "
        "life.' @D@He waves a dismissive hand. @S@'It is, perhaps a "
        "harmless fantasy and I sense that the sincerity of the thought "
        "is not there.'");

    addResponse("second test", "That may be...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::begin##, "
        "@S@'That may be...'");
    addResponse("second test", "Who would target my allies?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask## sharply, "
        "@S@'Who would target my allies? What have you seen?'");
    addResponse("second test", "What does this have to do with the trial?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::frown##. "
        "@S@'What does this have to do with the trial?'");

    addTopic("uhrdalen rebuke", "@D@Uhrdalen raises a spectral hand, "
        "cutting you off.\n\n@S@'That is not why I am here. I am not "
        "your friend. I am not your enemy. I simply am.'");
    addResponseTopic("second test", "That may be...",
        "uhrdalen rebuke");
    addResponseTopic("second test", "Who would target my allies?",
        "uhrdalen rebuke");
    addResponseTopic("second test", "What does this have to do with the trial?",
        "uhrdalen rebuke");

    addResponse("uhrdalen rebuke", "Then why are you here?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@'Then why are you here?'");
    addResponse("uhrdalen rebuke", "What are you, exactly?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::study## "
        "the wraith carefully. @S@'What are you, exactly?'");
    addResponse("uhrdalen rebuke", "Very well. Continue.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::nod## curtly. "
        "@S@'Very well. Continue.'");

    addTopic("colors of emotion", "@S@'I do what I must because it is "
        "all I know.' @D@His gaze drifts to the pulsing orbs atop the "
        "pedestals. @S@'The light pulses in the colors of sorrow, envy, "
        "wrath, and fear, each intermingled one with the other.'\n\n"
        "@D@He turns back to you, his voice taking on the cadence of "
        "recitation.\n\n@S@'Learn well this verse, for it is the key:\n"
        "Blood in the north.\nThe furnace of the southern heat.\n"
        "To the east the rising sun.\n"
        "To the west the fires of war embrace the lands.'");
    addResponseTopic("uhrdalen rebuke", "Then why are you here?",
        "colors of emotion");
    addResponseTopic("uhrdalen rebuke", "What are you, exactly?",
        "colors of emotion");
    addResponseTopic("uhrdalen rebuke", "Very well. Continue.",
        "colors of emotion");

    addResponse("colors of emotion", "Are you content to remain here?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask## quietly, "
        "@S@'Uhrdalen... I have so many questions. Foremost is why you "
        "are here. Are you content to remain where and as you are? Can "
        "I help you?'");
    addResponse("colors of emotion", "What must I do with this verse?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@'As "
        "to the next phase of the trial, is it permissible to explain "
        "the objective? I believe I understand the mechanics of what "
        "you have explained, but I do not know to what end we are to "
        "effect by our selections.'");
    addResponse("colors of emotion", "I will study the verse carefully.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::nod## slowly. "
        "@S@'I will study the verse carefully.'");

    addTopic("uhrdalen personal", "@D@Uhrdalen is still for a long "
        "moment.\n\n@S@'The luxury of time is not afforded to you and "
        "what I wish is irrelevant. Whether I am content is of little "
        "consequence to she who pulls the strings on this puppet.'");

    addTopic("test guidance", "@D@Uhrdalen regards you flatly.\n\n"
        "@S@'The objective is clearly spelled out in the verse I have "
        "given you. Certainly, you need further guidance, but you must "
        "use your own wit and that failing, random luck to complete "
        "this. As to the choice of plates, you do not want to misjudge "
        "them.'");

    addTopic("after magic square end", "@D@Uhrdalen's form begins to "
        "fade at the edges.\n\n@S@'The orbs await your touch. The verse "
        "is your guide. Heed its words well, ##ActorName##, for the "
        "path forward depends upon your choices.'\n\n@D@He gestures "
        "toward the pedestals. @S@'Continue, seeker.'");

    addResponseTopic("colors of emotion", "Are you content to remain here?",
        "uhrdalen personal");
    addResponseTopic("colors of emotion", "What must I do with this verse?",
        "test guidance");
    addResponseTopic("colors of emotion", "I will study the verse carefully.",
        "after magic square end");

    addResponse("uhrdalen personal", "Who pulls the strings?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::press##, "
        "@S@'Who pulls the strings? Who keeps you here?'");
    addResponse("uhrdalen personal", "I understand. The verse, then.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::let## the "
        "matter rest. @S@'I understand. The verse, then - I will heed "
        "its words.'");
    addResponseTopic("uhrdalen personal", "Who pulls the strings?",
        "after magic square end");
    addResponseTopic("uhrdalen personal", "I understand. The verse, then.",
        "after magic square end");

    addResponse("test guidance", "I will heed the verse.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::nod##. "
        "@S@'I will heed the verse.'");
    addResponse("test guidance", "That is frustratingly vague.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::mutter##, "
        "@S@'That is frustratingly vague.'");
    addResponseTopic("test guidance", "I will heed the verse.",
        "after magic square end");
    addResponseTopic("test guidance", "That is frustratingly vague.",
        "after magic square end");

    addResponse("after magic square end", "@I@Continue@E@",
        "@I@Continue@E@");
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
        "will understand what that truth costs.'");
    addResponseTopic("third test", "That mage was you.",
        "after echo pool end");
    addResponseTopic("third test", "@I@Say nothing@E@",
        "after echo pool end");

    addResponse("after echo pool end", "And what of the colors?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::glance## "
        "toward the pulsing orbs. @S@'And what of the colors? White, "
        "blue, green, red - they seem to be more than mere markers.'");
    addResponse("after echo pool end", "I begin to see the shape of it.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::nod## slowly. "
        "@S@'I begin to see the shape of it. Weakness and strength, "
        "two faces of the same coin.'");

    addTopic("shades of the orbs", "@D@Uhrdalen's gaze drifts to the "
        "pulsing orbs atop the pedestals.\n\n@S@'White, blue, green, "
        "red... so those have become the shades of... victory or of "
        "defeat?' @D@He turns back to you, his hollow eyes "
        "unreadable. @S@'Forget not that they are also colors used "
        "by Xyris to defy the will of the gods.'");
    addResponseTopic("after echo pool end", "And what of the colors?",
        "shades of the orbs");
    addResponseTopic("after echo pool end", "I begin to see the shape of it.",
        "shades of the orbs");

    addResponse("shades of the orbs", "Could those colors have more significance?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@'The "
        "colors of what? Could those colors have more significance "
        "than just identification?'");
    addResponse("shades of the orbs", "What do Xyris's colors have to do with this?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::frown##. "
        "@S@'What do Xyris's colors have to do with any of this?'");
    addResponse("shades of the orbs", "I did not know that.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::say## quietly, "
        "@S@'I did not know that. There is much hidden in this place.'");

    addTopic("tests reflection", "@D@Uhrdalen regards you with "
        "something that might be curiosity.\n\n@S@'In the first test, "
        "you created the rules - aye, that was you, not me. In the "
        "second, you followed the rules to the letter. You are "
        "adaptive, but you go into things and there is a clear-cut "
        "path to victory.' @D@He pauses, his spectral form "
        "flickering. @S@'What would you do if there were no hope of "
        "victory? What would you sacrifice to accomplish your goals?'");
    addResponseTopic("shades of the orbs", "Could those colors have more significance?",
        "tests reflection");
    addResponseTopic("shades of the orbs", "What do Xyris's colors have to do with this?",
        "tests reflection");
    addResponseTopic("shades of the orbs", "I did not know that.",
        "tests reflection");

    addResponse("tests reflection", "I would still defy my enemies.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::straighten##. "
        "@S@'Even without hope of victory I would still choose as I "
        "have - to defy my enemies and cause them what harm as I "
        "might unto my last breath.'");
    addResponse("tests reflection", "That is a question I hope never to answer.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::hesitate##. "
        "@S@'That is a question I hope never to answer truthfully.'");
    addResponse("tests reflection", "I would do whatever is necessary.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::reply## "
        "without hesitation. @S@'I would do whatever is necessary.'");

    addTopic("sacrifice of others", "@D@Uhrdalen tilts his skeletal "
        "head, studying you.\n\n@S@'What would you sacrifice to "
        "accomplish your goals? Apart from yourself, that is.' "
        "@D@His voice sharpens. @S@'Would you sacrifice your "
        "friends? Your loved ones?'");
    addResponseTopic("tests reflection", "I would still defy my enemies.",
        "sacrifice of others");
    addResponseTopic("tests reflection", "That is a question I hope never to answer.",
        "sacrifice of others");
    addResponseTopic("tests reflection", "I would do whatever is necessary.",
        "sacrifice of others");

    addResponse("sacrifice of others", "Not as easily, but I would do what I must.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::look## away "
        "for a moment. @S@'Not as easily, no. I would still do what "
        "I must. If by any sacrifice I could affect things in a "
        "positive way, I would.'");
    addResponse("sacrifice of others", "No. I would find another way.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::shake## "
        "##InitiatorPossessive## head firmly. @S@'No. There is "
        "always another way. I would find it.'");
    addResponse("sacrifice of others", "If the cause were just, yes.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::meet## "
        "Uhrdalen's hollow gaze. @S@'If the cause were just and "
        "the need dire enough... yes.'");

    addTopic("uhrdalen oath break", "@D@Uhrdalen is silent for a "
        "long moment. His form flickers violently, as though "
        "something inside him is warring with itself.\n\n@S@'"
        "Interesting.' @D@He draws closer, his voice dropping to "
        "barely a whisper. @S@'I break now my oath. I give you this "
        "opportunity to escape from this... this last chance. You "
        "will be free.' @D@He raises a spectral hand before you "
        "can speak. @S@'However, if you go into the maze, if you "
        "continue on, you will not reach the other side unaltered "
        "if you reach it at all.'");
    addResponseTopic("sacrifice of others", "Not as easily, but I would do what I must.",
        "uhrdalen oath break");
    addResponseTopic("sacrifice of others", "No. I would find another way.",
        "uhrdalen oath break");
    addResponseTopic("sacrifice of others", "If the cause were just, yes.",
        "uhrdalen oath break");

    addResponse("uhrdalen oath break", "If I turn around, I condemn others.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::shake## "
        "##InitiatorPossessive## head. @S@'But if I turn around, I "
        "condemn others to death, more suffering. Is that not the way "
        "of it? Nay, spectre... if I get a choice, I would rather "
        "see myself dead and the others succeed than more of this "
        "devastation that this wicked rat's nest has been sending "
        "forth.'");
    addResponse("uhrdalen oath break", "What do you mean, unaltered?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask## "
        "carefully, @S@'What do you mean, unaltered? What will this "
        "place do to me?'");
    addResponse("uhrdalen oath break", "Why would you break your oath for me?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::study## the "
        "wraith. @S@'Why would you break your oath for me? What "
        "is it you see in me that warrants such a risk?'");

    addTopic("we all have a choice", "@D@Uhrdalen's form steadies.\n\n"
        "@S@'We all have a choice.'");
    addResponseTopic("uhrdalen oath break", "If I turn around, I condemn others.",
        "we all have a choice");
    addResponseTopic("uhrdalen oath break", "What do you mean, unaltered?",
        "we all have a choice");
    addResponseTopic("uhrdalen oath break", "Why would you break your oath for me?",
        "we all have a choice");

    addResponse("we all have a choice", "Why offer this? Why think I would take it?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@'Uhrdalen, you choose to defy your oath and allow me to "
        "escape. Why would you do such a thing? And, why would you "
        "think that I would take your offer?'");
    addResponse("we all have a choice", "So be it. I continue.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::square## "
        "##InitiatorPossessive## shoulders. @S@'So be it. I "
        "continue.'");

    addTopic("uhrdalen explains offer", "@D@Uhrdalen waves a "
        "dismissive hand.\n\n@S@'The way is unbarred and the choice "
        "is yours. I am not passing judgment as to the likeliness of "
        "your decision, I have merely given you that opportunity if "
        "you so wish.'");
    addResponseTopic("we all have a choice", "Why offer this? Why think I would take it?",
        "uhrdalen explains offer");
    addResponseTopic("we all have a choice", "So be it. I continue.",
        "uhrdalen explains offer");

    addResponse("uhrdalen explains offer", "There is a greater calling that binds me.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::say## "
        "quietly, @S@'I believe you already know my heart. I would "
        "love to leave this place, but there is a greater calling "
        "that binds me to this mission whatever the outcome.'");
    addResponse("uhrdalen explains offer", "Your offer is noted and declined.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::incline## "
        "##InitiatorPossessive## head. @S@'Your offer is noted. "
        "And declined.'");

    addTopic("uhrdalen not a hero", "@D@Uhrdalen chuckles - a "
        "hollow, rasping sound that echoes through the chamber.\n\n"
        "@S@'You are interesting. I am not a hero. None would ever "
        "have looked to me in life to save anyone.'");
    addResponseTopic("uhrdalen explains offer", "There is a greater calling that binds me.",
        "uhrdalen not a hero");
    addResponseTopic("uhrdalen explains offer", "Your offer is noted and declined.",
        "uhrdalen not a hero");

    addResponse("uhrdalen not a hero", "So I must rot because you are not a hero?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::retort##, "
        "@S@'So I must rot because you are not a hero?'");
    addResponse("uhrdalen not a hero", "Heroes are made, not born.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::reply##, "
        "@S@'Heroes are made, not born. You chose to break your "
        "oath just now. That is a start.'");

    addTopic("embrace your fate", "@D@Uhrdalen's expression "
        "hardens - or as much as a skull can harden.\n\n@S@'If "
        "such is your fate, then embrace it. Trying to flee will not "
        "make it untrue. Make due with the tools you have been given, "
        "for they are sufficient for the task at hand.' @D@He fixes "
        "you with his hollow gaze. @S@'You have been told what your "
        "purpose was, but it seems you do not truly know. I am not "
        "here to forever repeat myself... I am not here to tutor.'");
    addResponseTopic("uhrdalen not a hero", "So I must rot because you are not a hero?",
        "embrace your fate");
    addResponseTopic("uhrdalen not a hero", "Heroes are made, not born.",
        "embrace your fate");

    addResponse("embrace your fate", "I ask for your mercy, to be the hero.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::press##, "
        "@S@'Speak plainly. Is there no way to prevent what evil "
        "is to come? I ask for your mercy, to be the hero.'");
    addResponse("embrace your fate", "What tools? Speak clearly for once.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::narrow## "
        "##InitiatorPossessive## eyes. @S@'What tools? Speak "
        "clearly for once, Uhrdalen.'");

    addTopic("uhrdalen mercy", "@D@Uhrdalen's form flares, filling "
        "the chamber with a chill that cuts to the bone.\n\n@S@'"
        "Mercy? You request mercy?' @D@His voice drops to a hiss. "
        "@S@'In these times, mercy is dealt with harshly. My foolish "
        "compassion toward you has put us in a rather untenable "
        "situation. You were to waste away in this place with the rest "
        "of the wretched masses until your time for service arrived. "
        "It is you who I had hand-picked for a certain task at hand.' "
        "@D@His spectral hands clench into fists. @S@'Nay, my heart "
        "is hardened. The very existence of this world now hangs in "
        "the balance, waiting on you...'");
    addResponseTopic("embrace your fate", "I ask for your mercy, to be the hero.",
        "uhrdalen mercy");
    addResponseTopic("embrace your fate", "What tools? Speak clearly for once.",
        "uhrdalen mercy");

    addResponse("uhrdalen mercy", "Nothing is predetermined.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::reply## "
        "firmly, @S@'Nothing is predetermined. This is but one "
        "battle in the war called life.'");
    addResponse("uhrdalen mercy", "Then I will bear whatever weight you place upon me.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::meet## the "
        "wraith's hollow gaze without flinching. @S@'Then I will "
        "bear whatever weight you place upon me.'");

    addTopic("uhrdalen metaphor", "@D@Uhrdalen regards you for a "
        "long, silent moment. The chill recedes.\n\n@S@'It is, of "
        "course, quite possible that I was simply speaking in "
        "metaphor.' @D@He waves a dismissive hand. @S@'What of it? "
        "It changes nothing.'");
    addResponseTopic("uhrdalen mercy", "Nothing is predetermined.",
        "uhrdalen metaphor");
    addResponseTopic("uhrdalen mercy", "Then I will bear whatever weight you place upon me.",
        "uhrdalen metaphor");

    addResponse("uhrdalen metaphor", "Is there more I should know?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::sigh##, "
        "mildly annoyed. @S@'I should be away. Is there more I "
        "should know before continuing?'");
    addResponse("uhrdalen metaphor", "You speak in riddles. One day I will have plain answers.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::mutter##, "
        "@S@'You speak in riddles and metaphors. One day I will "
        "have plain answers from you.'");

    addTopic("final wisdom echo pool", "@D@Uhrdalen's form begins "
        "to dim at the edges.\n\n@S@'Perhaps growth has ended and "
        "a fatal weakness has been exposed.' @D@He regards you one "
        "final time. @S@'Ask yourself this: why are you trying to "
        "complete this test I have laid before you?'\n\n@D@He "
        "gestures toward the pedestals. @S@'Consider that "
        "carefully, ##ActorName##, as you continue.\n"
        "Behold the frigid wastes of the north.\n"
        "Winter covers the southern lands.\n"
        "To the east, the frost falls on a new day.\n"
        "To the west, the unending snows.'");
    addResponseTopic("uhrdalen metaphor", "Is there more I should know?",
        "final wisdom echo pool");
    addResponseTopic("uhrdalen metaphor", "You speak in riddles. One day I will have plain answers.",
        "final wisdom echo pool");

    addResponse("final wisdom echo pool", "@I@Continue@E@",
        "@I@Continue@E@");
    addResponseEffect("final wisdom echo pool", "@I@Continue@E@",
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
