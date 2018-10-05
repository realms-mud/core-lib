//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void ThePlayerAndTheirName()
{
    addTopic("first conversation", "@D@A wispy figure appears. It is largely "
        "skeletal in nature, though ethereal and without substance. A bitterly "
        "frigid chill emanates from the thing. It is enveloped by a thin white "
        "veil, almost as of silk.\n\nThe figure looks at ##InitiatorName## as "
        "it speaks in a hoarse, raspy voice that seems almost to come out of "
        "a great depth, @S@'Greetings, seeker. Welcome to your trial. That "
        "which you seek lies through the mists before you. Ere you may pass, "
        "you must satisfy my curiosity. You are unlike those who I am "
        "accustomed to... testing. Who are you and why are you here?'@D@ It "
        "folds its arms and gives a toothsome leer that can only be "
        "interpreted as a smile.");

    addResponse("first conversation", "My name is...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::clear## ##InitiatorPossessive## throat and "
        "##ResponseInfinitive::say##, @S@'I am ##ActorName## and I am here to pass the "
        "trial, as you name it - and apparently to satisfy your curiousity. "
        "Am I allowed to ask of you then?'");

    addResponse("first conversation", "None of your business...", 
        "@D@@C@##InitiatorName## ##ResponseInfinitive::respond##, @S@'Who I "
        "am is not your concern, wraith. You have a task for me? Get on with "
        "it.'");

    addResponse("first conversation", "I think I'll deflect...", 
        "@D@@C@##InitiatorName## ##ResponseInfinitive::reply##, @S@'I am "
        "one who wishes to complete this trial.'");

    addTopic("wrong answer", "@D@The figure laughs - a harsh, gravelly sound "
        "that sets your nerves on edge. @S@'It would be most unfortunate were "
        "you to have come all this way to get not what you seek. I am your "
        "only route to this goal and so you must humor me. I shall leave you "
        "to reflect on your awful interpersonal skills if you do choose not "
        "to answer my very civil and reasonable inquiry. Again, who are you "
        "and why are you here?'");
    addResponseTopic("first conversation", "None of your business...", 
        "wrong answer");
    addResponseTopic("first conversation", "I think I'll deflect...",
        "wrong answer");

    addResponse("wrong answer", "My name is...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::clear## ##InitiatorPossessive## throat and "
        "##ResponseInfinitive::say##, @S@'I am ##ActorName## and I am here to pass the "
        "trial, as you name it - and apparently to satisfy your curiousity. "
        "Am I allowed to ask of you then?'");

    addResponse("wrong answer", "I think not...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::state##, @S@'You may not have my name.' @D@The "
        "wispy figure shrugs and vanishes.");
    addResponseEffect("wrong answer", "I think not...", (["opinion":-25, "vanish" : 1]));
    addResponseEvent("wrong answer", "I think not...", "uhrdalenLeft");
    addResponse("wrong answer", "Leave...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::turn## away. The wispy figure shrugs and vanishes.");
    addResponseEffect("wrong answer", "Leave...", (["opinion":-25, "vanish" : 1]));
    addResponseEvent("wrong answer", "Leave...", "uhrdalenLeft");
}

/////////////////////////////////////////////////////////////////////////////
private void WhoAreYou()
{
    addTopic("who are you", "@D@The figure shrugs, @S@'You may ask, but be "
        "prepared to be ignored until I am satisfied... To my question "
        "regarding who you are, you gave me your name. That is simply what "
        "others call you. Do not tell me that you define yourself by a label "
        "given unto you by others. Given that same logic, it would be best to "
        "not respond next with your title. As for why you are here, you are "
        "very clever... We would not be having this conversation if you were "
        "not here for the trial. What is your motivation for wanting to pass the trial?'");

    addResponseTopic("first conversation", "My name is...", "who are you");
    addResponseTopic("wrong answer", "My name is...", "who are you");

    string overallRespose = "I am one of the Chosen of The Lord of Waters and by the "
        "good grace, blessing and gifts of the aforementioned, I am here on "
        "a mission to restore balance to this world.' @D@@C@##InitiatorName## "
        "##ResponseInfinitive::gesture## in the direction one might suppose the Heart "
        "of Obedience artifact would lie. @S@'That thing is in my way. I have "
        "answered you, now who might you be?'";

    addResponse("who are you", "Fine. I'll be blunt...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::say##, @S@'Very well. I do not wish to speak in "
        "riddles. " + overallRespose);
    addResponse("who are you", "I'll humor you...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::reply##, @S@'I was the protector of the one I have "
        "failed. Yet " + overallRespose);
}

