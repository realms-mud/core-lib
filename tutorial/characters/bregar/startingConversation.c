//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void ThatHurts()
{
    addTopic("first conversation", "@D@The black-robed figure falls to the "
        "ground, seriously wounded.");

    addTopicInterjection("first conversation",
        "/lib/tutorial/characters/halgaladh/halgaladh.c",
        "shall we question this one?", 1);

    addTopic("what is this place", "@D@The black-robed figure "
        "looks absolutely terrified and chokes out, @S@`Please don't kill "
        "me!'");
    addResponse("first conversation", "Then answer...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::respond##, @S@`You "
        "should answer his question if you want to live.'");
    addResponse("first conversation", "Why not?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@`That "
        "all depends on how cooperative you are. I will repeat my friend: "
        "What is this place?'");
    addResponse("first conversation", "@I@Kill Prisoner@E@",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::shake## "
        "##InitiatorPossessive## head and ##ResponseInfinitive::say##, "
        "@S@`No... it's time to die.'");
    addResponseEffect("first conversation", "@I@Kill Prisoner@E@", (["attack":1]));
}

/////////////////////////////////////////////////////////////////////////////
private void SoIPickMyDeath()
{
    addTopic("not that", "@S@`I cannot tell you that! Please, you must not "
        "ask that of me.' @D@The figure loses all color in his face. @S@`He "
        "will do worse than kill me!'");

    addResponseTopic("first conversation", "Then answer...", "not that");
    addResponseTopic("first conversation", "Why not?", "not that");

    addTopicInterjection("not that",
        "/lib/tutorial/characters/donald/donald.c",
        "you get that for free", 1);

    addResponse("not that", "And what of us?", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::shrug## and ##ResponseInfinitive::note##, "
        "@S@`And what of us if you do not speak? Wrong answer. This is your "
        "last chance. If you do not tell me what I want, this man here,' @D@"
        "##InitiatorName## ##ResponseInfinitive::point## at Halgaladh, "
        "@S@`will sever your uncooperative head from your body. Now answer "
        "me: What is this place?");
    addResponse("not that", "Speak and you're safe...", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::nod## and reassuringly "
        "##ResponseInfinitive::say##, @S@`Speak and no harm will come to "
        "you. Things will go poorly if you do not.");

    addTopic("so I pick my death", "@D@The figure sighs brokenly and seems to "
        "have made peace with his fate. @S@`So you offer me my choice of "
        "deaths... very well. We are the Keepers of the Night and you have "
        "come upon one of our outposts.'");
    addResponseTopic("not that", "And what of us?", "so I pick my death");
    addResponseTopic("not that", "Speak and you're safe...", "so I pick my death");

    addResponse("so I pick my death", "And?", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::prod##, @S@`And?'");
}

/////////////////////////////////////////////////////////////////////////////
private void ThatIsDistracting()
{
    addTopic("and what?", "@S@`And what? I have told you what this place is.' "
        "@D@Quickly realizing that this was an unsatisfactory answer, he "
        "adds, @S@`As for what we do here, well... I think you know that "
        "much. We are raising an army.'");
    addResponseTopic("so I pick my death", "And?", "and what?");

    addTopicInterjection("and what?",
        "/lib/tutorial/characters/donald/donald.c",
        "I have a great idea", 1);

    addTopic("that's distracting", "@D@Despite his current predicament, the "
        "black-robed figure can't help but chuckle at the squad's antics, @S@`"
        "My apologies, but how the hell did you defeat us? You aren't exactly "
        "a well-oiled machine, are you?'");

    addResponse("that's distracting", "Perhaps not...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::respond##, @S@`Perhaps "
        "not. But that may well be an indictment on your group's... low level "
        "of readiness. My turn. What's the purpose of this army you're "
        "raising?' @D@After a short pause wherein no response was forthcoming, "
        "##InitiatorName## forcefully ##ResponseInfinitive::reiterate##, @S@`"
        "For what purpose!?'");

    addResponse("that's distracting", "Who's bleeding on the ground?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::respond##, @S@`And whose "
        "corpses decorate the landscape? Who's bleeding on the ground with "
        "a sword at their throat? Nay, it's my turn. What's the purpose of "
        "this army you're raising?' @D@After a short pause wherein no response "
        "was forthcoming, ##InitiatorName## forcefully "
        "##ResponseInfinitive::reiterate##, @S@`For what purpose!?'");

    addResponse("that's distracting", "My turn...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::dismiss## the "
        "black-robed man's jab and ##ResponseInfinitive::say##, @S@`Remain "
        "curious. My turn. What's the purpose of this army you're raising?' "
        "@D@After a short pause wherein no response was forthcoming, "
        "##InitiatorName## forcefully ##ResponseInfinitive::reiterate##, "
        "@S@`For what purpose!?'");
}

/////////////////////////////////////////////////////////////////////////////
private void GutsEqualSpilled()
{
    addTopic("I don't know", "@S@`I don't know...' @D@the black-robed man "
        "says, @S@`What do armies ever do? Please, let me go and I will tell "
        "you how you can stop it.'");
    addResponseTopic("that's distracting", "Perhaps not...", "I don't know");
    addResponseTopic("that's distracting", "Who's bleeding on the ground?",
        "I don't know");
    addResponseTopic("that's distracting", "My turn...", "I don't know");

    addResponse("I don't know", "It depends on what you say...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::say##, @S@`Tell me "
        "and I will consider your request. Tell me not and you will die very "
        "soon.'");
    addResponse("I don't know", "You might live @A@Intimidation@E@",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::glare## menacingly at "
        "the figure and ##ResponseInfinitive::add##, @S@`Tell me "
        "and I will consider your request. Tell me not and you will die very "
        "soon.'");
    addResponsePrerequisite("I don't know", "You might live @A@Intimidation@E@",
        (["intimidation":(["type":"skill", "value" : 5])]), 1);
    addResponseEffect("I don't know", "You might live @A@Intimidation@E@",
        (["experience":(["guild":"background", "amount" : 25])]));

    addResponse("I don't know", "Come now @A@Diplomacy@E@",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::smile## slightly at "
        "the figure and ##ResponseInfinitive::add##, @S@`Come now. You want "
        "to live and I want to let you live. Things would go far toward those "
        "goals if you shared your knowledge with us.'");
    addResponsePrerequisite("I don't know", "Come now @A@Diplomacy@E@",
        (["diplomacy":(["type":"skill", "value" : 5])]), 1);
    addResponseEffect("I don't know", "Come now @A@Diplomacy@E@",
        (["experience":(["guild":"background", "amount" : 25])]));
}

/////////////////////////////////////////////////////////////////////////////
private void GutsEqualSpilledPartTwo()
{
    addTopic("very well", "@S@`Very well...' @D@the black-robed man "
        "sobs desperately, @S@`Make your way into the heart of the temple. "
        "There, you will find the Nightmaster and his Orb of Obedience. The "
        "orb creates small spheres of energy that are implanted into the "
        "corpses. It is these that give them the power of the beyond.' @D@"
        "The man shrugs slightly as he adds, @S@`Our understanding is "
        "imperfect, only recently having acquired this orb. We were told "
        "that eventually, they will have minds of their own, that we would "
        "only require suggestion rather than nearly full control. Our "
        "amulets are the key. We tell the corpses to go somewhere and so "
        "they obey. If we do not concentrate our will on them, they are "
        "useless mounds of flesh, much like they were in life.'");
    addResponseTopic("I don't know", "It depends on what you say...", "very well");
    addResponseTopic("I don't know", "You might live @A@Intimidation@E@",
        "very well");
    addResponseTopic("I don't know", "Come now @A@Diplomacy@E@", "very well");

    addResponse("very well", "Useless? Seriously?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::smirk##, @S@`Useless "
        "as they were in life? For that arrogant jab alone, I might end you.'");
    addResponse("very well", "What else?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::say##, @S@`What other "
        "information can you provide? Quickly... Time is running out.'");

    addTopic("please don't kill me", "@D@The man looks absolutely terrified. "
        "He pleads, @S@`Please, I have told you all you need to know. Release "
        "me!' @D@When he realizes that his release is not imminent, he adds, "
        "@S@`The Nightmaster is one of the twelve living gerents of Xyris, "
        "lord of the dead. He commands us to prepare an army for his conquest "
        "of Eledhel. Enter his abode and you shall gladly serve him in death. "
        "Flee this place now lest you get ensnared by his web as I have. I "
        "beg of thee... Flee while there is time. He is aware of you. There "
        "is no more I can say. Release me!'");
    addTopicEvent("please don't kill me", "enterTheLair");
    addResponseTopic("very well", "Useless? Seriously?", "please don't kill me");
    addResponseTopic("very well", "What else?", "please don't kill me");

    addResponse("please don't kill me", "Yeah, sure. @I@Kill Prisoner@E@",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::shake## "
        "##InitiatorPossessive## head and ##ResponseInfinitive::say##, "
        "@S@`No... it's time to die.'");
    addResponseEffect("please don't kill me", "Yeah, sure. @I@Kill Prisoner@E@", 
        (["attack":1]));

    addResponse("please don't kill me", "Donald?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##,  @S@`Sir?'");
    addResponse("please don't kill me", "@I@Continue@E@", "");

    addTopic("please don't kill me part 2", "@D@The man looks expectantly at "
        "##InitiatorName## and adds, @S@`I have done my part. Release me.'");
    addResponseTopic("please don't kill me", "Donald?", 
        "please don't kill me part 2");
    addResponseTopic("please don't kill me", "@I@Continue@E@",
        "please don't kill me part 2");

    addTopicInterjection("please don't kill me part 2",
        "/lib/tutorial/characters/donald/donald.c",
        "grant him his release", 1);
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    ThatHurts();
    SoIPickMyDeath();
    ThatIsDistracting();
    GutsEqualSpilled();
    GutsEqualSpilledPartTwo();
}
