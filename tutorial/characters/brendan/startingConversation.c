//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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

    addResponse("villain", "Speak @A@Diplomacy@E@", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::chuckle## at the figure and ##ResponseInfinitive::say##,"
        " @S@`In the civilized world, one begging for clemency is typically less haughty. "
        "What is going on here? Why do you force us to fell our own comrades? And just "
        "what was that horrid smoking thunderclap?'");
    addResponsePrerequisite("villain", "Speak @A@Diplomacy@E@",
        (["diplomacy":(["type":"skill", "value" : 21])]), 1);
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
        "/lib/tutorial/characters/galadhel/galadhel.c",
        "brendan - need a decorator", 1);

    addResponse("you are a simpleton", "Seriously?", "@D@@C@##InitiatorName## "
        "##ResponseInfinitive::reply## ##InitiatorPossessive##, "
        "@S@`This is how you want to end? Seriously?' @D@@C@##InitiatorName## "
        "##ResponseInfinitive::clear## ##InitiatorPossessive## throat and "
        "##ResponseInfinitive::mock## the black-robed figure, @S@`\"Stop! I "
        "yield! Please don't kill me!\" It'd be a pity if your simpering whines "
        "came to naught. Perhaps you'd rather we converse?'");
    addResponse("you are a simpleton", "Is this how you end? @A@Persuasion@E@",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::reply## "
        "##InitiatorPossessive##, @S@`This is how you want to end? Seriously?' "
        "It'd be a pity if your simpering whines came to naught. Perhaps you'd "
        "rather we converse?'");
    addResponsePrerequisite("you are a simpleton", "Is this how you end? @A@Persuasion@E@",
        (["persuasion":(["type":"skill", "value" : 1])]), 1);
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
        "/lib/tutorial/characters/galadhel/galadhel.c",
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
        "/lib/tutorial/characters/donald/donald.c",
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

    addConditionalTopicAddendum("my death is nigh", "blessed daughter",
        (["presence":(["type":"presence", "value": ({ "galadhel" })])]),
        "@D@The robed one looks directly at Galadhel and adds, @S@`Now, if you "
        "would be so kind, blessed daughter and sister of the damned, I "
        "would prefer to leave this world.'");

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
private void KillMe()
{
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
    KillMe();
}
