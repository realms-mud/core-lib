//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void WhoAreYou()
{
    addTopic("villain", "@D@The black-robed figure responds in a raspy voice, "
        "@S@`Villain, is it? I am not the one who entered another's home "
        "and murdered his friends, now am I? Now, I lie here bleeding of "
        "multiple wounds with said murderer standing at my throat. What say I? "
        "Not a damned thing.'");
    addResponseTopic("first conversation", "Who are you?", "villain");

    addResponse("villain", "Let's try again", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::clear## ##InitiatorPossessive## throat and try a different "
        "tactic, @S@`Let's try this again. What in the Abyss is going on here? "
        "Why do you force us to fell our own comrades? What is the meaning of your "
        "little decorative but rather unfashionably macabre trinkets? And just "
        "what was that horrid smoking thunderclap?'");
    addResponse("villain", "Speak @A@Intimidation@E@", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::glare## at the figure and ##ResponseInfinitive::growl##,"
        " @S@`Do you want to live? If so, speak! What is going on here? "
        "Why do you force us to fell our own comrades? What is the meaning of your "
        "little decorative but rather unfashionably macabre trinkets? And just "
        "what was that horrid smoking thunderclap?'");
    addResponsePrerequisite("villain", "Speak @A@Intimidation@E@",
        (["intimidation":(["type":"skill", "value": 5 ])]), 1);
    addResponseEffect("villain", "Speak @A@Intimidation@E@",
        (["experience":(["guild":"background", "amount" : 25])]));

    addResponse("villain", "Speak @A@Diplomacy@E@", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::chuckle## at the figure and ##ResponseInfinitive::say##,"
        " @S@`In the civilized world, one begging for clemency is typically less haughty. "
        "What is going on here? Why do you force us to fell our own comrades? And just "
        "what was that horrid smoking thunderclap?'");
    addResponsePrerequisite("villain", "Speak @A@Diplomacy@E@",
        (["diplomacy":(["type":"skill", "value" : 5])]), 1);
    addResponseEffect("villain", "Speak @A@Diplomacy@E@",
        (["experience":(["guild":"background", "amount" : 25])]));
}

/////////////////////////////////////////////////////////////////////////////
private void YouAreABitSimple()
{
    addTopic("you are a simpleton", "@S@`You are a bit simple, aren't you? What "
        "is going on? Is that not a question I should be asking you? As I "
        "said, this is my home. Perhaps you are not familiar with the term? "
        "I live here as did my friends before you butchered them.' @D@The "
        "robed figure sneers.");
    addResponseTopic("villain", "Let's try again", "you are a simpleton");
    addResponseTopic("villain", "Speak @A@Intimidation@E@", "you are a simpleton");
    addResponseTopic("villain", "Speak @A@Diplomacy@E@", "you are a simpleton");

    addTopicInterjection("you are a simpleton",
        "/tutorial/characters/galadhel/galadhel.c",
        "brendan - need a decorator", 1);

    addResponse("you are a simpleton", "Seriously?", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::reply##, "
        "@S@`This is how you want to end? Seriously?' @D@@C@##InitiatorName## "
        "##ResponseInfinitive::clear## ##InitiatorPossessive## throat and "
        "##ResponseInfinitive::mock## the black-robed figure, @S@`\"Stop! I "
        "yield! Please don't kill me!\" It'd be a pity if your simpering whines "
        "came to naught. Perhaps you'd rather we converse?'");
    addResponse("you are a simpleton", "Is this how you end? @A@Persuasion@E@",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::reply##, @S@`This is "
        "how you want to end? Seriously? It'd be a pity if your simpering "
        "whines came to naught. Perhaps you'd rather we converse?'");
    addResponsePrerequisite("you are a simpleton", "Is this how you end? @A@Persuasion@E@",
        (["persuasion":(["type":"skill", "value" : 2])]), 1);
    addResponseEffect("you are a simpleton", "Is this how you end? @A@Persuasion@E@",
        (["experience":(["guild":"background", "amount" : 25])]));
}