/////////////////////////////////////////////////////////////////////////////
private void AndWhoMightYouBe()
{
    addTopic("who might you be", "@S@'Who might I be? That is a tale in and "
        "of itself - a tale that deviates considerably from the topic at hand. "
        "I am weak. I am strong. Burning. Freezing. Hiding behind "
        "inconsequential armor. I am my greatest fear. I am accursed, damned. "
        "I was beloved, but now forgotten. I am a thrall to the desires of "
        "others. Most importantly, I may well be an example to all of what "
        "not to do as you go through your life. ' @D@The being chuckles at this.");
    addResponseTopic("who are you", "Fine. I'll be blunt...", "who might you be");
    addResponseTopic("who are you", "I'll humor you...", "who might you be");

    addResponse("who might you be", "@I@Say nothing@E@", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::make## no response.");
    addResponse("who might you be", "That's a mouthful...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::say##, @S@'Repeating that without tripping up is "
        "my greatest fear... Can I just call you... Bob?'");
    addResponse("who might you be", "Let's be friends...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::ask##, @S@'And what do your friends call you? You "
        "still have them, yes?'");

    addTopic("who might you be PT2", "@D@After a short yet uncomfortable pause, "
        "the being continues. @S@'That can be a mouthful. You may call me "
        "Uhrdalen. As to your answer, you still do not understand the question. "
        "Too often, you spoke of external entities: Lord of Water this and "
        "Chosen that. You are of varied kin, some inconsequential and some "
        "not. You were chosen by a God and you speak of your mission. You "
        "judge your worth by the company you keep and not by what is within "
        "you. I did not ask you of any but yourself. Be that as it may, I do "
        "not believe you know and I shan't press.'");
    addTopicEvent("who might you be PT2", "revealName");
    addResponseTopic("who might you be", "@I@Say nothing@E@", "who might you be PT2");
    addResponseTopic("who might you be", "That's a mouthful...", "who might you be PT2");
    addResponseTopic("who might you be", "Let's be friends...", "who might you be PT2");

    addResponse("who might you be PT2", "@I@Continue@E@", "@I@Continue@E@");
}

/////////////////////////////////////////////////////////////////////////////
private void KnowThyself()
{
    addTopic("know thyself", "@S@'The only comment you made that is relevant "
        "to our conversation is the discussion of your purpose.' @D@Uhrdalen "
        "continues. @S@'You cannot hope to recover that thing until you "
        "understand yourself. Do not fear to seek those answers. At the end of "
        "this path that has opened up before you, you will find two things: "
        "one you wish for and one that is quite the opposite. You will find "
        "that the demon you face is you - and your prejudices.");
    addResponseTopic("who might you be PT2", "@I@Continue@E@", "know thyself");

    addResponse("know thyself", "Fair enough... @A@Wisdom@E@", "@D@@C@##InitiatorName## "
        "carefully ##ResponseInfinitive::respond##, @S@'Fair enough, my Lord "
        "Uhrdalen, Let me then say this: I do not know who I am. I have not "
        "the wisdom nor the years to be so certain. No, the things I spoke of "
        "are not who I am, but they are the vehicles by which I shall become "
        "who I must.'");

    addResponse("know thyself", "I understand... @A@Diplomacy@E@", "@D@@C@##InitiatorName## "
        "thoughtfully ##ResponseInfinitive::reply##, @S@'What I do understand "
        "is that there are terrible things happening and I am in a position "
        "to change them. I may fail, but I must try nonetheless.'");
}

/////////////////////////////////////////////////////////////////////////////
private void OnToTheTrial()
{
    addTopic("on to the trial", "@D@Uhrdalen nods at this, @S@'Well spoken, "
        "##ActorName##.  Now on to your trial. I am here, caretaker of the "
        "trial. Clearly, I must either be one of the wretched creatures bent "
        "toward Xyris's wickedness or I must be a thrall to his desires, "
        "unable to leave?'");
    addResponseTopic("know thyself", "Fair enough... @A@Wisdom@E@",
        "on to the trial");
    addResponseTopic("know thyself", "I understand... @A@Diplomacy@E@",
        "on to the trial");

    addResponse("on to the trial", "@I@Say nothing@E@", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::say## nothing, encouraging Uhrdalen to continue.");
    addResponse("on to the trial", "Do you need my help?", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::frown## and ##ResponseInfinitive::ask##, @S@'Do "
        "you need help?'");

    addTopic("no bonds hold me", "@S@'Nay, if I wished to leave this place, I "
        "am quite capable of doing so,' @D@Uhrdalen continues, @S@'No bonds "
        "force me to walk these lonely halls. As I did say, however, I am a "
        "thrall, a fool, and a thousand other colorful things. If I could "
        "break my bondage, perhaps I would... perhaps I am too much the "
        "craven to try. It is not a place so much as another's will that "
        "guides my ties to this place. I choose to be here because it is the "
        "path of least resistance. I am the opportunity missed, the lamb "
        "being guided by wolves. Nevertheless, my banter wastes your time "
        "when such things mean life itself. I would now encourage you to face "
        "the challenge.'");
    addResponseTopic("on to the trial", "@I@Say nothing@E@", "no bonds hold me");
    addResponseTopic("on to the trial", "Do you need my help?", "no bonds hold me");

    addResponse("no bonds hold me", "About that...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::clear## ##InitiatorPossessive## throat and "
        "##ResponseInfinitive::say##, @S@'So, about this challenge...'");
    addResponse("no bonds hold me", "The pedestals... @A@Spellcraft@E@", 
        "@D@@C@##InitiatorName## ##ResponseInfinitive::look## at the pulsating "
        "pedestals and ##ResponseInfinitive::ask##, @S@'I suspect that those "
        "have something to do with the challenge?'");
}

/////////////////////////////////////////////////////////////////////////////
private void ThePedestals()
{
    addTopic("the pedestals", "@D@Uhrdalen gestures at the pedestals and states, "
        "@S@'Look to the pedestals. Each light pulses in the colors of sorrow, "
        "envy, wrath, and fear, each intermingled one with the other. Touch the "
        "plate of sorrow and the lights to the north, south, and east shall "
        "change, cycling first to sorrow, then wrath, envy, and finally fear.'");
    addResponseTopic("no bonds hold me", "About that...", "the pedestals");
    addResponseTopic("no bonds hold me", "The pedestals... @A@Spellcraft@E@", 
        "the pedestals");

    addResponse("the pedestals", "@I@Continue@E@", "@I@Continue@E@");

    addTopic("the pedestals PT2", "@S@'Touch the plate of envy and the west, "
        "north, and east shall change. Touch the plate of fear and the west, "
        "east, and south do change. Touch the plate of wrath and the west, "
        "north, and south shall change. Place your hand on the plate of death "
        "and the colors shall revert to the union. Learn well this verse, for "
        "it is the key:\n\n@H@\tTo the north lies winter eternal.\n \tTo the "
        "south the green pastures beckon.\n\tTo the east the calming embrace "
        "of the sea.\n\tTo the west the fires of war embrace the lands.\n@E@");
    addResponseTopic("the pedestals", "@I@Continue@E@", "the pedestals PT2");

    addResponse("the pedestals PT2", "Say what?", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::mutter## in consternation, @S@'And here I "
        "though we would not be speaking in riddles...'");
    addResponse("the pedestals PT2", "Got it. @A@Mathematics@E@", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::nod##, @S@'I think I understand. This verse tells "
        "me what the pattern needs to be.'");

    addTopic("the pedestals PT3", "@S@'The objective is clearly spelled out "
        "in the verse I have given you. Certainly, you need further guidance, "
        "but you must use your own wit and that failing, random luck to "
        "complete this. As to the choice of plates, you do not want to misjudge "
        "them lest they be your death.' @D@As these ominous words are spoken, "
        "Uhrdalen fades from view.");
    addResponseTopic("the pedestals PT2", "Say what?", "the pedestals PT3");
    addResponseTopic("the pedestals PT2", "Got it. @A@Mathematics@E@", 
        "the pedestals PT3");
    addTopicEvent("the pedestals PT3", "startFirstTest");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    ThePlayerAndTheirName();
    WhoAreYou();
    AndWhoMightYouBe();
    KnowThyself();
    OnToTheTrial();
    ThePedestals();
}
