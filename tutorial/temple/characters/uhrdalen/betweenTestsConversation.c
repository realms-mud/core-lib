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
        "Blood in the north shall come.\nBlood in the south there already is.\n"
        "Blood in the east unto the crimson sea.\n"
        "From the west, blood bathes all.'");
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

    addTopic("crucible reflection", "@S@'Why did I obey?' @D@Uhrdalen "
        "echoes the question, or answers it - it is hard to tell. "
        "@S@'Because I did not know how to stop. Because the alternative "
        "was worse. Because obedience was all I knew. These are reasons "
        "and they are excuses and they are both true.'\n\n@D@His voice "
        "drops to something barely audible - not quite speech, not quite "
        "song. The words seem to pull themselves from him against his "
        "will.\n\n@S@'My dead heart lies before me\nMy weary body flees\n"
        "Surrendering to darkness\nEmpty now my dreams\nThe greatest love "
        "I have known\nBecame the sword that struck me down'");
    addResponseTopic("fourth test", "Why did you obey?",
        "crucible reflection");
    addResponseTopic("fourth test", "The poem makes more sense now.",
        "crucible reflection");

    addResponse("crucible reflection", "What was that you were singing?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask## softly, "
        "@S@'What was that? Those words... were you singing?'");
    addResponse("crucible reflection", "The greatest love became a sword...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::repeat## the "
        "words quietly. @S@'The greatest love you have known became "
        "the sword... You speak of Xyris?'");
    addResponse("crucible reflection", "You speak of love. Who did you love?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@'You "
        "speak of love. Who did you love, Uhrdalen?'");

    addTopic("the lament begins", "@D@Uhrdalen seems startled, as "
        "though he had not realized he was speaking aloud. His form "
        "flickers.\n\n@S@'Words from another life. A lament I composed "
        "in chains of light, when I still had voice enough to sing. "
        "Love, power, devotion - they were all the same thing once. "
        "Before they became the blade.'\n\n@D@His gaze grows distant "
        "again, and the half-song returns.\n\n@S@'I walked a road with "
        "no name\nBarefoot on shattered stone\nThe sky refused to look "
        "at me\nThe wind forgot my face'");
    addResponseTopic("crucible reflection", "What was that you were singing?",
        "the lament begins");
    addResponseTopic("crucible reflection", "The greatest love became a sword...",
        "the lament begins");
    addResponseTopic("crucible reflection", "You speak of love. Who did you love?",
        "the lament begins");

    addResponse("the lament begins", "These are your words? Your song?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::listen## "
        "carefully. @S@'These are your words? Your own song?'");
    addResponse("the lament begins", "The road with no name... is that this place?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::glance## "
        "around the chamber. @S@'The road with no name... is that "
        "what this place is?'");

    addTopic("after crucible end", "@S@'My words. My folly. My truth.' "
        "@D@He straightens, the distant look fading. His voice "
        "returns to its usual measured cadence.\n\n@S@'But enough of "
        "old sorrows. The pattern shifts again. Heed this verse:\n"
        "Emerald foes belch from the mountains in the north.\n"
        "As the trees to the south do bloom.\n"
        "The waters of the eastern sea do mirror,\n"
        "The green malady of the west.'\n\n@D@He gestures toward the "
        "pedestals. @S@'Go.'");
    addResponseTopic("the lament begins", "These are your words? Your song?",
        "after crucible end");
    addResponseTopic("the lament begins", "The road with no name... is that this place?",
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

    addTopic("mirror reflection", "@S@'What did I see?' @D@Uhrdalen "
        "pauses. @S@'Myself. Not the version Xyris made me into, not "
        "the wraith, not the mage. Just... myself. \"Held in my tracks "
        "by fear. My doom awaits me.\" Those lines are about the moment "
        "before understanding. The moment when you stop running and turn "
        "to look at what pursues you.'\n\n@D@His voice slips again into "
        "that half-sung cadence, as though the words have a gravity of "
        "their own.\n\n@S@'I heard the echoes call me\nNot with voices, "
        "but with grief\nShadows mouthing silent words\nOf lives I "
        "can't retrieve\n\nThe silence speaks in riddles now\nIt knows "
        "the things I fear\nThe light behind my eyes has dimmed\nBut "
        "still, I see too clear'");
    addResponseTopic("fifth test", "What did you see?",
        "mirror reflection");
    addResponseTopic("fifth test", "The shadow is part of us.",
        "mirror reflection");

    addResponse("mirror reflection", "Your lament again. The echoes...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::recognize## "
        "the cadence from before. @S@'Your lament again. The echoes "
        "calling with grief... like the pool of memories.'");
    addResponse("mirror reflection", "The light behind your eyes has dimmed...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::study## the "
        "wraith's hollow sockets. @S@'The light behind your eyes has "
        "dimmed, you say. And yet you see too clear. That is perhaps "
        "the cruelest part.'");

    addTopic("mirror song", "@D@Uhrdalen does not acknowledge that "
        "he has been singing. Perhaps he does not know.\n\n@S@'Thought "
        "I had sweet dreams\nThe dreams, a madness crushing me\n"
        "Ruthless, cruel reality\nI despise your hateful truth\nI look "
        "now toward the future\nLove is the lie we tell ourselves\nTo "
        "enhance the pain of the fall'\n\n@D@He stares through you, "
        "past you, at something only he can see.\n\n@S@'I am the ghost "
        "of what could be\nThe husk of what once dared\nTo rise against "
        "the wheel of time\nAnd found no solace there'");
    addResponseTopic("mirror reflection", "Your lament again. The echoes...",
        "mirror song");
    addResponseTopic("mirror reflection", "The light behind your eyes has dimmed...",
        "mirror song");

    addResponse("mirror song", "Love is a lie? Surely not.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::shake## "
        "##InitiatorPossessive## head. @S@'Love is a lie? Surely "
        "you cannot believe that.'");
    addResponse("mirror song", "A ghost of what could be... is that how you see yourself?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask## quietly, "
        "@S@'A ghost of what could be, the husk of what once dared... "
        "is that truly how you see yourself?'");

    addTopic("after mirror end", "@S@'Love is whatever it needs to be "
        "to hurt you most.' @D@He turns toward the pedestals, his "
        "voice steadying.\n\n@S@'But we are not here to discuss what "
        "I believe. Your next verse:\n"
        "Verdant haze blankets the northern wood.\n"
        "Moss reclaims the southern stone.\n"
        "The sapphire depths of the eastern tide.\n"
        "Cobalt sky stretches across the western horizon.'\n\n"
        "@D@He regards you gravely. @S@'The next trial will ask more "
        "of you than any before it.'");
    addResponseTopic("mirror song", "Love is a lie? Surely not.",
        "after mirror end");
    addResponseTopic("mirror song", "A ghost of what could be... is that how you see yourself?",
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

    addTopic("dream reflection", "@D@Uhrdalen's form steadies. "
        "@S@'You are kind to say so. Kinder than I deserve, perhaps.'"
        "\n\n@D@His voice drops into that familiar half-sung cadence, "
        "but this time there is no distance in it - only raw, "
        "unguarded pain.\n\n@S@'They told me death was mercy\nA "
        "kindness lost to me\nBut now I dream of crumbling bones\n"
        "And beg to cease to be\n\nYet still I breathe\nStill I "
        "fade\nWishing for the end I've made\nCursed to crawl through "
        "timeless days\nAnd drink the dust of memories'");
    addResponseTopic("sixth test", "I am sorry, Uhrdalen.",
        "dream reflection");
    addResponseTopic("sixth test", "Your suffering was not in vain.",
        "dream reflection");

    addResponse("dream reflection", "You wish for death?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask## "
        "carefully, @S@'You wish for death, Uhrdalen? After all "
        "this time?'");
    addResponse("dream reflection", "Is there no hope for you?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask## "
        "quietly, @S@'Is there no hope for you? No release?'");

    addTopic("dream song despair", "@D@Uhrdalen's form flares. "
        "The chamber fills with a bitter chill as his voice rises - "
        "no longer a murmur but a cry torn from centuries of "
        "solitude.\n\n@S@'Reckon me now, o fractured sky!\nBreak me "
        "on your wheel of flame!\nI dared the gods for endless life\n"
        "And burned the very name\nOf all I loved\nOf all I knew\n"
        "Ashes in a gilded frame\nA monument to emptiness\nA song "
        "without refrain'\n\n@D@The light in his hollow eyes gutters "
        "like a candle in a gale.\n\n@S@'I am not who I was\nI am "
        "not who I am\nI am nothing\nBut a name\nScorched\nIn\n"
        "Stone'\n\n@D@He draws a shuddering breath he does not "
        "need.\n\n@S@'Alone in this realm of twisted dreams\nThe "
        "price of immortality\nEclipse of eternity\nA cursed domain\n"
        "\nWhere our lives\nWhere our deaths\nThey're both the same'");
    addResponseTopic("dream reflection", "You wish for death?",
        "dream song despair");
    addResponseTopic("dream reflection", "Is there no hope for you?",
        "dream song despair");

    addResponse("dream song despair", "Uhrdalen...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::reach## out, "
        "though there is nothing solid to touch. @S@'Uhrdalen...'");
    addResponse("dream song despair", "You dared the gods for endless life?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@'You "
        "dared the gods for endless life? Is that what Xyris promised "
        "you?'");

    addTopic("dream song turning", "@D@The chill recedes. Uhrdalen's "
        "form steadies, and when he speaks again, there is something "
        "new in his voice - fragile, uncertain, but unmistakable. "
        "Something that was not there before.\n\n@S@'But in the hush "
        "that follows rage\nA trembling thought appears\nWhat if this "
        "fate I dragged behind\nIs only forged by fear?'\n\n@D@He "
        "looks at his own spectral hands.\n\n@S@'If there's no end, "
        "then I must change\nOr rot here all the same\nThe fountain "
        "gave no grace to me\nBut left me still, a name'\n\n@D@His "
        "voice strengthens.\n\n@S@'So break the mirror\nShatter the "
        "dream\nBury the hunger\nThat tore through the seams\nNo gods "
        "remain\nNo curse will stay\nBut I will rise\nIf just to walk "
        "away'\n\n@D@A pause. The faintest ghost of warmth.\n\n@S@'I "
        "walked a road with no name\nAnd left it in the flame\nNo "
        "savior waits to carry me\nBut I go on\nJust the same'");
    addResponseTopic("dream song despair", "Uhrdalen...",
        "dream song turning");
    addResponseTopic("dream song despair", "You dared the gods for endless life?",
        "dream song turning");

    addResponse("dream song turning", "There is hope in your words.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::say## "
        "quietly, @S@'There is hope in those words, Uhrdalen. "
        "You go on. Just the same.'");
    addResponse("dream song turning", "You will rise. I believe that.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::nod##. "
        "@S@'You will rise. I believe that.'");

    addTopic("after dream end", "@D@Uhrdalen regards you for a long "
        "moment. Something shifts behind those hollow eyes - not quite "
        "gratitude, not quite hope, but the space where such things "
        "might take root.\n\n@S@'Perhaps.' @D@He draws himself up. "
        "@S@'One trial remains after this next one. Steel yourself, "
        "##ActorName##. The gauntlet ahead will push your body as the "
        "dream pushed your spirit. Survive, and we will speak one "
        "final time.'\n\n@D@He gestures toward the pedestals.\n\n"
        "@S@'Your verse:\nThe emerald fields stretch to the east.\n"
        "Green pastures beckon from the west.\nThe sapphire rivers "
        "of the north do flow.\nThe cerulean mists of the south do "
        "rest.'");
    addResponseTopic("dream song turning", "There is hope in your words.",
        "after dream end");
    addResponseTopic("dream song turning", "You will rise. I believe that.",
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