/////////////////////////////////////////////////////////////////////////////
private void BadHost()
{
    addTopic("bad host", "@D@The robed figure wryly hisses, @S@"
        "`By all means. Converse. I feel like a bad host, however. If you "
        "would but let me up, I shall fetch some tea and we can have a more "
        "polite conversation.'");
    addResponseTopic("you are a simpleton", "Seriously?", "bad host");
    addResponseTopic("you are a simpleton", "Is this how you end? @A@Persuasion@E@",
        "bad host");

    addTopicInterjection("bad host",
        "/tutorial/characters/galadhel/galadhel.c",
        "threaten brendan", 1);

    addTopic("slow down, Sparky", "@D@The figure snorts, @S@`You would ensure "
        "your own death were you to let loose, young woman. You are arrogant "
        "and foolhardy to assume that I am defenseless.' @D@He abruptly stops his "
        "outburst, well-aware of the danger he currently faces.");

    addResponse("bad host", "Are you keeping score?", "@D@@C@##InitiatorName## "
        "impassively ##ResponseInfinitive::reply##, "
        "@S@`Assess your situation. You are currently under my foot and "
        "the recipient of my ire because you look quite similar "
        "to the one we saw flee the scene of our massacre. I will ask one "
        "last time. Who are you?'");
    addResponse("bad host", "Patience is not one of my virtues",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::note## ##InitiatorPossessive##, "
        "@S@`I am quickly losing my patience. Who are you?'");
}

/////////////////////////////////////////////////////////////////////////////
private void IAmAFarmer()
{
    addTopic("I'm a farmer", "@D@The figure sighs in a faux, wounded tone, "
        "@S@`Very well, I shall humor you. We are simple mushroom farmers. The corpses we "
        "collect because they suit our needs... My garb and trinkets, I wear "
        "because they are comfortable and will become increasingly so as the autumn "
        "gives way to winter. This building is here both for storage and for the "
        "harvesting of... our crop. As for the 'thunderclap' as you quaintly put "
        "it, well... that's just a fun little trick that a dear old friend taught "
        "me. As for the question about me forcing you to kill your comrades, well, "
        "I'm not the one who caused you to shoot or swing a sword at them, now am "
        "I? For that, at least, you should consider me blameless.'");
    addResponseTopic("bad host", "Patience is not one of my virtues", "I'm a farmer");
    addResponseTopic("bad host", "Are you keeping score?", "I'm a farmer");

    addTopicInterjection("I'm a farmer",
        "/tutorial/characters/donald/donald.c",
        "not communicative", 1);

    addTopic("besotted fool", "@D@The figure gasps in pain. @S@`My memories? "
        "What is this besotted fool speaking of?'");

    addTopic("my death is nigh", "@D@The figure seems disinclined to speak. "
        "@S@`Nay, I know that my death is nigh. Do the deed and be done. Ere "
        "I die, I console myself with the knowledge that you shall soon "
        "follow me. But take these words with you: the honor of the Guard is "
        "tarnished since the days of old. You have an enemy unarmed at your "
        "feet and you would resort to petty torture. Aye, my brothers are no "
        "better, but one would expect that from.... mushroom farmers.'");

    addResponse("I'm a farmer", "What the hell, Donald?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::sigh##, "
        "@S@`I have this under control, Donald. Brutish actions like that "
        "are decidedly not helpful.' @D@@C@##InitiatorName## "
        "##ResponseInfinitive::turn## back to the black-robed man "
        "and ##ResponseInfinitive::add##, @S@`However, he has a point. "
        "No more games. What are you doing here?'");
    addResponsePrerequisite("I'm a farmer", "What the hell, Donald?",
        (["presence": (["type":"presence", "value": ({ "donald" })])]));

    addResponseTopic("I'm a farmer", "What the hell, Donald?", "my death is nigh");

    addResponse("I'm a farmer", "Stop the games...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, "
        "@S@`And? No more games. What are you doing here?'");
    addResponseTopic("I'm a farmer", "Stop the games...", "my death is nigh");
}

/////////////////////////////////////////////////////////////////////////////
private void YouKnowMe()
{
    addConditionalTopicAddendum("my death is nigh", "blessed daughter",
        (["presence":(["type":"presence", "value" : ({ "galadhel" })])]),
        " @D@The robed one looks directly at Galadhel and adds, @S@`Now, if you "
        "would be so kind, blessed daughter and sister of the damned, I "
        "would prefer to leave this world.'");

    addTopicInterjection("my death is nigh",
        "/tutorial/characters/galadhel/galadhel.c",
        "you know me?", 1);

    addTopic("yes, I know you", "@D@The figure shrugs, @S@`Your resemblance to "
        "your brother is unmistakable.' @D@The black-robed looks quite "
        "pleased with himself.");

    addResponse("yes, I know you", "Galadhel?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::look## at Galadhel "
        "in shock and ##ResponseInfinitive::ask##, @S@`Galadhel?'");
    addResponse("yes, I know you", "Who are you?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::look## at Galadhel "
        "in shock and ##ResponseInfinitive::return## ##InitiatorPossessive## "
        "gaze to the black-robed figure. @C@##InitiatorName## "
        "##ResponseInfinitive::ask##, @S@`Who are you?'");

    addResponsePrerequisite("yes, I know you", "Galadhel?",
        (["presence":(["type":"presence", "value" : ({ "galadhel" })])]));
}

