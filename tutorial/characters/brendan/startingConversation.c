//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    // First conversation
    addTopic("first conversation", "@D@As you turn to talk to the black-robed figure, you "
        "note that it is a man in his early thirties. It is clear that he is of noble "
        "background. He eyes you balefully.");

    addResponse("first conversation", "Who are you?", "As you look at the figure, you note "
        "an amulet that makes you feel very uneasy. @S@`And what say you my little villain?");

    // Who are you?
    addTopic("villain", "@D@The black-robed figure responds in a raspy voice, "
        "@S@`Villain, is it? I am not the one who entered another's home "
        "and murdered his friends, now am I? Now, I lie here bleeding of "
        "multiple wounds with said murderer standing at my throat. What say I? "
        "Not a damned thing.'");
    addResponseTopic("first conversation", "Who are you?", "villain");

    addResponse("villain", "Let's try again", "@D@You clear your throat and try a different "
        "tactic, @S@`Let's try this again. What in the Abyss is going on here? "
        "Why do you force us to fell our own comrades? What is the meaning of your "
        "little decorative but rather unfashionably macabre trinkets? And just "
        "what was that horrid smoking thunderclap?'");

    // You're a bit simple...
    addTopic("you are a simpleton", "@S@`You are a bit simple, aren't you? What "
        "is going on? Is that not a question I should be asking you? As I "
        "said, this is my home. Perhaps you are not familiar with the term? "
        "I live here as did my friends before you butchered them.' @D@The "
        "robed figure sneers.");
    
    // task 352 needs to be implemented to properly support the firing of
    // Galadhel's interjection. Then, task 354 will be implemented here.
    addTopicEvent("you are a simpleton", "brendan - need a decorator");
    addResponseTopic("villain", "Let's try again", "you are a simpleton");

    // Respond to Galadhel
    addTopic("bad host", "@D@The robed figure wryly hisses, @S@"
        "`By all means. Converse. I feel like a bad host, however. If you "
        "would but let me up, I shall fetch some tea and we can have a more "
        "polite conversation.'");

    addResponse("bad host", "Are you keeping score?", "@D@You impassively reply, "
        "@S@`Assess your situation. You are currently under my foot and "
        "the recipient of my ire because you look quite similar "
        "to the one we saw flee the scene of our massacre.'");
    addResponseEvent("bad host", "Are you keeping score?", "threaten brendan");

    // I'm a farmer
    addTopic("I'm a farmer", "@D@`You would ensure your own death were "
        "you to let loose, young woman. You are arrogant and foolhardy to "
        "assume that I am defenseless.' @D@The figure sighs in a faux, wounded tone, "
        "@S@`Nonetheless, I shall humor you. We are simple mushroom farmers. The corpses we "
        "collect because they suit our needs... My garb and trinkets, I wear "
        "because they are comfortable and will become increasingly so as the autumn "
        "gives way to winter. This building is here both for storage and for the "
        "harvesting of... our crop. As for the 'thunderclap' as you quaintly put "
        "it, well... that's just a fun little trick that a dear old friend taught "
        "me. As for the question about me forcing you to kill your comrades, well, "
        "I'm not the one who caused you to shoot or swing a sword at them, now am "
        "I? For that, at least, you should consider me blameless.'");
    // This is a Donald event (354)
    addTopicEvent("I'm a farmer", "brendan - communicative");

    // I'm a farmer
    addTopic("my death is nigh", "@D@The robed gasps in agony, @S@"
        "`My memories? What is this besotted fool speaking of? Nay, I "
        "know that my death is nigh. Do the deed and be done. Ere I die, "
        "I console myself with the knowledge that you shall soon follow me. "
        "But take these words with you: the honor of the Guard is tarnished "
        "since the days of old. You have an enemy unarmed at your feet and "
        "you would resort to petty torture. Aye, my brothers are no better, "
        "but one would expect that from... mushroom farmers.'");
        
    addConditionalTopicAddendum("my death is nigh", ([ "present": "galadhel" ]),
        "@D@The robed one looks directly at Galadhel and adds, @S@`Now, if you "
        "would be so kind, blessed daughter and sister of the damned, I "
        "would prefer to leave this world.'");

}
