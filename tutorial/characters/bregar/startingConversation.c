//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void ThatHurts()
{
    addTopic("that hurts", "@D@The black-robed figure falls to the "
        "ground, seriously wounded.");

    addTopicInterjection("that hurts",
        "/lib/tutorial/characters/halgaladh/halgaladh.c",
        "shall we question this one?", 1);

    addTopic("what is this place", "@D@The black-robed figure "
        "looks absolutely terrified and chokes out, @S@`Please don't kill "
        "me!'");
    addResponse("that hurts", "Then answer...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::respond##, @S@`You "
        "should answer his question if you want to live.'");
    addResponse("that hurts", "Why not?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@`That "
        "all depends on how cooperative you are. I will repeat my friend: "
        "What is this place?'");
    addResponse("that hurts", "@I@Kill Prisoner@E@",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::shake## "
        "##InitiatorPossessive## head and ##ResponseInfinitive::say##, "
        "@S@`No... it's time to die.'");
    addResponseEffect("that hurts", "@I@Kill Prisoner@E@", (["attack":1]));
}

/////////////////////////////////////////////////////////////////////////////
private void SoIPickMyDeath()
{
    addTopic("not that", "@S@`I cannot tell you that! Please, you must not "
        "ask that of me.' @D@The figure loses all color in his face. @S@`He "
        "will do worse than kill me!'");

    addResponseTopic("that hurts", "Then answer...", "not that");
    addResponseTopic("that hurts", "Why not?", "not that");

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
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    ThatHurts();
    SoIPickMyDeath();
    ThatIsDistracting();
    GutsEqualSpilled();

}