/////////////////////////////////////////////////////////////////////////////
private void StopInterrupting()
{
    addTopic("stop interrupting", "@D@The figure smirks and wryly says, "
        "@S@`My tale is much better if I am not constantly interrupted. "
        "Do you wish to hear it or no?'");

    addTopicInterjection("stop interrupting",
        "/tutorial/characters/galadhel/galadhel.c",
        "Interruptions aren't your only concern", 1);

    addResponseTopic("yes, I know you", "Galadhel?", "stop interrupting");
    addResponseTopic("yes, I know you", "Who are you?", "stop interrupting");

    addTopic("I was Phaedra", "@D@The figure shrugs, apparently not at all "
        "opposed to spilling his guts. It's almost as if he enjoys telling "
        "how deeply rooted his associates are in Eledhel's politics. @S@`"
        "I was Phaedra. We were stationed in Helcarion... Your brother's "
        "command. That is, until the back of our forces was resoundingly "
        "broken.'");

    addResponse("I was Phaedra", "Wait. What?",
        "@D@Stunned, ##InitiatorName## ##ResponseInfinitive::look## at the figure "
        "and ##ResponseInfinitive::ask##, @S@`Helcarion? What "
        "happened?'");
    addResponseEffect("I was Phaedra", "Wait. What?",
        (["experience":(["guild":"background", "amount" : 500])]));

    addResponse("I was Phaedra", "And?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::look## at the figure "
        "and ##ResponseInfinitive::say##, @S@`And?'");
    addResponseEffect("I was Phaedra", "And?",
        (["experience":(["guild":"background", "amount" : 500])]));

    addTopic("We fought but lost", "@S@`We fought until but five of us were "
        "left. It was obvious that we were to be captured, for they would not "
        "kill us though the corpses of our foes piled up in walls before us.' "
        "@D@The black-robed figure glances at Galadhel and adds, @S@`Finally, "
        "weariness and the unabated attack of our foes overwhelmed us. We "
        "were taken. It was not a difficult choice to lay aside my allegiance "
        "after I saw what they did to Mendros. That aside, they paid me very "
        "well.'");
    addResponseTopic("I was Phaedra", "Wait. What?", "We fought but lost");
    addResponseTopic("I was Phaedra", "And?", "We fought but lost");
}

/////////////////////////////////////////////////////////////////////////////
private void SoThenWhat()
{
    addResponse("We fought but lost", "Galadhel's brother...", 
        "@D@@C@##InitiatorName## ##ResponseInfinitive::frown## slightly and "
        "##ResponseInfinitive::ask##, @S@`And what of Galadhel's brother?'");
    addResponse("We fought but lost", "Who are you people?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::frown## slightly and "
        "##ResponseInfinitive::ask##, @S@`Who, no what, are you people? What "
        "is your purpose here? And don't you dare continue with the mushroom "
        "farmer story.'");
    addResponse("We fought but lost", "What did they do to Mendros?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::frown## slightly and "
        "##ResponseInfinitive::ask##, @S@`What did they do to Mendros?'");
    addResponse("We fought but lost", "What are you doing?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::frown## slightly and "
        "##ResponseInfinitive::ask##, @S@`What are you and your fellows doing "
        "here? And don't you dare continue with the mushroom "
        "farmer story.'");

    addTopic("so then what", "@D@The figure begins, @S@`Very well, I su..'");
    addResponseTopic("We fought but lost", "Galadhel's brother...", 
        "so then what");
    addResponseTopic("We fought but lost", "Who are you people?",
        "so then what");
    addResponseTopic("We fought but lost", "What did they do to Mendros?",
        "so then what");
    addResponseTopic("We fought but lost", "What are you doing?",
        "so then what");

    addTopicInterjection("so then what",
        "/tutorial/characters/donald/donald.c",
        "we waste time on this bastard", 1);
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    // First conversation
    addTopic("first conversation", "@S@`Stop! I yield! Please don't kill me!', "
        "@D@the black-robed figure whines and throws its hands in the air. You "
        "note that it is a man in his early thirties. It is clear that he is of noble "
        "background. He eyes you balefully, but looks wholly defeated.");

    addResponse("first conversation", "Who are you?", "As you look at the figure, you note "
        "an amulet that makes you feel very uneasy. @D@@C@##InitiatorName## "
        "##ResponseInfinitive::ask##, @S@`And what say you my little villain?");

    WhoAreYou();
    YouAreABitSimple();
    BadHost();
    IAmAFarmer();
    YouKnowMe();
    StopInterrupting();
    SoThenWhat();
}
